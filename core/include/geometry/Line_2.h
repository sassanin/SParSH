/** =======================================================================
* @class     TLINE_2
* @brief     LINE_2 (element) descriptors
* @author    Sashikumaar Ganesan 
* @date      15.01.2020
* @History   
===========================================================================*/
#include <SParSH_Variables.h>
#include <CellDesc.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim> 
class TLine_2 : public TCellDesc<dim>
{
 protected:

  public:
  
  // Constructors
  TLine_2();
    
  //methods 

  /** \brief return diameter of a cell */
  double GetDiameter(SParSH::TVertex<dim> **Verts)
  { return 0.; }

  /** \brief return shortest edge of a cell */
  double GetShortestEdge(SParSH::TVertex<dim> **Verts)
  { return 0.;  }  

  // /** \brief return the length of the cell defined with the reference map */
  double GetLengthWithReferenceMap(SParSH::TVertex<dim> **Verts)
  { return 0.; }  

  // /** \brief return measure of a cell */
  double GetMeasure(SParSH::TVertex<dim> **Verts);
};

SParSH_NAMESPACE_END