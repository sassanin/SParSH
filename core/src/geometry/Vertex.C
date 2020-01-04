#include <SParSH_IO.h>
#include <Vertex.h>

SParSH_NAMESPACE_BEGIN

#ifdef __3D__
template <int dim>
TVertex<dim>::TVertex(double X, double Y, double Z) 
{
 V[0] = X;
 V[1] = Y;
 V[2] = Z;
cout << "TVert3d .C " << X << ", " << Y<< ", " << Z  <<endl; 
}

#elif __2D__
template <int dim>
TVertex<dim>::TVertex(double X, double Y) 
{
 V[0] = X;
 V[1] = Y;

cout << "TVert .C " << X << ", " << Y <<endl; 
}

void TVertex<2>::SetCoords(double X, double Y) {
 V[0] = X;
 V[1] = Y;

cout << "TVert  ln2()" << ln2() <<endl; 

cout << "TVert .C " << X << ", " << Y<<endl; 
} // void TVertex<2>::SetCoords 


#else
     

#endif

// explicit instantiations
template class TVertex<1>;
template class TVertex<2>;
template class TVertex<3>;

SParSH_NAMESPACE_END
