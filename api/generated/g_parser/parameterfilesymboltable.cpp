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
/// @file  parameterfilesymboltable.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "parameterfilesymboltable.h"

ParameterFileSymbolTable::ParameterFileSymbolTable()
{
    m_entries = NULL;
    m_modules = NULL;
}

ParameterFileSymbolTable::~ParameterFileSymbolTable()
{
    if (m_entries != NULL)
    {
        PARAMETER_DELETE[] m_entries;
    }

    if (m_modules != NULL)
    {
        PARAMETER_DELETE[] m_modules;
    }
}

BOOL ParameterFileSymbolTable::Load(
    BYTE*       buffer,
    UINT64      length,
    UINT32      tableSize,
    UINT64*     pos,
    UINT32      dataOffset,
    IModeTable* modeTable,
    UINT64      alignment)
{
    UINT32 entrySize = ParameterFileSymbolTableEntry::SYMBOL_ENTRY_SIZE;
    if (alignment == 1)
    {
        entrySize = ParameterFileSymbolTableEntry::SYMBOL_ENTRY_SIZE_LEGACY;
    }
    m_count = tableSize / entrySize;

    UINT32 expected = m_count * entrySize;
    BOOL   valid    = tableSize == expected;

    // Validate symbol table size
    if (valid)
    {
        m_moduleCount = 0;
        m_entries     = PARAMETER_NEW ParameterFileSymbolTableEntry[m_count];

        valid = m_entries != NULL;

        for (UINT32 i = 0; valid && i < m_count; i++)
        {
            m_entries[i].Init(this);
            valid = m_entries[i].Load(buffer, length, pos, dataOffset, modeTable, alignment);
            if (valid && m_entries[i].IsModule())
            {
                m_moduleCount++;
            }
        }

        if (!valid)
        {
            m_moduleCount = 0;
        }

        if (m_moduleCount > 0)
        {
            UINT32 module = 0;
            m_modules = PARAMETER_NEW ParameterFileSymbolTableEntry*[m_moduleCount];

            valid = m_modules != NULL;

            for (UINT32 i = 0; valid && i < m_count; i++)
            {
                if (m_entries[i].IsModule())
                {
                    m_modules[module++] = &m_entries[i];
                }
            }
        }
    }

    return valid;
}

ParameterFileSymbolTableEntry* ParameterFileSymbolTable::Find(
    UINT32 id)
{
    ParameterFileSymbolTableEntry* result = NULL;

    for (UINT32 i = 0; result == NULL && i < m_count; i++)
    {
        if (m_entries[i].ID == id)
        {
            result = &m_entries[i];
            break;
        }
    }

    return result;
}

ParameterFileSymbolTableEntry* ParameterFileSymbolTable::ReadPointerEntry(
    ParameterFileSymbolTableEntry* entry,
    UINT64 alignment)
{
    UINT32 id = 0;

    if (entry->Read(&id, alignment))
    {
        return Find(id);
    }
    return NULL;
}