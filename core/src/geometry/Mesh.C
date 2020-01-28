#include <SParSH_IO.h>
#include <Mesh.h>
#include <Vertex.h>
#include <iostream> 
#include <vector> 

SParSH_NAMESPACE_BEGIN

template <sint dim> 
TMesh<dim>::TMesh(size_t N_Vertices) 
 {
  Vertices.reserve(N_Vertices);
 }


template <sint dim> 
void TMesh<dim>::AddBoundIDs(vector<std::size_t> && BDIDs)
{
 BoundIDs = std::move(BDIDs);

//  for(std::size_t i_edge=0; i_edge<BDIDs.size(); ++i_edge)
//        cout << "BDIDs[i] :" << BDIDs[i_edge] << endl;

}// AddVertex


// explicit instantiation
template class TMesh<GEO_DIM>;

SParSH_NAMESPACE_END
