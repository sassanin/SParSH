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

#define Line_2_MaxN_EpV  1

template <sint dim> 
class TLine_2 : TCellDesc<dim>
{
 protected:

  public:
  
  // Constructors
  TLine_2();
    
  //methods 

  // /** \brief return diameter of a cell */
  // virtual double GetDiameter(SParSH::TVertex **Verts)
  // { return 0; }

  // /** \brief return shortest edge of a cell */
  // virtual double GetShortestEdge(TVertex **Verts)
  // { return 0;  }  

  // /** \brief return the length of the cell defined with the reference map */
  // virtual double GetLengthWithReferenceMap(TVertex **Verts)
  // { return 0; }  

  // /** \brief return measure of a cell */
  // virtual double GetMeasure(TVertex **Verts);

};

SParSH_NAMESPACE_END