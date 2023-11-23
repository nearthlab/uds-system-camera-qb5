////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////
// Copyright (c) 2021 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////

/********************************************************************/
/**
 * @file    tl_dev_eeprom.c
 * @brief   load EEPROM for device control
 */
/********************************************************************/

/*--------------------------------------------------------------------
  include headers
  --------------------------------------------------------------------*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "camxeepromdriverapi.h"
#include "tl_dev_eeprom_map.h"
#include "tl_dev_eeprom.h"
#include "tl_dev_local.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#define TOTAL_EEPROM_DATA_SIZE 0x3870

static uint8_t* m_otpdata      = NULL;
static uint32_t m_otpdatasize  = 0;

/*------------------------------------------------------------------*/
/**
 * @brief    check map version
 * @param    [in]    map_ver         EEPROM map version
 * @return   TL_E_SUCCESS            success
 * @return   TL_E_ERR_NOT_SUPPORT    not supported map version
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_eeprom_check_map_version(uint16_t map_ver)
{
    uint8_t ver = (uint8_t)(map_ver >> 8U);
    if (((ver & 0xF0) != (TL_EEPROM_SUPPORT_MAP_VER & 0xF0)) || (ver > TL_EEPROM_SUPPORT_MAP_VER)) {
        return TL_E_ERR_NOT_SUPPORT;
    }
    return TL_E_SUCCESS;
}

#if 0
/*------------------------------------------------------------------*/
/**
 * @brief    check module type
 * @param    [in]    mod_type        module type
 * @return   TL_E_SUCCESS            success
 * @return   TL_E_ERR_NOT_SUPPORT    not supported module type
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_eeprom_check_module_type(uint16_t mod_type)
{
    uint8_t type = (uint8_t)(mod_type >> 12U);

    switch(type) {
    case (uint8_t)TL_E_EEPROM_MOD_TYPE_V4:    /* this software supports only V4 */
    case (uint8_t)TL_E_EEPROM_MOD_TYPE_V4T:
        break;
    default:
        return TL_E_ERR_NOT_SUPPORT;
    }
    return TL_E_SUCCESS;
}
#endif

/*------------------------------------------------------------------*/
/**
 * @brief    check exp_max and exp_default
 * @param    [in]  p_mode      mode information
 */
/*------------------------------------------------------------------*/
static void tl_dev_eeprom_check_exp(tl_dev_rom_mode *p_mode)
{
    //MN34906_DBG("%s: exp_max:0x%x, exp_default:0x%x E",
    //    __FUNCTION__, p_mode->exp.exp_max, p_mode->exp.exp_default);

    /* if not set maximum, set from ae parameter[far] */
    if (p_mode->exp.exp_max == 0U) {
        p_mode->exp.exp_max = p_mode->ae[2].lumine_num;
    }
    /* if not set default, set from ae parameter[near] */
    if (p_mode->exp.exp_default == 0U) {
        p_mode->exp.exp_default = p_mode->ae[0].lumine_num;
    }
    //MN34906_DBG("%s: exp_max:0x%x, exp_default:0x%x X",
    //    __FUNCTION__, p_mode->exp.exp_max, p_mode->exp.exp_default);
}

/*------------------------------------------------------------------*/
/**
 * @brief    calculate XOR
 * @param    [in]    p_top      start address
 * @param    [in]    num        number of data
 * @param    [in]    org        original value
 * @return    result of XOR
 */
/*------------------------------------------------------------------*/
static uint16_t tl_dev_eeprom_calc_xor(uint16_t *p_top, uint16_t num, uint16_t org_xor)
{
    uint16_t i;
    for( i=0; i<num; i++) {
        org_xor ^= *(p_top + i);
    }
    return org_xor;
}

/*------------------------------------------------------------------*/
/**
 * @brief    calculate check-sum(XOR)
 * @param    [in]    p_cmn_mode   common & mode area data
 * @param    [in]    p_pup        Power-Up Sequence area data
 * @param    [in]    pup_size     Power-Up Sequence area data size[byte]
 * @return    TL_E_SUCCESS        success
 * @return    TL_E_ERR_PARAM      bad argument
 * @return    TL_E_ERR_SYSTEM     checksum error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_eeprom_calc_chksum(
    uint16_t *p_cmn_mode, uint16_t *p_pup, uint16_t pup_size)
{
    uint16_t i, num, r_xor=0, *p_tmp, align = (uint16_t)sizeof(uint16_t);

    if ((p_cmn_mode == NULL) || (p_pup == NULL) || (pup_size == 0U)) {
        return TL_E_ERR_PARAM;
    }

    /* calc camera type & info(without CHECK_SUM) */
    p_tmp = p_cmn_mode;
    num   = (TL_EEPROM_CHECK_SUM - TL_EEPROM_CMN_TOP) / align;
    r_xor = tl_dev_eeprom_calc_xor(p_tmp, num, r_xor);
    /* after CHECK_SUM data */
    p_tmp = p_cmn_mode + TL_EEPROM_OFFSET(TL_EEPROM_CHECK_SUM) + 1U;
    r_xor = tl_dev_eeprom_calc_xor(p_tmp, 1U, r_xor);
    /* calc common area remain */
    p_tmp = p_cmn_mode + TL_EEPROM_OFFSET(TL_EEPROM_PLANER_PRM);
    num   = (TL_EEPROM_CMN_AREA_SIZE - TL_EEPROM_PLANER_PRM) / align;
    r_xor = tl_dev_eeprom_calc_xor(p_tmp, num, r_xor);
    /* calc mode area */
    for( i=0; i<(uint16_t)TL_MODE_MAX; i++) {
        p_tmp = p_cmn_mode + TL_EEPROM_OFFSET(TL_EEPROM_MODE_TOP(i));
        num   = TL_EEPROM_MODE_AREA_SIZE / align;
        r_xor = tl_dev_eeprom_calc_xor(p_tmp, num, r_xor);
    }
    /* calc Power-Up Sequence area */
    num   = pup_size / align;
    r_xor = tl_dev_eeprom_calc_xor(p_pup, num, r_xor);

    /* check CHECK_SUM */
    p_tmp = p_cmn_mode + TL_EEPROM_OFFSET(TL_EEPROM_CHECK_SUM);
    if (r_xor != *p_tmp) {
        return TL_E_ERR_SYSTEM;
    }

    //MN34906_DBG("%s: done", __FUNCTION__);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    calculate frame rate
 * @param    [in]    p_cmn_mode      common & mode area data
 * @param    [in]    p_pup           Power-Up Sequence area data
 * @param    [in]    pup_size        Power-Up Sequence area data size[byte]
 * @return   TL_E_SUCCESS            success
 * @return   TL_E_ERR_PARAM          bad argument
 * @return   TL_E_ERR_SYSTEM         checksum error
 */
/*------------------------------------------------------------------*/
static uint16_t tl_dev_eeprom_calc_fps(tl_dev_rom_exp_prm *p_exp_prm)
{
    float    vd = 0.0F, fps = 0.0F;
    uint16_t ifps = 0xFFFFU;
    uint32_t clk_width = ((uint32_t)p_exp_prm->clk_width_u << 16U) | ((uint32_t)p_exp_prm->clk_width_l);

    if (p_exp_prm->vd_duration <= 2U) {
        return 0xFFFFU;
    }
    if ((p_exp_prm->vd_duration % 3U) != 0U) {
        return 0xFFFFU;
    }
    if (p_exp_prm->num_clk_in_hd == 0U) {
        return 0xFFFFU;
    }
    if (clk_width == 0U) {
        return 0xFFFFU;
    }

    vd = (float)p_exp_prm->vd_duration * (float)p_exp_prm->num_clk_in_hd * ((float)clk_width / 1000000.0F);

    if (vd <= 0.0F) {
        return 0xFFFFU;
    } else {
        fps = 1.0F / (vd / 1000000000.0F);    /* convert nano sec to sec */
        ifps = (uint16_t)lroundf(fps);
        if (ifps == 0U) {
            return 0xFFFFU;
        }
    }

    return ifps;
}

/*------------------------------------------------------------------*/
/**
 * @brief    convert uint16_t aray to char aray [little endian]
 * @param    [in]    p_in16            uint16_t aray
 * @param    [out]   p_out8            char aray
 * @param    [in]    u16_num           number of uint16_t data
 */
/*------------------------------------------------------------------*/
static void tl_dev_eeprom_cnv_u16_c(uint16_t *p_in16, char *p_out8, uint16_t u16_num)
{
    uint16_t i, tmp;
    for( i=0; i<u16_num; i++) {
        tmp = *(p_in16 + i);
        *(p_out8 + (i * 2U)     ) = (char)((tmp & 0xFF00U) >> 8U);
        *(p_out8 + (i * 2U) + 1U) = (char)((tmp & 0x00FFU));
    }
}

/*------------------------------------------------------------------*/
/**
 * @brief    convert uint16_t aray to int64 aray [little endian]
 * @param    [in]    p_in16            uint16_t aray
 * @param    [out]   p_out64           int64 aray
 * @param    [in]    i64_num           number of int64 data
 */
/*------------------------------------------------------------------*/
static void tl_dev_eeprom_cnv_u16_i64(uint16_t *p_in16, int64_t *p_out64, uint16_t i64_num)
{
    uint16_t i, *p_tmp, num = (sizeof(int64_t) / sizeof(uint16_t));
    for( i=0; i<i64_num; i++) {
        p_tmp = p_in16 + (num * i);
        /* convert int64 data */
        *(p_out64 + i)  = (int64_t)((((uint64_t)*p_tmp) << 48) | (((uint64_t)*(p_tmp + 1U)) << 32) |
                          (((uint64_t)*(p_tmp + 2U)) << 16) | ((uint64_t)*(p_tmp + 3U)));
    }
}


/*------------------------------------------------------------------*/
/**
 * @brief    check alpha max and alpha default
 * @param    [in]    addr        reading start address
 * @param    [in]    size        reading size[byte]
 * @param    [out]   data_top    output memory
 * @return   TL_E_SUCCESS        success
 * @return   TL_E_ERR_PARAM      bad argument
 * @return   TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_eeprom_burst_read(
    uint16_t addr, size_t size, uint16_t *data_top)
{
    uint16_t *tmp = NULL;
    size_t   t_size = 0;
    int i;

    //MN34906_DBG("%s: addr:0x%x, size:%d data_top:%p",
    //    __FUNCTION__, addr, size, data_top);

    if ((data_top == NULL) || ((addr % 2U) != 0U) || (size <= 0U) || (addr+size > m_otpdatasize)) {
        MN34906_DBG("%s: addr:0x%x, size:%d data_top:%p", __FUNCTION__, addr, size, data_top);
        return TL_E_ERR_PARAM;
    }

    //copy data from otadata directly
    memcpy((void*)data_top, (void *)(m_otpdata+addr), size);

    /* endian conversion[big to little] */
    t_size = size / 2U;    /* data is 2byte */
    for( i=0; i<(int)t_size; i++) {
        tmp = data_top + i;
        *tmp = (uint16_t)((uint16_t)(*tmp & 0x00FFU) << 8U) | ((uint16_t)(*tmp & 0xFF00U) >> 8U);
    }
    //MN34906_DBG("%s: addr:0x%x, size:%d data0/1:0x%x 0x%x",
    //    __FUNCTION__, addr, size, *data_top, *(data_top+1));
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    load common & mode area
 * @param    [out]    area           load data
 * @param    [out]    size           Power-Up Sequence data size[byte]
 * @return   TL_E_SUCCESS            success
 * @return   TL_E_ERR_PARAM          bad argument
 * @return   TL_E_ERR_SYSTEM         system error
 * @return   TL_E_ERR_NOT_SUPPORT    not supported module
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_eeprom_read_cmn_mode(uint16_t **area, uint16_t *pup_size)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;
    uint16_t    *p_tmp = NULL, tmp_size, tmp_vc;
    size_t        size;

    if ((area == NULL) || (pup_size == NULL)) {
        return TL_E_ERR_PARAM;
    }

    /* allocate memory for reading common & mode area */
    size = TL_EEPROM_CMN_AREA_SIZE + (TL_EEPROM_MODE_AREA_SIZE * TL_MODE_MAX);
    p_tmp = (uint16_t*)calloc(size, 1);
    if (p_tmp == NULL) {
        MN34906_DBG("%s: calloc failed, size:%d", __FUNCTION__, size);
        return TL_E_ERR_SYSTEM;
    }
    //MN34906_DBG("%s: calloced %p, size:%d E", __FUNCTION__, p_tmp, size);

    /* get camera type & info */
    tl_ret = tl_dev_eeprom_burst_read(TL_EEPROM_MOD_NAME, TL_EEPROM_CMN_CAM_AREA_SIZE, p_tmp);
    if (tl_ret != TL_E_SUCCESS) {
        free(p_tmp);
        MN34906_DBG("%s: tl_dev_eeprom_burst_read failed, size:%d", __FUNCTION__, tl_ret);
        return tl_ret;
    }

    /* check map version */
    tl_ret = tl_dev_eeprom_check_map_version(TL_EEPROM_OFST_VAL(p_tmp, TL_EEPROM_MAP_VER));
    if (tl_ret != TL_E_SUCCESS) {
        free(p_tmp);
        MN34906_DBG("%s: tl_dev_eeprom_check_map_version failed, size:%d", __FUNCTION__, tl_ret);
        return tl_ret;
    }

#if 0 //comment it from requirement
    /* check module type */
    tl_ret = tl_dev_eeprom_check_module_type(TL_EEPROM_OFST_VAL(p_tmp, TL_EEPROM_MOD_TYPE1));
    if (tl_ret != TL_E_SUCCESS) {
        free(p_tmp);
        MN34906_DBG("%s: tl_dev_eeprom_check_module_type failed, size:%d", __FUNCTION__, tl_ret);
        return tl_ret;
    }
#endif

    /* check Power-Up Sequence data size */
    tmp_size = TL_EEPROM_OFST_VAL(p_tmp, TL_EEPROM_PUP_SIZE);
    if ((tmp_size == 0U) || (tmp_size > TL_EEPROM_PUP_AREA_MAX_SIZE)) {
        free(p_tmp);
        MN34906_DBG("%s: TL_EEPROM_OFST_VAL failed, tmp_size:%d", __FUNCTION__, tmp_size);
        return TL_E_ERR_SYSTEM;
    }
    //MN34906_DBG("%s: pup_size:%d", __FUNCTION__, tmp_size);

    /* get common(ramain) & mode area */
    size = (TL_EEPROM_CMN_AREA_SIZE - TL_EEPROM_CMN_CAM_AREA_SIZE) + (TL_EEPROM_MODE_AREA_SIZE * TL_MODE_MAX);
    tl_ret = tl_dev_eeprom_burst_read(TL_EEPROM_PLANER_PRM, size, p_tmp + TL_EEPROM_OFFSET(TL_EEPROM_CMN_CAM_AREA_SIZE));
    if (tl_ret != TL_E_SUCCESS) {
        free(p_tmp);
        MN34906_DBG("%s: tl_dev_eeprom_burst_read failed, size:%d tl_ret:%d", __FUNCTION__, size, tl_ret, tl_ret);
        return tl_ret;
    }

    /* check Virtual Channel */
    tmp_vc = TL_EEPROM_OFST_VAL(p_tmp, TL_EEPROM_VC);
    if (tmp_vc != TL_EEPROM_SUPPORT_VC) {
        free(p_tmp);
        MN34906_DBG("%s: TL_EEPROM_OFST_VAL failed, size:%d", __FUNCTION__, tmp_vc);
        return TL_E_ERR_SYSTEM;
    }

    *pup_size = tmp_size;
    *area = p_tmp;

    //MN34906_DBG("%s: pup_size:%d X", __FUNCTION__, tmp_size);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    load Power-Up Sequence area
 * @param    [out]    area        load data
 * @param    [in]    size         Power-Up Sequence data size[byte]
 * @return   TL_E_SUCCESS         success
 * @return   TL_E_ERR_PARAM       bad argument
 * @return   TL_E_ERR_SYSTEM      system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_eeprom_read_pup(uint16_t **area, uint16_t pup_size)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;
    uint16_t    *p_tmp = NULL;

    if ((area == NULL) || (pup_size == 0U)) {
        return TL_E_ERR_PARAM;
    }

    /* allocate memory for reading common & mode area */
    p_tmp = (uint16_t*)calloc((size_t)pup_size, 1);
    if (p_tmp == NULL) {
        return TL_E_ERR_SYSTEM;
    }

    //MN34906_DBG("%s: pup_size:%d", __FUNCTION__, pup_size);

    /* get Power-Up Sequence */
    tl_ret = tl_dev_eeprom_burst_read(TL_EEPROM_PUP_TOP, (size_t)pup_size, p_tmp);
    if (tl_ret != TL_E_SUCCESS) {
        free(p_tmp);
        return tl_ret;
    }
    *area = p_tmp;

    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    convert common area
 * @param    [out]   p_eep            tl_dev_rom_common struct
 * @param    [in]    p_cmn            common area top
 */
/*------------------------------------------------------------------*/
static void tl_dev_eeprom_convert_cmn(tl_dev_rom_common *p_eep, uint16_t *p_cmn)
{
    /* cam_type */
    tl_dev_eeprom_cnv_u16_c(p_cmn + TL_EEPROM_OFFSET(TL_EEPROM_MOD_NAME), p_eep->cam_type.mod_name, TL_EEPROM_ARY_SIZE(p_eep->cam_type.mod_name));
    tl_dev_eeprom_cnv_u16_c(p_cmn + TL_EEPROM_OFFSET(TL_EEPROM_AFE_NAME), p_eep->cam_type.afe_name, TL_EEPROM_ARY_SIZE(p_eep->cam_type.afe_name));
    tl_dev_eeprom_cnv_u16_c(p_cmn + TL_EEPROM_OFFSET(TL_EEPROM_SNS_NAME), p_eep->cam_type.sns_name, TL_EEPROM_ARY_SIZE(p_eep->cam_type.sns_name));
    tl_dev_eeprom_cnv_u16_c(p_cmn + TL_EEPROM_OFFSET(TL_EEPROM_LNS_NAME), p_eep->cam_type.lns_name, TL_EEPROM_ARY_SIZE(p_eep->cam_type.lns_name));
    MN34906_DBG("%s: mod_name:%s, afe_name:%s, sns_name:%s, lns_name:%s", __FUNCTION__,
        p_eep->cam_type.mod_name, p_eep->cam_type.afe_name, p_eep->cam_type.sns_name, p_eep->cam_type.lns_name);

    /* cam_info */
    p_eep->cam_info.sno_l             = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_SNO_L);
    p_eep->cam_info.map_ver           = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_MAP_VER);
    p_eep->cam_info.sno_u             = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_SNO_U);
    p_eep->cam_info.ajust_date        = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_AJUST_DATE);
    p_eep->cam_info.ajust_no          = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_AJUST_NO);
    p_eep->cam_info.mod_type1         = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_MOD_TYPE1);
    p_eep->cam_info.mod_type2         = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_MOD_TYPE2);
    p_eep->cam_info.afe_ptn_id        = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_AFE_PTN_ID);
    p_eep->cam_info.opt_axis_center_h = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_OPT_AXIS_CENTER_H);
    p_eep->cam_info.opt_axis_center_v = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_OPT_AXIS_CENTER_V);
    p_eep->cam_info.fov_h             = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_FOV_H);
    p_eep->cam_info.fov_v             = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_FOV_V);
    p_eep->cam_info.pixel_pitch       = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_PIXEL_PITCH);
    p_eep->cam_info.focal_len         = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_FOCAL_LEN);
    p_eep->cam_info.enable_mode       = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_ENABLE_MODE);
    p_eep->cam_info.tal_mode          = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_TAL_MODE);
    p_eep->cam_info.pup_size          = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_PUP_SIZE);
    p_eep->cam_info.check_sum         = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_CHECK_SUM);
    MN34906_DBG("%s: sno_l:0x%x, map_ver:0x%x, sno_u:0x%x, ajust_date:0x%x, ajust_no:0x%x, mod_type1:0x%x,\n \
                mod_type2:0x%x, afe_ptn_id:0x%x, center_h:0x%x, center_v:0x%x, fov_h:0x%x, fov_v:0x%x,\n \
                pixel_pitch:0x%x, focal_len:0x%x, enable_mode:0x%x, tal_mode:0x%x, pup_size:%d, check_sum:0x%x",
        __FUNCTION__, p_eep->cam_info.sno_l, p_eep->cam_info.map_ver, p_eep->cam_info.sno_u, p_eep->cam_info.ajust_date,
        p_eep->cam_info.ajust_no, p_eep->cam_info.mod_type1, p_eep->cam_info.mod_type2, p_eep->cam_info.afe_ptn_id,
        p_eep->cam_info.opt_axis_center_h, p_eep->cam_info.opt_axis_center_v, p_eep->cam_info.fov_h, p_eep->cam_info.fov_v,
        p_eep->cam_info.pixel_pitch, p_eep->cam_info.focal_len, p_eep->cam_info.enable_mode, p_eep->cam_info.tal_mode,
        p_eep->cam_info.pup_size, p_eep->cam_info.check_sum);

    /* lens */
    tl_dev_eeprom_cnv_u16_i64(p_cmn + TL_EEPROM_OFFSET(TL_EEPROM_PLANER_PRM), p_eep->lens.planer_prm,
                              TL_EEPROM_ARY_SIZE(p_eep->lens.planer_prm));
    tl_dev_eeprom_cnv_u16_i64(p_cmn + TL_EEPROM_OFFSET(TL_EEPROM_DISTORTION_PRM), p_eep->lens.distortion_prm,
                              TL_EEPROM_ARY_SIZE(p_eep->lens.distortion_prm));

    /* shading */
    memcpy((void*)p_eep->shading.offset, (void*)(p_cmn + TL_EEPROM_OFFSET(TL_EEPROM_SHD_OFFSET)),
           TL_EEPROM_ARY_SIZE(p_eep->shading.offset) * sizeof(uint16_t));
    p_eep->shading.shd               = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_SHD);
    p_eep->shading.x0                = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_SHD_X0);
    memcpy((void*)p_eep->shading.xpwr, (void*)(p_cmn + TL_EEPROM_OFFSET(TL_EEPROM_SHD_XPWR)),
           TL_EEPROM_ARY_SIZE(p_eep->shading.xpwr) * sizeof(uint16_t));
    p_eep->shading.y0                = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_SHD_Y0);
    memcpy((void*)p_eep->shading.ypwr, (void*)(p_cmn + TL_EEPROM_OFFSET(TL_EEPROM_SHD_YPWR)),
           TL_EEPROM_ARY_SIZE(p_eep->shading.ypwr) * sizeof(uint16_t));

    /* dfct */
    memcpy((void*)p_eep->dfct.dfct_pix_th_tbl, (void*)(p_cmn + TL_EEPROM_OFFSET(TL_EEPROM_DFCT_PIX_TH_TBL)),
           TL_EEPROM_ARY_SIZE(p_eep->dfct.dfct_pix_th_tbl) * sizeof(uint16_t));
    memcpy((void*)p_eep->dfct.dfct, (void*)(p_cmn + TL_EEPROM_OFFSET(TL_EEPROM_DFCT)),
           TL_EEPROM_ARY_SIZE(p_eep->dfct.dfct) * sizeof(uint16_t));

    /* timing_mipi */
    p_eep->timing_mipi.shp_loc       = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_SHP_LOC);
    p_eep->timing_mipi.shd_loc       = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_SHD_LOC);
    p_eep->timing_mipi.output        = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_OUTPUT);
    p_eep->timing_mipi.output_sel    = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_OUTPUT_SEL);
    p_eep->timing_mipi.vc            = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_VC);

    /* cutout */
    p_eep->cutout.grid3              = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_GRID3);

    /* ir */
    p_eep->ir.ir1                    = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_IR1);
    memcpy((void*)p_eep->ir.ir_gmm,   (void*)(p_cmn + TL_EEPROM_OFFSET(TL_EEPROM_IR_GMM)),
           TL_EEPROM_ARY_SIZE(p_eep->ir.ir_gmm)   * sizeof(uint16_t));
    memcpy((void*)p_eep->ir.ir_gmm_y, (void*)(p_cmn + TL_EEPROM_OFFSET(TL_EEPROM_IR_GMM_Y)),
           TL_EEPROM_ARY_SIZE(p_eep->ir.ir_gmm_y) * sizeof(uint16_t));

    /* chkr */
    p_eep->chkr.upprth               = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_UPPRTH);
    p_eep->chkr.lwrth                = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_LWRTH);
    p_eep->chkr.start_v              = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_START_V);
    p_eep->chkr.start_h              = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_START_H);
    p_eep->chkr.size_h               = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_SIZE_H);
    p_eep->chkr.upprerr_h            = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_UPPRERR_H);
    p_eep->chkr.upprerr_v            = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_UPPRERR_V);
    p_eep->chkr.lwrerr_h             = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_LWRERR_H);
    p_eep->chkr.lwrerr_v             = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_LWRERR_V);
    p_eep->chkr.det_ena              = TL_EEPROM_OFST_VAL(p_cmn, TL_EEPROM_DET_ENA);
}

/*------------------------------------------------------------------*/
/**
 * @brief    convert mode area
 * @param    [out]   p_eep           tl_dev_rom_mode struct
 * @param    [in]    p_mode          mode area top
 * @return   TL_E_SUCCESS            success
 * @return   TL_E_ERR_SYSTEM         system error(EEPROM data error)
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_eeprom_convert_mode(tl_dev_rom_mode *p_eep, uint16_t *p_mode)
{
    uint16_t i, tmp;

    //MN34906_DBG("%s: E-->", __FUNCTION__);

    /* mode info */
    p_eep->info.tof_mode_flag       = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_TOF_MODE_FLAG);
    p_eep->info.ld_flag             = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_LD_FLAG);
    p_eep->info.range_near_limit    = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_RANGE_NEAR_LIMIT);
    p_eep->info.range_far_limit     = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_RANGE_FAR_LIMIT);
    p_eep->info.depth_unit          = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_DEPTH_UNIT);

    /* exposure */
    p_eep->exp.exp_max              = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_EXP_MAX);
    p_eep->exp.exp_default          = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_EXP_DEFAULT);

    /* AE parameters */
    for( i=0; i<(uint16_t)TL_EEPROM_ARY_SIZE(p_eep->ae); i++) {
        p_eep->ae[i].distance       = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_AE_OFST(i, TL_EEPROM_AE_DISTANCE));
        p_eep->ae[i].lumine_num     = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_AE_OFST(i, TL_EEPROM_AE_LUMINE_NUM));
        p_eep->ae[i].slope          = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_AE_OFST(i, TL_EEPROM_AE_SLOPE));
        p_eep->ae[i].zofst          = (int16_t)TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_AE_OFST(i, TL_EEPROM_AE_ZOFST));
    }

    /* AFE address of exposure */
    tmp = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_EXP_ADDR_NUM);
    p_eep->exp_addr.long_num        = (uint8_t)((tmp & 0xFF00U) >> 8U);
    p_eep->exp_addr.short_num       = (uint8_t)((tmp & 0x00F0U) >> 4U);
    p_eep->exp_addr.lms_num         = (uint8_t) (tmp & 0x000FU);
    memcpy((void*)p_eep->exp_addr.long_addr,  (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_EXP_ADDR_LONG)),
           TL_EEPROM_ARY_SIZE(p_eep->exp_addr.long_addr)  * sizeof(uint16_t));
    memcpy((void*)p_eep->exp_addr.short_addr, (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_EXP_ADDR_SHORT)),
           TL_EEPROM_ARY_SIZE(p_eep->exp_addr.short_addr) * sizeof(uint16_t));
    memcpy((void*)p_eep->exp_addr.lms_addr,   (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_EXP_ADDR_LMS)),
           TL_EEPROM_ARY_SIZE(p_eep->exp_addr.lms_addr)   * sizeof(uint16_t));
    if (p_eep->exp_addr.long_num > (uint8_t)TL_EEPROM_ARY_SIZE(p_eep->exp_addr.long_addr)) {
        return TL_E_ERR_SYSTEM;
    }
    if (p_eep->exp_addr.short_num > (uint8_t)TL_EEPROM_ARY_SIZE(p_eep->exp_addr.short_addr)) {
        return TL_E_ERR_SYSTEM;
    }
    if (p_eep->exp_addr.lms_num > (uint8_t)TL_EEPROM_ARY_SIZE(p_eep->exp_addr.lms_addr)) {
        return TL_E_ERR_SYSTEM;
    }

    /* AFE address of dummy transfer */
    p_eep->ccd_addr.addr_num        = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_DMMY_TRNS_NUM);
    memcpy((void*)p_eep->ccd_addr.addr, (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_DMMY_TRNS_ADR)),
           TL_EEPROM_ARY_SIZE(p_eep->ccd_addr.addr) * sizeof(uint16_t));
    if (p_eep->ccd_addr.addr_num > (uint16_t)TL_EEPROM_ARY_SIZE(p_eep->ccd_addr.addr)) {
        return TL_E_ERR_SYSTEM;
    }

    /* Parameters of exposure setting */
    p_eep->exp_prm.vd_ini_ofst         = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_VD_INI_OFST);
    p_eep->exp_prm.vd_ini_ofst_adr_num = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_VD_INI_OFST_ADR_NUM);
    memcpy((void*)p_eep->exp_prm.vd_init_ofst_adr, (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_VD_INIT_OFST_ADR)),
           TL_EEPROM_ARY_SIZE(p_eep->exp_prm.vd_init_ofst_adr) * sizeof(uint16_t));
    p_eep->exp_prm.ld_pls_duty         = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_LD_PLS_DUTY);
    p_eep->exp_prm.vd_duration         = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_VD_DURATION);
    p_eep->exp_prm.vd_reg_adr          = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_VD_REG_ADR);
    p_eep->exp_prm.num_clk_in_hd       = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_NUM_CLK_IN_HD);
    p_eep->exp_prm.beta_num            = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_BETA_NUM);
    p_eep->exp_prm.num_hd_in_readout   = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_NUM_HD_IN_READOUT);
    p_eep->exp_prm.clk_width_u         = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_CLK_WIDTH_U);
    p_eep->exp_prm.clk_width_l         = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_CLK_WIDTH_L);
    p_eep->exp_prm.tof_emt_period_ofst = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_TOF_EMT_PERIOD_OFST);
    p_eep->exp_prm.tof_seq_ini_ofst    = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_TOF_SEQ_INI_OFST);
    p_eep->exp_prm.idle_peri_num       = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_IDLE_PERI_NUM);
    memcpy((void*)p_eep->exp_prm.idle_peri_adr, (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_IDLE_PERI_ADR)),
           TL_EEPROM_ARY_SIZE(p_eep->exp_prm.idle_peri_adr) * sizeof(uint16_t));

    MN34906_DBG("%s: idle_peri_num:%d, idle_peri_adr:0x%x 0x%x 0x%x 0x%x",
        __FUNCTION__, p_eep->exp_prm.idle_peri_num, p_eep->exp_prm.idle_peri_adr[0],
        p_eep->exp_prm.idle_peri_adr[1], p_eep->exp_prm.idle_peri_adr[2], p_eep->exp_prm.idle_peri_adr[3]);

    if (p_eep->exp_prm.vd_ini_ofst_adr_num > (uint16_t)TL_EEPROM_ARY_SIZE(p_eep->exp_prm.vd_init_ofst_adr)) {
        return TL_E_ERR_SYSTEM;
    }
    if (p_eep->exp_prm.idle_peri_num > (uint16_t)TL_EEPROM_ARY_SIZE(p_eep->exp_prm.idle_peri_adr)) {
        return TL_E_ERR_SYSTEM;
    }

    /* nonlinear correction */
    memcpy((void*)p_eep->nlr.offset, (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_NLR_OFFSET)),
           TL_EEPROM_ARY_SIZE(p_eep->nlr.offset) * sizeof(uint16_t));
    p_eep->nlr.x0                      = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_NLR_X0);
    memcpy((void*)p_eep->nlr.xpwr,   (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_NLR_XPWR)),
           TL_EEPROM_ARY_SIZE(p_eep->nlr.xpwr)   * sizeof(uint16_t));

    /* depth correction */
    p_eep->depth.depth0                = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_DEPTH0);
    p_eep->depth.depth2                = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_DEPTH2);
    p_eep->depth.depth3                = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_DEPTH3);

    /* AFE timing control */
    memcpy((void*)p_eep->timing.rate_adjust, (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_RATE_ADJUST)),
           TL_EEPROM_ARY_SIZE(p_eep->timing.rate_adjust) * sizeof(uint16_t));
    memcpy((void*)p_eep->timing.align,       (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_ALIGN)),
           TL_EEPROM_ARY_SIZE(p_eep->timing.align)       * sizeof(uint16_t));
    memcpy((void*)p_eep->timing.read_size,   (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_READ_SIZE)),
           TL_EEPROM_ARY_SIZE(p_eep->timing.read_size)   * sizeof(uint16_t));
    memcpy((void*)p_eep->timing.roi,         (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_ROI)),
           TL_EEPROM_ARY_SIZE(p_eep->timing.roi)         * sizeof(uint16_t));

    /* grid conversion */
    memcpy((void*)p_eep->grid.grid, (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_GRID)),
           TL_EEPROM_ARY_SIZE(p_eep->grid.grid) * sizeof(uint16_t));

    /* RAW noise reduction */
    memcpy((void*)p_eep->raw_nr.xpwr,   (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_RAWNR_XPWR)),
           TL_EEPROM_ARY_SIZE(p_eep->raw_nr.xpwr)   * sizeof(uint16_t));
    memcpy((void*)p_eep->raw_nr.bl_tbl, (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_RAWNR_BL_TBL)),
           TL_EEPROM_ARY_SIZE(p_eep->raw_nr.bl_tbl) * sizeof(uint16_t));
    p_eep->raw_nr.med                  = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_RAWNR_MED);
    p_eep->raw_nr.sat_th               = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_RAWNR_SAT_TH);
    memcpy((void*)p_eep->raw_nr.bk_tbl, (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_RAWNR_BK_TBL)),
           TL_EEPROM_ARY_SIZE(p_eep->raw_nr.bk_tbl) * sizeof(uint16_t));

    /* coring */
    memcpy((void*)p_eep->coring.cor,  (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_COR)),
           TL_EEPROM_ARY_SIZE(p_eep->coring.cor)  * sizeof(uint16_t));
    memcpy((void*)p_eep->coring.corb, (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_CORB)),
           TL_EEPROM_ARY_SIZE(p_eep->coring.corb) * sizeof(uint16_t));
    memcpy((void*)p_eep->coring.corf, (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_CORF)),
           TL_EEPROM_ARY_SIZE(p_eep->coring.corf) * sizeof(uint16_t));

    /* depth control */
    p_eep->depth_ctrl.depth1           = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_DEPTH1);
    p_eep->depth_ctrl.control          = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_CONTROL);

    /* Duty modulation of TOF pulse */
    p_eep->pls_mod.control             = TL_EEPROM_OFST_VAL(p_mode, TL_EEPROM_PLS_MOD_CTRL); // for update reg 0xC300
    MN34906_DBG("pls_mod.control control_value data:0x%x for 0xC300", p_eep->pls_mod.control);
    memcpy((void*)p_eep->pls_mod.val, (void*)(p_mode + TL_EEPROM_OFFSET(TL_EEPROM_PLS_MOD_VAL)),
           TL_EEPROM_ARY_SIZE(p_eep->pls_mod.val) * sizeof(uint16_t));

    /* calc frame rate */
    p_eep->info.fps = tl_dev_eeprom_calc_fps(&p_eep->exp_prm);
    if (p_eep->info.fps == 0xFFFFU) {
        return TL_E_ERR_SYSTEM;
    }

    /* check exposure(max, default) */
    tl_dev_eeprom_check_exp(p_eep);

    //MN34906_DBG("%s: X<--", __FUNCTION__);
    return TL_E_SUCCESS;
}

#if 0
/*------------------------------------------------------------------*/
/**
 * @brief    convert Power-Up Sequence area
 * @param    [in/out] p_pup    Power-Up Sequence data
 * @param    [in]     size     Power-Up Sequence data size[byte]
 * @return   TL_E_SUCCESS      success
 * @return   TL_E_ERR_SYSTEM   system error(EEPROM data error)
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_eeprom_convert_pup(uint16_t *p_pup, uint16_t size)
{
    uint16_t tmp, tmp_size, n=0, i;

    /* convert data size to number of data */
    size /= sizeof(uint16_t);

    //MN34906_DBG("%s: pup size:%d E-->", __FUNCTION__, size);

    /* convert addr & value data for writing to AFE(I2C) */
    /* data in p_pup is Little Endian for calc checksum */
    /* However, since writing to AFE is Big Endian, so convert addr & value to Big Endian */
    /* number of data is only Little Endian */
    while(n < size) {
        /* get number of data */
        tmp_size = *(p_pup + n);
        if (tmp_size == 0U) {
            return TL_E_ERR_SYSTEM;
        }
        if (tmp_size > (size - n - 2U)) {
            return TL_E_ERR_SYSTEM;
        }
        n++;
        /* convert addr to Big Endian */
        tmp = *(p_pup + n);
        *(p_pup + n) = ((uint16_t)(tmp & 0xFF00U) >> 8U) | (uint16_t)((uint16_t)(tmp & 0x00FFU) << 8U);
        n++;
        /* convert data to Big Endian */
        for( i=0; i<tmp_size; i++) {
            tmp = *(p_pup + n + i);
            *(p_pup + n + i) = ((uint16_t)(tmp & 0xFF00U) >> 8U) | (uint16_t)((uint16_t)(tmp & 0x00FFU) << 8U);
        }
        n += tmp_size;    /* next size data */
    }

    //MN34906_DBG("%s: pup size:%d X<--", __FUNCTION__, size);
    return TL_E_SUCCESS;
}
#endif

/*------------------------------------------------------------------*/
/**
 * @brief    convert EEPROM data to tl_dev_eeprom struct
 * @param    [out]   p_eep           tl_dev_eeprom struct
 * @param    [in]    p_cmn_mode      common & mode area data
 * @param    [in]    p_pup           Power-Up Sequence area data
 * @param    [in]    size            Power-Up Sequence data size[byte]
 * @return   TL_E_SUCCESS            success
 * @return   TL_E_ERR_PARAM          bad argument
 * @return   TL_E_ERR_SYSTEM         system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_eeprom_convert(
    tl_dev_eeprom *p_eep, uint16_t *p_cmn_mode, uint16_t *p_pup, uint16_t size)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;

    if ((p_eep == NULL) || (p_cmn_mode == NULL) || (p_pup == NULL) || (size == 0U)) {
        return TL_E_ERR_PARAM;
    }

    //MN34906_DBG("%s: pup size:%d E-->", __FUNCTION__, size);

    /* convert common area */
    tl_dev_eeprom_convert_cmn(&p_eep->cmn, p_cmn_mode);

    //MN34906_DBG("%s: enable_mode:%d tl_dev_eeprom_convert_mode-->",
    //    __FUNCTION__, p_eep->cmn.cam_info.enable_mode);

    /* convert mode area */
    if ((p_eep->cmn.cam_info.enable_mode & 0x1U) == 0x1U) {
        tl_ret = tl_dev_eeprom_convert_mode(&p_eep->mode[0], p_cmn_mode + TL_EEPROM_OFFSET(TL_EEPROM_MODE_TOP(0)));
        if (tl_ret != TL_E_SUCCESS) {
            MN34906_DBG("%s: tl_dev_eeprom_convert_mode/0 failed, tl_ret:%d", __FUNCTION__, tl_ret);
            return tl_ret;
        }
    }
    if ((p_eep->cmn.cam_info.enable_mode & 0x2U) == 0x2U) {
        tl_ret = tl_dev_eeprom_convert_mode(&p_eep->mode[1], p_cmn_mode + TL_EEPROM_OFFSET(TL_EEPROM_MODE_TOP(1)));
        if (tl_ret != TL_E_SUCCESS) {
            MN34906_DBG("%s: tl_dev_eeprom_convert_mode/1 failed, tl_ret:%d", __FUNCTION__, tl_ret);
            return tl_ret;
        }
    }

#if 0 // don't convert again
    /* convert Power-Up Sequence area */
    tl_ret = tl_dev_eeprom_convert_pup(p_pup, size);
    if (tl_ret != TL_E_SUCCESS) {
        MN34906_DBG("%s: tl_dev_eeprom_convert_pup/1 failed, tl_ret:%d", __FUNCTION__, tl_ret);
        return tl_ret;
    }
    p_eep->pup_data = p_pup;
#endif

    //MN34906_DBG("%s: pup size:%d X,--", __FUNCTION__, size);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    convert shading offset data for each ranging mode
 * @param    [out]   p_eep           tl_dev_eeprom struct
 * @param    [in]    p_cmn_mode      common & mode area data
 * @return   TL_E_SUCCESS            success
 * @return   TL_E_ERR_PARAM          bad argument
 * @return   TL_E_ERR_SYSTEM         system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_eeprom_convert_shading(tl_dev_eeprom *p_eep, uint16_t *p_cmn_mode)
{
    int size, i, j;
    float fdata, funit, fslope;

    if ((p_eep == NULL) || (p_cmn_mode == NULL)) {
        return TL_E_ERR_PARAM;
    }

    // calculate shading parameters and store them to mode parameter structure
    for (i = 0; i < (uint16_t)TL_MODE_MAX; i++) {
        if ((i == 0) && ((p_eep->cmn.cam_info.enable_mode & 0x1U) != 0x1U)) {
            continue;
        }
        if ((i == 1) && ((p_eep->cmn.cam_info.enable_mode & 0x2U) != 0x2U)) {
            continue;
        }

        // offset
        size = sizeof(p_eep->cmn.shading.offset) / sizeof(p_eep->cmn.shading.offset[0]);
        funit  = (float)p_eep->mode[i].info.depth_unit / (float)16;
        fslope = (float)p_eep->mode[i].depth.depth3;

        for (j = 0; j < size; j++) {
            fdata = (float)p_eep->cmn.shading.offset[j];
            fdata = ((fdata * 128) / funit) / fslope;
            p_eep->mode[i].shading.offset[j] = (uint16_t)fdata;
        }

        // shd, x0, y0
        p_eep->mode[i].shading.shd = p_eep->cmn.shading.shd;
        p_eep->mode[i].shading.x0  = p_eep->cmn.shading.x0;
        p_eep->mode[i].shading.y0  = p_eep->cmn.shading.y0;

        // xpwr
        size = sizeof(p_eep->cmn.shading.xpwr) / sizeof(p_eep->cmn.shading.xpwr[0]);
        for (j = 0; j < size; j++) {
            p_eep->mode[i].shading.xpwr[j]  = p_eep->cmn.shading.xpwr[j];
        }

        // ypwr
        size = sizeof(p_eep->cmn.shading.ypwr) / sizeof(p_eep->cmn.shading.ypwr[0]);
        for (j = 0; j < size; j++) {
            p_eep->mode[i].shading.ypwr[j]  = p_eep->cmn.shading.ypwr[j];
        }
    }

    //MN34906_DBG("%s: done", __FUNCTION__);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    load EEPROM data
 * @param    [in, out]    dev        device control information
 * @return   TL_E_SUCCESS            success
 * @return   TL_E_ERR_PARAM          bad argument
 * @return   TL_E_ERR_SYSTEM         system error
 * @return   TL_E_ERR_NOT_SUPPORT    not supported device
 */
/*------------------------------------------------------------------*/
TL_E_RESULT tl_dev_eeprom_read(
        tl_dev *dev,
        uint8_t* otpdata,
        uint32_t otpdatasize)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;
    uint16_t *p_cmn_mode = NULL, *p_pup = NULL, size = 0;
    uint16_t afe_revision = 0, afe_mcode_id = 0;

    if (otpdata == NULL || otpdatasize <= 0)
    {
        MN34906_DBG("%s: Input parameter invalid:%p %d", __FUNCTION__, otpdata, otpdatasize);
        return TL_E_ERR_PARAM;
    }

    m_otpdata = otpdata;
    m_otpdatasize = otpdatasize;
    //MN34906_DBG("%s: m_otpdata:%p m_otpdatasize:%d E", __FUNCTION__, m_otpdata, m_otpdatasize);

    /* load common & mode area */
    tl_ret = tl_dev_eeprom_read_cmn_mode(&p_cmn_mode, &size);
    if (tl_ret != TL_E_SUCCESS) {
        MN34906_DBG("%s: tl_dev_eeprom_read_cmn_mode failed, rc:%d", __FUNCTION__, tl_ret);
        return tl_ret;
    }

    //MN34906_DBG("%s: tl_dev_eeprom_read_pup -->", __FUNCTION__);

    /* load Power-Up Sequence area */
    tl_ret = tl_dev_eeprom_read_pup(&p_pup, size);
    if (tl_ret != TL_E_SUCCESS) {
        free(p_cmn_mode);
        MN34906_DBG("%s: tl_dev_eeprom_read_pup failed, rc:%d", __FUNCTION__, tl_ret);
        return tl_ret;
    }

    //MN34906_DBG("%s: tl_dev_eeprom_calc_chksum -->", __FUNCTION__);

    /* check CHECK_SUM value */
    tl_ret = tl_dev_eeprom_calc_chksum(p_cmn_mode, p_pup, size);
    if (tl_ret != TL_E_SUCCESS) {
        free(p_cmn_mode);
        free(p_pup);
        MN34906_DBG("%s: tl_dev_eeprom_calc_chksum failed, rc:%d", __FUNCTION__, tl_ret);
        return tl_ret;
    }

    //MN34906_DBG("%s: tl_dev_eeprom_convert_shading -->", __FUNCTION__);

    /* convert shading offset suitable for each ranging mode */
    tl_ret = tl_dev_eeprom_convert_shading(&dev->dev_eeprom, p_cmn_mode);
    if (tl_ret != TL_E_SUCCESS) {
        free(p_cmn_mode);
        free(p_pup);
        MN34906_DBG("%s: tl_dev_eeprom_convert_shading failed, rc:%d", __FUNCTION__, tl_ret);
        return tl_ret;
    }

    //MN34906_DBG("%s: tl_dev_eeprom_convert -->", __FUNCTION__);

    /* convert using struct */
    tl_ret = tl_dev_eeprom_convert(&dev->dev_eeprom, p_cmn_mode, p_pup, size);
    if (tl_ret != TL_E_SUCCESS) {
        free(p_cmn_mode);
        free(p_pup);
        MN34906_DBG("%s: tl_dev_eeprom_convert failed, rc:%d", __FUNCTION__, tl_ret);
        return tl_ret;
    }

    /* free converted memory(p_pup is using) */
    dev->dev_eeprom.pup_data = p_pup;
    free(p_cmn_mode);

    // check revision
    if (otpdatasize >= (TOTAL_EEPROM_DATA_SIZE + sizeof(afe_revision)))
    {
        // afe_revision configured after 0x3870 in pana_mn34906_eeprom.xml
        memcpy(&afe_revision, (void *)(otpdata + TOTAL_EEPROM_DATA_SIZE), sizeof(afe_revision));
        afe_revision = (uint16_t)((uint16_t)(afe_revision & 0x00FFU) << 8U) | ((uint16_t)(afe_revision & 0xFF00U) >> 8U);
        MN34906_DBG("%s: afe_revision(sensor 0xC0FF):0x%x, afe_ptn_id(eeprom 0x008E):0x%x",
                     __FUNCTION__, afe_revision, dev->dev_eeprom.cmn.cam_info.afe_ptn_id);

        if ((afe_revision == 0x0000U) || (afe_revision == 0x0001U)) {
            if ((dev->dev_eeprom.cmn.cam_info.afe_ptn_id & 0xF000U) < 0x4000U) {
                MN34906_DBG("%s: afe_revision(0x%x) and afe_ptn_id(0x%x) not supported",
                  __FUNCTION__, afe_revision, dev->dev_eeprom.cmn.cam_info.afe_ptn_id);
                return TL_E_ERR_NOT_SUPPORT;
            }
        } else if (afe_revision == 0x0010U) {
            if ((dev->dev_eeprom.cmn.cam_info.afe_ptn_id & 0xF000U) >= 0x4000U) {
                MN34906_DBG("%s: afe_revision(0x%x) and afe_ptn_id(0x%x) not supported",
                  __FUNCTION__, afe_revision, dev->dev_eeprom.cmn.cam_info.afe_ptn_id);
                return TL_E_ERR_NOT_SUPPORT;
            }
        } else {
            MN34906_DBG("%s: afe_revision:0x%x not supported",
              __FUNCTION__, afe_revision);
            return TL_E_ERR_NOT_SUPPORT;
        }
    }

    //MN34906_DBG("%s: m_otpdatasize:%d X", __FUNCTION__, m_otpdatasize);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    free EEPROM data
 * @param    [in, out]    dev        device control information
 */
/*------------------------------------------------------------------*/
void tl_dev_eeprom_free(tl_dev *dev)
{
    if (dev == NULL) { return; }
    if (dev->dev_eeprom.pup_data != NULL) {
        free(dev->dev_eeprom.pup_data);
        dev->dev_eeprom.pup_data = NULL;
    }
}

#ifdef __cplusplus
} // CamX Namespace
#endif // __cplusplus
