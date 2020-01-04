/** =======================================================================
*
* @class     TVertex
* @brief     base class for vertex 
* @author    Sashikumaar Ganesan 
* @date      02.01.2020
* @History   
===========================================================================*/

#include <SParSH_Variables.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <int dim> 
class TVertex {

  private: 
   double V[dim]; 
 
  public:
  
  // Constructors
#ifdef __3D__
     TVertex(double X, double Y, double Z);
#elif __2D__
      TVertex(double X, double Y);

 void SetCoords(double X, double Y);
#else
    //  TVertex(double X);
#endif

};

SParSH_NAMESPACE_END