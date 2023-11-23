# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.feature2.rawhdr SHARED
    ../../chifeature2rawhdr.cpp
)

# Libraries to compile
target_link_libraries (com.qti.feature2.rawhdr chiutils)
target_link_libraries (com.qti.feature2.rawhdr com.qti.chi.override)
target_link_libraries (com.qti.feature2.rawhdr com.qti.feature2.gs)
target_link_libraries (com.qti.feature2.rawhdr camera_metadata)
target_link_libraries (com.qti.feature2.rawhdr chilog)
target_link_libraries (com.qti.feature2.rawhdr cutils)
#target_link_libraries (com.qti.feature2.rawhdr hardware)
target_link_libraries (com.qti.feature2.rawhdr log)
#target_link_libraries (com.qti.feature2.rawhdr qdMetaData)
target_link_libraries (com.qti.feature2.rawhdr sync)
target_link_libraries (com.qti.feature2.rawhdr utils)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen
#add_dependencies(com.qti.feature2.rawhdr autogen)

install(TARGETS com.qti.feature2.rawhdr LIBRARY DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

