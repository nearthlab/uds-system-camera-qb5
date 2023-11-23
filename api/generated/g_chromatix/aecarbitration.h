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
/// @file  aecarbitration.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AECARBITRATION_H
#define AECARBITRATION_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "globalelements.h"
#include "aecglobalelements.h"

#define AECARBITRATION_NAMESPACE_BEGIN namespace aecArbitration {
#define AECARBITRATION_NAMESPACE_END }

AECARBITRATION_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ISOSettingType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct ISOSettingType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// previewISO100Gain
    ///
    /// Tuning Level:  must_tune
    /// Description:   Specify the Gain corresponding to ISO100 in preview mode
    /// Type:          float
    /// Range:         [0,512]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT  previewISO100Gain;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// enableAntiBandingVsISOPrio
    ///
    /// Tuning Level:  often_tune
    /// Description:   Specify AntiBanding behavior when it conflicts with ISO settings. If enabled, it will favor Flicker
    ///                compensation over ISO consistency
    /// Type:          bool
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL   enableAntiBandingVsISOPrio;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// enableISOQuantization
    ///
    /// Tuning Level:  often_tune
    /// Description:   Enable flag for Quantized ISO value reporting(instead of continuous levels)
    /// Type:          bool
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL   enableISOQuantization;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// thresQuantizationISOValue - Array
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   (If ISO Quantization is enabled), it specify the ISO value thresholds to quantize for
    /// Type:          float
    /// Range:         [0,10000]
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32 thresQuantizationISOValueCount;
    UINT32 thresQuantizationISOValueID;
    FLOAT* thresQuantizationISOValue;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// quantizedISOValue - Array
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   (If ISO Quantization is enabled), it specify the Quantized ISO value wrt thresholds above
    /// Type:          float
    /// Range:         [0,10000]
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32 quantizedISOValueCount;
    UINT32 quantizedISOValueID;
    FLOAT* quantizedISOValue;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ExposureKneeType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct ExposureKneeType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// gain
    ///
    /// Tuning Level:  must_tune
    /// Description:   Gain Value at exposure knee
    /// Type:          float
    /// Range:         [1,512]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT             gain;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// expTime
    ///
    /// Tuning Level:  must_tune
    /// Description:   Exposure time (in NANO SECOND) at exposure knee
    /// Type:          ulong
    /// Range:         [1,60000000000]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT64            expTime;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// incrementPriority
    ///
    /// Tuning Level:  must_tune
    /// Description:   Specify Exposure increment method from knee point. select between Gain and ExpTime priority
    /// Range:         [0,2]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    aecglobalelements::AECExpIncPrioType incrementPriority;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// expIndex
    ///
    /// Tuning Level:  must_tune
    /// Description:   Specify How exposure setting increase from this exposure knee(for ex: Gain priority will increase
    ///                exposure strictly by gain first before Exposure time start increasing.
    /// Type:          float
    /// Range:         [-100,1000]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT             expIndex;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ExposureTableType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct ExposureTableType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// sensitivityCorrectionFactor
    ///
    /// Tuning Level:  must_tune
    /// Description:   Specify the sensitivity correction factor(Binning Factor) for Normalization between Exposure Tables
    /// Type:          float
    /// Range:         [0,16]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT             sensitivityCorrectionFactor;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// expKneeEntries - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32            expKneeEntriesCount;
    UINT32            expKneeEntriesID;
    ExposureKneeType* expKneeEntries;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// thresAntiBandingMinExpTimePct
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Percentage of minimum exposure time ATB is performed. If use a typical value of 1, minimum Exposure time
    ///                is strictly the banding peroid.
    /// Type:          float
    /// Range:         [0.5,1.5]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT             thresAntiBandingMinExpTimePct;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// AECCoreArbitrationType
/// Comments:       Core Arbitration Tuning Definition
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct AECCoreArbitrationType
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
    /// expTables - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                    expTablesCount;
    UINT32                    expTablesID;
    ExposureTableType*        expTables;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// minPreviewVertBlankTime
    ///
    /// Tuning Level:  must_tune
    /// Description:   Preview Minimum vertical Blanking time (in NANO SECOND)
    /// Type:          ulong
    /// Range:         [1,60000000000]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT64                    minPreviewVertBlankTime;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// enableEVExpTableAdj
    ///
    /// Tuning Level:  never_tune
    /// Description:   Enable Flag for Exposure Table Adjustment wrt EV setting. Enabling allow Exp Table to extend beyond by
    ///                digital gain
    /// Type:          bool
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL                      enableEVExpTableAdj;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// enableEVGainCapping
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Enable Flag to cap Exposure table extension only to Max EV Gain specified below
    /// Type:          bool
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL                      enableEVGainCapping;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// maxEVCappingGain
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Specify Maximum Gain Exposure table can extend to by EV settings(if EV Gain Capping is enabled)
    /// Type:          float
    /// Range:         [1,512]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT                     maxEVCappingGain;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ISOData
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ISOSettingType            ISOData;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// antibandingVsFPSMethod
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Specify impact on FPS under Flicker Compensation. LegacyAllowFPSToDrop will allow FPS to drop freely;
    ///                StrictlyEnforceFPS will limit Flicker compensation only within FPS allowance, MaximizeExposureTime will
    ///                allow partial FPS change in near-boundary case.
    /// Range:         [0,2]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    aecglobalelements::AECAntibandingVsFPSMethod antibandingVsFPSMethod;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// enablePreviewManualISO
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Enable Flag to apply Manual ISO to Preview Exposure Setting
    /// Type:          bool
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL                      enablePreviewManualISO;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// enablePreviewManualExpTime
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Enable Flag to apply Manual Exposure Time to Preview Exposure Setting
    /// Type:          bool
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL                      enablePreviewManualExpTime;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// enablePreviewManualFull
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Enable Flag to apply Full Manual settings under full-manual mode to Preview Exposure Setting
    /// Type:          bool
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL                      enablePreviewManualFull;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// disableBandingGainCapping
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   False: backward-compatible: cap max gain to table max. True: no capping
    /// Default Value: false
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL                      disableBandingGainCapping;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// AECCoreArbitrationTypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class AECCoreArbitrationTypeClass : public ParameterModule, public AECCoreArbitrationType
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const UINT16 MAJOR = 1;
    static const UINT16 MINOR = 0;
    static const UINT32 PATCH = 1;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Default Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AECCoreArbitrationTypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    AECCoreArbitrationTypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~AECCoreArbitrationTypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load ISOSettingType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadISOSettingType(
        ParameterFileSymbolTableEntry* entry,
        ISOSettingType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load ExposureKneeType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadExposureKneeType(
        ParameterFileSymbolTableEntry* entry,
        ExposureKneeType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load ExposureTableType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadExposureTableType(
        ParameterFileSymbolTableEntry* entry,
        ExposureTableType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load AECCoreArbitrationType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadAECCoreArbitrationType(
        ParameterFileSymbolTableEntry* entry,
        AECCoreArbitrationType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        AECCoreArbitrationType::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadparameter_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        AECCoreArbitrationType::parameter_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload ISOSettingType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadISOSettingType(
        ISOSettingType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload ExposureTableType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadExposureTableType(
        ExposureTableType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload AECCoreArbitrationType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadAECCoreArbitrationType(
        AECCoreArbitrationType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadparameter_versionStruct(
        AECCoreArbitrationType::parameter_versionStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class AECCoreArbitrationTypeClass

AECARBITRATION_NAMESPACE_END
#endif // AECARBITRATION_H
