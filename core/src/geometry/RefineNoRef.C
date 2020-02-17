/** =======================================================================
* @class     TRefineNoRef
* @brief     NoRef source 
* @author    Sashikumaar Ganesan 
* @date      17.02.2020
* @History   
===========================================================================*/

#include <RefineNoRef.h>

SParSH_NAMESPACE_BEGIN

using namespace std; 

// Constructor
template <sint dim> 
TRefineNoRef<dim>::TRefineNoRef(TCellDesc<dim> *celldesc) : TRefineDesc<dim>(celldesc)
{
#ifdef __2D__
  #define MAXN_ORIGEDGES    4
#else
  #define MAXN_ORIGEDGES   12
#endif

 static RefineType DatEdgeType[MAXN_ORIGEDGES];
 
 for (size_t i=0; i<MAXN_ORIGEDGES; ++i)
  DatEdgeType[i] = RefineType::NotDefined;

}

// explicit instantiation
template class TRefineNoRef<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END
