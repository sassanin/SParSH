/**=======================================================================
// @brief     routines for IO
// @author    Sashikumaar Ganesan, 
// @date      02/01/2020
// =======================================================================*/

#include<iostream> 
#include<tuple> 

#ifndef __VERTEX__
#define __VERTEX__

namespace SParSHMesh
{

template <typename dim>
class Vertex {

  protected:
    int N_Vertices;

    vector< tuple <double, double> > V; 

};


} // namespace SParSHMesh
