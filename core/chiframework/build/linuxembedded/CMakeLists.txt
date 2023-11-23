# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.chi.override SHARED
    ../../chxextensioninterface.cpp
    ../../chxextensionmodule.cpp
    ../../chxfeature.cpp
    ../../chxmulticamcontroller.cpp
    ../../chxmultifovzoomratiocontroller.cpp
    ../../chxpipeline.cpp
    ../../chxsensorselectmode.cpp
    ../../chxsession.cpp
    ../../chxusecase.cpp
    ../../chxzoomtranslator.cpp
)

# Libraries to compile
target_link_libraries (com.qti.chi.override chifeature2)
target_link_libraries (com.qti.chi.override chiutils)
target_link_libraries (com.qti.chi.override chiusecase)
target_link_libraries (com.qti.chi.override camera_metadata)
target_link_libraries (com.qti.chi.override chilog)
target_link_libraries (com.qti.chi.override cutils)
#target_link_libraries (com.qti.chi.override hardware)
target_link_libraries (com.qti.chi.override log)
target_link_libraries (com.qti.chi.override sync)
target_link_libraries (com.qti.chi.override utils)

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

install(TARGETS com.qti.chi.override LIBRARY DESTINATION lib/hw)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

