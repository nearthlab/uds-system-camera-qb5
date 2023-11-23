////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////
// Copyright (c) 2021 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////

/********************************************************************/
/**
 * @file    tl_dev_afe.c
 * @brief   AFE control
 */
/********************************************************************/

/*--------------------------------------------------------------------
    include headers
--------------------------------------------------------------------*/
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#include "camxeepromdriverapi.h"
#include "tl_dev_afe_map.h"
#include "tl_dev_local.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus


/**
 * @enum    TL_REGISTERSETTING_TYPE
 * @brief   register setting type.
 */
typedef enum {
    TL_REGISTERSETTING_COMMON = 0,
    TL_REGISTERSETTING_MODE,
    TL_REGISTERSETTING_STREAMON,
    TL_REGISTERSETTING_STREAMOFF,
    TL_REGISTERSETTING_MAX
} TL_REGISTERSETTING_TYPE;

TOFCalibration* m_pInitData        = NULL;
TOFCalibration* m_pCalibrationData = NULL;
TL_REGISTERSETTING_TYPE m_registersetting_type = TL_REGISTERSETTING_COMMON;

extern VOID AddInitRegisterSetting(uint16_t addr, uint16_t data, OperationType operation, TOFCalibration* pTOFCalibration);
extern VOID AddResolutionRegisterSetting(uint16_t addr, uint16_t data, OperationType operation, TOFCalibration* pTOFCalibration);
extern VOID AddStreamOnRegisterSetting(uint16_t addr, uint16_t data, OperationType operation, TOFCalibration* pTOFCalibration);
extern VOID AddStreamOffRegisterSetting(uint16_t addr, uint16_t data, OperationType operation, TOFCalibration* pTOFCalibration);

/*--------------------------------------------------------------------
    functions
--------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/**
 * @brief    single write to AFE
 * @param    [in]    addr        AFE address
 * @param    [in]    data        AFE data
 * @return    TL_E_SUCCESS       success.
 * @return    TL_E_ERR_SYSTEM    system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_single_write(uint16_t addr, uint16_t data)
{
    //MN34906_DBG("%s: addr:0x%x, data:0x%x", __FUNCTION__, addr, data);
    switch(m_registersetting_type)
    {
        case TL_REGISTERSETTING_COMMON:
        case TL_REGISTERSETTING_MODE:
                AddResolutionRegisterSetting(addr, data, OperationType::WRITE, m_pCalibrationData);
            break;
        case TL_REGISTERSETTING_STREAMON:
                AddStreamOnRegisterSetting(addr, data, OperationType::WRITE, m_pCalibrationData);
            break;
        case TL_REGISTERSETTING_STREAMOFF:
                AddStreamOffRegisterSetting(addr, data, OperationType::WRITE, m_pCalibrationData);
            break;
        default:
            break;
    }

    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    single write array data to AFE
 * @param    [in]    addr        AFE address
 * @param    [in]    data        AFE data
 * @return    TL_E_SUCCESS       success.
 * @return    TL_E_ERR_SYSTEM    system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_single_write_ary(TL_Reg *regs, uint16_t num)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;
    uint16_t i;

    //MN34906_DBG("%s: array size:%d", __FUNCTION__, num);
    for( i=0; i<num; i++) {
        tl_ret = tl_dev_afe_single_write((regs+i)->address, (regs+i)->value);
        if( tl_ret != TL_E_SUCCESS) {
            return tl_ret;
        }
    }

    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    burst write to AFE
 * @param    [in]    addr        AFE address
 * @param    [in]    data        AFE data group
 * @param    [in]    num         number of data
 * @return    TL_E_SUCCESS       success.
 * @return    TL_E_ERR_SYSTEM    system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_burst_write(uint16_t addr, uint16_t *data, uint16_t num)
{
    if( num == 0U) { return TL_E_SUCCESS; }    /* when empty, do nothing */
    if( data == NULL) { return TL_E_SUCCESS; }

    //MN34906_DBG("%s: data_num:%d, start addr:0x%x", __FUNCTION__, num, addr);

    /* create sequential data */
    for( int i = 0; i < num; i++) {
        //MN34906_DBG("data[%d]: 0x%x", i, *(data + i));
        switch(m_registersetting_type)
        {
            case TL_REGISTERSETTING_COMMON:
            case TL_REGISTERSETTING_MODE:
                AddResolutionRegisterSetting(addr+i, *(data + i), OperationType::WRITE_BURST, m_pCalibrationData);
                break;
            case TL_REGISTERSETTING_STREAMON:
                AddStreamOnRegisterSetting(addr+i, *(data + i), OperationType::WRITE_BURST, m_pCalibrationData);
                break;
            case TL_REGISTERSETTING_STREAMOFF:
                AddStreamOffRegisterSetting(addr+i, *(data + i), OperationType::WRITE_BURST, m_pCalibrationData);
                break;
            default:
                break;
        }
    }

    return TL_E_SUCCESS;
}

 /*------------------------------------------------------------------*/
/**
 * @brief    write register array.
             (Use "Burst Write" for continuous addresses, "Single Write" for others)
 * @param    [in]    reg          data to be set AFE
 * @param    [in]    num          number of data
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_burst_write_reg_ary(const TL_Reg *reg, uint16_t num)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;
    uint16_t *wdata = NULL;
    uint16_t top_addr;
    uint16_t i, data_cnt = 0;
    const TL_Reg *reg_addr;
    uint8_t  last_flg, w_flg;

    if( num == 0U) { return TL_E_SUCCESS; }    /* when empty, do nothing */
    if( reg == NULL) { return TL_E_SUCCESS; }

    /* get data size memory */
    wdata = (uint16_t *)malloc(sizeof(uint16_t) * (size_t)num);
    if( wdata == NULL) {
        return TL_E_ERR_SYSTEM;
    }

    //MN34906_DBG("%s: array size:%d", __FUNCTION__, num);

    /* get top address of continuous data */
    top_addr = reg->address;
    for( i = 0; i < num; i++) {
        reg_addr = reg + i;
        /* copy continuous data */
        *(wdata + data_cnt) = reg_addr->value;
        data_cnt++;

        /* if next data exist, flg ON */
        last_flg = ((i + 1U) < num) ? 0U : 1U;
        /* if next data exist and next address not sequential address, flg ON */
        w_flg    = ((last_flg == 1U) || ((reg_addr->address + 1U) != (reg_addr + 1U)->address)) ? 1U : 0U;

        //MN34906_DBG("%s: reg[%d]: addr:0x%x, value:0x%x", __FUNCTION__, i, reg_addr->address, reg_addr->value);

        if( w_flg == 1U) {
            tl_ret = tl_dev_afe_burst_write(top_addr, wdata, data_cnt);
            if( tl_ret != TL_E_SUCCESS) {
                break;
            }

            /* next data exist*/
            if( last_flg == 0U) {
                /* clear data count */
                data_cnt = 0U;
                /* update top address of sequential data */
                top_addr = (reg_addr + 1U)->address;
            }
        }
    }

    /* free memory */
    free((void *)wdata);

    return tl_ret;
}

/*------------------------------------------------------------------*/
/**
 * @brief    write powerup_sequence data to AFE
 * @param    [in]        p_eep    EEPROM data
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_powerup_seq(tl_dev_eeprom *p_eep)
{
    uint16_t n=0, *p_pup = p_eep->pup_data, data_num=0, addr=0, data_num_loop=0, data_num_total = 0;
    uint16_t pup_size = p_eep->cmn.cam_info.pup_size, size = p_eep->cmn.cam_info.pup_size / sizeof(uint16_t);
    OperationType operation = OperationType::WRITE;

    /* eeprom data is invalid */
    if( size == 0U) { return TL_E_ERR_SYSTEM; }
    if( p_pup == NULL) { return TL_E_ERR_SYSTEM; }

    //MN34906_DBG("%s: pup_size:%d, /2 = %d E-->", __FUNCTION__, pup_size, size);

    /* At EEPROM reading "Size" is LittleEndian and "Addr" and "Data" are converted to BigEndian */
    while(n < size) {
        /* get number of data */
        data_num = *(p_pup + n);
        if ((data_num == 0U) || (data_num > (size - n - 2U))) {
            return TL_E_ERR_SYSTEM;
        }

        //MN34906_DBG("data_num:%d", data_num);
        n++;

        /* burst write to AFE */
        addr = *(p_pup + n);
        for( data_num_loop=0; data_num_loop < data_num; data_num_loop++)
        {
            //MN34906_DBG("addr:0x%x, data:0x%x", addr+data_num_loop, *(p_pup + n + 1 + data_num_loop));
            AddInitRegisterSetting(addr+data_num_loop, *(p_pup + n + 1 + data_num_loop), operation, m_pInitData);

            if ((addr+data_num_loop) == 0xC08E)
            {
                p_eep->cmn.gpo_out_stby_value = *(p_pup + n + 1 + data_num_loop);
                MN34906_DBG("gpo_out_stby_value 0xC08E, data:0x%x", p_eep->cmn.gpo_out_stby_value);
            }
        }
        n += 1U + data_num;    /* next size data */
        data_num_total += data_num;
    }

    //MN34906_DBG("%s: pup_size:%d, /2 = %d, n:%d data_num_total:%d X<--", __FUNCTION__, pup_size, size, n, data_num_total);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    set shading data to AFE
 * @param    [in]    p_shading    shgding data in EEPROM
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_shading(tl_dev_rom_shading *p_shading)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;
    uint16_t *write_data = NULL;
    uint16_t data_size;
    uint16_t data_cnt = 0;

    //MN34906_DBG("%s: E-->", __FUNCTION__);

    /* write shading offset */
    data_size = (uint16_t)TL_AFE_ARY_SIZE(p_shading->offset);
    tl_ret = tl_dev_afe_burst_write(TL_AFE_SHD_OFFSET_ADDR, p_shading->offset, data_size);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* allocate writing data */
    data_size = (uint16_t)( sizeof(p_shading->shd) + sizeof(p_shading->x0) +
                    sizeof(p_shading->xpwr) + sizeof(p_shading->y0) + sizeof(p_shading->ypwr) );
    write_data = (uint16_t *)malloc((size_t)data_size);
    if( write_data == NULL) {
        return TL_E_ERR_SYSTEM;
    }

    /* data copy (these data are grouped for consecutive addresses) */
    data_cnt = 0;
    *(write_data + data_cnt) = p_shading->shd;
    data_cnt++;
    *(write_data + data_cnt) = p_shading->x0;
    data_cnt++;
    memcpy((void *)(write_data + data_cnt), (const void *)p_shading->xpwr, sizeof(p_shading->xpwr));
    data_cnt += (uint16_t)TL_AFE_ARY_SIZE(p_shading->xpwr);
    *(write_data + data_cnt) = p_shading->y0;
    data_cnt++;
    memcpy((void *)(write_data + data_cnt), (const void *)p_shading->ypwr, sizeof(p_shading->ypwr));
    data_cnt += (uint16_t)TL_AFE_ARY_SIZE(p_shading->ypwr);

    /* write data */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_SHD_DATA_ADDR, write_data, data_cnt);

    /* free writing data */
    free((void *)write_data);

    //MN34906_DBG("%s: X<--", __FUNCTION__);

    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    set dfct data to AFE
 * @param    [in]    p_dfct       dfct data in EEPROM
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_dfct(tl_dev_rom_dfct *p_dfct)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;
    uint16_t    data_size;

    //MN34906_DBG("%s: E-->", __FUNCTION__);

    /* write dfct pixel table */
    data_size = (uint16_t)TL_AFE_ARY_SIZE(p_dfct->dfct_pix_th_tbl);
    tl_ret = tl_dev_afe_burst_write(TL_AFE_DFCT_PIX_TH_TBL_ADDR, p_dfct->dfct_pix_th_tbl, data_size);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    /* write dfct setting */
    data_size = (uint16_t)TL_AFE_ARY_SIZE(p_dfct->dfct);
    tl_ret = tl_dev_afe_burst_write(TL_AFE_DFCT_ADDR, p_dfct->dfct, data_size);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    //MN34906_DBG("%s: X<--", __FUNCTION__);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    set timing & mipi data to AFE
 * @param    [in]    p_timing_mipi    timing & mipi data in EEPROM
 * @return    TL_E_SUCCESS            success.
 * @return    TL_E_ERR_SYSTEM         system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_timing_mipi(tl_dev_rom_timing_mipi *p_timing_mipi)
{
    TL_Reg regs[] = {
        {.address = TL_AFE_SHP_LOC_ADDR,     .value = p_timing_mipi->shp_loc},
        {.address = TL_AFE_SHD_LOC_ADDR,    .value = p_timing_mipi->shd_loc},
        {.address = TL_AFE_OUTPUT_ADDR,        .value = p_timing_mipi->output},
        {.address = TL_AFE_OUTPUTSEL_ADDR,    .value = p_timing_mipi->output_sel},
        {.address = TL_AFE_VC_ADDR,            .value = p_timing_mipi->vc},
    };

    //MN34906_DBG("%s:", __FUNCTION__);
    return tl_dev_afe_single_write_ary(regs, (uint16_t)TL_AFE_ARY_SIZE(regs));
}

/*------------------------------------------------------------------*/
/**
 * @brief    set cutout to AFE
 * @param    [in]    p_cutout    cutout data in EEPROM
 * @return    TL_E_SUCCESS       success.
 * @return    TL_E_ERR_SYSTEM    system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_cutout(tl_dev_rom_cutout *p_cutout)
{
    //MN34906_DBG("%s:", __FUNCTION__);
    return tl_dev_afe_single_write(TL_AFE_GRID3_ADDR, p_cutout->grid3);
}

/*------------------------------------------------------------------*/
/**
 * @brief    set IR gain & gamma data to AFE
 * @param    [in]    p_ir        IR gain & gamma data in EEPROM
 * @return    TL_E_SUCCESS       success.
 * @return    TL_E_ERR_SYSTEM    system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_ir(tl_dev_rom_ir *p_ir)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;
    uint16_t *write_data = NULL;
    uint16_t data_size;
    uint16_t data_cnt = 0;

    //MN34906_DBG("%s: E-->", __FUNCTION__);

    /* allocate writing data */
    data_size = (uint16_t)(sizeof(p_ir->ir1) + sizeof(p_ir->ir_gmm) + sizeof(p_ir->ir_gmm_y));
    write_data = (uint16_t *)malloc((size_t)data_size);
    if( write_data == NULL) {
        return TL_E_ERR_SYSTEM;
    }

    /* data copy (these data are grouped for consecutive addresses) */
    data_cnt = 0;
    *(write_data + data_cnt) = p_ir->ir1;
    data_cnt++;
    memcpy((void *)(write_data + data_cnt), (const void *)p_ir->ir_gmm, sizeof(p_ir->ir_gmm));
    data_cnt += (uint16_t)TL_AFE_ARY_SIZE(p_ir->ir_gmm);
    memcpy((void *)(write_data + data_cnt), (const void *)p_ir->ir_gmm_y, sizeof(p_ir->ir_gmm_y));
    data_cnt += (uint16_t)TL_AFE_ARY_SIZE(p_ir->ir_gmm_y);

    /* write data */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_IR_GAIN_GMM_ADDR, write_data, data_cnt);

    /* free writing data */
    free((void *)write_data);

    //MN34906_DBG("%s: X<--", __FUNCTION__);

    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    set chkr data to AFE
 * @param    [in]    p_chkr       Chkr data in EEPROM
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_chkr(tl_dev_rom_chkr *p_chkr)
{
    uint16_t write_data[] = {    /* writing data (these data are grouped for consecutive addresses) */
        p_chkr->upprth,
        p_chkr->lwrth,
        p_chkr->start_v,
        p_chkr->start_h,
        p_chkr->size_h,
        p_chkr->upprerr_h,
        p_chkr->upprerr_v,
        p_chkr->lwrerr_h,
        p_chkr->lwrerr_v,
        p_chkr->det_ena,
    };

    //MN34906_DBG("%s:", __FUNCTION__);
    return tl_dev_afe_burst_write(TL_AFE_CHKR_ADDR, write_data, (uint16_t)TL_AFE_ARY_SIZE(write_data));
}

/*------------------------------------------------------------------*/
/**
 * @brief    set EEPROM common area data to AFE
 * @param    [in]    eep_cmn      common data in EEPROM
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_PARAM      bad argument
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_cmn(tl_dev_rom_common *eep_cmn, tl_dev *dev)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;

    if( eep_cmn == NULL) { return TL_E_ERR_PARAM;}

    //MN34906_DBG("%s: E-->", __FUNCTION__);

    /* write dfct */
    tl_ret = tl_dev_afe_write_eeprom_dfct(&eep_cmn->dfct);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    /* write timing_mipi */
    tl_ret = tl_dev_afe_write_eeprom_timing_mipi(&eep_cmn->timing_mipi);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    /* write cutout */
    tl_ret = tl_dev_afe_write_eeprom_cutout(&eep_cmn->cutout);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    /* write ir */
    tl_ret = tl_dev_afe_write_eeprom_ir(&eep_cmn->ir);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    /* write chkr */
    tl_ret = tl_dev_afe_write_eeprom_chkr(&eep_cmn->chkr);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    //MN34906_DBG("%s: X<--", __FUNCTION__);

    return TL_E_SUCCESS;
}



/*------------------------------------------------------------------*/
/**
 * @brief    set NLR data to AFE
 * @param    [in]    p_nlr        nonlinear data in EEPROM
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_nlr(tl_dev_rom_nlr *p_nlr)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;
    uint16_t *write_data = NULL;
    uint16_t data_size;
    uint16_t data_cnt = 0;

    //MN34906_DBG("%s: E-->", __FUNCTION__);

    /* allocate writing data */
    data_size = (uint16_t)(sizeof(p_nlr->offset) + sizeof(p_nlr->x0) + sizeof(p_nlr->xpwr));
    write_data = (uint16_t *)malloc((size_t)data_size);
    if( write_data == NULL) {
        return TL_E_ERR_SYSTEM;
    }

    /* data copy (these data are grouped for consecutive addresses) */
    data_cnt = 0;
    memcpy((void *)(write_data + data_cnt), (const void *)p_nlr->offset, sizeof(p_nlr->offset));
    data_cnt += (uint16_t)TL_AFE_ARY_SIZE(p_nlr->offset);
    *(write_data + data_cnt) = p_nlr->x0;
    data_cnt++;
    memcpy((void *)(write_data + data_cnt), (const void *)p_nlr->xpwr, sizeof(p_nlr->xpwr));
    data_cnt += (uint16_t)TL_AFE_ARY_SIZE(p_nlr->xpwr);

    /* write data */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_NLR_ADDR, write_data, data_cnt);

    /* free writing data */
    free((void *)write_data);

    //MN34906_DBG("%s: X<--", __FUNCTION__);

    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    set zero point offset & slope of depth to AFE
 * @param    [in]    p_depth      zero-offset & slope data in EEPROM
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_depth(tl_dev_rom_depth *p_depth)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;
    uint16_t write_data[] = {    /* writing data (these data are grouped for consecutive addresses) */
        p_depth->depth2,
        p_depth->depth3,
    };

    //MN34906_DBG("%s: E-->", __FUNCTION__);

    /* write zero point offset */
    tl_ret = tl_dev_afe_single_write(TL_AFE_ZERO_OFFSET_ADDR, p_depth->depth0);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* write slope */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_DEPTH_SLOPE_ADDR, write_data, (uint16_t)TL_AFE_ARY_SIZE(write_data));
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    //MN34906_DBG("%s: X<--", __FUNCTION__);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    set mode timing to AFE
 * @param    [in]    p_timing     mode timing data in EEPROM
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_mode_timing(tl_dev_rom_mode_timing *p_timing)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;
    uint16_t    num;

    //MN34906_DBG("%s: E-->", __FUNCTION__);

    /* write rate_adjust */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_RATE_ADJUST_ADDR, p_timing->rate_adjust, (uint16_t)TL_AFE_ARY_SIZE(p_timing->rate_adjust));
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* write align */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_ALIGN_ADDR, p_timing->align, (uint16_t)TL_AFE_ARY_SIZE(p_timing->align));
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* write read_size0-1 */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_READ_SIZE0_ADDR, p_timing->read_size, 2U);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    /* write read_size3-7 */
    num = (uint16_t)TL_AFE_ARY_SIZE(p_timing->read_size) - 2U;
    tl_ret = tl_dev_afe_burst_write(TL_AFE_READ_SIZE3_ADDR, &p_timing->read_size[2], num);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* write ROI */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_ROI_ADDR, p_timing->roi, (uint16_t)TL_AFE_ARY_SIZE(p_timing->roi));
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    //MN34906_DBG("%s: X<--", __FUNCTION__);

    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    set grid conversion to AFE
 * @param    [in]    p_grid       grid conversion data in EEPROM
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_grid(tl_dev_rom_grid *p_grid)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;

    //MN34906_DBG("%s:", __FUNCTION__);
    /* write grid */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_GRID_ADDR, p_grid->grid, (uint16_t)TL_AFE_ARY_SIZE(p_grid->grid));
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    set RAW-NR to AFE
 * @param    [in]    p_raw_nr     RAW-NR data in EEPROM
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_raw_nr(tl_dev_rom_raw_nr *p_raw_nr)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;
    uint16_t write_data[] = {    /* writing data (these data are grouped for consecutive addresses) */
        p_raw_nr->med,
        p_raw_nr->sat_th,
    };

    //MN34906_DBG("%s: E-->", __FUNCTION__);
    /* write xpwr */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_RAWNR_XPWR_ADDR, p_raw_nr->xpwr, (uint16_t)TL_AFE_ARY_SIZE(p_raw_nr->xpwr));
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* write bl_tbl */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_RAWNR_BLTBL_ADDR, p_raw_nr->bl_tbl, (uint16_t)TL_AFE_ARY_SIZE(p_raw_nr->bl_tbl));
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* write med, sat_th */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_RAWNR_MED_ADDR, write_data, (uint16_t)TL_AFE_ARY_SIZE(write_data));
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* write bk_tbl */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_RAWNR_BKTBL_ADDR, p_raw_nr->bk_tbl, (uint16_t)TL_AFE_ARY_SIZE(p_raw_nr->bk_tbl));
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    //MN34906_DBG("%s: X<--", __FUNCTION__);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    set coring to AFE
 * @param    [in]    p_coring     coring data in EEPROM
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_coring(tl_dev_rom_coring *p_coring)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;
    uint16_t *write_data = NULL;
    uint16_t data_size;
    uint16_t data_cnt = 0;

    //MN34906_DBG("%s: E-->", __FUNCTION__);
    /* allocate writing data */
    data_size = (uint16_t)(sizeof(p_coring->cor) + sizeof(p_coring->corb) + sizeof(p_coring->corf));
    write_data = (uint16_t *)malloc((size_t)data_size);
    if( write_data == NULL) {
        return TL_E_ERR_SYSTEM;
    }

    /* data copy (these data are grouped for consecutive addresses) */
    data_cnt = 0;
    memcpy((void *)(write_data + data_cnt), (const void *)p_coring->cor, sizeof(p_coring->cor));
    data_cnt += (uint16_t)TL_AFE_ARY_SIZE(p_coring->cor);
    memcpy((void *)(write_data + data_cnt), (const void *)p_coring->corb, sizeof(p_coring->corb));
    data_cnt += (uint16_t)TL_AFE_ARY_SIZE(p_coring->corb);
    memcpy((void *)(write_data + data_cnt), (const void *)p_coring->corf, sizeof(p_coring->corf));
    data_cnt += (uint16_t)TL_AFE_ARY_SIZE(p_coring->corf);

    /* write data */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_CORING_ADDR, write_data, data_cnt);

    /* free writing data */
    free((void *)write_data);

    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    //MN34906_DBG("%s: X<--", __FUNCTION__);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    set depth control to AFE
 * @param    [in]    p_d_ctrl     depth control data in EEPROM
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_depth_ctrl(tl_dev_rom_depth_ctrl *p_d_ctrl)
{
    TL_Reg regs[] = {
        {.address = TL_AFE_DEPTH1_ADDR,     .value = p_d_ctrl->depth1},
        {.address = TL_AFE_CONTROL_ADDR,    .value = p_d_ctrl->control},
    };
    //MN34906_DBG("%s:", __FUNCTION__);
    return tl_dev_afe_single_write_ary(regs, (uint16_t)TL_AFE_ARY_SIZE(regs));
}

/*------------------------------------------------------------------*/
/**
 * @brief    set Duty modulation of TOF pulse to AFE
 * @param    [in]    p_pls_mod    Duty modulation of TOF pulse data in EEPROM
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_pls_mod(tl_dev_rom_pls_mod *p_pls_mod)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;

    //MN34906_DBG("%s: E-->", __FUNCTION__);

    /* write control */
    tl_ret = tl_dev_afe_single_write(TL_AFE_PLS_MOD_CTRL_ADDR, p_pls_mod->control);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    /* write val */
    tl_ret = tl_dev_afe_burst_write(TL_AFE_PLS_MOD_VAL_ADDR, p_pls_mod->val, (uint16_t)TL_AFE_ARY_SIZE(p_pls_mod->val));
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    //MN34906_DBG("%s: X<--", __FUNCTION__);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    calculate exposure setting
 * @param    [in]    prm                exposure paramters in EEPROM
 * @param    [in]    pls_mod            Duty modulation of TOF pulse in EEPROM
 * @param    [in]    exp                exposure setting value
 * @param    [out]   p_exp              exposure setting data to AFE
 * @return    TL_E_SUCCESS              success.
 * @return    TL_E_ERR_SYSTEM           system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_calc_exp(
    tl_dev_rom_exp_prm *prm, tl_dev_rom_pls_mod *pls_mod,
    uint16_t exp_val, tl_afe_exp_val *p_exp)
{
    uint32_t    pls_num = 0;
    int64_t     clk;
    int32_t     hd, exp_hd, dmy_hd, idle_peri;
    float       tmp;
    int         i;

    //MN34906_DBG("%s: idle_peri_num:%d, idle_peri_val:%d E-->", __FUNCTION__, prm->idle_peri_num, prm->idle_peri_val);

    /* exposure setting */
    p_exp->long_val  = exp_val;
    p_exp->short_val = exp_val / 4U;
    p_exp->lms_val   = exp_val - (exp_val / 4U) - 1U;

    if( prm->num_clk_in_hd == 0U) { return TL_E_ERR_SYSTEM; }

    /* idle period */
    idle_peri = prm->idle_peri_num == 0 ? 0 : prm->idle_peri_val + 2;

    /* [a] calculate number of clocks in A0/A1/A2 */
    for( i=0; i<(int)TL_AFE_ARY_SIZE(pls_mod->val); i++) {
        pls_num += (uint32_t)pls_mod->val[i];
    }
    tmp = ((float)pls_num * (float)exp_val) / 40.0F;
    clk = (((int64_t)prm->tof_seq_ini_ofst + ((int64_t)exp_val * (int64_t)prm->ld_pls_duty)) - (int64_t)2LL)
          + (int64_t)lroundf(tmp);
    if( clk < 0) { return TL_E_ERR_SYSTEM; }

    /* [b] calculate number of HDs in A0/A1/A2 */
    tmp = (float)clk / ((float)prm->num_clk_in_hd * 1.0F);
    hd  = (int32_t)ceilf(tmp);

    /* [c] calculate number of HDs in exposure */
    exp_hd = ((hd + hd + hd) * (int32_t)prm->beta_num) + (int32_t)prm->tof_emt_period_ofst;
    if( exp_hd > (int32_t)(0xFFFFU - (uint16_t)TL_AFE_READ_SIZE_OFFSET)) { return TL_E_ERR_SYSTEM; }
    if( exp_hd > (int32_t)(0xFFFFU - (uint16_t)TL_AFE_START_V_OFFSET)) { return TL_E_ERR_SYSTEM; }

    /* [d] calculate number of HDs in CCD dummy transfer */
    dmy_hd = (int32_t)prm->vd_duration - (int32_t)prm->vd_ini_ofst - exp_hd - (int32_t)prm->num_hd_in_readout;
    if( dmy_hd < 0) {          return TL_E_ERR_SYSTEM; }
    if( dmy_hd > 0xFFFFL) { return TL_E_ERR_SYSTEM; }

    /* calculate read size */
    p_exp->read_size2   = prm->vd_ini_ofst + (uint16_t)exp_hd + TL_AFE_READ_SIZE_OFFSET + idle_peri;
    /* calculate ccd dummy transfer */
    p_exp->ccd_dummy    = (uint16_t)dmy_hd - idle_peri;
    /* calculate start_v */
    p_exp->chkr_start_v = (uint16_t)exp_hd + TL_AFE_START_V_OFFSET;

    //MN34906_DBG("%s: <--", __FUNCTION__);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    write default exposure setting
 * @param    [in]    eep_mode     mode data in EEPROM
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_PARAM      bad argument
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_default_exp(tl_dev_rom_mode *eep_mode)
{
    TL_E_RESULT      tl_ret = TL_E_SUCCESS;
    tl_afe_exp_val   val;
    uint16_t         exp_val, ofst;
    uint16_t         i;
    TL_Reg           regs[15];    /* maximum array size is long_addr = 15 */

    //MN34906_DBG("%s: E-->", __FUNCTION__);

    exp_val = eep_mode->exp.exp_default;
    if (exp_val > eep_mode->exp.exp_max) {
        exp_val = eep_mode->exp.exp_max;
    }

    /* calculate exposure parameters */
    tl_ret = tl_dev_afe_calc_exp(&eep_mode->exp_prm, &eep_mode->pls_mod, exp_val, &val);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    //MN34906_DBG("%s: long:%d, flag:0x%x, short:%d, lms:%d", __FUNCTION__,
    //    eep_mode->exp_addr.long_num, eep_mode->info.tof_mode_flag,
    //    eep_mode->exp_addr.short_num, eep_mode->exp_addr.lms_num);
    /* write exposure(long) */
    if( eep_mode->exp_addr.long_num > 0U) {
        for( i=0; i<(uint16_t)eep_mode->exp_addr.long_num; i++) {
            regs[i].address = eep_mode->exp_addr.long_addr[i];
            regs[i].value   = val.long_val;
        }
        tl_ret = tl_dev_afe_burst_write_reg_ary(regs, (uint16_t)eep_mode->exp_addr.long_num);
        if( tl_ret != TL_E_SUCCESS) {
            return tl_ret;
        }
    }

    /* when WDR, set exposure of short and lms */
    if( (eep_mode->info.tof_mode_flag & TL_AFE_WDR) != 0U) {
        /* write exposure(short) */
        if( eep_mode->exp_addr.short_num > 0U) {
            for( i=0; i<(uint16_t)eep_mode->exp_addr.short_num; i++) {
                regs[i].address = eep_mode->exp_addr.short_addr[i];
                regs[i].value   = val.short_val;
            }
            tl_ret = tl_dev_afe_burst_write_reg_ary(regs, (uint16_t)eep_mode->exp_addr.short_num);
            if( tl_ret != TL_E_SUCCESS) {
                return tl_ret;
            }
        }
        /* write exposure(lms) */
        if( eep_mode->exp_addr.lms_num > 0U) {
            for( i=0; i<(uint16_t)eep_mode->exp_addr.lms_num; i++) {
                regs[i].address = eep_mode->exp_addr.lms_addr[i];
                regs[i].value   = val.lms_val;
            }
            tl_ret = tl_dev_afe_burst_write_reg_ary(regs, (uint16_t)eep_mode->exp_addr.lms_num);
            if( tl_ret != TL_E_SUCCESS) {
                return tl_ret;
            }
        }
    }

    /* write read size2 */
    tl_ret = tl_dev_afe_single_write(TL_AFE_READ_SIZE2_ADDR, val.read_size2);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* write ccd dummy transfer */
    if( eep_mode->ccd_addr.addr_num > 0U) {
        for( i=0; i<eep_mode->ccd_addr.addr_num; i++) {
            regs[i].address = eep_mode->ccd_addr.addr[i];
            regs[i].value   = val.ccd_dummy;
        }
        tl_ret = tl_dev_afe_burst_write_reg_ary(regs, eep_mode->ccd_addr.addr_num);
        if( tl_ret != TL_E_SUCCESS) {
            return tl_ret;
        }
    }

    /* write chkr start_v */
    tl_ret = tl_dev_afe_single_write(TL_AFE_CHKR_START_V_ADDR, val.chkr_start_v);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* write VD length */
    tl_ret = tl_dev_afe_single_write(eep_mode->exp_prm.vd_reg_adr, eep_mode->exp_prm.vd_duration - 2U);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* write initial offset of VD */
    if( (eep_mode->exp_prm.vd_ini_ofst >= 2U) && (eep_mode->exp_prm.vd_ini_ofst_adr_num > 0U)) {
        ofst = eep_mode->exp_prm.vd_ini_ofst - 1U;
        for( i=0; i<eep_mode->exp_prm.vd_ini_ofst_adr_num; i++) {
            regs[i].address = eep_mode->exp_prm.vd_init_ofst_adr[i];
            regs[i].value   = ofst;
        }
        tl_ret = tl_dev_afe_burst_write_reg_ary(regs, eep_mode->exp_prm.vd_ini_ofst_adr_num);
        if( tl_ret != TL_E_SUCCESS) {
            return tl_ret;
        }
    }

    //MN34906_DBG("%s: X<--", __FUNCTION__);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    set EEPROM mode area data to AFE
 * @param    [in]    eep_mode    mode data in EEPROM
 * @return    TL_E_SUCCESS       success.
 * @return    TL_E_ERR_PARAM     bad argument
 * @return    TL_E_ERR_SYSTEM    system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_eeprom_mode(tl_dev_rom_mode *eep_mode)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;

    if( eep_mode == NULL) { return TL_E_ERR_PARAM; }

    //MN34906_DBG("%s: E-->", __FUNCTION__);

     /* write shading */
    tl_ret = tl_dev_afe_write_eeprom_shading(&eep_mode->shading);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* write nlr */
    tl_ret = tl_dev_afe_write_eeprom_nlr(&eep_mode->nlr);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    /* write zero point offset & slope */
    tl_ret = tl_dev_afe_write_eeprom_depth(&eep_mode->depth);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    /* write mode timing */
    tl_ret = tl_dev_afe_write_eeprom_mode_timing(&eep_mode->timing);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    /* write grid */
    tl_ret = tl_dev_afe_write_eeprom_grid(&eep_mode->grid);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* write RAW-NR */
    tl_ret = tl_dev_afe_write_eeprom_raw_nr(&eep_mode->raw_nr);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    /* write coring */
    tl_ret = tl_dev_afe_write_eeprom_coring(&eep_mode->coring);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    /* write depth control */
    tl_ret = tl_dev_afe_write_eeprom_depth_ctrl(&eep_mode->depth_ctrl);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    /* write pls mod */
    tl_ret = tl_dev_afe_write_eeprom_pls_mod(&eep_mode->pls_mod);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }
    /* write default exposure */
    tl_ret = tl_dev_afe_write_default_exp(eep_mode);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    //MN34906_DBG("%s: X<--", __FUNCTION__);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    calculate ld setting
 * @param    [in]    ld_flag            exposure setting value
 * @return    ld setting
 */
/*------------------------------------------------------------------*/
static uint16_t tl_dev_afe_calc_ld_setting(uint16_t ld_flag)
{
    uint16_t unLdFlag = 0x0010;

    //MN34906_DBG("%s:", __FUNCTION__);
    if ( (ld_flag & 0x0001U) == 1U) {
        unLdFlag |= 0x0001U;    //LD1
    }
    if (((ld_flag & 0x0010U) >> 4U) == 1U) {
        unLdFlag |= 0x0002U;    //LD2
    }
    if (((ld_flag & 0x0100U) >> 8U) == 1U) {
        unLdFlag |= 0x0004U;    //LD3
    }
    if (((ld_flag & 0x1000U) >> 12U) == 1U) {
        unLdFlag |= 0x0008U;    //LD4
    }
    return unLdFlag;
}

/*------------------------------------------------------------------*/
/**
 * @brief    set LD setting to AFE
 * @param    [in]    ld_setting    LD setting
 * @return    TL_E_SUCCESS         success.
 * @return    TL_E_ERR_SYSTEM      system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_write_ld_setting(uint16_t ld_setting)
{
    TL_Reg regs[] = {
        {.address = TL_AFE_LDPOSBLKOUTEN_ADDR,       .value = ld_setting},
        {.address = TL_AFE_LDNEGBLKOUTEN_ADDR,       .value = ld_setting},
    };

    //MN34906_DBG("%s:", __FUNCTION__);
    return tl_dev_afe_single_write_ary(regs, (uint16_t)TL_AFE_ARY_SIZE(regs));
}

/*------------------------------------------------------------------*/
/**
 * @brief    Disable TAL
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM        system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_disable_tal()
{
    TL_Reg regs[] = {
        {.address = TL_AFE_TAL_DETECTOR_EN_ADDR,     .value = 0U},
        {.address = TL_AFE_TAL_EN_ADDR,              .value = 0U},
    };

    //MN34906_DBG("%s:", __FUNCTION__);
    return tl_dev_afe_single_write_ary(regs, (uint16_t)TL_AFE_ARY_SIZE(regs));
}

/*------------------------------------------------------------------*/
/**
 * @brief    Enable TAL
 * @param    [in]    tal_mode_flag    TAL mode flag in EEPROM
 * @param    [in]    ld_setting       LD setting value
 * @return    TL_E_SUCCESS            success.
 * @return    TL_E_ERR_SYSTEM         system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_enable_tal(uint16_t tal_mode_flag, uint16_t ld_setting)
{
    TL_Reg regs[] = {
        {.address = TL_AFE_TAL_EN_ADDR,              .value = 0},
        {.address = TL_AFE_TAL_DETECTOR_EN_ADDR,     .value = ld_setting},
    };

    //MN34906_DBG("%s: E-->", __FUNCTION__);

    uint16_t unData2 = ld_setting | (uint16_t)(ld_setting << 8U);

    if( (tal_mode_flag & 0x0001U) == 0x0001U) {
        /* LD rising edge TAL-valid */
    } else {
        /* LD rising edge TAL-invalid */
        unData2 &= 0xFFF0U;
    }
    if( (tal_mode_flag & 0x0002U) == 0x0002U) {
        /* LD falling edge TAL-valid */
    } else {
        /* LD falling edge TAL-invalid */
        unData2 &= 0xF0FFU;
    }
    if( (tal_mode_flag & 0x0004U) == 0x0004U) {
        /* SUB rising edge TAL-valid */
    } else {
        /* SUB rising edge TAL-invalid */
        unData2 &= 0x0FFFU;
    }
    if( (tal_mode_flag & 0x0008U) == 0x0008U) {
        /* SUB falling edge TAL-valid */
    } else {
        /* SUB falling edge TAL-invalid */
        unData2 &= 0xFF0FU;
    }
    regs[0].value = unData2;

    //MN34906_DBG("%s: X<--", __FUNCTION__);
    return tl_dev_afe_single_write_ary(regs, (uint16_t)TL_AFE_ARY_SIZE(regs));
}

/*------------------------------------------------------------------*/
/**
 * @brief    set output image according to the device image type
 * @param    [in]    dev          device control infomation
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_set_image_type(tl_dev *dev)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;

    //MN34906_DBG("%s: E-->", __FUNCTION__);

    /* argument error check */
    if( dev == NULL) { return TL_E_ERR_PARAM; }

    MN34906_DBG("%s: dev->image_type:%d", __FUNCTION__, dev->image_type);

    switch(dev->image_type) {
    case TL_E_IMAGE_TYPE_VGA_DEPTH_QVGA_IR_BG:
    case TL_E_IMAGE_TYPE_QVGA_DEPTH_IR_BG:
        /* set output system to Depth + IR/BG output */
        tl_ret = tl_dev_afe_single_write(TL_AFE_OUTPUT_TYPE_ADDR, TL_AFE_OUTPUT_TYPE_DEPTH_IRBG_VAL);
        break;

    case TL_E_IMAGE_TYPE_VGA_DEPTH_IR:
    case TL_E_IMAGE_TYPE_VGA_IR_QVGA_DEPTH:
        /* set output system to Depth + IR output */
        tl_ret = tl_dev_afe_single_write(TL_AFE_OUTPUT_TYPE_ADDR, TL_AFE_OUTPUT_TYPE_DEPTH_IR_VAL);
        break;

    case TL_E_IMAGE_TYPE_VGA_IR_BG:
        /* set output system to IR + BG output */
        tl_ret = tl_dev_afe_single_write(TL_AFE_OUTPUT_TYPE_ADDR, TL_AFE_OUTPUT_TYPE_BG_IR_VAL);
        break;

    default:
        tl_ret = TL_E_ERR_SYSTEM;
        break;
    }

    //MN34906_DBG("%s: X<--, ret:%d", __FUNCTION__, tl_ret);
    return tl_ret;
}

/*------------------------------------------------------------------*/
/**
 * @brief    write mode id to AFE
 * @param    [in]    mode         ranging mode
 * @return    TL_E_SUCCESS        success.
 * @return    TL_E_ERR_PARAM      bad argument
 * @return    TL_E_ERR_SYSTEM     system error
 */
/*------------------------------------------------------------------*/
static TL_E_RESULT tl_dev_afe_set_mode_id(TL_E_MODE mode)
{
    uint16_t mode_val = TL_AFE_MODE0_VAL;

    switch(mode) {
    case TL_E_MODE_0:
        mode_val = TL_AFE_MODE0_VAL;
        break;
    case TL_E_MODE_1:
        mode_val = TL_AFE_MODE1_VAL;
        break;
    default:
        return TL_E_ERR_PARAM;
    }

    MN34906_DBG("%s: mode_val:%d", __FUNCTION__, mode_val);
    return tl_dev_afe_single_write(TL_AFE_MODE_ADDR, mode_val);
}


/*------------------------------------------------------------------*/
/**
 * @brief    AFE initial setting
 * @param    [in]    dev           device control infomation
 * @return    TL_E_SUCCESS         success.
 * @return    TL_E_ERR_PARAM       bad argument
 * @return    TL_E_ERR_SYSTEM      system error
 */
/*------------------------------------------------------------------*/
TL_E_RESULT tl_dev_afe_init_param(tl_dev *dev, TOFCalibration* pTOFCalibration)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;

    /* argument error check */
    if( dev == NULL) { return TL_E_ERR_PARAM; }
    m_pInitData = pTOFCalibration;

    //MN34906_DBG("%s: E-->", __FUNCTION__);

#if 0 // can't read reg idle_peri_adr here
    /* get idle period value, the value can be got from AFE after powerup sequence */
    if ((dev->dev_eeprom.cmn.cam_info.enable_mode & 0x1U) == 0x1U) {
        tl_ret = tl_dev_afe_single_read(dev->dev_eeprom.mode[0].exp_prm.idle_peri_adr[0], &dev->dev_eeprom.mode[0].exp_prm.idle_peri_val);
        if( tl_ret != TL_E_SUCCESS) {
            return tl_ret;
        }
    }
    if ((dev->dev_eeprom.cmn.cam_info.enable_mode & 0x2U) == 0x2U) {
        tl_ret = tl_dev_afe_single_read(dev->dev_eeprom.mode[1].exp_prm.idle_peri_adr[0], &dev->dev_eeprom.mode[0].exp_prm.idle_peri_val);
        if( tl_ret != TL_E_SUCCESS) {
            return tl_ret;
        }
    }
#endif

    /* set Powerup data */
    tl_ret = tl_dev_afe_write_eeprom_powerup_seq(&dev->dev_eeprom);
    if( tl_ret != TL_E_SUCCESS) {
        MN34906_DBG("%s:%d failed", __FUNCTION__, __LINE__);
        return tl_ret;
    }

    MN34906_DBG("%s enable_mode:%d, idle_peri_adr:0x%x, 0x%x",
        __FUNCTION__,
        dev->dev_eeprom.cmn.cam_info.enable_mode,
        dev->dev_eeprom.mode[0].exp_prm.idle_peri_adr[0],
        dev->dev_eeprom.mode[1].exp_prm.idle_peri_adr[0]);

    //MN34906_DBG("%s: X<--", __FUNCTION__);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    AFE common setting
 * @param    [in]    dev            device control infomation
 * @return    TL_E_SUCCESS          success.
 * @return    TL_E_ERR_PARAM        bad argument
 * @return    TL_E_ERR_SYSTEM       system error
 */
/*------------------------------------------------------------------*/
TL_E_RESULT tl_dev_afe_common_param(tl_dev *dev, TOFCalibration* pTOFCalibration)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;

    /* argument error check */
    if( dev == NULL) { return TL_E_ERR_PARAM; }

    m_pCalibrationData = pTOFCalibration;
    m_registersetting_type = TL_REGISTERSETTING_COMMON;

    //MN34906_DBG("%s: E-->", __FUNCTION__);

    /* set EEPROM(common area) parameter */
    tl_ret = tl_dev_afe_write_eeprom_cmn(&dev->dev_eeprom.cmn, dev);
    if( tl_ret != TL_E_SUCCESS) {
        MN34906_DBG("%s:%d failed", __FUNCTION__, __LINE__);
        return tl_ret;
    }

    //MN34906_DBG("%s: X<--", __FUNCTION__);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    ranging mode setting
 * @param    [in]    dev            device control infomation
 * @return    TL_E_SUCCESS          success.
 * @return    TL_E_ERR_PARAM        bad argument
 * @return    TL_E_ERR_SYSTEM       system error
 */
/*------------------------------------------------------------------*/
TL_E_RESULT tl_dev_afe_set_mode(tl_dev *dev, TOFCalibration* pTOFCalibration)
{
    TL_E_RESULT tl_ret = TL_E_SUCCESS;
    uint16_t tal = 0, ld_setting = 0;

    /* argument error check */
    if( dev == NULL) { return TL_E_ERR_PARAM; }
    if( dev->mode < TL_E_MODE_0) { return TL_E_ERR_PARAM; }
    if( dev->mode > TL_E_MODE_1) { return TL_E_ERR_PARAM; }

    m_pCalibrationData = pTOFCalibration;
    m_registersetting_type = TL_REGISTERSETTING_MODE;

    tal = dev->dev_eeprom.cmn.cam_info.tal_mode;
    //MN34906_DBG("%s: mode:%d tal:%d E-->", __FUNCTION__, dev->mode, tal);
    if( tal != 0U) {    /* when use tal, disable tal control */
        tl_ret = tl_dev_afe_disable_tal();
        if( tl_ret != TL_E_SUCCESS) {
            return tl_ret;
        }
    }

    /* write EEPROM mode area parameters */
    tl_ret = tl_dev_afe_write_eeprom_mode(&dev->dev_eeprom.mode[dev->mode]);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* write LD setting */
    ld_setting = tl_dev_afe_calc_ld_setting(dev->dev_eeprom.mode[dev->mode].info.ld_flag);
    tl_ret = tl_dev_afe_write_ld_setting(ld_setting);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* set output image according to the dev->image_type */
    tl_ret =  tl_dev_afe_set_image_type(dev);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    /* write mode value */
    tl_ret = tl_dev_afe_set_mode_id(dev->mode);
    if( tl_ret != TL_E_SUCCESS) {
        return tl_ret;
    }

    if( tal != 0U) {    /* when use tal, enable tal control */
        tl_ret = tl_dev_afe_enable_tal(tal, ld_setting);
        if( tl_ret != TL_E_SUCCESS) {
            return tl_ret;
        }
    }

    //MN34906_DBG("%s: mode:%d tal:%d X<--", __FUNCTION__, dev->mode, tal);
    return TL_E_SUCCESS;
}

/*------------------------------------------------------------------*/
/**
 * @brief    AFE streamon setting
 * @param    [in]    dev            device control infomation
 * @return    TL_E_SUCCESS          success.
 * @return    TL_E_ERR_PARAM        bad argument
 * @return    TL_E_ERR_SYSTEM       system error
 */
/*------------------------------------------------------------------*/
TL_E_RESULT tl_dev_afe_streamon_param(tl_dev *dev, TOFCalibration* pTOFCalibration)
{
    uint16_t gpo_out_stby_value1 = 0, gpo_out_stby_value2 = 0, control_value = 0;

    /* argument error check */
    if( dev == NULL)
    {
        return TL_E_ERR_PARAM;
    }

    m_pCalibrationData = pTOFCalibration;
    m_registersetting_type = TL_REGISTERSETTING_STREAMON;

    MN34906_DBG("%s: gpo_out_stby_value:0x%x, control_value:0x%x",
        __FUNCTION__,
        dev->dev_eeprom.cmn.gpo_out_stby_value,
        dev->dev_eeprom.mode[dev->mode].pls_mod.control);

    gpo_out_stby_value1 = dev->dev_eeprom.cmn.gpo_out_stby_value;
    gpo_out_stby_value1 = (gpo_out_stby_value1 & 0xFFBFU) | 0x0040U;
    gpo_out_stby_value2 = (gpo_out_stby_value1 & 0xFFFDU) | 0x0002U;
    dev->dev_eeprom.cmn.gpo_out_stby_value = gpo_out_stby_value2;

    control_value = dev->dev_eeprom.mode[dev->mode].pls_mod.control;
    control_value = (control_value & 0xFFFEU) | 0x0001U;

    TL_Reg regs[] = {
        {.address = 0xC08E,    .value = gpo_out_stby_value1},
        {.address = 0xC08E,    .value = gpo_out_stby_value2},
        {.address = 0xC300,    .value = control_value},

        {.address = 0xC4C0,    .value = 0x001C},
        {.address = 0xC4C3,    .value = 0x001C},
        {.address = 0xC4D7,    .value = 0x0000},
        {.address = 0xC4D5,    .value = 0x0002},
        {.address = 0xC4DA,    .value = 0x0001},
        {.address = 0xC4F0,    .value = 0x0000},
        {.address = 0xC427,    .value = 0x0003},
        {.address = 0xC427,    .value = 0x0001},
        {.address = 0xC427,    .value = 0x0000},
        {.address = 0xC426,    .value = 0x0030},
        {.address = 0xC426,    .value = 0x0010},
        {.address = 0xC426,    .value = 0x0000},
        {.address = 0xC423,    .value = 0x0080},
        {.address = 0xC431,    .value = 0x0080},

        {.address = 0x4001,    .value = 0x0007},
        {.address = 0x7C22,    .value = 0x0004},
    };

    return tl_dev_afe_single_write_ary(regs, (uint16_t)TL_AFE_ARY_SIZE(regs));
}

/*------------------------------------------------------------------*/
/**
 * @brief    AFE streamoff setting
 * @param    [in]    dev            device control infomation
 * @return    TL_E_SUCCESS          success.
 * @return    TL_E_ERR_PARAM        bad argument
 * @return    TL_E_ERR_SYSTEM       system error
 */
/*------------------------------------------------------------------*/
TL_E_RESULT tl_dev_afe_streamoff_param(tl_dev *dev, TOFCalibration* pTOFCalibration)
{
    uint16_t gpo_out_stby_value1 = 0, gpo_out_stby_value2 = 0, control_value = 0;

    /* argument error check */
    if( dev == NULL)
    {
        return TL_E_ERR_PARAM;
    }

    m_pCalibrationData = pTOFCalibration;
    m_registersetting_type = TL_REGISTERSETTING_STREAMOFF;

    gpo_out_stby_value1 = dev->dev_eeprom.cmn.gpo_out_stby_value;
    gpo_out_stby_value1 = gpo_out_stby_value1 & 0xFFFD;
    gpo_out_stby_value2 = gpo_out_stby_value1 & 0xFFBF;

    control_value = dev->dev_eeprom.mode[dev->mode].pls_mod.control;
    control_value = (uint16_t)(control_value & 0xFFFE);

    MN34906_DBG("%s: gpo_out_stby_value:0x%x, control_value:0x%x", __FUNCTION__,
        dev->dev_eeprom.cmn.gpo_out_stby_value, dev->dev_eeprom.mode[dev->mode].pls_mod.control);

    TL_Reg regs[] = {
        {.address = 0x4001,    .value = 0x0004},
        {.address = 0x7C22,    .value = 0x0004},
        {.address = 0xC431,    .value = 0x0082},

        {.address = 0xC423,    .value = 0x0000},
        {.address = 0xC426,    .value = 0x0020},
        {.address = 0xC427,    .value = 0x0002},

        {.address = 0xC4C0,    .value = 0x003C},
        {.address = 0xC4C3,    .value = 0x003C},
        {.address = 0xC4D5,    .value = 0x0003},
        {.address = 0xC4DA,    .value = 0x0000},
        {.address = 0xC4D7,    .value = 0x0001},
        {.address = 0xC4F0,    .value = 0x0001},

        {.address = 0xC300,    .value = control_value},
        {.address = 0xC08E,    .value = gpo_out_stby_value1},
        {.address = 0xC08E,    .value = gpo_out_stby_value2},

        {.address = 0xC025,    .value = 0x0000},
    };
    return tl_dev_afe_single_write_ary(regs, (uint16_t)TL_AFE_ARY_SIZE(regs));
}

#ifdef __cplusplus
} // CamX Namespace
#endif // __cplusplus
