# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.feature2.swmf SHARED
    ../../chifeature2swmf.cpp
)

# Libraries to compile
target_link_libraries (com.qti.feature2.swmf chiutils)
target_link_libraries (com.qti.feature2.swmf com.qti.chi.override)
target_link_libraries (com.qti.feature2.swmf com.qti.feature2.gs)
target_link_libraries (com.qti.feature2.swmf camera_metadata)
target_link_libraries (com.qti.feature2.swmf chilog)
target_link_libraries (com.qti.feature2.swmf cutils)
#target_link_libraries (com.qti.feature2.swmf hardware)
target_link_libraries (com.qti.feature2.swmf log)
#target_link_libraries (com.qti.feature2.swmf qdMetaData)
target_link_libraries (com.qti.feature2.swmf sync)
target_link_libraries (com.qti.feature2.swmf utils)

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
#add_dependencies(com.qti.feature2.swmf autogen)

install(TARGETS com.qti.feature2.swmf LIBRARY DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

