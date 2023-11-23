////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2019 Qualcomm Technologies, Inc.
/// All Rights Reserved.
/// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CHIFEATURE2TESTBASE_H
#define CHIFEATURE2TESTBASE_H

#include "chifeature2base.h"
#include "chifeature2types.h"
#include "chxmetadata.h"

#include "bayer2yuvinputdata.h"
#include "chifeature2test.h"

class ChiFeature2TestBase
{
public:
    enum Feature2Type
    {
        Bayer2Yuv,
        MFNR,
        HDR
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ChiFeature2TestBase
    ///
    /// @param pTest    The test object that will be used to check and assert conditions.
    ///
    /// @brief Default constructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ChiFeature2TestBase(
        ChiFeature2Test* pTest);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// ~ChiFeature2TestBase
    ///
    /// @brief Default destructor
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ~ChiFeature2TestBase();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Initialize
    ///
    /// @param Feature2Type    Feature for which this test case need to be initialized
    ///
    /// @brief Initialize all the required variables required for test
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VOID Initialize(
        Feature2Type feature2Type);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// Uninitialize
    ///
    /// @brief Uninitialize/cleanup here once test is done
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VOID Uninitialize();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetFeature2Descriptor
    ///
    /// @param pFeature2DescriptorOut    [out] Feature descriptor to create the feature
    ///
    /// @brief get feature descriptor which will be used to create the feature
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VOID GetFeature2Descriptor(
        ChiFeature2CreateInputInfo* pFeature2DescriptorOut);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// GetInputFeature2RequestObject
    ///
    /// @param pFeature2Base               [in] Feature2base pointer
    ///
    /// @param ppFeature2RequestObjectOut  [out] Feature request object for this request
    ///
    /// @brief get input feature request object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VOID GetInputFeature2RequestObject(
        ChiFeature2Base*            pFeature2Base,
        ChiFeature2RequestObject**  ppFeature2RequestObjectOut,
        VOID*                       pPrivateData);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// PostProcessRequest
    ///
    /// @param feature2RequestObject    [in] Feature request object from process request
    ///
    /// @brief process on feature request object came back from ProcessRequest call
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VOID PostProcessRequest(
        ChiFeature2RequestObject* feature2RequestObject);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// RunTestFeature2
    ///
    /// @param Feature2Type    Feature for which this test case need to be initialized
    ///
    /// @brief main business logic to run the test
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    VOID RunTestFeature2(
        Feature2Type feature2Type);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// CreateMetadataManager
    ///
    /// @brief create metadata manager for metadata operations
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CDKResult CreateMetadataManager();

    /// Placeholder callback. Update once defined
    static VOID ChiFeature2TestCbInputRequest(
        ChiFeature2RequestObject*   pFeature2RequestObject,
        VOID*                       pPrivateCallbackData);

private:
    ChiFeature2Test*    m_pTest;                            ///< Test object
    Feature2Type        m_feature2Type;                     ///< Feature type
    ChiMetadataManager* m_pMetadataManager;                 ///< Metadata manager for metadata operations
    UINT32              m_genericMetadataClientId;          ///< Client id returned while creating metadata manager
    Mutex*              m_pFeature2RequestStateMutex;       ///< App Result mutex
    Condition*          m_pFeature2RequestStateComplete;
    static const UINT32 DefaultNumMetadataBuffers = 16;     ///< Default number of metadata buffers
};

#endif // CHIFEATURE2TESTBASE_H