////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2018-2020 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  QCamxHAL3TestVideo.cpp
/// @brief TestCase for Video
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "QCamxHAL3TestVideo.h"

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "QCamxHAL3Test"

typedef enum {
    PREVIEW_IDX   =  0,
    VIDEO_IDX     =  1,
    SNAPSHOT_IDX  =  2,
} StreamIdx;

QCamxHAL3TestVideo::QCamxHAL3TestVideo(camera_module_t* module, QCamxHAL3TestConfig* config)
{
    init(module, config);

    mVideoMode = VIDEO_MODE_NORMAL;
    mIsStoped = true;
    #ifdef ENABLE_VIDEO_ENCODER
    mVideoEncoder = new QCamxTestVideoEncoder(mConfig);
    #endif
}

/************************************************************************
* name : ~QCamxHAL3TestVideo
* function: destruct object
************************************************************************/
QCamxHAL3TestVideo::~QCamxHAL3TestVideo()
{
    deinit();
}

/************************************************************************
* name : CapturePostProcess
* function: Do post process
************************************************************************/
void QCamxHAL3TestVideo::CapturePostProcess(DeviceCallback* cb, camera3_capture_result *result)
{
    const camera3_stream_buffer_t* buffers = NULL;
    buffers = result->output_buffers;

    for (uint32_t i = 0;i < result->num_output_buffers ;i++) {
        int index = mDevice->findStream(buffers[i].stream);
        CameraStream* stream = mDevice->mCameraStreams[index];
        BufferInfo* info = stream->bufferManager->getBufferInfo(buffers[i].buffer);
        if (stream->streamId == SNAPSHOT_IDX) {
            if (mCbs && mCbs->snapshot_cb) {
                mCbs->snapshot_cb(info, result->frame_number);
            }
            QCamxHAL3TestCase::DumpFrame(info, result->frame_number, SNAPSHOT_TYPE);
            stream->bufferManager->ReturnBuffer(buffers[i].buffer);
         } else if (stream->streamId == VIDEO_IDX) {
            if (mCbs && mCbs->video_cb) {
                mCbs->video_cb(info, result->frame_number);
            }
            if (mDumpVideoNum > 0 &&
                (mDumpInterval == 0 ||
                (mDumpInterval > 0 && result->frame_number % mDumpInterval == 0))) {
                QCamxHAL3TestCase::DumpFrame(info, result->frame_number, VIDEO_TYPE);
                if (mDumpInterval == 0) {
                    mDumpVideoNum--;
                }
            }
            if (mIsStoped) {
                stream->bufferManager->ReturnBuffer(buffers[i].buffer);
            } else {
                EnqueueFrameBuffer(stream,buffers[i].buffer);
            }
            if (mConfig->mShowFps) {
                showFPS(VIDEO_TYPE);
            }
        } else if (stream->streamId == PREVIEW_IDX) {
            if (mCbs && mCbs->preview_cb) {
                mCbs->preview_cb(info, result->frame_number);
            }
            if (mDumpPreviewNum > 0 &&
                (mDumpInterval == 0 ||
                (mDumpInterval > 0 && result->frame_number % mDumpInterval == 0))) {
                QCamxHAL3TestCase::DumpFrame(info, result->frame_number, PREVIEW_TYPE);
                if (mDumpInterval == 0) {
                    mDumpPreviewNum--;
                }
            }
            stream->bufferManager->ReturnBuffer(buffers[i].buffer);

            if (mConfig->mShowFps) {
                showFPS(PREVIEW_TYPE);
            }

        }
    }
}

/************************************************************************
* name : selectOpMode
* function: choose suitable operate mode.
************************************************************************/
void QCamxHAL3TestVideo::selectOpMode(uint32_t *operation_mode,int width,int height,
    int fps)
{
    uint32_t tags = 0;
    const int32_t *sensorModeTable = NULL;
    int res = 0;

    sp<VendorTagDescriptor> vTags =
        android::VendorTagDescriptor::getGlobalVendorTagDescriptor();
    camera_metadata_ro_entry entry;
    CameraMetadata::getTagFromName("org.quic.camera2.sensormode.info.SensorModeTable",
        vTags.get(), &tags);

    res = find_camera_metadata_ro_entry(mDevice->mCharacteristics, tags, &entry);
    if ((res == 0) && (entry.count > 0)) {
        sensorModeTable = entry.data.i32;
    }

    int modeCount = sensorModeTable[0];
    int modeSize = sensorModeTable[1];
    int sensorMode = -1;
    int s_width,s_height,s_fps,matched_fps;

    matched_fps = MAX_SENSOR_FPS;

    for (int i = 0; i < modeCount; i++) {
        s_width  =  sensorModeTable[2 + i*modeSize];
        s_height =  sensorModeTable[3 + i*modeSize];
        s_fps    =  sensorModeTable[4 + i*modeSize];

        if ((s_width >= width) &&
            (s_height >= height) &&
            (s_fps >= fps) &&
            (s_fps <= matched_fps)) {
            matched_fps = s_fps;
            sensorMode = i;
        }
    }

    if (sensorMode > 0) {
        // use StreamConfigModeSensorMode in camx
        *operation_mode = (*operation_mode) | ((sensorMode + 1) << 16) | (0x1 << 24);
    }
}

/************************************************************************
* name : initVideoStreams
* function: init video stream
************************************************************************/
int QCamxHAL3TestVideo::initVideoStreams()
{
    int res = 0;

    //init stream configure
    //check preview stream
    bool supportsPartialResults;
    uint32_t partialResultCount;
    std::vector<AvailableStream> outputPreviewStreams;
    QCAMX_PRINT("preview:%dx%d %d\n",
        mConfig->mPreviewStream.width,
        mConfig->mPreviewStream.height,
        mConfig->mPreviewStream.format);

    AvailableStream previewThreshold = {
        mConfig->mPreviewStream.width,
        mConfig->mPreviewStream.height,
        mConfig->mPreviewStream.format
    };
    if (res == 0) {
        camera_metadata_ro_entry entry;
        res = find_camera_metadata_ro_entry(mDevice->mCharacteristics,
            ANDROID_REQUEST_PARTIAL_RESULT_COUNT, &entry);
        if ((0 == res) && (entry.count > 0)) {
            partialResultCount = entry.data.i32[0];
            supportsPartialResults = (partialResultCount > 1);
        }
        res = mDevice->GetValidOutputStreams(outputPreviewStreams, &previewThreshold);
    }
    if (res < 0 || outputPreviewStreams.size() == 0) {
        QCAMX_ERR("Failed to find output stream for preview: w: %d, h: %d, fmt: %d",
            mConfig->mPreviewStream.width, mConfig->mPreviewStream.height,
            mConfig->mPreviewStream.format);
        return -1;
    }

    //check video stream
    std::vector<AvailableStream> outputVideoStreams;
    QCAMX_PRINT("video:%dx%d %d\n",
        mConfig->mVideoStream.width,
        mConfig->mVideoStream.height,
        mConfig->mVideoStream.format);

    AvailableStream videoThreshold = {
        mConfig->mVideoStream.width,
        mConfig->mVideoStream.height,
        mConfig->mVideoStream.format
    };

    if (res == 0) {
        camera_metadata_ro_entry entry;
        res = find_camera_metadata_ro_entry(mDevice->mCharacteristics,
            ANDROID_REQUEST_PARTIAL_RESULT_COUNT, &entry);
        if ((0 == res) && (entry.count > 0)) {
            partialResultCount = entry.data.i32[0];
            supportsPartialResults = (partialResultCount > 1);
        }
        res = mDevice->GetValidOutputStreams(outputVideoStreams, &videoThreshold);
    }
    if (res < 0 || outputVideoStreams.size() == 0) {
        QCAMX_ERR("Failed to find output stream for video: w: %d, h: %d, fmt: %d",
            mConfig->mVideoStream.width, mConfig->mVideoStream.height,
            mConfig->mVideoStream.format);
        return -1;
    }

    //check snapshot stream
    if (mStreams.size() == 3 && mVideoMode <= VIDEO_MODE_HFR60) {
        std::vector<AvailableStream> outputSnapshotStreams;
        QCAMX_PRINT("snapshot:%dx%d %d\n",
            mConfig->mSnapshotStream.width,
            mConfig->mSnapshotStream.height,
            mConfig->mSnapshotStream.format);

        AvailableStream snapshotThreshold = {
            mConfig->mSnapshotStream.width,
            mConfig->mSnapshotStream.height,
            mConfig->mSnapshotStream.format
        };
        if (res == 0) {
            camera_metadata_ro_entry entry;
            res = find_camera_metadata_ro_entry(mDevice->mCharacteristics,
                ANDROID_REQUEST_PARTIAL_RESULT_COUNT, &entry);
            if ((0 == res) && (entry.count > 0)) {
                partialResultCount = entry.data.i32[0];
                supportsPartialResults = (partialResultCount > 1);
            }
            res = mDevice->GetValidOutputStreams(outputSnapshotStreams, &snapshotThreshold);
        }
        if (res < 0 || outputSnapshotStreams.size() == 0) {
            QCAMX_ERR("Failed to find output stream for snapshot: w: %d, h: %d, fmt: %d",
                mConfig->mSnapshotStream.width, mConfig->mSnapshotStream.height,
                mConfig->mSnapshotStream.format);
            return -1;
        }
    }

    mDevice->setSyncBufferMode(SYNC_BUFFER_EXTERNAL);
    mDevice->setFpsRange(mConfig->mFpsRange[0], mConfig->mFpsRange[1]);

    uint32_t operation_mode = CAMERA3_STREAM_CONFIGURATION_NORMAL_MODE;
    if (mVideoMode >= VIDEO_MODE_HFR60) {
        // for HFR case
        int stream_size = 0;
        int stream_index = 0;
        for (int i = 0;i < (int)mStreams.size();i++) {
            if ((mStreams[i]->width * mStreams[i]->height) > stream_size) {
                stream_size = mStreams[i]->width * mStreams[i]->height;
                stream_index = i;
            }
        }
        operation_mode = CAMERA3_STREAM_CONFIGURATION_CONSTRAINED_HIGH_SPEED_MODE;
        selectOpMode(&operation_mode,mStreams[stream_index]->width,
            mStreams[stream_index]->height,mConfig->mFpsRange[1]);
    }

    mDevice->configureStreams(mStreams,operation_mode);

    mDevice->constructDefaultRequestSettings(PREVIEW_IDX, mConfig->mPreviewStream.type);

    if (mMetadataExt) {
        mDevice->setCurrentMeta(mMetadataExt);
        mDevice->constructDefaultRequestSettings(VIDEO_IDX, CAMERA3_TEMPLATE_VIDEO_RECORD );
    } else {
        mDevice->constructDefaultRequestSettings(VIDEO_IDX, CAMERA3_TEMPLATE_VIDEO_RECORD , true);
    }

    if (mVideoMode <= VIDEO_MODE_HFR60) {
        mDevice->constructDefaultRequestSettings(SNAPSHOT_IDX, CAMERA3_TEMPLATE_VIDEO_SNAPSHOT);
    }

    android::CameraMetadata* metaUpdate = getCurrentMeta();
    sp<VendorTagDescriptor> vTags =
        android::VendorTagDescriptor::getGlobalVendorTagDescriptor();

    uint8_t antibanding = ANDROID_CONTROL_AE_ANTIBANDING_MODE_AUTO;
    metaUpdate->update(ANDROID_CONTROL_AE_ANTIBANDING_MODE,&(antibanding),sizeof(antibanding));

    uint8_t afmode = ANDROID_CONTROL_AF_MODE_CONTINUOUS_VIDEO;
    metaUpdate->update(ANDROID_CONTROL_AF_MODE, &(afmode), 1);
    uint8_t reqFaceDetectMode =  (uint8_t)ANDROID_STATISTICS_FACE_DETECT_MODE_OFF;
    metaUpdate->update(ANDROID_STATISTICS_FACE_DETECT_MODE,
            &reqFaceDetectMode, 1);

    if (mVideoMode <= VIDEO_MODE_HFR60) {
        uint8_t jpegquality = JPEG_QUALITY_DEFAULT;
        metaUpdate->update(ANDROID_JPEG_QUALITY,&(jpegquality),sizeof(jpegquality));
    }

    if (mVideoMode != VIDEO_MODE_NORMAL) {
        uint8_t videohdr = 0;
        uint8_t PCREnable = 0;
        uint8_t EISEnable = 0;
        uint32_t tag;
        uint8_t reqVstabMode = ANDROID_CONTROL_VIDEO_STABILIZATION_MODE_OFF;
        metaUpdate->update(ANDROID_CONTROL_VIDEO_STABILIZATION_MODE, &reqVstabMode, 1);

        uint8_t nr = ANDROID_NOISE_REDUCTION_MODE_FAST;
        metaUpdate->update(ANDROID_NOISE_REDUCTION_MODE, &(nr), 1);

        uint8_t antibanding = ANDROID_CONTROL_AE_ANTIBANDING_MODE_50HZ;
        metaUpdate->update(ANDROID_CONTROL_AE_ANTIBANDING_MODE,&antibanding,1);

        CameraMetadata::getTagFromName("org.quic.camera2.streamconfigs.HDRVideoMode",
            vTags.get(), &tag);
        metaUpdate->update(tag, &(videohdr), 1);

        CameraMetadata::getTagFromName("org.quic.camera.EarlyPCRenable.EarlyPCRenable",
            vTags.get(), &tag);
        metaUpdate->update(tag, &(PCREnable), 1);

        CameraMetadata::getTagFromName("org.quic.camera.eis3enable.EISV3Enable",
            vTags.get(), &tag);
        metaUpdate->update(tag, &(EISEnable), 1);
    }

    updataMetaDatas(metaUpdate);
    return res;
}

int QCamxHAL3TestVideo::PreinitStreams()
{
    int res = 0;
    int stream_num = 3;

    QCAMX_INFO("Preinit Video Streams \n");

    mPreviewStream.stream_type = CAMERA3_STREAM_OUTPUT;
    mPreviewStream.width = mConfig->mPreviewStream.width;
    mPreviewStream.height = mConfig->mPreviewStream.height;
    mPreviewStream.format = mConfig->mPreviewStream.format;
    if (mConfig->mPreviewStream.type == CAMERA3_TEMPLATE_VIDEO_RECORD) {
        mPreviewStream.usage =
            GRALLOC_USAGE_PRIVATE_0        |
            GRALLOC_USAGE_HW_VIDEO_ENCODER |
            GRALLOC_USAGE_HW_CAMERA_WRITE;
        mPreviewStream.data_space = HAL_DATASPACE_BT709;
    } else {
        mPreviewStream.usage =
            GRALLOC_USAGE_HW_COMPOSER    |
            GRALLOC_USAGE_HW_TEXTURE     |
            GRALLOC_USAGE_HW_CAMERA_WRITE;
        mPreviewStream.data_space = HAL_DATASPACE_UNKNOWN;
    }
    mPreviewStream.rotation = 0;
    if (mConfig->mFpsRange[1] > 60) {
        mPreviewStream.max_buffers = HFR_PREVIEW_STREAM_BUFFER_MAX;
    } else {
        mPreviewStream.max_buffers = PREVIEW_STREAM_BUFFER_MAX;
    }
    mPreviewStream.priv = 0;
    QCAMX_PRINT("preview stream max buffers: %d\n",mPreviewStream.max_buffers);

    // add video stream
    mVideoStream.stream_type = CAMERA3_STREAM_OUTPUT;//OUTPUT
    mVideoStream.width = mConfig->mVideoStream.width;
    mVideoStream.height = mConfig->mVideoStream.height;
    mVideoStream.format = mConfig->mVideoStream.format;
    mVideoStream.data_space = HAL_DATASPACE_BT709;
    mVideoStream.usage =
        GRALLOC_USAGE_PRIVATE_0        |
        GRALLOC_USAGE_HW_VIDEO_ENCODER |
        GRALLOC_USAGE_HW_CAMERA_WRITE;

    mVideoStream.rotation = 0;
    if (mConfig->mFpsRange[1] > 60) {
        mVideoStream.max_buffers = HFR_VIDEO_STREAM_BUFFER_MAX;
    } else {
        mVideoStream.max_buffers = VIDEO_STREAM_BUFFER_MAX;
    }
    mVideoStream.priv = 0;
    QCAMX_PRINT("video stream max buffers: %d\n",mVideoStream.max_buffers);

    // add snapshot stream
    mSnapshotStream.stream_type = CAMERA3_STREAM_OUTPUT;//OUTPUT
    mSnapshotStream.width = mConfig->mSnapshotStream.width;
    mSnapshotStream.height = mConfig->mSnapshotStream.height;
    mSnapshotStream.format = mConfig->mSnapshotStream.format;
    mSnapshotStream.data_space = HAL_DATASPACE_V0_JFIF;
    mSnapshotStream.usage = GRALLOC_USAGE_SW_READ_OFTEN;
    mSnapshotStream.rotation = 0;
    mSnapshotStream.max_buffers = SNAPSHOT_STREAM_BUFFER_MAX;
    mSnapshotStream.priv = 0;

    if (mConfig->mFpsRange[1] > 30 && mConfig->mFpsRange[1] <= 60) {
        // for HFR case such as 4K@60 and 1080p@60
        mVideoMode = VIDEO_MODE_HFR60;
    } else if (mConfig->mFpsRange[1] > 60 && mConfig->mFpsRange[1] <= 90) {
        // for HFR case such as 1080p@90
        mVideoMode = VIDEO_MODE_HFR90;
    } else if (mConfig->mFpsRange[1] > 90 && mConfig->mFpsRange[1] <= 120) {
        // for HFR case such as 1080p@120
        mVideoMode = VIDEO_MODE_HFR120;
    }else if (mConfig->mFpsRange[1] > 120 && mConfig->mFpsRange[1] <= 240) {
        // for HFR case such as 1080p@240
        mVideoMode = VIDEO_MODE_HFR240;
    }else if (mConfig->mFpsRange[1] > 240 && mConfig->mFpsRange[1] <= 480) {
        // for HFR case such as 720p@480
        mVideoMode = VIDEO_MODE_HFR480;
    }

    if (mVideoMode <= VIDEO_MODE_HFR60) {
        stream_num = 3;
        mStreams.resize(stream_num);
        mStreams[VIDEO_IDX] = &mVideoStream;
        mStreams[PREVIEW_IDX] = &mPreviewStream;
        mStreams[SNAPSHOT_IDX] = &mSnapshotStream;
    } else {
        stream_num = 2;
        mStreams.resize(stream_num);
        mStreams[VIDEO_IDX] = &mVideoStream;
        mStreams[PREVIEW_IDX] = &mPreviewStream;
    }

    mDevice->PreAllocateStreams(mStreams);

    return res;
}

/************************************************************************
* name : EnqueueFrameBuffer
* function: enqueue a frame to video encoder
************************************************************************/
void QCamxHAL3TestVideo::EnqueueFrameBuffer(CameraStream *stream,buffer_handle_t *buf_handle) {
    #ifdef ENABLE_VIDEO_ENCODER
    mVideoEncoder->EnqueueFrameBuffer(stream,buf_handle);
    #else
    stream->bufferManager->ReturnBuffer(buf_handle);
    #endif
}

/************************************************************************
* name : stop
* function: stop video tests
************************************************************************/
void QCamxHAL3TestVideo::stop()
{
    mIsStoped = true;
    #ifdef ENABLE_VIDEO_ENCODER
    mVideoEncoder->stop();
    #endif
    mDevice->stopStreams();
    #ifdef ENABLE_VIDEO_ENCODER
    delete mVideoEncoder;
    mVideoEncoder = NULL;
    #endif
    mDevice->setSyncBufferMode(SYNC_BUFFER_INTERNAL);
}

/************************************************************************
* name : RequestCaptures
* function: impliment "s" command
************************************************************************/
void QCamxHAL3TestVideo::RequestCaptures(StreamCapture request)
{
    // send a message to request thread
    pthread_mutex_lock(&mDevice->mRequestThread->mutex);
    CameraRequestMsg* msg = new CameraRequestMsg();
    memset(msg,0,sizeof(CameraRequestMsg));
    msg->requestNumber[SNAPSHOT_IDX] = request.count;
    msg->mask |= 1 << SNAPSHOT_IDX;
    msg->msgType = REQUEST_CHANGE;
    mDevice->mRequestThread->msgQueue.push_back(msg);
    QCAMX_INFO("Msg for capture picture mask%x \n",msg->mask);
    pthread_cond_signal(&mDevice->mRequestThread->cond);
    pthread_mutex_unlock(&mDevice->mRequestThread->mutex);
}

/************************************************************************
* name : run
* function: start video test case
************************************************************************/
void QCamxHAL3TestVideo::run()
{
    //open camera
    int res = 0;

    mDevice->setCallBack(this);
    res = initVideoStreams();

    if (mVideoMode <= VIDEO_MODE_HFR60) {
        mDevice->mLivingRequestExtAppend = LIVING_REQUEST_APPEND;
    } else {
        mDevice->mLivingRequestExtAppend = HFR_LIVING_REQUEST_APPEND;
    }
    #ifdef ENABLE_VIDEO_ENCODER
    mVideoEncoder->run();
    #endif
    mIsStoped = false;
    CameraThreadData* resultThreadVideo = new CameraThreadData();

    CameraThreadData* requestThreadVideo = new CameraThreadData();
    requestThreadVideo->requestNumber[VIDEO_IDX] = REQUEST_NUMBER_UMLIMIT;
    requestThreadVideo->requestNumber[PREVIEW_IDX] = REQUEST_NUMBER_UMLIMIT;

    if (mVideoMode > VIDEO_MODE_HFR60) {
        requestThreadVideo->skipPattern[PREVIEW_IDX] =
            ceil(((float)mVideoMode) / VIDEO_MODE_HFR60);
    }
    QCAMX_INFO("skipPattern[PREVIEW_IDX] = %d",
        requestThreadVideo->skipPattern[PREVIEW_IDX]);

    mDevice->processCaptureRequestOn(requestThreadVideo,resultThreadVideo);
}
