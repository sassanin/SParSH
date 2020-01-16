/** =======================================================================
*
* @class     TVertex
* @brief     base class for vertex 
* @author    Sashikumaar Ganesan 
* @date      02.01.2020
* @History   
===========================================================================*/

#include<tuple> 
#include <vector>

#pragma once

namespace SParSHMesh {
template <int dim> 
class TVertex {

  private: 
   //std::vector<T> elems[dim]; 
   double V[dim]; 
 
  public:
    // Constructors
//#ifdef __3D__
    //  TVertex(double X, double Y, double Z);
//#elif __2D__
      TVertex(double X, double Y);

      void SetCoords(double X, double Y);
//#else
   //   TVertex(double X);
//#endif

};


template <int dim>
TVertex<dim>::TVertex(double X, double Y) 
{
 V[0] = X;
 V[1] = Y;

 cout << "TVert " << X << ", " << Y <<endl; 
}

#include "Vertex.C"

} // namespace SParSHMesh

//#endif