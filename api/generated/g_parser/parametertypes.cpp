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
/// @file  parametertypes.cpp
/// @brief Auto-generated Chromatix parameter file
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "parametertypes.h"

VersionUnion::VersionUnion()
{
    Value = 0;
}

VersionUnion::VersionUnion(
    UINT64 value)
{
    Value = value;
}

VersionUnion::VersionUnion(
    UINT16 major,
    UINT16 minor,
    UINT32 patch)
{
    Version.Major = major;
    Version.Minor = minor;
    Version.Patch = patch;
}

bool VersionUnion::operator ==(const VersionUnion& rhs)
{
    return Compare(rhs) == 0;
}

bool VersionUnion::operator !=(const VersionUnion& rhs)
{
    return Compare(rhs) != 0;
}

bool VersionUnion::operator >(const VersionUnion& rhs)
{
    return Compare(rhs) > 0;
}

bool VersionUnion::operator >=(const VersionUnion& rhs)
{
    return Compare(rhs) >= 0;
}

bool VersionUnion::operator <(const VersionUnion& rhs)
{
    return Compare(rhs) < 0;
}

bool VersionUnion::operator <=(const VersionUnion& rhs)
{
    return Compare(rhs) <= 0;
}

INT32 VersionUnion::Compare(const VersionUnion& rhs) const
{
    INT32 result = 0;
    if (Version.Major > rhs.Version.Major)
    {
        result = 1;
    }
    else if (Version.Major < rhs.Version.Major)
    {
        result = -1;
    }
    else if (Version.Minor > rhs.Version.Minor)
    {
        result = 1;
    }
    else if (Version.Minor < rhs.Version.Minor)
    {
        result = -1;
    }
    else if (Version.Patch > rhs.Version.Patch)
    {
        result = 1;
    }
    else if (Version.Patch < rhs.Version.Patch)
    {
        result = -1;
    }

    return result;
}

ModeUnion::ModeUnion()
{
    Value = 0;
}

ModeUnion::ModeUnion(
    UINT64 value)
{
    Value = value;
}

ModeUnion::ModeUnion(
    UINT16 mode,
    UINT16 subMode,
    UINT32 group)
{
    Mode.Mode = mode;
    Mode.SubMode = subMode;
    Mode.Group = group;
}
