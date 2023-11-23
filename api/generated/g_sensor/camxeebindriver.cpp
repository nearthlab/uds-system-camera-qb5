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
/// @file  camxeebindriver.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "camxeebindriver.h"
#include "parametersetmanager.h"

CAMX_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
EEbinDriverClass::EEbinDriverClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(slaveInfo);
    PARAMETER_INITIALIZE(versionReadInfo);
    PARAMETER_INITIALIZE(versionFormatInfo);
    PARAMETER_INITIALIZE(dataReadInfo);
    PARAMETER_INITIALIZE(dataWriteInfo);
    PARAMETER_INITIALIZE(moduleInfoCount);
    PARAMETER_INITIALIZE(moduleInfoID);
    PARAMETER_INITIALIZE(moduleInfo);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
EEbinDriverClass::EEbinDriverClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(slaveInfo);
    PARAMETER_INITIALIZE(versionReadInfo);
    PARAMETER_INITIALIZE(versionFormatInfo);
    PARAMETER_INITIALIZE(dataReadInfo);
    PARAMETER_INITIALIZE(dataWriteInfo);
    PARAMETER_INITIALIZE(moduleInfo);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
EEbinDriverClass::~EEbinDriverClass()
{
    UnloadEEbinDriver(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* EEbinDriverClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "EEbinDriver")) == 0)
    {
        name = "EEbinDriver";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load EEBinSlaveInformation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL EEbinDriverClass::LoadEEBinSlaveInformation(
    ParameterFileSymbolTableEntry* entry,
    EEBinSlaveInformation* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->slaveAddress, alignment);
    structure->i2cFrequencyMode = (I2CFrequencyMode)entry->ReadEnum(&result, alignment);
    result = result && camxsensorcommonClass::LoadPowerSequenceInfo(entry, &structure->powerUpSequence, alignment);
    result = result && camxsensorcommonClass::LoadPowerSequenceInfo(entry, &structure->powerDownSequence, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load MemoryFormatInfo
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL EEbinDriverClass::LoadMemoryFormatInfo(
    ParameterFileSymbolTableEntry* entry,
    MemoryFormatInfo* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->offset, alignment);
    result = result && entry->Read(&structure->lengthInBytes, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load VersionFormatInfo
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL EEbinDriverClass::LoadVersionFormatInfo(
    ParameterFileSymbolTableEntry* entry,
    VersionFormatInfo* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = LoadMemoryFormatInfo(entry, &structure->version, alignment);
    result = result && LoadMemoryFormatInfo(entry, &structure->readStartAddress, alignment);
    result = result && LoadMemoryFormatInfo(entry, &structure->readEndAddress, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ModuleInformation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL EEbinDriverClass::LoadModuleInformation(
    ParameterFileSymbolTableEntry* entry,
    ModuleInformation* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading String HWVersion from symbol table
    {
        UINT32 count = 0;
        result = entry->Read(&count, alignment);
        ParameterFileSymbolTableEntry* stringPointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && stringPointerEntry != NULL;
        structure->HWVersion = NULL;
        result = result && stringPointerEntry->ReadString(&structure->HWVersion, count, alignment);
    }

    // Reading String SWVersion from symbol table
    {
        UINT32 count = 0;
        result = result && entry->Read(&count, alignment);
        ParameterFileSymbolTableEntry* stringPointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && stringPointerEntry != NULL;
        structure->SWVersion = NULL;
        result = result && stringPointerEntry->ReadString(&structure->SWVersion, count, alignment);
    }

    // Reading String MiscVersion from symbol table
    {
        UINT32 count = 0;
        result = result && entry->Read(&count, alignment);
        ParameterFileSymbolTableEntry* stringPointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && stringPointerEntry != NULL;
        structure->MiscVersion = NULL;
        result = result && stringPointerEntry->ReadString(&structure->MiscVersion, count, alignment);
    }

    // Reading String binaryName from symbol table
    {
        UINT32 count = 0;
        result = result && entry->Read(&count, alignment);
        ParameterFileSymbolTableEntry* stringPointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && stringPointerEntry != NULL;
        structure->binaryName = NULL;
        result = result && stringPointerEntry->ReadString(&structure->binaryName, count, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load EEbinDriver
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL EEbinDriverClass::LoadEEbinDriver(
    ParameterFileSymbolTableEntry* entry,
    EEbinDriver* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && LoadEEBinSlaveInformation(entry, &structure->slaveInfo, alignment);
    result = result && camxsensorcommonClass::LoadSettingsInfo(entry, &structure->versionReadInfo, alignment);
    result = result && LoadVersionFormatInfo(entry, &structure->versionFormatInfo, alignment);
    result = result && camxsensorcommonClass::LoadSettingsInfo(entry, &structure->dataReadInfo, alignment);
    result = result && camxsensorcommonClass::LoadSettingsInfo(entry, &structure->dataWriteInfo, alignment);

    // Reading Array moduleInfo from symbol table
    {
        result = result && entry->Read(&structure->moduleInfoCount, alignment);
        structure->moduleInfoID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->moduleInfo = PARAMETER_NEW ModuleInformation[structure->moduleInfoCount];
        }
        if (!result || structure->moduleInfo == NULL)
        {
            structure->moduleInfoCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->moduleInfoCount; i++)
        {
            result = LoadModuleInformation(pointerEntry, &structure->moduleInfo[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL EEbinDriverClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    EEbinDriver::module_versionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->major_revision, alignment);
    result = result && entry->Read(&structure->minor_revision, alignment);
    result = result && entry->Read(&structure->incr_revision, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload EEBinSlaveInformation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EEbinDriverClass::UnloadEEBinSlaveInformation(
    EEBinSlaveInformation* structure)
{
    camxsensorcommonClass::UnloadPowerSequenceInfo(&structure->powerUpSequence);
    camxsensorcommonClass::UnloadPowerSequenceInfo(&structure->powerDownSequence);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload ModuleInformation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EEbinDriverClass::UnloadModuleInformation(
    ModuleInformation* structure)
{
    PARAMETER_DELETE[] structure->HWVersion;
    PARAMETER_DELETE[] structure->SWVersion;
    PARAMETER_DELETE[] structure->MiscVersion;
    PARAMETER_DELETE[] structure->binaryName;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload EEbinDriver
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EEbinDriverClass::UnloadEEbinDriver(
    EEbinDriver* structure)
{
    UnloadEEBinSlaveInformation(&structure->slaveInfo);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->versionReadInfo);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->dataReadInfo);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->dataWriteInfo);
    for (UINT32 i = 0; i < structure->moduleInfoCount; i++)
    {
        UnloadModuleInformation(&structure->moduleInfo[i]);
    }
    PARAMETER_DELETE[] structure->moduleInfo;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* EEbinDriverClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    EEbinDriverClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW EEbinDriverClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && LoadEEbinDriver(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


CAMX_NAMESPACE_END
