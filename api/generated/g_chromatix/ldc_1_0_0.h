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
/// @file  ldc_1_0_0.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef LDC_1_0_0_H
#define LDC_1_0_0_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "ispglobalelements.h"

#define LDC_1_0_0_NAMESPACE_BEGIN namespace ldc_1_0_0 {
#define LDC_1_0_0_NAMESPACE_END }

LDC_1_0_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ldc10_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct ldc10_rgn_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ctc_grid_x_tab
    ///
    /// Tuning Level:  must_tune
    /// Description:   UNDISTORTED_IPE_OUT_TO_DISTORTED_INPUT_GRID: Grid value for x.
    /// Default Value: 0
    /// Range:         [-131072, 131071]
    /// Bit Depth:     18s, Q4
    /// Length:        3417
    /// Conversion:    No Conversion needed
    /// Notes:         Linear interpolation.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct ctc_grid_x_tabStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// ctc_grid_x - Array
        ///
        /// Tuning Level:  must_tune
        /// Default Value: 0
        /// Length:        3417
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        FLOAT ctc_grid_x[3417];
    } ctc_grid_x_tab;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ctc_grid_y_tab
    ///
    /// Tuning Level:  must_tune
    /// Description:   UNDISTORTED_IPE_OUT_TO_DISTORTED_INPUT_GRID: Grid value for y.
    /// Default Value: 0
    /// Range:         [-131072, 131071]
    /// Bit Depth:     18s, Q4
    /// Length:        3417
    /// Conversion:    No Conversion needed
    /// Notes:         Linear interpolation.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct ctc_grid_y_tabStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// ctc_grid_y - Array
        ///
        /// Tuning Level:  must_tune
        /// Default Value: 0
        /// Length:        3417
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        FLOAT ctc_grid_y[3417];
    } ctc_grid_y_tab;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ld_i2u_grid_x_tab
    ///
    /// Tuning Level:  often_tune
    /// Description:   DISTORTED_INPUT_TO_UNDISTORTED_IPE_OUT_GRID: Grid value for x.
    /// Default Value: 0
    /// Range:         [-131072, 131071]
    /// Bit Depth:     18s, Q3
    /// Length:        3417
    /// Conversion:    No Conversion needed
    /// Notes:         Linear interpolation.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct ld_i2u_grid_x_tabStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// ld_i2u_grid_x - Array
        ///
        /// Tuning Level:  often_tune
        /// Default Value: 0
        /// Length:        3417
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        FLOAT ld_i2u_grid_x[3417];
    } ld_i2u_grid_x_tab;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ld_i2u_grid_y_tab
    ///
    /// Tuning Level:  often_tune
    /// Description:   DISTORTED_INPUT_TO_UNDISTORTED_IPE_OUT_GRID: Grid value for y.
    /// Default Value: 0
    /// Range:         [-131072, 131071]
    /// Bit Depth:     18s, Q3
    /// Length:        3417
    /// Conversion:    No Conversion needed
    /// Notes:         Linear interpolation.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct ld_i2u_grid_y_tabStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// ld_i2u_grid_y - Array
        ///
        /// Tuning Level:  often_tune
        /// Default Value: 0
        /// Length:        3417
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        FLOAT ld_i2u_grid_y[3417];
    } ld_i2u_grid_y_tab;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_ldc10_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_ldc10_aec_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// aec_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    globalelements::trigger_pt_type_aec aec_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ldc10_rgn_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ldc10_rgn_dataType  ldc10_rgn_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_ldc10_lens_zoom_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_ldc10_lens_zoom_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// lens_zoom_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ispglobalelements::trigger_pt_type lens_zoom_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// lens_zoom_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct lens_zoom_dataStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// mod_ldc10_aec_data - Array
        /// Min Length:    1
        /// Max Length:    Unbounded
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32                  mod_ldc10_aec_dataCount;
        UINT32                  mod_ldc10_aec_dataID;
        mod_ldc10_aec_dataType* mod_ldc10_aec_data;
    } lens_zoom_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_ldc10_lens_posn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_ldc10_lens_posn_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// lens_posn_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ispglobalelements::trigger_pt_type lens_posn_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// lens_posn_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct lens_posn_dataStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// mod_ldc10_lens_zoom_data - Array
        /// Min Length:    1
        /// Max Length:    Unbounded
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32                        mod_ldc10_lens_zoom_dataCount;
        UINT32                        mod_ldc10_lens_zoom_dataID;
        mod_ldc10_lens_zoom_dataType* mod_ldc10_lens_zoom_data;
    } lens_posn_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_ldc10_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_ldc10_coreType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// mod_ldc10_lens_posn_data - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                        mod_ldc10_lens_posn_dataCount;
    UINT32                        mod_ldc10_lens_posn_dataID;
    mod_ldc10_lens_posn_dataType* mod_ldc10_lens_posn_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_ldc10Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_ldc10Type
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Binary file symbol table entry ID
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32 SymbolTableID;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// enable_section
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct enable_sectionStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;
        globalelements::enable_flag_type ctc_transform_grid_enable;
    } enable_section;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// module_version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct module_versionStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;
        INT32 major_revision;
        INT32 minor_revision;
        INT32 incr_revision;
    } module_version;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// parameter_version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct parameter_versionStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;
        CHAR* revision;
    } parameter_version;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// control_variables
    ///
    /// Default Value: control_lens_position, control_lens_zoom, control_gain
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct control_variablesStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// control_var_type - Array
        /// Default Value: control_lens_position, control_lens_zoom, control_gain
        /// Length:        3
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        enum class control_var_typeEnum
        {
            control_lux_idx       = 0,
            control_gain          = 1,
            control_lens_position = 8,
            control_lens_zoom     = 13
        } control_var_type[3];
    } control_variables;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// control_method
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct control_methodStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// aec_exp_control
        /// Default Value: control_gain
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ispglobalelements::tuning_control_aec_type aec_exp_control;
    } control_method;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// chromatix_ldc10_core
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_ldc10_coreType chromatix_ldc10_core;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_ldc10TypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class chromatix_ldc10TypeClass : public ParameterModule, public chromatix_ldc10Type
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const UINT16 MAJOR = 3;
    static const UINT16 MINOR = 0;
    static const UINT32 PATCH = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Default Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_ldc10TypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_ldc10TypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~chromatix_ldc10TypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load ldc10_rgn_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadldc10_rgn_dataType(
        ParameterFileSymbolTableEntry* entry,
        ldc10_rgn_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load ldc10_rgn_dataType_ctc_grid_x_tabStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadldc10_rgn_dataType_ctc_grid_x_tabStruct(
        ParameterFileSymbolTableEntry* entry,
        ldc10_rgn_dataType::ctc_grid_x_tabStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load ldc10_rgn_dataType_ctc_grid_y_tabStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadldc10_rgn_dataType_ctc_grid_y_tabStruct(
        ParameterFileSymbolTableEntry* entry,
        ldc10_rgn_dataType::ctc_grid_y_tabStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load ldc10_rgn_dataType_ld_i2u_grid_x_tabStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadldc10_rgn_dataType_ld_i2u_grid_x_tabStruct(
        ParameterFileSymbolTableEntry* entry,
        ldc10_rgn_dataType::ld_i2u_grid_x_tabStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load ldc10_rgn_dataType_ld_i2u_grid_y_tabStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadldc10_rgn_dataType_ld_i2u_grid_y_tabStruct(
        ParameterFileSymbolTableEntry* entry,
        ldc10_rgn_dataType::ld_i2u_grid_y_tabStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_ldc10_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_ldc10_aec_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_ldc10_aec_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_ldc10_lens_zoom_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_ldc10_lens_zoom_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_ldc10_lens_zoom_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_ldc10_lens_zoom_dataType_lens_zoom_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_ldc10_lens_zoom_dataType_lens_zoom_dataStruct(
        ParameterFileSymbolTableEntry* entry,
        mod_ldc10_lens_zoom_dataType::lens_zoom_dataStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_ldc10_lens_posn_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_ldc10_lens_posn_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_ldc10_lens_posn_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_ldc10_lens_posn_dataType_lens_posn_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_ldc10_lens_posn_dataType_lens_posn_dataStruct(
        ParameterFileSymbolTableEntry* entry,
        mod_ldc10_lens_posn_dataType::lens_posn_dataStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_ldc10_coreType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_ldc10_coreType(
        ParameterFileSymbolTableEntry* entry,
        chromatix_ldc10_coreType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_ldc10Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_ldc10Type(
        ParameterFileSymbolTableEntry* entry,
        chromatix_ldc10Type* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load enable_sectionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadenable_sectionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_ldc10Type::enable_sectionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_ldc10Type::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadparameter_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_ldc10Type::parameter_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load control_variablesStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcontrol_variablesStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_ldc10Type::control_variablesStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load control_methodStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcontrol_methodStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_ldc10Type::control_methodStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_ldc10_lens_zoom_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_ldc10_lens_zoom_dataType(
        mod_ldc10_lens_zoom_dataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_ldc10_lens_zoom_dataType_lens_zoom_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_ldc10_lens_zoom_dataType_lens_zoom_dataStruct(
        mod_ldc10_lens_zoom_dataType::lens_zoom_dataStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_ldc10_lens_posn_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_ldc10_lens_posn_dataType(
        mod_ldc10_lens_posn_dataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_ldc10_lens_posn_dataType_lens_posn_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_ldc10_lens_posn_dataType_lens_posn_dataStruct(
        mod_ldc10_lens_posn_dataType::lens_posn_dataStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatix_ldc10_coreType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadchromatix_ldc10_coreType(
        chromatix_ldc10_coreType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatix_ldc10Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadchromatix_ldc10Type(
        chromatix_ldc10Type* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadparameter_versionStruct(
        chromatix_ldc10Type::parameter_versionStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class chromatix_ldc10TypeClass

LDC_1_0_0_NAMESPACE_END
#endif // LDC_1_0_0_H

