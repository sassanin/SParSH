/** =======================================================================
* @class     TBaseCell
* @brief     BaseCell source 
* @author    Sashikumaar Ganesan 
* @date      20.02.2020
* @History   
===========================================================================*/
#include <BaseCell.h>

SParSH_NAMESPACE_BEGIN

// Constructor
template <sint dim> 
TBaseCell<dim>::TBaseCell()
{
 
}

// explicit instantiation
template class TBaseCell<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END
