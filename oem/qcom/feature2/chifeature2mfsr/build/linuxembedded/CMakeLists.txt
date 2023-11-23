# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.feature2.mfsr SHARED
    ../../chifeature2hwmultiframe.cpp
)

# Libraries to compile
target_link_libraries (com.qti.feature2.mfsr chiutils)
target_link_libraries (com.qti.feature2.mfsr com.qti.chi.override)
target_link_libraries (com.qti.feature2.mfsr com.qti.feature2.gs)
target_link_libraries (com.qti.feature2.mfsr camera_metadata)
target_link_libraries (com.qti.feature2.mfsr chilog)
target_link_libraries (com.qti.feature2.mfsr cutils)
#target_link_libraries (com.qti.feature2.mfsr hardware)
target_link_libraries (com.qti.feature2.mfsr log)
#target_link_libraries (com.qti.feature2.mfsr qdMetaData)
target_link_libraries (com.qti.feature2.mfsr sync)
target_link_libraries (com.qti.feature2.mfsr utils)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)
include_directories (${CAMX_CHICDK_CORE_PATH}/chifeature2)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen
#add_dependencies(com.qti.feature2.mfsr autogen)

install(TARGETS com.qti.feature2.mfsr LIBRARY DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

