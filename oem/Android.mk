ifneq ($(CAMX_CHICDK_PATH),)
LOCAL_PATH := $(CAMX_CHICDK_PATH)/oem
else
LOCAL_PATH := $(call my-dir)
endif

include $(CAMX_CHICDK_OEM_PATH)/qcom/eeprom/truly_cmb433_eeprom/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/eeprom/cmk_imx577_eeprom/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2anchorsync/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2demux/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2frameselect/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2fusion/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2generic/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2graphselector/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2hdr/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2memcpy/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2mfsr/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2qcfa/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2rawhdr/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2rt/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2serializer/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2stub/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/feature2/chifeature2swmf/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/aecwrapper/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/afwrapper/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/awbwrapper/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/customhwnode/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/depth/build/android/Android.mk

ifeq ($(TARGET_BOARD_PLATFORM),$(MSMSTEPPE))
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/dewarp/build/android/Android.mk
endif

include $(CAMX_CHICDK_OEM_PATH)/qcom/node/dummyrtb/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/dummysat/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/dummystich/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/fcv/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/gpu/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/hafoverride/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/hvx/addconstant/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/hvx/binning/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/memcpy/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/nodeutils/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/remosaic/build/android/Android.mk

ifeq ($(TARGET_BOARD_PLATFORM),$(MSMSTEPPE))
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/swcac/build/android/Android.mk
endif

include $(CAMX_CHICDK_OEM_PATH)/qcom/node/staticaecalgo/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/staticafalgo/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/staticawbalgo/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/node/staticpdlibalgo/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/imx318/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/imx334/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/imx362/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/imx376/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/imx386/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/imx476/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/imx519/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/imx576/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/imx577/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/max7366_6dof/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/max7366_eyetrack/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/max7366_ov6211/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/max7366_ov9282/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/ov12a10/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/ov12a10_front/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/cmk_imx577/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/ov13855/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/ov13880/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/ov64b40/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/ov7251/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/ov9282/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/ov8856/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/s5k2l7/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/s5k2x5sp/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/s5k5e9yu05/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/imx481/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/imx586_aajh5/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/imx686/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/s5k3m5/build/android/Android.mk
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/s5k3p9/build/android/Android.mk

ifeq ($(TARGET_BOARD_PLATFORM),kona)
include $(CAMX_CHICDK_OEM_PATH)/qcom/sensor/imx563/build/android/Android.mk
endif

include $(CAMX_CHICDK_OEM_PATH)/qcom/utils/chilog/build/android/Android.mk
