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
/// @file  dsx_1_0_0.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "dsx_1_0_0.h"
#include "parametersetmanager.h"

DSX_1_0_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Default Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_dsx10TypeClass::chromatix_dsx10TypeClass(
    const CHAR* name)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), 0, ModeUnion(0))
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(control_variables);
    PARAMETER_INITIALIZE(chromatix_dsx10_reserve);
    PARAMETER_INITIALIZE(chromatix_dsx10_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_dsx10TypeClass::chromatix_dsx10TypeClass(
    const CHAR* name,
    UINT32      modeId,
    ModeUnion   mode)
    : ParameterModule(name, VersionUnion(MAJOR, MINOR, PATCH), modeId, mode)
{
    PARAMETER_INITIALIZE(SymbolTableID);
    PARAMETER_INITIALIZE(module_version);
    PARAMETER_INITIALIZE(parameter_version);
    PARAMETER_INITIALIZE(control_variables);
    PARAMETER_INITIALIZE(chromatix_dsx10_reserve);
    PARAMETER_INITIALIZE(chromatix_dsx10_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
chromatix_dsx10TypeClass::~chromatix_dsx10TypeClass()
{
    Unloadchromatix_dsx10Type(this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GetName
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const CHAR* chromatix_dsx10TypeClass::GetName(
    const CHAR* type)
{
    const CHAR* name = type;
    CHAR temp[ParameterFileSymbolTableEntry::TYPE_LEN + 1];
    if (PARAMETER_STRCMP(type, ParameterFileSymbolTableEntry::GetType(temp, "dsx10_ife_video_full_dc4")) == 0)
    {
        name = "dsx10_ife_video_full_dc4";
    }
    return name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_dsx10_reserveType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loadchromatix_dsx10_reserveType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_dsx10_reserveType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->Read(&structure->param_calc_mode, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dsx10_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loaddsx10_rgn_dataType(
    ParameterFileSymbolTableEntry* entry,
    dsx10_rgn_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loaddsx10_rgn_dataType_luma_kernel_weights_unpacked_horiz_tabStruct(entry, &structure->luma_kernel_weights_unpacked_horiz_tab, alignment);
    result = result && Loaddsx10_rgn_dataType_luma_kernel_weights_unpacked_vert_tabStruct(entry, &structure->luma_kernel_weights_unpacked_vert_tab, alignment);
    result = result && Loaddsx10_rgn_dataType_chroma_kernel_weights_unpacked_horiz_tabStruct(entry, &structure->chroma_kernel_weights_unpacked_horiz_tab, alignment);
    result = result && Loaddsx10_rgn_dataType_chroma_kernel_weights_unpacked_vert_tabStruct(entry, &structure->chroma_kernel_weights_unpacked_vert_tab, alignment);
    result = result && entry->Read(&structure->luma_padding_weights_en, alignment);
    result = result && entry->Read(&structure->chroma_padding_weights_en, alignment);
    result = result && Loaddsx10_rgn_dataType_luma_padding_weights_top_tabStruct(entry, &structure->luma_padding_weights_top_tab, alignment);
    result = result && Loaddsx10_rgn_dataType_luma_padding_weights_bot_tabStruct(entry, &structure->luma_padding_weights_bot_tab, alignment);
    result = result && Loaddsx10_rgn_dataType_luma_padding_weights_left_tabStruct(entry, &structure->luma_padding_weights_left_tab, alignment);
    result = result && Loaddsx10_rgn_dataType_luma_padding_weights_right_tabStruct(entry, &structure->luma_padding_weights_right_tab, alignment);
    result = result && Loaddsx10_rgn_dataType_chroma_padding_weights_top_tabStruct(entry, &structure->chroma_padding_weights_top_tab, alignment);
    result = result && Loaddsx10_rgn_dataType_chroma_padding_weights_bot_tabStruct(entry, &structure->chroma_padding_weights_bot_tab, alignment);
    result = result && Loaddsx10_rgn_dataType_chroma_padding_weights_left_tabStruct(entry, &structure->chroma_padding_weights_left_tab, alignment);
    result = result && Loaddsx10_rgn_dataType_chroma_padding_weights_right_tabStruct(entry, &structure->chroma_padding_weights_right_tab, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dsx10_rgn_dataType_luma_kernel_weights_unpacked_horiz_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loaddsx10_rgn_dataType_luma_kernel_weights_unpacked_horiz_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    dsx10_rgn_dataType::luma_kernel_weights_unpacked_horiz_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->luma_kernel_weights_unpacked_horiz, 192, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dsx10_rgn_dataType_luma_kernel_weights_unpacked_vert_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loaddsx10_rgn_dataType_luma_kernel_weights_unpacked_vert_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    dsx10_rgn_dataType::luma_kernel_weights_unpacked_vert_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->luma_kernel_weights_unpacked_vert, 192, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dsx10_rgn_dataType_chroma_kernel_weights_unpacked_horiz_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loaddsx10_rgn_dataType_chroma_kernel_weights_unpacked_horiz_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    dsx10_rgn_dataType::chroma_kernel_weights_unpacked_horiz_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->chroma_kernel_weights_unpacked_horiz, 96, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dsx10_rgn_dataType_chroma_kernel_weights_unpacked_vert_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loaddsx10_rgn_dataType_chroma_kernel_weights_unpacked_vert_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    dsx10_rgn_dataType::chroma_kernel_weights_unpacked_vert_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->chroma_kernel_weights_unpacked_vert, 96, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dsx10_rgn_dataType_luma_padding_weights_top_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loaddsx10_rgn_dataType_luma_padding_weights_top_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    dsx10_rgn_dataType::luma_padding_weights_top_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->luma_padding_weights_top, 24, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dsx10_rgn_dataType_luma_padding_weights_bot_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loaddsx10_rgn_dataType_luma_padding_weights_bot_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    dsx10_rgn_dataType::luma_padding_weights_bot_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->luma_padding_weights_bot, 24, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dsx10_rgn_dataType_luma_padding_weights_left_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loaddsx10_rgn_dataType_luma_padding_weights_left_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    dsx10_rgn_dataType::luma_padding_weights_left_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->luma_padding_weights_left, 24, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dsx10_rgn_dataType_luma_padding_weights_right_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loaddsx10_rgn_dataType_luma_padding_weights_right_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    dsx10_rgn_dataType::luma_padding_weights_right_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->luma_padding_weights_right, 24, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dsx10_rgn_dataType_chroma_padding_weights_top_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loaddsx10_rgn_dataType_chroma_padding_weights_top_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    dsx10_rgn_dataType::chroma_padding_weights_top_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->chroma_padding_weights_top, 8, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dsx10_rgn_dataType_chroma_padding_weights_bot_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loaddsx10_rgn_dataType_chroma_padding_weights_bot_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    dsx10_rgn_dataType::chroma_padding_weights_bot_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->chroma_padding_weights_bot, 8, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dsx10_rgn_dataType_chroma_padding_weights_left_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loaddsx10_rgn_dataType_chroma_padding_weights_left_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    dsx10_rgn_dataType::chroma_padding_weights_left_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->chroma_padding_weights_left, 8, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load dsx10_rgn_dataType_chroma_padding_weights_right_tabStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loaddsx10_rgn_dataType_chroma_padding_weights_right_tabStruct(
    ParameterFileSymbolTableEntry* entry,
    dsx10_rgn_dataType::chroma_padding_weights_right_tabStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = entry->ReadArray(structure->chroma_padding_weights_right, 8, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load mod_dsx10_sr_scale_ratio_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loadmod_dsx10_sr_scale_ratio_dataType(
    ParameterFileSymbolTableEntry* entry,
    mod_dsx10_sr_scale_ratio_dataType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = ispglobalelements::ispglobalelementsClass::Loadtrigger_pt_type(entry, &structure->sr_scale_ratio_trigger, alignment);
    result = result && Loaddsx10_rgn_dataType(entry, &structure->dsx10_rgn_data, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_dsx10_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loadchromatix_dsx10_coreType(
    ParameterFileSymbolTableEntry* entry,
    chromatix_dsx10_coreType* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;


    // Reading Array mod_dsx10_sr_scale_ratio_data from symbol table
    {
        result = entry->Read(&structure->mod_dsx10_sr_scale_ratio_dataCount, alignment);
        structure->mod_dsx10_sr_scale_ratio_dataID = entry->ID;
        ParameterFileSymbolTableEntry* pointerEntry = entry->Table->ReadPointerEntry(entry, alignment);
        result = result && pointerEntry != NULL;
        if (result)
        {
            structure->mod_dsx10_sr_scale_ratio_data = PARAMETER_NEW mod_dsx10_sr_scale_ratio_dataType[structure->mod_dsx10_sr_scale_ratio_dataCount];
        }
        if (!result || structure->mod_dsx10_sr_scale_ratio_data == NULL)
        {
            structure->mod_dsx10_sr_scale_ratio_dataCount = 0;
        }
        for (UINT32 i = 0; result && i < structure->mod_dsx10_sr_scale_ratio_dataCount; i++)
        {
            result = Loadmod_dsx10_sr_scale_ratio_dataType(pointerEntry, &structure->mod_dsx10_sr_scale_ratio_data[i], alignment);
        }
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load chromatix_dsx10Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loadchromatix_dsx10Type(
    ParameterFileSymbolTableEntry* entry,
    chromatix_dsx10Type* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    result = Loadmodule_versionStruct(entry, &structure->module_version, alignment);
    result = result && Loadparameter_versionStruct(entry, &structure->parameter_version, alignment);
    result = result && Loadcontrol_variablesStruct(entry, &structure->control_variables, alignment);
    result = result && Loadchromatix_dsx10_reserveType(entry, &structure->chromatix_dsx10_reserve, alignment);
    result = result && Loadchromatix_dsx10_coreType(entry, &structure->chromatix_dsx10_core, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Load module_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOL chromatix_dsx10TypeClass::Loadmodule_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_dsx10Type::module_versionStruct* structure,
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
BOOL chromatix_dsx10TypeClass::Loadparameter_versionStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_dsx10Type::parameter_versionStruct* structure,
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
BOOL chromatix_dsx10TypeClass::Loadcontrol_variablesStruct(
    ParameterFileSymbolTableEntry* entry,
    chromatix_dsx10Type::control_variablesStruct* structure,
    UINT64 alignment)
{
    BOOL result = TRUE;

    structure->control_var_type = (chromatix_dsx10Type::control_variablesStruct::control_var_typeEnum)entry->ReadEnum(&result, alignment);

    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_dsx10_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_dsx10TypeClass::Unloadchromatix_dsx10_coreType(
    chromatix_dsx10_coreType* structure)
{
    PARAMETER_DELETE[] structure->mod_dsx10_sr_scale_ratio_data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload chromatix_dsx10Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_dsx10TypeClass::Unloadchromatix_dsx10Type(
    chromatix_dsx10Type* structure)
{
    Unloadparameter_versionStruct(&structure->parameter_version);
    Unloadchromatix_dsx10_coreType(&structure->chromatix_dsx10_core);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Unload parameter_versionStruct
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void chromatix_dsx10TypeClass::Unloadparameter_versionStruct(
    chromatix_dsx10Type::parameter_versionStruct* structure)
{
    PARAMETER_DELETE[] structure->revision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parse symbol table entry, and return a new object
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ParameterModule* chromatix_dsx10TypeClass::Parse(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment) const
{
    chromatix_dsx10TypeClass* cls = NULL;

    if (PARAMETER_STRCMP(Type, entry->Type) == 0 && Version.Value == entry->Version.Value)
    {
        cls = PARAMETER_NEW chromatix_dsx10TypeClass(GetName(entry->Type), 
            entry->ModeId, entry->Mode);
        if (cls != NULL)
        {
            BOOL result = TRUE;

            cls->SymbolTableID = entry->ID;
            cls->ID            = entry->ID;

            result = result && Loadchromatix_dsx10Type(entry, cls, alignment);

            if (!result)
            {
                PARAMETER_DELETE cls;
                cls = NULL;
            }
        }
    }
    return (ParameterModule*)cls;
}


DSX_1_0_0_NAMESPACE_END
