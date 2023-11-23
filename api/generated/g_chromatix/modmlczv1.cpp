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
/// @file  modmlczv1.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "modmlczv1.h"
#include "parametersetmanager.h"

MODMLCZV1_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixMLCZV1TypeClass::chromatixMLCZV1TypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(moduleID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(enableFlag);
    PARAMETER_INITIALIZE(detectionZoneCount);
    PARAMETER_INITIALIZE(detectionZoneID);
    PARAMETER_INITIALIZE(detectionZone);
    PARAMETER_INITIALIZE(MLCZCount);
    PARAMETER_INITIALIZE(MLCZID);
    PARAMETER_INITIALIZE(MLCZ);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixMLCZV1TypeClass::chromatixMLCZV1TypeClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(moduleID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(enableFlag);
    PARAMETER_INITIALIZE(detectionZone);
    PARAMETER_INITIALIZE(MLCZ);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixMLCZV1TypeClass::~chromatixMLCZV1TypeClass()
{
    UnloadchromatixMLCZV1Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatixMLCZV1TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "SFMLCZV1")) == 0)
    {
        name = "SFMLCZV1";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load awbMLCZoneConfigType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixMLCZV1TypeClass::LoadawbMLCZoneConfigType(
    ParameterFileSymbolTableEntry* entry,
    awbMLCZoneConfigType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading String Description from symbol table
    {
        UINT32 count = 0;
        result = entry->Read(&count, alignment);
        ParameterFileSymbolTableEntry* stringPointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && stringPointerEntry != NULL;
        structure->Description = NULL;
        result = result && stringPointerEntry->ReadString(&structure->Description, count, alignment);
    }
    result = result && entry->Read(&structure->groupID, alignment);
    structure->zoneType = (awbglobalelements::awbZoneType)entry->ReadEnum(&result, alignment);
    result = result && entry->Read(&structure->triggerLevel, alignment);
    for (UINT32 i = 0; result && i < 3; i++)
    {
        structure->triggerCtrlType[i] = (awbMLCZTriggerCtrlType)entry->ReadEnum(&result, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load awbMLCDetecionZoneType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixMLCZV1TypeClass::LoadawbMLCDetecionZoneType(
    ParameterFileSymbolTableEntry* entry,
    awbMLCDetecionZoneType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = LoadawbMLCZoneConfigType(entry, &structure->zoneConfigData, alignment);
    result = result && awbglobalelements::awbglobalelementsClass::LoadtriggerPointType(entry, &structure->triggerPt, alignment);

    // Reading Array triggerData from symbol table
    {
        result = result && entry->Read(&structure->triggerDataCount, alignment);
        structure->triggerDataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->triggerData = PARAMETER_NEW awbglobalelements::awbTriggerDataZoneType[structure->triggerDataCount];
        }
        if (!result || structure->triggerData == NULL)
        {
            structure->triggerDataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->triggerDataCount; i++)
        {
            result = awbglobalelements::awbglobalelementsClass::LoadawbTriggerDataZoneType(pointerEntry, &structure->triggerData[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load awbMLCZoneType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixMLCZV1TypeClass::LoadawbMLCZoneType(
    ParameterFileSymbolTableEntry* entry,
    awbMLCZoneType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = LoadawbMLCZoneConfigType(entry, &structure->zoneConfigData, alignment);
    result = result && awbglobalelements::awbglobalelementsClass::LoadtriggerPointType(entry, &structure->triggerPt, alignment);

    // Reading Array triggerData from symbol table
    {
        result = result && entry->Read(&structure->triggerDataCount, alignment);
        structure->triggerDataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->triggerData = PARAMETER_NEW awbglobalelements::awbTriggerDataZoneLevel1Type[structure->triggerDataCount];
        }
        if (!result || structure->triggerData == NULL)
        {
            structure->triggerDataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->triggerDataCount; i++)
        {
            result = awbglobalelements::awbglobalelementsClass::LoadawbTriggerDataZoneLevel1Type(pointerEntry, &structure->triggerData[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixMLCZV1Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixMLCZV1TypeClass::LoadchromatixMLCZV1Type(
    ParameterFileSymbolTableEntry* entry,
    chromatixMLCZV1Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = awbglobalelements::awbglobalelementsClass::LoadmoduleIDType(entry, &structure->moduleID, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && entry->Read(&structure->enableFlag, alignment);

    // Reading Array detectionZone from symbol table
    {
        result = result && entry->Read(&structure->detectionZoneCount, alignment);
        structure->detectionZoneID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->detectionZone = PARAMETER_NEW awbMLCDetecionZoneType[structure->detectionZoneCount];
        }
        if (!result || structure->detectionZone == NULL)
        {
            structure->detectionZoneCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->detectionZoneCount; i++)
        {
            result = LoadawbMLCDetecionZoneType(pointerEntry, &structure->detectionZone[i], alignment);
        }
    }

    // Reading Array MLCZ from symbol table
    {
        result = result && entry->Read(&structure->MLCZCount, alignment);
        structure->MLCZID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->MLCZ = PARAMETER_NEW awbMLCZoneType[structure->MLCZCount];
        }
        if (!result || structure->MLCZ == NULL)
        {
            structure->MLCZCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->MLCZCount; i++)
        {
            result = LoadawbMLCZoneType(pointerEntry, &structure->MLCZ[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixMLCZV1TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatixMLCZV1Type::module_versionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->major_revision, alignment);
    result = result && entry->Read(&structure->minor_revision, alignment);
    result = result && entry->Read(&structure->incr_revision, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload awbMLCZoneConfigType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatixMLCZV1TypeClass::UnloadawbMLCZoneConfigType(
    awbMLCZoneConfigType* structure)
{
    PARAMETER_DELETE[] structure->Description;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload awbMLCDetecionZoneType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatixMLCZV1TypeClass::UnloadawbMLCDetecionZoneType(
    awbMLCDetecionZoneType* structure)
{
    UnloadawbMLCZoneConfigType(&structure->zoneConfigData);
    PARAMETER_DELETE[] structure->triggerData;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload awbMLCZoneType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatixMLCZV1TypeClass::UnloadawbMLCZoneType(
    awbMLCZoneType* structure)
{
    UnloadawbMLCZoneConfigType(&structure->zoneConfigData);
    for (UINT32 i = 0; i < structure->triggerDataCount; i++)
    {
        awbglobalelements::awbglobalelementsClass::UnloadawbTriggerDataZoneLevel1Type(&structure->triggerData[i]);
    }
    PARAMETER_DELETE[] structure->triggerData;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatixMLCZV1Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatixMLCZV1TypeClass::UnloadchromatixMLCZV1Type(
    chromatixMLCZV1Type* structure)
{
    for (UINT32 i = 0; i < structure->detectionZoneCount; i++)
    {
        UnloadawbMLCDetecionZoneType(&structure->detectionZone[i]);
    }
    PARAMETER_DELETE[] structure->detectionZone;
    for (UINT32 i = 0; i < structure->MLCZCount; i++)
    {
        UnloadawbMLCZoneType(&structure->MLCZ[i]);
    }
    PARAMETER_DELETE[] structure->MLCZ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatixMLCZV1TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatixMLCZV1TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatixMLCZV1TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && LoadchromatixMLCZV1Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


MODMLCZV1_NAMESPACE_END
