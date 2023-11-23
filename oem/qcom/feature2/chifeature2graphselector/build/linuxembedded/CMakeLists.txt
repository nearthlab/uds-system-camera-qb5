# User Variables
set (SUPPORT_FUNCTION_CALL_TRACE 1)

# NO DATA FOR SECTION: Custom additions (begin)

# Common Include
include (${CAMX_CHICDK_API_PATH}/../core/build/linuxembedded/common.cmake)

# Files and Build Type
add_library( com.qti.feature2.gs SHARED
   ../../chifeature2anchorsyncdescriptor.cpp
   ../../chifeature2bayer2yuvdescriptor.cpp
   ../../chifeature2demuxdescriptor.cpp
   ../../chifeature2frameselectdescriptor.cpp
   ../../chifeature2fusiondescriptor.cpp
   ../../chifeature2formatconvertordescriptor.cpp
   ../../chifeature2bokehdescriptor.cpp
   ../../chifeature2bpsdescriptor.cpp
   ../../chifeature2graphselector.cpp
   ../../${TARGET_PLATFORM}/chifeature2graphselectoroem.cpp
   ../../chifeature2graphdescriptors.cpp
   ../../chifeature2ipedescriptor.cpp
   ../../chifeature2jpegdescriptor.cpp
   ../../chifeature2mfnrdescriptor.cpp
   ../../chifeature2mfsrdescriptor.cpp
   ../../chifeature2oemgraphdescriptors.cpp
   ../../chifeature2realtimedescriptor.cpp
   ../../chifeature2hdrtype1descriptor.cpp
   ../../chifeature2rawhdrdescriptor.cpp
   ../../chifeature2serializerdescriptor.cpp
   ../../chifeature2swmfdescriptor.cpp
   ../../chifeature2memcpydescriptor.cpp
)

# Libraries to compile
target_link_libraries (com.qti.feature2.gs chiutils)
target_link_libraries (com.qti.feature2.gs com.qti.chi.override)
target_link_libraries (com.qti.feature2.gs camera_metadata)
target_link_libraries (com.qti.feature2.gs chilog)
target_link_libraries (com.qti.feature2.gs cutils)
#target_link_libraries (com.qti.feature2.gs hardware)
target_link_libraries (com.qti.feature2.gs log)
#target_link_libraries (com.qti.feature2.gs qdMetaData)
target_link_libraries (com.qti.feature2.gs sync)
target_link_libraries (com.qti.feature2.gs utils)

# Include Paths
include_directories (${CAMX_C_INCLUDES})
include_directories (../..)
include_directories (${CAMX_CHICDK_CORE_PATH}/chifeature2)
include_directories (${CAMX_CHICDK_CORE_PATH}/chiframework)
include_directories (${CAMX_CHICDK_CORE_PATH}/chiusecase)
include_directories (${CAMX_CHICDK_CORE_PATH}/chiutils)

# Dependencies


# Definitions
add_definitions (${CAMX_CFLAGS})
add_definitions (${CAMX_CPPFLAGS})
# NO DATA FOR SECTION: Custom additions (end)

# Auto-Gen
#add_dependencies(com.qti.feature2.gs autogen)

install(TARGETS com.qti.feature2.gs LIBRARY DESTINATION lib)

if (CONFIG STREQUAL "Debug")
    add_definitions( -g )
endif()

