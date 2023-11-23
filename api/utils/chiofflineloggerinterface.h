////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  chiofflineloggerinterface.h
/// @brief Offline Logger interfaces
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CHIOFFLINELOGGERINTERFACE_H
#define CHIOFFLINELOGGERINTERFACE_H

#include "camxcdktypes.h"
#include "camxchiofflineloggercommon.h"
#include "chi.h"

typedef VOID*          OFFLINELOGGERHANDLE;               ///< Handle to a Offlinelogger context

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PFNCHIADDLOG
///
/// @brief  Fuction pointer to let CHI add log to the offlinelogger queue
///
/// @return VOID
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef VOID(*PFNCHIADDLOG)(OfflineLoggerType type, const CHAR* pText);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PFNCHIFLUSHLOG
///
/// @brief  Fuction pointer to let CHI flush the offline log into android file system
///
/// @return VOID
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef VOID(*PFNCHIFLUSHLOG)(OfflineLoggerType type, BOOL lastFlush);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PFNCHINOTIFYCAMERAOPEN
///
/// @brief  Fuction pointer to notify offlinelogger camera open
///
/// @return VOID
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef VOID(*PFNCHINOTIFYCAMERAOPEN)(OfflineLoggerType type);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PFNCHINOTIFYCAMERACLOSE
///
/// @brief  Fuction pointer to notify offlinelogger camera close
///
/// @return VOID
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef VOID(*PFNCHINOTIFYCAMERACLOSE)(OfflineLoggerType type);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PFNCHIDISABLELOG
///
/// @brief  Fuction pointer to let CHI disable the offline log system
///
/// @return VOID
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef VOID(*PFNCHIDISABLELOG)(OfflineLoggerType type);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PFNCHIISENABLE
///
/// @brief  Fuction pointer to let CHI get the enable/disable of offline log system
///
/// @return BOOL
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef BOOL(*PFNCHIISENABLE)(OfflineLoggerType type);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PFNSIGNALOFFLINETHREAD
///
/// @brief  Function pointer for CAMX OfflineLogger to callback to CHI and signal OfflineLogger
///         thread to trigger flush
///
/// @return VOID
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef VOID(*PFNSIGNALOFFLINETHREAD)(OfflineLoggerType type);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PFNCHILINKOFFLINELOGGER
///
/// @brief  Set function pointer to let Camx offlineLogger signal CHI logger thread to trigger flush
///
/// @return BOOL
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef BOOL(*PFNCHILINKFLUSHTRIGGER)(OfflineLoggerType type, PFNSIGNALOFFLINETHREAD pSignalFunc);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// PFNCHIGETSETTING
///
/// @brief  Set function pointer to let Camx offlineLogger get camx override setting from CHI API
///
/// @return BOOL
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef BOOL(*PFNCHIGETSETTING)(OfflineLoggerType type, PFNGETSETTINGS pGetSetting);

/// @brief Offlinelogger Ops
typedef struct ChiOfflineLogOps
{
    UINT32                    size;                  ///< Size of this structure
    PFNCHIADDLOG              pAddLog;               ///< Add Log
    PFNCHIFLUSHLOG            pFlushLog;             ///< Flush queue
    PFNCHINOTIFYCAMERAOPEN    pNotifyCameraOpen;     ///< Notify camera open
    PFNCHINOTIFYCAMERACLOSE   pNotifyCameraClose;    ///< Notify camera close
    PFNCHIDISABLELOG          pDisableOfflineLog;    ///< Disable offlinelogger system
    PFNCHIISENABLE            pIsEnableOfflineLog;   ///< Return if offlinelogger system is enabled
    PFNCHILINKFLUSHTRIGGER    pLinkFlushTrigger;     ///< Link flush trigger to underlying offline log system
    PFNCHIGETSETTING          pGetSetting;           ///< Get override setting from CHI API
} CHIOFFLINELOGOPS;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// OfflineLoggerEntry
///
/// @brief  Main entry point of the OfflineLogger
///
/// @return None
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef VOID(*PCHIOFFLINELOGENTRY)(CHIOFFLINELOGOPS* pOfflineLogOps);

#endif // CHIOFFLINELOGGERINTERFACE_H