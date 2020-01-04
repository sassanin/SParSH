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
 * general configuration
=======================================================================*/

#ifdef NULL
  #undef NULL
#endif
#define NULL nullptr

#ifdef __3D__
#define GEO_DIM 3
#else
#define GEO_DIM 2
#endif

constexpr double ln2() { 
  return log(2.0); 
  } 

 enum class boolean {FALSE, TRUE};


#endif


