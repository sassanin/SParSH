
/** =======================================================================
* @class     TLINE_2
* @brief     LINE_2 (element) descriptors source 
* @author    Sashikumaar Ganesan 
* @date      15.01.2020
* @History   
===========================================================================*/

#include <Line_2.h>
 
SParSH_NAMESPACE_BEGIN

using namespace std; 
 
// Constructor
template <sint dim> 
TLine_2<dim>::TLine_2()
{
 static constexpr sint DatEdgeVertex[1][2] = { {0, 1}};
 static constexpr sint DatVertexEdge[2][1] = { {0}, {0}};

 this->MaxN_EpV = 1;
 this->EdgeVertex = (const sint *) DatEdgeVertex;
 this->VertexEdge = (const sint *) DatVertexEdge;
 this->Type = CellType::LINE_2;
 this->N_Vertices = 2;   
 this->N_Facets = 2;   
}

// Methods
// template <sint dim> 
// double TLine_2<dim>::GetMeasure(SParSH::TVertex<dim> **Verts)
// {
  // double x1,x2,y1,y2;

  // x1 = Verts[0]->GetX();
  // y1 = Verts[0]->GetY();
  // x2 = Verts[1]->GetX();
  // y2 = Verts[1]->GetY();

  // return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
// }


// explicit instantiation
template class TLine_2<GEO_DIM>;

SParSH_NAMESPACE_END
