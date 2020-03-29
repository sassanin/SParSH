/** =======================================================================
* @class     TBaseCell
* @brief     BaseCell source 
* @author    Sashikumaar Ganesan 
* @date      20.02.2020
* @History   
===========================================================================*/
#include <BaseCell.h>
#include <vector>

SParSH_NAMESPACE_BEGIN

// Constructor
template <sint dim> 
TBaseCell<dim>::TBaseCell(TRefineDesc<dim> *refindesc)
{
 RefinDesc = refindesc;
 PhaseID = 0; 
 Facets.resize((RefinDesc->GetCellDesc())->GetN_Facets(), nullptr);
}

// explicit instantiation
template class TBaseCell<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END

