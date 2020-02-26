/** =======================================================================
* @class     TBaseCell
* @brief     BaseCell source 
* @author    Sashikumaar Ganesan 
* @date      20.02.2020
* @History   
===========================================================================*/
#include <BaseCell.h>
// #include <CellDesc.h>
// #include <RefineDesc.h>

SParSH_NAMESPACE_BEGIN

// Constructor
template <sint dim> 
TBaseCell<dim>::TBaseCell(TRefineDesc<dim> *refindesc)
{
 RefinDesc = refindesc;
 int N_ = (refindesc->GetCellDesc())->GetN_Facets();  


//  Joints = new TJoint*[N_];


}

// explicit instantiation
template class TBaseCell<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END

