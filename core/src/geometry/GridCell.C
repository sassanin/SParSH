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
 GlobalVertIndex.resize( (this->RefinDesc)->GetN_OrigVertices() );
 RegionID = 0;
}

template <sint dim> 
void TGridCell<dim>::WriteCell(std::ofstream &dat)
 {
  int N = size(GlobalVertIndex);
  dat <<  N << " ";
  for(int i=0; i<N; ++i) 
   dat << GlobalVertIndex[i] << " ";
  dat << endl;
 }

// explicit instantiation
template class TGridCell<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END
