/** =======================================================================
* @class     TRefineNoRef
* @brief     No refinement 
* @author    Sashikumaar Ganesan 
* @date      17.02.2020
* @History   
===========================================================================*/
#include <RefineDesc.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim> 
class TRefineNoRef : public TRefineDesc<dim>
{
  protected:

  public:
    // Constructor
    /** \brief build a descriptor for regular refinement of a line */
    TRefineNoRef(TCellDesc<dim> *celldesc);

    // Methods
};

SParSH_NAMESPACE_END