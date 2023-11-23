# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.stats.aecwrapper SHARED
    ../../src/aecwrapper.cpp
)

# Libraries to compile
target_link_libraries (com.qti.stats.aecwrapper camxosutils)
target_link_libraries (com.qti.stats.aecwrapper camxutils)
target_link_libraries (com.qti.stats.aecwrapper camxgenerated)
target_link_libraries (com.qti.stats.aecwrapper dl)
target_link_libraries (com.qti.stats.aecwrapper cutils)
target_link_libraries (com.qti.stats.aecwrapper log)
target_link_libraries (com.qti.stats.aecwrapper offlinelog)
target_link_libraries (com.qti.stats.aecwrapper sync)
target_link_libraries (com.qti.stats.aecwrapper camximageformatutils)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)
include_directories (${CAMX_CHICDK_API_PATH}/common)
include_directories (${CAMX_CHICDK_API_PATH}/stats)
include_directories (${CAMX_CHICDK_OEM_PATH}/qcom/node/aecwrapper/inc)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen
#add_dependencies(com.qti.stats.aecwrapper autogen)

install(TARGETS com.qti.stats.aecwrapper LIBRARY DESTINATION lib/${CAMX_LIB_OUTPUT_PATH})

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

