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
/// @file  camxsensorcommon.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "camxsensorcommon.h"
#include "parametersetmanager.h"

CAMX_NAMESPACE_BEGIN


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load RegisterSetting
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL camxsensorcommonClass::LoadRegisterSetting(
    ParameterFileSymbolTableEntry* entry,
    RegisterSetting* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Optional parameter slaveAddr from symbol table
    {
        result = entry->Read(&structure->slaveAddrExists, alignment);
        structure->slaveAddrID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->slaveAddrExists)
        {
            result = pointerEntry->Read(&structure->slaveAddr, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->slaveAddr);
        }
    }
    result = result && entry->Read(&structure->registerAddr, alignment);

    // Reading Array registerData from symbol table
    {
        result = result && entry->Read(&structure->registerDataCount, alignment);
        structure->registerDataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->registerData = pointerEntry->ReadArray<UINT32>(structure->registerDataCount, alignment);
            result = structure->registerData != NULL;
        }
        if (!result || structure->registerData == NULL)
        {
            structure->registerDataCount = 0;
        }
    }
    result = result && entry->Read(&structure->regAddrType, alignment);
    result = result && entry->Read(&structure->regDataType, alignment);
    structure->operation = (OperationType)entry->ReadEnum(&result, alignment);

    // Reading Optional parameter delayUs from symbol table
    {
        result = result && entry->Read(&structure->delayUsExists, alignment);
        structure->delayUsID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->delayUsExists)
        {
            result = result && pointerEntry->Read(&structure->delayUs, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->delayUs);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load SettingsInfo
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL camxsensorcommonClass::LoadSettingsInfo(
    ParameterFileSymbolTableEntry* entry,
    SettingsInfo* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array regSetting from symbol table
    {
        result = entry->Read(&structure->regSettingCount, alignment);
        structure->regSettingID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->regSetting = PARAMETER_NEW RegisterSetting[structure->regSettingCount];
        }
        if (!result || structure->regSetting == NULL)
        {
            structure->regSettingCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->regSettingCount; i++)
        {
            result = LoadRegisterSetting(pointerEntry, &structure->regSetting[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load PowerSetting
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL camxsensorcommonClass::LoadPowerSetting(
    ParameterFileSymbolTableEntry* entry,
    PowerSetting* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    structure->configType = (PowerConfigurationType)entry->ReadEnum(&result, alignment);
    result = result && entry->Read(&structure->configValue, alignment);
    result = result && entry->Read(&structure->delayMs, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load PowerSequenceInfo
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL camxsensorcommonClass::LoadPowerSequenceInfo(
    ParameterFileSymbolTableEntry* entry,
    PowerSequenceInfo* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array powerSetting from symbol table
    {
        result = entry->Read(&structure->powerSettingCount, alignment);
        structure->powerSettingID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->powerSetting = PARAMETER_NEW PowerSetting[structure->powerSettingCount];
        }
        if (!result || structure->powerSetting == NULL)
        {
            structure->powerSettingCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->powerSettingCount; i++)
        {
            result = LoadPowerSetting(pointerEntry, &structure->powerSetting[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load FrameDimension
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL camxsensorcommonClass::LoadFrameDimension(
    ParameterFileSymbolTableEntry* entry,
    FrameDimension* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->xStart, alignment);
    result = result && entry->Read(&structure->yStart, alignment);
    result = result && entry->Read(&structure->width, alignment);
    result = result && entry->Read(&structure->height, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load Dimension
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL camxsensorcommonClass::LoadDimension(
    ParameterFileSymbolTableEntry* entry,
    Dimension* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->width, alignment);
    result = result && entry->Read(&structure->height, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load Position
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL camxsensorcommonClass::LoadPosition(
    ParameterFileSymbolTableEntry* entry,
    Position* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->x, alignment);
    result = result && entry->Read(&structure->y, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload RegisterSetting
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void camxsensorcommonClass::UnloadRegisterSetting(
    RegisterSetting* structure)
{
    PARAMETER_DELETE[] structure->registerData;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload SettingsInfo
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void camxsensorcommonClass::UnloadSettingsInfo(
    SettingsInfo* structure)
{
    for (UINT32 i = 0; i < structure->regSettingCount; i++)
    {
        UnloadRegisterSetting(&structure->regSetting[i]);
    }
    PARAMETER_DELETE[] structure->regSetting;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload PowerSequenceInfo
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void camxsensorcommonClass::UnloadPowerSequenceInfo(
    PowerSequenceInfo* structure)
{
    PARAMETER_DELETE[] structure->powerSetting;
}

CAMX_NAMESPACE_END
