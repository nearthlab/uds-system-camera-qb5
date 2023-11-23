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
/// @file  parameterutils.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "parameterutils.h"

UINT64 ParameterUtils::Read(
    BYTE*   buffer,
    UINT64* pos,
    UINT64  size,
    UINT64  alignment)
{
    UINT64 result = 0;
    for (UINT64 i = 0; i < size; i++)
    {
        result += (((UINT64)buffer[(*pos)++]) << (i * 8));
    }
    if (size < alignment)
    {
        *pos += (alignment - size);
    }
    return result;
}

BOOL ParameterUtils::Read(
    INT8*   value,
    BYTE*   buffer,
    UINT64  length,
    UINT64* pos,
    UINT64  alignment)
{
    const UINT64 OBJ_SIZE = 1;
    if ((*pos) + OBJ_SIZE <= length)
    {
        *value = (INT8)buffer[*pos];
        *pos  += PARAMETER_MAX(OBJ_SIZE, alignment);
        return TRUE;
    }
    return FALSE;
}

BOOL ParameterUtils::Read(
    UINT8*  value,
    BYTE*   buffer,
    UINT64  length,
    UINT64* pos,
    UINT64  alignment)
{
    const UINT64 OBJ_SIZE = 1;
    if ((*pos) + OBJ_SIZE <= length)
    {
        *value = (UINT8)buffer[*pos];
        *pos  += PARAMETER_MAX(OBJ_SIZE, alignment);
        return TRUE;
    }
    return FALSE;
}

BOOL ParameterUtils::Read(
    BOOL*   value,
    BYTE*   buffer,
    UINT64  length,
    UINT64* pos,
    UINT64  alignment)
{
    UINT32 intVal = 0;
    BOOL   result = Read(&intVal, buffer, length, pos, alignment);
    if (result)
    {
        *value = (BOOL)intVal;
    }
    return result;
}

BOOL ParameterUtils::ReadString(
    CHAR*   value,
    BYTE*   buffer,
    UINT64  length,
    UINT64* pos,
    UINT64  destStrSize,
    UINT64  maxChars,
    UINT64  alignment)
{
    UINT64 chars  = PARAMETER_MIN(maxChars, length - (*pos));
    BOOL   result = FALSE;

    if (value != NULL)
    {
        if (IS_ALIGNED(*pos) && IS_ALIGNED(buffer))
        {
            PARAMETER_MEMCPY(value, destStrSize, (CHAR*)&buffer[*pos], chars);
        }
        else
        {
            for (UINT64 i = 0; i < chars; i++)
            {
                value[i] = (CHAR)buffer[(*pos) + i];
            }
        }
        value[destStrSize - 1] = '\0';
        result = TRUE;
    }

    *pos += maxChars + REMAINDER(maxChars, alignment);

    return result;
}

CHAR* ParameterUtils::ReadString(
    BYTE*   buffer,
    UINT64  length,
    UINT64* pos,
    UINT64  maxChars,
    UINT64  alignment)
{
    UINT64 chars = 0;
    while (chars < maxChars && (*pos) + chars < length && buffer[(*pos) + chars] != 0)
    {
        chars++;
    }

    CHAR* result = PARAMETER_NEW CHAR[(UINT32)(chars + 1)];
    if (result != NULL)
    {
        if (IS_ALIGNED(*pos) && IS_ALIGNED(buffer))
        {
            PARAMETER_STRCPY(result, chars + 1, (CHAR*)&buffer[*pos]);
        }
        else
        {
            for (UINT64 i = 0; i < chars; i++)
            {
                result[i] = (CHAR)buffer[(*pos) + i];
            }
        }

        result[chars] = '\0';
    }

    *pos += (maxChars + REMAINDER(maxChars, alignment));

    return result;
}

BOOL ParameterUtils::ReadBuffer(
    BYTE*   value,
    BYTE*   buffer,
    UINT64  length,
    UINT64* pos,
    UINT64  count,
    UINT64  alignment)
{
    UINT64 bytesCopied = (count <= length - (*pos)) ? count : length - (*pos);
    if (IS_ALIGNED(*pos) && IS_ALIGNED(buffer))
    {
        PARAMETER_MEMCPY(value, bytesCopied, (CHAR*)&buffer[*pos], bytesCopied);
    }
    else
    {
        for (UINT64 i = 0; i < bytesCopied; i++)
        {
            value[i] = buffer[(*pos) + i];
        }
    }

    *pos += count + REMAINDER(count, alignment);

    return bytesCopied == count;
}