# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.node.stich SHARED
    ../../camxchinodedummystich.cpp
)

# Libraries to compile
target_link_libraries (com.qti.node.stich camera_metadata)
target_link_libraries (com.qti.node.stich chilog)
target_link_libraries (com.qti.node.stich dl)
target_link_libraries (com.qti.node.stich libcom.qti.chinodeutils)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen
#add_dependencies(com.qti.node.stich autogen)

install(TARGETS com.qti.node.stich LIBRARY DESTINATION lib/${CAMX_LIB_OUTPUT_PATH})

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

