////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////
// Copyright (c) 2021 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////

/********************************************************************/
/**
 * @file    tl_dev_afe_map.h
 * @brief   AFE device address mapping
 */
/********************************************************************/

#ifndef H_TL_DEV_AFE_MAP
#define H_TL_DEV_AFE_MAP

/*--------------------------------------------------------------------
    include headers
--------------------------------------------------------------------*/
#include <stdint.h>

/*--------------------------------------------------------------------
  definitions
  --------------------------------------------------------------------*/
#define TL_AFE_SLAVE_ADDR                   (0x64U)      /* AFE device slave address */
#define TL_AFE_ARY_SIZE(ary)                (sizeof((ary)) / sizeof((ary)[0]))
#define TL_AFE_WDR                          (0x0002U)    /* WDR mode */

/*----------------------------*/
/* AFE information address    */
/*----------------------------*/
#define TL_AFE_REVISION_ADDR                (0xC0FFU)    /* AFE revision */

/*----------------------------*/
/* AFE setting address & data */
/*----------------------------*/
#define TL_AFE_I2C_RESET_ADDR               (0xC022U)    /* reset of AFE address */
                                                         /* [note] writing "1" to this address, AFE will reboot */
                                                         /* therefore, ACK will not return. */
#define TL_AFE_I2C_RESET_ADDR_SWAP          (0x22C0U)    /* reset of AFE address(swap value) */
                                                         /* writing address is big endian, therefore */

#define TL_AFE_OUTPUT_TYPE_ADDR             (0xC3DBU)    /* output type address */
#define TL_AFE_OUTPUT_TYPE_DEPTH_IR_VAL     (0x0000U)    /* output type Depth + IR value */
#define TL_AFE_OUTPUT_TYPE_DEPTH_IRBG_VAL   (0x0002U)    /* output type Depth + IR/BG value */
#define TL_AFE_OUTPUT_TYPE_BG_IR_VAL        (0x0001U)    /* output type BG + IR value */



/*-----------------------------------------*/
/* AFE setting address from EEPROM(common) */
/*-----------------------------------------*/
#define TL_AFE_SHD_OFFSET_ADDR              (0xC600U)    /* depth shading offset */
#define TL_AFE_SHD_DATA_ADDR                (0xC3C0U)    /* depth shading data */

#define TL_AFE_DFCT_PIX_TH_TBL_ADDR         (0xC318U)    /* dfct look up table value */
#define TL_AFE_DFCT_ADDR                    (0xC316U)    /* dfct setttng */

#define TL_AFE_SHP_LOC_ADDR                 (0xC044U)    /* SHP edge locations */
#define TL_AFE_SHD_LOC_ADDR                 (0xC046U)    /* SHD edge location */
#define TL_AFE_OUTPUT_ADDR                  (0xC3DAU)    /* AFE output setting */
#define TL_AFE_OUTPUTSEL_ADDR               (0xC3DBU)    /* image output setting(default) */
#define TL_AFE_VC_ADDR                      (0xC3DCU)    /* MIPI virtual channel setting */

#define TL_AFE_GRID3_ADDR                   (0xC32AU)    /* cut out setting */

#define TL_AFE_IR_GAIN_GMM_ADDR             (0xC371U)    /* IR gain & gamma setting */

#define TL_AFE_CHKR_ADDR                    (0xC30CU)    /* chkr setting */



/*-----------------------------------------*/
/* AFE setting address from EEPROM(mode)   */
/*-----------------------------------------*/
#define TL_AFE_READ_SIZE2_ADDR              (0xC3CCU)    /* when to start output */
#define TL_AFE_CHKR_START_V_ADDR            (0xC30EU)    /* Vsync timing address */

#define TL_AFE_NLR_ADDR                     (0xC382U)    /* nlr data address */

#define TL_AFE_ZERO_OFFSET_ADDR             (0xC37EU)    /* zero point offset address */
#define TL_AFE_DEPTH_SLOPE_ADDR             (0xC380U)    /* depth slope address */
#define TL_AFE_DEPTH3_SLOPE_ADDR            (0xC381U)     /* depth3 slope address */

#define TL_AFE_RATE_ADJUST_ADDR             (0xC324U)    /* rate adjust */
#define TL_AFE_ALIGN_ADDR                   (0xC301U)    /* align */
#define TL_AFE_READ_SIZE0_ADDR              (0xC3CAU)    /* read size0 */
#define TL_AFE_READ_SIZE3_ADDR              (0xC3CDU)    /* read size3 */
#define TL_AFE_ROI_ADDR                     (0xC3D2U)    /* ROI */

#define TL_AFE_GRID_ADDR                    (0xC327U)    /* grid */

#define TL_AFE_RAWNR_XPWR_ADDR              (0xC347U)    /* RAW-NR xpwr */
#define TL_AFE_RAWNR_BLTBL_ADDR             (0xC338U)    /* RAW-NR bl_tbl */
#define TL_AFE_RAWNR_MED_ADDR               (0xC345U)    /* RAW-NR med */
#define TL_AFE_RAWNR_BKTBL_ADDR             (0xC32BU)    /* RAW-NR bk_tbl */

#define TL_AFE_CORING_ADDR                  (0xC34AU)    /* coring address */

#define TL_AFE_DEPTH1_ADDR                  (0xC37FU)    /* depth1 address */
#define TL_AFE_CONTROL_ADDR                 (0xC300U)    /* depth control address */

#define TL_AFE_PLS_MOD_CTRL_ADDR            (0x7D11U)    /* contorl of TOF pluse address */
#define TL_AFE_PLS_MOD_VAL_ADDR             (0xC710U)    /* contorl of TOF pluse address */

#define TL_AFE_LDPOSBLKOUTEN_ADDR           (0xC084U)    /* LD positive edge setting */
#define TL_AFE_LDNEGBLKOUTEN_ADDR           (0xC085U)    /* LD negative edge setting */
#define TL_AFE_LD_ENABLE                    (0x0010U)    /* TAL enable setting data */

#define TL_AFE_TAL_EN_ADDR                  (0xC730U)    /* TAL enable setting address */
#define TL_AFE_TAL_DETECTOR_EN_ADDR         (0xC75EU)    /* TAL detector setting address */

#define TL_AFE_MODE_ADDR                    (0x4000U)    /* mode address */
#define TL_AFE_MODE0_VAL                    (0x0000U)    /* mode0 */
#define TL_AFE_MODE1_VAL                    (0x0001U)    /* mode1 */


/*----------------------*/
/* For exposure setting */
/*----------------------*/
typedef struct {
    uint16_t    long_val;        /* number of lumine(long) */
    uint16_t    short_val;       /* number of lumine(short) */
    uint16_t    lms_val;         /* number of lumine(lms) */
    uint16_t    read_size2;      /* when to start output */
    uint16_t    ccd_dummy;       /* ccd dummy transfer */
    uint16_t    chkr_start_v;    /* Vsync timing */
} tl_afe_exp_val;

#define TL_AFE_READ_SIZE_OFFSET  (7U)    /* offset of read_size2 */
#define TL_AFE_START_V_OFFSET    (750U)  /* offset of start_v */

#endif    /* H_TL_DEV_AFE_MAP */
