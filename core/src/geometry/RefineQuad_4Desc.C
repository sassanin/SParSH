/** =======================================================================
* @class     TRefineQuad_4Desc
* @brief     RefineLine descriptors source 
* @author    Sashikumaar Ganesan 
* @date      13.02.2020
* @History   
===========================================================================*/
#include <RefineQuad_4Desc.h>

SParSH_NAMESPACE_BEGIN

using namespace std; 

// Constructor
template <sint dim> 
TRefineQuad_4Desc<dim>::TRefineQuad_4Desc(TCellDesc<dim> *celldesc) : TRefineDesc<dim>(celldesc)
{
 static constexpr CellType DatChildType[4] = { CellType::QUAD_4, CellType::QUAD_4, CellType::QUAD_4, CellType::QUAD_4};
 static constexpr RefineType DatEdgeType[3] = { RefineType::Line_2Reg, RefineType::Line_2Reg, RefineType::Line_2Reg};
 static constexpr int DatChildVertex[4][4] = { {0, 4, 8, 7},  {1, 5, 8, 4},  {2, 6, 8, 5},  {3, 7, 8, 6}};
 static constexpr int DatVertexChild[9][4] = { {0},  {1},  {2},  {3},  {0, 1},  {1, 2},  {2, 3}, {0, 3},  {0, 1, 2, 3}};
 static constexpr int DatVertexChildIndex[9][4] = { {0},  {0},  {0},  {0},  {1, 3},  {1, 3},  {1, 3}, {3, 1},  {2, 2, 2, 2}};
 static constexpr int DatVertexChildLen[9] = { 1,  1,  1,  1,  2,  2,  2,  2,  4};
 static constexpr int DatChildEdge[4][4] = { {0, 8,11, 7},  {2, 9, 8, 1},  {4,10, 9, 3},  {6,11,10, 5}};
 static constexpr int DatEdgeChild[12][2] = { {0},  {1},  {1},  {2},  {2},  {3},  {3},  {0}, {0, 1},  {1, 2},  {2, 3},  {0, 3}};
 static constexpr int DatEdgeChildIndex[12][2] = { {0},  {3},  {0},  {3},  {0},  {3},  {0},  {3}, {1, 2},  {1, 2},  {1, 2},  {2, 1}};
 static constexpr int DatEdgeChildLen[12] = { 1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2};
 static constexpr int DatEdgeVertex[12][2] = { {0, 4},  {4, 1},  {1, 5},  {5, 2},  {2, 6},  {6, 3},
                                               {3, 7},  {7, 0},  {4, 8},  {5, 8},  {6, 8},  {7, 8}};
 static constexpr int DatVertexEdge[9][4] = { {0, 7},  {1, 2},  {3, 4},  {5, 6},  {0, 1, 8},
                                               {2, 3, 9},  {4, 5,10},  {6, 7,11},  {8, 9,10,11}};
 static constexpr int DatVertexEdgeIndex[9][4] = { {0, 1},  {1, 0},  {1, 0},  {1,0},  {1, 0, 0},
                                                    {1, 0, 0},  {1, 0, 0},  {1, 0, 0},  {1, 1, 1, 1}};
 static constexpr int DatVertexEdgeLen[9] = {2,  2,  2,  2,  3,  3,  3,  3,  4};
 static constexpr int DatNewVertexEqOldVertex[4] = {0, 1, 2, 3};
 static constexpr int DatNewVertexEqOldVertexIndex[4] = {0, 1, 2, 3};
 
 static constexpr int DatInteriorVertexOfCell[1] = {8};
 static constexpr double DatPositionOfIntVert[1][4] = {{0.25, 0.25, 0.25, 0.25}};

 static constexpr int DatInteriorEdgeOfCell[4] = {8, 9, 10, 11};
 static constexpr int DatInteriorVertexOfEdge[4][1] = {{4}, {5}, {6}, {7} };
 static constexpr int DatInteriorVertexOfEdgeLen[4] = {1,  1,  1,  1};
 static constexpr int DatOldEdgeNewVertex[4][3] = { {0, 4, 1},  {1, 5, 2},  {2, 6, 3},  {3, 7, 0}};
 static constexpr int DatOldEdgeNewEdge[4][2] = { {0, 1},  {2, 3},  {4, 5},  {6, 7}};
 static constexpr int DatOldEdgeNewLocEdge[4][4] = { {0, -1, -1, 3}, {3, 0, -1, -1}, {-1, 3, 0, -1}, {-1, -1, 3, 0} };
 static constexpr int DatNewEdgeOldEdge[12] ={0,  0,  1,  1,  2,  2,  3,  3,  -1,  -1,  -1,  -1};
 
 this->RefinementType = RefineType::Quad_4Reg;
 this->N_Edges = 12;
 this->N_Vertices = 9;
 this->N_Children = 4;
 this->N_NewVertEqOldVert = 4;
 this->N_InnerVertices = 1;    
 this->N_InnerEdges = 4;

 this->MaxN_VpC = 4;
 this->MaxN_CpV = 4;
 this->MaxN_EpC = 4;
 this->MaxN_CpE = 2;
 this->MaxN_EpV = 4;
 this->MaxN_iVpE = 1;
 this->MaxN_nVpoE = 3;
 this->MaxN_nEpoE = 2;

 this->ChildType = static_cast<const CellType *>(DatChildType);
 this->EdgeType = static_cast<const RefineType *>(DatEdgeType);
 this->ChildVertex = static_cast<const int *>(*DatChildVertex);
 this->VertexChild =  static_cast<const int *>(*DatVertexChild);
 this->VertexChildIndex = static_cast<const int *>(*DatVertexChildIndex);
 this->VertexChildLen = static_cast<const int *>(DatVertexChildLen);
 this->ChildEdge = static_cast<const int *>(*DatChildEdge);
 this->EdgeChild = static_cast<const int *>(*DatEdgeChild);
 this->EdgeChildIndex = static_cast<const int *>(*DatEdgeChildIndex);
 this->EdgeChildLen = static_cast<const int *>(DatEdgeChildLen);
 this->EdgeVertex = static_cast<const int *>(*DatEdgeVertex);
 this->VertexEdge = static_cast<const int *>(*DatVertexEdge);
 this->VertexEdgeIndex = static_cast<const int *>(*DatVertexEdgeIndex);
 this->VertexEdgeLen = static_cast<const int *>(DatVertexEdgeLen);
 this->NewVertexEqOldVertex = static_cast<const int *>(DatNewVertexEqOldVertex);
 this->NewVertexEqOldVertexIndex = static_cast<const int *>(DatNewVertexEqOldVertexIndex);
 this->InteriorVertexOfCell = static_cast<const int *>(DatInteriorVertexOfCell);
 this->PositionOfIntVert = static_cast<const double *>(*DatPositionOfIntVert);
 this->InteriorEdgeOfCell = static_cast<const int *>(DatInteriorEdgeOfCell);
 this->InteriorVertexOfEdge = static_cast<const int *>(*DatInteriorVertexOfEdge);
 this->InteriorVertexOfEdgeLen = static_cast<const int *>(DatInteriorVertexOfEdgeLen);
 this->OldEdgeNewVertex = static_cast<const int *>(*DatOldEdgeNewVertex);
 this->OldEdgeNewEdge = static_cast<const int *>(*DatOldEdgeNewEdge);
 this->OldEdgeNewLocEdge= static_cast<const int *>(*DatOldEdgeNewLocEdge);
 this->NewEdgeOldEdge = static_cast<const int *>(DatNewEdgeOldEdge);
}

// explicit instantiation
template class TRefineQuad_4Desc<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END
