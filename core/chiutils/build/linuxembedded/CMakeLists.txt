# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( chiutils
    ../../chxutils.cpp
    ../../chxperf.cpp
    ../../chxmetadata.cpp
)

# Libraries to compile
target_link_libraries (chiutils chilog)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)
include_directories (${CAMX_EXT_INCLUDE}/hardware/libhardware/include/) #to include hardware/hardware.h
#include_directories (${CAMX_CHICDK_API_PATH}/node/)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen

install(TARGETS chiutils ARCHIVE DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

