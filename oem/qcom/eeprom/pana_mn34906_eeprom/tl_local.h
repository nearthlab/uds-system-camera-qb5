////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////
// Copyright (c) 2021 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////

/********************************************************************/
/**
 * @file    tl_local.h
 * @brief   loacl definitions
 */
/********************************************************************/

#ifndef H_TL_LOCAL
#define H_TL_LOCAL

/*--------------------------------------------------------------------
    include headers
--------------------------------------------------------------------*/
#include <stdint.h>
#include "tl.h"

/*--------------------------------------------------------------------
    definitions
--------------------------------------------------------------------*/

/* image size */
#define TL_QVGA_WIDTH            (320U)
#define TL_QVGA_HEIGHT           (240U)
#define TL_QVGA_SIZE             (TL_QVGA_WIDTH * TL_QVGA_HEIGHT)
#define TL_QVGA_DATA_SIZE        (sizeof(int16_t) * TL_QVGA_SIZE)
#define TL_VGA_WIDTH             (640U)
#define TL_VGA_HEIGHT            (480U)
#define TL_VGA_SIZE              (TL_VGA_WIDTH * TL_VGA_HEIGHT)
#define TL_VGA_DATA_SIZE         (sizeof(int16_t) * TL_VGA_SIZE)
#define TL_DEPTH_INVALID_DATA    (0xFFFFU)
#define TL_SENSOR_INVALID_DATA   (0x0FFFU)

/* states */
typedef enum {
    TL_E_ST_STOP = 0,    /* stopped */
    TL_E_ST_STREAMING,   /* streaming */
} TL_E_STATE;


/* type of property-command */
#define TL_CMD_TYPE_DEV        (0x10000000U)    /* for device */

#define TL_MODE_MAX            (TL_E_MODE_1 + 1U)

/* callback thread */
#define TL_CB_THREAD_NAME      ("CB_THREAD")    /* name */
#define TL_CB_CPU_NO           (3)              /* cpu No.  */

typedef struct {
    uint16_t    address;    /*!< address of the register */
    uint16_t    value;      /*!< value of the register */
} TL_Reg;

#endif    /* H_TL_LOCAL */
