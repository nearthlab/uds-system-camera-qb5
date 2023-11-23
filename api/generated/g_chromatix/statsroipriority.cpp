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
/// @file  statsroipriority.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "statsroipriority.h"
#include "parametersetmanager.h"

STATSROIPRIORITY_NAMESPACE_BEGIN


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load modFaceRoiTriggerDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL statsroipriorityClass::LoadmodFaceRoiTriggerDataType(
    ParameterFileSymbolTableEntry* entry,
    modFaceRoiTriggerDataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = statsglobalelements::statsglobalelementsClass::LoadglbTriggerPointType(entry, &structure->triggerPt, alignment);

    // Reading Array triggerData from symbol table
    {
        result = result && entry->Read(&structure->triggerDataCount, alignment);
        structure->triggerDataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->triggerData = PARAMETER_NEW statsglobalelements::glbTriggerDataFloatType[structure->triggerDataCount];
        }
        if (!result || structure->triggerData == NULL)
        {
            structure->triggerDataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->triggerDataCount; i++)
        {
            result = statsglobalelements::statsglobalelementsClass::LoadglbTriggerDataFloatType(pointerEntry, &structure->triggerData[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixStatsROIPriorityType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL statsroipriorityClass::LoadchromatixStatsROIPriorityType(
    ParameterFileSymbolTableEntry* entry,
    chromatixStatsROIPriorityType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->dominantScoreEnhancement, alignment);
    result = result && LoadmodFaceRoiTriggerDataType(entry, &structure->FaceROISizeWeight, alignment);
    result = result && LoadmodFaceRoiTriggerDataType(entry, &structure->FaceROILocationWeight, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload modFaceRoiTriggerDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void statsroipriorityClass::UnloadmodFaceRoiTriggerDataType(
    modFaceRoiTriggerDataType* structure)
{
    PARAMETER_DELETE[] structure->triggerData;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatixStatsROIPriorityType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void statsroipriorityClass::UnloadchromatixStatsROIPriorityType(
    chromatixStatsROIPriorityType* structure)
{
    UnloadmodFaceRoiTriggerDataType(&structure->FaceROISizeWeight);
    UnloadmodFaceRoiTriggerDataType(&structure->FaceROILocationWeight);
}

STATSROIPRIORITY_NAMESPACE_END