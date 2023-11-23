# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.feature2.memcpy SHARED
    ../../chifeature2memcpy.cpp
)

# Libraries to compile
target_link_libraries (com.qti.feature2.memcpy chiutils)
target_link_libraries (com.qti.feature2.memcpy com.qti.chi.override)
target_link_libraries (com.qti.feature2.memcpy com.qti.feature2.gs)
target_link_libraries (com.qti.feature2.memcpy camera_metadata)
target_link_libraries (com.qti.feature2.memcpy chilog)
target_link_libraries (com.qti.feature2.memcpy cutils)
#target_link_libraries (com.qti.feature2.memcpy hardware)
target_link_libraries (com.qti.feature2.memcpy log)
#target_link_libraries (com.qti.feature2.memcpy qdMetaData)
target_link_libraries (com.qti.feature2.memcpy sync)
target_link_libraries (com.qti.feature2.memcpy utils)

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
#add_dependencies(com.qti.feature2.memcpy autogen)

install(TARGETS com.qti.feature2.memcpy LIBRARY DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

