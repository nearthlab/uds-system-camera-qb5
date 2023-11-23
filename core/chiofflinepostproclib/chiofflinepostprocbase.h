////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  chiofflinepostprocbase.h
/// @brief Post Processing Encoder Interface
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CHIOFFLINEPOSTPROCBASE_H
#define CHIOFFLINEPOSTPROCBASE_H

#include "chiofflinepostproctypes.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief  Base Class that defines Encoder interface
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChiFeature2PostProcBase
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destroy
    ///
    /// @brief  Function to destroy the encoder instance
    ///
    /// @return None
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual void Destroy() = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// PostProcess
    ///
    /// @brief  Function to post process the input and generate output as expected
    ///
    /// @param  pSessionParams  Pointer to session Params
    ///
    /// @return PostProcResultInfo structure
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual PostProcResultInfo PostProcess(
        PostProcSessionParams*   pSessionParams) = 0;

protected:

    PostProcResultInfo      m_output;       ///< Postprocessing output
    PostProcCreateParams    m_createParams; ///< Postproc Create Params

    virtual ~ChiFeature2PostProcBase()                                          = default;
    ChiFeature2PostProcBase()                                                   = default;

private:
    ChiFeature2PostProcBase(const ChiFeature2PostProcBase& rOther)              = delete;
    ChiFeature2PostProcBase(const ChiFeature2PostProcBase&& rrOther)            = delete;
    ChiFeature2PostProcBase& operator=(const ChiFeature2PostProcBase& rOther)   = delete;
    ChiFeature2PostProcBase& operator=(const ChiFeature2PostProcBase&& rrOther) = delete;

};

#endif // CHIOFFLINEPOSTPROCBASE_H