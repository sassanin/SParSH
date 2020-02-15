/** =======================================================================
* @class     TRefineHexa_8Desc.
* @brief     refinement descriptor for Hexa_8
* @author    Sashikumaar Ganesan 
* @date      15.02.2020
* @History   
===========================================================================*/
#ifdef __3D__

#include <RefineDesc.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim> 
class TRefineHexa_8Desc : public TRefineDesc<dim>
{
  protected:

  public:
    // Constructor
    /** \brief build a descriptor for regular refinement of a quad_4 */
    TRefineHexa_8Desc(TCellDesc<dim> *celldesc);

    // Methods
};

SParSH_NAMESPACE_END

#endif