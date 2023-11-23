////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  chifeature2demux.h
/// @brief CHI anchorsync feature derived class declarations
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CHIFEATURE2DEMUX_H
#define CHIFEATURE2DEMUX_H


#include "chifeature2base.h"
#include "chxextensionmodule.h"

// NOWHINE FILE CP006:  used standard libraries for performance improvements

/// @brief demux private information
struct ChiFeature2DemuxPrivateInfo
{
    std::vector<UINT8> portMap;                 ///< Input dependency index to port map
    std::vector<VOID*> settingMap;              ///< Input dependency index to setting map
    std::vector<UINT8> requestIdMap;            ///< Input dependency index to output request id map
    UINT8              numInputDependency;      ///< Number of input dependency
    UINT8              numTotalDependency;      ///< Number of total dependency including Buffer & Metadata
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Feature derived class
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ChiFeature2Demux : public ChiFeature2Base
{
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Create
    ///
    /// @brief  Static function to create Demux feature
    ///
    /// @param  pCreateInputInfo   Pointer to create input info for Demux feature
    ///
    /// @return None
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static ChiFeature2Demux* Create(
        ChiFeature2CreateInputInfo* pCreateInputInfo);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Destroy
    ///
    /// @brief  Virtual method to destroy.
    ///
    /// @return None
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual VOID Destroy();

protected:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// OnInitialize
    ///
    /// @brief  Function creates Sessions and Pipelines based on input descriptor.
    ///         Derived features can override this to create sessions and pipelines or for virtual camx impl.
    ///
    /// @param  pCreateInputInfo  Feature create input information.
    ///
    /// @return CDKResultSuccess if successful or CDK error values in case of error.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CDKResult OnInitialize(
        ChiFeature2CreateInputInfo* pCreateInputInfo);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// OnPrepareRequest
    ///
    /// @brief  Virtual method to prepare request for anchorsync feature.
    ///
    /// @param  pRequestObject  Feature request object instance.
    ///
    /// @return CDKResultSuccess if successful or CDK error values in case of error.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CDKResult OnPrepareRequest(
        ChiFeature2RequestObject* pRequestObject) const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// OnExecuteProcessRequest
    ///
    /// @brief  Virtual method to execute request for anchorsync feature.
    ///
    /// @param  pRequestObject  Feature request object instance.
    ///
    /// @return CDKResultSuccess if successful or CDK error values in case of error.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CDKResult OnExecuteProcessRequest(
        ChiFeature2RequestObject* pRequestObject) const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// DoCleanupRequest
    ///
    /// @brief  Virtual method to cleanup request for Demux feature.
    ///
    /// @param  pRequestObject  Feature request object instance.
    ///
    /// @return CDKResultSuccess if successful or CDK error values in case of error.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CDKResult DoCleanupRequest(
        ChiFeature2RequestObject* pRequestObject) const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// DoFlush
    ///
    /// @brief  Virtual method to flush request for Demux feature.
    ///
    /// @return CDKResultSuccess if successful or CDK error values in case of error.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CDKResult DoFlush();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// OnPopulateDependencySettings
    ///
    /// @brief  populate Feature Settings
    ///
    /// @param  pRequestObject    Feature request object instance.
    /// @param  dependencyIndex   Dependency index
    /// @param  pSettingPortId    Metadata port id
    /// @param  pFeatureSettings  Metadata Setting
    ///
    /// @return CDKResultSuccess if successful or CDK error values in case of error.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual CDKResult OnPopulateDependencySettings(
        ChiFeature2RequestObject*     pRequestObject,
        UINT8                         dependencyIndex,
        const ChiFeature2Identifier*  pSettingPortId,
        ChiMetadata*                  pFeatureSettings
        ) const;

private:
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetNumOfInputDependency
    ///
    /// @brief  Method to get number of input dependency for Demux feature.
    ///
    /// @param  pRequestObject  Feature request object instance.
    ///
    /// @return Number of input dependency
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    UINT32 GetNumOfInputDependency(
        ChiFeature2RequestObject* pRequestObject) const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// BuildAndSubmitOutputInfo
    ///
    /// @brief  @brief  private method to build output data and notify downstream feature.
    ///
    /// @param  pRequestObject  Feature request object instance.
    ///
    /// @return CDKResultSuccess if successful or CDK error values in case of error.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CDKResult BuildAndSubmitOutputInfo(
        ChiFeature2RequestObject* pRequestObject) const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetOutputBuffer
    ///
    /// @brief  @brief  private method to get output port buffer from input port.
    ///
    /// @param  pRequestObject  Feature request object instance.
    /// @param  requestId       Request index.
    /// @param  outputId        Output port Id.
    /// @param  pTarget         The pointer of target
    ///
    /// @return CDKResultSuccess if successful or CDK error values in case of error.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CDKResult GetOutputBuffer(
        ChiFeature2RequestObject* pRequestObject,
        UINT8                     requestId,
        ChiFeature2Identifier     outputId,
        VOID*                     pTarget) const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ChiFeature2Demux
    ///
    /// @brief  Deafault constructor.
    ///
    /// @return None
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ChiFeature2Demux() = default;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ~ChiFeature2Demux
    ///
    /// @brief  Virtual destructor.
    ///
    /// @return None
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    virtual ~ChiFeature2Demux() = default;

    ChiFeature2Demux(const ChiFeature2Demux&) = delete;                       ///< Disallow the copy constructor
    ChiFeature2Demux& operator= (const ChiFeature2Demux&) = delete;           ///< Disallow assignment operator
};

#endif // CHIFEATURE2DEMUX_H