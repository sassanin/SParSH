/**=======================================================================
// @brief     Constants and definitions defined in SParSH
// @author    Sashikumaar Ganesan, 
// @date      04/01/2020
// =======================================================================*/

#include <math.h>


#ifndef __SParSH_Variables__
#define __SParSH_Variables__

#define SParSH_NAMESPACE_BEGIN namespace SParSH {
#define SParSH_NAMESPACE_END }


/**=======================================================================
 * Information about SParSH:
=======================================================================*/
#define SParSH_PACKAGE_NAME "@SParSH_PACKAGE_NAME@"

#define SParSH_PACKAGE_VERSION "@SParSH_PACKAGE_VERSION@"
#define SParSH_VERSION_MAJOR @SParSH_VERSION_MAJOR@
#define SParSH_VERSION_MINOR @SParSH_VERSION_MINOR@
#define SParSH_VERSION_SUBMINOR @SParSH_VERSION_SUBMINOR@

/**=======================================================================
 * mesh configuration
=======================================================================*/

 /** based on https://cgns.github.io/CGNS_docs_current/sids/conv.html#unstructgrid */
  enum class CellType {LINE_2, LINE3, LINE_4, LINE_5,
                       TRI_3, TRI_6, 	TRI_9, TRI_12,
                       QUAD_4, QUAD_8, QUAD_9, QUAD_12, QUAD_16, QUAD_P4_16, 
                       TETRA_4, TETRA_10, TETRA_16, TETRA_20, TETRA_22,
                       PYRA_5, PYRA_13, PYRA_14, PYRA_21, PYRA_29, PYRA_30, PYRA_P4_29, 
                       PENTA_6, PENTA_15, PENTA_18, PENTA_24, PENTA_38, PENTA_40,  PENTA_33,
                       HEXA_8, HEXA_20, HEXA_27, HEXA_32 };


/**=======================================================================
 * general configuration
=======================================================================*/

#ifdef NULL
  #undef NULL
#endif
#define NULL nullptr

#define sint uint_fast8_t

#ifdef __3D__
#define GEO_DIM 3
#else
#define GEO_DIM 2
#endif

constexpr double ln2() { 
  return log(2.0); 
  } 

enum class boolean {FALSE, TRUE};

enum class GridCellType {tirangle};


#endif


