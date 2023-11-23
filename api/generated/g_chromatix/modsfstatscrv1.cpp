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
/// @file  modsfstatscrv1.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "modsfstatscrv1.h"
#include "parametersetmanager.h"

MODSFSTATSCRV1_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixSFStatScrV1TypeClass::chromatixSFStatScrV1TypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(moduleID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(enableFlag);
    PARAMETER_INITIALIZE(darkThresholdData);
    PARAMETER_INITIALIZE(saturationThresholdData);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixSFStatScrV1TypeClass::chromatixSFStatScrV1TypeClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(moduleID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(enableFlag);
    PARAMETER_INITIALIZE(darkThresholdData);
    PARAMETER_INITIALIZE(saturationThresholdData);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixSFStatScrV1TypeClass::~chromatixSFStatScrV1TypeClass()
{
    UnloadchromatixSFStatScrV1Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatixSFStatScrV1TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "SFStatScrV1")) == 0)
    {
        name = "SFStatScrV1";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load modSFStatScrV1ThrDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixSFStatScrV1TypeClass::LoadmodSFStatScrV1ThrDataType(
    ParameterFileSymbolTableEntry* entry,
    modSFStatScrV1ThrDataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = awbglobalelements::awbglobalelementsClass::LoadtriggerPointType(entry, &structure->triggerPt, alignment);

    // Reading Array triggerData from symbol table
    {
        result = result && entry->Read(&structure->triggerDataCount, alignment);
        structure->triggerDataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->triggerData = PARAMETER_NEW awbglobalelements::awbTriggerDataRGBType[structure->triggerDataCount];
        }
        if (!result || structure->triggerData == NULL)
        {
            structure->triggerDataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->triggerDataCount; i++)
        {
            result = awbglobalelements::awbglobalelementsClass::LoadawbTriggerDataRGBType(pointerEntry, &structure->triggerData[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixSFStatScrV1Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixSFStatScrV1TypeClass::LoadchromatixSFStatScrV1Type(
    ParameterFileSymbolTableEntry* entry,
    chromatixSFStatScrV1Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = awbglobalelements::awbglobalelementsClass::LoadmoduleIDType(entry, &structure->moduleID, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && entry->Read(&structure->enableFlag, alignment);
    result = result && LoadmodSFStatScrV1ThrDataType(entry, &structure->darkThresholdData, alignment);
    result = result && LoadmodSFStatScrV1ThrDataType(entry, &structure->saturationThresholdData, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixSFStatScrV1TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatixSFStatScrV1Type::module_versionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->major_revision, alignment);
    result = result && entry->Read(&structure->minor_revision, alignment);
    result = result && entry->Read(&structure->incr_revision, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload modSFStatScrV1ThrDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatixSFStatScrV1TypeClass::UnloadmodSFStatScrV1ThrDataType(
    modSFStatScrV1ThrDataType* structure)
{
    PARAMETER_DELETE[] structure->triggerData;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatixSFStatScrV1Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatixSFStatScrV1TypeClass::UnloadchromatixSFStatScrV1Type(
    chromatixSFStatScrV1Type* structure)
{
    UnloadmodSFStatScrV1ThrDataType(&structure->darkThresholdData);
    UnloadmodSFStatScrV1ThrDataType(&structure->saturationThresholdData);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatixSFStatScrV1TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatixSFStatScrV1TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatixSFStatScrV1TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && LoadchromatixSFStatScrV1Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


MODSFSTATSCRV1_NAMESPACE_END
