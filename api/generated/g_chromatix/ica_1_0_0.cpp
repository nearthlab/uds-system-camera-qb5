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
/// @file  ica_1_0_0.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "ica_1_0_0.h"
#include "parametersetmanager.h"

ICA_1_0_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_ica10TypeClass::chromatix_ica10TypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(enable_section);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(control_variables);
    PARAMETER_INITIALIZE(control_method);
    PARAMETER_INITIALIZE(chromatix_ica10_reserve);
    PARAMETER_INITIALIZE(chromatix_ica10_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_ica10TypeClass::chromatix_ica10TypeClass(
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
    PARAMETER_INITIALIZE(chromatix_ica10_reserve);
    PARAMETER_INITIALIZE(chromatix_ica10_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_ica10TypeClass::~chromatix_ica10TypeClass()
{
    Unloadchromatix_ica10Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatix_ica10TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "ica10_ipe_module1")) == 0)
    {
        name = "ica10_ipe_module1";
    }
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "ica10_ipe_module2")) == 0)
    {
        name = "ica10_ipe_module2";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_ica10_reserveType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadchromatix_ica10_reserveType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica10_reserveType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->opg_invalid_output_treatment_calculate, alignment);
    result = result && entry->Read(&structure->opg_invalid_output_treatment_y, alignment);
    result = result && entry->Read(&structure->opg_invalid_output_treatment_cb, alignment);
    result = result && entry->Read(&structure->opg_invalid_output_treatment_cr, alignment);
    result = result && entry->Read(&structure->distorted_input_to_undistorted_ldc_grid_valid, alignment);
    result = result && entry->Read(&structure->undistorted_to_lens_distorted_output_ld_grid_valid, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica10_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadica10_rgn_dataType(
    ParameterFileSymbolTableEntry* entry,
    ica10_rgn_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->y_interpolation_type, alignment);
    result = result && Loadica10_rgn_dataType_ctc_grid_x_tabStruct(entry, &structure->ctc_grid_x_tab, alignment);
    result = result && Loadica10_rgn_dataType_ctc_grid_y_tabStruct(entry, &structure->ctc_grid_y_tab, alignment);
    result = result && Loadica10_rgn_dataType_opg_interpolation_lut_0_tabStruct(entry, &structure->opg_interpolation_lut_0_tab, alignment);
    result = result && Loadica10_rgn_dataType_opg_interpolation_lut_1_tabStruct(entry, &structure->opg_interpolation_lut_1_tab, alignment);
    result = result && Loadica10_rgn_dataType_opg_interpolation_lut_2_tabStruct(entry, &structure->opg_interpolation_lut_2_tab, alignment);
    result = result && Loadica10_rgn_dataType_distorted_input_to_undistorted_ldc_grid_x_tabStruct(entry, &structure->distorted_input_to_undistorted_ldc_grid_x_tab, alignment);
    result = result && Loadica10_rgn_dataType_distorted_input_to_undistorted_ldc_grid_y_tabStruct(entry, &structure->distorted_input_to_undistorted_ldc_grid_y_tab, alignment);
    result = result && Loadica10_rgn_dataType_undistorted_to_lens_distorted_output_ld_grid_x_tabStruct(entry, &structure->undistorted_to_lens_distorted_output_ld_grid_x_tab, alignment);
    result = result && Loadica10_rgn_dataType_undistorted_to_lens_distorted_output_ld_grid_y_tabStruct(entry, &structure->undistorted_to_lens_distorted_output_ld_grid_y_tab, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica10_rgn_dataType_ctc_grid_x_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadica10_rgn_dataType_ctc_grid_x_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica10_rgn_dataType::ctc_grid_x_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->ctc_grid_x, 829, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica10_rgn_dataType_ctc_grid_y_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadica10_rgn_dataType_ctc_grid_y_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica10_rgn_dataType::ctc_grid_y_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->ctc_grid_y, 829, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica10_rgn_dataType_opg_interpolation_lut_0_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadica10_rgn_dataType_opg_interpolation_lut_0_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica10_rgn_dataType::opg_interpolation_lut_0_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->opg_interpolation_lut_0, 16, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica10_rgn_dataType_opg_interpolation_lut_1_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadica10_rgn_dataType_opg_interpolation_lut_1_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica10_rgn_dataType::opg_interpolation_lut_1_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->opg_interpolation_lut_1, 16, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica10_rgn_dataType_opg_interpolation_lut_2_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadica10_rgn_dataType_opg_interpolation_lut_2_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica10_rgn_dataType::opg_interpolation_lut_2_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->opg_interpolation_lut_2, 16, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica10_rgn_dataType_distorted_input_to_undistorted_ldc_grid_x_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadica10_rgn_dataType_distorted_input_to_undistorted_ldc_grid_x_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica10_rgn_dataType::distorted_input_to_undistorted_ldc_grid_x_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->distorted_input_to_undistorted_ldc_grid_x, 829, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica10_rgn_dataType_distorted_input_to_undistorted_ldc_grid_y_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadica10_rgn_dataType_distorted_input_to_undistorted_ldc_grid_y_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica10_rgn_dataType::distorted_input_to_undistorted_ldc_grid_y_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->distorted_input_to_undistorted_ldc_grid_y, 829, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica10_rgn_dataType_undistorted_to_lens_distorted_output_ld_grid_x_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadica10_rgn_dataType_undistorted_to_lens_distorted_output_ld_grid_x_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica10_rgn_dataType::undistorted_to_lens_distorted_output_ld_grid_x_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->undistorted_to_lens_distorted_output_ld_grid_x, 829, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load ica10_rgn_dataType_undistorted_to_lens_distorted_output_ld_grid_y_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadica10_rgn_dataType_undistorted_to_lens_distorted_output_ld_grid_y_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    ica10_rgn_dataType::undistorted_to_lens_distorted_output_ld_grid_y_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->undistorted_to_lens_distorted_output_ld_grid_y, 829, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_ica10_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadmod_ica10_aec_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_ica10_aec_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = globalelements::globalelementsClass::Loadtrigger_pt_type_aec(entry, &structure->aec_trigger, alignment);
    result = result && Loadica10_rgn_dataType(entry, &structure->ica10_rgn_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_ica10_lens_zoom_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadmod_ica10_lens_zoom_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_ica10_lens_zoom_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->lens_zoom_trigger, alignment);
    result = result && Loadmod_ica10_lens_zoom_dataType_lens_zoom_dataStruct(entry, &structure->lens_zoom_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_ica10_lens_zoom_dataType_lens_zoom_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadmod_ica10_lens_zoom_dataType_lens_zoom_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_ica10_lens_zoom_dataType::lens_zoom_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_ica10_aec_data from symbol table
    {
        result = entry->Read(&structure->mod_ica10_aec_dataCount, alignment);
        structure->mod_ica10_aec_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_ica10_aec_data = PARAMETER_NEW mod_ica10_aec_dataType[structure->mod_ica10_aec_dataCount];
        }
        if (!result || structure->mod_ica10_aec_data == NULL)
        {
            structure->mod_ica10_aec_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_ica10_aec_dataCount; i++)
        {
            result = Loadmod_ica10_aec_dataType(pointerEntry, &structure->mod_ica10_aec_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_ica10_lens_posn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadmod_ica10_lens_posn_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_ica10_lens_posn_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->lens_posn_trigger, alignment);
    result = result && Loadmod_ica10_lens_posn_dataType_lens_posn_dataStruct(entry, &structure->lens_posn_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_ica10_lens_posn_dataType_lens_posn_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadmod_ica10_lens_posn_dataType_lens_posn_dataStruct(
    ParameterFileSymbolTableEntry* entry,
    mod_ica10_lens_posn_dataType::lens_posn_dataStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_ica10_lens_zoom_data from symbol table
    {
        result = entry->Read(&structure->mod_ica10_lens_zoom_dataCount, alignment);
        structure->mod_ica10_lens_zoom_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_ica10_lens_zoom_data = PARAMETER_NEW mod_ica10_lens_zoom_dataType[structure->mod_ica10_lens_zoom_dataCount];
        }
        if (!result || structure->mod_ica10_lens_zoom_data == NULL)
        {
            structure->mod_ica10_lens_zoom_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_ica10_lens_zoom_dataCount; i++)
        {
            result = Loadmod_ica10_lens_zoom_dataType(pointerEntry, &structure->mod_ica10_lens_zoom_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_ica10_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadchromatix_ica10_coreType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica10_coreType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_ica10_lens_posn_data from symbol table
    {
        result = entry->Read(&structure->mod_ica10_lens_posn_dataCount, alignment);
        structure->mod_ica10_lens_posn_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_ica10_lens_posn_data = PARAMETER_NEW mod_ica10_lens_posn_dataType[structure->mod_ica10_lens_posn_dataCount];
        }
        if (!result || structure->mod_ica10_lens_posn_data == NULL)
        {
            structure->mod_ica10_lens_posn_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_ica10_lens_posn_dataCount; i++)
        {
            result = Loadmod_ica10_lens_posn_dataType(pointerEntry, &structure->mod_ica10_lens_posn_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_ica10Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadchromatix_ica10Type(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica10Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadenable_sectionStruct(entry, &structure->enable_section, alignment);
    result = result && Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && Loadcontrol_variablesStruct(entry, &structure->control_variables, alignment);
    result = result && Loadcontrol_methodStruct(entry, &structure->control_method, alignment);
    result = result && Loadchromatix_ica10_reserveType(entry, &structure->chromatix_ica10_reserve, alignment);
    result = result && Loadchromatix_ica10_coreType(entry, &structure->chromatix_ica10_core, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load enable_sectionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadenable_sectionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica10Type::enable_sectionStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->ctc_transform_grid_enable, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica10Type::module_versionStruct* structure,
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
BOOL chromatix_ica10TypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica10Type::parameter_versionStruct* structure,
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
BOOL chromatix_ica10TypeClass::Loadcontrol_variablesStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica10Type::control_variablesStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    for (UINT32 i = 0; result && i < 3; i++)
    {
        structure->control_var_type[i] = (chromatix_ica10Type::control_variablesStruct::control_var_typeEnum)entry->ReadEnum(&result, alignment);
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load control_methodStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_ica10TypeClass::Loadcontrol_methodStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_ica10Type::control_methodStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    structure->aec_exp_control = (ispglobalelements::tuning_control_aec_type)entry->ReadEnum(&result, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_ica10_lens_zoom_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_ica10TypeClass::Unloadmod_ica10_lens_zoom_dataType(
    mod_ica10_lens_zoom_dataType* structure)
{
    Unloadmod_ica10_lens_zoom_dataType_lens_zoom_dataStruct(&structure->lens_zoom_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_ica10_lens_zoom_dataType_lens_zoom_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_ica10TypeClass::Unloadmod_ica10_lens_zoom_dataType_lens_zoom_dataStruct(
    mod_ica10_lens_zoom_dataType::lens_zoom_dataStruct* structure)
{
    PARAMETER_DELETE[] structure->mod_ica10_aec_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_ica10_lens_posn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_ica10TypeClass::Unloadmod_ica10_lens_posn_dataType(
    mod_ica10_lens_posn_dataType* structure)
{
    Unloadmod_ica10_lens_posn_dataType_lens_posn_dataStruct(&structure->lens_posn_data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload mod_ica10_lens_posn_dataType_lens_posn_dataStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_ica10TypeClass::Unloadmod_ica10_lens_posn_dataType_lens_posn_dataStruct(
    mod_ica10_lens_posn_dataType::lens_posn_dataStruct* structure)
{
    for (UINT32 i = 0; i < structure->mod_ica10_lens_zoom_dataCount; i++)
    {
        Unloadmod_ica10_lens_zoom_dataType(&structure->mod_ica10_lens_zoom_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_ica10_lens_zoom_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_ica10_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_ica10TypeClass::Unloadchromatix_ica10_coreType(
    chromatix_ica10_coreType* structure)
{
    for (UINT32 i = 0; i < structure->mod_ica10_lens_posn_dataCount; i++)
    {
        Unloadmod_ica10_lens_posn_dataType(&structure->mod_ica10_lens_posn_data[i]);
    }
    PARAMETER_DELETE[] structure->mod_ica10_lens_posn_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_ica10Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_ica10TypeClass::Unloadchromatix_ica10Type(
    chromatix_ica10Type* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    Unloadchromatix_ica10_coreType(&structure->chromatix_ica10_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_ica10TypeClass::Unloadparameter_versionStruct(
    chromatix_ica10Type::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatix_ica10TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatix_ica10TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatix_ica10TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && Loadchromatix_ica10Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


ICA_1_0_0_NAMESPACE_END
