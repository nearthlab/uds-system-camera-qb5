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
/// @file  bpcbcc_5_0_0.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BPCBCC_5_0_0_H
#define BPCBCC_5_0_0_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "ispglobalelements.h"

#define BPCBCC_5_0_0_NAMESPACE_BEGIN namespace bpcbcc_5_0_0 {
#define BPCBCC_5_0_0_NAMESPACE_END }

BPCBCC_5_0_0_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// bpcbcc50_rgn_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct bpcbcc50_rgn_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// hot_pixel_correction_disable
    ///
    /// Tuning Level:  often_tune
    /// Description:   hot pixel correction enable/disable
    /// Type:          int
    /// Default Value: 0
    /// Range:         [0,1]
    /// Bit Depth:     1uQ0
    /// Conversion:    no conversion needed
    /// Notes:         Enable bit.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT hot_pixel_correction_disable;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// cold_pixel_correction_disable
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   cold pixel correction enable/disable.
    /// Type:          int
    /// Default Value: 0
    /// Range:         [0,1]
    /// Bit Depth:     1uQ0
    /// Conversion:    no conversion needed
    /// Notes:         Enable bit
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT cold_pixel_correction_disable;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// same_channel_recovery
    ///
    /// Tuning Level:  rarely_tune
    /// Description:   Use only same channel information for detection.
    /// Type:          int
    /// Default Value: 0
    /// Range:         [0,1]
    /// Bit Depth:     1uQ0
    /// Conversion:    no conversion needed
    /// Notes:         Enable bit
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT same_channel_recovery;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// fmax
    ///
    /// Tuning Level:  often_tune
    /// Description:   Bad pixel maximum threshold factor.
    /// Type:          int
    /// Default Value: 80
    /// Range:         [0,127]
    /// Bit Depth:     7uQ6
    /// Conversion:    no conversion needed
    /// Notes:         larger values mean less bad pixels detection
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT fmax;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// fmin
    ///
    /// Tuning Level:  often_tune
    /// Description:   Bad pixel minimum threshold factor.
    /// Type:          int
    /// Default Value: 32
    /// Range:         [0,127]
    /// Bit Depth:     7uQ6
    /// Conversion:    no conversion needed
    /// Notes:         larger values mean less bad pixels detection
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT fmin;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// bpc_offset
    ///
    /// Tuning Level:  often_tune
    /// Description:   offset used in single bad pixel detection for regular bayer or T1 in HDR mode.
    /// Type:          int
    /// Default Value: 128
    /// Range:         [0,16383]
    /// Bit Depth:     14uQ0
    /// Conversion:    no conversion needed
    /// Notes:         larger values mean less bad pixels detection
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT bpc_offset;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// bcc_offset
    ///
    /// Tuning Level:  often_tune
    /// Description:   offset used in couplet bad pixel detection for regular bayer or T1 in HDR mode.
    /// Type:          int
    /// Default Value: 128
    /// Range:         [0,16383]
    /// Bit Depth:     14uQ0
    /// Conversion:    no conversion needed
    /// Notes:         larger values mean less bad pixels detection
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT bcc_offset;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// correction_threshold
    ///
    /// Tuning Level:  often_tune
    /// Description:   if departure of correction value from the original value is larger than this threshold, the pixel will be
    ///                corrected using the correction value.
    /// Type:          int
    /// Default Value: 128
    /// Range:         [0,8191]
    /// Bit Depth:     13uQ0
    /// Conversion:    no conversion needed
    /// Notes:         larger values mean less bad pixels detection
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    FLOAT correction_threshold;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_bpcbcc50_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_bpcbcc50_aec_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// aec_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    globalelements::trigger_pt_type_aec   aec_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// bpcbcc50_rgn_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bpcbcc50_rgn_dataType bpcbcc50_rgn_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_bpcbcc50_hdr_aec_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_bpcbcc50_hdr_aec_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// hdr_aec_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ispglobalelements::trigger_pt_type_aec_hdr hdr_aec_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// hdr_aec_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct hdr_aec_dataStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// mod_bpcbcc50_aec_data - Array
        /// Min Length:    1
        /// Max Length:    Unbounded
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32                     mod_bpcbcc50_aec_dataCount;
        UINT32                     mod_bpcbcc50_aec_dataID;
        mod_bpcbcc50_aec_dataType* mod_bpcbcc50_aec_data;
    } hdr_aec_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// mod_bpcbcc50_drc_gain_dataType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct mod_bpcbcc50_drc_gain_dataType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// drc_gain_trigger
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ispglobalelements::trigger_pt_type drc_gain_trigger;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// drc_gain_data
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct drc_gain_dataStruct
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// mod_bpcbcc50_hdr_aec_data - Array
        /// Min Length:    1
        /// Max Length:    Unbounded
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32                         mod_bpcbcc50_hdr_aec_dataCount;
        UINT32                         mod_bpcbcc50_hdr_aec_dataID;
        mod_bpcbcc50_hdr_aec_dataType* mod_bpcbcc50_hdr_aec_data;
    } drc_gain_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_bpcbcc50_coreType
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_bpcbcc50_coreType
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// mod_bpcbcc50_drc_gain_data - Array
    /// Min Length:    1
    /// Max Length:    Unbounded
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                          mod_bpcbcc50_drc_gain_dataCount;
    UINT32                          mod_bpcbcc50_drc_gain_dataID;
    mod_bpcbcc50_drc_gain_dataType* mod_bpcbcc50_drc_gain_data;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_bpcbcc50Type
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct chromatix_bpcbcc50Type
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
        globalelements::enable_flag_type bpcbcc_enable;
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
    /// Default Value: control_drc_gain, control_aec_exp_sensitivity_ratio, control_gain
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct control_variablesStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// control_var_type - Array
        /// Default Value: control_drc_gain, control_aec_exp_sensitivity_ratio, control_gain
        /// Length:        3
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        enum class control_var_typeEnum
        {
            control_lux_idx                   = 0,
            control_gain                      = 1,
            control_drc_gain                  = 2,
            control_exp_time_ratio            = 3,
            control_aec_exp_sensitivity_ratio = 4,
            control_exp_gain_ratio            = 5
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
        ispglobalelements::tuning_control_aec_type     aec_exp_control;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// aec_hdr_control
        /// Default Value: control_aec_exp_sensitivity_ratio
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ispglobalelements::tuning_control_aec_hdr_type aec_hdr_control;
    } control_method;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// dynamic_enable_triggers
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct dynamic_enable_triggersStruct
    {
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Binary file symbol table entry ID
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        UINT32 SymbolTableID;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// bpcbcc_enable
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        struct bpcbcc_enableStruct
        {
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /// Binary file symbol table entry ID
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            UINT32 SymbolTableID;

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /// enable
            ///
            /// Tuning Level:  rarely_tune
            /// Description:   enable BPCBCC5.0 module
            /// Type:          int
            /// Default Value: 0
            /// Range:         [0,1]
            /// Bit Depth:     1uQ0
            /// Conversion:    no conversion needed
            /// Notes:         none
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            globalelements::enable_flag_type        enable;

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /// hyst_control_var
            ///
            /// Tuning Level:  rarely_tune
            /// Description:   enable BPCBCC5.0 module
            /// Type:          uint
            /// Default Value: control_gain
            /// Range:         [0,1]
            /// Bit Depth:     1uQ0
            /// Conversion:    no conversion needed
            /// Notes:         none
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ispglobalelements::control_var_type        hyst_control_var;

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /// hyst_mode
            /// Default Value: UPWARD
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ispglobalelements::hyst_direction          hyst_mode;

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /// hyst_trigger
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ispglobalelements::trigger_pt_couplet_type hyst_trigger;
        } bpcbcc_enable;
    } dynamic_enable_triggers;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// chromatix_bpcbcc50_core
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_bpcbcc50_coreType chromatix_bpcbcc50_core;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// chromatix_bpcbcc50TypeClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class chromatix_bpcbcc50TypeClass : public ParameterModule, public chromatix_bpcbcc50Type
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const UINT16 MAJOR = 5;
    static const UINT16 MINOR = 0;
    static const UINT32 PATCH = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Default Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_bpcbcc50TypeClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    chromatix_bpcbcc50TypeClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~chromatix_bpcbcc50TypeClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load bpcbcc50_rgn_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadbpcbcc50_rgn_dataType(
        ParameterFileSymbolTableEntry* entry,
        bpcbcc50_rgn_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_bpcbcc50_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_bpcbcc50_aec_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_bpcbcc50_aec_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_bpcbcc50_hdr_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_bpcbcc50_hdr_aec_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_bpcbcc50_hdr_aec_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_bpcbcc50_hdr_aec_dataType_hdr_aec_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_bpcbcc50_hdr_aec_dataType_hdr_aec_dataStruct(
        ParameterFileSymbolTableEntry* entry,
        mod_bpcbcc50_hdr_aec_dataType::hdr_aec_dataStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_bpcbcc50_drc_gain_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_bpcbcc50_drc_gain_dataType(
        ParameterFileSymbolTableEntry* entry,
        mod_bpcbcc50_drc_gain_dataType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load mod_bpcbcc50_drc_gain_dataType_drc_gain_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmod_bpcbcc50_drc_gain_dataType_drc_gain_dataStruct(
        ParameterFileSymbolTableEntry* entry,
        mod_bpcbcc50_drc_gain_dataType::drc_gain_dataStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_bpcbcc50_coreType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_bpcbcc50_coreType(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bpcbcc50_coreType* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load chromatix_bpcbcc50Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadchromatix_bpcbcc50Type(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bpcbcc50Type* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load enable_sectionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadenable_sectionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bpcbcc50Type::enable_sectionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bpcbcc50Type::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadparameter_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bpcbcc50Type::parameter_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load control_variablesStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcontrol_variablesStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bpcbcc50Type::control_variablesStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load control_methodStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadcontrol_methodStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bpcbcc50Type::control_methodStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load dynamic_enable_triggersStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loaddynamic_enable_triggersStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bpcbcc50Type::dynamic_enable_triggersStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load dynamic_enable_triggersStruct_bpcbcc_enableStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loaddynamic_enable_triggersStruct_bpcbcc_enableStruct(
        ParameterFileSymbolTableEntry* entry,
        chromatix_bpcbcc50Type::dynamic_enable_triggersStruct::bpcbcc_enableStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_bpcbcc50_hdr_aec_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_bpcbcc50_hdr_aec_dataType(
        mod_bpcbcc50_hdr_aec_dataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_bpcbcc50_hdr_aec_dataType_hdr_aec_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_bpcbcc50_hdr_aec_dataType_hdr_aec_dataStruct(
        mod_bpcbcc50_hdr_aec_dataType::hdr_aec_dataStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_bpcbcc50_drc_gain_dataType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_bpcbcc50_drc_gain_dataType(
        mod_bpcbcc50_drc_gain_dataType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload mod_bpcbcc50_drc_gain_dataType_drc_gain_dataStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadmod_bpcbcc50_drc_gain_dataType_drc_gain_dataStruct(
        mod_bpcbcc50_drc_gain_dataType::drc_gain_dataStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatix_bpcbcc50_coreType
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadchromatix_bpcbcc50_coreType(
        chromatix_bpcbcc50_coreType* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload chromatix_bpcbcc50Type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadchromatix_bpcbcc50Type(
        chromatix_bpcbcc50Type* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload parameter_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void Unloadparameter_versionStruct(
        chromatix_bpcbcc50Type::parameter_versionStruct* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class chromatix_bpcbcc50TypeClass

BPCBCC_5_0_0_NAMESPACE_END
#endif // BPCBCC_5_0_0_H

