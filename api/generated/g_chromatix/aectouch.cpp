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
/// @file  aectouch.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "aectouch.h"
#include "parametersetmanager.h"

AECTOUCH_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AECTouchTypeClass::AECTouchTypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(touchMtr);
    PARAMETER_INITIALIZE(touchConv);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AECTouchTypeClass::AECTouchTypeClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(touchMtr);
    PARAMETER_INITIALIZE(touchConv);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AECTouchTypeClass::~AECTouchTypeClass()
{
    UnloadAECTouchType(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* AECTouchTypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "Touch")) == 0)
    {
        name = "Touch";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load TouchConvergenceType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECTouchTypeClass::LoadTouchConvergenceType(
    ParameterFileSymbolTableEntry* entry,
    TouchConvergenceType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->convSpeedAdjRatio, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load TouchMeteringType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECTouchTypeClass::LoadTouchMeteringType(
    ParameterFileSymbolTableEntry* entry,
    TouchMeteringType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->enableTouchROI, alignment);
    result = result && entry->Read(&structure->weightTouchROI, alignment);
    result = result && entry->Read(&structure->weightTemporalFilter, alignment);
    result = result && entry->Read(&structure->centerWeightStrength, alignment);
    result = result && entry->Read(&structure->enableTouchLEDMetering, alignment);
    result = result && entry->Read(&structure->enableTouchROIHistAdj, alignment);

    // Reading Array ROIHistAdjZone from symbol table
    {
        result = result && entry->Read(&structure->ROIHistAdjZoneCount, alignment);
        structure->ROIHistAdjZoneID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->ROIHistAdjZone = PARAMETER_NEW aecglobalelements::ROIHistAdjZoneType[structure->ROIHistAdjZoneCount];
        }
        if (!result || structure->ROIHistAdjZone == NULL)
        {
            structure->ROIHistAdjZoneCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->ROIHistAdjZoneCount; i++)
        {
            result = aecglobalelements::aecglobalelementsClass::LoadROIHistAdjZoneType(pointerEntry, &structure->ROIHistAdjZone[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load AECTouchType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECTouchTypeClass::LoadAECTouchType(
    ParameterFileSymbolTableEntry* entry,
    AECTouchType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && LoadTouchMeteringType(entry, &structure->touchMtr, alignment);
    result = result && LoadTouchConvergenceType(entry, &structure->touchConv, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECTouchTypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    AECTouchType::module_versionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->major_revision, alignment);
    result = result && entry->Read(&structure->minor_revision, alignment);
    result = result && entry->Read(&structure->incr_revision, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECTouchTypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    AECTouchType::parameter_versionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading String revision from symbol table
    {
        UINT32 count = 0;
        result = entry->Read(&count, alignment);
        ParameterFileSymbolTableEntry* stringPointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && stringPointerEntry != NULL;
        structure->revision = NULL;
        result = result && stringPointerEntry->ReadString(&structure->revision, count, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload TouchMeteringType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AECTouchTypeClass::UnloadTouchMeteringType(
    TouchMeteringType* structure)
{
    PARAMETER_DELETE[] structure->ROIHistAdjZone;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload AECTouchType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AECTouchTypeClass::UnloadAECTouchType(
    AECTouchType* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    UnloadTouchMeteringType(&structure->touchMtr);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AECTouchTypeClass::Unloadparameter_versionStruct(
    AECTouchType::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* AECTouchTypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    AECTouchTypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW AECTouchTypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && LoadAECTouchType(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


AECTOUCH_NAMESPACE_END
