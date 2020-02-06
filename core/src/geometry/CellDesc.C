#include <SParSH_IO.h>
#include <CellDesc.h>

SParSH_NAMESPACE_BEGIN


 
// Constructor
template <sint dim> 
TCellDesc<dim>::TCellDesc()
{
 Type = CellType::NOT_DEFINED;
 N_Vertices = 0;   
 N_Edges = 0;   
 N_Facets = 0;    
 EdgeType = CellType::NOT_DEFINED;     
 MaxN_EpV = 0;
 EdgeVertex = nullptr;
 VertexEdge = nullptr;  
}

// explicit instantiation
template class TCellDesc<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END
