/** =======================================================================
* @class     TTriangle_3
* @brief     TRI_3 (element) descriptors
* @author    Sashikumaar Ganesan 
* @date      06.02.2020
* @History   
===========================================================================*/
#include <SParSH_Variables.h>
#include <CellDesc.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim> 
class TTriangle_3 : public TCellDesc<dim>
{
 protected:

  public:
  
  // Constructors
  TTriangle_3();
    
  //methods 

  /** \brief return diameter of a cell */
  double GetDiameter(SParSH::TVertex<dim> **Verts);

  /** \brief return shortest edge of a cell */
  double GetShortestEdge(SParSH::TVertex<dim> **Verts);  

  /** \brief return the length of the cell defined with the reference map */
  double GetLengthWithReferenceMap(SParSH::TVertex<dim> **Verts);
 
  /** \brief return measure of a cell */
  double GetMeasure(SParSH::TVertex<dim> **Verts);
};

SParSH_NAMESPACE_END