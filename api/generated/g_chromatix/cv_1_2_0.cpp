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
/// @file  cv_1_2_0.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "cv_1_2_0.h"
#include "parametersetmanager.h"

CV_1_2_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_cv12TypeClass::chromatix_cv12TypeClass(
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
    PARAMETER_INITIALIZE(chromatix_cv12_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_cv12TypeClass::chromatix_cv12TypeClass(
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
    PARAMETER_INITIALIZE(chromatix_cv12_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_cv12TypeClass::~chromatix_cv12TypeClass()
{
    Unloadchromatix_cv12Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatix_cv12TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "cv12_ipe")) == 0)
    {
        name = "cv12_ipe";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load cv12_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadcv12_rgn_dataType(
    ParameterFileSymbolTableEntry* entry,
    cv12_rgn_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->r_to_y, alignment);
    result = result && entry->Read(&structure->g_to_y, alignment);
    result = result && entry->Read(&structure->b_to_y, alignment);
    result = result && entry->Read(&structure->y_offset, alignment);
    result = result && entry->Read(&structure->ap, alignment);
    result = result && entry->Read(&structure->am, alignment);
    result = result && entry->Read(&structure->bp, alignment);
    result = result && entry->Read(&structure->bm, alignment);
    result = result && entry->Read(&structure->cp, alignment);
    result = result && entry->Read(&structure->cm, alignment);
    result = result && entry->Read(&structure->dp, alignment);
    result = result && entry->Read(&structure->dm, alignment);
    result = result && entry->Read(&structure->kcr, alignment);
    result = result && entry->Read(&structure->kcb, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_cv12_cct_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadmod_cv12_cct_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_cv12_cct_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->cct_trigger, alignment);
    result = result && Loadcv12_rgn_dataType(entry, &structure->cv12_rgn_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_cv12_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadmod_cv12_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_cv12_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = globalelements::globalelementsClass::Loadtrigger_pt_type_aec(entry, &structure->aec_trigger, alignment);
    result = result && Loadmod_cv12_aec_dataType_aec_dataStruct(entry, &structure->aec_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_cv12_aec_dataType_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadmod_cv12_aec_dataType_aec_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_cv12_aec_dataType::aec_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_cv12_cct_data from symbol table
    {
        result = entry->Read(&structure->mod_cv12_cct_dataCount, alignment);
        structure->mod_cv12_cct_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_cv12_cct_data = PARAMETER_NEW mod_cv12_cct_dataType[structure->mod_cv12_cct_dataCount];
        }
        if (!result || structure->mod_cv12_cct_data == NULL)
        {
            structure->mod_cv12_cct_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_cv12_cct_dataCount; i++)
        {
            result = Loadmod_cv12_cct_dataType(pointerEntry, &structure->mod_cv12_cct_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_cv12_led_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadmod_cv12_led_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_cv12_led_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->led_trigger, alignment);
    result = result && Loadmod_cv12_led_dataType_led_dataStruct(entry, &structure->led_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_cv12_led_dataType_led_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadmod_cv12_led_dataType_led_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_cv12_led_dataType::led_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_cv12_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_cv12_aec_dataCount, alignment);
        structure->mod_cv12_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_cv12_aec_data = PARAMETER_NEW mod_cv12_aec_dataType[structure->mod_cv12_aec_dataCount];
        }
        if (!result || structure->mod_cv12_aec_data == NULL)
        {
            structure->mod_cv12_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_cv12_aec_dataCount; i++)
        {
            result = Loadmod_cv12_aec_dataType(pointerEntry, &structure->mod_cv12_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_cv12_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadmod_cv12_hdr_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_cv12_hdr_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type_aec_hdr(entry, &structure->hdr_aec_trigger, alignment);
    result = result && Loadmod_cv12_hdr_aec_dataType_hdr_aec_dataStruct(entry, &structure->hdr_aec_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_cv12_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadmod_cv12_hdr_aec_dataType_hdr_aec_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_cv12_hdr_aec_dataType::hdr_aec_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_cv12_led_data from symbol table
    {
        result = entry->Read(&structure->mod_cv12_led_dataCount, alignment);
        structure->mod_cv12_led_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_cv12_led_data = PARAMETER_NEW mod_cv12_led_dataType[structure->mod_cv12_led_dataCount];
        }
        if (!result || structure->mod_cv12_led_data == NULL)
        {
            structure->mod_cv12_led_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_cv12_led_dataCount; i++)
        {
            result = Loadmod_cv12_led_dataType(pointerEntry, &structure->mod_cv12_led_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_cv12_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadmod_cv12_drc_gain_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_cv12_drc_gain_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->drc_gain_trigger, alignment);
    result = result && Loadmod_cv12_drc_gain_dataType_drc_gain_dataStruct(entry, &structure->drc_gain_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_cv12_drc_gain_dataType_drc_gain_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadmod_cv12_drc_gain_dataType_drc_gain_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_cv12_drc_gain_dataType::drc_gain_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_cv12_hdr_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_cv12_hdr_aec_dataCount, alignment);
        structure->mod_cv12_hdr_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_cv12_hdr_aec_data = PARAMETER_NEW mod_cv12_hdr_aec_dataType[structure->mod_cv12_hdr_aec_dataCount];
        }
        if (!result || structure->mod_cv12_hdr_aec_data == NULL)
        {
            structure->mod_cv12_hdr_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_cv12_hdr_aec_dataCount; i++)
        {
            result = Loadmod_cv12_hdr_aec_dataType(pointerEntry, &structure->mod_cv12_hdr_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_cv12_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadchromatix_cv12_coreType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cv12_coreType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_cv12_drc_gain_data from symbol table
    {
        result = entry->Read(&structure->mod_cv12_drc_gain_dataCount, alignment);
        structure->mod_cv12_drc_gain_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_cv12_drc_gain_data = PARAMETER_NEW mod_cv12_drc_gain_dataType[structure->mod_cv12_drc_gain_dataCount];
        }
        if (!result || structure->mod_cv12_drc_gain_data == NULL)
        {
            structure->mod_cv12_drc_gain_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_cv12_drc_gain_dataCount; i++)
        {
            result = Loadmod_cv12_drc_gain_dataType(pointerEntry, &structure->mod_cv12_drc_gain_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_cv12Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadchromatix_cv12Type(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cv12Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadenable_sectionStruct(entry, &structure->enable_section, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && Loadcontrol_variablesStruct(entry, &structure->control_variables, alignment);
    result = result && Loadcontrol_methodStruct(entry, &structure->control_method, alignment);
    result = result && Loadprivate_informationStruct(entry, &structure->private_information, alignment);
    result = result && Loadchromatix_cv12_coreType(entry, &structure->chromatix_cv12_core, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load enable_sectionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadenable_sectionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cv12Type::enable_sectionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->cv_enable, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cv12Type::module_versionStruct* structure,
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
BOOL chromatix_cv12TypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cv12Type::parameter_versionStruct* structure,
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
BOOL chromatix_cv12TypeClass::Loadcontrol_variablesStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cv12Type::control_variablesStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    for (UINT32 i = 0; result && i < 5; i++)
    {
        structure->control_var_type[i] = (chromatix_cv12Type::control_variablesStruct::control_var_typeEnum)entry->ReadEnum(&result, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load control_methodStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cv12TypeClass::Loadcontrol_methodStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cv12Type::control_methodStruct* structure,
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
BOOL chromatix_cv12TypeClass::Loadprivate_informationStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cv12Type::private_informationStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->led_sensitivity_trigger, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_cv12_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cv12TypeClass::Unloadmod_cv12_aec_dataType(
    mod_cv12_aec_dataType* structure)
{
    Unloadmod_cv12_aec_dataType_aec_dataStruct(&structure->aec_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_cv12_aec_dataType_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cv12TypeClass::Unloadmod_cv12_aec_dataType_aec_dataStruct(
    mod_cv12_aec_dataType::aec_dataStruct* structure)
{
    PARAMETER_DELETE[] structure->mod_cv12_cct_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_cv12_led_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cv12TypeClass::Unloadmod_cv12_led_dataType(
    mod_cv12_led_dataType* structure)
{
    Unloadmod_cv12_led_dataType_led_dataStruct(&structure->led_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_cv12_led_dataType_led_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cv12TypeClass::Unloadmod_cv12_led_dataType_led_dataStruct(
    mod_cv12_led_dataType::led_dataStruct* structure)
{
    for (UINT32 i = 0; i < structure->mod_cv12_aec_dataCount; i++)
    {
        Unloadmod_cv12_aec_dataType(&structure->mod_cv12_aec_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_cv12_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_cv12_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cv12TypeClass::Unloadmod_cv12_hdr_aec_dataType(
    mod_cv12_hdr_aec_dataType* structure)
{
    Unloadmod_cv12_hdr_aec_dataType_hdr_aec_dataStruct(&structure->hdr_aec_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_cv12_hdr_aec_dataType_hdr_aec_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cv12TypeClass::Unloadmod_cv12_hdr_aec_dataType_hdr_aec_dataStruct(
    mod_cv12_hdr_aec_dataType::hdr_aec_dataStruct* structure)
{
    for (UINT32 i = 0; i < structure->mod_cv12_led_dataCount; i++)
    {
        Unloadmod_cv12_led_dataType(&structure->mod_cv12_led_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_cv12_led_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_cv12_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cv12TypeClass::Unloadmod_cv12_drc_gain_dataType(
    mod_cv12_drc_gain_dataType* structure)
{
    Unloadmod_cv12_drc_gain_dataType_drc_gain_dataStruct(&structure->drc_gain_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_cv12_drc_gain_dataType_drc_gain_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cv12TypeClass::Unloadmod_cv12_drc_gain_dataType_drc_gain_dataStruct(
    mod_cv12_drc_gain_dataType::drc_gain_dataStruct* structure)
{
    for (UINT32 i = 0; i < structure->mod_cv12_hdr_aec_dataCount; i++)
    {
        Unloadmod_cv12_hdr_aec_dataType(&structure->mod_cv12_hdr_aec_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_cv12_hdr_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_cv12_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cv12TypeClass::Unloadchromatix_cv12_coreType(
    chromatix_cv12_coreType* structure)
{
    for (UINT32 i = 0; i < structure->mod_cv12_drc_gain_dataCount; i++)
    {
        Unloadmod_cv12_drc_gain_dataType(&structure->mod_cv12_drc_gain_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_cv12_drc_gain_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_cv12Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cv12TypeClass::Unloadchromatix_cv12Type(
    chromatix_cv12Type* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    Unloadchromatix_cv12_coreType(&structure->chromatix_cv12_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cv12TypeClass::Unloadparameter_versionStruct(
    chromatix_cv12Type::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatix_cv12TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatix_cv12TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatix_cv12TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && Loadchromatix_cv12Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


CV_1_2_0_NAMESPACE_END
