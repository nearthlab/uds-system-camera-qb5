////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////
// Copyright (c) 2021 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////

/********************************************************************/
/**
 * @file    tl.h
 * @brief   interfaces of tof library
 */
/********************************************************************/

#ifndef H_TL
#define H_TL

/*--------------------------------------------------------------------
    include headers
--------------------------------------------------------------------*/
#include <stdint.h>



/*--------------------------------------------------------------------
    definitions
--------------------------------------------------------------------*/
/**
 * @enum    TL_E_BOOL
 * @brief   Value of boolean.
 */
typedef enum {
    TL_E_FALSE = 0,       /*!< false */
    TL_E_TRUE,            /*!< true */
} TL_E_BOOL;


/**
 * @enum    TL_E_RESULT
 * @brief   Return value of functions.
 */
typedef enum {
    TL_E_SUCCESS = 0,       /*!< success. */
    TL_E_ERR_PARAM,         /*!< bad parameter */
    TL_E_ERR_SYSTEM,        /*!< system error */
    TL_E_ERR_STATE,         /*!< state error */
    TL_E_ERR_TIMEOUT,       /*!< timeout error */
    TL_E_ERR_EMPTY,         /*!< buffer empty error */
    TL_E_ERR_NOT_SUPPORT    /*!< not supported function */
} TL_E_RESULT;


/**
 * @name    TL_E_IMAGE_TYPE
 * @brief   Image type to be acquired
 */
typedef enum {
    TL_E_IMAGE_TYPE_VGA_DEPTH_QVGA_IR_BG = 0,    /*!< VGA depth image and QVGA IR image, BG data */
    TL_E_IMAGE_TYPE_QVGA_DEPTH_IR_BG,            /*!< QVGA depth image, IR image and BG data */
    TL_E_IMAGE_TYPE_VGA_DEPTH_IR,                /*!< VGA depth image and IR image */
    TL_E_IMAGE_TYPE_VGA_IR_QVGA_DEPTH,           /*!< VGA IR image and QVGA depth image */
    TL_E_IMAGE_TYPE_VGA_IR_BG,                   /*!< VGA IR image and BG data */
    TL_E_IMAGE_TYPE_MAX
} TL_E_IMAGE_TYPE;

/**
 * @enum    TL_E_MODE
 * @brief   Ranging mode
 */
typedef enum {
    TL_E_MODE_0,        /*!< mode 0 */
    TL_E_MODE_1,        /*!< mode 1 */
} TL_E_MODE;

/**
 * @name    TL_NOTIFY
 * @brief   Contents of the notification
 */
/* @{ */
#define TL_NOTIFY_IMAGE         (0x00000001U)    /*!< notify recieved image */
#define TL_NOTIFY_NO_BUFFER     (0x00000100U)    /*!< notify image buffer is empty */
#define TL_NOTIFY_DISCONNECT    (0x00000200U)    /*!< notify disconnected */
#define TL_NOTIFY_DEVICE_ERR    (0x00001000U)    /*!< notify device error */
#define TL_NOTIFY_SYSTEM_ERR    (0x00002000U)    /*!< notify system error */
#define TL_NOTIFY_STOPPED       (0x80000000U)    /*!< notify stopped to recieve image */
/* @} */


/**
 * @struct   TL_Handle
 * @brief    Device handle
 */
struct stTL_Handle;
typedef struct stTL_Handle TL_Handle;


/**
 * @struct   TL_Image
 * @brief    Image buffers
 */
typedef struct {
    void    *depth;     /*!< depth image */
    void    *ir;        /*!< IR image */
    void    *bg;        /*!< BG data */
} TL_Image;


/**
 * @struct   TL_CbData
 * @brief    Transfer data
 */
typedef struct {
    TL_Image        image;   /*!< image buffers */
    int32_t         temp;    /*!< temperature [x100 degree] */
} TL_CbData;




/**
 * @brief    Callback function from library.
 * @param    [in]    notify    contents of the notification
 * @param    [in]    data    Transfer data
 */
typedef void (*TL_Cb)(TL_Handle *handle, uint32_t notify, TL_CbData data);


/**
 * @struct    TL_Param
 * @brief    initial parameter
 */
typedef struct {
    TL_Cb               cb_func;        /*!< callback from library */
    TL_E_IMAGE_TYPE     image_type;     /*!< Image type to be acquired */
    uint32_t            buf_num;        /*!< number of image buffers */
} TL_Param;



/**
 * @name    TL_CMD
 * @brief    Commands of property
 */
/* @{ */
#define TL_CMD_DEVICE_INFO      (0x10000011U)    /*!< device information : TL_DeviceInfo */
#define TL_CMD_FOV              (0x10000001U)    /*!< field of view : TL_Fov */
#define TL_CMD_RESOLUTION       (0x10000002U)    /*!< image resolution : TL_Resolution */
#define TL_CMD_MODE             (0x30000003U)    /*!< ranging mode : TL_E_MODE */
#define TL_CMD_MODE_INFO        (0x10000012U)    /*!< ranging mode information : TL_ModeInfoGroup */
/* @} */


/**
 * @struct    TL_DeviceInfo
 * @brief    device information
 */
typedef struct {
    char        mod_name[32];    /*!< device name */
    char        afe_name[32];    /*!< model name of AFE */
    char        sns_name[32];    /*!< model name of Sensor */
    char        lns_name[32];    /*!< model name of Lens */
    uint16_t    mod_type1;       /*!< model type 1 (HW version) */
    uint16_t    mod_type2;       /*!< model type 2 (Wavelength of light source[nm]) */
    uint16_t    afe_ptn_id;      /*!< pattern ID of AFE setting */
    uint16_t    sno_l;           /*!< Serial No. (Control number) */
    uint16_t    map_ver;         /*!< information map version */
    uint16_t    sno_u;           /*!< Serial No. */
    uint16_t    ajust_date;      /*!< Adjusted date */
    uint16_t    ajust_no;        /*!< Adjust No. */
} TL_DeviceInfo;


/**
 * @struct    TL_Fov
 * @brief    Field of view
 */
typedef struct {
    uint16_t    focal_length;   /*!< Focal length [x100 mm] */
    uint16_t    angle_h;        /*!< Horizontal viewing angle [x100 degree] */
    uint16_t    angle_v;        /*!< Vertical viewing angle [x100 degree] */
} TL_Fov;


/**
 * @struct    TL_ImageFormat
 * @brief    Image format
 */
typedef struct {
    uint16_t    width;          /*!< image width */
    uint16_t    height;         /*!< image height */
    uint16_t    stride;         /*!< data stride */
    uint16_t    bit_per_pixel;  /*!< pixel length [bit/pixel] */
} TL_ImageFormat;


/**
 * @struct    TL_Resolution
 * @brief    Image resolution
 */
typedef struct {
    TL_ImageFormat    depth;    /*!< depth Image format */
    TL_ImageFormat    ir;       /*!< IR Image format */
    TL_ImageFormat    bg;       /*!< BG data format */
} TL_Resolution;




/**
 * @struct    TL_ModeInfo
 * @brief    ranging mode information
 */
typedef struct {
    TL_E_BOOL   enable;         /*!< Availability of ranging mode */
    uint16_t    range_near;     /*!< near limit of range */
    uint16_t    range_far;      /*!< far limit of range */
    uint16_t    depth_unit;     /*!< Unit of Depth value */
    uint16_t    fps;            /*!< frame rate */
} TL_ModeInfo;


/**
 * @struct    TL_ModeInfoGroup
 * @brief    ranging mode informations
 */
typedef struct {
    TL_ModeInfo        mode_0;  /*!< information of TL_E_MODE_0 */
    TL_ModeInfo        mode_1;  /*!< information of TL_E_MODE_1 */
} TL_ModeInfoGroup;

/**
 * @struct    TL_DepthNr
 * @brief    depth NR informations
 */
typedef struct {
    TL_E_BOOL    enable;        /*!< enable or disable */
    float        fgain;         /*!< gain of 3DNR threshold */
} TL_DepthNr;

#endif    /* H_TL */
