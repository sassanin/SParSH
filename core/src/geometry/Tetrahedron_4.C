
/** =======================================================================
* @class     Tetrahedron_4
* @brief     TETRA_4 (element) descriptors source 
* @author    Sashikumaar Ganesan 
* @date      10.02.2020
* @History   
===========================================================================*/

#include <Tetrahedron_4.h>

SParSH_NAMESPACE_BEGIN

using namespace std; 

// Constructor
template <sint dim> 
TTetrahedron_4<dim>::TTetrahedron_4()
{
 static constexpr sint DatEdgeVertex[6][2] = { {0, 1},  {1, 2},  {2, 0}, {0, 3},  {1, 3},  {2, 3}};
 static constexpr sint DatVertexEdge[4][3] =  { {2, 0, 3},  {0, 1, 4},  {1, 2, 5},  {3, 4, 5}};

 static constexpr sint DatFaceVertex[4][3] = { {0, 1, 2},  {0, 3, 1},  {2, 1, 3},  {0, 2, 3}};
 static constexpr sint DatFaceVertexLen[4] = { 3, 3, 3, 3}; 
 static constexpr sint DatVertexFace[4][3] = { {0, 1, 3},  {0, 2, 1},  {0, 3, 2},  {1, 2, 3}};

static constexpr sint DatFaceEdge[4][3] = { {0, 1, 2},  {3, 4, 0},  {1, 4, 5},  {2, 5, 3}};
static constexpr sint DatFaceEdgeLen[4] = { 3, 3, 3, 3};
static constexpr sint DatEdgeFace[6][2] = { {1, 0},  {2, 0},  {3, 0}, {3, 1},  {1, 2},  {2, 3}};

static const CellType DatFaceType[4] = { CellType::TRI_3, CellType::TRI_3, CellType::TRI_3, CellType::TRI_3};

 this->Type = CellType::TETRA_4;
 this->N_Vertices = 4;   
 this->N_Edges = 6;   
 this->N_Facets = 4;    
 this->EdgeType = CellType::LINE_2;     
 this->MaxN_EpV = 3;
 this->EdgeVertex = static_cast<const sint *>(*DatEdgeVertex);
 this->VertexEdge = static_cast<const sint *>(*DatVertexEdge);   

 this->N_Faces = 4;
 this->MaxN_VpF = 3;
 this->MaxN_FpV = 3;
 this->MaxN_EpF = 3;
 this->MaxN_FpE = 2;

 this->FaceVertex = static_cast<const sint *>(*DatFaceVertex);
 this->FaceVertexLen = static_cast<const sint *>(DatFaceVertexLen);
 this->VertexFace = static_cast<const sint *>(*DatVertexFace);
 this->FaceEdge = static_cast<const sint *>(*DatFaceEdge);
 this->FaceEdgeLen = static_cast<const sint *>(DatFaceEdgeLen);
 this->EdgeFace = static_cast<const sint *>(*DatEdgeFace);
 this->FaceType = static_cast<const CellType *>(DatFaceType);
}

// Methods
template <sint dim> 
double TTetrahedron_4<dim>::GetDiameter(SParSH::TVertex<dim> **Verts)
{

return 0.;
}

template <sint dim> 
double TTetrahedron_4<dim>::GetShortestEdge(SParSH::TVertex<dim> **Verts)
{

return 0.;
}

template <sint dim> 
double TTetrahedron_4<dim>::GetLengthWithReferenceMap(SParSH::TVertex<dim> **Verts)
{

return 0.;
}

template <sint dim> 
double TTetrahedron_4<dim>::GetMeasure(SParSH::TVertex<dim> **Verts)
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
template class TTetrahedron_4<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END
