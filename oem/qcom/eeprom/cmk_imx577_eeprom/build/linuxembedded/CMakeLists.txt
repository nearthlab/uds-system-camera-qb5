# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.eeprom.cmk_imx577 SHARED
    ../../cmk_imx577_eeprom.cpp
)

# Libraries to compile

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)
include_directories (${CAMX_CHICDK_API_PATH}/sensor)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen
#add_dependencies(com.qti.eeprom.cmk_imx577 autogen)

install(TARGETS com.qti.eeprom.cmk_imx577 LIBRARY DESTINATION lib/camera)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

