# User Variables
set (CHROMATIX_VERSION 0x0310)

set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qtistatic.stats.aec SHARED
    ../../src/camxstaticaecalgoimpl.cpp
)

# Libraries to compile
target_link_libraries (com.qtistatic.stats.aec camxosutils)
target_link_libraries (com.qtistatic.stats.aec camxutils)
target_link_libraries (com.qtistatic.stats.aec camxgenerated)
target_link_libraries (com.qtistatic.stats.aec chilog)
target_link_libraries (com.qtistatic.stats.aec dl)
target_link_libraries (com.qtistatic.stats.aec cutils)
target_link_libraries (com.qtistatic.stats.aec log)
target_link_libraries (com.qtistatic.stats.aec offlinelog)
target_link_libraries (com.qtistatic.stats.aec sync)
target_link_libraries (com.qtistatic.stats.aec camximageformatutils)


# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (${CAMX_CHICDK_API_PATH}/common)
include_directories (${CAMX_CHICDK_API_PATH}/stats)
include_directories (${CAMX_CHICDK_OEM_PATH}/qcom/node/staticaecalgo/inc)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen
#add_dependencies(com.qtistatic.stats.aec autogen)

install(TARGETS com.qtistatic.stats.aec LIBRARY DESTINATION lib/${CAMX_LIB_OUTPUT_PATH})

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

