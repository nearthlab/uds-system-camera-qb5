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
/// @file  cac_2_2_0.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "cac_2_2_0.h"
#include "parametersetmanager.h"

CAC_2_2_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_cac22TypeClass::chromatix_cac22TypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(enable_section);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(control_variables);
    PARAMETER_INITIALIZE(control_method);
    PARAMETER_INITIALIZE(chromatix_cac22_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_cac22TypeClass::chromatix_cac22TypeClass(
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
    PARAMETER_INITIALIZE(chromatix_cac22_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_cac22TypeClass::~chromatix_cac22TypeClass()
{
    Unloadchromatix_cac22Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatix_cac22TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "cac22_ipe")) == 0)
    {
        name = "cac22_ipe";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load cac22_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cac22TypeClass::Loadcac22_rgn_dataType(
    ParameterFileSymbolTableEntry* entry,
    cac22_rgn_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->cac_en, alignment);
    result = result && entry->Read(&structure->y_spot_thr, alignment);
    result = result && entry->Read(&structure->y_saturation_thr, alignment);
    result = result && entry->Read(&structure->c_spot_thr, alignment);
    result = result && entry->Read(&structure->c_saturation_thr, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_cac22_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cac22TypeClass::Loadmod_cac22_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_cac22_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = globalelements::globalelementsClass::Loadtrigger_pt_type_aec(entry, &structure->aec_trigger, alignment);
    result = result && Loadcac22_rgn_dataType(entry, &structure->cac22_rgn_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_cac22_total_scale_ratio_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cac22TypeClass::Loadmod_cac22_total_scale_ratio_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_cac22_total_scale_ratio_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->total_scale_ratio_trigger, alignment);
    result = result && Loadmod_cac22_total_scale_ratio_dataType_total_scale_ratio_dataStruct(entry, &structure->total_scale_ratio_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_cac22_total_scale_ratio_dataType_total_scale_ratio_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cac22TypeClass::Loadmod_cac22_total_scale_ratio_dataType_total_scale_ratio_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_cac22_total_scale_ratio_dataType::total_scale_ratio_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_cac22_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_cac22_aec_dataCount, alignment);
        structure->mod_cac22_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_cac22_aec_data = PARAMETER_NEW mod_cac22_aec_dataType[structure->mod_cac22_aec_dataCount];
        }
        if (!result || structure->mod_cac22_aec_data == NULL)
        {
            structure->mod_cac22_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_cac22_aec_dataCount; i++)
        {
            result = Loadmod_cac22_aec_dataType(pointerEntry, &structure->mod_cac22_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_cac22_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cac22TypeClass::Loadchromatix_cac22_coreType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cac22_coreType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_cac22_total_scale_ratio_data from symbol table
    {
        result = entry->Read(&structure->mod_cac22_total_scale_ratio_dataCount, alignment);
        structure->mod_cac22_total_scale_ratio_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_cac22_total_scale_ratio_data = PARAMETER_NEW mod_cac22_total_scale_ratio_dataType[structure->mod_cac22_total_scale_ratio_dataCount];
        }
        if (!result || structure->mod_cac22_total_scale_ratio_data == NULL)
        {
            structure->mod_cac22_total_scale_ratio_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_cac22_total_scale_ratio_dataCount; i++)
        {
            result = Loadmod_cac22_total_scale_ratio_dataType(pointerEntry, &structure->mod_cac22_total_scale_ratio_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_cac22Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cac22TypeClass::Loadchromatix_cac22Type(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cac22Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadenable_sectionStruct(entry, &structure->enable_section, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && Loadcontrol_variablesStruct(entry, &structure->control_variables, alignment);
    result = result && Loadcontrol_methodStruct(entry, &structure->control_method, alignment);
    result = result && Loadchromatix_cac22_coreType(entry, &structure->chromatix_cac22_core, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load enable_sectionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cac22TypeClass::Loadenable_sectionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cac22Type::enable_sectionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->cac_global_enable, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cac22TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cac22Type::module_versionStruct* structure,
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
BOOL chromatix_cac22TypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cac22Type::parameter_versionStruct* structure,
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
BOOL chromatix_cac22TypeClass::Loadcontrol_variablesStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cac22Type::control_variablesStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    for (UINT32 i = 0; result && i < 2; i++)
    {
        structure->control_var_type[i] = (chromatix_cac22Type::control_variablesStruct::control_var_typeEnum)entry->ReadEnum(&result, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load control_methodStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_cac22TypeClass::Loadcontrol_methodStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_cac22Type::control_methodStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    structure->aec_exp_control = (ispglobalelements::tuning_control_aec_type)entry->ReadEnum(&result, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_cac22_total_scale_ratio_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cac22TypeClass::Unloadmod_cac22_total_scale_ratio_dataType(
    mod_cac22_total_scale_ratio_dataType* structure)
{
    Unloadmod_cac22_total_scale_ratio_dataType_total_scale_ratio_dataStruct(&structure->total_scale_ratio_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_cac22_total_scale_ratio_dataType_total_scale_ratio_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cac22TypeClass::Unloadmod_cac22_total_scale_ratio_dataType_total_scale_ratio_dataStruct(
    mod_cac22_total_scale_ratio_dataType::total_scale_ratio_dataStruct* structure)
{
    PARAMETER_DELETE[] structure->mod_cac22_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_cac22_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cac22TypeClass::Unloadchromatix_cac22_coreType(
    chromatix_cac22_coreType* structure)
{
    for (UINT32 i = 0; i < structure->mod_cac22_total_scale_ratio_dataCount; i++)
    {
        Unloadmod_cac22_total_scale_ratio_dataType(&structure->mod_cac22_total_scale_ratio_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_cac22_total_scale_ratio_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_cac22Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cac22TypeClass::Unloadchromatix_cac22Type(
    chromatix_cac22Type* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    Unloadchromatix_cac22_coreType(&structure->chromatix_cac22_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_cac22TypeClass::Unloadparameter_versionStruct(
    chromatix_cac22Type::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatix_cac22TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatix_cac22TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatix_cac22TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && Loadchromatix_cac22Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


CAC_2_2_0_NAMESPACE_END
