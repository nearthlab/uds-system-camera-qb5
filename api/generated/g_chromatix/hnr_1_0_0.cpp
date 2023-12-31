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
/// @file  hnr_1_0_0.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "hnr_1_0_0.h"
#include "parametersetmanager.h"

HNR_1_0_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_hnr10TypeClass::chromatix_hnr10TypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(enable_section);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(control_variables);
    PARAMETER_INITIALIZE(control_method);
    PARAMETER_INITIALIZE(dynamic_enable_triggers);
    PARAMETER_INITIALIZE(chromatix_hnr10_reserve);
    PARAMETER_INITIALIZE(chromatix_hnr10_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_hnr10TypeClass::chromatix_hnr10TypeClass(
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
    PARAMETER_INITIALIZE(dynamic_enable_triggers);
    PARAMETER_INITIALIZE(chromatix_hnr10_reserve);
    PARAMETER_INITIALIZE(chromatix_hnr10_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_hnr10TypeClass::~chromatix_hnr10TypeClass()
{
    Unloadchromatix_hnr10Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatix_hnr10TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "hnr10_bps")) == 0)
    {
        name = "hnr10_bps";
    }
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "hnr10_ipe")) == 0)
    {
        name = "hnr10_ipe";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load hnr10_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadhnr10_rgn_dataType(
    ParameterFileSymbolTableEntry* entry,
    hnr10_rgn_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadhnr10_rgn_dataType_lnr_gain_arr_tabStruct(entry, &structure->lnr_gain_arr_tab, alignment);
    result = result && entry->Read(&structure->lnr_shift, alignment);
    result = result && Loadhnr10_rgn_dataType_radial_noise_prsv_adj_tabStruct(entry, &structure->radial_noise_prsv_adj_tab, alignment);
    result = result && Loadhnr10_rgn_dataType_cnr_gain_arr_tabStruct(entry, &structure->cnr_gain_arr_tab, alignment);
    result = result && entry->Read(&structure->cnr_low_thrd_u, alignment);
    result = result && entry->Read(&structure->cnr_low_thrd_v, alignment);
    result = result && entry->Read(&structure->cnr_low_gap_u, alignment);
    result = result && entry->Read(&structure->cnr_low_gap_v, alignment);
    result = result && entry->Read(&structure->cnr_adj_gain, alignment);
    result = result && entry->Read(&structure->cnr_scale, alignment);
    result = result && Loadhnr10_rgn_dataType_fnr_gain_arr_tabStruct(entry, &structure->fnr_gain_arr_tab, alignment);
    result = result && Loadhnr10_rgn_dataType_fnr_gain_clamp_arr_tabStruct(entry, &structure->fnr_gain_clamp_arr_tab, alignment);
    result = result && Loadhnr10_rgn_dataType_fnr_ac_th_tabStruct(entry, &structure->fnr_ac_th_tab, alignment);
    result = result && entry->Read(&structure->fnr_ac_shift, alignment);
    result = result && Loadhnr10_rgn_dataType_filtering_nr_gain_arr_tabStruct(entry, &structure->filtering_nr_gain_arr_tab, alignment);
    result = result && entry->Read(&structure->abs_amp_shift, alignment);
    result = result && entry->Read(&structure->lpf3_percent, alignment);
    result = result && entry->Read(&structure->lpf3_offset, alignment);
    result = result && entry->Read(&structure->lpf3_strength, alignment);
    result = result && Loadhnr10_rgn_dataType_blend_lnr_gain_arr_tabStruct(entry, &structure->blend_lnr_gain_arr_tab, alignment);
    result = result && entry->Read(&structure->blend_cnr_adj_gain, alignment);
    result = result && Loadhnr10_rgn_dataType_blend_snr_gain_arr_tabStruct(entry, &structure->blend_snr_gain_arr_tab, alignment);
    result = result && entry->Read(&structure->skin_hue_min, alignment);
    result = result && entry->Read(&structure->skin_hue_max, alignment);
    result = result && entry->Read(&structure->skin_y_min, alignment);
    result = result && entry->Read(&structure->skin_y_max, alignment);
    result = result && entry->Read(&structure->skin_saturation_min_y_max, alignment);
    result = result && entry->Read(&structure->skin_saturation_max_y_max, alignment);
    result = result && entry->Read(&structure->skin_saturation_min_y_min, alignment);
    result = result && entry->Read(&structure->skin_saturation_max_y_min, alignment);
    result = result && entry->Read(&structure->skin_boundary_probability, alignment);
    result = result && entry->Read(&structure->skin_percent, alignment);
    result = result && entry->Read(&structure->skin_non_skin_to_skin_q_ratio, alignment);
    result = result && entry->Read(&structure->face_boundary, alignment);
    result = result && entry->Read(&structure->face_transition, alignment);
    result = result && Loadhnr10_rgn_dataType_snr_gain_arr_tabStruct(entry, &structure->snr_gain_arr_tab, alignment);
    result = result && entry->Read(&structure->snr_skin_smoothing_str, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load hnr10_rgn_dataType_lnr_gain_arr_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadhnr10_rgn_dataType_lnr_gain_arr_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    hnr10_rgn_dataType::lnr_gain_arr_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->lnr_gain_arr, 33, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load hnr10_rgn_dataType_radial_noise_prsv_adj_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadhnr10_rgn_dataType_radial_noise_prsv_adj_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    hnr10_rgn_dataType::radial_noise_prsv_adj_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->radial_noise_prsv_adj, 7, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load hnr10_rgn_dataType_cnr_gain_arr_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadhnr10_rgn_dataType_cnr_gain_arr_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    hnr10_rgn_dataType::cnr_gain_arr_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->cnr_gain_arr, 25, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load hnr10_rgn_dataType_fnr_gain_arr_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadhnr10_rgn_dataType_fnr_gain_arr_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    hnr10_rgn_dataType::fnr_gain_arr_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->fnr_gain_arr, 17, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load hnr10_rgn_dataType_fnr_gain_clamp_arr_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadhnr10_rgn_dataType_fnr_gain_clamp_arr_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    hnr10_rgn_dataType::fnr_gain_clamp_arr_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->fnr_gain_clamp_arr, 17, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load hnr10_rgn_dataType_fnr_ac_th_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadhnr10_rgn_dataType_fnr_ac_th_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    hnr10_rgn_dataType::fnr_ac_th_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->fnr_ac_th, 17, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load hnr10_rgn_dataType_filtering_nr_gain_arr_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadhnr10_rgn_dataType_filtering_nr_gain_arr_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    hnr10_rgn_dataType::filtering_nr_gain_arr_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->filtering_nr_gain_arr, 33, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load hnr10_rgn_dataType_blend_lnr_gain_arr_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadhnr10_rgn_dataType_blend_lnr_gain_arr_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    hnr10_rgn_dataType::blend_lnr_gain_arr_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->blend_lnr_gain_arr, 17, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load hnr10_rgn_dataType_blend_snr_gain_arr_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadhnr10_rgn_dataType_blend_snr_gain_arr_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    hnr10_rgn_dataType::blend_snr_gain_arr_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->blend_snr_gain_arr, 17, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load hnr10_rgn_dataType_snr_gain_arr_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadhnr10_rgn_dataType_snr_gain_arr_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    hnr10_rgn_dataType::snr_gain_arr_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->snr_gain_arr, 17, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_hnr10_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadmod_hnr10_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_hnr10_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = globalelements::globalelementsClass::Loadtrigger_pt_type_aec(entry, &structure->aec_trigger, alignment);
    result = result && Loadhnr10_rgn_dataType(entry, &structure->hnr10_rgn_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_hnr10_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadmod_hnr10_hdr_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_hnr10_hdr_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type_aec_hdr(entry, &structure->hdr_aec_trigger, alignment);
    result = result && Loadmod_hnr10_hdr_aec_dataType_hdr_aec_dataStruct(entry, &structure->hdr_aec_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_hnr10_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadmod_hnr10_hdr_aec_dataType_hdr_aec_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_hnr10_hdr_aec_dataType::hdr_aec_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_hnr10_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_hnr10_aec_dataCount, alignment);
        structure->mod_hnr10_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_hnr10_aec_data = PARAMETER_NEW mod_hnr10_aec_dataType[structure->mod_hnr10_aec_dataCount];
        }
        if (!result || structure->mod_hnr10_aec_data == NULL)
        {
            structure->mod_hnr10_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_hnr10_aec_dataCount; i++)
        {
            result = Loadmod_hnr10_aec_dataType(pointerEntry, &structure->mod_hnr10_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_hnr10_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadmod_hnr10_drc_gain_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_hnr10_drc_gain_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->drc_gain_trigger, alignment);
    result = result && Loadmod_hnr10_drc_gain_dataType_drc_gain_dataStruct(entry, &structure->drc_gain_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_hnr10_drc_gain_dataType_drc_gain_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadmod_hnr10_drc_gain_dataType_drc_gain_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_hnr10_drc_gain_dataType::drc_gain_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_hnr10_hdr_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_hnr10_hdr_aec_dataCount, alignment);
        structure->mod_hnr10_hdr_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_hnr10_hdr_aec_data = PARAMETER_NEW mod_hnr10_hdr_aec_dataType[structure->mod_hnr10_hdr_aec_dataCount];
        }
        if (!result || structure->mod_hnr10_hdr_aec_data == NULL)
        {
            structure->mod_hnr10_hdr_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_hnr10_hdr_aec_dataCount; i++)
        {
            result = Loadmod_hnr10_hdr_aec_dataType(pointerEntry, &structure->mod_hnr10_hdr_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_hnr10_total_scale_ratio_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadmod_hnr10_total_scale_ratio_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_hnr10_total_scale_ratio_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->total_scale_ratio_trigger, alignment);
    result = result && Loadmod_hnr10_total_scale_ratio_dataType_total_scale_ratio_dataStruct(entry, &structure->total_scale_ratio_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_hnr10_total_scale_ratio_dataType_total_scale_ratio_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadmod_hnr10_total_scale_ratio_dataType_total_scale_ratio_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_hnr10_total_scale_ratio_dataType::total_scale_ratio_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_hnr10_drc_gain_data from symbol table
    {
        result = entry->Read(&structure->mod_hnr10_drc_gain_dataCount, alignment);
        structure->mod_hnr10_drc_gain_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_hnr10_drc_gain_data = PARAMETER_NEW mod_hnr10_drc_gain_dataType[structure->mod_hnr10_drc_gain_dataCount];
        }
        if (!result || structure->mod_hnr10_drc_gain_data == NULL)
        {
            structure->mod_hnr10_drc_gain_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_hnr10_drc_gain_dataCount; i++)
        {
            result = Loadmod_hnr10_drc_gain_dataType(pointerEntry, &structure->mod_hnr10_drc_gain_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_hnr10_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadchromatix_hnr10_coreType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hnr10_coreType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_hnr10_total_scale_ratio_data from symbol table
    {
        result = entry->Read(&structure->mod_hnr10_total_scale_ratio_dataCount, alignment);
        structure->mod_hnr10_total_scale_ratio_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_hnr10_total_scale_ratio_data = PARAMETER_NEW mod_hnr10_total_scale_ratio_dataType[structure->mod_hnr10_total_scale_ratio_dataCount];
        }
        if (!result || structure->mod_hnr10_total_scale_ratio_data == NULL)
        {
            structure->mod_hnr10_total_scale_ratio_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_hnr10_total_scale_ratio_dataCount; i++)
        {
            result = Loadmod_hnr10_total_scale_ratio_dataType(pointerEntry, &structure->mod_hnr10_total_scale_ratio_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_hnr10_reserveType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadchromatix_hnr10_reserveType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hnr10_reserveType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->lnr_en, alignment);
    result = result && entry->Read(&structure->rnr_en, alignment);
    result = result && entry->Read(&structure->cnr_en, alignment);
    result = result && entry->Read(&structure->snr_en, alignment);
    result = result && entry->Read(&structure->fd_snr_en, alignment);
    result = result && entry->Read(&structure->fnr_en, alignment);
    result = result && entry->Read(&structure->lpf3_en, alignment);
    result = result && entry->Read(&structure->blend_cnr_en, alignment);
    result = result && entry->Read(&structure->blend_snr_en, alignment);
    result = result && Loadchromatix_hnr10_reserveType_radial_anchor_tabStruct(entry, &structure->radial_anchor_tab, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_hnr10_reserveType_radial_anchor_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadchromatix_hnr10_reserveType_radial_anchor_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hnr10_reserveType::radial_anchor_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->radial_anchor, 7, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_hnr10Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadchromatix_hnr10Type(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hnr10Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadenable_sectionStruct(entry, &structure->enable_section, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && Loadcontrol_variablesStruct(entry, &structure->control_variables, alignment);
    result = result && Loadcontrol_methodStruct(entry, &structure->control_method, alignment);
    result = result && Loaddynamic_enable_triggersStruct(entry, &structure->dynamic_enable_triggers, alignment);
    result = result && Loadchromatix_hnr10_reserveType(entry, &structure->chromatix_hnr10_reserve, alignment);
    result = result && Loadchromatix_hnr10_coreType(entry, &structure->chromatix_hnr10_core, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load enable_sectionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadenable_sectionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hnr10Type::enable_sectionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->hnr_nr_enable, alignment);
    result = result && entry->Read(&structure->hnr_blend_enable, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hnr10Type::module_versionStruct* structure,
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
BOOL chromatix_hnr10TypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hnr10Type::parameter_versionStruct* structure,
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
BOOL chromatix_hnr10TypeClass::Loadcontrol_variablesStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hnr10Type::control_variablesStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    for (UINT32 i = 0; result && i < 4; i++)
    {
        structure->control_var_type[i] = (chromatix_hnr10Type::control_variablesStruct::control_var_typeEnum)entry->ReadEnum(&result, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load control_methodStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loadcontrol_methodStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hnr10Type::control_methodStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    structure->aec_exp_control = (ispglobalelements::tuning_control_aec_type)entry->ReadEnum(&result, alignment);
    structure->aec_hdr_control = (ispglobalelements::tuning_control_aec_hdr_type)entry->ReadEnum(&result, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dynamic_enable_triggersStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loaddynamic_enable_triggersStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hnr10Type::dynamic_enable_triggersStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loaddynamic_enable_triggersStruct_hnr_nr_enableStruct(entry, &structure->hnr_nr_enable, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dynamic_enable_triggersStruct_hnr_nr_enableStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hnr10TypeClass::Loaddynamic_enable_triggersStruct_hnr_nr_enableStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hnr10Type::dynamic_enable_triggersStruct::hnr_nr_enableStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->enable, alignment);
    structure->hyst_control_var = (ispglobalelements::control_var_type)entry->ReadEnum(&result, alignment);
    structure->hyst_mode = (ispglobalelements::hyst_direction)entry->ReadEnum(&result, alignment);
    result = result && ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_couplet_type(entry, &structure->hyst_trigger, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_hnr10_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_hnr10TypeClass::Unloadmod_hnr10_hdr_aec_dataType(
    mod_hnr10_hdr_aec_dataType* structure)
{
    Unloadmod_hnr10_hdr_aec_dataType_hdr_aec_dataStruct(&structure->hdr_aec_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_hnr10_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_hnr10TypeClass::Unloadmod_hnr10_hdr_aec_dataType_hdr_aec_dataStruct(
    mod_hnr10_hdr_aec_dataType::hdr_aec_dataStruct* structure)
{
    PARAMETER_DELETE[] structure->mod_hnr10_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_hnr10_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_hnr10TypeClass::Unloadmod_hnr10_drc_gain_dataType(
    mod_hnr10_drc_gain_dataType* structure)
{
    Unloadmod_hnr10_drc_gain_dataType_drc_gain_dataStruct(&structure->drc_gain_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_hnr10_drc_gain_dataType_drc_gain_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_hnr10TypeClass::Unloadmod_hnr10_drc_gain_dataType_drc_gain_dataStruct(
    mod_hnr10_drc_gain_dataType::drc_gain_dataStruct* structure)
{
    for (UINT32 i = 0; i < structure->mod_hnr10_hdr_aec_dataCount; i++)
    {
        Unloadmod_hnr10_hdr_aec_dataType(&structure->mod_hnr10_hdr_aec_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_hnr10_hdr_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_hnr10_total_scale_ratio_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_hnr10TypeClass::Unloadmod_hnr10_total_scale_ratio_dataType(
    mod_hnr10_total_scale_ratio_dataType* structure)
{
    Unloadmod_hnr10_total_scale_ratio_dataType_total_scale_ratio_dataStruct(&structure->total_scale_ratio_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_hnr10_total_scale_ratio_dataType_total_scale_ratio_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_hnr10TypeClass::Unloadmod_hnr10_total_scale_ratio_dataType_total_scale_ratio_dataStruct(
    mod_hnr10_total_scale_ratio_dataType::total_scale_ratio_dataStruct* structure)
{
    for (UINT32 i = 0; i < structure->mod_hnr10_drc_gain_dataCount; i++)
    {
        Unloadmod_hnr10_drc_gain_dataType(&structure->mod_hnr10_drc_gain_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_hnr10_drc_gain_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_hnr10_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_hnr10TypeClass::Unloadchromatix_hnr10_coreType(
    chromatix_hnr10_coreType* structure)
{
    for (UINT32 i = 0; i < structure->mod_hnr10_total_scale_ratio_dataCount; i++)
    {
        Unloadmod_hnr10_total_scale_ratio_dataType(&structure->mod_hnr10_total_scale_ratio_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_hnr10_total_scale_ratio_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_hnr10Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_hnr10TypeClass::Unloadchromatix_hnr10Type(
    chromatix_hnr10Type* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    Unloadchromatix_hnr10_coreType(&structure->chromatix_hnr10_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_hnr10TypeClass::Unloadparameter_versionStruct(
    chromatix_hnr10Type::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatix_hnr10TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatix_hnr10TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatix_hnr10TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && Loadchromatix_hnr10Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


HNR_1_0_0_NAMESPACE_END
