ifneq ($(CAMX_CHICDK_PATH),)
LOCAL_PATH := $(CAMX_CHICDK_PATH)/core
else
LOCAL_PATH := $(call my-dir)
endif

include $(CAMX_CHICDK_CORE_PATH)/chifeature2/build/android/Android.mk
include $(CAMX_CHICDK_CORE_PATH)/chiframework/build/android/Android.mk
include $(CAMX_CHICDK_CORE_PATH)/chiofflinepostproclib/build/android/Android.mk
include $(CAMX_CHICDK_CORE_PATH)/chiofflinepostprocservice/build/android/Android.mk
include $(CAMX_CHICDK_CORE_PATH)/chiusecase/build/android/Android.mk
include $(CAMX_CHICDK_CORE_PATH)/chiutils/build/android/Android.mk
include $(CAMX_CHICDK_CORE_PATH)/lib/build/android/Android.mk
