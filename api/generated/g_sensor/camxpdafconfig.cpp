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
/// @file  camxpdafconfig.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "camxpdafconfig.h"
#include "parametersetmanager.h"

CAMX_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PDAFConfigurationDataClass::PDAFConfigurationDataClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(PDCommonInfo);
    PARAMETER_INITIALIZE(PDModeInfoCount);
    PARAMETER_INITIALIZE(PDModeInfoID);
    PARAMETER_INITIALIZE(PDModeInfo);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PDAFConfigurationDataClass::PDAFConfigurationDataClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(PDCommonInfo);
    PARAMETER_INITIALIZE(PDModeInfo);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PDAFConfigurationDataClass::~PDAFConfigurationDataClass()
{
    UnloadPDAFConfigurationData(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* PDAFConfigurationDataClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "PDConfigData")) == 0)
    {
        name = "PDConfigData";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load PDAFInformation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL PDAFConfigurationDataClass::LoadPDAFInformation(
    ParameterFileSymbolTableEntry* entry,
    PDAFInformation* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading String PDAFName from symbol table
    {
        UINT32 count = 0;
        result = entry->Read(&count, alignment);
        ParameterFileSymbolTableEntry* stringPointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && stringPointerEntry != NULL;
        structure->PDAFName = NULL;
        result = result && stringPointerEntry->ReadString(&structure->PDAFName, count, alignment);
    }
    structure->PDOrientation = (PDAFOrientation)entry->ReadEnum(&result, alignment);
    result = result && entry->Read(&structure->PDDefocusConfidenceThreshold, alignment);

    // Reading Optional parameter PDBlackLevel from symbol table
    {
        result = result && entry->Read(&structure->PDBlackLevelExists, alignment);
        structure->PDBlackLevelID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->PDBlackLevelExists)
        {
            result = result && pointerEntry->Read(&structure->PDBlackLevel, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->PDBlackLevel);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load PDAFPixelCoordinates
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL PDAFConfigurationDataClass::LoadPDAFPixelCoordinates(
    ParameterFileSymbolTableEntry* entry,
    PDAFPixelCoordinates* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->PDXCoordinate, alignment);
    result = result && entry->Read(&structure->PDYCoordinate, alignment);
    structure->PDPixelShieldInformation = (PDAFPixelShieldInformation)entry->ReadEnum(&result, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load PDAFBlockPattern
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL PDAFConfigurationDataClass::LoadPDAFBlockPattern(
    ParameterFileSymbolTableEntry* entry,
    PDAFBlockPattern* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->PDPixelCount, alignment);

    // Reading Array PDPixelCoordinates from symbol table
    {
        result = result && entry->Read(&structure->PDPixelCoordinatesCount, alignment);
        structure->PDPixelCoordinatesID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->PDPixelCoordinates = PARAMETER_NEW PDAFPixelCoordinates[structure->PDPixelCoordinatesCount];
        }
        if (!result || structure->PDPixelCoordinates == NULL)
        {
            structure->PDPixelCoordinatesCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->PDPixelCoordinatesCount; i++)
        {
            result = LoadPDAFPixelCoordinates(pointerEntry, &structure->PDPixelCoordinates[i], alignment);
        }
    }
    result = result && camxsensorcommonClass::LoadDimension(entry, &structure->PDBlockDimensions, alignment);
    result = result && entry->Read(&structure->PDOffsetHorizontal, alignment);
    result = result && entry->Read(&structure->PDOffsetVertical, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load PDAFSensorNativePatternInformation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL PDAFConfigurationDataClass::LoadPDAFSensorNativePatternInformation(
    ParameterFileSymbolTableEntry* entry,
    PDAFSensorNativePatternInformation* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->PDBlockCountHorizontal, alignment);
    result = result && entry->Read(&structure->PDBlockCountVertical, alignment);

    // Reading Optional parameter PDBlockPattern from symbol table
    {
        result = result && entry->Read(&structure->PDBlockPatternExists, alignment);
        structure->PDBlockPatternID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->PDBlockPatternExists)
        {
            result = result && LoadPDAFBlockPattern(pointerEntry, &structure->PDBlockPattern, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->PDBlockPattern);
        }
    }
    result = result && camxsensorcommonClass::LoadFrameDimension(entry, &structure->PDCropRegion, alignment);
    result = result && entry->Read(&structure->PDDownscaleFactorHorizontal, alignment);
    result = result && entry->Read(&structure->PDDownscaleFactorVertical, alignment);
    structure->PDNativeBufferFormat = (PDAFBufferDataFormat)entry->ReadEnum(&result, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load PDAFBlockPatternInformation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL PDAFConfigurationDataClass::LoadPDAFBlockPatternInformation(
    ParameterFileSymbolTableEntry* entry,
    PDAFBlockPatternInformation* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->PDStride, alignment);
    structure->PDBufferFormat = (PDAFBufferDataFormat)entry->ReadEnum(&result, alignment);

    // Reading Optional parameter PDBlockPattern from symbol table
    {
        result = result && entry->Read(&structure->PDBlockPatternExists, alignment);
        structure->PDBlockPatternID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->PDBlockPatternExists)
        {
            result = result && LoadPDAFBlockPattern(pointerEntry, &structure->PDBlockPattern, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->PDBlockPattern);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load PDAFModeInformation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL PDAFConfigurationDataClass::LoadPDAFModeInformation(
    ParameterFileSymbolTableEntry* entry,
    PDAFModeInformation* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Optional parameter PDSensorNativePatternInfo from symbol table
    {
        result = entry->Read(&structure->PDSensorNativePatternInfoExists, alignment);
        structure->PDSensorNativePatternInfoID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->PDSensorNativePatternInfoExists)
        {
            result = LoadPDAFSensorNativePatternInformation(pointerEntry, &structure->PDSensorNativePatternInfo, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->PDSensorNativePatternInfo);
        }
    }

    // Reading Optional parameter PDBufferBlockPatternInfo from symbol table
    {
        result = result && entry->Read(&structure->PDBufferBlockPatternInfoExists, alignment);
        structure->PDBufferBlockPatternInfoID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->PDBufferBlockPatternInfoExists)
        {
            result = result && LoadPDAFBlockPatternInformation(pointerEntry, &structure->PDBufferBlockPatternInfo, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->PDBufferBlockPatternInfo);
        }
    }
    structure->PDType = (PDAFType)entry->ReadEnum(&result, alignment);
    result = result && entry->Read(&structure->PDSensorMode, alignment);

    // Reading String PDAFLibraryName from symbol table
    {
        UINT32 count = 0;
        result = result && entry->Read(&count, alignment);
        ParameterFileSymbolTableEntry* stringPointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && stringPointerEntry != NULL;
        structure->PDAFLibraryName = NULL;
        result = result && stringPointerEntry->ReadString(&structure->PDAFLibraryName, count, alignment);
    }

    // Reading Optional parameter PDSensorPDStatsFormat from symbol table
    {
        result = result && entry->Read(&structure->PDSensorPDStatsFormatExists, alignment);
        structure->PDSensorPDStatsFormatID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->PDSensorPDStatsFormatExists)
        {
            structure->PDSensorPDStatsFormat = (SensorPDStatsFormat)pointerEntry->ReadEnum(&result, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->PDSensorPDStatsFormat);
        }
    }

    // Reading Optional parameter PDSensorOutputFormat from symbol table
    {
        result = result && entry->Read(&structure->PDSensorOutputFormatExists, alignment);
        structure->PDSensorOutputFormatID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->PDSensorOutputFormatExists)
        {
            structure->PDSensorOutputFormat = (PDAFBufferDataFormat)pointerEntry->ReadEnum(&result, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->PDSensorOutputFormat);
        }
    }

    // Reading Optional parameter lcrPDOffsetCorrection from symbol table
    {
        result = result && entry->Read(&structure->lcrPDOffsetCorrectionExists, alignment);
        structure->lcrPDOffsetCorrectionID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->lcrPDOffsetCorrectionExists)
        {
            result = result && pointerEntry->Read(&structure->lcrPDOffsetCorrection, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->lcrPDOffsetCorrection);
        }
    }

    // Reading Optional parameter PDPixelOrderType from symbol table
    {
        result = result && entry->Read(&structure->PDPixelOrderTypeExists, alignment);
        structure->PDPixelOrderTypeID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->PDPixelOrderTypeExists)
        {
            structure->PDPixelOrderType = (PDAFPixelOrderType)pointerEntry->ReadEnum(&result, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->PDPixelOrderType);
        }
    }

    // Reading Optional parameter PDOffsetCorrection from symbol table
    {
        result = result && entry->Read(&structure->PDOffsetCorrectionExists, alignment);
        structure->PDOffsetCorrectionID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result && structure->PDOffsetCorrectionExists)
        {
            result = result && pointerEntry->Read(&structure->PDOffsetCorrection, alignment);
        }
        else
        {
            PARAMETER_INITIALIZE(structure->PDOffsetCorrection);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load PDAFConfigurationData
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL PDAFConfigurationDataClass::LoadPDAFConfigurationData(
    ParameterFileSymbolTableEntry* entry,
    PDAFConfigurationData* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && LoadPDAFInformation(entry, &structure->PDCommonInfo, alignment);

    // Reading Array PDModeInfo from symbol table
    {
        result = result && entry->Read(&structure->PDModeInfoCount, alignment);
        structure->PDModeInfoID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->PDModeInfo = PARAMETER_NEW PDAFModeInformation[structure->PDModeInfoCount];
        }
        if (!result || structure->PDModeInfo == NULL)
        {
            structure->PDModeInfoCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->PDModeInfoCount; i++)
        {
            result = LoadPDAFModeInformation(pointerEntry, &structure->PDModeInfo[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL PDAFConfigurationDataClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    PDAFConfigurationData::module_versionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->major_revision, alignment);
    result = result && entry->Read(&structure->minor_revision, alignment);
    result = result && entry->Read(&structure->incr_revision, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload PDAFInformation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PDAFConfigurationDataClass::UnloadPDAFInformation(
    PDAFInformation* structure)
{
    PARAMETER_DELETE[] structure->PDAFName;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload PDAFBlockPattern
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PDAFConfigurationDataClass::UnloadPDAFBlockPattern(
    PDAFBlockPattern* structure)
{
    PARAMETER_DELETE[] structure->PDPixelCoordinates;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload PDAFSensorNativePatternInformation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PDAFConfigurationDataClass::UnloadPDAFSensorNativePatternInformation(
    PDAFSensorNativePatternInformation* structure)
{
    UnloadPDAFBlockPattern(&structure->PDBlockPattern);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload PDAFBlockPatternInformation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PDAFConfigurationDataClass::UnloadPDAFBlockPatternInformation(
    PDAFBlockPatternInformation* structure)
{
    UnloadPDAFBlockPattern(&structure->PDBlockPattern);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload PDAFModeInformation
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PDAFConfigurationDataClass::UnloadPDAFModeInformation(
    PDAFModeInformation* structure)
{
    UnloadPDAFSensorNativePatternInformation(&structure->PDSensorNativePatternInfo);
    UnloadPDAFBlockPatternInformation(&structure->PDBufferBlockPatternInfo);
    PARAMETER_DELETE[] structure->PDAFLibraryName;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload PDAFConfigurationData
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PDAFConfigurationDataClass::UnloadPDAFConfigurationData(
    PDAFConfigurationData* structure)
{
    UnloadPDAFInformation(&structure->PDCommonInfo);
    for (UINT32 i = 0; i < structure->PDModeInfoCount; i++)
    {
        UnloadPDAFModeInformation(&structure->PDModeInfo[i]);
    }
    PARAMETER_DELETE[] structure->PDModeInfo;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* PDAFConfigurationDataClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    PDAFConfigurationDataClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW PDAFConfigurationDataClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && LoadPDAFConfigurationData(entry, cls, alignment);

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
