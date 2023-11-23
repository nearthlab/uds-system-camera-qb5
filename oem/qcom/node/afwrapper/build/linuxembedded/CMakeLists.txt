# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.stats.afwrapper SHARED
    ../../src/afwrapper.cpp
)

# Libraries to compile
target_link_libraries (com.qti.stats.afwrapper camxosutils)
target_link_libraries (com.qti.stats.afwrapper camxutils)
target_link_libraries (com.qti.stats.afwrapper camxgenerated)
target_link_libraries (com.qti.stats.afwrapper dl)
target_link_libraries (com.qti.stats.afwrapper cutils)
target_link_libraries (com.qti.stats.afwrapper log)
target_link_libraries (com.qti.stats.afwrapper offlinelog)
target_link_libraries (com.qti.stats.afwrapper sync)
target_link_libraries (com.qti.stats.afwrapper camximageformatutils)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)
include_directories (${CAMX_CHICDK_API_PATH}/common)
include_directories (${CAMX_CHICDK_API_PATH}/stats)
include_directories (${CAMX_CHICDK_OEM_PATH}/qcom/node/afwrapper/inc)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen
#add_dependencies(com.qti.stats.afwrapper autogen)

install(TARGETS com.qti.stats.afwrapper LIBRARY DESTINATION lib/${CAMX_LIB_OUTPUT_PATH})

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

