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

template <sint dim, bool BD_Vert=false> 
class TVertex {

  private: 
   double V[dim]; 
 
  public:
  
  // Constructors
  TVertex(double *X);

  //methods 
  void SetCoords(double *X);
  
  void GetCoords(double *X);

  double* GetCoordsPtr()
  { return V; }
  
  bool IsBoundVert();

};

SParSH_NAMESPACE_END