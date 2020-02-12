
/** =======================================================================
* @class     Hexahedron_8
* @brief     HEXA_8 (element) descriptors source 
* @author    Sashikumaar Ganesan 
* @date      11.02.2020
* @History   
===========================================================================*/

#include <Hexahedron_8.h>

SParSH_NAMESPACE_BEGIN

using namespace std; 

// Constructor
template <sint dim> 
THexahedron_8<dim>::THexahedron_8()
{
 static constexpr sint DatEdgeVertex[12][2] = { {0, 1},  {1, 2},  {2, 3},  {3, 0}, {0, 4},  {1, 5},  {2, 6},  {3, 7},
                                                {4, 5},  {5, 6},  {6, 7},  {7, 4}};
 static constexpr sint DatVertexEdge[8][3] =  { {3, 0, 4},  {0, 1, 5},  {1, 2, 6},  {2, 3, 7}, {4, 8,11},  {5, 9, 8},  {6,10, 9},  {7,11,10}};

 static constexpr sint DatFaceVertex[6][4] = { {0, 1, 2, 3},  {0, 4, 5, 1},  {1, 5, 6, 2}, {2, 6, 7, 3},  {0, 3, 7, 4},  {4, 7, 6, 5}};
 static constexpr sint DatFaceVertexLen[6] = { 4, 4, 4, 4, 4, 4}; 
 static constexpr sint DatVertexFace[8][3] = { {0, 1, 4}, {0, 2, 1}, {0, 3, 2}, {0, 4, 3}, {1, 5, 4}, {2, 5, 1}, {3, 5, 2}, {4, 5, 3}};

 static constexpr sint DatFaceEdge[6][4] = { {0, 1, 2, 3}, {4, 8, 5, 0}, {5, 9, 6, 1}, {6,10, 7, 2}, {3, 7,11, 4}, {11,10, 9,8}};
 static constexpr sint DatFaceEdgeLen[6] = { 4, 4, 4, 4, 4, 4 };
 static constexpr sint DatEdgeFace[12][2] = { {1, 0}, {2, 0}, {3, 0}, {4, 0}, {4, 1}, {1, 2}, {2, 3}, {3, 4}, {5, 1}, {5, 2}, {5, 3}, {5, 4}};

 static const CellType DatFaceType[4] = { CellType::QUAD_4, CellType::QUAD_4, CellType::QUAD_4, CellType::QUAD_4};

 this->Type = CellType::HEXA_8;
 this->N_Vertices = 8;   
 this->N_Edges = 12;   
 this->N_Facets = 6;    
 this->EdgeType = CellType::LINE_2;     
 this->MaxN_EpV = 3;
 this->EdgeVertex = static_cast<const sint *>(*DatEdgeVertex);
 this->VertexEdge = static_cast<const sint *>(*DatVertexEdge);   

 this->N_Faces = 6;
 this->MaxN_VpF = 4;
 this->MaxN_FpV = 3;
 this->MaxN_EpF = 4;
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
double THexahedron_8<dim>::GetDiameter(SParSH::TVertex<dim> **Verts)
{

return 0.;
}

template <sint dim> 
double THexahedron_8<dim>::GetShortestEdge(SParSH::TVertex<dim> **Verts)
{

return 0.;
}

template <sint dim> 
double THexahedron_8<dim>::GetLengthWithReferenceMap(SParSH::TVertex<dim> **Verts)
{

return 0.;
}

template <sint dim> 
double THexahedron_8<dim>::GetMeasure(SParSH::TVertex<dim> **Verts)
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
template class THexahedron_8<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END
