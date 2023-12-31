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
/// @file  imagesensormodulesetmanager.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include "imagesensormodulesetmanager.h"

ImageSensorModuleSetManager::ImageSensorModuleSetManager()
{
    UINT32 index = 0;
    m_defaultModules[index++] = (const ParameterModule*)PARAMETER_NEW CamX::CameraModuleDataClass("cameraModuleData");
    m_defaultModules[index++] = (const ParameterModule*)PARAMETER_NEW CamX::ActuatorDriverDataClass("actuatorDriver");
    m_defaultModules[index++] = (const ParameterModule*)PARAMETER_NEW CamX::ActuatorDriverDataClass("actuatorDriver1");
    m_defaultModules[index++] = (const ParameterModule*)PARAMETER_NEW CamX::PDAFConfigurationDataClass("PDConfigData");
    m_defaultModules[index++] = (const ParameterModule*)PARAMETER_NEW CamX::EEPROMDriverDataClass("EEPROMDriverData");
    m_defaultModules[index++] = (const ParameterModule*)PARAMETER_NEW CamX::FlashDriverDataClass("flashDriverData");
    m_defaultModules[index++] = (const ParameterModule*)PARAMETER_NEW CamX::EEbinDriverClass("EEbinDriver");
    m_defaultModules[index++] = (const ParameterModule*)PARAMETER_NEW CamX::SensorDriverDataClass("sensorDriverData");
    m_defaultModules[index++] = (const ParameterModule*)PARAMETER_NEW CamX::OISDriverDataClass("OISDriver");

    for (UINT32 i = 0; i < index; i++)
    {
        m_moduleMap[m_defaultModules[i]->Type] = (void*)m_defaultModules[i];
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// UpdateBinaryParameters
///
/// @brief Replaces exising parameters with the ones in a buffer. LoadBinaryParameters must be called first
///
/// @param buffer   Binary parameter buffer
/// @param length   Length of the binary parameter buffer
///
/// @return Node
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL ImageSensorModuleSetManager::UpdateBinaryParameters(
    UINT8* buffer,
    UINT64 length)
{
    BOOL result = Valid;

    if (result)
    {
        ImageSensorModuleSetManager* update = new ImageSensorModuleSetManager();

        if (update->LoadBinaryParameters(buffer, length))
        {
            UpdateParameters(update);
            PARAMETER_DELETE update;
            result = TRUE;
        }
    }

    return result;
}

CamX::CameraModuleData* ImageSensorModuleSetManager::GetModule_cameraModuleData(
    TuningMode* modeBranch,
    UINT32 modeCount)
{
    ParameterModule* pModule = GetModule((const CHAR *)"cameraModuleData",
        modeBranch, modeCount);

    return (CamX::CameraModuleData*)(CamX::CameraModuleDataClass*)pModule;
}

CamX::ActuatorDriverData* ImageSensorModuleSetManager::GetModule_actuatorDriver(
    TuningMode* modeBranch,
    UINT32 modeCount)
{
    ParameterModule* pModule = GetModule((const CHAR *)"actuatorDriver",
        modeBranch, modeCount);

    return (CamX::ActuatorDriverData*)(CamX::ActuatorDriverDataClass*)pModule;
}

CamX::ActuatorDriverData* ImageSensorModuleSetManager::GetModule_actuatorDriver1(
    TuningMode* modeBranch,
    UINT32 modeCount)
{
    ParameterModule* pModule = GetModule((const CHAR *)"actuatorDriver1",
        modeBranch, modeCount);

    return (CamX::ActuatorDriverData*)(CamX::ActuatorDriverDataClass*)pModule;
}

CamX::PDAFConfigurationData* ImageSensorModuleSetManager::GetModule_PDConfigData(
    TuningMode* modeBranch,
    UINT32 modeCount)
{
    ParameterModule* pModule = GetModule((const CHAR *)"PDConfigData",
        modeBranch, modeCount);

    return (CamX::PDAFConfigurationData*)(CamX::PDAFConfigurationDataClass*)pModule;
}

CamX::EEPROMDriverData* ImageSensorModuleSetManager::GetModule_EEPROMDriverData(
    TuningMode* modeBranch,
    UINT32 modeCount)
{
    ParameterModule* pModule = GetModule((const CHAR *)"EEPROMDriverData",
        modeBranch, modeCount);

    return (CamX::EEPROMDriverData*)(CamX::EEPROMDriverDataClass*)pModule;
}

CamX::FlashDriverData* ImageSensorModuleSetManager::GetModule_flashDriverData(
    TuningMode* modeBranch,
    UINT32 modeCount)
{
    ParameterModule* pModule = GetModule((const CHAR *)"flashDriverData",
        modeBranch, modeCount);

    return (CamX::FlashDriverData*)(CamX::FlashDriverDataClass*)pModule;
}

CamX::EEbinDriver* ImageSensorModuleSetManager::GetModule_EEbinDriver(
    TuningMode* modeBranch,
    UINT32 modeCount)
{
    ParameterModule* pModule = GetModule((const CHAR *)"EEbinDriver",
        modeBranch, modeCount);

    return (CamX::EEbinDriver*)(CamX::EEbinDriverClass*)pModule;
}

CamX::SensorDriverData* ImageSensorModuleSetManager::GetModule_sensorDriverData(
    TuningMode* modeBranch,
    UINT32 modeCount)
{
    ParameterModule* pModule = GetModule((const CHAR *)"sensorDriverData",
        modeBranch, modeCount);

    return (CamX::SensorDriverData*)(CamX::SensorDriverDataClass*)pModule;
}

CamX::OISDriverData* ImageSensorModuleSetManager::GetModule_OISDriver(
    TuningMode* modeBranch,
    UINT32 modeCount)
{
    ParameterModule* pModule = GetModule((const CHAR *)"OISDriver",
        modeBranch, modeCount);

    return (CamX::OISDriverData*)(CamX::OISDriverDataClass*)pModule;
}

