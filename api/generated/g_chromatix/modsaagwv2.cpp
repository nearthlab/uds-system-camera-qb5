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
/// @file  modsaagwv2.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "modsaagwv2.h"
#include "parametersetmanager.h"

MODSAAGWV2_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixSAAGWV2TypeClass::chromatixSAAGWV2TypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(moduleID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(enableFlag);
    PARAMETER_INITIALIZE(outdoorWeightCtrlCount);
    PARAMETER_INITIALIZE(outdoorWeightCtrlID);
    PARAMETER_INITIALIZE(outdoorWeightCtrl);
    PARAMETER_INITIALIZE(AHLightWeightCtrlCount);
    PARAMETER_INITIALIZE(AHLightWeightCtrlID);
    PARAMETER_INITIALIZE(AHLightWeightCtrl);
    PARAMETER_INITIALIZE(confidenceLevelCount);
    PARAMETER_INITIALIZE(confidenceLevelID);
    PARAMETER_INITIALIZE(confidenceLevel);
    PARAMETER_INITIALIZE(outdoorInterpWeightCount);
    PARAMETER_INITIALIZE(outdoorInterpWeightID);
    PARAMETER_INITIALIZE(outdoorInterpWeight);
    PARAMETER_INITIALIZE(AHLightInterpWeightCount);
    PARAMETER_INITIALIZE(AHLightInterpWeightID);
    PARAMETER_INITIALIZE(AHLightInterpWeight);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixSAAGWV2TypeClass::chromatixSAAGWV2TypeClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(moduleID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(enableFlag);
    PARAMETER_INITIALIZE(outdoorWeightCtrl);
    PARAMETER_INITIALIZE(AHLightWeightCtrl);
    PARAMETER_INITIALIZE(confidenceLevel);
    PARAMETER_INITIALIZE(outdoorInterpWeight);
    PARAMETER_INITIALIZE(AHLightInterpWeight);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixSAAGWV2TypeClass::~chromatixSAAGWV2TypeClass()
{
    UnloadchromatixSAAGWV2Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatixSAAGWV2TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "SAAGWV2")) == 0)
    {
        name = "SAAGWV2";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load modIlluWVCtrlV1CCTTriggerDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixSAAGWV2TypeClass::LoadmodIlluWVCtrlV1CCTTriggerDataType(
    ParameterFileSymbolTableEntry* entry,
    modIlluWVCtrlV1CCTTriggerDataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = awbglobalelements::awbglobalelementsClass::LoadtriggerPointType(entry, &structure->triggerPt, alignment);
    result = result && awbglobalelements::awbglobalelementsClass::LoadawbFloatDataType(entry, &structure->triggerData, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load modIlluWVCtrlV1LuxTriggerDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixSAAGWV2TypeClass::LoadmodIlluWVCtrlV1LuxTriggerDataType(
    ParameterFileSymbolTableEntry* entry,
    modIlluWVCtrlV1LuxTriggerDataType* structure,
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
            structure->triggerData = PARAMETER_NEW modIlluWVCtrlV1CCTTriggerDataType[structure->triggerDataCount];
        }
        if (!result || structure->triggerData == NULL)
        {
            structure->triggerDataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->triggerDataCount; i++)
        {
            result = LoadmodIlluWVCtrlV1CCTTriggerDataType(pointerEntry, &structure->triggerData[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load modAGWWeightDataTypeV1
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixSAAGWV2TypeClass::LoadmodAGWWeightDataTypeV1(
    ParameterFileSymbolTableEntry* entry,
    modAGWWeightDataTypeV1* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    for (UINT32 i = 0; result && i < 2; i++)
    {
        structure->triggerType[i] = (awbglobalelements::awbTriggerCtrlType)entry->ReadEnum(&result, alignment);
    }
    result = result && awbglobalelements::awbglobalelementsClass::LoadtriggerPointType(entry, &structure->triggerPt, alignment);

    // Reading Array triggerData from symbol table
    {
        result = result && entry->Read(&structure->triggerDataCount, alignment);
        structure->triggerDataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->triggerData = PARAMETER_NEW awbglobalelements::awbSAConfidenceLevel2Type[structure->triggerDataCount];
        }
        if (!result || structure->triggerData == NULL)
        {
            structure->triggerDataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->triggerDataCount; i++)
        {
            result = awbglobalelements::awbglobalelementsClass::LoadawbSAConfidenceLevel2Type(pointerEntry, &structure->triggerData[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixSAAGWV2Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixSAAGWV2TypeClass::LoadchromatixSAAGWV2Type(
    ParameterFileSymbolTableEntry* entry,
    chromatixSAAGWV2Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = awbglobalelements::awbglobalelementsClass::LoadmoduleIDType(entry, &structure->moduleID, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && entry->Read(&structure->enableFlag, alignment);

    // Reading Array outdoorWeightCtrl from symbol table
    {
        result = result && entry->Read(&structure->outdoorWeightCtrlCount, alignment);
        structure->outdoorWeightCtrlID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->outdoorWeightCtrl = PARAMETER_NEW modIlluWVCtrlV1LuxTriggerDataType[structure->outdoorWeightCtrlCount];
        }
        if (!result || structure->outdoorWeightCtrl == NULL)
        {
            structure->outdoorWeightCtrlCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->outdoorWeightCtrlCount; i++)
        {
            result = LoadmodIlluWVCtrlV1LuxTriggerDataType(pointerEntry, &structure->outdoorWeightCtrl[i], alignment);
        }
    }

    // Reading Array AHLightWeightCtrl from symbol table
    {
        result = result && entry->Read(&structure->AHLightWeightCtrlCount, alignment);
        structure->AHLightWeightCtrlID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->AHLightWeightCtrl = PARAMETER_NEW modIlluWVCtrlV1LuxTriggerDataType[structure->AHLightWeightCtrlCount];
        }
        if (!result || structure->AHLightWeightCtrl == NULL)
        {
            structure->AHLightWeightCtrlCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->AHLightWeightCtrlCount; i++)
        {
            result = LoadmodIlluWVCtrlV1LuxTriggerDataType(pointerEntry, &structure->AHLightWeightCtrl[i], alignment);
        }
    }

    // Reading Array confidenceLevel from symbol table
    {
        result = result && entry->Read(&structure->confidenceLevelCount, alignment);
        structure->confidenceLevelID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->confidenceLevel = PARAMETER_NEW awbglobalelements::awbSAConfidenceDataType[structure->confidenceLevelCount];
        }
        if (!result || structure->confidenceLevel == NULL)
        {
            structure->confidenceLevelCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->confidenceLevelCount; i++)
        {
            result = awbglobalelements::awbglobalelementsClass::LoadawbSAConfidenceDataType(pointerEntry, &structure->confidenceLevel[i], alignment);
        }
    }

    // Reading Array outdoorInterpWeight from symbol table
    {
        result = result && entry->Read(&structure->outdoorInterpWeightCount, alignment);
        structure->outdoorInterpWeightID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->outdoorInterpWeight = PARAMETER_NEW modAGWWeightDataTypeV1[structure->outdoorInterpWeightCount];
        }
        if (!result || structure->outdoorInterpWeight == NULL)
        {
            structure->outdoorInterpWeightCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->outdoorInterpWeightCount; i++)
        {
            result = LoadmodAGWWeightDataTypeV1(pointerEntry, &structure->outdoorInterpWeight[i], alignment);
        }
    }

    // Reading Array AHLightInterpWeight from symbol table
    {
        result = result && entry->Read(&structure->AHLightInterpWeightCount, alignment);
        structure->AHLightInterpWeightID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->AHLightInterpWeight = PARAMETER_NEW modAGWWeightDataTypeV1[structure->AHLightInterpWeightCount];
        }
        if (!result || structure->AHLightInterpWeight == NULL)
        {
            structure->AHLightInterpWeightCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->AHLightInterpWeightCount; i++)
        {
            result = LoadmodAGWWeightDataTypeV1(pointerEntry, &structure->AHLightInterpWeight[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixSAAGWV2TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatixSAAGWV2Type::module_versionStruct* structure,
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
BOOL chromatixSAAGWV2TypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatixSAAGWV2Type::parameter_versionStruct* structure,
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
/// Unload modIlluWVCtrlV1LuxTriggerDataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatixSAAGWV2TypeClass::UnloadmodIlluWVCtrlV1LuxTriggerDataType(
    modIlluWVCtrlV1LuxTriggerDataType* structure)
{
    PARAMETER_DELETE[] structure->triggerData;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload modAGWWeightDataTypeV1
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatixSAAGWV2TypeClass::UnloadmodAGWWeightDataTypeV1(
    modAGWWeightDataTypeV1* structure)
{
    for (UINT32 i = 0; i < structure->triggerDataCount; i++)
    {
        awbglobalelements::awbglobalelementsClass::UnloadawbSAConfidenceLevel2Type(&structure->triggerData[i]);
    }
    PARAMETER_DELETE[] structure->triggerData;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatixSAAGWV2Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatixSAAGWV2TypeClass::UnloadchromatixSAAGWV2Type(
    chromatixSAAGWV2Type* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    for (UINT32 i = 0; i < structure->outdoorWeightCtrlCount; i++)
    {
        UnloadmodIlluWVCtrlV1LuxTriggerDataType(&structure->outdoorWeightCtrl[i]);
    }
    PARAMETER_DELETE[] structure->outdoorWeightCtrl;
    for (UINT32 i = 0; i < structure->AHLightWeightCtrlCount; i++)
    {
        UnloadmodIlluWVCtrlV1LuxTriggerDataType(&structure->AHLightWeightCtrl[i]);
    }
    PARAMETER_DELETE[] structure->AHLightWeightCtrl;
    for (UINT32 i = 0; i < structure->confidenceLevelCount; i++)
    {
        awbglobalelements::awbglobalelementsClass::UnloadawbSAConfidenceDataType(&structure->confidenceLevel[i]);
    }
    PARAMETER_DELETE[] structure->confidenceLevel;
    for (UINT32 i = 0; i < structure->outdoorInterpWeightCount; i++)
    {
        UnloadmodAGWWeightDataTypeV1(&structure->outdoorInterpWeight[i]);
    }
    PARAMETER_DELETE[] structure->outdoorInterpWeight;
    for (UINT32 i = 0; i < structure->AHLightInterpWeightCount; i++)
    {
        UnloadmodAGWWeightDataTypeV1(&structure->AHLightInterpWeight[i]);
    }
    PARAMETER_DELETE[] structure->AHLightInterpWeight;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatixSAAGWV2TypeClass::Unloadparameter_versionStruct(
    chromatixSAAGWV2Type::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatixSAAGWV2TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatixSAAGWV2TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatixSAAGWV2TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && LoadchromatixSAAGWV2Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


MODSAAGWV2_NAMESPACE_END
