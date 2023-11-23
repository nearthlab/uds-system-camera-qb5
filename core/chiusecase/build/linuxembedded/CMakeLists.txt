# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( chiusecase
    ../../chxadvancedcamerausecase.cpp
    ../../chxusecasedefault.cpp
    ../../chxusecasemc.cpp
    ../../chxusecasevrmc.cpp
    #../../chxusecasesuperslowmotionfrc.cpp
    ../../chxusecasetorch.cpp
    ../../chxusecaseutils.cpp
    ../../chxusecasedual.cpp
)

# Libraries to compile
target_link_libraries (chiusecase chifeature2)
target_link_libraries (chiusecase chilog)
target_link_libraries (chiusecase gbm)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)
include_directories (${CAMX_CHICDK_API_PATH}/utils)
include_directories (${CAMX_CHICDK_OEM_PATH}/qcom/feature2/chifeature2graphselector)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen

install(TARGETS chiusecase ARCHIVE DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

