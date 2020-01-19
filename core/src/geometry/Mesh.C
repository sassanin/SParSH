#include <SParSH_IO.h>
#include <Mesh.h>
#include <Vertex.h>
#include <iostream> 
#include <vector> 

SParSH_NAMESPACE_BEGIN

template <sint dim> 
TMesh<dim>::TMesh(int N_Vertices) 
 {
  Vertices.reserve(N_Vertices);
 }


template <sint dim> 
void TMesh<dim>::AddVertex(std::shared_ptr< TVertex<GEO_DIM>> &Vert)
{

 Vertices.push_back(Vert);

}// AddVertex


// explicit instantiation
template class TMesh<GEO_DIM>;

SParSH_NAMESPACE_END
