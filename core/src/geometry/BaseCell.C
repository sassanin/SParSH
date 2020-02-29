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
#include <vector>

SParSH_NAMESPACE_BEGIN

// Constructor
template <sint dim> 
TBaseCell<dim>::TBaseCell(TRefineDesc<dim> *refindesc)
{
 RefinDesc = refindesc;
 PhaseID = 0;
 N_Facets = (refindesc->GetCellDesc())->GetN_Facets();  
//  Facets.reserve(N_Facets);

//  for(int i=0; i< N_Facets ; ++i)
//   { 
    //   Facets.push_back(move(make_unique<nullptr>));
//    }

//   output(N_Facets);
//   output(Facets.size());

}

// explicit instantiation
template class TBaseCell<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END

