#include <SParSH_IO.h>
#include <Facet.h>
// #include <Vertex.h>
// #include <iostream> 
// #include <vector> 

SParSH_NAMESPACE_BEGIN

template <sint dim> 
TFacet<dim>::TFacet()
 {
  Type = FacetType::NotAssigned;
  ID = 0;
  OwnCell = NULL;
  NeibCell = NULL;
 }
 
template <sint dim> 
TFacet<dim>::TFacet(FacetType type,  std::size_t id, std::size_t N_Vert,  std::size_t *Vindex)
 {
  Type = type;
  ID = id;

  for(std::size_t i; i<N_Vert ; ++i )
    {
     V.push_back(Vindex[i]);
    }

  OwnCell = NULL;
  NeibCell = NULL;
 }


// explicit instantiation
template class TFacet<GEO_DIM>;

SParSH_NAMESPACE_END
