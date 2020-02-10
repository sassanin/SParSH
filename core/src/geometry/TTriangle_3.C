
/** =======================================================================
* @class     TTriangle_3
* @brief     TRI_3 (element) descriptors source 
* @author    Sashikumaar Ganesan 
* @date      06.02.2020
* @History   
===========================================================================*/

#include <Triangle_3.h>

SParSH_NAMESPACE_BEGIN

using namespace std; 


 
// Constructor
template <sint dim> 
TTriangle_3<dim>::TTriangle_3()
{
 static constexpr sint DatEdgeVertex[3][2] = { {0, 1},  {1, 2},  {2, 0}};
 static constexpr sint DatVertexEdge[3][2] = { {2, 0},  {0, 1},  {1, 2}};

 this->Type = CellType::TRI_3;
 this->N_Vertices = 3;   
 this->N_Edges = 3;   
 this->N_Facets = 3;    
 this->EdgeType = CellType::LINE_2;     
 this->MaxN_EpV = 2;
 this->EdgeVertex = (const sint *) DatEdgeVertex;
 this->VertexEdge = (const sint *) DatVertexEdge;   
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
template class TTriangle_3<GEO_DIM>;

SParSH_NAMESPACE_END
