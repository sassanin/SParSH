/** =======================================================================
* @class     TRefineTria_3Desc
* @brief     refinement descriptor for Tria_3
* @author    Sashikumaar Ganesan 
* @date      13.02.2020
* @History   
===========================================================================*/
#include <RefineDesc.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim> 
class TRefineTria_3Desc : public TRefineDesc<dim>
{
  protected:

  public:
    // Constructor
    /** \brief build a descriptor for regular refinement of a line */
    TRefineTria_3Desc(TCellDesc<dim> *celldesc);

    // Methods
};

SParSH_NAMESPACE_END