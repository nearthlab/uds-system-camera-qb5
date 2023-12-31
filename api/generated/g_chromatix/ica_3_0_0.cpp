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
/// @file  ica_3_0_0.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "ica_3_0_0.h"
#include "parametersetmanager.h"

ICA_3_0_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_ica30TypeClass::chromatix_ica30TypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(enable_section);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(control_variables);
    PARAMETER_INITIALIZE(control_method);
    PARAMETER_INITIALIZE(chromatix_ica30_reserve);
    PARAMETER_INITIALIZE(chromatix_ica30_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_ica30TypeClass::chromatix_ica30TypeClass(
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
    PARAMETER_INITIALIZE(chromatix_ica30_reserve);
    PARAMETER_INITIALIZE(chromatix_ica30_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_ica30TypeClass::~chromatix_ica30TypeClass()
{
    Unloadchromatix_ica30Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatix_ica30TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "ica30_ipe_module1")) == 0)
    {
        name = "ica30_ipe_module1";
    }
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "ica30_ipe_module2")) == 0)
    {
        name = "ica30_ipe_module2";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_ica30_reserveType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadchromatix_ica30_reserveType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica30_reserveType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->ctc_grid_transform_geometry, alignment);
    result = result && entry->Read(&structure->opg_invalid_output_treatment_calculate, alignment);
    result = result && entry->Read(&structure->opg_invalid_output_treatment_y, alignment);
    result = result && entry->Read(&structure->opg_invalid_output_treatment_cb, alignment);
    result = result && entry->Read(&structure->opg_invalid_output_treatment_cr, alignment);
    result = result && entry->Read(&structure->ld_u2i_grid_valid, alignment);
    result = result && entry->Read(&structure->ld_i2u_grid_valid, alignment);
    result = result && entry->Read(&structure->ld_i2u_grid_geometry, alignment);
    result = result && entry->Read(&structure->ld_full_out_width, alignment);
    result = result && entry->Read(&structure->ld_full_out_height, alignment);
    result = result && entry->Read(&structure->ldc_model_type, alignment);
    result = result && Loadchromatix_ica30_reserveType_model_parameters_tabStruct(entry, &structure->model_parameters_tab, alignment);
    result = result && entry->Read(&structure->focal_length_x, alignment);
    result = result && entry->Read(&structure->focal_length_y, alignment);
    result = result && entry->Read(&structure->optical_center_x, alignment);
    result = result && entry->Read(&structure->optical_center_y, alignment);
    result = result && entry->Read(&structure->image_size_distorted_x, alignment);
    result = result && entry->Read(&structure->image_size_distorted_y, alignment);
    result = result && entry->Read(&structure->res_param_1, alignment);
    result = result && entry->Read(&structure->res_param_2, alignment);
    result = result && entry->Read(&structure->res_param_3, alignment);
    result = result && entry->Read(&structure->res_param_4, alignment);
    result = result && entry->Read(&structure->res_param_5, alignment);
    result = result && entry->Read(&structure->res_param_6, alignment);
    result = result && entry->Read(&structure->res_param_7, alignment);
    result = result && entry->Read(&structure->res_param_8, alignment);
    result = result && entry->Read(&structure->res_param_9, alignment);
    result = result && entry->Read(&structure->res_param_10, alignment);
    result = result && Loadchromatix_ica30_reserveType_res_lut_param_1_tabStruct(entry, &structure->res_lut_param_1_tab, alignment);
    result = result && Loadchromatix_ica30_reserveType_res_lut_param_2_tabStruct(entry, &structure->res_lut_param_2_tab, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_ica30_reserveType_model_parameters_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadchromatix_ica30_reserveType_model_parameters_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica30_reserveType::model_parameters_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->model_parameters, 32, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_ica30_reserveType_res_lut_param_1_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadchromatix_ica30_reserveType_res_lut_param_1_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica30_reserveType::res_lut_param_1_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->res_lut_param_1, 32, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_ica30_reserveType_res_lut_param_2_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadchromatix_ica30_reserveType_res_lut_param_2_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica30_reserveType::res_lut_param_2_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->res_lut_param_2, 32, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica30_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadica30_rgn_dataType(
    ParameterFileSymbolTableEntry* entry,
    ica30_rgn_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->y_interpolation_type, alignment);
    result = result && Loadica30_rgn_dataType_ctc_grid_x_tabStruct(entry, &structure->ctc_grid_x_tab, alignment);
    result = result && Loadica30_rgn_dataType_ctc_grid_y_tabStruct(entry, &structure->ctc_grid_y_tab, alignment);
    result = result && Loadica30_rgn_dataType_opg_interpolation_lut_0_tabStruct(entry, &structure->opg_interpolation_lut_0_tab, alignment);
    result = result && Loadica30_rgn_dataType_opg_interpolation_lut_1_tabStruct(entry, &structure->opg_interpolation_lut_1_tab, alignment);
    result = result && Loadica30_rgn_dataType_opg_interpolation_lut_2_tabStruct(entry, &structure->opg_interpolation_lut_2_tab, alignment);
    result = result && Loadica30_rgn_dataType_ld_i2u_grid_x_tabStruct(entry, &structure->ld_i2u_grid_x_tab, alignment);
    result = result && Loadica30_rgn_dataType_ld_i2u_grid_y_tabStruct(entry, &structure->ld_i2u_grid_y_tab, alignment);
    result = result && entry->Read(&structure->ldc_calib_domain, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica30_rgn_dataType_ctc_grid_x_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadica30_rgn_dataType_ctc_grid_x_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica30_rgn_dataType::ctc_grid_x_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->ctc_grid_x, 3417, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica30_rgn_dataType_ctc_grid_y_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadica30_rgn_dataType_ctc_grid_y_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica30_rgn_dataType::ctc_grid_y_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->ctc_grid_y, 3417, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica30_rgn_dataType_opg_interpolation_lut_0_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadica30_rgn_dataType_opg_interpolation_lut_0_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica30_rgn_dataType::opg_interpolation_lut_0_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->opg_interpolation_lut_0, 16, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica30_rgn_dataType_opg_interpolation_lut_1_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadica30_rgn_dataType_opg_interpolation_lut_1_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica30_rgn_dataType::opg_interpolation_lut_1_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->opg_interpolation_lut_1, 16, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica30_rgn_dataType_opg_interpolation_lut_2_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadica30_rgn_dataType_opg_interpolation_lut_2_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica30_rgn_dataType::opg_interpolation_lut_2_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->opg_interpolation_lut_2, 16, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica30_rgn_dataType_ld_i2u_grid_x_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadica30_rgn_dataType_ld_i2u_grid_x_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica30_rgn_dataType::ld_i2u_grid_x_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->ld_i2u_grid_x, 3417, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica30_rgn_dataType_ld_i2u_grid_y_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadica30_rgn_dataType_ld_i2u_grid_y_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica30_rgn_dataType::ld_i2u_grid_y_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->ld_i2u_grid_y, 3417, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_ica30_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadmod_ica30_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_ica30_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = globalelements::globalelementsClass::Loadtrigger_pt_type_aec(entry, &structure->aec_trigger, alignment);
    result = result && Loadica30_rgn_dataType(entry, &structure->ica30_rgn_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_ica30_lens_zoom_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadmod_ica30_lens_zoom_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_ica30_lens_zoom_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->lens_zoom_trigger, alignment);
    result = result && Loadmod_ica30_lens_zoom_dataType_lens_zoom_dataStruct(entry, &structure->lens_zoom_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_ica30_lens_zoom_dataType_lens_zoom_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadmod_ica30_lens_zoom_dataType_lens_zoom_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_ica30_lens_zoom_dataType::lens_zoom_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_ica30_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_ica30_aec_dataCount, alignment);
        structure->mod_ica30_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_ica30_aec_data = PARAMETER_NEW mod_ica30_aec_dataType[structure->mod_ica30_aec_dataCount];
        }
        if (!result || structure->mod_ica30_aec_data == NULL)
        {
            structure->mod_ica30_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_ica30_aec_dataCount; i++)
        {
            result = Loadmod_ica30_aec_dataType(pointerEntry, &structure->mod_ica30_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_ica30_lens_posn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadmod_ica30_lens_posn_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_ica30_lens_posn_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->lens_posn_trigger, alignment);
    result = result && Loadmod_ica30_lens_posn_dataType_lens_posn_dataStruct(entry, &structure->lens_posn_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_ica30_lens_posn_dataType_lens_posn_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadmod_ica30_lens_posn_dataType_lens_posn_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_ica30_lens_posn_dataType::lens_posn_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_ica30_lens_zoom_data from symbol table
    {
        result = entry->Read(&structure->mod_ica30_lens_zoom_dataCount, alignment);
        structure->mod_ica30_lens_zoom_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_ica30_lens_zoom_data = PARAMETER_NEW mod_ica30_lens_zoom_dataType[structure->mod_ica30_lens_zoom_dataCount];
        }
        if (!result || structure->mod_ica30_lens_zoom_data == NULL)
        {
            structure->mod_ica30_lens_zoom_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_ica30_lens_zoom_dataCount; i++)
        {
            result = Loadmod_ica30_lens_zoom_dataType(pointerEntry, &structure->mod_ica30_lens_zoom_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_ica30_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadchromatix_ica30_coreType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica30_coreType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_ica30_lens_posn_data from symbol table
    {
        result = entry->Read(&structure->mod_ica30_lens_posn_dataCount, alignment);
        structure->mod_ica30_lens_posn_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_ica30_lens_posn_data = PARAMETER_NEW mod_ica30_lens_posn_dataType[structure->mod_ica30_lens_posn_dataCount];
        }
        if (!result || structure->mod_ica30_lens_posn_data == NULL)
        {
            structure->mod_ica30_lens_posn_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_ica30_lens_posn_dataCount; i++)
        {
            result = Loadmod_ica30_lens_posn_dataType(pointerEntry, &structure->mod_ica30_lens_posn_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_ica30Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadchromatix_ica30Type(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica30Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadenable_sectionStruct(entry, &structure->enable_section, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && Loadcontrol_variablesStruct(entry, &structure->control_variables, alignment);
    result = result && Loadcontrol_methodStruct(entry, &structure->control_method, alignment);
    result = result && Loadchromatix_ica30_reserveType(entry, &structure->chromatix_ica30_reserve, alignment);
    result = result && Loadchromatix_ica30_coreType(entry, &structure->chromatix_ica30_core, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load enable_sectionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadenable_sectionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica30Type::enable_sectionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->ctc_transform_grid_enable, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica30Type::module_versionStruct* structure,
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
BOOL chromatix_ica30TypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica30Type::parameter_versionStruct* structure,
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
BOOL chromatix_ica30TypeClass::Loadcontrol_variablesStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica30Type::control_variablesStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    for (UINT32 i = 0; result && i < 3; i++)
    {
        structure->control_var_type[i] = (chromatix_ica30Type::control_variablesStruct::control_var_typeEnum)entry->ReadEnum(&result, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load control_methodStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica30TypeClass::Loadcontrol_methodStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica30Type::control_methodStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    structure->aec_exp_control = (ispglobalelements::tuning_control_aec_type)entry->ReadEnum(&result, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_ica30_lens_zoom_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_ica30TypeClass::Unloadmod_ica30_lens_zoom_dataType(
    mod_ica30_lens_zoom_dataType* structure)
{
    Unloadmod_ica30_lens_zoom_dataType_lens_zoom_dataStruct(&structure->lens_zoom_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_ica30_lens_zoom_dataType_lens_zoom_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_ica30TypeClass::Unloadmod_ica30_lens_zoom_dataType_lens_zoom_dataStruct(
    mod_ica30_lens_zoom_dataType::lens_zoom_dataStruct* structure)
{
    PARAMETER_DELETE[] structure->mod_ica30_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_ica30_lens_posn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_ica30TypeClass::Unloadmod_ica30_lens_posn_dataType(
    mod_ica30_lens_posn_dataType* structure)
{
    Unloadmod_ica30_lens_posn_dataType_lens_posn_dataStruct(&structure->lens_posn_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_ica30_lens_posn_dataType_lens_posn_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_ica30TypeClass::Unloadmod_ica30_lens_posn_dataType_lens_posn_dataStruct(
    mod_ica30_lens_posn_dataType::lens_posn_dataStruct* structure)
{
    for (UINT32 i = 0; i < structure->mod_ica30_lens_zoom_dataCount; i++)
    {
        Unloadmod_ica30_lens_zoom_dataType(&structure->mod_ica30_lens_zoom_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_ica30_lens_zoom_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_ica30_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_ica30TypeClass::Unloadchromatix_ica30_coreType(
    chromatix_ica30_coreType* structure)
{
    for (UINT32 i = 0; i < structure->mod_ica30_lens_posn_dataCount; i++)
    {
        Unloadmod_ica30_lens_posn_dataType(&structure->mod_ica30_lens_posn_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_ica30_lens_posn_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_ica30Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_ica30TypeClass::Unloadchromatix_ica30Type(
    chromatix_ica30Type* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    Unloadchromatix_ica30_coreType(&structure->chromatix_ica30_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_ica30TypeClass::Unloadparameter_versionStruct(
    chromatix_ica30Type::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatix_ica30TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatix_ica30TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatix_ica30TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && Loadchromatix_ica30Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


ICA_3_0_0_NAMESPACE_END
