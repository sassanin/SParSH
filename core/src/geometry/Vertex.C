#include <SParSH_IO.h>
#include <Vertex.h>

SParSH_NAMESPACE_BEGIN

template <sint dim, bool BD_Vert> 
TVertex<dim, BD_Vert>::TVertex(double *X) 
 {
  for(sint i=0;i<dim;++i) { 
   V[i] = X[i]; 
  }
 }

template <sint dim, bool BD_Vert> 
void TVertex<dim, BD_Vert>::SetCoords(double *X) 
 {
  for(sint i=0;i<dim;++i) { 
   V[i] = X[i]; 
  }
 }

template <sint dim, bool BD_Vert> 
void TVertex<dim, BD_Vert>::GetCoords(double *X) 
 {
  for(sint i=0;i<dim;++i) { 
   X[i] = V[i]; 
  }
 }

template <sint dim, bool BD_Vert> 
bool TVertex<dim, BD_Vert>::IsBoundVert() 
 {
  return BD_Vert;
 }

// explicit instantiation
 template class TVertex<SParSH::GEO_DIM>;


SParSH_NAMESPACE_END
