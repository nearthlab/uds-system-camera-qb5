////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2020 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "camxeepromdriverapi.h"

// NOWHINE ENTIRE FILE
#include "camxtypes.h"
#include <android/log.h>
#include "camxmem.h"
#include "camxdebugprint.h"
#include "camxosutils.h"
#include "camxdebug.h"
#include "tl_dev_eeprom_map.h"
#include "tl_dev_afe_map.h"
#include "tl_dev_local.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#define LONG_RANGE_MODE        0
#define SHORT_RANGE_MODE       1

#define CALIBRATION_LENGTH     51
#define LONG_RANGE_MODE_SIZE   51
#define SHORT_RANGE_MODE_SIZE  51

#define SETTING_SIZE_INIT      4000
#define SETTING_SIZE_CONFIG    500
#define SETTING_SIZE_STREAMON  50
#define SETTING_SIZE_STREAMOFF 50

tl_dev dev;

extern TL_E_RESULT tl_dev_eeprom_read(
        tl_dev *dev,
        uint8_t* otpdata,
        uint32_t otpdatasize);
extern TL_E_RESULT tl_dev_afe_init_param(tl_dev *dev, TOFCalibration* pTOFCalibration);
extern TL_E_RESULT tl_dev_afe_common_param(tl_dev *dev, TOFCalibration* pTOFCalibration);
extern TL_E_RESULT tl_dev_afe_set_mode(tl_dev *dev, TOFCalibration* pTOFCalibration);
extern TL_E_RESULT tl_dev_afe_streamon_param(tl_dev *dev, TOFCalibration* pTOFCalibration);
extern TL_E_RESULT tl_dev_afe_streamoff_param(tl_dev *dev, TOFCalibration* pTOFCalibration);

#define SHORT_RANGE_MODE_OFFSET  0
#define LONG_RANGE_MODE_OFFSET (SHORT_RANGE_MODE_SIZE * 2)

static UINT32 TOFLongRangeCalRegData[CALIBRATION_LENGTH];
static UINT32 TOFShortRangeCalRegData[CALIBRATION_LENGTH];
static UINT32 TOFInitSettingCalRegData[SETTING_SIZE_INIT];
static UINT32 TOFConfigSettingCalRegData[SETTING_SIZE_CONFIG];
static UINT32 TOFStreamOnSettingCalRegData[SETTING_SIZE_STREAMON];
static UINT32 TOFStreamOffSettingCalRegData[SETTING_SIZE_STREAMOFF];

static RegisterSetting InitRegSetting[SETTING_SIZE_INIT];
static RegisterSetting ConfigRegSetting[SETTING_SIZE_CONFIG];
static RegisterSetting StreamOnRegSetting[SETTING_SIZE_STREAMON];
static RegisterSetting StreamOffRegSetting[SETTING_SIZE_STREAMOFF];

static UINT32 TOFCalibrationRegAddres[CALIBRATION_LENGTH] = {
    0xC382,
    0xC383,
    0xC384,
    0xC385,
    0xC386,
    0xC387,
    0xC388,
    0xC389,
    0xC38A,
    0xC38B,
    0xC38C,
    0xC38D,
    0xC38E,
    0xC38F,
    0xC390,
    0xC391,
    0xC392,
    0xC393,
    0xC394,
    0xC395,
    0xC396,
    0xC397,
    0xC398,
    0xC399,
    0xC39A,
    0xC39B,
    0xC39C,
    0xC39D,
    0xC39E,
    0xC39F,
    0xC3A0,
    0xC3A1,
    0xC3A2,
    0xC3A3,
    0xC3A4,
    0xC3A5,
    0xC3A6,
    0xC3A7,
    0xC3A8,
    0xC3A9,
    0xC3AA,
    0xC3AB,
    0xC3AC,
    0xC3AD,
    0xC3AE,
    0xC3AF,
    0xC3B0,
    0xC3B1,
    0xC3B2,
    0xC37E,
    0xC381
};

static RegisterSetting longRangeModeRegSetting[LONG_RANGE_MODE_SIZE];
static RegisterSetting shortRangeModeRegSetting[SHORT_RANGE_MODE_SIZE];
//static RegisterSetting longRangeModeRegSetting;
//static RegisterSetting shortRangeModeRegSetting;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// format_longrangemode
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID format_longrangemode(
    UINT8*            otpdata,
    UINT32            otpdatasize,
    TOFCalibration*    pLongRangModeData)
{
    for (UINT32 index = 0; index < otpdatasize; index++) {
        MN34906_DBG("long range mode otpdata[%d] = %d", index, otpdata[index]);
    }

    pLongRangModeData->isAvailable = TRUE;
    pLongRangModeData->settings.regSettingCount= LONG_RANGE_MODE_SIZE;
    pLongRangModeData->settings.regSetting = &longRangeModeRegSetting[0];

    for (UINT32 index = 0; index < LONG_RANGE_MODE_SIZE; index++) {
        longRangeModeRegSetting[index].registerAddr       = TOFCalibrationRegAddres[index];
        TOFLongRangeCalRegData[index]                     = ((otpdata[2 * index + LONG_RANGE_MODE_OFFSET] << 8) + (otpdata[2 * index + 1 + LONG_RANGE_MODE_OFFSET]));
        longRangeModeRegSetting[index].registerData       = &TOFLongRangeCalRegData[index];
        longRangeModeRegSetting[index].registerData[0]    = TOFLongRangeCalRegData[index];
        longRangeModeRegSetting[index].regAddrType        = 2;
        longRangeModeRegSetting[index].regDataType        = 2;
        longRangeModeRegSetting[index].operation          = OperationType::WRITE;

        longRangeModeRegSetting[index].delayUsExists      = 0;
        longRangeModeRegSetting[index].delayUsID          = 0;
        longRangeModeRegSetting[index].delayUs            = 0;

        longRangeModeRegSetting[index].registerDataCount  = 1;
    }

    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// format_shortrangemode
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID format_shortrangemode(
    UINT8*            otpdata,
    UINT32            otpdatasize,
    TOFCalibration*   pShortRangModeData)
{
    for (UINT32 index = 0; index < otpdatasize; index++) {
        MN34906_DBG("short range mode otpdata[%d] = %d", index, otpdata[index]);
    }

    pShortRangModeData->isAvailable = TRUE;
    pShortRangModeData->settings.regSettingCount= SHORT_RANGE_MODE_SIZE;
    pShortRangModeData->settings.regSetting = &shortRangeModeRegSetting[0];

    for (UINT32 index = 0; index < SHORT_RANGE_MODE_SIZE; index++) {
        shortRangeModeRegSetting[index].registerAddr       = TOFCalibrationRegAddres[index];
        TOFShortRangeCalRegData[index]                     = (otpdata[2 * index] << 8) + (otpdata[2 * index + 1]);
        shortRangeModeRegSetting[index].registerData       = &TOFShortRangeCalRegData[index];
        shortRangeModeRegSetting[index].registerData[0]    = TOFShortRangeCalRegData[index];
        shortRangeModeRegSetting[index].regAddrType        = 2;
        shortRangeModeRegSetting[index].regDataType        = 2;
        shortRangeModeRegSetting[index].operation          = OperationType::WRITE;

        shortRangeModeRegSetting[index].delayUsExists      = 0;
        shortRangeModeRegSetting[index].delayUsID          = 0;
        shortRangeModeRegSetting[index].delayUs            = 0;
        shortRangeModeRegSetting[index].registerDataCount  = 1;
    }

    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DumpOtpData:
//     Dump the command and mode area(total 2160Byts) for support application customization
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static void DumpOtpData(UINT8* otpdata, UINT32 otpdatasize)
{
    FILE*  pDumpFile        = NULL;
    char   fileName[FILENAME_MAX] = { 0 };

    if (otpdata != NULL)
    {
        // format the filename
        snprintf(fileName, sizeof(fileName), "%s/%s_%s_%s", CamX::ConfigFileDirectory,
                          "mn34906", "eeprom", "raw.bin");
        pDumpFile = fopen(fileName, "wb");
    }

    if (pDumpFile != NULL)
    {
        // write the otpdata
        fwrite(otpdata, 1, otpdatasize, pDumpFile);
        fclose(pDumpFile);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// OtpdataVerify
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static UINT8 OtpdataVerify(
        UINT8* otpdata,
        UINT32 otpdatasize)
{
    TL_E_RESULT ret = TL_E_SUCCESS;

    ret = tl_dev_eeprom_read(&dev, otpdata, otpdatasize);
    if (ret != TL_E_SUCCESS) {
        DumpOtpData(otpdata, 20); //don't dump the full otpdata if data check failed.
        if (ret == TL_E_ERR_NOT_SUPPORT) {
            return TL_E_ERR_NOT_SUPPORT;
        }
        return TL_E_ERR_SYSTEM;
    }

    // dump the otpdata to folder ConfigFileDirectory, size TL_EEPROM_PUP_TOP
    DumpOtpData(otpdata, TL_EEPROM_PUP_TOP);

    return TL_E_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FormatInitSettings
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static UINT8 FormatInitSettings(
        UINT8* otpdata,
        UINT32 otpdatasize,
        TOFCalibration* pTOFCalibration)
{
    TL_E_RESULT ret = TL_E_SUCCESS;

    //MN34906_DBG("FormatInitSettings otpdatasize:%d E-->", otpdatasize);

    pTOFCalibration->settings.regSettingCount = 0;
    pTOFCalibration->settings.regSetting = &InitRegSetting[0];

    /* set initial parameters to AFE. */
    ret = tl_dev_afe_init_param(&dev, pTOFCalibration);
    if (ret != TL_E_SUCCESS) {
        return TL_E_ERR_SYSTEM;
    }
    //MN34906_DBG("FormatInitSettings otpdatasize:%d X<--", otpdatasize);
    return TL_E_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FormatResolutionSettings
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static UINT8 FormatResolutionSettings(
        UINT8* otpdata,
        UINT32 otpdatasize,
        UINT16 residx,
        TOFCalibration* pTOFCalibration)
{
    TL_E_RESULT ret = TL_E_SUCCESS;

    //MN34906_DBG("FormatResolutionSettings otpdatasize:%d E-->", otpdatasize);

    pTOFCalibration->settings.regSettingCount = 0;
    pTOFCalibration->settings.regSetting = &ConfigRegSetting[0];

    //get mode and image_type from resolution index, TL_E_IMAGE_TYPE_MAX:5
    dev.mode = (TL_E_MODE)(residx / TL_E_IMAGE_TYPE_MAX);             //mode 0/1
    dev.image_type = (TL_E_IMAGE_TYPE)(residx % TL_E_IMAGE_TYPE_MAX); //image type 0/1/2/3/4

    /* set common parameters to AFE. */
    ret = tl_dev_afe_common_param(&dev, pTOFCalibration);
    if (ret != TL_E_SUCCESS) {
        return TL_E_ERR_SYSTEM;
    }

    /* set mode parameters to AFE. */
    tl_dev_afe_set_mode(&dev, pTOFCalibration);
    if (ret != TL_E_SUCCESS) {
        return TL_E_ERR_SYSTEM;
    }

    //MN34906_DBG("FormatResolutionSettings otpdatasize:%d, mode:%d, image_type:%d X<--",
    //    otpdatasize, dev.mode, dev.image_type);
    return TL_E_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FormatStreamOnSettings
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static UINT8 FormatStreamOnSettings(
        UINT8* otpdata,
        UINT32 otpdatasize,
        TOFCalibration* pTOFCalibration)
{
    TL_E_RESULT ret = TL_E_SUCCESS;

    //MN34906_DBG("FormatStreamOnSettings otpdatasize:%d E-->", otpdatasize);

    pTOFCalibration->settings.regSettingCount = 0;
    pTOFCalibration->settings.regSetting = &StreamOnRegSetting[0];

    /* set streamon parameters to AFE. */
    ret = tl_dev_afe_streamon_param(&dev, pTOFCalibration);
    if (ret != TL_E_SUCCESS) {
        return TL_E_ERR_SYSTEM;
    }

    //MN34906_DBG("FormatStreamOnSettings otpdatasize:%d X<--", otpdatasize);
    return TL_E_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FormatStreamOffSettings
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static UINT8 FormatStreamOffSettings(
        UINT8* otpdata,
        UINT32 otpdatasize,
        TOFCalibration* pTOFCalibration)
{
    TL_E_RESULT ret = TL_E_SUCCESS;

    //MN34906_DBG("FormatStreamOffSettings otpdatasize:%d E-->", otpdatasize);

    pTOFCalibration->settings.regSettingCount = 0;
    pTOFCalibration->settings.regSetting = &StreamOffRegSetting[0];

    /* set streamoff parameters to AFE. */
    ret = tl_dev_afe_streamoff_param(&dev, pTOFCalibration);
    if (ret != TL_E_SUCCESS) {
        return TL_E_ERR_SYSTEM;
    }

    //MN34906_DBG("FormatStreamOffSettings otpdatasize:%d X<--", otpdatasize);
    return TL_E_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AddInitRegisterSetting
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID AddInitRegisterSetting(uint16_t addr, uint16_t data, OperationType operation, TOFCalibration* pTOFCalibration)
{
    uint16_t index = 0;

    pTOFCalibration->isAvailable = TRUE;
    index = pTOFCalibration->settings.regSettingCount;
    if (index >= SETTING_SIZE_INIT) {
        MN34906_DBG("%s: setting num %d over %d, ignore it", __FUNCTION__, index, SETTING_SIZE_INIT);
        return;
    }

    // ignore register 0xC022, IIC report failed due to ACK will not return.
    if (addr == TL_AFE_I2C_RESET_ADDR) {// 0xC022U /* reset of AFE address */
        return;
    }

    InitRegSetting[index].registerAddr       = addr;
    TOFInitSettingCalRegData[index]          = data;
    InitRegSetting[index].registerData       = &TOFInitSettingCalRegData[index];
    InitRegSetting[index].registerData[0]    = TOFInitSettingCalRegData[index];
    InitRegSetting[index].regAddrType        = 2;
    InitRegSetting[index].regDataType        = 2;
    InitRegSetting[index].operation          = OperationType::WRITE;

    InitRegSetting[index].delayUsExists      = 0;
    InitRegSetting[index].delayUsID          = 0;
    InitRegSetting[index].delayUs            = 0;
    InitRegSetting[index].registerDataCount  = 1;
    pTOFCalibration->settings.regSettingCount++;
    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AddResolutionRegisterSetting
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID AddResolutionRegisterSetting(uint16_t addr, uint16_t data, OperationType operation, TOFCalibration* pTOFCalibration)
{
    uint16_t index = 0;

    pTOFCalibration->isAvailable = TRUE;
    index = pTOFCalibration->settings.regSettingCount;
    if (index >= SETTING_SIZE_CONFIG) {
        MN34906_DBG("%s: setting num %d over %d, ignore it", __FUNCTION__, index, SETTING_SIZE_CONFIG);
        return;
    }

    ConfigRegSetting[index].registerAddr       = addr;
    TOFConfigSettingCalRegData[index]          = data;
    ConfigRegSetting[index].registerData       = &TOFConfigSettingCalRegData[index];
    ConfigRegSetting[index].registerData[0]    = TOFConfigSettingCalRegData[index];
    ConfigRegSetting[index].regAddrType        = 2;
    ConfigRegSetting[index].regDataType        = 2;
    ConfigRegSetting[index].operation          = OperationType::WRITE;

    ConfigRegSetting[index].delayUsExists      = 0;
    ConfigRegSetting[index].delayUsID          = 0;
    ConfigRegSetting[index].delayUs            = 0;
    ConfigRegSetting[index].registerDataCount  = 1;
    pTOFCalibration->settings.regSettingCount++;
    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AddStreamOnRegisterSetting
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID AddStreamOnRegisterSetting(uint16_t addr, uint16_t data, OperationType operation, TOFCalibration* pTOFCalibration)
{
    uint16_t index = 0;

    pTOFCalibration->isAvailable = TRUE;
    index = pTOFCalibration->settings.regSettingCount;
    if (index >= SETTING_SIZE_STREAMON) {
        MN34906_DBG("%s: setting num %d over %d, ignore it", __FUNCTION__, index, SETTING_SIZE_STREAMON);
        return;
    }

    StreamOnRegSetting[index].registerAddr       = addr;
    TOFStreamOnSettingCalRegData[index]          = data;
    StreamOnRegSetting[index].registerData       = &TOFStreamOnSettingCalRegData[index];
    StreamOnRegSetting[index].registerData[0]    = TOFStreamOnSettingCalRegData[index];
    StreamOnRegSetting[index].regAddrType        = 2;
    StreamOnRegSetting[index].regDataType        = 2;
    StreamOnRegSetting[index].operation          = OperationType::WRITE;

    StreamOnRegSetting[index].delayUsExists      = 0;
    StreamOnRegSetting[index].delayUsID          = 0;
    StreamOnRegSetting[index].delayUs            = 0;
    StreamOnRegSetting[index].registerDataCount  = 1;
    pTOFCalibration->settings.regSettingCount++;
    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// AddStreamOffRegisterSetting
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID AddStreamOffRegisterSetting(uint16_t addr, uint16_t data, OperationType operation, TOFCalibration* pTOFCalibration)
{
    uint16_t index = 0;

    pTOFCalibration->isAvailable = TRUE;
    index = pTOFCalibration->settings.regSettingCount;
    if (index >= SETTING_SIZE_STREAMOFF) {
        MN34906_DBG("%s: setting num %d over %d, ignore it", __FUNCTION__, index, SETTING_SIZE_STREAMOFF);
        return;
    }

    StreamOffRegSetting[index].registerAddr       = addr;
    TOFStreamOffSettingCalRegData[index]          = data;
    StreamOffRegSetting[index].registerData       = &TOFStreamOffSettingCalRegData[index];
    StreamOffRegSetting[index].registerData[0]    = TOFStreamOffSettingCalRegData[index];
    StreamOffRegSetting[index].regAddrType        = 2;
    StreamOffRegSetting[index].regDataType        = 2;
    StreamOffRegSetting[index].operation          = OperationType::WRITE;

    StreamOffRegSetting[index].delayUsExists      = 0;
    StreamOffRegSetting[index].delayUsID          = 0;
    StreamOffRegSetting[index].delayUs            = 0;
    StreamOffRegSetting[index].registerDataCount  = 1;
    pTOFCalibration->settings.regSettingCount++;
    return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GetEEPROMLibraryAPIs
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID GetEEPROMLibraryAPIs(
    EEPROMLibraryAPI* pEEPROMLibraryAPI)
{
    pEEPROMLibraryAPI->majorVersion       = 1;
    pEEPROMLibraryAPI->minorVersion       = 0;
    pEEPROMLibraryAPI->pFormatTOFLongRangeModeSettings  = NULL; //format_longrangemode;
    pEEPROMLibraryAPI->pFormatTOFShortRangeModeSettings = NULL; //format_shortrangemode;
    pEEPROMLibraryAPI->pOtpdataVerify                   = OtpdataVerify;
    pEEPROMLibraryAPI->pFormatTOFInitSettings           = FormatInitSettings;
    pEEPROMLibraryAPI->pFormatTOFResolutonSettings      = FormatResolutionSettings;
    pEEPROMLibraryAPI->pFormatTOFStreamOnSettings       = FormatStreamOnSettings;
    pEEPROMLibraryAPI->pFormatTOFStreamOffSettings      = FormatStreamOffSettings;
}

#ifdef __cplusplus
} // CamX Namespace
#endif // __cplusplus
