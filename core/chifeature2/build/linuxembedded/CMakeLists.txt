# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( chifeature2
    ../../chifeature2base.cpp
    ../../chifeature2baserequestflow.cpp
    ../../chifeature2featurepool.cpp
    ../../chifeature2graph.cpp
    ../../chifeature2graphmanager.cpp
    ../../chifeature2multistagedescriptor.cpp
    ../../chifeature2requestobject.cpp
    ../../chifeature2usecaserequestobject.cpp
    ../../chifeature2wrapper.cpp
    ../../chitargetbuffermanager.cpp
    ../../chithreadmanager.cpp
)

# Libraries to compile
target_link_libraries (chifeature2 offlinelog)
target_link_libraries (chifeature2 cutils)
target_link_libraries (chifeature2 chilog)
target_link_libraries (chifeature2 log)
target_link_libraries (chifeature2 sync)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)
include_directories (${CAMX_CHICDK_OEM_PATH}/qcom/feature2/chifeature2graphselector)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen

install(TARGETS chifeature2 ARCHIVE DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

