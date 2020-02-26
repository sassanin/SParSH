/** =======================================================================
* @class     TGridCell
* @brief     BaseCell source 
* @author    Sashikumaar Ganesan 
* @date      20.02.2020
* @History   
===========================================================================*/
#include <GridCell.h>

SParSH_NAMESPACE_BEGIN

// Constructor
template <sint dim> 
TGridCell<dim>::TGridCell(TRefineDesc<dim> *refindesc, int reflevel) : TBaseCell<dim>(refindesc)
{
 GlobalVertIndex.reserve( (this->RefinDesc)->GetN_OrigVertices() );
}

// explicit instantiation
template class TGridCell<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END
