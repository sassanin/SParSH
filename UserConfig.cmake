# ===================================================================
# This is an user configuration file for Scalable PARallel numeica for Hetrogenious systems (SParSH) Version 1.0
# written by Sashikumaar Ganesan, CDS, IISc Bangalore, India
# date: 28 Dec 2018
# ===================================================================

# controlling the output messages
set(CMAKE_VERBOSE_MAKEFILE FALSE)

# selection of dimension (2D 3D)
 set(SParSH_GEO "3D" CACHE STRING "Change SParSH_GEO, to select the Dimensio of the problem")

 #...................................................................................................................................................
# select this line accordingly to include your main program
 set(SParSH_MODEL "${PROJECT_SOURCE_DIR}/2DModels/CD2D_SParSH.C" CACHE STRING "Enter to select the Main file of the model") 
# set(SParSH_MODEL "${PROJECT_SOURCE_DIR}/2DModels/TCD2D_SParSH.C" CACHE STRING "Enter to select the Main file of the model") 
# set(SParSH_MODEL "${PROJECT_SOURCE_DIR}/2DModels/TCD2D_SParSH_ALE.C" CACHE STRING "Enter to select the Main file of the model") 
# set(SParSH_MODEL "${PROJECT_SOURCE_DIR}/2DModels/NSE2D_SParSH.C" CACHE STRING "Enter to select the Main file of the model")
# set(SParSH_MODEL "${PROJECT_SOURCE_DIR}/2DModels/TNSE2D_SParSH.C" CACHE STRING "Enter to select the Main file of the model")


# set(SParSH_MODEL "${PROJECT_SOURCE_DIR}/3DModels/CD3D_SParSH.C" CACHE STRING "Enter to select the Main file of the model")
# set(SParSH_MODEL "${PROJECT_SOURCE_DIR}/3DModels/TCD3D_SParSH.C" CACHE STRING "Enter to select the Main file of the model")
# set(SParSH_MODEL "${PROJECT_SOURCE_DIR}/3DModels/NSE3D_SParSH.C" CACHE STRING "Enter to select the Main file of the model")
# set(SParSH_MODEL "${PROJECT_SOURCE_DIR}/3DModels/TNSE3D_SParSH.C" CACHE STRING "Enter to select the Main file of the model")
# set(SParSH_MODEL "${PROJECT_SOURCE_DIR}/3DModels/RTE_SParSH.C" CACHE STRING "Enter to select the Main file of the model")



# selection of architect type (LINUX64 MAC64 INTEL64 TYRONE64 CRAY64)
set(SParSH_ARCH "INTEL64" CACHE STRING "select the machine type")

#  selection of program type (SEQUENTIAL SMPI MPI OMPONLY HYBRID)
set(SParSH_PARALLEL_TYPE "SEQUENTIAL" CACHE STRING "select the parallel type")

#  selection of program type (MPICH OPENMPI INTELMPI CRAYMPI MACMPI)
set(SParSH_MPI_IMPLEMENTATION "INTELMPI" CACHE STRING "select the MPI Implementation type")
 
# set the path to save the exe file ....................................................................................
#.......................................................................................................................
set(SParSH_OUTPUT_DIR_PATH "${CMAKE_SOURCE_DIR}/../SParSH_Output/CD2D" CACHE STRING "select the model")
# set(SParSH_OUTPUT_DIR_PATH "${CMAKE_SOURCE_DIR}/../SParSH_Output/TCD2D" CACHE STRING "select the model")
# set(SParSH_OUTPUT_DIR_PATH "${CMAKE_SOURCE_DIR}/../SParSH_Output/NSE2D" CACHE STRING "select the model")
# set(SParSH_OUTPUT_DIR_PATH "${CMAKE_SOURCE_DIR}/../SParSH_Output/TNSE2D" CACHE STRING "select the model")
# set(SParSH_OUTPUT_DIR_PATH "${CMAKE_SOURCE_DIR}/../SParSH_Output/CD3D" CACHE STRING "select the model")
# set(SParSH_OUTPUT_DIR_PATH "${CMAKE_SOURCE_DIR}/../SParSH_Output/TCD3D" CACHE STRING "select the model")
# set(SParSH_OUTPUT_DIR_PATH "${CMAKE_SOURCE_DIR}/../SParSH_Output/NSE3D" CACHE STRING "select the model")
# set(SParSH_OUTPUT_DIR_PATH "${CMAKE_SOURCE_DIR}/../SParSH_Output/TNSE3D" CACHE STRING "select the model")
# set(SParSH_OUTPUT_DIR_PATH "${CMAKE_SOURCE_DIR}/../SParSH_Output/RTE" CACHE STRING "select the model")

set(USE_SParSH_DEFINE -D__PRIVATE__)

# CMAKE_BUILD_TYPE [ DEBUG | RELEASE | RELWITHDEBINFO | MINSIZEREL ]
set(EXE_BUILD_TYPE DEBUG)


# set FALSE, if you want to use libs provided in SParSH 
# if you set TRUE, it will search in all you lib paths and if not found, SParSH libs will be used
set(SParSH_USE_SYSTEM_MKLBLAS TRUE)
set(SParSH_USE_SYSTEM_UMFPACK TRUE)
set(SParSH_USE_SYSTEM_MUMPS TRUE)
set(SParSH_USE_SYSTEM_GRIDGEN TRUE)
set(SParSH_USE_SYSTEM_TETGEN TRUE)

# SET(DAI_WITH_BP ON CACHE BOOL "Belief Propagation" FORCE)
# ========================================================================================================================
# no need to change anyting after this line
# used only when ccmake or cmake-gui is used
# ========================================================================================================================
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${SParSH_OUTPUT_DIR_PATH}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SParSH_OUTPUT_DIR_PATH}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SParSH_OUTPUT_DIR_PATH})

set_property(CACHE SParSH_GEO PROPERTY STRINGS 2D 3D ) 

# selection of all main programs
if("${SParSH_GEO}" STREQUAL "2D")
  file(GLOB_RECURSE MAIN_SOURCES "${PROJECT_SOURCE_DIR}/2DModels/*.C")
  set_property(CACHE SParSH_MODEL PROPERTY STRINGS  ${MAIN_SOURCES})   
elseif("${SParSH_GEO}" STREQUAL "3D")
  file(GLOB_RECURSE MAIN_SOURCES "${PROJECT_SOURCE_DIR}/3DModels/*.C")
  set_property(CACHE SParSH_MODEL PROPERTY STRINGS  ${MAIN_SOURCES})  
endif()  

# selection of all architects
set_property(CACHE SParSH_ARCH PROPERTY STRINGS LINUX64 MAC64 INTEL64 TYRONE64 CRAY64)

# selection of all program types
set_property(CACHE SParSH_PARALLEL_TYPE PROPERTY STRINGS SEQUENTIAL SMPI MPI OMPONLY HYBRID)

# selection of all program types
set_property(CACHE SParSH_MPI_IMPLEMENTATION PROPERTY STRINGS MPICH OPENMPI INTELMPI CRAYMPI MACMPI)

# selection of all output folder
if("${SParSH_GEO}" STREQUAL "2D")
set_property(CACHE SParSH_OUTPUT_DIR_PATH PROPERTY STRINGS  ${CMAKE_SOURCE_DIR}/OutPut/cd2d  ${CMAKE_SOURCE_DIR}/OutPut/tcd2d  ${CMAKE_SOURCE_DIR}/OutPut/nse2d  ${CMAKE_SOURCE_DIR}/OutPut/tnse2d)
 elseif("${SParSH_GEO}" STREQUAL "3D")
set_property(CACHE SParSH_OUTPUT_DIR_PATH PROPERTY STRINGS  ${CMAKE_SOURCE_DIR}/OutPut/cd3d  ${CMAKE_SOURCE_DIR}/OutPut/tcd3d  ${CMAKE_SOURCE_DIR}/OutPut/nse3d  ${CMAKE_SOURCE_DIR}/OutPut/tnse3d)
endif()

# ======================================================================
# general settings
# ======================================================================
 if("${SParSH_PARALLEL_TYPE}" STREQUAL "MPI")
   set(SParSH_PRG_DEFINE "-D_PAR -D_MPIONLY -D_MPI")
 elseif("${SParSH_PARALLEL_TYPE}" STREQUAL "OMPONLY")
   set(SParSH_PRG_DEFINE "-D_PAR -D_OMPONLY -D_OMP")
 elseif("${SParSH_PARALLEL_TYPE}" STREQUAL "HYBRID")
   set(SParSH_PRG_DEFINE "-D_PAR -D_MPI -D_HYBRID")
 elseif("${SParSH_PARALLEL_TYPE}" STREQUAL "SEQUENTIAL")
    set(SParSH_PRG_DEFINE "-D_SEQ ")
  elseif("${SParSH_PARALLEL_TYPE}" STREQUAL "SMPI")
    set(SParSH_PRG_DEFINE "-D_SEQ -D_SMPI")
 endif()

 if("${SParSH_ARCH}" STREQUAL "LINUX64")
   set(SParSH_CXX_DEF "${SParSH_CXX_DEF} -std=c++1z -fopenmp")
   set(SParSH_C_DEF "  ${SParSH_C_DEF}  -DREDUCED -DNO_TIMER -DMKL_ILP64  ")
 elseif("${SParSH_ARCH}" STREQUAL "MAC64")
   set(SParSH_CXX_DEF "-std=c++1z  -stdlib=libc++ ${SParSH_CXX_DEF}  -fapple-pragma-pack -Wdeprecated-register  ")
   set(SParSH_C_DEF "  ${SParSH_C_DEF}  -DREDUCED -DNO_TIMER -DMKL_ILP64 -m64 -fapple-pragma-pack ")
 elseif("${SParSH_ARCH}" STREQUAL "INTEL64")
   set(SParSH_CXX_DEF "${SParSH_CXX_DEF}  -std=c++1z  -qopenmp ")
   set(SParSH_C_DEF "  ${SParSH_C_DEF}   -DREDUCED -DNO_TIMER -DMKL_ILP64 -m64  ")
 elseif("${SParSH_ARCH}" STREQUAL "TYRONE64")
   set(SParSH_CXX_DEF "${SParSH_CXX_DEF} -DREDUCED -DNO_TIMER")
   set(SParSH_C_DEF "  ${SParSH_C_DEF}  -DREDUCED -DNO_TIMER  -DMPICH_IGNORE_CXX_SEEK ")  
 elseif("${SParSH_ARCH}" STREQUAL "CRAY64")
   set(SParSH_CXX_DEF "${SParSH_CXX_DEF} -DMPICH_IGNORE_CXX_SEEK ")  
      set(SParSH_C_DEF "  ${SParSH_C_DEF}  -DREDUCED -DNO_TIMER -DMPICH_IGNORE_CXX_SEEK  ")
 endif()
 
set(SParSH_C_DEF " ${SParSH_C_DEF} -D__${SParSH_GEO}__ -D__${SParSH_ARCH}__  -DTRILIBRARY -DTETLIBRARY  ${SParSH_PRG_DEFINE} ${USE_SParSH_DEFINE}") 
set(SParSH_CXX_DEF " ${SParSH_CXX_DEF} -D__${SParSH_GEO}__ -D__${SParSH_ARCH}__  -DTRILIBRARY -DTETLIBRARY ${SParSH_PRG_DEFINE} ${USE_SParSH_DEFINE}")
