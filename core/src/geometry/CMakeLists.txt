

include_directories("${CMAKE_SOURCE_DIR}/core/include/geometry")

file(GLOB_RECURSE GEN_SOURCES "${PROJECT_SOURCE_DIR}/core/src/geometry/*.C")
 
 
add_library(geo STATIC ${GEN_SOURCES})

