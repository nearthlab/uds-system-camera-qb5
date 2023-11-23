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
/// @file  afdepthafelements.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef AFDEPTHAFELEMENTS_H
#define AFDEPTHAFELEMENTS_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"

#define AFDEPTHAFELEMENTS_NAMESPACE_BEGIN namespace afdepthafelements {
#define AFDEPTHAFELEMENTS_NAMESPACE_END }

AFDEPTHAFELEMENTS_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDepthAFFocusEntryType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixDepthAFFocusEntryType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// startPosition
    ///
    /// Description:   start position of the trigger zone
    /// Type:          int
    /// Default Value: 0
    /// Range:         [0, 399]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 startPosition;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// endPosition
    ///
    /// Description:   end position of the trigger zone
    /// Type:          int
    /// Default Value: 399
    /// Range:         [0, 399]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 endPosition;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// focusDoneThreshold
    ///
    /// Description:   threshold of defocus that indicate focus is done
    /// Type:          int
    /// Default Value: 8
    /// Range:         [0,10]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 focusDoneThreshold;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// fineScanStepSize
    ///
    /// Description:   defocus range in far direction when current lens position be treated as focused
    /// Type:          int
    /// Default Value: 8
    /// Range:         [0, 20]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 fineScanStepSize;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// stepsRangeNear
    ///
    /// Description:   Steps in near direction indicate fine search range
    /// Type:          int
    /// Default Value: 30
    /// Range:         [0, 5]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 stepsRangeNear;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// stepsRangeFar
    ///
    /// Description:   Steps in far direction indicate fine search range
    /// Type:          int
    /// Default Value: 30
    /// Range:         [0, 5]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 stepsRangeFar;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDepthAFFocusType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixDepthAFFocusType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// entries - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                          entriesCount;
    UINT32                          entriesID;
    chromatixDepthAFFocusEntryType* entries;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDepthAFConverge
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixDepthAFConverge
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// waitConfidenceRecoverCount
    ///
    /// Description:   frame count that algorithm wait for recorver before fallback
    /// Type:          int
    /// Default Value: 5
    /// Range:         [0, 8]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                     waitConfidenceRecoverCount;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// frameSkip
    ///
    /// Description:   frameSkip in converge after lens move
    /// Type:          int
    /// Default Value: 0
    /// Range:         [0,2]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                     frameSkip;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// normalLight
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDepthAFFocusType normalLight;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// lowlight
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDepthAFFocusType lowlight;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDepthAFDOFScalerType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixDepthAFDOFScalerType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// normalizedLensPosition
    ///
    /// Description:   Normalized lens position, if lens position is near end, the value is 1, if lens position is far end, the
    ///                value is 0.
    /// Type:          float
    /// Default Value: 0.0
    /// Range:         [0,1]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT normalizedLensPosition;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// DOFScaler
    ///
    /// Description:   DOF scaler value at the given normalized lens position, this scaler will be applied to fine scan step
    ///                size, defocus threshold, focus done threshold etc./
    /// Type:          float
    /// Default Value: 0.0
    /// Range:         [1,10]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT DOFScaler;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDepthAFDOFScalerEntryType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixDepthAFDOFScalerEntryType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// entries - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                         entriesCount;
    UINT32                         entriesID;
    chromatixDepthAFDOFScalerType* entries;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDepthAFMonitor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixDepthAFMonitor
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// DOFScalerTable
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDepthAFDOFScalerEntryType DOFScalerTable;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDepthAFWindowConfigure
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixDepthAFWindowConfigure
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// enable
    ///
    /// Description:   Enable for this window
    /// Type:          bool
    /// Default Value: true
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL  enable;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// horizontalGridCount
    ///
    /// Description:   Grid size in horizontal direction
    /// Type:          int
    /// Default Value: 1
    /// Range:         [1,15]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 horizontalGridCount;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// verticalGridCount
    ///
    /// Description:   Grid size in vertical direction
    /// Type:          int
    /// Default Value: 1
    /// Range:         [1,12]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 verticalGridCount;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// horizontalSkip
    ///
    /// Description:   pixel skip count in horizontal direction for stats parsing
    /// Type:          int
    /// Default Value: 1
    /// Range:         [0, 4]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 horizontalSkip;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// verticalSkip
    ///
    /// Description:   line skip count in vertical direction for stats parsing
    /// Type:          int
    /// Default Value: 1
    /// Range:         [0, 4]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 verticalSkip;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// minConfidentPixelPercentage
    ///
    /// Description:   threshold of confident pixel percentage when a grid be selected
    /// Type:          int
    /// Default Value: 80
    /// Range:         [0, 100]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 minConfidentPixelPercentage;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// minConfidentGridPercentage
    ///
    /// Description:   threshold of confident grid percentage when window be selected
    /// Type:          int
    /// Default Value: 20
    /// Range:         [0, 100]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 minConfidentGridPercentage;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// defocusPercentile
    ///
    /// Description:   Nth percentile of the valid grid to select for use in multi depth scene
    /// Type:          float
    /// Default Value: 0.0
    /// Range:         [0.0, 1.0]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT defocusPercentile;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDepthAFConfidenceEntryType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixDepthAFConfidenceEntryType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// startLuxIndex
    ///
    /// Description:   Lux index of zone start
    /// Type:          float
    /// Default Value: 20
    /// Range:         [0,unbounded]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT startLuxIndex;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// endLuxIndex
    ///
    /// Description:   Lux Index of zone end
    /// Type:          float
    /// Default Value: 100
    /// Range:         [0,unbounded]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT endLuxIndex;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// threshold
    ///
    /// Description:   threshold that used to judge a pixel is confident or not
    /// Type:          int
    /// Default Value: 50
    /// Range:         [0,unbounded]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32 threshold;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDepthAFConfidenceType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixDepthAFConfidenceType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// entries - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                               entriesCount;
    UINT32                               entriesID;
    chromatixDepthAFConfidenceEntryType* entries;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDepthAFFOVMapType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixDepthAFFOVMapType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// horizontalOffset
    ///
    /// Description:   Depth stats starting point in horizontal direction in camif size
    /// Type:          float
    /// Default Value: 0
    /// Range:         [-2, 2]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT horizontalOffset;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// verticalOffset
    ///
    /// Description:   Depth stats starting point in vertical direction in camif size
    /// Type:          float
    /// Default Value: 0
    /// Range:         [-2, 2]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT verticalOffset;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// horizontalCoverage
    ///
    /// Description:   Depth stats coverage in horizontal direction in camif size
    /// Type:          float
    /// Default Value: 1.0
    /// Range:         [0, 3.0]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT horizontalCoverage;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// verticalCoverage
    ///
    /// Description:   Depth stats coverage in vertical direction in camif size
    /// Type:          float
    /// Default Value: 1.0
    /// Range:         [0, 3.0]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT verticalCoverage;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDepthAFStats
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixDepthAFStats
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// minimalDistance
    ///
    /// Description:   Minimal distance in millimeter that sensor can provide
    /// Type:          int
    /// Default Value: 100
    /// Range:         [0,unbounded]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                           minimalDistance;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// maximumDistance
    ///
    /// Description:   maximum distance in millimeter that sensor can provide
    /// Type:          int
    /// Default Value: 3000
    /// Range:         [0,unbounded]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    INT32                           maximumDistance;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// fovMap
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDepthAFFOVMapType      fovMap;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// confidenceTable
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDepthAFConfidenceType  confidenceTable;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// center
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDepthAFWindowConfigure center;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// peripheral
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDepthAFWindowConfigure peripheral;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// touch
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDepthAFWindowConfigure touch;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// face
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDepthAFWindowConfigure face;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDepthAFType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixDepthAFType
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
    /// stats
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDepthAFStats    stats;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// monitor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDepthAFMonitor  monitor;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// converge
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDepthAFConverge converge;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixDepthAFTypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class chromatixDepthAFTypeClass : public ParameterModule, public chromatixDepthAFType
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const UINT16 MAJOR = 8;
    static const UINT16 MINOR = 0;
    static const UINT32 PATCH = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Default Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDepthAFTypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixDepthAFTypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~chromatixDepthAFTypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixDepthAFFocusEntryType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixDepthAFFocusEntryType(
        ParameterFileSymbolTableEntry* entry,
        chromatixDepthAFFocusEntryType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixDepthAFFocusType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixDepthAFFocusType(
        ParameterFileSymbolTableEntry* entry,
        chromatixDepthAFFocusType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixDepthAFConverge
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixDepthAFConverge(
        ParameterFileSymbolTableEntry* entry,
        chromatixDepthAFConverge* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixDepthAFDOFScalerType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixDepthAFDOFScalerType(
        ParameterFileSymbolTableEntry* entry,
        chromatixDepthAFDOFScalerType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixDepthAFDOFScalerEntryType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixDepthAFDOFScalerEntryType(
        ParameterFileSymbolTableEntry* entry,
        chromatixDepthAFDOFScalerEntryType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixDepthAFMonitor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixDepthAFMonitor(
        ParameterFileSymbolTableEntry* entry,
        chromatixDepthAFMonitor* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixDepthAFWindowConfigure
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixDepthAFWindowConfigure(
        ParameterFileSymbolTableEntry* entry,
        chromatixDepthAFWindowConfigure* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixDepthAFConfidenceEntryType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixDepthAFConfidenceEntryType(
        ParameterFileSymbolTableEntry* entry,
        chromatixDepthAFConfidenceEntryType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixDepthAFConfidenceType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixDepthAFConfidenceType(
        ParameterFileSymbolTableEntry* entry,
        chromatixDepthAFConfidenceType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixDepthAFFOVMapType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixDepthAFFOVMapType(
        ParameterFileSymbolTableEntry* entry,
        chromatixDepthAFFOVMapType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixDepthAFStats
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixDepthAFStats(
        ParameterFileSymbolTableEntry* entry,
        chromatixDepthAFStats* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixDepthAFType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixDepthAFType(
        ParameterFileSymbolTableEntry* entry,
        chromatixDepthAFType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatixDepthAFType::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadparameter_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatixDepthAFType::parameter_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatixDepthAFFocusType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadchromatixDepthAFFocusType(
        chromatixDepthAFFocusType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatixDepthAFConverge
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadchromatixDepthAFConverge(
        chromatixDepthAFConverge* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatixDepthAFDOFScalerEntryType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadchromatixDepthAFDOFScalerEntryType(
        chromatixDepthAFDOFScalerEntryType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatixDepthAFMonitor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadchromatixDepthAFMonitor(
        chromatixDepthAFMonitor* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatixDepthAFConfidenceType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadchromatixDepthAFConfidenceType(
        chromatixDepthAFConfidenceType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatixDepthAFStats
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadchromatixDepthAFStats(
        chromatixDepthAFStats* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatixDepthAFType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadchromatixDepthAFType(
        chromatixDepthAFType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadparameter_versionStruct(
        chromatixDepthAFType::parameter_versionStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class chromatixDepthAFTypeClass

AFDEPTHAFELEMENTS_NAMESPACE_END
#endif // AFDEPTHAFELEMENTS_H

