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
/// @file  gamma_1_6_0.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gamma_1_6_0.h"
#include "parametersetmanager.h"

GAMMA_1_6_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_gamma16TypeClass::chromatix_gamma16TypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(enable_section);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(control_variables);
    PARAMETER_INITIALIZE(control_method);
    PARAMETER_INITIALIZE(private_information);
    PARAMETER_INITIALIZE(chromatix_gamma16_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_gamma16TypeClass::chromatix_gamma16TypeClass(
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
    PARAMETER_INITIALIZE(private_information);
    PARAMETER_INITIALIZE(chromatix_gamma16_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_gamma16TypeClass::~chromatix_gamma16TypeClass()
{
    Unloadchromatix_gamma16Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatix_gamma16TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "gamma16_bps")) == 0)
    {
        name = "gamma16_bps";
    }
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "gamma16_ife")) == 0)
    {
        name = "gamma16_ife";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load gamma16_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadgamma16_rgn_dataType(
    ParameterFileSymbolTableEntry* entry,
    gamma16_rgn_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->table, 65, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_gamma16_channel_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadmod_gamma16_channel_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_gamma16_channel_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    structure->channel_type = (ispglobalelements::channel_rgb_type)entry->ReadEnum(&result, alignment);
    result = result && Loadgamma16_rgn_dataType(entry, &structure->gamma16_rgn_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_gamma16_cct_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadmod_gamma16_cct_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_gamma16_cct_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->cct_trigger, alignment);
    result = result && Loadmod_gamma16_cct_dataType_cct_dataStruct(entry, &structure->cct_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_gamma16_cct_dataType_cct_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadmod_gamma16_cct_dataType_cct_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_gamma16_cct_dataType::cct_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_gamma16_channel_data from symbol table
    {
        result = entry->Read(&structure->mod_gamma16_channel_dataCount, alignment);
        structure->mod_gamma16_channel_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_gamma16_channel_data = PARAMETER_NEW mod_gamma16_channel_dataType[structure->mod_gamma16_channel_dataCount];
        }
        if (!result || structure->mod_gamma16_channel_data == NULL)
        {
            structure->mod_gamma16_channel_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_gamma16_channel_dataCount; i++)
        {
            result = Loadmod_gamma16_channel_dataType(pointerEntry, &structure->mod_gamma16_channel_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_gamma16_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadmod_gamma16_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_gamma16_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = globalelements::globalelementsClass::Loadtrigger_pt_type_aec(entry, &structure->aec_trigger, alignment);
    result = result && Loadmod_gamma16_aec_dataType_aec_dataStruct(entry, &structure->aec_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_gamma16_aec_dataType_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadmod_gamma16_aec_dataType_aec_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_gamma16_aec_dataType::aec_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_gamma16_cct_data from symbol table
    {
        result = entry->Read(&structure->mod_gamma16_cct_dataCount, alignment);
        structure->mod_gamma16_cct_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_gamma16_cct_data = PARAMETER_NEW mod_gamma16_cct_dataType[structure->mod_gamma16_cct_dataCount];
        }
        if (!result || structure->mod_gamma16_cct_data == NULL)
        {
            structure->mod_gamma16_cct_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_gamma16_cct_dataCount; i++)
        {
            result = Loadmod_gamma16_cct_dataType(pointerEntry, &structure->mod_gamma16_cct_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_gamma16_led_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadmod_gamma16_led_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_gamma16_led_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->led_idx_trigger, alignment);
    result = result && Loadmod_gamma16_led_dataType_led_idx_dataStruct(entry, &structure->led_idx_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_gamma16_led_dataType_led_idx_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadmod_gamma16_led_dataType_led_idx_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_gamma16_led_dataType::led_idx_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_gamma16_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_gamma16_aec_dataCount, alignment);
        structure->mod_gamma16_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_gamma16_aec_data = PARAMETER_NEW mod_gamma16_aec_dataType[structure->mod_gamma16_aec_dataCount];
        }
        if (!result || structure->mod_gamma16_aec_data == NULL)
        {
            structure->mod_gamma16_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_gamma16_aec_dataCount; i++)
        {
            result = Loadmod_gamma16_aec_dataType(pointerEntry, &structure->mod_gamma16_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_gamma16_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadmod_gamma16_hdr_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_gamma16_hdr_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type_aec_hdr(entry, &structure->hdr_aec_trigger, alignment);
    result = result && Loadmod_gamma16_hdr_aec_dataType_hdr_aec_dataStruct(entry, &structure->hdr_aec_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_gamma16_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadmod_gamma16_hdr_aec_dataType_hdr_aec_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_gamma16_hdr_aec_dataType::hdr_aec_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_gamma16_led_idx_data from symbol table
    {
        result = entry->Read(&structure->mod_gamma16_led_idx_dataCount, alignment);
        structure->mod_gamma16_led_idx_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_gamma16_led_idx_data = PARAMETER_NEW mod_gamma16_led_dataType[structure->mod_gamma16_led_idx_dataCount];
        }
        if (!result || structure->mod_gamma16_led_idx_data == NULL)
        {
            structure->mod_gamma16_led_idx_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_gamma16_led_idx_dataCount; i++)
        {
            result = Loadmod_gamma16_led_dataType(pointerEntry, &structure->mod_gamma16_led_idx_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_gamma16_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadmod_gamma16_drc_gain_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_gamma16_drc_gain_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->drc_gain_trigger, alignment);
    result = result && Loadmod_gamma16_drc_gain_dataType_drc_gain_dataStruct(entry, &structure->drc_gain_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_gamma16_drc_gain_dataType_drc_gain_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadmod_gamma16_drc_gain_dataType_drc_gain_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_gamma16_drc_gain_dataType::drc_gain_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_gamma16_hdr_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_gamma16_hdr_aec_dataCount, alignment);
        structure->mod_gamma16_hdr_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_gamma16_hdr_aec_data = PARAMETER_NEW mod_gamma16_hdr_aec_dataType[structure->mod_gamma16_hdr_aec_dataCount];
        }
        if (!result || structure->mod_gamma16_hdr_aec_data == NULL)
        {
            structure->mod_gamma16_hdr_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_gamma16_hdr_aec_dataCount; i++)
        {
            result = Loadmod_gamma16_hdr_aec_dataType(pointerEntry, &structure->mod_gamma16_hdr_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_gamma16_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadchromatix_gamma16_coreType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_gamma16_coreType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_gamma16_drc_gain_data from symbol table
    {
        result = entry->Read(&structure->mod_gamma16_drc_gain_dataCount, alignment);
        structure->mod_gamma16_drc_gain_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_gamma16_drc_gain_data = PARAMETER_NEW mod_gamma16_drc_gain_dataType[structure->mod_gamma16_drc_gain_dataCount];
        }
        if (!result || structure->mod_gamma16_drc_gain_data == NULL)
        {
            structure->mod_gamma16_drc_gain_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_gamma16_drc_gain_dataCount; i++)
        {
            result = Loadmod_gamma16_drc_gain_dataType(pointerEntry, &structure->mod_gamma16_drc_gain_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_gamma16Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadchromatix_gamma16Type(
    ParameterFileSymbolTableEntry* entry,
    chromatix_gamma16Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadenable_sectionStruct(entry, &structure->enable_section, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && Loadcontrol_variablesStruct(entry, &structure->control_variables, alignment);
    result = result && Loadcontrol_methodStruct(entry, &structure->control_method, alignment);
    result = result && Loadprivate_informationStruct(entry, &structure->private_information, alignment);
    result = result && Loadchromatix_gamma16_coreType(entry, &structure->chromatix_gamma16_core, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load enable_sectionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadenable_sectionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_gamma16Type::enable_sectionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->gamma_enable, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_gamma16Type::module_versionStruct* structure,
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
BOOL chromatix_gamma16TypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_gamma16Type::parameter_versionStruct* structure,
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
BOOL chromatix_gamma16TypeClass::Loadcontrol_variablesStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_gamma16Type::control_variablesStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    for (UINT32 i = 0; result && i < 5; i++)
    {
        structure->control_var_type[i] = (chromatix_gamma16Type::control_variablesStruct::control_var_typeEnum)entry->ReadEnum(&result, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load control_methodStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadcontrol_methodStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_gamma16Type::control_methodStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    structure->aec_exp_control = (ispglobalelements::tuning_control_aec_type)entry->ReadEnum(&result, alignment);
    structure->aec_hdr_control = (ispglobalelements::tuning_control_aec_hdr_type)entry->ReadEnum(&result, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load private_informationStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_gamma16TypeClass::Loadprivate_informationStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_gamma16Type::private_informationStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->led_sensitivity_trigger, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_gamma16_cct_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_gamma16TypeClass::Unloadmod_gamma16_cct_dataType(
    mod_gamma16_cct_dataType* structure)
{
    Unloadmod_gamma16_cct_dataType_cct_dataStruct(&structure->cct_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_gamma16_cct_dataType_cct_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_gamma16TypeClass::Unloadmod_gamma16_cct_dataType_cct_dataStruct(
    mod_gamma16_cct_dataType::cct_dataStruct* structure)
{
    PARAMETER_DELETE[] structure->mod_gamma16_channel_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_gamma16_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_gamma16TypeClass::Unloadmod_gamma16_aec_dataType(
    mod_gamma16_aec_dataType* structure)
{
    Unloadmod_gamma16_aec_dataType_aec_dataStruct(&structure->aec_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_gamma16_aec_dataType_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_gamma16TypeClass::Unloadmod_gamma16_aec_dataType_aec_dataStruct(
    mod_gamma16_aec_dataType::aec_dataStruct* structure)
{
    for (UINT32 i = 0; i < structure->mod_gamma16_cct_dataCount; i++)
    {
        Unloadmod_gamma16_cct_dataType(&structure->mod_gamma16_cct_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_gamma16_cct_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_gamma16_led_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_gamma16TypeClass::Unloadmod_gamma16_led_dataType(
    mod_gamma16_led_dataType* structure)
{
    Unloadmod_gamma16_led_dataType_led_idx_dataStruct(&structure->led_idx_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_gamma16_led_dataType_led_idx_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_gamma16TypeClass::Unloadmod_gamma16_led_dataType_led_idx_dataStruct(
    mod_gamma16_led_dataType::led_idx_dataStruct* structure)
{
    for (UINT32 i = 0; i < structure->mod_gamma16_aec_dataCount; i++)
    {
        Unloadmod_gamma16_aec_dataType(&structure->mod_gamma16_aec_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_gamma16_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_gamma16_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_gamma16TypeClass::Unloadmod_gamma16_hdr_aec_dataType(
    mod_gamma16_hdr_aec_dataType* structure)
{
    Unloadmod_gamma16_hdr_aec_dataType_hdr_aec_dataStruct(&structure->hdr_aec_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_gamma16_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_gamma16TypeClass::Unloadmod_gamma16_hdr_aec_dataType_hdr_aec_dataStruct(
    mod_gamma16_hdr_aec_dataType::hdr_aec_dataStruct* structure)
{
    for (UINT32 i = 0; i < structure->mod_gamma16_led_idx_dataCount; i++)
    {
        Unloadmod_gamma16_led_dataType(&structure->mod_gamma16_led_idx_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_gamma16_led_idx_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_gamma16_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_gamma16TypeClass::Unloadmod_gamma16_drc_gain_dataType(
    mod_gamma16_drc_gain_dataType* structure)
{
    Unloadmod_gamma16_drc_gain_dataType_drc_gain_dataStruct(&structure->drc_gain_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_gamma16_drc_gain_dataType_drc_gain_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_gamma16TypeClass::Unloadmod_gamma16_drc_gain_dataType_drc_gain_dataStruct(
    mod_gamma16_drc_gain_dataType::drc_gain_dataStruct* structure)
{
    for (UINT32 i = 0; i < structure->mod_gamma16_hdr_aec_dataCount; i++)
    {
        Unloadmod_gamma16_hdr_aec_dataType(&structure->mod_gamma16_hdr_aec_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_gamma16_hdr_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_gamma16_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_gamma16TypeClass::Unloadchromatix_gamma16_coreType(
    chromatix_gamma16_coreType* structure)
{
    for (UINT32 i = 0; i < structure->mod_gamma16_drc_gain_dataCount; i++)
    {
        Unloadmod_gamma16_drc_gain_dataType(&structure->mod_gamma16_drc_gain_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_gamma16_drc_gain_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_gamma16Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_gamma16TypeClass::Unloadchromatix_gamma16Type(
    chromatix_gamma16Type* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    Unloadchromatix_gamma16_coreType(&structure->chromatix_gamma16_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_gamma16TypeClass::Unloadparameter_versionStruct(
    chromatix_gamma16Type::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatix_gamma16TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatix_gamma16TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatix_gamma16TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && Loadchromatix_gamma16Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


GAMMA_1_6_0_NAMESPACE_END
