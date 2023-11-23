# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( libcamerapostproc SHARED
    ../../chiofflinejpegencode.cpp
    ../../chiofflinepostprocencode.cpp
    ../../chiofflinepostprocintf.cpp
)

# Libraries to compile
target_link_libraries (libcamerapostproc com.qti.chi.override)
target_link_libraries (libcamerapostproc com.qti.feature2.generic)
target_link_libraries (libcamerapostproc com.qti.feature2.gs)
target_link_libraries (libcamerapostproc camera_metadata)
target_link_libraries (libcamerapostproc chilog)
target_link_libraries (libcamerapostproc log)
#target_link_libraries (libcamerapostproc qdMetaData)
target_link_libraries (libcamerapostproc sync)
target_link_libraries (libcamerapostproc dl)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)
include_directories (${CAMX_CHICDK_OEM_PATH}/qcom/feature2/chifeature2anchorsync)
include_directories (${CAMX_CHICDK_OEM_PATH}/qcom/feature2/chifeature2generic)
include_directories (${CAMX_CHICDK_OEM_PATH}/qcom/feature2/chifeature2graphselector)
include_directories (${CAMX_CHICDK_OEM_PATH}/qcom/feature2/chifeature2hdr)
include_directories (${CAMX_CHICDK_OEM_PATH}/qcom/feature2/chifeature2mfsr)
include_directories (${CAMX_CHICDK_OEM_PATH}/qcom/feature2/chifeature2qcfa)
include_directories (${CAMX_CHICDK_OEM_PATH}/qcom/feature2/chifeature2rt)
include_directories (${CAMX_CHICDK_OEM_PATH}/qcom/feature2/chifeature2swmf)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen

install(TARGETS libcamerapostproc LIBRARY DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

