# =======================================================================
# PURPOSE :  configuration file for the SParSH Version 1.1
# AUTHOR  : Sashikumaar Ganesan, CDS, IISc Bangalore, India
# DATE    : 05 June 2015
# ========================================================================

# normally no need to alter any thing in this file
# please DO NOT modify unless if it is necessary
# beginners are advised NOT to alter anything the below contents

cmake_minimum_required (VERSION 3.0)

project (SParSH)

include(${CMAKE_SOURCE_DIR}/UserConfig.cmake)

set (SParSH_VERSION_MAJOR 1)
set (SParSH_VERSION_MINOR 0)

SET(BUILD_SHARED_LIBS ON)
option(BUILD_DOC "Build documentation" ON)

# set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /opt/local/lib)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /opt/lib)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /opt/intel/mkl/lib/intel64)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} $ENV{HOME}/intel/mkl/lib/intel64)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} $ENV{HOME}/lib)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} $ENV{HOME}/software/lib)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} $ENV{HOME}/Software/lib)

set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} /opt/local/include)
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} /opt/include)
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} /opt/intel/mkl/include)
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} $ENV{HOME}/intel/mkl/include)
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} $ENV{HOME}/include)
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} $ENV{HOME}/software/include)
set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} $ENV{HOME}/Software/include)

# set(ENV{PKG_CONFIG_PATH} $ENV{PKG_CONFIG_PATH}:/opt/local/lib/pkgconfig )
set(SParSH_EXTLIB_PATH ${PROJECT_SOURCE_DIR}/crust/Ext_Lib)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/crust/CmakeModules/")

if(NOT "${SParSH_ARCH}" STREQUAL "CRAY64")
# search the blas in the system, if available it will be default
message("==================Searching BLAS in the System - begin===================================================")
if(SParSH_USE_SYSTEM_MKLBLAS)
    message("Searching MKL BLAS ...")
    find_package(MKLBLAS REQUIRED)
    include_directories(${BLAS_INCLUDE_DIRS})
    if(CMAKE_VERBOSE_MAKEFILE)
      if(BLAS_FOUND)
        message("Available system BLAS_LIB =${BLAS_LIBRARIES}")
      elseif(NOT BLAS_FOUND)
        message("MKL BLAS_NOT_FOUND in your system, searching ...")
      endif(BLAS_FOUND)
    endif(CMAKE_VERBOSE_MAKEFILE)  
endif(SParSH_USE_SYSTEM_MKLBLAS)

if(NOT BLAS_FOUND)
# if(SParSH_USE_SYSTEM_BLAS)
  find_package(BLAS)
  include_directories(${BLAS_INCLUDE_DIRS})
  if(CMAKE_VERBOSE_MAKEFILE)
    if(BLAS_FOUND)
      message("Available system BLAS_LIB =${BLAS_LIBRARIES}")
    elseif(NOT BLAS_FOUND)
       message("BLAS_NOT_FOUND in your system, BLAS must be linked before compiling")
    endif()
  endif()
# endif(SParSH_USE_SYSTEM_BLAS)
endif(NOT BLAS_FOUND)
message("==================Searching BLAS in the System - end=====================================================")

message("BLAS_LIBRARIES  = ${BLAS_LIBRARIES}")

if("${SParSH_PARALLEL_TYPE}" STREQUAL "MPI" OR "${SParSH_PARALLEL_TYPE}" STREQUAL "HYBRID" OR "${SParSH_PARALLEL_TYPE}" STREQUAL "SMPI")

#   message("==================Searching MPI in the System - begin===================================================")
find_package(MPI)

   if("${SParSH_MPI_IMPLEMENTATION}" STREQUAL "MPICH")
       set(MPI_LIBS -lmpich -lmpichf90 -lmpichcxx -lgfortran )
   elseif("${SParSH_MPI_IMPLEMENTATION}" STREQUAL "OPENMPI")
      set(MPI_LIBS -lmpi -lmpifort -lmpicxx)
   elseif("${SParSH_MPI_IMPLEMENTATION}" STREQUAL "INTELMPI")
      set(MPI_LIBS -lifcore)    
       message("Available MPI_LIBS =${MPI_LIBS}")
   elseif("${SParSH_MPI_IMPLEMENTATION}" STREQUAL "MACMPI")
     set(MPI_LIBS -lmpich -lmpichf90 -lmpichcxx)             
   endif("${SParSH_MPI_IMPLEMENTATION}" STREQUAL "MPICH")   

message(" MPI_LIBS " = ${MPI_LIBS})

 # search the MUMPS in the system, if available it wil be default
 message("==================Searching MUMPS in the System - begin=====================================================")
 find_package(MUMPS)
 include_directories(${MUMPS_INCLUDE_DIRS})
 if(CMAKE_VERBOSE_MAKEFILE)
  if(MUMPS_FOUND)
    message("Available system MUMPS_LIB =${MUMPS_LIBRARIES}")
  elseif(NOT MUMPS_FOUND)
    message(FATAL_ERROR "MUMPS_NOT_FOUND in your system or in the SParSH")
  endif()
 endif()
 message("==================Searching MUMPS in the System - end=======================================================")

endif("${SParSH_PARALLEL_TYPE}" STREQUAL "MPI" OR "${SParSH_PARALLEL_TYPE}" STREQUAL "HYBRID" OR "${SParSH_PARALLEL_TYPE}" STREQUAL "SMPI")

endif(NOT "${SParSH_ARCH}" STREQUAL "CRAY64")

# search the UMFPACK in the system, if available it wil be default
message("==================Searching UMFPACK in the System - begin===================================================")
find_package(UMFPACK)
include_directories(${UMFPACK_INCLUDE_DIRS})
if(CMAKE_VERBOSE_MAKEFILE)
  if(UMFPACK_FOUND)
    message("Available system UMFPACK_LIB =${UMFPACK_LIBRARIES}")
  elseif(NOT UMFPACK_FOUND)
    message(FATAL_ERROR "UMFPACK_NOT_FOUND in your system or in the SParSH")
  endif(UMFPACK_FOUND)
endif(CMAKE_VERBOSE_MAKEFILE)
message("==================Searching UMFPACK in the System - end=====================================================")

# search the GRIDGEN in the system, if available it wil be default
message("==================Searching GRIDGEN in the System - begin==================================================")
find_package(GRIDGEN)
include_directories(${GRIDGEN_INCLUDE_DIRS})
if(CMAKE_VERBOSE_MAKEFILE)
  if(GRIDGEN_FOUND)
    message("Available system GRIDGEN_LIB =${GRIDGEN_LIBRARIES}")
  elseif(NOT GRIDGEN_FOUND)
    message(FATAL_ERROR "GRIDGEN_NOT_FOUND in your system or in the SParSH")
  endif()
endif()
message("==================Searching GRIDGEN in the System - end====================================================")

# search the TETGEN in the system, if available it wil be default
if("${SParSH_GEO}" STREQUAL "3D")
  message("==================Searching TETGEN in the System - begin==================================================")
  find_package(TETGEN)
  include_directories(${TETGEN_INCLUDE_DIRS})
  if(CMAKE_VERBOSE_MAKEFILE)
    if(TETGEN_FOUND)
      message("Available system TETGEN_LIB =${TETGEN_LIBRARIES}")
    elseif(NOT TETGEN_FOUND)
      message(FATAL_ERROR "TETGEN_NOT_FOUND in your system or in the SParSH")
    endif()
  endif()
message("==================Searching TETGEN in the System - end======================================================")
endif("${SParSH_GEO}" STREQUAL "3D")

if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
    set(CMAKE_C_FLAGS   "${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

# search the TECPLOT in the system, if available it wil be default
message("==================Searching TECPLOT in the System - begin==================================================")
find_package(TECPLOT)
include_directories(${TECPLOT_INCLUDE_DIRS})
if(CMAKE_VERBOSE_MAKEFILE)
  if(TECPLOT_FOUND)
    message("Available system TECPLOT_LIB =${TECPLOT_LIBRARIES}")
  elseif(NOT TECPLOT_FOUND)
    message(FATAL_ERROR "TECPLOT_NOT_FOUND in your system or in the SParSH")
  endif()
endif()
message("==================Searching TECPLOT in the System - end====================================================")


# select the compiler type,
# CMAKE_BUILD_TYPE [DEBUG|RELEASE|RELWITHDEBINFO|MINSIZEREL]
set(CMAKE_BUILD_TYPE DEBUG CACHE STRING "options")
set(SParSH_INCLUDE )

include (CMakeForceCompiler)
  set(CMAKE_SYSTEM_NAME ${SParSH_ARCH})
  
if("${SParSH_ARCH}" STREQUAL "MAC64")
  if("${SParSH_PARALLEL_TYPE}" STREQUAL "MPI"  OR "${SParSH_PARALLEL_TYPE}" STREQUAL "HYBRID" OR "${SParSH_PARALLEL_TYPE}" STREQUAL "SMPI")
    find_path(MPI_CPATH   mpicc-mpich-mp)
    set(CMAKE_C_COMPILER ${MPI_CPATH}/mpicc-mpich-mp)
    find_path(MPI_CXXPATH   mpicxx-mpich-mp)  
    set(CMAKE_CXX_COMPILER ${MPI_CXXPATH}/mpicxx-mpich-mp)      
  elseif("${SParSH_PARALLEL_TYPE}" STREQUAL "SEQUENTIAL"  OR "${SParSH_PARALLEL_TYPE}" STREQUAL "OMPONLY")
    find_path(CPATH  clang)
    set(CMAKE_C_COMPILER ${CPATH}/clang  )
    find_path(CXXPATH clang++)  
    set(CMAKE_CXX_COMPILER ${CXXPATH}/clang++)  
  endif("${SParSH_PARALLEL_TYPE}" STREQUAL "MPI"  OR "${SParSH_PARALLEL_TYPE}" STREQUAL "HYBRID" OR "${SParSH_PARALLEL_TYPE}" STREQUAL "SMPI")
elseif("${SParSH_ARCH}" STREQUAL "LINUX64")
  if("${SParSH_PARALLEL_TYPE}" STREQUAL "MPI"  OR "${SParSH_PARALLEL_TYPE}" STREQUAL "HYBRID" OR "${SParSH_PARALLEL_TYPE}" STREQUAL "SMPI")
    find_path(MPI_CPATH   mpicc)
    set(CMAKE_C_COMPILER ${MPI_CPATH}/mpicc)
    find_path(MPI_CXXPATH   mpicxx)  
    set(CMAKE_CXX_COMPILER ${MPI_CXXPATH}/mpicxx)      
  elseif("${SParSH_PARALLEL_TYPE}" STREQUAL "SEQUENTIAL"  OR "${SParSH_PARALLEL_TYPE}" STREQUAL "OMPONLY")
    find_path(CPATH  gcc)
    set(CMAKE_C_COMPILER ${CPATH}/gcc)
    find_path(CXXPATH g++)  
    set(CMAKE_CXX_COMPILER ${CXXPATH}/g++)  
  endif("${SParSH_PARALLEL_TYPE}" STREQUAL "MPI"  OR "${SParSH_PARALLEL_TYPE}" STREQUAL "HYBRID" OR "${SParSH_PARALLEL_TYPE}" STREQUAL "SMPI")
elseif("${SParSH_ARCH}" STREQUAL "INTEL64")
  if("${SParSH_PARALLEL_TYPE}" STREQUAL "MPI"  OR "${SParSH_PARALLEL_TYPE}" STREQUAL "HYBRID" OR "${SParSH_PARALLEL_TYPE}" STREQUAL "SMPI")
    find_path(MPI_CPATH   mpiicc)
    set(CMAKE_C_COMPILER ${MPI_CPATH}/mpiicc)
    find_path(MPI_CXXPATH   mpiicpc)  
    set(CMAKE_CXX_COMPILER ${MPI_CXXPATH}/mpiicpc)      
  elseif("${SParSH_PARALLEL_TYPE}" STREQUAL "SEQUENTIAL"  OR "${SParSH_PARALLEL_TYPE}" STREQUAL "OMPONLY")
    include_directories("/opt/intel/include")
    find_path(CPATH  icc)
    set(CMAKE_C_COMPILER ${CPATH}/icc)
    find_path(CXXPATH icpc)  
    set(CMAKE_CXX_COMPILER ${CXXPATH}/icpc)  
  endif("${SParSH_PARALLEL_TYPE}" STREQUAL "MPI"  OR "${SParSH_PARALLEL_TYPE}" STREQUAL "HYBRID" OR "${SParSH_PARALLEL_TYPE}" STREQUAL "SMPI")  
elseif("${SParSH_ARCH}" STREQUAL "CRAY64")
    find_path(CPATH cc)
    set(CMAKE_C_COMPILER ${CPATH}/cc)
    find_path(CXXPATH CC)  
    set(CMAKE_CXX_COMPILER ${CXXPATH}/CC)  
endif()

# set the define for compiler  options
  set(CMAKE_C_FLAGS "${SParSH_C_DEF}")
  set(CMAKE_C_FLAGS_DEBUG "-g ${SParSH_C_DEF}")
  set(CMAKE_C_FLAGS_RELEASE "O3 -s  ${SParSH_C_DEF}")
  set(CMAKE_CXX_FLAGS "${SParSH_CXX_DEF} " )
  set(CMAKE_CXX_FLAGS_DEBUG "$ -v {SParSH_CXX_DEF} ")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -s ${SParSH_CXX_DEF}") 
 
 include_directories("${CMAKE_SOURCE_DIR}/crust/include/common")
 include_directories("${CMAKE_SOURCE_DIR}/core/include/geometry")
# include_directories("${CMAKE_SOURCE_DIR}/include/QuadFormulas")
# include_directories("${CMAKE_SOURCE_DIR}/include/FE1D")
# include_directories("${CMAKE_SOURCE_DIR}/include/FE2D")
# include_directories("${CMAKE_SOURCE_DIR}/include/FE3D")
# include_directories("${CMAKE_SOURCE_DIR}/include/AMG")
# include_directories("${CMAKE_SOURCE_DIR}/include/PBE")
# include_directories("${CMAKE_SOURCE_DIR}/include/Refinement")
# include_directories("${CMAKE_SOURCE_DIR}/include/System")
# include_directories("${CMAKE_SOURCE_DIR}/include/Parallel")
# include_directories("${CMAKE_SOURCE_DIR}/Examples")

# add_subdirectory(src/AMG) 
# add_subdirectory(src/Refinement) 
# add_subdirectory(src/QuadFormulas)  
# add_subdirectory(src/Geometry)          
 add_subdirectory(crust/src/common) 
 add_subdirectory(core/src/geometry) 
# add_subdirectory(src/System) 
# add_subdirectory(src/PBE) 

# if("${SParSH_PARALLEL_TYPE}" STREQUAL "MPI"  OR "${SParSH_PARALLEL_TYPE}" STREQUAL "HYBRID" OR "${SParSH_PARALLEL_TYPE}" STREQUAL "SMPI")
#    add_subdirectory(src/Parallel) 
# endif("${SParSH_PARALLEL_TYPE}" STREQUAL "MPI"  OR "${SParSH_PARALLEL_TYPE}" STREQUAL "HYBRID" OR "${SParSH_PARALLEL_TYPE}" STREQUAL "SMPI")

add_executable(SParSH_${SParSH_GEO}_${SParSH_PARALLEL_TYPE}.exe  ${SParSH_MODEL})

# if( "${SParSH_PARALLEL_TYPE}" STREQUAL "MPI"  OR "${SParSH_PARALLEL_TYPE}" STREQUAL "HYBRID" OR "${SParSH_PARALLEL_TYPE}" STREQUAL "SMPI" )
#    target_link_libraries(SParSH_${SParSH_GEO}_${SParSH_PARALLEL_TYPE}.exe "sys" "par" "geo"  "fe" "gen" "geo" "fe" "gen"  
#                       "amg"  "quad" "ref" "geo" "fe" "quad" "geo"  ${UMFPACK_LIBRARIES} ${TECPLOT_LIBRARIES}
#                       ${MPIBLACS_LIBRARIES}  ${TETGEN_LIBRARIES} ${GRIDGEN_LIBRARIES}  ${MUMPS_LIBRARIES}   ${BLAS_LIBRARIES} ${MPI_LIBS})  
# elseif( "${SParSH_PARALLEL_TYPE}" STREQUAL "SEQUENTIAL"  OR "${SParSH_PARALLEL_TYPE}" STREQUAL "OMPONLY")
#    target_link_libraries(SParSH_${SParSH_GEO}_${SParSH_PARALLEL_TYPE}.exe "sys" "geo"  "fe" "gen" "geo" "fe" "gen"  
#                       "amg"  "quad" "ref" "geo" "fe" "quad" "geo"  ${UMFPACK_LIBRARIES} ${TECPLOT_LIBRARIES}
#                       ${BLAS_LIBRARIES} ${TETGEN_LIBRARIES} ${GRIDGEN_LIBRARIES} )
# endif("${SParSH_PARALLEL_TYPE}" STREQUAL "MPI"  OR "${SParSH_PARALLEL_TYPE}" STREQUAL "HYBRID" OR "${SParSH_PARALLEL_TYPE}" STREQUAL "SMPI")

target_link_libraries(SParSH_${SParSH_GEO}_${SParSH_PARALLEL_TYPE}.exe  "geo" "common" "geo" "common" ${UMFPACK_LIBRARIES} ${TECPLOT_LIBRARIES}
                              ${BLAS_LIBRARIES} ${TETGEN_LIBRARIES} ${GRIDGEN_LIBRARIES} )

message("============================================================================================================"  )  
message("SParSH_GEO=${SParSH_GEO}")
message("SParSH_MODEL=${SParSH_MODEL}")
message("SParSH_ARCH=${SParSH_ARCH}")
message("SParSH_PARALLEL_TYPE=${SParSH_PARALLEL_TYPE}")
message("C_COMPILER=${CMAKE_C_COMPILER}")
message("CXX_COMPILER=${CMAKE_CXX_COMPILER}")
message("SParSH_CXX_DEF=${SParSH_CXX_DEF}")
message("EXE_FILE=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/SParSH_${SParSH_GEO}_${SParSH_PARALLEL_TYPE}.exe")
message("============================================================================================================"  )        
message("Configuration for the SParSH Version 1.0")  
message("         Sashikumaar Ganesan")
message("         Dept. of Computational & Data Sciences")
message("         Indian Institute of Science, Bangalore, India")  
message("mailto : sashi-AT-iisc.ac.in") 
message("============================================================================================================"  ) 




