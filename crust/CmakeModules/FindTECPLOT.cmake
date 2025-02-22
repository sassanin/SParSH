# ===================================================================
# This is FindTECPLOT.cmake file for SParSH Version 1.0
# written by Sashikumaar Ganesan, CDS, IISc Bangalore, India
# date: 28 Dec 2019
# searching for a TECPLOT lib in the system 
# if found, this will define
#  TECPLOT_FOUND - System has TECPLOT
#  TECPLOT_INCLUDE_DIRS - The TECPLOT include directories
#  TECPLOT_LIBRARIES - The libraries needed to use TECPLOT
# ===================================================================
if(TECPLOT_INCLUDES AND TECPLOT_LIBRARIES)
  set(TECPLOT_FIND_QUIETLY TRUE)
endif(TECPLOT_INCLUDES AND TECPLOT_LIBRARIES)

if(NOT TECPLOT_FOUND)
  find_path(TECPLOT_INCLUDE_DIR   TECIO.h PATHS $ENV{TECPLOTDIR}/include ${CMAKE_INCLUDE_PATH})
  find_library(TECPLOT_LIBRARY NAMES tecio PATHS $ENV{TECPLOTDIR}/lib ${CMAKE_LIBRARY_PATH})
  get_filename_component(TECPLOT_LIBDIR ${TECPLOT_LIBRARY} PATH)
     
     
     
  if(NOT TECPLOT_LIBRARY)
    message("TECPLOT not found in the system, so checking the availability in SParSH for the selected SParSH_ARCH=${SParSH_ARCH}")
    find_path(TECPLOT_INCLUDE_DIR  TECIO.h PATHS ${SParSH_EXTLIB_PATH}/tecplot/include)
    find_library(TECPLOT_LIBRARY NAMES tecio_${SParSH_ARCH} PATHS ${SParSH_EXTLIB_PATH}/tecplot/lib)
  endif(NOT TECPLOT_LIBRARY)
  
  if(TECPLOT_LIBRARY)      
    # set TECPLOT
    if(TECPLOT_LIBRARY)
      include(FindPackageHandleStandardArgs)
    
      set(TECPLOT_LIBRARIES ${TECPLOT_LIBRARY})
      set(TECPLOT_INCLUDE_DIRS ${TECPLOT_INCLUDE_DIR})

      # handle the QUIETLY and REQUIRED arguments and set TECPLOT_FOUND to TRUE
      # if all listed variables are TRUE
      find_package_handle_standard_args(TECPLOT  DEFAULT_MSG
                                        TECPLOT_LIBRARY TECPLOT_INCLUDE_DIR)

      mark_as_advanced(TECPLOT_INCLUDE_DIR TECPLOT_LIBRARY)
    endif(TECPLOT_LIBRARY)  
  endif()

endif()


