# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.feature2.stub SHARED
    ../../chifeature2stub.cpp
)

# Libraries to compile
target_link_libraries (com.qti.feature2.stub chiutils)
target_link_libraries (com.qti.feature2.stub com.qti.chi.override)
target_link_libraries (com.qti.feature2.stub com.qti.feature2.gs)
target_link_libraries (com.qti.feature2.stub camera_metadata)
target_link_libraries (com.qti.feature2.stub chilog)
target_link_libraries (com.qti.feature2.stub cutils)
#target_link_libraries (com.qti.feature2.stub hardware)
target_link_libraries (com.qti.feature2.stub log)
#target_link_libraries (com.qti.feature2.stub qdMetaData)
target_link_libraries (com.qti.feature2.stub sync)
target_link_libraries (com.qti.feature2.stub utils)

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
#add_dependencies(com.qti.feature2.stub autogen)

install(TARGETS com.qti.feature2.stub LIBRARY DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

