/** =======================================================================
* @class     TQuadrangle_4
* @brief     QUAD_4 (element) descriptors
* @author    Sashikumaar Ganesan 
* @date      10.02.2020
* @History   
===========================================================================*/
#include <SParSH_Variables.h>
#include <CellDesc.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim> 
class TQuadrangle_4 : public TCellDesc<dim>
{
 protected:

  public:
  
  // Constructors
  TQuadrangle_4();
    
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