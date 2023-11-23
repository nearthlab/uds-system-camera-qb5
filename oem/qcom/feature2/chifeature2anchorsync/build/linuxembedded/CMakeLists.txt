# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.feature2.anchorsync SHARED
    ../../chifeature2anchorsync.cpp
)

# Libraries to compile
target_link_libraries (com.qti.feature2.anchorsync chiutils)
target_link_libraries (com.qti.feature2.anchorsync com.qti.chi.override)
target_link_libraries (com.qti.feature2.anchorsync com.qti.feature2.gs)
target_link_libraries (com.qti.feature2.anchorsync camera_metadata)
target_link_libraries (com.qti.feature2.anchorsync chilog)
target_link_libraries (com.qti.feature2.anchorsync cutils)
#target_link_libraries (com.qti.feature2.anchorsync hardware)
target_link_libraries (com.qti.feature2.anchorsync log)
#target_link_libraries (com.qti.feature2.anchorsync qdMetaData)
target_link_libraries (com.qti.feature2.anchorsync sync)
target_link_libraries (com.qti.feature2.anchorsync utils)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)
include_directories (${CAMX_CHICDK_CORE_PATH}/chifeature2)
include_directories (${CAMX_CHICDK_CORE_PATH}/chiframework)
include_directories (${CAMX_CHICDK_CORE_PATH}/chiusecase)
include_directories (${CAMX_CHICDK_CORE_PATH}/chiutils)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen
#add_dependencies(com.qti.feature2.anchorsync autogen)

install(TARGETS com.qti.feature2.anchorsync LIBRARY DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

