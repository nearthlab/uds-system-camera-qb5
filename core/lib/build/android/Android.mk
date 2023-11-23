ifeq ($(CAMX_CHICDK_CORE_PATH),)
LOCAL_PATH := $(abspath $(call my-dir)/../..)
CAMX_CHICDK_CORE_PATH := $(abspath $(LOCAL_PATH)/..)
else
LOCAL_PATH := $(CAMX_CHICDK_CORE_PATH)/lib
endif

include $(CLEAR_VARS)

# Module supports function call tracing via ENABLE_FUNCTION_CALL_TRACE
# Required before including common.mk
SUPPORT_FUNCTION_CALL_TRACE := 1

# Get definitions common to the CAMX project here
include $(CAMX_CHICDK_PATH)/core/build/android/common.mk

LOCAL_INC_FILES :=

LOCAL_SRC_FILES :=

LOCAL_C_LIBS := $(CAMX_C_LIBS)

LOCAL_C_INCLUDES :=                 \
    $(CAMX_C_INCLUDES)

# Compiler flags
LOCAL_CFLAGS := $(CAMX_CFLAGS)
LOCAL_CPPFLAGS := $(CAMX_CPPFLAGS)

LOCAL_STATIC_LIBRARIES :=

LOCAL_WHOLE_STATIC_LIBRARIES :=     \
    libchifeature2                  \
    libchiframework                 \
    libchiutils                     \
    libchiusecase

LOCAL_SHARED_LIBRARIES +=                                   \
    libcamera_metadata                                      \
    libchilog                                               \
    libcutils                                               \
    libhardware                                             \
    libhidlbase                                             \
    libhidltransport                                        \
    liblog                                                  \
    libqdMetaData                                           \
    libsync                                                 \
    libutils                                                \
    vendor.qti.hardware.camera.postproc@1.0-service-impl    \
    vendor.qti.hardware.vpp@1.1                             \
    vendor.qti.hardware.vpp@1.2

# Libraries to link
# Build in vendor partition
LOCAL_PROPRIETARY_MODULE := true

# Deployment path under lib/lib64
LOCAL_MODULE_RELATIVE_PATH := hw

LOCAL_MODULE := com.qti.chi.override

include $(BUILD_SHARED_LIBRARY)
