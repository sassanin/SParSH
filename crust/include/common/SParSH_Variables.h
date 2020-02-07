/**=======================================================================
// @brief     Constants and definitions defined in SParSH
// @author    Sashikumaar Ganesan, 
// @date      04/01/2020
// =======================================================================*/
#include <stdint.h>
#include <math.h>

#pragma once

#define SParSH_NAMESPACE_BEGIN namespace SParSH {
#define SParSH_NAMESPACE_END }
#define sarshpout(x)  std::cout << " Exited @ File: " <<  __FILE__ << "("<< __LINE__ <<") " << " Reason: " <<  x.what() << "!\n"

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

// #define sint uint_fast8_t
#define sint size_t

SParSH_NAMESPACE_BEGIN
#ifdef __3D__
const sint Space_Dim = 3;
#define GEO_DIM Space_Dim
#elif __2D__  
const sint Space_Dim = 2;
#define GEO_DIM Space_Dim
#else
const sint Space_Dim = 1;
#define GEO_DIM Space_Dim
#endif

//constexpr double ln2() { 
//  return log(2.0); 
//  } 

enum class boolean {FALSE, TRUE};

enum class GridCellType {tirangle};


/**=======================================================================
 * mesh configuration
=======================================================================*/



SParSH_NAMESPACE_END


