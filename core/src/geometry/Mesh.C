#include <SParSH_IO.h>
#include <Mesh.h>

SParSH_NAMESPACE_BEGIN

template <sint dim> 
TMesh<dim>::TMesh(int N_Vertices) 
 {

//    Vertices.reserve(N_Vertices);

 }

// explicit instantiation
template class TMesh<GEO_DIM>;

SParSH_NAMESPACE_END
