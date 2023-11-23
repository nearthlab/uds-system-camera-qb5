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
/// @file  hdr_2_3_0.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "hdr_2_3_0.h"
#include "parametersetmanager.h"

HDR_2_3_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_hdr23TypeClass::chromatix_hdr23TypeClass(
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
    PARAMETER_INITIALIZE(chromatix_hdr23_reserve);
    PARAMETER_INITIALIZE(chromatix_hdr23_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_hdr23TypeClass::chromatix_hdr23TypeClass(
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
    PARAMETER_INITIALIZE(chromatix_hdr23_reserve);
    PARAMETER_INITIALIZE(chromatix_hdr23_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_hdr23TypeClass::~chromatix_hdr23TypeClass()
{
    Unloadchromatix_hdr23Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatix_hdr23TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "hdr23_ife")) == 0)
    {
        name = "hdr23_ife";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load hdr23_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hdr23TypeClass::Loadhdr23_rgn_dataType(
    ParameterFileSymbolTableEntry* entry,
    hdr23_rgn_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->recon_min_factor, alignment);
    result = result && entry->Read(&structure->recon_flat_region_th, alignment);
    result = result && entry->Read(&structure->recon_h_edge_th1, alignment);
    result = result && entry->Read(&structure->recon_h_edge_dth_log2, alignment);
    result = result && entry->Read(&structure->recon_motion_th1, alignment);
    result = result && entry->Read(&structure->recon_motion_dth_log2, alignment);
    result = result && entry->Read(&structure->recon_dark_th1, alignment);
    result = result && entry->Read(&structure->recon_dark_dth_log2, alignment);
    result = result && entry->Read(&structure->hdr_zrec_prefilt_tap0, alignment);
    result = result && entry->Read(&structure->hdr_zrec_g_grad_th1, alignment);
    result = result && entry->Read(&structure->hdr_zrec_rb_grad_th1, alignment);
    result = result && entry->Read(&structure->mac_motion0_th1, alignment);
    result = result && entry->Read(&structure->mac_motion0_th2, alignment);
    result = result && entry->Read(&structure->mac_motion0_strength, alignment);
    result = result && entry->Read(&structure->mac_low_light_th1, alignment);
    result = result && entry->Read(&structure->mac_low_light_strength, alignment);
    result = result && entry->Read(&structure->mac_high_light_th1, alignment);
    result = result && entry->Read(&structure->mac_high_light_dth_log2, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_hdr23_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hdr23TypeClass::Loadmod_hdr23_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_hdr23_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = globalelements::globalelementsClass::Loadtrigger_pt_type_aec(entry, &structure->aec_trigger, alignment);
    result = result && Loadhdr23_rgn_dataType(entry, &structure->hdr23_rgn_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_hdr23_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hdr23TypeClass::Loadmod_hdr23_hdr_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_hdr23_hdr_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type_aec_hdr(entry, &structure->hdr_aec_trigger, alignment);
    result = result && Loadmod_hdr23_hdr_aec_dataType_hdr_aec_dataStruct(entry, &structure->hdr_aec_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_hdr23_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hdr23TypeClass::Loadmod_hdr23_hdr_aec_dataType_hdr_aec_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_hdr23_hdr_aec_dataType::hdr_aec_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_hdr23_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_hdr23_aec_dataCount, alignment);
        structure->mod_hdr23_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_hdr23_aec_data = PARAMETER_NEW mod_hdr23_aec_dataType[structure->mod_hdr23_aec_dataCount];
        }
        if (!result || structure->mod_hdr23_aec_data == NULL)
        {
            structure->mod_hdr23_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_hdr23_aec_dataCount; i++)
        {
            result = Loadmod_hdr23_aec_dataType(pointerEntry, &structure->mod_hdr23_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_hdr23_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hdr23TypeClass::Loadchromatix_hdr23_coreType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hdr23_coreType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_hdr23_hdr_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_hdr23_hdr_aec_dataCount, alignment);
        structure->mod_hdr23_hdr_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_hdr23_hdr_aec_data = PARAMETER_NEW mod_hdr23_hdr_aec_dataType[structure->mod_hdr23_hdr_aec_dataCount];
        }
        if (!result || structure->mod_hdr23_hdr_aec_data == NULL)
        {
            structure->mod_hdr23_hdr_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_hdr23_hdr_aec_dataCount; i++)
        {
            result = Loadmod_hdr23_hdr_aec_dataType(pointerEntry, &structure->mod_hdr23_hdr_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_hdr23_reserveType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hdr23TypeClass::Loadchromatix_hdr23_reserveType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hdr23_reserveType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->hdr_recon_en, alignment);
    result = result && entry->Read(&structure->hdr_mac_en, alignment);
    result = result && entry->Read(&structure->hdr_msb_align, alignment);
    result = result && entry->Read(&structure->hdr_zrec_g_grad_dth_log2, alignment);
    result = result && entry->Read(&structure->hdr_zrec_rb_grad_dth_log2, alignment);
    result = result && entry->Read(&structure->recon_edge_lpf_tap0, alignment);
    result = result && entry->Read(&structure->mac_motion_dilation, alignment);
    result = result && entry->Read(&structure->mac_motion0_dt0, alignment);
    result = result && entry->Read(&structure->mac_low_light_dth_log2, alignment);
    result = result && entry->Read(&structure->mac_smooth_enable, alignment);
    result = result && entry->Read(&structure->mac_smooth_th1, alignment);
    result = result && entry->Read(&structure->mac_smooth_dth_log2, alignment);
    result = result && entry->Read(&structure->mac_smooth_tap0, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_hdr23Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hdr23TypeClass::Loadchromatix_hdr23Type(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hdr23Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadenable_sectionStruct(entry, &structure->enable_section, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && Loadcontrol_variablesStruct(entry, &structure->control_variables, alignment);
    result = result && Loadcontrol_methodStruct(entry, &structure->control_method, alignment);
    result = result && Loaddynamic_enable_triggersStruct(entry, &structure->dynamic_enable_triggers, alignment);
    result = result && Loadchromatix_hdr23_reserveType(entry, &structure->chromatix_hdr23_reserve, alignment);
    result = result && Loadchromatix_hdr23_coreType(entry, &structure->chromatix_hdr23_core, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load enable_sectionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hdr23TypeClass::Loadenable_sectionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hdr23Type::enable_sectionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->hdr_enable, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hdr23TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hdr23Type::module_versionStruct* structure,
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
BOOL chromatix_hdr23TypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hdr23Type::parameter_versionStruct* structure,
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
BOOL chromatix_hdr23TypeClass::Loadcontrol_variablesStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hdr23Type::control_variablesStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    for (UINT32 i = 0; result && i < 2; i++)
    {
        structure->control_var_type[i] = (chromatix_hdr23Type::control_variablesStruct::control_var_typeEnum)entry->ReadEnum(&result, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load control_methodStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hdr23TypeClass::Loadcontrol_methodStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hdr23Type::control_methodStruct* structure,
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
BOOL chromatix_hdr23TypeClass::Loaddynamic_enable_triggersStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hdr23Type::dynamic_enable_triggersStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loaddynamic_enable_triggersStruct_hdr_recon_enStruct(entry, &structure->hdr_recon_en, alignment);
    result = result && Loaddynamic_enable_triggersStruct_hdr_mac_enStruct(entry, &structure->hdr_mac_en, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dynamic_enable_triggersStruct_hdr_recon_enStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hdr23TypeClass::Loaddynamic_enable_triggersStruct_hdr_recon_enStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hdr23Type::dynamic_enable_triggersStruct::hdr_recon_enStruct* structure,
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
/// Load dynamic_enable_triggersStruct_hdr_mac_enStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_hdr23TypeClass::Loaddynamic_enable_triggersStruct_hdr_mac_enStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_hdr23Type::dynamic_enable_triggersStruct::hdr_mac_enStruct* structure,
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
/// Unload mod_hdr23_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_hdr23TypeClass::Unloadmod_hdr23_hdr_aec_dataType(
    mod_hdr23_hdr_aec_dataType* structure)
{
    Unloadmod_hdr23_hdr_aec_dataType_hdr_aec_dataStruct(&structure->hdr_aec_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_hdr23_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_hdr23TypeClass::Unloadmod_hdr23_hdr_aec_dataType_hdr_aec_dataStruct(
    mod_hdr23_hdr_aec_dataType::hdr_aec_dataStruct* structure)
{
    PARAMETER_DELETE[] structure->mod_hdr23_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_hdr23_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_hdr23TypeClass::Unloadchromatix_hdr23_coreType(
    chromatix_hdr23_coreType* structure)
{
    for (UINT32 i = 0; i < structure->mod_hdr23_hdr_aec_dataCount; i++)
    {
        Unloadmod_hdr23_hdr_aec_dataType(&structure->mod_hdr23_hdr_aec_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_hdr23_hdr_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_hdr23Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_hdr23TypeClass::Unloadchromatix_hdr23Type(
    chromatix_hdr23Type* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    Unloadchromatix_hdr23_coreType(&structure->chromatix_hdr23_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_hdr23TypeClass::Unloadparameter_versionStruct(
    chromatix_hdr23Type::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatix_hdr23TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatix_hdr23TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatix_hdr23TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && Loadchromatix_hdr23Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


HDR_2_3_0_NAMESPACE_END
