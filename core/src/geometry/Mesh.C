/** =======================================================================
* @Source    TMesh
* @brief     base class source for Mesh 
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
TMesh<dim>::TMesh() 
 {
  N_InnerFacets = 0;
  N_InterfaceFacts = 0;
  N_BoundaryFacts = 0;   
 }

/** generate the coll of raw ptrs and share it */
template <sint dim> 
vector<reference_wrapper<TGridCell<dim>>> TMesh<dim>::GetCollection() 
{
  size_t N_Cells = Cells.size();

  // output(N_Cells);
  
  if(CellsRefs.size()==0 && N_Cells!=0)
   {
    for (auto ptr : Cells) 
     {
      CellsRefs.push_back(std::ref(*ptr));
     }
   }

  return CellsRefs;
}


/** Writing the vertices in the give dat file */
template <sint dim>   
void TMesh<dim>::WriteMesh(std::ofstream &dat)
{
 double X[dim];
 size_t N_V = Vertices.size();
 dat << "POINTS " << N_V << " float" << endl;

 for(auto V : Vertices)
  V->WriteVert(dat); 

 dat << endl;

 size_t N_E = Cells.size();
 size_t N_LocalVertices = 0;
 for(auto E : Cells)
   N_LocalVertices += E->GetN_Vertices();

 dat << "CELLS " << N_E << " " <<  N_E+N_LocalVertices << endl;

 for(auto E : Cells)
  E->WriteCell(dat); 

  dat << endl;
  dat << "CELL_TYPES " << N_E << endl;
  for(auto E : Cells)
   dat << E->GetVTKType()<< " ";

  dat << endl << endl;
  dat << "CELL_DATA " << N_E << endl;

  // standard output writing
  dat << "SCALARS " << "RegionID";
  dat << " float"<< endl;
  dat << "LOOKUP_TABLE " << "default" << endl;
  for(auto E : Cells)
   dat << E->GetRegionID()<< endl;

  // dat << "POINT_DATA " << N_V << endl;
  //     dat << "SCALARS " << "Test";
  //     dat << " float"<< endl;
  //     dat << "LOOKUP_TABLE " << "default" << endl;
  //     for(int j=0;j<N_V;j++)
  //       dat <<1.0 << endl;

  
  dat << endl << endl;
 
} // WriteMesh(


// template <sint dim> 
// void TMesh<dim>::AddBoundIDs(vector<size_t> && BDIDs)
// {

//  BoundIDs = move(BDIDs);

//  /** Array contains the internal facets and boundary factes */ 
//  Facets.reserve(BoundIDs.size()+1);

// //  for(size_t i_edge=0; i_edge<BoundIDs.size(); ++i_edge)
// //        cout << "BDIDs[i] :" << BoundIDs[i_edge] << endl;

// }// AddVertex

// template <sint dim> 
// size_t TMesh<dim>::GetBoundIndex(size_t BDID)
//  {
//   size_t i_edge;

//   for( i_edge=0; i_edge<BoundIDs.size(); ++i_edge)
//    if(BDID == BoundIDs[i_edge])
//     { break; }

//   try { if (i_edge == BoundIDs.size()) throw runtime_error("Could not find the BD for the given component");  }

//   catch (exception &ex)
//     { sarshpout(ex); exit(-1); }

//   return (i_edge);
//  }

// explicit instantiation
template class TMesh<GEO_DIM>;

SParSH_NAMESPACE_END
