/** =======================================================================
* @class     TRefineLine_2Desc
* @brief     refinement descriptor for line
* @author    Sashikumaar Ganesan 
* @date      13.02.2020
* @History   
===========================================================================*/
#include <RefineDesc.h>
#include <CellDesc.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim> 
class TRefineLine_2Desc : public TRefineDesc<dim>
{
  protected:

  public:
    // Constructor
    /** \brief build a descriptor for regular refinement of a line */
    TRefineLine_2Desc(TCellDesc<dim> *celldesc);

    // Methods
};

SParSH_NAMESPACE_END