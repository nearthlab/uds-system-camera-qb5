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
/// @file  modspectralsensorinfoassistawbv1.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "modspectralsensorinfoassistawbv1.h"
#include "parametersetmanager.h"

MODSPECTRALSENSORINFOASSISTAWBV1_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixSpectralSensorInfoAssistV1TypeClass::chromatixSpectralSensorInfoAssistV1TypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(moduleID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(TemporalFilterForSpectralSensorInfoCtrl);
    PARAMETER_INITIALIZE(OutdoorScenesWeightCtrl);
    PARAMETER_INITIALIZE(IndoorAHScenesWeightCtrl);
    PARAMETER_INITIALIZE(OutdoorScenesConfidenceCtrl);
    PARAMETER_INITIALIZE(IndoorAHScenesConfidenceCtrl);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixSpectralSensorInfoAssistV1TypeClass::chromatixSpectralSensorInfoAssistV1TypeClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(moduleID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(TemporalFilterForSpectralSensorInfoCtrl);
    PARAMETER_INITIALIZE(OutdoorScenesWeightCtrl);
    PARAMETER_INITIALIZE(IndoorAHScenesWeightCtrl);
    PARAMETER_INITIALIZE(OutdoorScenesConfidenceCtrl);
    PARAMETER_INITIALIZE(IndoorAHScenesConfidenceCtrl);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixSpectralSensorInfoAssistV1TypeClass::~chromatixSpectralSensorInfoAssistV1TypeClass()
{
    UnloadchromatixSpectralSensorInfoAssistV1Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatixSpectralSensorInfoAssistV1TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "SFSpectralSensorAssistV1")) == 0)
    {
        name = "SFSpectralSensorAssistV1";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load modTemporalFilterCtrlType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixSpectralSensorInfoAssistV1TypeClass::LoadmodTemporalFilterCtrlType(
    ParameterFileSymbolTableEntry* entry,
    modTemporalFilterCtrlType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->enableTempFilterForSpectralSensorInfoFlag, alignment);
    result = result && entry->Read(&structure->NormalConvSpeed, alignment);
    result = result && entry->Read(&structure->LockThreshold, alignment);
    result = result && entry->Read(&structure->LockFrameNumber, alignment);
    result = result && entry->Read(&structure->LockConvSpeed, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load modgeneralizedWVCtrlType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixSpectralSensorInfoAssistV1TypeClass::LoadmodgeneralizedWVCtrlType(
    ParameterFileSymbolTableEntry* entry,
    modgeneralizedWVCtrlType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->enableFlag, alignment);
    result = result && awbglobalelements::awbglobalelementsClass::LoadawbGWVTriggerConfigType(entry, &structure->triggerInfo, alignment);
    result = result && awbglobalelements::awbglobalelementsClass::LoadtriggerPointType(entry, &structure->triggerPt, alignment);

    // Reading Array triggerData from symbol table
    {
        result = result && entry->Read(&structure->triggerDataCount, alignment);
        structure->triggerDataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->triggerData = PARAMETER_NEW modgeneralwvv1::modGeneralWVV1Level1TriggerDataType[structure->triggerDataCount];
        }
        if (!result || structure->triggerData == NULL)
        {
            structure->triggerDataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->triggerDataCount; i++)
        {
            result = modgeneralwvv1::chromatixGeneralWVV1TypeClass::LoadmodGeneralWVV1Level1TriggerDataType(pointerEntry, &structure->triggerData[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixSpectralSensorInfoAssistV1Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixSpectralSensorInfoAssistV1TypeClass::LoadchromatixSpectralSensorInfoAssistV1Type(
    ParameterFileSymbolTableEntry* entry,
    chromatixSpectralSensorInfoAssistV1Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = awbglobalelements::awbglobalelementsClass::LoadmoduleIDType(entry, &structure->moduleID, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && LoadmodTemporalFilterCtrlType(entry, &structure->TemporalFilterForSpectralSensorInfoCtrl, alignment);
    result = result && LoadmodgeneralizedWVCtrlType(entry, &structure->OutdoorScenesWeightCtrl, alignment);
    result = result && LoadmodgeneralizedWVCtrlType(entry, &structure->IndoorAHScenesWeightCtrl, alignment);
    result = result && LoadmodgeneralizedWVCtrlType(entry, &structure->OutdoorScenesConfidenceCtrl, alignment);
    result = result && LoadmodgeneralizedWVCtrlType(entry, &structure->IndoorAHScenesConfidenceCtrl, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixSpectralSensorInfoAssistV1TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatixSpectralSensorInfoAssistV1Type::module_versionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->major_revision, alignment);
    result = result && entry->Read(&structure->minor_revision, alignment);
    result = result && entry->Read(&structure->incr_revision, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload modgeneralizedWVCtrlType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatixSpectralSensorInfoAssistV1TypeClass::UnloadmodgeneralizedWVCtrlType(
    modgeneralizedWVCtrlType* structure)
{
    for (UINT32 i = 0; i < structure->triggerDataCount; i++)
    {
        modgeneralwvv1::chromatixGeneralWVV1TypeClass::UnloadmodGeneralWVV1Level1TriggerDataType(&structure->triggerData[i]);
    }
    PARAMETER_DELETE[] structure->triggerData;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatixSpectralSensorInfoAssistV1Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatixSpectralSensorInfoAssistV1TypeClass::UnloadchromatixSpectralSensorInfoAssistV1Type(
    chromatixSpectralSensorInfoAssistV1Type* structure)
{
    UnloadmodgeneralizedWVCtrlType(&structure->OutdoorScenesWeightCtrl);
    UnloadmodgeneralizedWVCtrlType(&structure->IndoorAHScenesWeightCtrl);
    UnloadmodgeneralizedWVCtrlType(&structure->OutdoorScenesConfidenceCtrl);
    UnloadmodgeneralizedWVCtrlType(&structure->IndoorAHScenesConfidenceCtrl);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatixSpectralSensorInfoAssistV1TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatixSpectralSensorInfoAssistV1TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatixSpectralSensorInfoAssistV1TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && LoadchromatixSpectralSensorInfoAssistV1Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


MODSPECTRALSENSORINFOASSISTAWBV1_NAMESPACE_END
