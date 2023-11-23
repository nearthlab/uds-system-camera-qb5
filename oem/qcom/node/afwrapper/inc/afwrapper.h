////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  afwrapper.h
/// @brief AF algorithm interface implementation wrappre header
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CAMXAF_H
#define CAMXAF_H

#include "chiafinterface.h"
#include "camxmoduleconfig.h"

/// @brief  Represents AF internal data
struct AFWrapperInternalDataType
{
    CHIAFAlgorithm         AFOps;         ///< AF algorithm interface function pointers
    StatsAlgorithmHandle    hAFAlgorithm;  ///< AF algorithm handle
};

#endif // CAMXAF_H