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
/// @file  abf_4_0_0.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "abf_4_0_0.h"
#include "parametersetmanager.h"

ABF_4_0_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_abf40TypeClass::chromatix_abf40TypeClass(
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
    PARAMETER_INITIALIZE(chromatix_abf40_reserve);
    PARAMETER_INITIALIZE(chromatix_abf40_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_abf40TypeClass::chromatix_abf40TypeClass(
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
    PARAMETER_INITIALIZE(chromatix_abf40_reserve);
    PARAMETER_INITIALIZE(chromatix_abf40_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_abf40TypeClass::~chromatix_abf40TypeClass()
{
    Unloadchromatix_abf40Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatix_abf40TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "abf40_bps")) == 0)
    {
        name = "abf40_bps";
    }
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "abf40_ife")) == 0)
    {
        name = "abf40_ife";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf40_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadabf40_rgn_dataType(
    ParameterFileSymbolTableEntry* entry,
    abf40_rgn_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->minmax_maxshft, alignment);
    result = result && entry->Read(&structure->minmax_minshft, alignment);
    result = result && entry->Read(&structure->minmax_offset, alignment);
    result = result && entry->Read(&structure->minmax_bls, alignment);
    result = result && Loadabf40_rgn_dataType_blkpix_lev_tabStruct(entry, &structure->blkpix_lev_tab, alignment);
    result = result && Loadabf40_rgn_dataType_noise_std_lut_tabStruct(entry, &structure->noise_std_lut_tab, alignment);
    result = result && Loadabf40_rgn_dataType_curve_offset_tabStruct(entry, &structure->curve_offset_tab, alignment);
    result = result && Loadabf40_rgn_dataType_dist_ker_tabStruct(entry, &structure->dist_ker_tab, alignment);
    result = result && Loadabf40_rgn_dataType_edge_softness_tabStruct(entry, &structure->edge_softness_tab, alignment);
    result = result && Loadabf40_rgn_dataType_denoise_strength_tabStruct(entry, &structure->denoise_strength_tab, alignment);
    result = result && Loadabf40_rgn_dataType_noise_prsv_anchor_tabStruct(entry, &structure->noise_prsv_anchor_tab, alignment);
    result = result && Loadabf40_rgn_dataType_noise_prsv_base_tabStruct(entry, &structure->noise_prsv_base_tab, alignment);
    result = result && Loadabf40_rgn_dataType_radial_edge_softness_adj_tabStruct(entry, &structure->radial_edge_softness_adj_tab, alignment);
    result = result && Loadabf40_rgn_dataType_radial_noise_prsv_adj_tabStruct(entry, &structure->radial_noise_prsv_adj_tab, alignment);
    result = result && Loadabf40_rgn_dataType_act_fac_lut_tabStruct(entry, &structure->act_fac_lut_tab, alignment);
    result = result && entry->Read(&structure->act_fac0, alignment);
    result = result && entry->Read(&structure->act_fac1, alignment);
    result = result && entry->Read(&structure->act_thd0, alignment);
    result = result && entry->Read(&structure->act_thd1, alignment);
    result = result && entry->Read(&structure->act_smth_thd0, alignment);
    result = result && entry->Read(&structure->act_smth_thd1, alignment);
    result = result && entry->Read(&structure->dark_thd, alignment);
    result = result && Loadabf40_rgn_dataType_dark_fac_lut_tabStruct(entry, &structure->dark_fac_lut_tab, alignment);
    result = result && entry->Read(&structure->edge_detect_thd, alignment);
    result = result && entry->Read(&structure->edge_count_low, alignment);
    result = result && entry->Read(&structure->edge_detect_noise_scaler, alignment);
    result = result && entry->Read(&structure->edge_smooth_strength, alignment);
    result = result && Loadabf40_rgn_dataType_edge_smooth_scaler_tabStruct(entry, &structure->edge_smooth_scaler_tab, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf40_rgn_dataType_blkpix_lev_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadabf40_rgn_dataType_blkpix_lev_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf40_rgn_dataType::blkpix_lev_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->blkpix_lev, 2, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf40_rgn_dataType_noise_std_lut_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadabf40_rgn_dataType_noise_std_lut_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf40_rgn_dataType::noise_std_lut_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->noise_std_lut, 65, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf40_rgn_dataType_curve_offset_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadabf40_rgn_dataType_curve_offset_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf40_rgn_dataType::curve_offset_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->curve_offset, 4, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf40_rgn_dataType_dist_ker_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadabf40_rgn_dataType_dist_ker_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf40_rgn_dataType::dist_ker_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->dist_ker, 18, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf40_rgn_dataType_edge_softness_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadabf40_rgn_dataType_edge_softness_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf40_rgn_dataType::edge_softness_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->edge_softness, 4, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf40_rgn_dataType_denoise_strength_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadabf40_rgn_dataType_denoise_strength_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf40_rgn_dataType::denoise_strength_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->denoise_strength, 4, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf40_rgn_dataType_noise_prsv_anchor_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadabf40_rgn_dataType_noise_prsv_anchor_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf40_rgn_dataType::noise_prsv_anchor_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->noise_prsv_anchor, 5, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf40_rgn_dataType_noise_prsv_base_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadabf40_rgn_dataType_noise_prsv_base_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf40_rgn_dataType::noise_prsv_base_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->noise_prsv_base, 10, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf40_rgn_dataType_radial_edge_softness_adj_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadabf40_rgn_dataType_radial_edge_softness_adj_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf40_rgn_dataType::radial_edge_softness_adj_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->radial_edge_softness_adj, 5, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf40_rgn_dataType_radial_noise_prsv_adj_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadabf40_rgn_dataType_radial_noise_prsv_adj_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf40_rgn_dataType::radial_noise_prsv_adj_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->radial_noise_prsv_adj, 5, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf40_rgn_dataType_act_fac_lut_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadabf40_rgn_dataType_act_fac_lut_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf40_rgn_dataType::act_fac_lut_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->act_fac_lut, 32, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf40_rgn_dataType_dark_fac_lut_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadabf40_rgn_dataType_dark_fac_lut_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf40_rgn_dataType::dark_fac_lut_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->dark_fac_lut, 42, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load abf40_rgn_dataType_edge_smooth_scaler_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadabf40_rgn_dataType_edge_smooth_scaler_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    abf40_rgn_dataType::edge_smooth_scaler_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->edge_smooth_scaler, 4, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_abf40_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadmod_abf40_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_abf40_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = globalelements::globalelementsClass::Loadtrigger_pt_type_aec(entry, &structure->aec_trigger, alignment);
    result = result && Loadabf40_rgn_dataType(entry, &structure->abf40_rgn_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_abf40_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadmod_abf40_hdr_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_abf40_hdr_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type_aec_hdr(entry, &structure->hdr_aec_trigger, alignment);
    result = result && Loadmod_abf40_hdr_aec_dataType_hdr_aec_dataStruct(entry, &structure->hdr_aec_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_abf40_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadmod_abf40_hdr_aec_dataType_hdr_aec_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_abf40_hdr_aec_dataType::hdr_aec_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_abf40_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_abf40_aec_dataCount, alignment);
        structure->mod_abf40_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_abf40_aec_data = PARAMETER_NEW mod_abf40_aec_dataType[structure->mod_abf40_aec_dataCount];
        }
        if (!result || structure->mod_abf40_aec_data == NULL)
        {
            structure->mod_abf40_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_abf40_aec_dataCount; i++)
        {
            result = Loadmod_abf40_aec_dataType(pointerEntry, &structure->mod_abf40_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_abf40_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadmod_abf40_drc_gain_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_abf40_drc_gain_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->drc_gain_trigger, alignment);
    result = result && Loadmod_abf40_drc_gain_dataType_drc_gain_dataStruct(entry, &structure->drc_gain_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_abf40_drc_gain_dataType_drc_gain_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadmod_abf40_drc_gain_dataType_drc_gain_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_abf40_drc_gain_dataType::drc_gain_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_abf40_hdr_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_abf40_hdr_aec_dataCount, alignment);
        structure->mod_abf40_hdr_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_abf40_hdr_aec_data = PARAMETER_NEW mod_abf40_hdr_aec_dataType[structure->mod_abf40_hdr_aec_dataCount];
        }
        if (!result || structure->mod_abf40_hdr_aec_data == NULL)
        {
            structure->mod_abf40_hdr_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_abf40_hdr_aec_dataCount; i++)
        {
            result = Loadmod_abf40_hdr_aec_dataType(pointerEntry, &structure->mod_abf40_hdr_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_abf40_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadchromatix_abf40_coreType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf40_coreType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_abf40_drc_gain_data from symbol table
    {
        result = entry->Read(&structure->mod_abf40_drc_gain_dataCount, alignment);
        structure->mod_abf40_drc_gain_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_abf40_drc_gain_data = PARAMETER_NEW mod_abf40_drc_gain_dataType[structure->mod_abf40_drc_gain_dataCount];
        }
        if (!result || structure->mod_abf40_drc_gain_data == NULL)
        {
            structure->mod_abf40_drc_gain_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_abf40_drc_gain_dataCount; i++)
        {
            result = Loadmod_abf40_drc_gain_dataType(pointerEntry, &structure->mod_abf40_drc_gain_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_abf40_reserveType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadchromatix_abf40_reserveType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf40_reserveType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->cross_plane_en, alignment);
    result = result && entry->Read(&structure->dark_desat_en, alignment);
    result = result && entry->Read(&structure->dark_smooth_en, alignment);
    result = result && entry->Read(&structure->act_adj_en, alignment);
    result = result && entry->Read(&structure->blk_opt, alignment);
    result = result && Loadchromatix_abf40_reserveType_radial_anchor_tabStruct(entry, &structure->radial_anchor_tab, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_abf40_reserveType_radial_anchor_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadchromatix_abf40_reserveType_radial_anchor_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf40_reserveType::radial_anchor_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->radial_anchor, 5, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_abf40Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadchromatix_abf40Type(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf40Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadenable_sectionStruct(entry, &structure->enable_section, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && Loadcontrol_variablesStruct(entry, &structure->control_variables, alignment);
    result = result && Loadcontrol_methodStruct(entry, &structure->control_method, alignment);
    result = result && Loaddynamic_enable_triggersStruct(entry, &structure->dynamic_enable_triggers, alignment);
    result = result && Loadchromatix_abf40_reserveType(entry, &structure->chromatix_abf40_reserve, alignment);
    result = result && Loadchromatix_abf40_coreType(entry, &structure->chromatix_abf40_core, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load enable_sectionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadenable_sectionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf40Type::enable_sectionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->bilateral_en, alignment);
    result = result && entry->Read(&structure->minmax_en, alignment);
    result = result && entry->Read(&structure->dirsmth_en, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf40Type::module_versionStruct* structure,
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
BOOL chromatix_abf40TypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf40Type::parameter_versionStruct* structure,
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
BOOL chromatix_abf40TypeClass::Loadcontrol_variablesStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf40Type::control_variablesStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    for (UINT32 i = 0; result && i < 3; i++)
    {
        structure->control_var_type[i] = (chromatix_abf40Type::control_variablesStruct::control_var_typeEnum)entry->ReadEnum(&result, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load control_methodStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loadcontrol_methodStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf40Type::control_methodStruct* structure,
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
BOOL chromatix_abf40TypeClass::Loaddynamic_enable_triggersStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf40Type::dynamic_enable_triggersStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loaddynamic_enable_triggersStruct_bilateral_enStruct(entry, &structure->bilateral_en, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dynamic_enable_triggersStruct_bilateral_enStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_abf40TypeClass::Loaddynamic_enable_triggersStruct_bilateral_enStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_abf40Type::dynamic_enable_triggersStruct::bilateral_enStruct* structure,
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
/// Unload mod_abf40_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_abf40TypeClass::Unloadmod_abf40_hdr_aec_dataType(
    mod_abf40_hdr_aec_dataType* structure)
{
    Unloadmod_abf40_hdr_aec_dataType_hdr_aec_dataStruct(&structure->hdr_aec_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_abf40_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_abf40TypeClass::Unloadmod_abf40_hdr_aec_dataType_hdr_aec_dataStruct(
    mod_abf40_hdr_aec_dataType::hdr_aec_dataStruct* structure)
{
    PARAMETER_DELETE[] structure->mod_abf40_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_abf40_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_abf40TypeClass::Unloadmod_abf40_drc_gain_dataType(
    mod_abf40_drc_gain_dataType* structure)
{
    Unloadmod_abf40_drc_gain_dataType_drc_gain_dataStruct(&structure->drc_gain_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_abf40_drc_gain_dataType_drc_gain_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_abf40TypeClass::Unloadmod_abf40_drc_gain_dataType_drc_gain_dataStruct(
    mod_abf40_drc_gain_dataType::drc_gain_dataStruct* structure)
{
    for (UINT32 i = 0; i < structure->mod_abf40_hdr_aec_dataCount; i++)
    {
        Unloadmod_abf40_hdr_aec_dataType(&structure->mod_abf40_hdr_aec_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_abf40_hdr_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_abf40_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_abf40TypeClass::Unloadchromatix_abf40_coreType(
    chromatix_abf40_coreType* structure)
{
    for (UINT32 i = 0; i < structure->mod_abf40_drc_gain_dataCount; i++)
    {
        Unloadmod_abf40_drc_gain_dataType(&structure->mod_abf40_drc_gain_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_abf40_drc_gain_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_abf40Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_abf40TypeClass::Unloadchromatix_abf40Type(
    chromatix_abf40Type* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    Unloadchromatix_abf40_coreType(&structure->chromatix_abf40_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_abf40TypeClass::Unloadparameter_versionStruct(
    chromatix_abf40Type::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatix_abf40TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatix_abf40TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatix_abf40TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && Loadchromatix_abf40Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


ABF_4_0_0_NAMESPACE_END