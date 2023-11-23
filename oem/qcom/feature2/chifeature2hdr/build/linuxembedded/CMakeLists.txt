# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.feature2.hdr SHARED
    ../../chifeature2hdr.cpp
)

# Libraries to compile
target_link_libraries (com.qti.feature2.hdr chiutils)
target_link_libraries (com.qti.feature2.hdr com.qti.chi.override)
target_link_libraries (com.qti.feature2.hdr com.qti.feature2.gs)
target_link_libraries (com.qti.feature2.hdr camera_metadata)
target_link_libraries (com.qti.feature2.hdr chilog)
target_link_libraries (com.qti.feature2.hdr cutils)
#target_link_libraries (com.qti.feature2.hdr hardware)
target_link_libraries (com.qti.feature2.hdr log)
#target_link_libraries (com.qti.feature2.hdr qdMetaData)
target_link_libraries (com.qti.feature2.hdr sync)
target_link_libraries (com.qti.feature2.hdr utils)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen
#add_dependencies(com.qti.feature2.hdr autogen)

install(TARGETS com.qti.feature2.hdr LIBRARY DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

