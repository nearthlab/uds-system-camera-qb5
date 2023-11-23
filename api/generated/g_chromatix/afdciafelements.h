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
/// @file  afdciafelements.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AFDCIAFELEMENTS_H
#define AFDCIAFELEMENTS_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"

#define AFDCIAFELEMENTS_NAMESPACE_BEGIN namespace afdciafelements {
#define AFDCIAFELEMENTS_NAMESPACE_END }

AFDCIAFELEMENTS_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixAFDCIAFFineSearchStepInfoType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixAFDCIAFFineSearchStepInfoType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// stepSize
    ///
    /// Description:   Step Size.
    /// Type:          int
    /// Range:         [0,1000]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 stepSize;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// farSteps
    ///
    /// Description:   No of Steps in Far Direction
    /// Type:          int
    /// Range:         [0,5000]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 farSteps;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// nearSteps
    ///
    /// Description:   No of Steps in Near Direction
    /// Type:          int
    /// Range:         [0,5000]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 nearSteps;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixAFCameraOrientationType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum class chromatixAFCameraOrientationType
{
    AF_CAM_ORIENT_LEFT  = 0,
    AF_CAM_ORIENT_RIGHT = 1,
    AF_CAM_ORIENT_UP    = 2,
    AF_CAM_ORIENT_DOWN  = 3,
    AF_CAM_ORIENT_MAX   = 4
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDCIAFType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixDCIAFType
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Binary file symbol table entry ID
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32 SymbolTableID;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// module_version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct module_versionStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;
        INT32 major_revision;
        INT32 minor_revision;
        INT32 incr_revision;
    } module_version;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// parameter_version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct parameter_versionStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;
        CHAR* revision;
    } parameter_version;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// monitorEnable
    ///
    /// Description:    Enable flag for scene monitor for DCIAF. Effect: Runs distance estimation library in continuous mode for
    ///                scene monitor.
    /// Type:          uint
    /// Range:         [0,1]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                                  monitorEnable;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// monitorFrequency
    ///
    /// Description:   Max rate of distance estimation in monitor mode. Effect: Distance stats would arrive at or below this
    ///                rate in monitor.
    /// Type:          int
    /// Range:         [1,30]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   monitorFrequency;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// searchFrequency
    ///
    /// Description:   Max rate of distance estimation in AF search mode. Effect: Distance stats would arrive at or below this
    ///                rate in search.
    /// Type:          int
    /// Range:         [1,30]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   searchFrequency;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// baselineMM
    ///
    /// Description:   Physical distance(mm) between optical centers of dual cameras.
    /// Type:          float
    /// Range:         [0,unbounded]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT                                   baselineMM;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// auxDirection
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixAFCameraOrientationType        auxDirection;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// macroEstimateLimitCM
    ///
    /// Description:   Closest distance in cm estimated by depth service. Effect: Distance may not be estimated for objects
    ///                closer than this value.
    /// Type:          float
    /// Range:         [0,unbounded]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT                                   macroEstimateLimitCM;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// alignmentCheckEnable
    ///
    /// Description:   Enable alignment check in depth service. Effect: Enables alignment check.
    /// Type:          uint
    /// Range:         [0,1]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                                  alignmentCheckEnable;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// jumpToStartLimit
    ///
    /// Description:   Largest lens position jump. Effect: Smaller steps would give smooth lens move. Larger steps would move
    ///                lens to destination in one step.
    /// Type:          int
    /// Range:         [10,1024]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   jumpToStartLimit;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// numNearSteps
    ///
    /// Description:   Number of steps at near end. Effect: Affects near range of fine search.
    /// Type:          int
    /// Range:         [0,10]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   numNearSteps;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// numFarSteps
    ///
    /// Description:   Number of steps at far end. Effect: Affects far range of fine search.
    /// Type:          int
    /// Range:         [0,10]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   numFarSteps;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// dciafStepSize
    ///
    /// Description:   Step size to determine range of fine search. Effect: Affects range of fine search.
    /// Type:          int
    /// Range:         [1,20]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   dciafStepSize;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// motionDataUseEnable
    ///
    /// Description:   Flag for using gyro data for trigger. Effect: Uses gyro info for scene change and panning stable.
    /// Type:          uint
    /// Range:         [0,1]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                                  motionDataUseEnable;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// sceneChangeLensPositionThreshold
    ///
    /// Description:   Lens position delta threshold for scene change detection.
    /// Type:          int
    /// Range:         [10,40]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   sceneChangeLensPositionThreshold;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// panningStableLensPositionThreshold
    ///
    /// Description:   Lens position delta threshold for scene stable.
    /// Type:          int
    /// Range:         [5,20]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   panningStableLensPositionThreshold;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// panningStableDurationMSBright
    ///
    /// Description:   Time duration to consider scene stable in bright light in ms. Effect: Trigger speed and behavior in
    ///                bright light.
    /// Type:          int
    /// Range:         [66,198]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   panningStableDurationMSBright;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// panningStableDurationMSLow
    ///
    /// Description:   Time duration to consider scene stable in low light in ms. Effect: Trigger speed and behavior in low
    ///                light.
    /// Type:          int
    /// Range:         [100,400]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   panningStableDurationMSLow;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// maxLowLightWaitMs
    ///
    /// Description:   Time duration Focus Converge Time out in ms in Low Light Effect: Can cause to time out faster if DCRF is
    ///                not working.
    /// Type:          int
    /// Range:         [100,400]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   maxLowLightWaitMs;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// maxNormalLightWaitMs
    ///
    /// Description:   Time duration Focus Converge Time out in ms in Low Light Effect: Can cause to time out faster if DCRF is
    ///                not working.
    /// Type:          int
    /// Range:         [50,400]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   maxNormalLightWaitMs;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// jumpWithNoSkip
    ///
    /// Description:   If Last Jump before fine search exceeds this threshold, skip a frame Effect: If disabled, can cause focus
    ///                failures when moving between infinity and macro.
    /// Type:          int
    /// Range:         [0,1000]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   jumpWithNoSkip;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// skipframesBeforeFineSearch
    ///
    /// Description:   No of Frames to skip before fine search if a big jump is detected, Effect: If disabled, can cause focus
    ///                failures when moving between infinity and macro.
    /// Type:          int
    /// Range:         [0,10]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   skipframesBeforeFineSearch;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// distanceThresholdMacroRegionInMM
    ///
    /// Description:   Used to compute dynamic scene change threshold for macro region.
    /// Type:          int
    /// Range:         [100,400]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   distanceThresholdMacroRegionInMM;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// distanceThresholdNonMacroFactor
    ///
    /// Description:   Used to compute dynamic scene change threshold for macro region.
    /// Type:          int
    /// Range:         [0,100]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   distanceThresholdNonMacroFactor;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// lowLightThreshold
    ///
    /// Description:   Maps to the Lux index to understand whats the threshold for low light. Effect: Trigger speed and behavior
    ///                in low light.
    /// Type:          int
    /// Range:         [0,8]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   lowLightThreshold;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// useFineSearchExtension
    ///
    /// Description:   Enables fine search extension. Effect: WIll account for DCRF failures if any.
    /// Type:          uint
    /// Range:         [0,1]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                                  useFineSearchExtension;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// macroRegionThresholdInMM
    ///
    /// Description:   Use the threshold to determine if its in macro region. Effect: Allows to use correct setp size and no of
    ///                steps per region.
    /// Type:          int
    /// Range:         [0,5000]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   macroRegionThresholdInMM;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// farRegionThresholdInMM
    ///
    /// Description:   Use the threshold to determine if its in macro region. Effect: Allows to use correct setp size and no of
    ///                steps per region.
    /// Type:          int
    /// Range:         [0,10000]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                                   farRegionThresholdInMM;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// normalLightFineSearchInfo - Array
    /// Min Length:    1
    /// Max Length:    3
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                                  normalLightFineSearchInfoCount;
    UINT32                                  normalLightFineSearchInfoID;
    chromatixAFDCIAFFineSearchStepInfoType* normalLightFineSearchInfo;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// lowLightFineSearchInfo - Array
    /// Min Length:    1
    /// Max Length:    3
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                                  lowLightFineSearchInfoCount;
    UINT32                                  lowLightFineSearchInfoID;
    chromatixAFDCIAFFineSearchStepInfoType* lowLightFineSearchInfo;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixAFDCIAFDistanceRange
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum class chromatixAFDCIAFDistanceRange
{
    AF_DCIAF_MACRO_RANGE = 0,
    AF_DCIAF_MID_RANGE   = 1,
    AF_DCIAF_FAR_RANGE   = 2,
    AF_DCIAF_MAX_RANGE   = 3
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDCIAFTypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class chromatixDCIAFTypeClass : public ParameterModule, public chromatixDCIAFType
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const UINT16 MAJOR = 7;
    static const UINT16 MINOR = 0;
    static const UINT32 PATCH = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Default Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDCIAFTypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDCIAFTypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~chromatixDCIAFTypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixAFDCIAFFineSearchStepInfoType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixAFDCIAFFineSearchStepInfoType(
        ParameterFileSymbolTableEntry* entry,
        chromatixAFDCIAFFineSearchStepInfoType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixDCIAFType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixDCIAFType(
        ParameterFileSymbolTableEntry* entry,
        chromatixDCIAFType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatixDCIAFType::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadparameter_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatixDCIAFType::parameter_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatixDCIAFType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadchromatixDCIAFType(
        chromatixDCIAFType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadparameter_versionStruct(
        chromatixDCIAFType::parameter_versionStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class chromatixDCIAFTypeClass

AFDCIAFELEMENTS_NAMESPACE_END
#endif // AFDCIAFELEMENTS_H

