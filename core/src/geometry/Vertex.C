#include <SParSH_IO.h>
#include <Vertex.h>

namespace SParSHMesh
{

//#ifdef __3D__


//#elif __2D__
void TVertex::SetCoords(double X, double Y) 
{
 V[0] = X;
 V[1] = Y;

 cout << "TVert Set Coord" << X << ", " << Y <<endl; 
}

//#else
     

//#endif


} // namespace SParSHMesh