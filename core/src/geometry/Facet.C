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
TFacet<dim>::TFacet(FacetType type, size_t id, size_t N_Vert, TVertex<dim> **Vert)
 {
  Type = type;
  ID = id;

  for(std::size_t i; i<N_Vert ; ++i )
    {
     Vertices.push_back(Vert[i]);
    }

  OwnCell = NULL;
  NeibCell = NULL;
 }


// explicit instantiation
template class TFacet<GEO_DIM>;

SParSH_NAMESPACE_END
