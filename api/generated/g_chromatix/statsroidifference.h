////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2023 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// THIS IS AUTO-GENERATED CODE.  PLEASE DO NOT EDIT (File bug reports against tools).
///
/// Auto-generated by: Parameter Parser V2.0.0 (1907311625)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  statsroidifference.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef STATSROIDIFFERENCE_H
#define STATSROIDIFFERENCE_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "statsglobalelements.h"

#define STATSROIDIFFERENCE_NAMESPACE_BEGIN namespace statsroidifference {
#define STATSROIDIFFERENCE_NAMESPACE_END }

STATSROIDIFFERENCE_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// faceTriggerCtrlType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum class faceTriggerCtrlType
{
    TriggerCtrlLuxIdx  = 0,
    TriggerCtrlGain    = 1,
    TriggerCtrlTypeMax = 2
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// modFaceRoiDiffTriggerDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct modFaceRoiDiffTriggerDataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerPt
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    statsglobalelements::glbTriggerPointType       triggerPt;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// triggerData - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                    triggerDataCount;
    UINT32                    triggerDataID;
    statsglobalelements::FaceROIDiffThresholdType* triggerData;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixStatsROIDifferenceType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixStatsROIDifferenceType
{
    statsglobalelements::glbEnableFlagType             statsROIDiffEnable;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// TriggerCtrlType
    /// Default Value: TriggerCtrlGain
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    faceTriggerCtrlType           TriggerCtrlType;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// statsROIDiffThreshold
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   statsROIDifference for location, size and count
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    modFaceRoiDiffTriggerDataType statsROIDiffThreshold;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// statsroidifferenceClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class statsroidifferenceClass
{
public:

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load modFaceRoiDiffTriggerDataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadmodFaceRoiDiffTriggerDataType(
        ParameterFileSymbolTableEntry* entry,
        modFaceRoiDiffTriggerDataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixStatsROIDifferenceType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixStatsROIDifferenceType(
        ParameterFileSymbolTableEntry* entry,
        chromatixStatsROIDifferenceType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload modFaceRoiDiffTriggerDataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadmodFaceRoiDiffTriggerDataType(
        modFaceRoiDiffTriggerDataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatixStatsROIDifferenceType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadchromatixStatsROIDifferenceType(
        chromatixStatsROIDifferenceType* structure);

}; // End class statsroidifferenceClass

STATSROIDIFFERENCE_NAMESPACE_END
#endif // STATSROIDIFFERENCE_H
