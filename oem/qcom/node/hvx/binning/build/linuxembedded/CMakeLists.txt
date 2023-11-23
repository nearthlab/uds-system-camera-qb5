# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.hvx.binning SHARED
    ../../camxchihvxbinning.cpp
)

# Libraries to compile
target_link_libraries (com.qti.hvx.binning dl)
target_link_libraries (com.qti.hvx.binning chilog)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen
#add_dependencies(com.qti.hvx.binning autogen)

install(FILES
        ${CAMX_CHICDK_OEM_PATH}/qcom/node/hvx/binning/libdsp_streamer_binning.so
        DESTINATION lib/rfsa/adsp)
install(TARGETS com.qti.hvx.binning LIBRARY DESTINATION lib/${CAMX_LIB_OUTPUT_PATH})

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

