# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.feature2.qcfa SHARED
    ../../chifeature2qcfa.cpp
)

# Libraries to compile
target_link_libraries (com.qti.feature2.qcfa chiutils)
target_link_libraries (com.qti.feature2.qcfa com.qti.chi.override)
target_link_libraries (com.qti.feature2.qcfa com.qti.feature2.gs)
target_link_libraries (com.qti.feature2.qcfa camera_metadata)
target_link_libraries (com.qti.feature2.qcfa chilog)
target_link_libraries (com.qti.feature2.qcfa cutils)
#target_link_libraries (com.qti.feature2.qcfa hardware)
target_link_libraries (com.qti.feature2.qcfa log)
#target_link_libraries (com.qti.feature2.qcfa qdMetaData)
target_link_libraries (com.qti.feature2.qcfa sync)
target_link_libraries (com.qti.feature2.qcfa utils)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen
#add_dependencies(com.qti.feature2.qcfa autogen)

install(TARGETS com.qti.feature2.qcfa LIBRARY DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

