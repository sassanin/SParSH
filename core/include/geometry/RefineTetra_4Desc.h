/** =======================================================================
* @class     TRefineTetra_4Desc
* @brief     refinement descriptor for Tetra_4
* @author    Sashikumaar Ganesan 
* @date      14.02.2020
* @History   
===========================================================================*/
#ifdef __3D__

#include <RefineDesc.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim> 
class TRefineTetra_4Desc : public TRefineDesc<dim>
{
  protected:

  public:
    // Constructor
    /** \brief build a descriptor for regular refinement of a quad_4 */
    TRefineTetra_4Desc(TCellDesc<dim> *celldesc);

    // Methods
};

SParSH_NAMESPACE_END

#endif