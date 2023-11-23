# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.feature2.rt SHARED
    ../../chifeature2realtime.cpp
)

# Libraries to compile
target_link_libraries (com.qti.feature2.rt chiutils)
target_link_libraries (com.qti.feature2.rt com.qti.chi.override)
target_link_libraries (com.qti.feature2.rt com.qti.feature2.gs)
target_link_libraries (com.qti.feature2.rt camera_metadata)
target_link_libraries (com.qti.feature2.rt chilog)
target_link_libraries (com.qti.feature2.rt cutils)
#target_link_libraries (com.qti.feature2.rt hardware)
target_link_libraries (com.qti.feature2.rt log)
#target_link_libraries (com.qti.feature2.rt qdMetaData)
target_link_libraries (com.qti.feature2.rt sync)
target_link_libraries (com.qti.feature2.rt utils)

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
#add_dependencies(com.qti.feature2.rt autogen)

install(TARGETS com.qti.feature2.rt LIBRARY DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

