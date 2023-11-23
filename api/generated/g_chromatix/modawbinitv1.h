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
/// @file  modawbinitv1.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MODAWBINITV1_H
#define MODAWBINITV1_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "globalelements.h"
#include "awbglobalelements.h"

#define MODAWBINITV1_NAMESPACE_BEGIN namespace modawbinitv1 {
#define MODAWBINITV1_NAMESPACE_END }

MODAWBINITV1_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// modAWBInitV1BGStatsModeType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum class modAWBInitV1BGStatsModeType
{
    ZoomFOV = 0,
    FullFOV = 1
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// modAWBInitV1BGStatsConfType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct modAWBInitV1BGStatsConfType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// BGStatMode
    ///
    /// Description:   BG stats window config mode: 0 = Full FOV, 1 = Zoom FOV
    /// Default Value: FullFOV
    /// Range:         [0,1]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    modAWBInitV1BGStatsModeType BGStatMode;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// modAWBInitV1GlobalEnvConfType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct modAWBInitV1GlobalEnvConfType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// DepthMapEnable
    ///
    /// Tuning Level:  must_tune
    /// Description:   All depth map modules and info enable/disable
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    awbglobalelements::enableFlagType DepthMapEnable;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixAWBInitV1Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatixAWBInitV1Type
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Binary file symbol table entry ID
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32 SymbolTableID;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// moduleID
    ///
    /// Tuning Level:  never_tune
    /// Description:   Define module ID, sub module ID
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    awbglobalelements::moduleIDType                  moduleID;

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
    /// enableFlag
    ///
    /// Tuning Level:  must_tune
    /// Description:   module enable flag
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    awbglobalelements::enableFlagType                enableFlag;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// initialGain
    ///
    /// Tuning Level:  must_tune
    /// Description:   Initial/default AWB gain, will be applied when camera launches or there is no confident AWB decision
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    awbglobalelements::awbRGBDataType                initialGain;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// initialCCT
    ///
    /// Tuning Level:  must_tune
    /// Description:   Initial/default CCT value, will be applied when camera launches or if there is no confident AWB decision
    /// Type:          float
    /// Range:         [2000.0,9999.9]
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT                         initialCCT;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// BGStatConf
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    modAWBInitV1BGStatsConfType   BGStatConf;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GlobalEnvConf
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    modAWBInitV1GlobalEnvConfType GlobalEnvConf;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatixAWBInitV1TypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class chromatixAWBInitV1TypeClass : public ParameterModule, public chromatixAWBInitV1Type
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const UINT16 MAJOR = 1;
    static const UINT16 MINOR = 1;
    static const UINT32 PATCH = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Default Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixAWBInitV1TypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatixAWBInitV1TypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~chromatixAWBInitV1TypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load modAWBInitV1BGStatsConfType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadmodAWBInitV1BGStatsConfType(
        ParameterFileSymbolTableEntry* entry,
        modAWBInitV1BGStatsConfType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load modAWBInitV1GlobalEnvConfType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadmodAWBInitV1GlobalEnvConfType(
        ParameterFileSymbolTableEntry* entry,
        modAWBInitV1GlobalEnvConfType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatixAWBInitV1Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadchromatixAWBInitV1Type(
        ParameterFileSymbolTableEntry* entry,
        chromatixAWBInitV1Type* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatixAWBInitV1Type::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class chromatixAWBInitV1TypeClass

MODAWBINITV1_NAMESPACE_END
#endif // MODAWBINITV1_H

