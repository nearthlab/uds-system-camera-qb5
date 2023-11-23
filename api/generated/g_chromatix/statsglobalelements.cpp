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
/// @file  statsglobalelements.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "statsglobalelements.h"
#include "parametersetmanager.h"

STATSGLOBALELEMENTS_NAMESPACE_BEGIN


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load glbTriggerPointType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL statsglobalelementsClass::LoadglbTriggerPointType(
    ParameterFileSymbolTableEntry* entry,
    glbTriggerPointType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->start, alignment);
    result = result && entry->Read(&structure->end, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load glbFloatDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL statsglobalelementsClass::LoadglbFloatDataType(
    ParameterFileSymbolTableEntry* entry,
    glbFloatDataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load glbTriggerDataFloatType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL statsglobalelementsClass::LoadglbTriggerDataFloatType(
    ParameterFileSymbolTableEntry* entry,
    glbTriggerDataFloatType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = LoadglbTriggerPointType(entry, &structure->triggerPt, alignment);
    result = result && LoadglbFloatDataType(entry, &structure->triggerData, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load FaceROIDiffThresholdDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL statsglobalelementsClass::LoadFaceROIDiffThresholdDataType(
    ParameterFileSymbolTableEntry* entry,
    FaceROIDiffThresholdDataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->locationThreshold, alignment);
    result = result && entry->Read(&structure->sizeThreshold, alignment);
    result = result && entry->Read(&structure->countThreshold, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load FaceROIDiffThresholdType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL statsglobalelementsClass::LoadFaceROIDiffThresholdType(
    ParameterFileSymbolTableEntry* entry,
    FaceROIDiffThresholdType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = LoadglbTriggerPointType(entry, &structure->triggerPt, alignment);
    result = result && LoadFaceROIDiffThresholdDataType(entry, &structure->triggerData, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load statsExtensionParamType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL statsglobalelementsClass::LoadstatsExtensionParamType(
    ParameterFileSymbolTableEntry* entry,
    statsExtensionParamType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->ID, alignment);

    // Reading String Name from symbol table
    {
        UINT32 count = 0;
        result = result && entry->Read(&count, alignment);
        ParameterFileSymbolTableEntry* stringPointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && stringPointerEntry != NULL;
        structure->Name = NULL;
        result = result && stringPointerEntry->ReadString(&structure->Name, count, alignment);
    }
    result = result && entry->Read(&structure->enableFlag, alignment);

    // Reading Array data from symbol table
    {
        result = result && entry->Read(&structure->dataCount, alignment);
        structure->dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->data = pointerEntry->ReadArray<FLOAT>(structure->dataCount, alignment);
            result = structure->data != NULL;
        }
        if (!result || structure->data == NULL)
        {
            structure->dataCount = 0;
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload statsExtensionParamType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void statsglobalelementsClass::UnloadstatsExtensionParamType(
    statsExtensionParamType* structure)
{
    PARAMETER_DELETE[] structure->Name;
    PARAMETER_DELETE[] structure->data;
}

STATSGLOBALELEMENTS_NAMESPACE_END