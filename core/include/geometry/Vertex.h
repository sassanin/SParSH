/** =======================================================================
* @class     TVertex
* @brief     base class for vertex 
* @author    Sashikumaar Ganesan 
* @date      02.01.2020
* @History   
===========================================================================*/

#include <SParSH_Variables.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim=SParSH::GEO_DIM, bool BD_Vert=false> 
class TVertex {

  private: 
  
  /** \brief V[] contains the coordinats of the vertex */
   double V[dim]; 
 
  public:
  
  /** \brief  Default constructor with coordinates of the vertex */
  TVertex(double *X);

  //methods 

  /** \brief  Assign/Change the coordinates of the vertex */
  void SetCoords(double *X);

  /** \brief  Copy and return the coordinates of the vertex */
  void GetCoords(double *X);

  /** \brief  Return the address of the vertex */
  double* GetCoordsPtr()
  { return V; }
  
  /** \brief  Return the type (bpoundary vertex or not) of the vertex */
  bool IsBoundVert();

};

SParSH_NAMESPACE_END