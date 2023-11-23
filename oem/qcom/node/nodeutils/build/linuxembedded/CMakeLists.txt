# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( libcom.qti.chinodeutils SHARED
    ../../camxchinodeutil.cpp
)

# Libraries to compile
target_link_libraries (libcom.qti.chinodeutils camera_metadata)
target_link_libraries (libcom.qti.chinodeutils chilog)

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
#add_dependencies(libcom.qti.chinodeutils autogen)

install(TARGETS libcom.qti.chinodeutils LIBRARY DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

