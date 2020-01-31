/** =======================================================================
* @Source    TMesh
* @brief     base class for Mesh 
* @author    Sashikumaar Ganesan 
* @date      17.01.2020
* @History   
* ===========================================================================*/
#include <SParSH_IO.h>
#include <Mesh.h>
#include <Vertex.h>
#include <iostream> 
#include <vector> 


using namespace std;

SParSH_NAMESPACE_BEGIN

template <sint dim> 
TMesh<dim>::TMesh(size_t N_Vertices) 
 {
  Vertices.reserve(N_Vertices);
 }


template <sint dim> 
void TMesh<dim>::AddBoundIDs(vector<size_t> && BDIDs)
{

 BoundIDs = move(BDIDs);

 /** Arracy contains the internal facets and boundary factes */ 
 Facets.resize(BoundIDs.size()+1);

//  for(size_t i_edge=0; i_edge<BoundIDs.size(); ++i_edge)
//        cout << "BDIDs[i] :" << BoundIDs[i_edge] << endl;

}// AddVertex

template <sint dim> 
size_t TMesh<dim>::GetBoundIndex(size_t BDID)
 {
  size_t i_edge;

  for( i_edge=0; i_edge<BoundIDs.size(); ++i_edge)
   if(BDID == BoundIDs[i_edge])
    { break; }

  try { if (i_edge == BoundIDs.size()) throw runtime_error("Could not find the BD for the given component");  }

  catch (exception &ex)
    { sarshpout(ex); exit(-1); }

  return (i_edge);
 }

// explicit instantiation
template class TMesh<GEO_DIM>;

SParSH_NAMESPACE_END
