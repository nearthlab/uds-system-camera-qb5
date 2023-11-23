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
/// @file  modsensorcalv1.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "modsensorcalv1.h"
#include "parametersetmanager.h"

MODSENSORCALV1_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixSenorCalV1TypeClass::chromatixSenorCalV1TypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(moduleID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(enableFlag);
    PARAMETER_INITIALIZE(numOfCalFactors);
    PARAMETER_INITIALIZE(cctOfCalFactors);
    PARAMETER_INITIALIZE(goldenModuleCal);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixSenorCalV1TypeClass::chromatixSenorCalV1TypeClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(moduleID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(enableFlag);
    PARAMETER_INITIALIZE(numOfCalFactors);
    PARAMETER_INITIALIZE(cctOfCalFactors);
    PARAMETER_INITIALIZE(goldenModuleCal);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixSenorCalV1TypeClass::~chromatixSenorCalV1TypeClass()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatixSenorCalV1TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "sensorCalV1")) == 0)
    {
        name = "sensorCalV1";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixSenorCalV1Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixSenorCalV1TypeClass::LoadchromatixSenorCalV1Type(
    ParameterFileSymbolTableEntry* entry,
    chromatixSenorCalV1Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = awbglobalelements::awbglobalelementsClass::LoadmoduleIDType(entry, &structure->moduleID, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && entry->Read(&structure->enableFlag, alignment);
    result = result && entry->Read(&structure->numOfCalFactors, alignment);
    result = result && entry->ReadArray(structure->cctOfCalFactors, 6, alignment);
    for (UINT32 i = 0; result && i < 15; i++)
    {
        result = result && awbglobalelements::awbglobalelementsClass::LoadawbPointDataType(entry, &structure->goldenModuleCal[i], alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixSenorCalV1TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatixSenorCalV1Type::module_versionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->major_revision, alignment);
    result = result && entry->Read(&structure->minor_revision, alignment);
    result = result && entry->Read(&structure->incr_revision, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatixSenorCalV1TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatixSenorCalV1TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatixSenorCalV1TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && LoadchromatixSenorCalV1Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


MODSENSORCALV1_NAMESPACE_END