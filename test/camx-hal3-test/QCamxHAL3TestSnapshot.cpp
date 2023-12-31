////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2018-2020 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  QCamxHAL3TestSnapshot.cpp
/// @brief Test for snapshot
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "QCamxHAL3TestSnapshot.h"

#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "QCamxHAL3Test"

typedef enum {
    PREVIEW_IDX   =  0,
    SNAPSHOT_IDX  =  1,
} StreamIdx;

/************************************************************************
* name : QCamxHAL3TestSnapshot
* function: construct object.
************************************************************************/
QCamxHAL3TestSnapshot::QCamxHAL3TestSnapshot(camera_module_t* module, QCamxHAL3TestConfig* config)
{
    init(module, config);
    mSnapshotNum = 0;
}

/************************************************************************
* name : ~QCamxHAL3TestSnapshot
* function: destory object.
************************************************************************/
QCamxHAL3TestSnapshot::~QCamxHAL3TestSnapshot()
{
    deinit();
}

/************************************************************************
* name : CapturePostProcess
* function: callback for postprocess capture result.
************************************************************************/
void QCamxHAL3TestSnapshot::CapturePostProcess(DeviceCallback* cb, camera3_capture_result *result)
{
    const camera3_stream_buffer_t* buffers = NULL;
    QCamxHAL3TestSnapshot* testsnap = (QCamxHAL3TestSnapshot*)cb;
    QCamxHAL3TestDevice* device = testsnap->mDevice;
    buffers = result->output_buffers;

    for (uint32_t i = 0;i < result->num_output_buffers ;i++) {
        int index = device->findStream(buffers[i].stream);
        CameraStream* stream = device->mCameraStreams[index];
        BufferInfo* info = stream->bufferManager->getBufferInfo(buffers[i].buffer);
        if (stream->streamType == CAMERA3_TEMPLATE_STILL_CAPTURE) {
            if (mCbs && mCbs->snapshot_cb) {
                mCbs->snapshot_cb(info, result->frame_number);
            }
            if (mSnapshotNum > 0) {
                QCamxHAL3TestCase::DumpFrame(info, result->frame_number, SNAPSHOT_TYPE);
                mSnapshotNum--;
                QCAMX_INFO("Get One Picture %d Last\n", mSnapshotNum);
            }
        }
        if (stream->streamType == CAMERA3_TEMPLATE_PREVIEW) {
            if (mCbs && mCbs->preview_cb) {
                mCbs->preview_cb(info, result->frame_number);
            }
            if (testsnap->mDumpPreviewNum > 0 &&
                (mDumpInterval == 0 ||
                (mDumpInterval > 0 && result->frame_number % mDumpInterval == 0))) {
                QCamxHAL3TestCase::DumpFrame(info, result->frame_number, PREVIEW_TYPE);
                if (mDumpInterval == 0) {
                    testsnap->mDumpPreviewNum--;
                }
            }
            if (mConfig->mShowFps) {
                showFPS(PREVIEW_TYPE);
            }
        }
    }
}

/************************************************************************
* name : initSnapshotStreams
* function: private function for init streams for snapshot.
************************************************************************/
int QCamxHAL3TestSnapshot::initSnapshotStreams()
{
    int res = 0;
    int32_t SensorOrientation = 0;
    //init stream configure
    bool supportsPartialResults;
    uint32_t partialResultCount;
    std::vector<AvailableStream> outputPreviewStreams;
    AvailableStream previewThreshold = {
        mConfig->mPreviewStream.width,
        mConfig->mPreviewStream.height,
        mConfig->mPreviewStream.format};
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

    std::vector<AvailableStream> outputSnapshotStreams;
    AvailableStream snapshotThreshold = {
        mConfig->mSnapshotStream.width,
        mConfig->mSnapshotStream.height,
        mConfig->mSnapshotStream.format};
    if (res == 0){
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

    //get SensorOrientation metadata.
    camera_metadata_ro_entry entry;
    res = find_camera_metadata_ro_entry(mDevice->mCharacteristics,
        ANDROID_SENSOR_ORIENTATION, &entry);
    if ((0 == res) && (entry.count > 0)) {
        SensorOrientation = entry.data.i32[0];
        QCAMX_INFO("successfully to get SensorOrientation metadata, orientation: %d", SensorOrientation);
    } else {
        QCAMX_ERR("Failed to get SensorOrientation metadata, return: %d", res);
        res = 0;
    }

    mDevice->setSyncBufferMode(SYNC_BUFFER_INTERNAL);
    mDevice->setFpsRange(mConfig->mFpsRange[0], mConfig->mFpsRange[1]);
    mDevice->configureStreams(mStreams);

    if (mMetadataExt) {
        mDevice->setCurrentMeta(mMetadataExt);
        mDevice->constructDefaultRequestSettings(PREVIEW_IDX, CAMERA3_TEMPLATE_PREVIEW);
    } else {
        mDevice->constructDefaultRequestSettings(PREVIEW_IDX, CAMERA3_TEMPLATE_PREVIEW, true);
    }

    mDevice->constructDefaultRequestSettings(SNAPSHOT_IDX,CAMERA3_TEMPLATE_STILL_CAPTURE);

    uint8_t jpegquality     = JPEG_QUALITY_DEFAULT;
    int32_t jpegOrientation = SensorOrientation;
    uint8_t ZslEnable       = ANDROID_CONTROL_ENABLE_ZSL_FALSE;
    android::CameraMetadata* metaUpdate = getCurrentMeta();
    (*metaUpdate).update(ANDROID_JPEG_QUALITY,&(jpegquality),sizeof(jpegquality));
    (*metaUpdate).update(ANDROID_JPEG_ORIENTATION, &(jpegOrientation), 1);

    if (mConfig->mZslEnabled) {
        ZslEnable = ANDROID_CONTROL_ENABLE_ZSL_TRUE;
    }
    (*metaUpdate).update(ANDROID_CONTROL_ENABLE_ZSL, &(ZslEnable), 1);

    updataMetaDatas(metaUpdate);

    return res;
}

int QCamxHAL3TestSnapshot::PreinitStreams()
{
    int res = 0;
    QCAMX_INFO("preinit snapshot streams start\n");

    int stream_num = 2;

    mPreviewStream.stream_type = CAMERA3_STREAM_OUTPUT;
    mPreviewStream.width  = mConfig->mPreviewStream.width;
    mPreviewStream.height = mConfig->mPreviewStream.height;
    mPreviewStream.format = mConfig->mPreviewStream.format;
    mPreviewStream.data_space = HAL_DATASPACE_UNKNOWN;
    // for Full Test UseCase
    if (mConfig->mZslEnabled) {
        mPreviewStream.usage =
            GRALLOC_USAGE_HW_COMPOSER    |
            GRALLOC_USAGE_HW_TEXTURE     |
            GRALLOC_USAGE_HW_CAMERA_READ |
            GRALLOC_USAGE_HW_CAMERA_WRITE;
    } else {
        mPreviewStream.usage =
            GRALLOC_USAGE_SW_READ_OFTEN  |
            GRALLOC_USAGE_SW_WRITE_OFTEN |
            GRALLOC_USAGE_HW_CAMERA_READ |
            GRALLOC_USAGE_HW_CAMERA_WRITE;
    }
    mPreviewStream.rotation = 0;
    mPreviewStream.max_buffers = PREVIEW_STREAM_BUFFER_MAX;
    mPreviewStream.priv = 0;

    mSnapshotStream.stream_type = CAMERA3_STREAM_OUTPUT;
    mSnapshotStream.width = mConfig->mSnapshotStream.width;
    mSnapshotStream.height = mConfig->mSnapshotStream.height;
    mSnapshotStream.format = mConfig->mSnapshotStream.format;
    mSnapshotStream.data_space = HAL_DATASPACE_V0_JFIF;
    mSnapshotStream.usage = GRALLOC_USAGE_SW_READ_OFTEN;
    mSnapshotStream.rotation = 0;
    mSnapshotStream.max_buffers = SNAPSHOT_STREAM_BUFFER_MAX;
    mSnapshotStream.priv = 0;

    mStreams.resize(stream_num);
    mStreams[PREVIEW_IDX] = &mPreviewStream;
    mStreams[SNAPSHOT_IDX] = &mSnapshotStream;

    mDevice->PreAllocateStreams(mStreams);
    QCAMX_INFO("preinit snapshot streams end\n");
    return res;
}

/************************************************************************
* name : run
* function: interface for create snapshot thread.
************************************************************************/
void QCamxHAL3TestSnapshot::run()
{
    //open camera
    QCAMX_PRINT("CameraId:%d\n",mConfig->mCameraId);
    mDevice->setCallBack(this);
    initSnapshotStreams();

    CameraThreadData* resultThread = new CameraThreadData();
    CameraThreadData* requestThread = new CameraThreadData();

    requestThread->requestNumber[PREVIEW_IDX] = REQUEST_NUMBER_UMLIMIT;
    if (mConfig->mSnapshotStream.format == HAL_PIXEL_FORMAT_BLOB) {
        requestThread->requestNumber[SNAPSHOT_IDX] = 0;
    } else {
        requestThread->requestNumber[SNAPSHOT_IDX] = REQUEST_NUMBER_UMLIMIT;
    }

    mDevice->processCaptureRequestOn(requestThread,resultThread);
}

/************************************************************************
* name : stop
* function:  stop all the thread and release the device object.
************************************************************************/
void QCamxHAL3TestSnapshot::stop()
{
    mDevice->stopStreams();
}

/************************************************************************
* name : RequestCaptures
* function: populate capture request.
************************************************************************/
void QCamxHAL3TestSnapshot::RequestCaptures(StreamCapture request)
{
    mSnapshotNum = request.count;
    if (mConfig->mSnapshotStream.format != HAL_PIXEL_FORMAT_BLOB) {
        return;
    }

    // send a message to request thread
    pthread_mutex_lock(&mDevice->mRequestThread->mutex);
    CameraRequestMsg* msg = new CameraRequestMsg();
    memset(msg,0,sizeof(CameraRequestMsg));
    msg->requestNumber[SNAPSHOT_IDX] = request.count;
    msg->mask = 1 << SNAPSHOT_IDX;
    msg->msgType = REQUEST_CHANGE;
    mDevice->mRequestThread->msgQueue.push_back(msg);
    QCAMX_INFO("Msg for capture picture mask%x \n",msg->mask);
    pthread_cond_signal(&mDevice->mRequestThread->cond);
    pthread_mutex_unlock(&mDevice->mRequestThread->mutex);
}
