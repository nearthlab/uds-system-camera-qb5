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
/// @file  camxeebindriver.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CAMXEEBINDRIVER_H
#define CAMXEEBINDRIVER_H

#include "parametermodule.h"
#include "parameterfilesymboltable.h"
#include "parametertypes.h"
#include "camxsensorcommon.h"

#define CAMX_NAMESPACE_BEGIN namespace CamX {
#define CAMX_NAMESPACE_END }

CAMX_NAMESPACE_BEGIN

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// EEBinSlaveInformation
///
/// Description:   EEPROM Slave Information
/// Comments:      EEBin slave information
///                 element for slaveAddress
///                 element for I2CFrequencyMode
///                 element for power up sequence
///                 element for power down sequence
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct EEBinSlaveInformation
{
    /// 8-bit or 10-bit I2C slave address to access EEbinData
    UINT16                              slaveAddress;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// i2cFrequencyMode
    /// Default Value: FAST
    /// Comments:      I2C frequency mode of slave
    ///                Supported modes are: STANDARD (100 KHz), FAST (400 KHz), FAST_PLUS (1 MHz), CUSTOM (Custom frequency in
    ///                DTSI)
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    I2CFrequencyMode  i2cFrequencyMode;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// powerUpSequence
    /// Comments:      Sequence of power configuration type and configuration value required to control power to the device
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    PowerSequenceInfo powerUpSequence;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// powerDownSequence
    /// Comments:      Sequence of power configuration type and configuration value required to control power to the device
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    PowerSequenceInfo powerDownSequence;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// MemoryFormatInfo
/// Comments:      Specifies memory offset value and length in bytes information
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct MemoryFormatInfo
{
    /// Offset value in the memory read
    UINT16 offset;
    /// number of bytes of data to be read from the specified offset
    UINT16 lengthInBytes;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// VersionFormatInfo
/// Comments:      Specifies information to format the version to identify EEBin read is needed or not and read details
///                 element for formating the EEBin version read
///                 element for formating the EEBin read start address
///                 element for formating the EEBin read end address
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct VersionFormatInfo
{

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// version
    /// Comments:      Specifies memory offset value and length in bytes information
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    MemoryFormatInfo version;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// readStartAddress
    /// Comments:      Specifies memory offset value and length in bytes information
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    MemoryFormatInfo readStartAddress;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// readEndAddress
    /// Comments:      Specifies memory offset value and length in bytes information
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    MemoryFormatInfo readEndAddress;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ModuleInformation
/// Comments:      Specifies the file information of a Hw module
///                 element for HW Version Info
///                 element for SW Version Info
///                 element for Misc Version Info
///                 element for Sensor Position
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct ModuleInformation
{
    /// HW Version 5 characters
    CHAR* HWVersion;
    /// SW Version 4 characters
    CHAR* SWVersion;
    /// MISC Version 2 characters
    CHAR* MiscVersion;
    /// Full name of the binary file in the format com.vendor.category.module.bin
    /// This name is used as is to find the .bin file in the predefined device paths to load
    CHAR* binaryName;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// EEbinDriver
/// Comments:      EEbin Driver data
///                 element for slaveInfo
///                 element for reading to EEBin vesrion
///                 element for formating the EEBin version read
///                 element for Reading EEBin data information
///                 element for Write EEBin data information
///                 element for module information
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct EEbinDriver
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Binary file symbol table entry ID
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32 SymbolTableID;

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
    /// slaveInfo
    ///
    /// Description:   EEPROM Slave Information
    /// Comments:      EEBin slave information
    ///                 element for slaveAddress
    ///                 element for I2CFrequencyMode
    ///                 element for power up sequence
    ///                 element for power down sequence
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    EEBinSlaveInformation          slaveInfo;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// versionReadInfo
    /// Comments:      Sequence of register settings to configure the device
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SettingsInfo versionReadInfo;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// versionFormatInfo
    /// Comments:      Specifies information to format the version to identify EEBin read is needed or not and read details
    ///                 element for formating the EEBin version read
    ///                 element for formating the EEBin read start address
    ///                 element for formating the EEBin read end address
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VersionFormatInfo              versionFormatInfo;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// dataReadInfo
    /// Comments:      Sequence of register settings to configure the device
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SettingsInfo dataReadInfo;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// dataWriteInfo
    /// Comments:      Sequence of register settings to configure the device
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SettingsInfo dataWriteInfo;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// moduleInfo - Array
    /// Min Length:    1
    /// Max Length:    20
    /// Comments:      Specifies the file information of a Hw module
    ///                 element for HW Version Info
    ///                 element for SW Version Info
    ///                 element for Misc Version Info
    ///                 element for Sensor Position
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32                         moduleInfoCount;
    UINT32                         moduleInfoID;
    ModuleInformation*             moduleInfo;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// EEbinDriverClass
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class EEbinDriverClass : public ParameterModule, public EEbinDriver
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Version
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const UINT16 MAJOR = 1;
    static const UINT16 MINOR = 0;
    static const UINT32 PATCH = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Default Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    EEbinDriverClass(
        const CHAR* name);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    EEbinDriverClass(
        const CHAR* name,
        UINT32      modeId,
        ModeUnion   mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~EEbinDriverClass();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetName
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static const CHAR* GetName(
        const CHAR* type);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load EEBinSlaveInformation
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadEEBinSlaveInformation(
        ParameterFileSymbolTableEntry* entry,
        EEBinSlaveInformation* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load MemoryFormatInfo
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadMemoryFormatInfo(
        ParameterFileSymbolTableEntry* entry,
        MemoryFormatInfo* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load VersionFormatInfo
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadVersionFormatInfo(
        ParameterFileSymbolTableEntry* entry,
        VersionFormatInfo* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load ModuleInformation
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadModuleInformation(
        ParameterFileSymbolTableEntry* entry,
        ModuleInformation* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load EEbinDriver
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL LoadEEbinDriver(
        ParameterFileSymbolTableEntry* entry,
        EEbinDriver* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Load module_versionStruct
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static BOOL Loadmodule_versionStruct(
        ParameterFileSymbolTableEntry* entry,
        EEbinDriver::module_versionStruct* structure,
        UINT64 alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload EEBinSlaveInformation
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadEEBinSlaveInformation(
        EEBinSlaveInformation* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload ModuleInformation
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadModuleInformation(
        ModuleInformation* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Unload EEbinDriver
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void UnloadEEbinDriver(
        EEbinDriver* structure);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Parse symbol table entry, and return a new object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ParameterModule* Parse(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment) const;

}; // End class EEbinDriverClass

CAMX_NAMESPACE_END
#endif // CAMXEEBINDRIVER_H

