
/** =======================================================================
* @class     TRefineDesc
* @brief     RefineDesc descriptors source 
* @author    Sashikumaar Ganesan 
* @date      07.02.2020
* @History   
===========================================================================*/

#include <RefineDesc.h>

SParSH_NAMESPACE_BEGIN

using namespace std; 

// Constructor
template <sint dim> 
TRefineDesc<dim>::TRefineDesc()
{
//  this->Type = CellType::TRI_3;
//  this->N_Vertices = 3;   
//  this->N_Edges = 3;   
//  this->N_Facets = 3;    
//  this->EdgeType = CellType::LINE_2;     
//  this->MaxN_EpV = 2;
//  this->EdgeVertex = (const int *) DatEdgeVertex;
//  this->VertexEdge = (const int *) DatVertexEdge;   
}

// Methods
// template <sint dim> 
// double TTriangle_3<dim>::GetMeasure(SParSH::TVertex<dim> **Verts)
// {
  // double x1,x2,y1,y2;

  // x1 = Verts[0]->GetX();
  // y1 = Verts[0]->GetY();
  // x2 = Verts[1]->GetX();
  // y2 = Verts[1]->GetY();

  // return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
// }


// explicit instantiation
template class TRefineDesc<GEO_DIM>;

SParSH_NAMESPACE_END
