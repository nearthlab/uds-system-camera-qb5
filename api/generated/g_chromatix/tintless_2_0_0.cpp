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
/// @file  tintless_2_0_0.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "tintless_2_0_0.h"
#include "parametersetmanager.h"

TINTLESS_2_0_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_tintless20TypeClass::chromatix_tintless20TypeClass(
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
    PARAMETER_INITIALIZE(chromatix_tintless20_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_tintless20TypeClass::chromatix_tintless20TypeClass(
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
    PARAMETER_INITIALIZE(chromatix_tintless20_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_tintless20TypeClass::~chromatix_tintless20TypeClass()
{
    Unloadchromatix_tintless20Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatix_tintless20TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "tintless20_sw")) == 0)
    {
        name = "tintless20_sw";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load tintless20_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tintless20TypeClass::Loadtintless20_rgn_dataType(
    ParameterFileSymbolTableEntry* entry,
    tintless20_rgn_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadtintless20_rgn_dataType_tintless_threshold_tabStruct(entry, &structure->tintless_threshold_tab, alignment);
    result = result && entry->Read(&structure->tintless_high_accuracy_mode, alignment);
    result = result && entry->Read(&structure->tintless_update_delay, alignment);
    result = result && entry->Read(&structure->tintless_trace_percentage, alignment);
    result = result && entry->Read(&structure->center_weight, alignment);
    result = result && entry->Read(&structure->corner_weight, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load tintless20_rgn_dataType_tintless_threshold_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tintless20TypeClass::Loadtintless20_rgn_dataType_tintless_threshold_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    tintless20_rgn_dataType::tintless_threshold_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->tintless_threshold, 16, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_tintless20_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tintless20TypeClass::Loadmod_tintless20_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_tintless20_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = globalelements::globalelementsClass::Loadtrigger_pt_type_aec(entry, &structure->aec_trigger, alignment);
    result = result && Loadtintless20_rgn_dataType(entry, &structure->tintless20_rgn_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_tintless20_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tintless20TypeClass::Loadmod_tintless20_hdr_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_tintless20_hdr_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type_aec_hdr(entry, &structure->hdr_aec_trigger, alignment);
    result = result && Loadmod_tintless20_hdr_aec_dataType_hdr_aec_dataStruct(entry, &structure->hdr_aec_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_tintless20_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tintless20TypeClass::Loadmod_tintless20_hdr_aec_dataType_hdr_aec_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_tintless20_hdr_aec_dataType::hdr_aec_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_tintless20_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_tintless20_aec_dataCount, alignment);
        structure->mod_tintless20_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_tintless20_aec_data = PARAMETER_NEW mod_tintless20_aec_dataType[structure->mod_tintless20_aec_dataCount];
        }
        if (!result || structure->mod_tintless20_aec_data == NULL)
        {
            structure->mod_tintless20_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_tintless20_aec_dataCount; i++)
        {
            result = Loadmod_tintless20_aec_dataType(pointerEntry, &structure->mod_tintless20_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_tintless20_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tintless20TypeClass::Loadchromatix_tintless20_coreType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tintless20_coreType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_tintless20_hdr_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_tintless20_hdr_aec_dataCount, alignment);
        structure->mod_tintless20_hdr_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_tintless20_hdr_aec_data = PARAMETER_NEW mod_tintless20_hdr_aec_dataType[structure->mod_tintless20_hdr_aec_dataCount];
        }
        if (!result || structure->mod_tintless20_hdr_aec_data == NULL)
        {
            structure->mod_tintless20_hdr_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_tintless20_hdr_aec_dataCount; i++)
        {
            result = Loadmod_tintless20_hdr_aec_dataType(pointerEntry, &structure->mod_tintless20_hdr_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_tintless20Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tintless20TypeClass::Loadchromatix_tintless20Type(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tintless20Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadenable_sectionStruct(entry, &structure->enable_section, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && Loadcontrol_variablesStruct(entry, &structure->control_variables, alignment);
    result = result && Loadcontrol_methodStruct(entry, &structure->control_method, alignment);
    result = result && Loaddynamic_enable_triggersStruct(entry, &structure->dynamic_enable_triggers, alignment);
    result = result && Loadchromatix_tintless20_coreType(entry, &structure->chromatix_tintless20_core, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load enable_sectionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tintless20TypeClass::Loadenable_sectionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tintless20Type::enable_sectionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->tintless_en, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tintless20TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tintless20Type::module_versionStruct* structure,
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
BOOL chromatix_tintless20TypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tintless20Type::parameter_versionStruct* structure,
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
BOOL chromatix_tintless20TypeClass::Loadcontrol_variablesStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tintless20Type::control_variablesStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    for (UINT32 i = 0; result && i < 2; i++)
    {
        structure->control_var_type[i] = (chromatix_tintless20Type::control_variablesStruct::control_var_typeEnum)entry->ReadEnum(&result, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load control_methodStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tintless20TypeClass::Loadcontrol_methodStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tintless20Type::control_methodStruct* structure,
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
BOOL chromatix_tintless20TypeClass::Loaddynamic_enable_triggersStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tintless20Type::dynamic_enable_triggersStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loaddynamic_enable_triggersStruct_tintless_enStruct(entry, &structure->tintless_en, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dynamic_enable_triggersStruct_tintless_enStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_tintless20TypeClass::Loaddynamic_enable_triggersStruct_tintless_enStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_tintless20Type::dynamic_enable_triggersStruct::tintless_enStruct* structure,
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
/// Unload mod_tintless20_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_tintless20TypeClass::Unloadmod_tintless20_hdr_aec_dataType(
    mod_tintless20_hdr_aec_dataType* structure)
{
    Unloadmod_tintless20_hdr_aec_dataType_hdr_aec_dataStruct(&structure->hdr_aec_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_tintless20_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_tintless20TypeClass::Unloadmod_tintless20_hdr_aec_dataType_hdr_aec_dataStruct(
    mod_tintless20_hdr_aec_dataType::hdr_aec_dataStruct* structure)
{
    PARAMETER_DELETE[] structure->mod_tintless20_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_tintless20_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_tintless20TypeClass::Unloadchromatix_tintless20_coreType(
    chromatix_tintless20_coreType* structure)
{
    for (UINT32 i = 0; i < structure->mod_tintless20_hdr_aec_dataCount; i++)
    {
        Unloadmod_tintless20_hdr_aec_dataType(&structure->mod_tintless20_hdr_aec_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_tintless20_hdr_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_tintless20Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_tintless20TypeClass::Unloadchromatix_tintless20Type(
    chromatix_tintless20Type* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    Unloadchromatix_tintless20_coreType(&structure->chromatix_tintless20_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_tintless20TypeClass::Unloadparameter_versionStruct(
    chromatix_tintless20Type::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatix_tintless20TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatix_tintless20TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatix_tintless20TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && Loadchromatix_tintless20Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


TINTLESS_2_0_0_NAMESPACE_END