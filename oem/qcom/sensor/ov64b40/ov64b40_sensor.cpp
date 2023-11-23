////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "camxsensordriverapi.h"
// NOWHINE ENTIRE FILE
#include <android/log.h>
#define OV64B40_DBG(fmt, args...) __android_log_print(ANDROID_LOG_INFO, "OV64B40", fmt, ##args)
#define MINVALUE(Value1, Value2) ((Value1) > (Value2) ? (Value2) : (Value1))
#define MAXVALUE(Value1, Value2) ((Value1) < (Value2) ? (Value2) : (Value1))
#define EVEN(Value) ((0 == ((Value) % 2))? (Value): (Value) + 1)
#define VERTICAL_OFFSET(resolutionIndex) (((resolutionIndex == 0) || (resolutionIndex == 1)) ? 12:12)//?
                                                      // Vertical offset for Full Size Mode is 5
                                                      // Vertical offset for Summation and SHDR modes are 10
#define MIN_LINE_COUNT(resolutionMode) ((SensorResolutionMode::SHDR == resolutionMode)? 4:4)
                                                      // Min LineCount for Full Size and Summation Mode is 4
                                                      // Min LineCount for SHDR Mode is 8
#define minVBlank(applyMiddleExposure) ((TRUE == applyMiddleExposure)? 0:0)//?
                                                      // Min VBlank is 150 lines for 3Exp SHDR
                                                      // Min VBlank is 148 lines for 2Exp SHDR
                                                      // This value is read from the register
                                                      // m_sys_frm_req_lei_sen_base_staggered_ref_min_proc_lines (0x200107E8)
                                                      // and remains constant until the mode changes.
                                                      // The value was read from the register while the mode was streaming,
                                                      // and the value was confirmed with the sensor vendor
#define readoutTime(resolutionIndex) (((3 == resolutionIndex) || (4 == resolutionIndex))? 0: 0)//?
                                                      // Readout Time is 6636 lines for 2840x2132 (Mode 3 & 4)
                                                      // Readout Time is 4020 lines for 2240x1260 (Mode 5 & 6)
                                                      // This value is read from the register
                                                      // m_sys_frm_req_lei_sen_base_staggered_ref_readout_lines (0x200107EC)
                                                      // and remains constant until the mode changes
                                                      // The value was read from the register while the mode was streaming,
                                                      // and the value was confirmed with the sensor vendor
#define ROUNDUP6(Value) ((Value) % 6 == 0)? (Value) : ((Value) + (6 - ((Value) % 6)))

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

static const UINT  OV64B40RegisterGainDecimator    = 256;                  ///< Register gain decimator factor
static const UINT  OV64B40DigitalGainDecimator     = 1024;                 ///< Digital gain decimator factor

static const UINT  OV64B40MinRegisterGain         = 0x0100;               ///< Minimum analog register gain
static const UINT  OV64B40MaxRegisterGain         = 0x1000;               ///< Maximum analog register gain
static const FLOAT OV64B40MinRealGain             = (OV64B40MinRegisterGain / OV64B40RegisterGainDecimator);///< Minimum analog real gain(1X)
static const FLOAT OV64B40MaxRealGain             = (OV64B40MaxRegisterGain / OV64B40RegisterGainDecimator);///< Maximum analog real gain(16X)
static const UINT  OV64B40MinDigitalRegisterGain   = 0x0400;               ///< Minimum digital gain
static const UINT  OV64B40MaxDigitalRegisterGain   = 0x4000;               ///< Maximum digital gain
static const FLOAT OV64B40MinDigitalGain          = (OV64B40MinDigitalRegisterGain / OV64B40DigitalGainDecimator);///< Minimum digital gain(1X)
static const FLOAT OV64B40MaxDigitalGain          = (OV64B40MaxDigitalRegisterGain / OV64B40DigitalGainDecimator);///< Maximum digital gain(16X)
                                                                           ///< Dig gain 1x = Reg gain 0x0400

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// RegisterToRealGain
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static FLOAT RegisterToRealGain(
    UINT registerGain)
{
    FLOAT tempRegisterGain = static_cast<FLOAT>(registerGain);

    if (OV64B40MaxRegisterGain < tempRegisterGain)
    {
        tempRegisterGain = OV64B40MaxRegisterGain;
    }
    else if (OV64B40MinRegisterGain > tempRegisterGain)
    {
        tempRegisterGain = OV64B40MinRegisterGain;
    }

    return  static_cast<FLOAT>(tempRegisterGain / OV64B40RegisterGainDecimator);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// RealToRegisterGain
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static UINT RealToRegisterGain(
    FLOAT realGain)
{
    FLOAT tempRealGain = realGain;
    UINT  registerGain = OV64B40MinRegisterGain;

   if (OV64B40MaxRealGain < tempRealGain)
    {
        tempRealGain = OV64B40MaxRealGain;
    }
    else if (2.0f >= realGain)
    {
        tempRealGain = ((int)(realGain * 128.0f)) / 128.0f;
    }
    else if (4.0f >= realGain)
    {
        tempRealGain = ((int)(realGain * 64.0f)) / 64.0f;
    }
    else if (8.0f >= realGain)
    {
        tempRealGain = ((int)(realGain * 32.0f)) / 32.0f;
    }
    else
    {
        tempRealGain = ((int)(realGain * 16.0f)) / 16.0f;
    }

    registerGain = static_cast<UINT>(tempRealGain * OV64B40RegisterGainDecimator);
    return registerGain;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CalculateDigitalGain
// Return digitalRegisterGain
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static UINT CalculateDigitalGain(
    FLOAT totalRealGain,
    FLOAT analogRealGain)
{
    UINT32 digitalMSB = 0, digitalLSB = 0, digitalGain = 0;

    FLOAT digitalRealGain = totalRealGain / analogRealGain;

    if (OV64B40MaxDigitalGain < digitalRealGain)
    {
        digitalRealGain = OV64B40MaxDigitalGain;
    }
    else if (OV64B40MinDigitalGain > digitalRealGain)
    {
        digitalRealGain = OV64B40MinDigitalGain;
    }

    return static_cast<UINT>(digitalRealGain * OV64B40DigitalGainDecimator);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FillExposureSettings
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 0
BOOL CalculateExposure(
    SensorExposureInfo*          pExposureInfo,
    SensorCalculateExposureData* pCalculateExposureData)
{
    INT     CITLong             = 0;   // Coarse Integration Time for Long Exposure Frame
    INT     CITMiddle           = 0;   // Coarse Integration Time for Middle Exposure Frame
    INT     CITShort            = 0;   // Coarse Integration Time for Short Exposure Frame
    INT     frameLengthLines    = 0;   // Frame Length Lines
    INT     minCIT              = 0;   // Minimum Coarse integration Time
    INT     maxCIT              = 0;   // Maximum Coarse Integration Time
    INT     maxCITLong          = 0;   // Maximum Coarse Integration Time
    INT     maxCITMiddle        = 0;   // Maximum Middle Coarse Integration Time
    INT     maxCITShort         = 0;   // Maximum Short Coarse Integration Time

    if (NULL == pExposureInfo || NULL == pCalculateExposureData)
    {
        return FALSE;
    }

   // Calculation for long exposure
    pExposureInfo->analogRegisterGain   = RealToRegisterGain(pCalculateExposureData->realGain);
    pExposureInfo->analogRealGain       = static_cast<FLOAT>(RegisterToRealGain(pExposureInfo->analogRegisterGain));
    pExposureInfo->digitalRegisterGain  = CalculateDigitalGain(pCalculateExposureData->realGain,
                                                   pExposureInfo->analogRealGain);
    pExposureInfo->digitalRealGain      = static_cast<FLOAT>(pExposureInfo->digitalRegisterGain) /
                                                   static_cast<FLOAT>(OV64B40DigitalGainDecimator);
    pExposureInfo->ISPDigitalGain       = pCalculateExposureData->realGain /
                                                   (pExposureInfo->analogRealGain * pExposureInfo->digitalRealGain);
    pExposureInfo->lineCount            = pCalculateExposureData->lineCount;


   if (TRUE == pCalculateExposureData->applyMiddleExposure)
   {
        CITMiddle = pCalculateExposureData->middleLinecount;
       if ((pCalculateExposureData->middleRealGain < pExposureInfo->analogRealGain) &&
           (pCalculateExposureData->middleRealGain < OV64B40MaxRealGain))
       {
           CITMiddle = pCalculateExposureData->middleLinecount *
                       (pCalculateExposureData->middleRealGain / pExposureInfo->analogRealGain);
           OV64B40_DBG("Updating Middle LC. CurrentLC: %d, UpdatedLC: %d",
                       pCalculateExposureData->middleLinecount,
                       CITMiddle);
       }
       // Calculation for middle exposure
       pExposureInfo->middleRegisterGain         = RealToRegisterGain(pCalculateExposureData->middleRealGain);
       pExposureInfo->middleAnalogRealGain       = static_cast<FLOAT>(RegisterToRealGain(pExposureInfo->middleRegisterGain));
       pExposureInfo->middleDigitalRegisterGain  = CalculateDigitalGain(pCalculateExposureData->middleRealGain,
                                                           pExposureInfo->middleAnalogRealGain);
       pExposureInfo->middleDigitalRealGain      = static_cast<FLOAT>(pExposureInfo->middleDigitalRegisterGain) /
                                                           static_cast<FLOAT>(OV64B40DigitalGainDecimator);
       pExposureInfo->middleISPDigitalGain       = pCalculateExposureData->middleRealGain /
                                                           (pExposureInfo->middleAnalogRealGain * pExposureInfo->middleDigitalRealGain);
       pExposureInfo->middleLinecount            = CITMiddle;
   }


   if (TRUE == pCalculateExposureData->applyShortExposure)
   {
        CITShort = pCalculateExposureData->shortLinecount;
       if ((pCalculateExposureData->shortRealGain < pExposureInfo->analogRealGain) &&
           (pCalculateExposureData->shortRealGain < OV64B40MaxRealGain))
       {
           CITShort = pCalculateExposureData->shortLinecount *
                       (pCalculateExposureData->shortRealGain / pExposureInfo->analogRealGain);
           OV64B40_DBG("Updating Short LC. CurrentLC: %d, UpdatedLC: %d",
                       pCalculateExposureData->shortLinecount,
                       CITShort);
       }
       // Calculation for short exposure
       pExposureInfo->shortRegisterGain         = RealToRegisterGain(pCalculateExposureData->shortRealGain);
       pExposureInfo->shortAnalogRealGain       = static_cast<FLOAT>(RegisterToRealGain(pExposureInfo->shortRegisterGain));
       pExposureInfo->shortDigitalRegisterGain  = CalculateDigitalGain(pCalculateExposureData->shortRealGain,
                                                           pExposureInfo->shortAnalogRealGain);
       pExposureInfo->shortDigitalRealGain      = static_cast<FLOAT>(pExposureInfo->shortDigitalRegisterGain) /
                                                           static_cast<FLOAT>(OV64B40DigitalGainDecimator);
       pExposureInfo->shortISPDigitalGain       = pCalculateExposureData->shortRealGain /
                                                           (pExposureInfo->shortAnalogRealGain * pExposureInfo->shortDigitalRealGain);
       pExposureInfo->shortLinecount            = CITShort;
   }

   frameLengthLines = pCalculateExposureData->frameLengthLines;
   if (SensorResolutionMode::SHDR == pCalculateExposureData->sensorResolutionMode)
   {
       // FLL of Summation mode (1Exp SHDR) must be even
       if ((FALSE == pCalculateExposureData->applyMiddleExposure) &&
       (FALSE == pCalculateExposureData->applyShortExposure))
       {
           frameLengthLines = EVEN(frameLengthLines);
       }
       // FLL for 2Exp SHDR and 3Exp SHDR must be a multiple of 6
       else
       {
           frameLengthLines = ROUNDUP6(frameLengthLines);
       }
   }

   minCIT           = MIN_LINE_COUNT(pCalculateExposureData->sensorResolutionMode);
   maxCIT           = frameLengthLines - VERTICAL_OFFSET(pCalculateExposureData->sensorResolutionIndex);
   // CITLong should range between min CIT and maxCIT
   CITLong = pExposureInfo->lineCount;
   CITLong = MAXVALUE(CITLong, minCIT);
   CITLong = MINVALUE(CITLong, maxCIT);
   pExposureInfo->lineCount = CITLong;

   // In case of 2 Exp SHDR
   if (FALSE == pCalculateExposureData->applyMiddleExposure &&
       TRUE == pCalculateExposureData->applyShortExposure &&
       SensorResolutionMode::SHDR == pCalculateExposureData->sensorResolutionMode)
   {
       CITShort = pExposureInfo->shortLinecount;

       // M+S < FLL - min VBlank - Readout
       // Although we program only L & S per request, JD1 doesn't technically support a 2Exp
       // SHDR mode. It has a 3Exp SHDR mode and sends out only 2 frames per request.
       // Thus we cannot ignore internal timing of M in the calculation
       maxCITShort = (frameLengthLines - minVBlank(pCalculateExposureData->applyMiddleExposure) -
                       readoutTime(pCalculateExposureData->sensorResolutionIndex))/2;

       // CITShort should range between min CIT and maxCIT
       CITShort = MAXVALUE(CITShort, minCIT);
       CITShort = MINVALUE(CITShort, maxCITShort);

       // L + S < FLL
       maxCITLong = frameLengthLines - CITShort;
       CITLong = MINVALUE((maxCITLong - 1), CITLong);

       pExposureInfo->lineCount       = CITLong;
       pExposureInfo->shortLinecount  = CITShort;
   }

   pExposureInfo->frameLengthLines = frameLengthLines;


   OV64B40_DBG("AG [Long: %f, Middle: %f, Short: %f], DG [Long: %f, Middle: %f, Short: %f] "
       " ISP [Long: %f, Middle: %f, Short: %f] LC: [Long: %d, Middle: %d, Short: %d], FLL: %d",
       pExposureInfo->analogRealGain,
       pExposureInfo->middleAnalogRealGain,
       pExposureInfo->shortAnalogRealGain,
       pExposureInfo->digitalRealGain,
       pExposureInfo->middleDigitalRealGain,
       pExposureInfo->shortDigitalRealGain,
       pExposureInfo->ISPDigitalGain,
       pExposureInfo->middleISPDigitalGain,
       pExposureInfo->shortISPDigitalGain,
       pExposureInfo->lineCount,
       pExposureInfo->middleLinecount,
       pExposureInfo->shortLinecount,
       pExposureInfo->frameLengthLines);

    return TRUE;
}
#else
BOOL CalculateExposure(
    SensorExposureInfo*          pExposureInfo,
    SensorCalculateExposureData* pCalculateExposureData)
{
    if (NULL == pExposureInfo || NULL == pCalculateExposureData)
    {
        return FALSE;
    }

    pExposureInfo->analogRegisterGain   = RealToRegisterGain(pCalculateExposureData->realGain);
    pExposureInfo->analogRealGain       = static_cast<FLOAT>(RegisterToRealGain(pExposureInfo->analogRegisterGain));
    pExposureInfo->digitalRegisterGain  = CalculateDigitalGain(pCalculateExposureData->realGain, pExposureInfo->analogRealGain);
    pExposureInfo->digitalRealGain      = static_cast<FLOAT>(pExposureInfo->digitalRegisterGain) /
                                                   static_cast<FLOAT>(OV64B40DigitalGainDecimator);
    pExposureInfo->ISPDigitalGain       = pCalculateExposureData->realGain /
                                                   (pExposureInfo->analogRealGain * pExposureInfo->digitalRealGain);
    pExposureInfo->lineCount            = pCalculateExposureData->lineCount;

    return TRUE;
}
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FillExposureSettings
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 0
BOOL FillExposureSettings(
    RegSettingsInfo*        pRegSettingsInfo,
    SensorFillExposureData* pExposureData)
{
    UINT32  index     = 0;
    UINT    regCount  = 0;

    if ((NULL == pRegSettingsInfo) || (NULL == pExposureData))
    {
        return FALSE;
    }
    /*
    For fullsize resolutions, the exposure is 1line, for other resolutions, the exposure step is 2line, the sensor works as an even number
   regardless of the writeen base number or even number.
    */
    for (index = 0; index < pExposureData->pRegInfo->groupHoldOnSettings.regSettingCount; index++)
    {
        pRegSettingsInfo->regSetting[regCount].registerAddr =
            pExposureData->pRegInfo->groupHoldOnSettings.regSetting[index].registerAddr;
        pRegSettingsInfo->regSetting[regCount].registerData =
            pExposureData->pRegInfo->groupHoldOnSettings.regSetting[index].registerData;
        pRegSettingsInfo->regSetting[regCount].regAddrType  =
            pExposureData->pRegInfo->groupHoldOnSettings.regSetting[index].regAddrType;
        pRegSettingsInfo->regSetting[regCount].regDataType  =
            pExposureData->pRegInfo->groupHoldOnSettings.regSetting[index].regDataType;
        pRegSettingsInfo->regSetting[regCount].delayUs      =
            pExposureData->pRegInfo->groupHoldOnSettings.regSetting[index].delayUs;
        regCount++;
    }

   OV64B40_DBG("Exposure Normal: linecnt:%d; ARegGain:%d; DRegGain:%d; coarseIntgTimeAddr:0x%x",
           pExposureData->lineCount,
           pExposureData->analogRegisterGain,
           pExposureData->digitalRegisterGain,
           pExposureData->pRegInfo->coarseIntgTimeAddr);

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->frameLengthLinesAddr;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->frameLengthLines >> 8) & 0xFF;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->frameLengthLinesAddr + 1;
    pRegSettingsInfo->regSetting[regCount].registerData  = pExposureData->frameLengthLines & 0xFF;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->coarseIntgTimeAddr;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->lineCount >> 16) & 0xFF;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->coarseIntgTimeAddr + 1;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->lineCount >> 8) & 0xFF;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr = pExposureData->pRegInfo->coarseIntgTimeAddr + 2;
    pRegSettingsInfo->regSetting[regCount].registerData = pExposureData->lineCount & 0xFF;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->globalAnalogGainAddr;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->analogRegisterGain >> 7) & 0x7F;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->globalAnalogGainAddr+ 1;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->analogRegisterGain << 1) & 0xFE;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->GlobalDigitalGainAddr;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->digitalRegisterGain >> 10) & 0x0F;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->GlobalDigitalGainAddr + 1;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->digitalRegisterGain >> 2) & 0xFF;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->GlobalDigitalGainAddr + 2;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->digitalRegisterGain << 6) & 0xC0;
    regCount++;

   if (TRUE == pExposureData->applyMiddleExposure)
   {
       OV64B40_DBG("Exposure Middle: linecnt:%d; ARegGain:%d; DRegGain:%d",
               pExposureData->middleLineCount,
               pExposureData->middleRegisterGain,
               pExposureData->middleDigitalRegisterGain);
       pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->middleCoarseIntgTimeAddr;
       pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->middleLineCount >> 16) & 0xFF;
       regCount++;

       pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->middleCoarseIntgTimeAddr + 1;
       pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->middleLineCount >> 8) & 0xFF;
       regCount++;

       pRegSettingsInfo->regSetting[regCount].registerAddr = pExposureData->pRegInfo->middleCoarseIntgTimeAddr + 2;
       pRegSettingsInfo->regSetting[regCount].registerData = pExposureData->middleLineCount & 0xFF;
       regCount++;

       pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->middleGlobalAnalogGainAddr;
       pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->middleRegisterGain >> 7) & 0x7F;
       regCount++;

       pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->middleGlobalAnalogGainAddr+ 1;
       pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->middleRegisterGain << 1) & 0xFE;
       regCount++;

       pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->middleGlobalDigitalGainAddr;
       pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->middleDigitalRegisterGain >> 10) & 0x0F;
       regCount++;

       pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->middleGlobalDigitalGainAddr + 1;
       pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->middleDigitalRegisterGain >> 2) & 0xFF;
       regCount++;

       pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->middleGlobalDigitalGainAddr + 2;
       pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->middleDigitalRegisterGain << 6) & 0xC0;
       regCount++;
   }


   if (TRUE == pExposureData->applyShortExposure)
   {
       OV64B40_DBG("Exposure Short: linecnt:%d; ARegGain:%d; DRegGain:%d; coarseIntgTimeAddr:0x%x",
               pExposureData->shortLineCount,
               pExposureData->shortRegisterGain,
               pExposureData->shortDigitalRegisterGain,
               pExposureData->pRegInfo->shortCoarseIntgTimeAddr);

       pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->shortCoarseIntgTimeAddr;
       pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->shortLineCount >> 16) & 0xFF;
       regCount++;

       pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->shortCoarseIntgTimeAddr + 1;
       pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->shortLineCount >> 8) & 0xFF;
       regCount++;

       pRegSettingsInfo->regSetting[regCount].registerAddr = pExposureData->pRegInfo->shortCoarseIntgTimeAddr + 2;
       pRegSettingsInfo->regSetting[regCount].registerData = pExposureData->shortLineCount & 0xFF;
       regCount++;

       pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->shortGlobalAnalogGainAddr;
       pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->shortRegisterGain >> 7) & 0x7F;
       regCount++;

       pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->shortGlobalAnalogGainAddr+ 1;
       pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->shortRegisterGain << 1) & 0xFE;
       regCount++;

       pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->shortGlobalDigitalGainAddr;
       pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->shortDigitalRegisterGain >> 10) & 0x0F;
       regCount++;

       pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->shortGlobalDigitalGainAddr + 1;
       pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->shortDigitalRegisterGain >> 2) & 0xFF;
       regCount++;

       pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->shortGlobalDigitalGainAddr + 2;
       pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->shortDigitalRegisterGain << 6) & 0xC0;
       regCount++;
   }


    for (index = 0; (pExposureData->pRegInfo->groupHoldOnSettings.regSettingCount + index) < regCount; index++)
    {
        pRegSettingsInfo->regSetting[pExposureData->pRegInfo->groupHoldOnSettings.regSettingCount + index].regAddrType  =
            I2CRegAddressDataTypeWord;
        pRegSettingsInfo->regSetting[pExposureData->pRegInfo->groupHoldOnSettings.regSettingCount + index].regDataType  =
            I2CRegAddressDataTypeByte;
        pRegSettingsInfo->regSetting[pExposureData->pRegInfo->groupHoldOnSettings.regSettingCount + index].delayUs      =
            0;
    }

    for (index = 0; index < pExposureData->pRegInfo->groupHoldOffSettings.regSettingCount; index++)
    {
        pRegSettingsInfo->regSetting[regCount].registerAddr  =
            pExposureData->pRegInfo->groupHoldOffSettings.regSetting[index].registerAddr;
        pRegSettingsInfo->regSetting[regCount].registerData  =
            pExposureData->pRegInfo->groupHoldOffSettings.regSetting[index].registerData;
        pRegSettingsInfo->regSetting[regCount].regAddrType  =
            pExposureData->pRegInfo->groupHoldOffSettings.regSetting[index].regAddrType;
        pRegSettingsInfo->regSetting[regCount].regDataType=
            pExposureData->pRegInfo->groupHoldOffSettings.regSetting[index].regDataType;
        regCount++;
    }

    pRegSettingsInfo->regSettingCount = regCount;

    if (MAX_REG_SETTINGS <= regCount)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}
#else
BOOL FillExposureSettings(
    RegSettingsInfo*        pRegSettingsInfo,
    SensorFillExposureData* pExposureData)
{
    UINT32  index     = 0;
    UINT    regCount  = 0;

    if ((NULL == pRegSettingsInfo) || (NULL == pExposureData))
    {
        return FALSE;
    }

    for (index = 0; index < pExposureData->pRegInfo->groupHoldOnSettings.regSettingCount; index++)
    {
        pRegSettingsInfo->regSetting[regCount].registerAddr =
            pExposureData->pRegInfo->groupHoldOnSettings.regSetting[index].registerAddr;
        pRegSettingsInfo->regSetting[regCount].registerData =
            pExposureData->pRegInfo->groupHoldOnSettings.regSetting[index].registerData;
        pRegSettingsInfo->regSetting[regCount].regAddrType  =
            pExposureData->pRegInfo->groupHoldOnSettings.regSetting[index].regAddrType;
        pRegSettingsInfo->regSetting[regCount].regDataType  =
            pExposureData->pRegInfo->groupHoldOnSettings.regSetting[index].regDataType;
        pRegSettingsInfo->regSetting[regCount].delayUs      =
            pExposureData->pRegInfo->groupHoldOnSettings.regSetting[index].delayUs;
        regCount++;
    }

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->frameLengthLinesAddr;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->frameLengthLines & 0xFF00) >> 8;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->frameLengthLinesAddr + 1;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->frameLengthLines & 0xFF);
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->coarseIntgTimeAddr;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->lineCount >> 16) & 0x0F;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->coarseIntgTimeAddr + 1;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->lineCount >> 8) & 0xFF;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr = pExposureData->pRegInfo->coarseIntgTimeAddr + 2;
    pRegSettingsInfo->regSetting[regCount].registerData = pExposureData->lineCount & 0xFF;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->globalAnalogGainAddr;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->analogRegisterGain & 0xFF00) >> 8;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->globalAnalogGainAddr+ 1;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->analogRegisterGain & 0xFF);
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->digitalGainBlueAddr;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->digitalRegisterGain & 0xFF00) >> 8;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->digitalGainBlueAddr+ 1;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->digitalRegisterGain & 0xFF);
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->digitalGainGreenBlueAddr;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->digitalRegisterGain & 0xFF00) >> 8;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->digitalGainGreenBlueAddr + 1;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->digitalRegisterGain & 0xFF);
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->digitalGainGreenRedAddr;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->digitalRegisterGain & 0xFF00) >> 8;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->digitalGainGreenRedAddr + 1;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->digitalRegisterGain & 0xFF);
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->digitalGainRedAddr;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->digitalRegisterGain & 0xFF00) >> 8;
    regCount++;

    pRegSettingsInfo->regSetting[regCount].registerAddr  = pExposureData->pRegInfo->digitalGainRedAddr + 1;
    pRegSettingsInfo->regSetting[regCount].registerData  = (pExposureData->digitalRegisterGain & 0xFF);
    regCount++;

    for (index = 0; (pExposureData->pRegInfo->groupHoldOnSettings.regSettingCount + index) < regCount; index++)
    {
        pRegSettingsInfo->regSetting[pExposureData->pRegInfo->groupHoldOnSettings.regSettingCount + index].regAddrType  =
            I2CRegAddressDataTypeWord;
        pRegSettingsInfo->regSetting[pExposureData->pRegInfo->groupHoldOnSettings.regSettingCount + index].regDataType  =
            I2CRegAddressDataTypeByte;
        pRegSettingsInfo->regSetting[pExposureData->pRegInfo->groupHoldOnSettings.regSettingCount + index].delayUs      =
            0;
    }

    for (index = 0; index < pExposureData->pRegInfo->groupHoldOffSettings.regSettingCount; index++)
    {
        pRegSettingsInfo->regSetting[regCount].registerAddr  =
            pExposureData->pRegInfo->groupHoldOffSettings.regSetting[index].registerAddr;
        pRegSettingsInfo->regSetting[regCount].registerData  =
            pExposureData->pRegInfo->groupHoldOffSettings.regSetting[index].registerData;
        pRegSettingsInfo->regSetting[regCount].regAddrType  =
            pExposureData->pRegInfo->groupHoldOffSettings.regSetting[index].regAddrType;
        pRegSettingsInfo->regSetting[regCount].regDataType=
            pExposureData->pRegInfo->groupHoldOffSettings.regSetting[index].regDataType;
        regCount++;
    }

    pRegSettingsInfo->regSettingCount = regCount;

    if (MAX_REG_SETTINGS <= regCount)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// GetSensorLibraryAPIs
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VOID GetSensorLibraryAPIs(
    SensorLibraryAPI* pSensorLibraryAPI)
{
    pSensorLibraryAPI->majorVersion          = 1;
    pSensorLibraryAPI->minorVersion          = 0;
    pSensorLibraryAPI->pCalculateExposure    = CalculateExposure;
    pSensorLibraryAPI->pFillExposureSettings = FillExposureSettings;
}

#ifdef __cplusplus
} // CamX Namespace
#endif // __cplusplus

