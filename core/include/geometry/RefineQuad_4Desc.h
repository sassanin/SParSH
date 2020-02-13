/** =======================================================================
* @class     TRefineQuad_4Desc
* @brief     refinement descriptor for Quad_4
* @author    Sashikumaar Ganesan 
* @date      13.02.2020
* @History   
===========================================================================*/
#include <RefineDesc.h>
#include <CellDesc.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim> 
class TRefineQuad_4Desc : public TRefineDesc<dim>
{
  protected:

  public:
    // Constructor
    /** \brief build a descriptor for regular refinement of a quad_4 */
    TRefineQuad_4Desc(TCellDesc<dim> *celldesc);

    // Methods
};

SParSH_NAMESPACE_END