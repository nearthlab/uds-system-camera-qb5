# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( chilog SHARED
    ../../chxdebugprint.cpp
)

# Libraries to compile
target_link_libraries (chilog cutils)
target_link_libraries (chilog log)
target_link_libraries (chilog sync)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)
include_directories (${CAMX_CHICDK_API_PATH}/utils)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen

install(TARGETS chilog LIBRARY DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

