/** =======================================================================
*
* @class     TVertex
* @brief     base class for vertex 
* @author    Sashikumaar Ganesan 
* @date      02.01.2020
* @History   
===========================================================================*/

#include<tuple> 

#ifndef __VERTEX__
#define __VERTEX__

namespace SParSHMesh {
template <class T, int dim> 
class TVertex {

  protected:
      T V[dim]; 

  public:
    // Constructors

//#ifdef __3D__
//      /** 3D vertex */
//      TVertex(double initX, double initY, double initZ)
//      { } ;
//#else
//      /** 2D vertex */ 
//      TVertex(double initX, double initY)
//      { };
//#endif




};

#include "Vertex.C"

} // namespace SParSHMesh
#endif