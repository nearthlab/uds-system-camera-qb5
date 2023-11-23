////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file   chiofflinepostproctest.cpp
/// @brief  Test code to validate offline postproc feature
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define LOG_TAG "PostProcTest"
#define LOG_NDEBUG 0

#include <sys/mman.h>
#include <utils/Log.h>
#include <time.h>
#include <pthread.h>

#include <vendor/qti/hardware/camera/postproc/1.0/IPostProcService.h>
#include <vendor/qti/hardware/camera/postproc/1.0/IPostProcSession.h>

#include <android/hardware/graphics/allocator/3.0/IAllocator.h>
#include <android/hardware/graphics/mapper/3.0/IMapper.h>
#include "chiofflinepostproccallbacks.h"

using android::hardware::graphics::allocator::V3_0::IAllocator;
using android::hardware::graphics::common::V1_2::PixelFormat;
using android::hardware::graphics::common::V1_0::BufferUsage;
using android::hardware::graphics::mapper::V3_0::BufferDescriptor;
using android::hardware::graphics::mapper::V3_0::IMapper;
using android::hidl::base::V1_0::IBase;
using android::hardware::hidl_death_recipient;
using android::hardware::hidl_handle;
using android::hardware::hidl_vec;
using android::hardware::Return;
using android::sp;
using android::wp;
using vendor::qti::hardware::camera::postproc::V1_0::BufferParams;
using vendor::qti::hardware::camera::postproc::V1_0::CameraMetadata;
using vendor::qti::hardware::camera::postproc::V1_0::CreateParams;
using vendor::qti::hardware::camera::postproc::V1_0::Error;
using vendor::qti::hardware::camera::postproc::V1_0::HandleParams;
using vendor::qti::hardware::camera::postproc::V1_0::IPostProcService;
using vendor::qti::hardware::camera::postproc::V1_0::IPostProcSession;
using vendor::qti::hardware::camera::postproc::V1_0::JpegCapabilities;
using vendor::qti::hardware::camera::postproc::V1_0::PostProcCapabilities;
using vendor::qti::hardware::camera::postproc::V1_0::PostProcType;
using vendor::qti::hardware::camera::postproc::V1_0::ProcessRequestParams;

using vendor::qti::hardware::camera::postproc::V1_0::implementation::CameraPostProcCallBacks;

sp<IAllocator> g_Allocator;
sp<IMapper> g_Mapper;

pthread_mutex_t mutex;
pthread_cond_t encodeWait;


const native_handle_t* outh;
static uint32_t inbuf_size;

static uint32_t width_12M = 4608;
static uint32_t height_12M = 3456;

static uint32_t width_48M = 8000;
static uint32_t height_48M = 6000;

uint32_t requestId = 0;
uint8_t bServiceDied = false;


struct PostProcClientDeathRecipient : hidl_death_recipient
{
public:
    PostProcClientDeathRecipient() = default;
    virtual ~PostProcClientDeathRecipient() = default;
    virtual void serviceDied(uint64_t cookie, const wp<IBase> &who);
};


void PostProcClientDeathRecipient::serviceDied(uint64_t /*cookie*/, const wp<IBase>& /*who*/)
{
    ALOGE("%s, received from service, PostProcClientDeathRecipient", __FUNCTION__);
    bServiceDied = true;
    pthread_cond_signal(&encodeWait);
}

sp<PostProcClientDeathRecipient> mClientDeathReceipient = nullptr;

static const native_handle_t* GrallocAlloc(PixelFormat format, uint32_t width, uint32_t height, uint64_t usage,
                                            /*output*/ uint32_t *stride)
{
    IMapper::BufferDescriptorInfo info = {
      .width = width,
      .height = height,
      .layerCount = 1,
      .format = format,
      .usage = usage,
    };

    const native_handle_t * handle = nullptr;

    auto descriptor = BufferDescriptor();
    g_Mapper->createDescriptor(info, [&](const auto &/*_error*/, const auto &_descriptor){
        descriptor = _descriptor;
        });

    g_Allocator->allocate(descriptor, 1, [&](const auto &/*_error*/, const auto &_stride, const auto &_buffers)
    {
        if (_buffers.size() == 1)
        {
            g_Mapper->importBuffer(_buffers[0], [&](const auto &/*e*/, const auto &b) {
                                                handle = static_cast<const native_handle_t *>(b);
                                            });
            if (stride)
            {
                *stride = _stride;
            }
        }
    });
    return handle;
}

static void GrallocFree(const native_handle_t *buffer_handle)
{
    if (!buffer_handle)
    {
        return;
    }
    auto buffer = const_cast<native_handle_t *>(buffer_handle);
    g_Mapper->freeBuffer(buffer);
}

int32_t clipIndex = 0;

static uint32_t LoadFrame(char* buffer)
{
    FILE* fp;
    uint32_t ret = 0;

    if (1 == clipIndex)
    {
        char file[] = "/data/vendor/camera/colorbar.yuv";

        fp = fopen(file, "rb");
        if (!fp)
        {
            ALOGE("%s: fopen failed %s, clipIndex %d error code %s", __FUNCTION__, file, clipIndex, strerror(errno));
            return -1;
        }
    }
    else
    {
        char file[] = "/data/vendor/camera/nv12_4608_3456.yuv";

        fp = fopen(file, "rb");
        if (!fp)
        {
            ALOGE("%s: fopen failed %s, clipIndex %d error code %s", __FUNCTION__, file, clipIndex, strerror(errno));
            return -1;
        }
    }

    fseek(fp, 0, SEEK_END);
    uint64_t fileSize = ftell(fp);

    ALOGE("Input file %p: size is: %lld", fp, (long long)fileSize);
    fseek(fp, 0, SEEK_SET);
    uint64_t readSize = fread(buffer, 1, fileSize, fp);

    if (readSize != fileSize)
    {
        ret = -1;
        ALOGE("readSize %lld is not same as fileSize %lld", (long long)readSize, (long long)fileSize);
    }

    fclose(fp);
    return ret;
}


int main()
{
    g_Allocator = IAllocator::getService();
    g_Mapper = IMapper::getService();

    ALOGE("jpegfeature2 test started");
    bServiceDied = false;

    sp<CameraPostProcCallBacks> pCallbacks = new CameraPostProcCallBacks();

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&encodeWait, NULL);

    CreateParams            encCreate;
    BufferParams            bufferParams;
    HandleParams            inHandle;
    HandleParams            outHandle;
    ProcessRequestParams    encParams;

    Error error   = Error::INVALID_HANDLE;
    auto  hidl_cb = [&](const auto reqId, const auto tmpError)
    {
        if (Error::NONE != tmpError)
        {
            error = tmpError;
        }
        else
        {
            error     = Error::NONE;
            requestId = reqId;
        }
    };

    ALOGE("connecting to postprocservice ");
    android::sp<IPostProcService> service = IPostProcService::getService("camerapostprocservice");
    if (service == nullptr) {
        ALOGE("getService is NULL for postprocservice");
        pCallbacks = nullptr;
        return 0;
    }

    ALOGE("connected to postprocservice ");
    mClientDeathReceipient = new PostProcClientDeathRecipient();

    service->linkToDeath(mClientDeathReceipient, 0L);

    ALOGE("postprocservice is linkToDeath done, go to sleep for 1sec");
    usleep(1000000);
    ALOGE("postprocservice is linkToDeath done, after sleep");


    bufferParams.width      = 4608;
    bufferParams.height     = 3456;
    bufferParams.format     = (uint32_t) PixelFormat::YCBCR_420_888;

    encCreate.input.resize(1);
    encCreate.output.resize(1);
    encCreate.postProcTypeVal   = PostProcType::JPEG;
    encCreate.input[0]          = bufferParams;
    // output differ by just format type
    bufferParams.format         = (uint32_t) 0x00000021; // blob format
    encCreate.output[0]         = bufferParams;

    encParams.input.resize(1);
    encParams.output.resize(1);
    encParams.streamId  = 0;

    android::sp<IPostProcSession> encoder = service->createPostProcessor(encCreate, pCallbacks);
    if (encoder == nullptr)
    {
        ALOGE("createEncoder returned failure");
        service = nullptr;
        encoder = nullptr;
        pCallbacks = nullptr;
        return 0;
    }

    ALOGE("PostprocTest started, pCallbacks %p, service %p, Encoder %p",
          pCallbacks.get(), service.get(), encoder.get());


    const native_handle_t* inh;


    inh  = GrallocAlloc(PixelFormat::YCBCR_420_888, width_12M, height_12M, 0, nullptr);
    outh = GrallocAlloc(PixelFormat::YCBCR_420_888,width_12M*2, height_12M*2, 0, nullptr);

    if (!inh ||!outh)
    {
        ALOGE("inh or outh are NULL");
        GrallocFree(inh);
        GrallocFree(outh);
        service = nullptr;
        encoder = nullptr;
        pCallbacks = nullptr;
        return 0;
    }

    ALOGE("encode started");

    uint8_t status = true;
    uint8_t async  = true;

    for (uint32_t t = 0; t < 3 && !bServiceDied; t ++)
    {
        char * inbuf;

        inbuf_size = ((width_12M + 63) / 64 * 64) * ((height_12M + 63) / 64 * 64) * 1.5;
        inbuf = (char*)mmap(NULL, inbuf_size, (PROT_READ | PROT_WRITE), MAP_SHARED, inh->data[0], 0);

        if (!inbuf)
        {
            ALOGE("format verify format %d error: mmap input", t);
            break;
        }
        else
        {
            ALOGE("input buffer size is %d", inbuf_size);
        }

        if (LoadFrame(inbuf))
        {
            ALOGE("format verify format %d error: load Frame", t);
            munmap(inbuf, inbuf_size);
            status = false;
            break;
        }

        munmap(inbuf, inbuf_size);

        const hidl_handle in_hidl(inh);
        const hidl_handle out_hidl(outh);

        const CameraMetadata settings;

        if (0 == clipIndex)
        {
            inHandle.width      = 4608;
            inHandle.height     = 3456;
            inHandle.format     = (uint32_t) PixelFormat::YCBCR_420_888;
            outHandle.width     = 4608;
            outHandle.height    = 3456;
            outHandle.format    = (uint32_t) 0x00000021;// blob format
        }
        else
        {
            inHandle.width      = 640;
            inHandle.height     = 480;
            inHandle.format     = (uint32_t) PixelFormat::YCBCR_420_888;
            outHandle.width     = 640;
            outHandle.height    = 480;
            outHandle.format    = (uint32_t) 0x00000021;// blob format
        }

        inHandle.bufHandle  = in_hidl;
        outHandle.bufHandle = out_hidl;
        encParams.input[0]  = inHandle;
        encParams.output[0] = outHandle;
        encParams.streamId  = 0;
        encParams.metadata  = settings;


        Return<void> ret = encoder->process(encParams, hidl_cb);

        if (Error::NONE != error)
        {
            ALOGE("process request failed");
            status = false;
            break;
        }
        else
        {
            ALOGE("process request queued, requestId %d", requestId);
        }

        if (bServiceDied)
        {
            ALOGE("serviceDied notification received from service ");
        }
        // usleep(1000000);

        // If multiple resolutions needs to be verified with single handle use this code to serialize
#if 0
        ALOGE("Waiting for signal from pCallbacks ");
        pthread_cond_wait(&encodeWait, &mutex);
        clipIndex = !clipIndex;
        ALOGE("Signal from pCallbacks is received, clipIndex %d", clipIndex);
        async = false;
#endif
    }

    if (!bServiceDied && status && async)
    {
        ALOGE("Waiting for signal from pCallbacks ");
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&encodeWait, &mutex);
        pthread_mutex_unlock(&mutex);
        ALOGE("Signal from pCallbacks is received");
    }

    if (!bServiceDied)
    {
        ALOGE("bServiceDied %d, release resources, status %d", bServiceDied, status);
        service->unlinkToDeath(mClientDeathReceipient);
        service.clear();
        encoder.clear();
        encoder = NULL;
        service = NULL;
        //usleep(100000);
    }

    ALOGE("encode completed, bServiceDied %d", bServiceDied);

    mClientDeathReceipient.clear();
    mClientDeathReceipient = NULL;


    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&encodeWait);
    pCallbacks.clear();
    pCallbacks = NULL;
    ALOGE(" Test case exited");

	return 0;
}
