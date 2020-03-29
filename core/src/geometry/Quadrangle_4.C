
/** =======================================================================
* @class     TQuadrangle_4
* @brief     TRI_3 (element) descriptors source 
* @author    Sashikumaar Ganesan 
* @date      06.02.2020
* @History   
===========================================================================*/

#include <Quadrangle_4.h>

SParSH_NAMESPACE_BEGIN

using namespace std; 

// Constructor
template <sint dim> 
TQuadrangle_4<dim>::TQuadrangle_4()
{
 static constexpr sint DatEdgeVertex[4][2] = { {0, 1},  {1, 2},  {2, 3},  {3, 0}};
 static constexpr sint DatVertexEdge[4][2] = { {3, 0},  {0, 1},  {1, 2},  {2, 3}};

 this->Type = CellType::QUAD_4;
 this->N_Vertices = 4;   
 this->N_Edges = 4;   
 this->N_Facets = 4;    
 this->EdgeType = CellType::LINE_2;     
 this->MaxN_EpV = 2;
 this->EdgeVertex = static_cast<const sint *>(*DatEdgeVertex);
 this->VertexEdge = static_cast<const sint *>(*DatVertexEdge);   
 this->VTKType = VTKCellType::QUAD_4; 
}

// Methods
template <sint dim> 
double TQuadrangle_4<dim>::GetDiameter(SParSH::TVertex<dim> **Verts)
{

return 0.;
}

template <sint dim> 
double TQuadrangle_4<dim>::GetShortestEdge(SParSH::TVertex<dim> **Verts)
{

return 0.;
}

template <sint dim> 
double TQuadrangle_4<dim>::GetLengthWithReferenceMap(SParSH::TVertex<dim> **Verts)
{

return 0.;
}

template <sint dim> 
double TQuadrangle_4<dim>::GetMeasure(SParSH::TVertex<dim> **Verts)
{
  // double x1,x2,y1,y2;

  // x1 = Verts[0]->GetX();
  // y1 = Verts[0]->GetY();
  // x2 = Verts[1]->GetX();
  // y2 = Verts[1]->GetY();

  // return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  return 0.;
}


// explicit instantiation
template class TQuadrangle_4<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END
