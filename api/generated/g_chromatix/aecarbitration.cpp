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
/// @file  aecarbitration.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "aecarbitration.h"
#include "parametersetmanager.h"

AECARBITRATION_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AECCoreArbitrationTypeClass::AECCoreArbitrationTypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(expTablesCount);
    PARAMETER_INITIALIZE(expTablesID);
    PARAMETER_INITIALIZE(expTables);
    PARAMETER_INITIALIZE(minPreviewVertBlankTime);
    PARAMETER_INITIALIZE(enableEVExpTableAdj);
    PARAMETER_INITIALIZE(enableEVGainCapping);
    PARAMETER_INITIALIZE(maxEVCappingGain);
    PARAMETER_INITIALIZE(ISOData);
    PARAMETER_INITIALIZE(antibandingVsFPSMethod);
    PARAMETER_INITIALIZE(enablePreviewManualISO);
    PARAMETER_INITIALIZE(enablePreviewManualExpTime);
    PARAMETER_INITIALIZE(enablePreviewManualFull);
    PARAMETER_INITIALIZE(disableBandingGainCapping);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AECCoreArbitrationTypeClass::AECCoreArbitrationTypeClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(expTables);
    PARAMETER_INITIALIZE(minPreviewVertBlankTime);
    PARAMETER_INITIALIZE(enableEVExpTableAdj);
    PARAMETER_INITIALIZE(enableEVGainCapping);
    PARAMETER_INITIALIZE(maxEVCappingGain);
    PARAMETER_INITIALIZE(ISOData);
    PARAMETER_INITIALIZE(antibandingVsFPSMethod);
    PARAMETER_INITIALIZE(enablePreviewManualISO);
    PARAMETER_INITIALIZE(enablePreviewManualExpTime);
    PARAMETER_INITIALIZE(enablePreviewManualFull);
    PARAMETER_INITIALIZE(disableBandingGainCapping);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AECCoreArbitrationTypeClass::~AECCoreArbitrationTypeClass()
{
    UnloadAECCoreArbitrationType(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* AECCoreArbitrationTypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "Arbitration")) == 0)
    {
        name = "Arbitration";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ISOSettingType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECCoreArbitrationTypeClass::LoadISOSettingType(
    ParameterFileSymbolTableEntry* entry,
    ISOSettingType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->previewISO100Gain, alignment);
    result = result && entry->Read(&structure->enableAntiBandingVsISOPrio, alignment);
    result = result && entry->Read(&structure->enableISOQuantization, alignment);

    // Reading Array thresQuantizationISOValue from symbol table
    {
        result = result && entry->Read(&structure->thresQuantizationISOValueCount, alignment);
        structure->thresQuantizationISOValueID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->thresQuantizationISOValue = pointerEntry->ReadArray<FLOAT>(structure->thresQuantizationISOValueCount, alignment);
            result = structure->thresQuantizationISOValue != NULL;
        }
        if (!result || structure->thresQuantizationISOValue == NULL)
        {
            structure->thresQuantizationISOValueCount = 0;
        }
    }

    // Reading Array quantizedISOValue from symbol table
    {
        result = result && entry->Read(&structure->quantizedISOValueCount, alignment);
        structure->quantizedISOValueID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->quantizedISOValue = pointerEntry->ReadArray<FLOAT>(structure->quantizedISOValueCount, alignment);
            result = structure->quantizedISOValue != NULL;
        }
        if (!result || structure->quantizedISOValue == NULL)
        {
            structure->quantizedISOValueCount = 0;
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ExposureKneeType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECCoreArbitrationTypeClass::LoadExposureKneeType(
    ParameterFileSymbolTableEntry* entry,
    ExposureKneeType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->gain, alignment);
    result = result && entry->Read(&structure->expTime, alignment);
    structure->incrementPriority = (aecglobalelements::AECExpIncPrioType)entry->ReadEnum(&result, alignment);
    result = result && entry->Read(&structure->expIndex, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ExposureTableType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECCoreArbitrationTypeClass::LoadExposureTableType(
    ParameterFileSymbolTableEntry* entry,
    ExposureTableType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->sensitivityCorrectionFactor, alignment);

    // Reading Array expKneeEntries from symbol table
    {
        result = result && entry->Read(&structure->expKneeEntriesCount, alignment);
        structure->expKneeEntriesID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->expKneeEntries = PARAMETER_NEW ExposureKneeType[structure->expKneeEntriesCount];
        }
        if (!result || structure->expKneeEntries == NULL)
        {
            structure->expKneeEntriesCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->expKneeEntriesCount; i++)
        {
            result = LoadExposureKneeType(pointerEntry, &structure->expKneeEntries[i], alignment);
        }
    }
    result = result && entry->Read(&structure->thresAntiBandingMinExpTimePct, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load AECCoreArbitrationType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECCoreArbitrationTypeClass::LoadAECCoreArbitrationType(
    ParameterFileSymbolTableEntry* entry,
    AECCoreArbitrationType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);

    // Reading Array expTables from symbol table
    {
        result = result && entry->Read(&structure->expTablesCount, alignment);
        structure->expTablesID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->expTables = PARAMETER_NEW ExposureTableType[structure->expTablesCount];
        }
        if (!result || structure->expTables == NULL)
        {
            structure->expTablesCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->expTablesCount; i++)
        {
            result = LoadExposureTableType(pointerEntry, &structure->expTables[i], alignment);
        }
    }
    result = result && entry->Read(&structure->minPreviewVertBlankTime, alignment);
    result = result && entry->Read(&structure->enableEVExpTableAdj, alignment);
    result = result && entry->Read(&structure->enableEVGainCapping, alignment);
    result = result && entry->Read(&structure->maxEVCappingGain, alignment);
    result = result && LoadISOSettingType(entry, &structure->ISOData, alignment);
    structure->antibandingVsFPSMethod = (aecglobalelements::AECAntibandingVsFPSMethod)entry->ReadEnum(&result, alignment);
    result = result && entry->Read(&structure->enablePreviewManualISO, alignment);
    result = result && entry->Read(&structure->enablePreviewManualExpTime, alignment);
    result = result && entry->Read(&structure->enablePreviewManualFull, alignment);
    result = result && entry->Read(&structure->disableBandingGainCapping, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL AECCoreArbitrationTypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    AECCoreArbitrationType::module_versionStruct* structure,
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
BOOL AECCoreArbitrationTypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    AECCoreArbitrationType::parameter_versionStruct* structure,
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
/// Unload ISOSettingType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AECCoreArbitrationTypeClass::UnloadISOSettingType(
    ISOSettingType* structure)
{
    PARAMETER_DELETE[] structure->thresQuantizationISOValue;
    PARAMETER_DELETE[] structure->quantizedISOValue;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload ExposureTableType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AECCoreArbitrationTypeClass::UnloadExposureTableType(
    ExposureTableType* structure)
{
    PARAMETER_DELETE[] structure->expKneeEntries;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload AECCoreArbitrationType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AECCoreArbitrationTypeClass::UnloadAECCoreArbitrationType(
    AECCoreArbitrationType* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    for (UINT32 i = 0; i < structure->expTablesCount; i++)
    {
        UnloadExposureTableType(&structure->expTables[i]);
    }
    PARAMETER_DELETE[] structure->expTables;
    UnloadISOSettingType(&structure->ISOData);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AECCoreArbitrationTypeClass::Unloadparameter_versionStruct(
    AECCoreArbitrationType::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* AECCoreArbitrationTypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    AECCoreArbitrationTypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW AECCoreArbitrationTypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && LoadAECCoreArbitrationType(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


AECARBITRATION_NAMESPACE_END
