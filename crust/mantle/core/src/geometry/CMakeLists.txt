

include_directories("${CMAKE_SOURCE_DIR}/crust/mantle/core/include/geometry")

file(GLOB_RECURSE GEN_SOURCES "${PROJECT_SOURCE_DIR}/crust/mantle/core/include/geometry/*.C")
 
 
add_library(geo STATIC ${GEN_SOURCES})

