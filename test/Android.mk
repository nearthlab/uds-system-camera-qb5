ifneq ($(CAMX_CHICDK_PATH),)
LOCAL_PATH := $(CAMX_CHICDK_PATH)/test
#CAMX_CHICDK_TEST_PATH := $(LOCAL_PATH)
else
LOCAL_PATH := $(call my-dir)
endif

include $(CAMX_CHICDK_TEST_PATH)/chifeature2test/build/android/Android.mk
include $(CAMX_CHICDK_TEST_PATH)/chifeature2testframework/build/android/Android.mk
include $(CAMX_CHICDK_TEST_PATH)/chiofflinepostproctest/build/android/Android.mk
include $(CAMX_CHICDK_TEST_PATH)/f2player/build/android/Android.mk
