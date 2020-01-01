

include_directories("${CMAKE_SOURCE_DIR}/crust/include/common")

file(GLOB_RECURSE GEN_SOURCES "${PROJECT_SOURCE_DIR}/crust/src/common/*.C")
 
 
add_library(common STATIC ${GEN_SOURCES})

