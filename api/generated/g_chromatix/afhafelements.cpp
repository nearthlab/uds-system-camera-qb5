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
/// @file  afhafelements.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "afhafelements.h"
#include "parametersetmanager.h"

AFHAFELEMENTS_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixHAFTypeClass::chromatixHAFTypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(enable_section);
    PARAMETER_INITIALIZE(defaultROISize);
    PARAMETER_INITIALIZE(ROIGridSetting);
    PARAMETER_INITIALIZE(statsConsumeEnableCount);
    PARAMETER_INITIALIZE(statsConsumeEnableID);
    PARAMETER_INITIALIZE(statsConsumeEnable);
    PARAMETER_INITIALIZE(statsSelect);
    PARAMETER_INITIALIZE(fineSearchDropThreshold);
    PARAMETER_INITIALIZE(fineStepSize);
    PARAMETER_INITIALIZE(maxMoveStep);
    PARAMETER_INITIALIZE(maxMoveStepBuffer);
    PARAMETER_INITIALIZE(baseFrameDelay);
    PARAMETER_INITIALIZE(AFFineSearchExtension);
    PARAMETER_INITIALIZE(sceneChangeDuringFS);
    PARAMETER_INITIALIZE(faceCAFHighPriorityEnable);
    PARAMETER_INITIALIZE(enableInitialPosition);
    PARAMETER_INITIALIZE(initialLensIdx);
    PARAMETER_INITIALIZE(depthConfidenceCountThreshold);
    PARAMETER_INITIALIZE(HAFROISettings);
    PARAMETER_INITIALIZE(HAFFollowerSettings);
    PARAMETER_INITIALIZE(macroRegionThresholdInMM);
    PARAMETER_INITIALIZE(farRegionThresholdinMM);
    PARAMETER_INITIALIZE(fineStartMoveBuffer);
    PARAMETER_INITIALIZE(DOFMultiplier);
    PARAMETER_INITIALIZE(enableForceScanEnd);
    PARAMETER_INITIALIZE(enablePassiveScanTimeout);
    PARAMETER_INITIALIZE(enableZeroTouchLag);
    PARAMETER_INITIALIZE(maxScanCountThreshold);
    PARAMETER_INITIALIZE(gyroSettings);
    PARAMETER_INITIALIZE(enableDynamicAnchorPoints);
    PARAMETER_INITIALIZE(anchorPosition1);
    PARAMETER_INITIALIZE(anchorPosition2);
    PARAMETER_INITIALIZE(minimumFocusIndex);
    PARAMETER_INITIALIZE(HJNormalizedWeightType);
    PARAMETER_INITIALIZE(CAFHJNormalizedWeightType);
    PARAMETER_INITIALIZE(AFControlAECInfoEnable);
    PARAMETER_INITIALIZE(AFControlAECInfoFPS);
    PARAMETER_INITIALIZE(spd_stats_type);
    PARAMETER_INITIALIZE(spd_bg_stats_thresh_auto_convert_enable);
    PARAMETER_INITIALIZE(enableParallelSearch);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixHAFTypeClass::chromatixHAFTypeClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(enable_section);
    PARAMETER_INITIALIZE(defaultROISize);
    PARAMETER_INITIALIZE(ROIGridSetting);
    PARAMETER_INITIALIZE(statsConsumeEnable);
    PARAMETER_INITIALIZE(statsSelect);
    PARAMETER_INITIALIZE(fineSearchDropThreshold);
    PARAMETER_INITIALIZE(fineStepSize);
    PARAMETER_INITIALIZE(maxMoveStep);
    PARAMETER_INITIALIZE(maxMoveStepBuffer);
    PARAMETER_INITIALIZE(baseFrameDelay);
    PARAMETER_INITIALIZE(AFFineSearchExtension);
    PARAMETER_INITIALIZE(sceneChangeDuringFS);
    PARAMETER_INITIALIZE(faceCAFHighPriorityEnable);
    PARAMETER_INITIALIZE(enableInitialPosition);
    PARAMETER_INITIALIZE(initialLensIdx);
    PARAMETER_INITIALIZE(depthConfidenceCountThreshold);
    PARAMETER_INITIALIZE(HAFROISettings);
    PARAMETER_INITIALIZE(HAFFollowerSettings);
    PARAMETER_INITIALIZE(macroRegionThresholdInMM);
    PARAMETER_INITIALIZE(farRegionThresholdinMM);
    PARAMETER_INITIALIZE(fineStartMoveBuffer);
    PARAMETER_INITIALIZE(DOFMultiplier);
    PARAMETER_INITIALIZE(enableForceScanEnd);
    PARAMETER_INITIALIZE(enablePassiveScanTimeout);
    PARAMETER_INITIALIZE(enableZeroTouchLag);
    PARAMETER_INITIALIZE(maxScanCountThreshold);
    PARAMETER_INITIALIZE(gyroSettings);
    PARAMETER_INITIALIZE(enableDynamicAnchorPoints);
    PARAMETER_INITIALIZE(anchorPosition1);
    PARAMETER_INITIALIZE(anchorPosition2);
    PARAMETER_INITIALIZE(minimumFocusIndex);
    PARAMETER_INITIALIZE(HJNormalizedWeightType);
    PARAMETER_INITIALIZE(CAFHJNormalizedWeightType);
    PARAMETER_INITIALIZE(AFControlAECInfoEnable);
    PARAMETER_INITIALIZE(AFControlAECInfoFPS);
    PARAMETER_INITIALIZE(spd_stats_type);
    PARAMETER_INITIALIZE(spd_bg_stats_thresh_auto_convert_enable);
    PARAMETER_INITIALIZE(enableParallelSearch);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatixHAFTypeClass::~chromatixHAFTypeClass()
{
    UnloadchromatixHAFType(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatixHAFTypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "chromatixHAF")) == 0)
    {
        name = "chromatixHAF";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixHAFGyroSettingsType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixHAFTypeClass::LoadchromatixHAFGyroSettingsType(
    ParameterFileSymbolTableEntry* entry,
    chromatixHAFGyroSettingsType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->enableGyroSamplingRateAdjustment, alignment);
    result = result && entry->Read(&structure->gyroSamplingRateMonitor, alignment);
    result = result && entry->Read(&structure->gyroSamplingRateSearching, alignment);
    result = result && entry->Read(&structure->gyroSamplingRateSearchingHJ, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixAFFollowerStepType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixHAFTypeClass::LoadchromatixAFFollowerStepType(
    ParameterFileSymbolTableEntry* entry,
    chromatixAFFollowerStepType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->stepSize, alignment);
    result = result && entry->Read(&structure->numFarSteps, alignment);
    result = result && entry->Read(&structure->numNearSteps, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixSearchInfoType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixHAFTypeClass::LoadchromatixSearchInfoType(
    ParameterFileSymbolTableEntry* entry,
    chromatixSearchInfoType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = LoadchromatixAFFollowerStepType(entry, &structure->AFFollowerMacroRange, alignment);
    result = result && LoadchromatixAFFollowerStepType(entry, &structure->AFFollowerMidRange, alignment);
    result = result && LoadchromatixAFFollowerStepType(entry, &structure->AFFollowerFarRange, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixFollowerFineSearchInfoType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixHAFTypeClass::LoadchromatixFollowerFineSearchInfoType(
    ParameterFileSymbolTableEntry* entry,
    chromatixFollowerFineSearchInfoType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = LoadchromatixSearchInfoType(entry, &structure->normalLightFineSearchInfo, alignment);
    result = result && LoadchromatixSearchInfoType(entry, &structure->lowLightFineSearchInfo, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixHAFFollowerSettingsType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixHAFTypeClass::LoadchromatixHAFFollowerSettingsType(
    ParameterFileSymbolTableEntry* entry,
    chromatixHAFFollowerSettingsType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->enableFollower, alignment);
    result = result && LoadchromatixFollowerFineSearchInfoType(entry, &structure->AFFollowerFineSearchSettings, alignment);
    result = result && entry->Read(&structure->enableGravityCompensationForFollower, alignment);
    result = result && entry->Read(&structure->jumpToStartLimitForFollower, alignment);
    result = result && entry->Read(&structure->lowLightThresholdForFollower, alignment);
    result = result && entry->Read(&structure->useFineSearchExtensionForFollower, alignment);
    result = result && entry->Read(&structure->activeConvergenceFollowForFollower, alignment);
    result = result && entry->Read(&structure->lensPosThresholdForActiveConvergenceFollow, alignment);
    result = result && entry->Read(&structure->searchStrategy, alignment);
    result = result && entry->Read(&structure->lensMappingStrategy, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixHAFROISettingsType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixHAFTypeClass::LoadchromatixHAFROISettingsType(
    ParameterFileSymbolTableEntry* entry,
    chromatixHAFROISettingsType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->HAFROIEnable, alignment);
    result = result && entry->Read(&structure->HAFROIHNum, alignment);
    result = result && entry->Read(&structure->HAFROIVNum, alignment);
    result = result && entry->Read(&structure->HAFCenterROISize, alignment);
    result = result && entry->Read(&structure->HAFCornerROISize, alignment);
    result = result && entry->Read(&structure->HAFROIDelay, alignment);
    result = result && entry->Read(&structure->enableROIShifting, alignment);
    result = result && entry->Read(&structure->ROIShiftType, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixAFFineSearchExtensionType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixHAFTypeClass::LoadchromatixAFFineSearchExtensionType(
    ParameterFileSymbolTableEntry* entry,
    chromatixAFFineSearchExtensionType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->enable, alignment);
    result = result && entry->Read(&structure->maximumFineSearchExtensionCount, alignment);
    result = result && entry->Read(&structure->numNearSteps, alignment);
    result = result && entry->Read(&structure->numFarSteps, alignment);
    result = result && entry->Read(&structure->stepSize, alignment);
    result = result && entry->Read(&structure->decreaseDropRatio, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatixHAFType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixHAFTypeClass::LoadchromatixHAFType(
    ParameterFileSymbolTableEntry* entry,
    chromatixHAFType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && Loadenable_sectionStruct(entry, &structure->enable_section, alignment);
    result = result && LoaddefaultROISizeStruct(entry, &structure->defaultROISize, alignment);
    result = result && LoadROIGridSettingStruct(entry, &structure->ROIGridSetting, alignment);

    // Reading Array statsConsumeEnable from symbol table
    {
        result = result && entry->Read(&structure->statsConsumeEnableCount, alignment);
        structure->statsConsumeEnableID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->statsConsumeEnable = pointerEntry->ReadArray<UINT32>(structure->statsConsumeEnableCount, alignment);
            result = structure->statsConsumeEnable != NULL;
        }
        if (!result || structure->statsConsumeEnable == NULL)
        {
            structure->statsConsumeEnableCount = 0;
        }
    }
    structure->statsSelect = (chromatixAFFocusValueStatsType)entry->ReadEnum(&result, alignment);
    result = result && entry->Read(&structure->fineSearchDropThreshold, alignment);
    result = result && entry->Read(&structure->fineStepSize, alignment);
    result = result && entry->Read(&structure->maxMoveStep, alignment);
    result = result && entry->Read(&structure->maxMoveStepBuffer, alignment);
    result = result && entry->Read(&structure->baseFrameDelay, alignment);
    result = result && LoadchromatixAFFineSearchExtensionType(entry, &structure->AFFineSearchExtension, alignment);
    result = result && entry->Read(&structure->sceneChangeDuringFS, alignment);
    result = result && entry->Read(&structure->faceCAFHighPriorityEnable, alignment);
    result = result && entry->Read(&structure->enableInitialPosition, alignment);
    result = result && entry->Read(&structure->initialLensIdx, alignment);
    result = result && entry->Read(&structure->depthConfidenceCountThreshold, alignment);
    result = result && LoadchromatixHAFROISettingsType(entry, &structure->HAFROISettings, alignment);
    result = result && LoadchromatixHAFFollowerSettingsType(entry, &structure->HAFFollowerSettings, alignment);
    result = result && entry->Read(&structure->macroRegionThresholdInMM, alignment);
    result = result && entry->Read(&structure->farRegionThresholdinMM, alignment);
    result = result && entry->Read(&structure->fineStartMoveBuffer, alignment);
    result = result && entry->Read(&structure->DOFMultiplier, alignment);
    result = result && entry->Read(&structure->enableForceScanEnd, alignment);
    result = result && entry->Read(&structure->enablePassiveScanTimeout, alignment);
    result = result && entry->Read(&structure->enableZeroTouchLag, alignment);
    result = result && entry->Read(&structure->maxScanCountThreshold, alignment);
    result = result && LoadchromatixHAFGyroSettingsType(entry, &structure->gyroSettings, alignment);
    result = result && entry->Read(&structure->enableDynamicAnchorPoints, alignment);
    result = result && entry->Read(&structure->anchorPosition1, alignment);
    result = result && entry->Read(&structure->anchorPosition2, alignment);
    result = result && entry->Read(&structure->minimumFocusIndex, alignment);
    result = result && entry->Read(&structure->HJNormalizedWeightType, alignment);
    result = result && entry->Read(&structure->CAFHJNormalizedWeightType, alignment);
    result = result && entry->Read(&structure->AFControlAECInfoEnable, alignment);
    result = result && entry->Read(&structure->AFControlAECInfoFPS, alignment);
    result = result && entry->Read(&structure->spd_stats_type, alignment);
    result = result && entry->Read(&structure->spd_bg_stats_thresh_auto_convert_enable, alignment);
    result = result && entry->Read(&structure->enableParallelSearch, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixHAFTypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatixHAFType::module_versionStruct* structure,
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
BOOL chromatixHAFTypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatixHAFType::parameter_versionStruct* structure,
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
/// Load enable_sectionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixHAFTypeClass::Loadenable_sectionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatixHAFType::enable_sectionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->CAFEnable, alignment);
    result = result && entry->Read(&structure->PDAFEnable, alignment);
    result = result && entry->Read(&structure->TOFEnable, alignment);
    result = result && entry->Read(&structure->DCIAFEnable, alignment);
    result = result && entry->Read(&structure->DepthAFEnable, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load defaultROISizeStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixHAFTypeClass::LoaddefaultROISizeStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatixHAFType::defaultROISizeStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->width, alignment);
    result = result && entry->Read(&structure->height, alignment);
    result = result && entry->Read(&structure->lowlightScalerRatio, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ROIGridSettingStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatixHAFTypeClass::LoadROIGridSettingStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatixHAFType::ROIGridSettingStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->gridRatioH, alignment);
    result = result && entry->Read(&structure->gridRatioV, alignment);
    result = result && entry->Read(&structure->gridGapRatioH, alignment);
    result = result && entry->Read(&structure->gridGapRatioV, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatixHAFType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatixHAFTypeClass::UnloadchromatixHAFType(
    chromatixHAFType* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    PARAMETER_DELETE[] structure->statsConsumeEnable;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatixHAFTypeClass::Unloadparameter_versionStruct(
    chromatixHAFType::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatixHAFTypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatixHAFTypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatixHAFTypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && LoadchromatixHAFType(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


AFHAFELEMENTS_NAMESPACE_END
