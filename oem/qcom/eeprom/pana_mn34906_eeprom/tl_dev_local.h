////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////
// Copyright (c) 2021 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////

/********************************************************************/
/**
 * @file    tl_dev_local.h
 * @brief   definitions of device control
 */
/********************************************************************/

#ifndef H_TL_DEVICE_LOCAL
#define H_TL_DEVICE_LOCAL

/*--------------------------------------------------------------------
    include headers
--------------------------------------------------------------------*/
#include <stdint.h>
#include <errno.h>
#include <android/log.h>

#include "tl_local.h"
#include "tl_dev_eeprom.h"

#define MN34906_DBG(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, "MN34906",fmt, ##args)

/*--------------------------------------------------------------------
    definitions
--------------------------------------------------------------------*/

/* device control information */
typedef struct {
    TL_E_MODE               mode;            /* Ranging mode */
    TL_E_MODE               debug_pre_mode;  /* Ranging mode before debug mode */
    TL_E_IMAGE_TYPE         image_type;      /* Image type to be acquired */
    tl_dev_eeprom           dev_eeprom;      /* EEPROM device */
} tl_dev;

#endif    /* H_TL_DEVICE_LOCAL */
