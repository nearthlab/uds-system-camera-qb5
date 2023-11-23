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
/// @file  tmc_1_2_0.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "tmc_1_2_0.h"
#include "parametersetmanager.h"

TMC_1_2_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_tmc12TypeClass::chromatix_tmc12TypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(enable_section);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(control_variables);
    PARAMETER_INITIALIZE(control_method);
    PARAMETER_INITIALIZE(chromatix_tmc12_reserve);
    PARAMETER_INITIALIZE(chromatix_tmc12_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_tmc12TypeClass::chromatix_tmc12TypeClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(enable_section);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(control_variables);
    PARAMETER_INITIALIZE(control_method);
    PARAMETER_INITIALIZE(chromatix_tmc12_reserve);
    PARAMETER_INITIALIZE(chromatix_tmc12_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_tmc12TypeClass::~chromatix_tmc12TypeClass()
{
    Unloadchromatix_tmc12Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatix_tmc12TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "tmc12_sw")) == 0)
    {
        name = "tmc12_sw";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load tmc12_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadtmc12_rgn_dataType(
    ParameterFileSymbolTableEntry* entry,
    tmc12_rgn_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->gtm_percentage, alignment);
    result = result && entry->Read(&structure->ltm_percentage, alignment);
    result = result && entry->Read(&structure->dark_boost_ratio, alignment);
    result = result && entry->Read(&structure->dark_boost_offset, alignment);
    result = result && Loadtmc12_rgn_dataType_tone_target_tabStruct(entry, &structure->tone_target_tab, alignment);
    result = result && Loadtmc12_rgn_dataType_tone_anchors_tabStruct(entry, &structure->tone_anchors_tab, alignment);
    result = result && entry->Read(&structure->tone_bright_adj, alignment);
    result = result && entry->Read(&structure->tone_dark_adj, alignment);
    result = result && entry->Read(&structure->stretch_bright_str, alignment);
    result = result && entry->Read(&structure->stretch_dark_str, alignment);
    result = result && entry->Read(&structure->hist_supr_range_start, alignment);
    result = result && entry->Read(&structure->hist_supr_range_end, alignment);
    result = result && entry->Read(&structure->hist_boost_range_start, alignment);
    result = result && entry->Read(&structure->hist_boost_range_end, alignment);
    result = result && entry->Read(&structure->hist_avg_range_start, alignment);
    result = result && entry->Read(&structure->hist_avg_range_end, alignment);
    result = result && Loadtmc12_rgn_dataType_hist_conv_kernel_tabStruct(entry, &structure->hist_conv_kernel_tab, alignment);
    result = result && entry->Read(&structure->hist_clip_slope, alignment);
    result = result && entry->Read(&structure->hist_enhance_clamp, alignment);
    result = result && Loadtmc12_rgn_dataType_hist_enhance_ratio_tabStruct(entry, &structure->hist_enhance_ratio_tab, alignment);
    result = result && entry->Read(&structure->contrast_bright_clip, alignment);
    result = result && entry->Read(&structure->contrast_dark_adj, alignment);
    result = result && entry->Read(&structure->contrast_he_bright, alignment);
    result = result && entry->Read(&structure->contrast_he_dark, alignment);
    result = result && entry->Read(&structure->hist_smoothing_str, alignment);
    result = result && entry->Read(&structure->hist_curve_smoothing_str, alignment);
    result = result && entry->Read(&structure->scene_change_smoothing_str, alignment);
    result = result && entry->Read(&structure->scene_change_curve_smoothing_str, alignment);
    result = result && entry->Read(&structure->scene_change_hist_delta_th1, alignment);
    result = result && entry->Read(&structure->scene_change_hist_delta_th2, alignment);
    result = result && entry->Read(&structure->scene_change_lux_idx_delta_th1, alignment);
    result = result && entry->Read(&structure->scene_change_lux_idx_delta_th2, alignment);
    result = result && entry->Read(&structure->core_rsv_para1, alignment);
    result = result && entry->Read(&structure->core_rsv_para2, alignment);
    result = result && entry->Read(&structure->core_rsv_para3, alignment);
    result = result && entry->Read(&structure->core_rsv_para4, alignment);
    result = result && entry->Read(&structure->core_rsv_para5, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load tmc12_rgn_dataType_tone_target_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadtmc12_rgn_dataType_tone_target_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    tmc12_rgn_dataType::tone_target_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->tone_target, 5, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load tmc12_rgn_dataType_tone_anchors_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadtmc12_rgn_dataType_tone_anchors_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    tmc12_rgn_dataType::tone_anchors_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->tone_anchors, 5, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load tmc12_rgn_dataType_hist_conv_kernel_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadtmc12_rgn_dataType_hist_conv_kernel_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    tmc12_rgn_dataType::hist_conv_kernel_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->hist_conv_kernel, 5, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load tmc12_rgn_dataType_hist_enhance_ratio_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadtmc12_rgn_dataType_hist_enhance_ratio_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    tmc12_rgn_dataType::hist_enhance_ratio_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->hist_enhance_ratio, 5, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_tmc12_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadmod_tmc12_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_tmc12_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = globalelements::globalelementsClass::Loadtrigger_pt_type_aec(entry, &structure->aec_trigger, alignment);
    result = result && Loadtmc12_rgn_dataType(entry, &structure->tmc12_rgn_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_tmc12_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadmod_tmc12_hdr_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_tmc12_hdr_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type_aec_hdr(entry, &structure->hdr_aec_trigger, alignment);
    result = result && Loadmod_tmc12_hdr_aec_dataType_hdr_aec_dataStruct(entry, &structure->hdr_aec_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_tmc12_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadmod_tmc12_hdr_aec_dataType_hdr_aec_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_tmc12_hdr_aec_dataType::hdr_aec_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_tmc12_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_tmc12_aec_dataCount, alignment);
        structure->mod_tmc12_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_tmc12_aec_data = PARAMETER_NEW mod_tmc12_aec_dataType[structure->mod_tmc12_aec_dataCount];
        }
        if (!result || structure->mod_tmc12_aec_data == NULL)
        {
            structure->mod_tmc12_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_tmc12_aec_dataCount; i++)
        {
            result = Loadmod_tmc12_aec_dataType(pointerEntry, &structure->mod_tmc12_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_tmc12_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadmod_tmc12_drc_gain_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_tmc12_drc_gain_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->drc_gain_trigger, alignment);
    result = result && Loadmod_tmc12_drc_gain_dataType_drc_gain_dataStruct(entry, &structure->drc_gain_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_tmc12_drc_gain_dataType_drc_gain_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadmod_tmc12_drc_gain_dataType_drc_gain_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_tmc12_drc_gain_dataType::drc_gain_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_tmc12_hdr_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_tmc12_hdr_aec_dataCount, alignment);
        structure->mod_tmc12_hdr_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_tmc12_hdr_aec_data = PARAMETER_NEW mod_tmc12_hdr_aec_dataType[structure->mod_tmc12_hdr_aec_dataCount];
        }
        if (!result || structure->mod_tmc12_hdr_aec_data == NULL)
        {
            structure->mod_tmc12_hdr_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_tmc12_hdr_aec_dataCount; i++)
        {
            result = Loadmod_tmc12_hdr_aec_dataType(pointerEntry, &structure->mod_tmc12_hdr_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_tmc12_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadchromatix_tmc12_coreType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tmc12_coreType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_tmc12_drc_gain_data from symbol table
    {
        result = entry->Read(&structure->mod_tmc12_drc_gain_dataCount, alignment);
        structure->mod_tmc12_drc_gain_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_tmc12_drc_gain_data = PARAMETER_NEW mod_tmc12_drc_gain_dataType[structure->mod_tmc12_drc_gain_dataCount];
        }
        if (!result || structure->mod_tmc12_drc_gain_data == NULL)
        {
            structure->mod_tmc12_drc_gain_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_tmc12_drc_gain_dataCount; i++)
        {
            result = Loadmod_tmc12_drc_gain_dataType(pointerEntry, &structure->mod_tmc12_drc_gain_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_tmc12_reserveType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadchromatix_tmc12_reserveType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tmc12_reserveType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->use_gtm, alignment);
    result = result && entry->Read(&structure->use_ltm, alignment);
    result = result && entry->Read(&structure->curve_model, alignment);
    result = result && entry->Read(&structure->curve_order, alignment);
    result = result && entry->Read(&structure->tone_max_ratio, alignment);
    result = result && entry->Read(&structure->reserve_rsv_para1, alignment);
    result = result && entry->Read(&structure->reserve_rsv_para2, alignment);
    result = result && entry->Read(&structure->reserve_rsv_para3, alignment);
    result = result && entry->Read(&structure->reserve_rsv_para4, alignment);
    result = result && entry->Read(&structure->reserve_rsv_para5, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_tmc12Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadchromatix_tmc12Type(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tmc12Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadenable_sectionStruct(entry, &structure->enable_section, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && Loadcontrol_variablesStruct(entry, &structure->control_variables, alignment);
    result = result && Loadcontrol_methodStruct(entry, &structure->control_method, alignment);
    result = result && Loadchromatix_tmc12_reserveType(entry, &structure->chromatix_tmc12_reserve, alignment);
    result = result && Loadchromatix_tmc12_coreType(entry, &structure->chromatix_tmc12_core, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load enable_sectionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadenable_sectionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tmc12Type::enable_sectionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->tmc_enable, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tmc12Type::module_versionStruct* structure,
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
BOOL chromatix_tmc12TypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tmc12Type::parameter_versionStruct* structure,
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
/// Load control_variablesStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadcontrol_variablesStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tmc12Type::control_variablesStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    for (UINT32 i = 0; result && i < 3; i++)
    {
        structure->control_var_type[i] = (chromatix_tmc12Type::control_variablesStruct::control_var_typeEnum)entry->ReadEnum(&result, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load control_methodStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tmc12TypeClass::Loadcontrol_methodStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tmc12Type::control_methodStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    structure->aec_exp_control = (ispglobalelements::tuning_control_aec_type)entry->ReadEnum(&result, alignment);
    structure->aec_hdr_control = (ispglobalelements::tuning_control_aec_hdr_type)entry->ReadEnum(&result, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_tmc12_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_tmc12TypeClass::Unloadmod_tmc12_hdr_aec_dataType(
    mod_tmc12_hdr_aec_dataType* structure)
{
    Unloadmod_tmc12_hdr_aec_dataType_hdr_aec_dataStruct(&structure->hdr_aec_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_tmc12_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_tmc12TypeClass::Unloadmod_tmc12_hdr_aec_dataType_hdr_aec_dataStruct(
    mod_tmc12_hdr_aec_dataType::hdr_aec_dataStruct* structure)
{
    PARAMETER_DELETE[] structure->mod_tmc12_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_tmc12_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_tmc12TypeClass::Unloadmod_tmc12_drc_gain_dataType(
    mod_tmc12_drc_gain_dataType* structure)
{
    Unloadmod_tmc12_drc_gain_dataType_drc_gain_dataStruct(&structure->drc_gain_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_tmc12_drc_gain_dataType_drc_gain_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_tmc12TypeClass::Unloadmod_tmc12_drc_gain_dataType_drc_gain_dataStruct(
    mod_tmc12_drc_gain_dataType::drc_gain_dataStruct* structure)
{
    for (UINT32 i = 0; i < structure->mod_tmc12_hdr_aec_dataCount; i++)
    {
        Unloadmod_tmc12_hdr_aec_dataType(&structure->mod_tmc12_hdr_aec_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_tmc12_hdr_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_tmc12_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_tmc12TypeClass::Unloadchromatix_tmc12_coreType(
    chromatix_tmc12_coreType* structure)
{
    for (UINT32 i = 0; i < structure->mod_tmc12_drc_gain_dataCount; i++)
    {
        Unloadmod_tmc12_drc_gain_dataType(&structure->mod_tmc12_drc_gain_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_tmc12_drc_gain_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_tmc12Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_tmc12TypeClass::Unloadchromatix_tmc12Type(
    chromatix_tmc12Type* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    Unloadchromatix_tmc12_coreType(&structure->chromatix_tmc12_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_tmc12TypeClass::Unloadparameter_versionStruct(
    chromatix_tmc12Type::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatix_tmc12TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatix_tmc12TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatix_tmc12TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && Loadchromatix_tmc12Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


TMC_1_2_0_NAMESPACE_END
