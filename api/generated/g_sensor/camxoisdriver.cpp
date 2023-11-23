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
/// @file  camxoisdriver.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "camxoisdriver.h"
#include "parametersetmanager.h"

CAMX_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
OISDriverDataClass::OISDriverDataClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(slaveInfo);
    PARAMETER_INITIALIZE(opcode);
    PARAMETER_INITIALIZE(oisinitSettings);
    PARAMETER_INITIALIZE(enableOisSettings);
    PARAMETER_INITIALIZE(disableOisSettings);
    PARAMETER_INITIALIZE(enterDownloadModeSettingsExists);
    PARAMETER_INITIALIZE(enterDownloadModeSettingsID);
    PARAMETER_INITIALIZE(enterDownloadModeSettings);
    PARAMETER_INITIALIZE(movieModeSettingsExists);
    PARAMETER_INITIALIZE(movieModeSettingsID);
    PARAMETER_INITIALIZE(movieModeSettings);
    PARAMETER_INITIALIZE(stillModeSettingsExists);
    PARAMETER_INITIALIZE(stillModeSettingsID);
    PARAMETER_INITIALIZE(stillModeSettings);
    PARAMETER_INITIALIZE(centeringOnSettingsExists);
    PARAMETER_INITIALIZE(centeringOnSettingsID);
    PARAMETER_INITIALIZE(centeringOnSettings);
    PARAMETER_INITIALIZE(centeringOffSettingsExists);
    PARAMETER_INITIALIZE(centeringOffSettingsID);
    PARAMETER_INITIALIZE(centeringOffSettings);
    PARAMETER_INITIALIZE(pantiltOnSettingsExists);
    PARAMETER_INITIALIZE(pantiltOnSettingsID);
    PARAMETER_INITIALIZE(pantiltOnSettings);
    PARAMETER_INITIALIZE(sceneOisSettingsExists);
    PARAMETER_INITIALIZE(sceneOisSettingsID);
    PARAMETER_INITIALIZE(sceneOisSettings);
    PARAMETER_INITIALIZE(sceneFilterOnSettingsExists);
    PARAMETER_INITIALIZE(sceneFilterOnSettingsID);
    PARAMETER_INITIALIZE(sceneFilterOnSettings);
    PARAMETER_INITIALIZE(sceneFilterOffSettingsExists);
    PARAMETER_INITIALIZE(sceneFilterOffSettingsID);
    PARAMETER_INITIALIZE(sceneFilterOffSettings);
    PARAMETER_INITIALIZE(sceneRangeOnSettingsExists);
    PARAMETER_INITIALIZE(sceneRangeOnSettingsID);
    PARAMETER_INITIALIZE(sceneRangeOnSettings);
    PARAMETER_INITIALIZE(sceneRangeOffSettingsExists);
    PARAMETER_INITIALIZE(sceneRangeOffSettingsID);
    PARAMETER_INITIALIZE(sceneRangeOffSettings);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
OISDriverDataClass::OISDriverDataClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(slaveInfo);
    PARAMETER_INITIALIZE(opcode);
    PARAMETER_INITIALIZE(oisinitSettings);
    PARAMETER_INITIALIZE(enableOisSettings);
    PARAMETER_INITIALIZE(disableOisSettings);
    PARAMETER_INITIALIZE(enterDownloadModeSettings);
    PARAMETER_INITIALIZE(movieModeSettings);
    PARAMETER_INITIALIZE(stillModeSettings);
    PARAMETER_INITIALIZE(centeringOnSettings);
    PARAMETER_INITIALIZE(centeringOffSettings);
    PARAMETER_INITIALIZE(pantiltOnSettings);
    PARAMETER_INITIALIZE(sceneOisSettings);
    PARAMETER_INITIALIZE(sceneFilterOnSettings);
    PARAMETER_INITIALIZE(sceneFilterOffSettings);
    PARAMETER_INITIALIZE(sceneRangeOnSettings);
    PARAMETER_INITIALIZE(sceneRangeOffSettings);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
OISDriverDataClass::~OISDriverDataClass()
{
    UnloadOISDriverData(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* OISDriverDataClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "OISDriver")) == 0)
    {
        name = "OISDriver";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load OISSlaveInfo
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL OISDriverDataClass::LoadOISSlaveInfo(
    ParameterFileSymbolTableEntry* entry,
    OISSlaveInfo* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading String OISName from symbol table
    {
        UINT32 count = 0;
        result = entry->Read(&count, alignment);
        ParameterFileSymbolTableEntry* stringPointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && stringPointerEntry != NULL;
        structure->OISName = NULL;
        result = result && stringPointerEntry->ReadString(&structure->OISName, count, alignment);
    }
    result = result && entry->Read(&structure->slaveAddress, alignment);
    structure->i2cFrequencyMode = (I2CFrequencyMode)entry->ReadEnum(&result, alignment);
    result = result && entry->Read(&structure->fwflag, alignment);
    result = result && entry->Read(&structure->oiscalib, alignment);
    result = result && camxsensorcommonClass::LoadPowerSequenceInfo(entry, &structure->powerUpSequence, alignment);
    result = result && camxsensorcommonClass::LoadPowerSequenceInfo(entry, &structure->powerDownSequence, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load OISopcode
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL OISDriverDataClass::LoadOISopcode(
    ParameterFileSymbolTableEntry* entry,
    OISopcode* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->prog, alignment);
    result = result && entry->Read(&structure->coeff, alignment);
    result = result && entry->Read(&structure->pheripheral, alignment);
    result = result && entry->Read(&structure->memory, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load OISDriverData
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL OISDriverDataClass::LoadOISDriverData(
    ParameterFileSymbolTableEntry* entry,
    OISDriverData* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && LoadOISSlaveInfo(entry, &structure->slaveInfo, alignment);
    result = result && LoadOISopcode(entry, &structure->opcode, alignment);
    result = result && camxsensorcommonClass::LoadSettingsInfo(entry, &structure->oisinitSettings, alignment);
    result = result && camxsensorcommonClass::LoadSettingsInfo(entry, &structure->enableOisSettings, alignment);
    result = result && camxsensorcommonClass::LoadSettingsInfo(entry, &structure->disableOisSettings, alignment);

    // Reading Optional parameter enterDownloadModeSettings from symbol table
    {
        result = result && entry->Read(&structure->enterDownloadModeSettingsExists, alignment);
        structure->enterDownloadModeSettingsID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->enterDownloadModeSettingsExists)
        {
            result = result && camxsensorcommonClass::LoadSettingsInfo(pointerEntry, &structure->enterDownloadModeSettings, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->enterDownloadModeSettings);
        }
    }

    // Reading Optional parameter movieModeSettings from symbol table
    {
        result = result && entry->Read(&structure->movieModeSettingsExists, alignment);
        structure->movieModeSettingsID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->movieModeSettingsExists)
        {
            result = result && camxsensorcommonClass::LoadSettingsInfo(pointerEntry, &structure->movieModeSettings, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->movieModeSettings);
        }
    }

    // Reading Optional parameter stillModeSettings from symbol table
    {
        result = result && entry->Read(&structure->stillModeSettingsExists, alignment);
        structure->stillModeSettingsID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->stillModeSettingsExists)
        {
            result = result && camxsensorcommonClass::LoadSettingsInfo(pointerEntry, &structure->stillModeSettings, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->stillModeSettings);
        }
    }

    // Reading Optional parameter centeringOnSettings from symbol table
    {
        result = result && entry->Read(&structure->centeringOnSettingsExists, alignment);
        structure->centeringOnSettingsID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->centeringOnSettingsExists)
        {
            result = result && camxsensorcommonClass::LoadSettingsInfo(pointerEntry, &structure->centeringOnSettings, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->centeringOnSettings);
        }
    }

    // Reading Optional parameter centeringOffSettings from symbol table
    {
        result = result && entry->Read(&structure->centeringOffSettingsExists, alignment);
        structure->centeringOffSettingsID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->centeringOffSettingsExists)
        {
            result = result && camxsensorcommonClass::LoadSettingsInfo(pointerEntry, &structure->centeringOffSettings, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->centeringOffSettings);
        }
    }

    // Reading Optional parameter pantiltOnSettings from symbol table
    {
        result = result && entry->Read(&structure->pantiltOnSettingsExists, alignment);
        structure->pantiltOnSettingsID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->pantiltOnSettingsExists)
        {
            result = result && camxsensorcommonClass::LoadSettingsInfo(pointerEntry, &structure->pantiltOnSettings, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->pantiltOnSettings);
        }
    }

    // Reading Optional parameter sceneOisSettings from symbol table
    {
        result = result && entry->Read(&structure->sceneOisSettingsExists, alignment);
        structure->sceneOisSettingsID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->sceneOisSettingsExists)
        {
            result = result && camxsensorcommonClass::LoadSettingsInfo(pointerEntry, &structure->sceneOisSettings, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->sceneOisSettings);
        }
    }

    // Reading Optional parameter sceneFilterOnSettings from symbol table
    {
        result = result && entry->Read(&structure->sceneFilterOnSettingsExists, alignment);
        structure->sceneFilterOnSettingsID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->sceneFilterOnSettingsExists)
        {
            result = result && camxsensorcommonClass::LoadSettingsInfo(pointerEntry, &structure->sceneFilterOnSettings, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->sceneFilterOnSettings);
        }
    }

    // Reading Optional parameter sceneFilterOffSettings from symbol table
    {
        result = result && entry->Read(&structure->sceneFilterOffSettingsExists, alignment);
        structure->sceneFilterOffSettingsID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->sceneFilterOffSettingsExists)
        {
            result = result && camxsensorcommonClass::LoadSettingsInfo(pointerEntry, &structure->sceneFilterOffSettings, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->sceneFilterOffSettings);
        }
    }

    // Reading Optional parameter sceneRangeOnSettings from symbol table
    {
        result = result && entry->Read(&structure->sceneRangeOnSettingsExists, alignment);
        structure->sceneRangeOnSettingsID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->sceneRangeOnSettingsExists)
        {
            result = result && camxsensorcommonClass::LoadSettingsInfo(pointerEntry, &structure->sceneRangeOnSettings, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->sceneRangeOnSettings);
        }
    }

    // Reading Optional parameter sceneRangeOffSettings from symbol table
    {
        result = result && entry->Read(&structure->sceneRangeOffSettingsExists, alignment);
        structure->sceneRangeOffSettingsID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->sceneRangeOffSettingsExists)
        {
            result = result && camxsensorcommonClass::LoadSettingsInfo(pointerEntry, &structure->sceneRangeOffSettings, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->sceneRangeOffSettings);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL OISDriverDataClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    OISDriverData::module_versionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->major_revision, alignment);
    result = result && entry->Read(&structure->minor_revision, alignment);
    result = result && entry->Read(&structure->incr_revision, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload OISSlaveInfo
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OISDriverDataClass::UnloadOISSlaveInfo(
    OISSlaveInfo* structure)
{
    PARAMETER_DELETE[] structure->OISName;
    camxsensorcommonClass::UnloadPowerSequenceInfo(&structure->powerUpSequence);
    camxsensorcommonClass::UnloadPowerSequenceInfo(&structure->powerDownSequence);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload OISDriverData
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OISDriverDataClass::UnloadOISDriverData(
    OISDriverData* structure)
{
    UnloadOISSlaveInfo(&structure->slaveInfo);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->oisinitSettings);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->enableOisSettings);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->disableOisSettings);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->enterDownloadModeSettings);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->movieModeSettings);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->stillModeSettings);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->centeringOnSettings);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->centeringOffSettings);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->pantiltOnSettings);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->sceneOisSettings);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->sceneFilterOnSettings);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->sceneFilterOffSettings);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->sceneRangeOnSettings);
    camxsensorcommonClass::UnloadSettingsInfo(&structure->sceneRangeOffSettings);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* OISDriverDataClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    OISDriverDataClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW OISDriverDataClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && LoadOISDriverData(entry, cls, alignment);

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
