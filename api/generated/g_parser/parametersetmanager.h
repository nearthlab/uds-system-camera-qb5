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
/// @file  parametersetmanager.h
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PARAMETERSETMANAGER_H
#define PARAMETERSETMANAGER_H

#include "parametertuningtypes.h"
#include "parameterfilesymboltableentry.h"
#include "parameterfilesymboltable.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// class ModeEntry
///
/// @brief Contains an mode tree data.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ModeEntry
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Constructor
    ///
    /// @brief  Constructs the ModeEntry class
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ModeEntry();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destructor
    ///
    /// @brief  Destructs the ModeEntry class
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ~ModeEntry();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Initialize
    ///
    /// @brief  Initializes the ModeEntry class
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VOID Initialize(
        UINT32 id,
        ModeUnion mode,
        ModeEntry* link);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Add
    ///
    /// @brief  Adds a child ModeEntry
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VOID AddMode(
        ModeEntry* child);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Add
    ///
    /// @brief  Adds a Module
    ///
    /// @return TRUE if successful
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL AddModule(
        ParameterModule* module);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ReplaceModule
    ///
    /// @brief  Replaces existing or adds a new Module.
    ///
    /// @return Replaced module, NULL if this is a new module.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ParameterModule* ReplaceModule(
        ParameterModule* module);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// FindMode
    ///
    /// @brief  Finds a ModeEntry, in the mode tree, from a mode id
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ModeEntry* FindMode(
        UINT32 id);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// FindMode
    ///
    /// @brief  Finds a ModeEntry, in children, from a mode, subMode
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ModeEntry* FindMode(
        TuningMode* mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// FindMode
    ///
    /// @brief  Finds a ModeEntry, in children, from a mode/subMode array
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ModeEntry* FindMode(  
        TuningMode* modes,
        UINT32 count,
        UINT32 found);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// FindModule
    ///
    /// @brief  Finds a Module from a module name id
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ParameterModule* FindModule(
        const CHAR* moduleName);

    UINT32           Id;          // Mode ID
    ModeUnion        Mode;        // Mode
    ModeEntry*       Link;        // Linked Mode, NULL if not linked
    ModeEntry*       Parent;      // Parent Mode
    ModeEntry*       FirstChild;  // First Child
    ModeEntry*       LastChild;   // Last Child
    ModeEntry*       FirstGroup;  // First Group Mode
    ModeEntry*       LastGroup;   // Last Group Mode
    ModeEntry*       Next;        // Next mode
    ParameterModule* FirstModule; // First Module
    ParameterModule* LastModule;  // Last Module
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ParameterSetManager
///
/// @brief Manages the parameter set
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ParameterSetManager : public IModeTable
{
public:
    // Constants as defined in Chromatix Data Access Design document
    const CHAR*  TAG             = "QTI Chromatix Header";
    const UINT32 TAG_LEN         = 28;
    const UINT32 TOOL_LEN        = 48;
    const UINT32 BINARY_TAG_LEN  = 64;
    const UINT16 MAJOR           = 2;
    const UINT16 MINOR           = 0;
    const UINT32 PATCH           = 0;
    const UINT16 LINK_MAJOR      = 2;
    const UINT16 LINK_MINOR      = 0;
    const UINT32 LINK_PATCH      = 0;
    const UINT16 MODE_TREE_MAJOR = 1;
    const UINT16 MODE_TREE_MINOR = 0;
    const UINT32 MODE_TREE_PATCH = 2;
    const UINT16 ALIGNED_MAJOR   = 1;
    const UINT16 ALIGNED_MINOR   = 1;
    const UINT32 ALIGNED_PATCH   = 0;
    const UINT32 MIN_SECTIONS    = 2;
    const UINT32 MAX_SECTIONS    = 3;
    const UINT32 SYMBOL_SECTION  = 0;
    const UINT32 DATA_SECTION    = 1;
    const UINT32 MODE_SECTION    = 2;
    const UINT32 SIZE_OFFSET     = TAG_LEN;  // Offset to write the file size
    const UINT32 NOT_LINKED_ID   = 0xFFFFFFFF;

    static const INT32 ERROR_LEN = 1024;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// LoadBinaryParameters
    ///
    /// @brief Loads binary parameters from a buffer
    ///
    /// @param buffer   Binary parameter buffer
    /// @param length   Length of the binary parameter buffer
    ///
    /// @return True if binary is valid
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL LoadBinaryParameters(
        UINT8* buffer,
        UINT64 length);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// FreeReplacedParameters
    ///
    /// @brief Frees any Parameter objects that were replaced with a call to UpdateParameters
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void FreeReplacedParameters();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetModule
    ///
    /// @brief Returns first parameter module matching the name, mode, selector, and selectorData
    ///
    /// @param name         Module name
    /// @param modeBranch   Mode branch
    /// @param modeCount    Mode count
    ///
    /// @return The first parameter module found matching the name and mode.  Version is ignored.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ParameterModule* GetModule(
        const CHAR* name,
        TuningMode* modeBranch,
        UINT32      modeCount);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetModeEntry
    ///
    /// @brief Gets the Mode and SubMode from a given Mode ID
    ///
    /// @param modeID    Mode ID
    /// @param mode      Mode for the Mode ID [out]
    ///
    /// @return TRUE if ModeID was found, otherwise FALSE
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual BOOL GetModeEntry(
        UINT32     modeID,
        ModeUnion* mode);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetModeEntry
    ///
    /// @brief Gets the Mode and SubMode from a given Mode ID
    ///
    /// @param modeBranch   Mode branch
    /// @param modeCount    Mode count
    ///
    /// @return ModeEntry if found, otherwise NULL
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ModeEntry* GetModeEntry(
        TuningMode* modeBranch,
        UINT32      modeCount);

    BOOL Valid;
    CHAR Error[ERROR_LEN];

protected:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ParameterSetManager
    ///
    /// @brief Constructor
    ///
    /// @return Node
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ParameterSetManager();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ~ParameterSetManager
    ///
    /// @brief Destructor
    ///
    /// @return Node
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ~ParameterSetManager();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// UpdateParameters
    ///
    /// @brief Replaces exising parameters.
    ///
    /// @param parameters   ParameterSetManager object to use for replacement parameters. Parameters are removed from this object.
    ///
    /// @return True if no errors occur
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL UpdateParameters(
        ParameterSetManager* parameters);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// UpdateParameters
    ///
    /// @brief Replaces exising parameters.
    ///
    /// @param destinationRoot   Root destination mode
    /// @param sourceRoot        Root source mode
    ///
    /// @return True if no errors occur
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL UpdateParameters(
        ModeEntry* destinationRoot,
        ModeEntry* sourceRoot);

private:

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ReadHeader
    ///
    /// @brief Reads and validates the the binary parameter file header
    ///
    /// @param buffer    Binary parameter buffer
    /// @param length    Length of the binary parameter buffer
    /// @param pos       Current position in the the binary parameter buffer [in/out]
    /// @param offset    Offset to the section buffer [out]
    /// @param count     Section count [out]
    /// @param alignment Bianry data alignment [out]
    ///
    /// @return True if successful
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL ReadHeader(
        UINT8*  buffer,
        UINT64  length,
        UINT64* pos,
        UINT32* offset,
        UINT32* count,
        UINT64* alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// AddModule
    ///
    /// @brief Updates the module in the module table, or adds new module if not found.
    ///
    /// @param module   Parameter module to add of update
    ///
    /// @return TRUE if successful
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL AddModule(
        ParameterModule* module);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ReadSections
    ///
    /// @brief Reads and validates the the binary parameter file section table
    ///
    /// @param buffer   Binary parameter buffer
    /// @param length   Length of the binary parameter buffer
    /// @param pos      Current position in the the binary parameter buffer [in/out]
    /// @param count    Section count
    ///
    /// @return True if successful
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BOOL ReadSections(
        UINT8*      buffer,
        UINT64      length,
        UINT64*     pos,
        UINT32      count,
        IModeTable* modeTable,
        UINT64      alignment);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// SetError
    ///
    /// @brief Reports an error
    ///
    /// @param message  Binary parameter buffer
    /// @param entry    Symbol table entry containing the error
    /// @param module   Parameter module containing the error
    ///
    /// @return None
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void SetError(
        const CHAR* message,
        const ParameterFileSymbolTableEntry* entry = NULL,
        const ParameterModule* module = NULL);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// CreateModule
    ///
    /// @brief Creates a new parameter module from a symbol table entry
    ///
    /// @param entry    Symbol table entry
    ///
    /// @return Parameter module
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ParameterModule* CreateModule(
        ParameterFileSymbolTableEntry* entry,
        UINT64 alignment);

    virtual const ParameterModule* GetDefaultModule(char* type) = 0;

    ModeEntry*       m_rootMode;
    ModeEntry*       m_modes;
    UINT32           m_modeCount;
    ParameterModule* m_firstReplaced;
    ParameterModule* m_lastReplaced;
    VersionUnion     m_version;
};

#endif