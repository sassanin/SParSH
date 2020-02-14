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
 static constexpr sint DatChildVertex[4][4] = { {0, 4, 8, 7},  {1, 5, 8, 4},  {2, 6, 8, 5},  {3, 7, 8, 6}};
 static constexpr sint DatVertexChild[9][4] = { {0},  {1},  {2},  {3},  {0, 1},  {1, 2},  {2, 3}, {0, 3},  {0, 1, 2, 3}};
 static constexpr sint DatVertexChildIndex[9][4] = { {0},  {0},  {0},  {0},  {1, 3},  {1, 3},  {1, 3}, {3, 1},  {2, 2, 2, 2}};
 static constexpr sint DatVertexChildLen[9] = { 1,  1,  1,  1,  2,  2,  2,  2,  4};
 static constexpr sint DatChildEdge[4][4] = { {0, 8,11, 7},  {2, 9, 8, 1},  {4,10, 9, 3},  {6,11,10, 5}};
 static constexpr sint DatEdgeChild[12][2] = { {0},  {1},  {1},  {2},  {2},  {3},  {3},  {0}, {0, 1},  {1, 2},  {2, 3},  {0, 3}};
 static constexpr sint DatEdgeChildIndex[12][2] = { {0},  {3},  {0},  {3},  {0},  {3},  {0},  {3}, {1, 2},  {1, 2},  {1, 2},  {2, 1}};
 static constexpr sint DatEdgeChildLen[12] = { 1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2};
 static constexpr sint DatEdgeVertex[12][2] = { {0, 4},  {4, 1},  {1, 5},  {5, 2},  {2, 6},  {6, 3},
                                               {3, 7},  {7, 0},  {4, 8},  {5, 8},  {6, 8},  {7, 8}};
 static constexpr sint DatVertexEdge[9][4] = { {0, 7},  {1, 2},  {3, 4},  {5, 6},  {0, 1, 8},
                                               {2, 3, 9},  {4, 5,10},  {6, 7,11},  {8, 9,10,11}};
 static constexpr sint DatVertexEdgeIndex[9][4] = { {0, 1},  {1, 0},  {1, 0},  {1,0},  {1, 0, 0},
                                                    {1, 0, 0},  {1, 0, 0},  {1, 0, 0},  {1, 1, 1, 1}};
 static constexpr sint DatVertexEdgeLen[9] = {2,  2,  2,  2,  3,  3,  3,  3,  4};
 static constexpr sint DatNewVertexEqOldVertex[4] = {0, 1, 2, 3};
 static constexpr sint DatNewVertexEqOldVertexIndex[4] = {0, 1, 2, 3};
 
 static constexpr sint DatInteriorVertexOfCell[1] = {8};
 static constexpr double DatPositionOfIntVert[1][4] = {{0.25, 0.25, 0.25, 0.25}};

 static constexpr sint DatInteriorEdgeOfCell[4] = {8, 9, 10, 11};
 static constexpr sint DatInteriorVertexOfEdge[4][1] = {{4}, {5}, {6}, {7} };
 static constexpr sint DatInteriorVertexOfEdgeLen[4] = {1,  1,  1,  1};
 static constexpr sint DatOldEdgeNewVertex[4][3] = { {0, 4, 1},  {1, 5, 2},  {2, 6, 3},  {3, 7, 0}};
 static constexpr sint DatOldEdgeNewEdge[4][2] = { {0, 1},  {2, 3},  {4, 5},  {6, 7}};
 static constexpr sint DatOldEdgeNewLocEdge[4][4] = { {0, -1, -1, 3}, {3, 0, -1, -1}, {-1, 3, 0, -1}, {-1, -1, 3, 0} };
 static constexpr sint DatNewEdgeOldEdge[12] ={0,  0,  1,  1,  2,  2,  3,  3,  -1,  -1,  -1,  -1};
 
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
 this->ChildVertex = static_cast<const sint *>(*DatChildVertex);
 this->VertexChild =  static_cast<const sint *>(*DatVertexChild);
 this->VertexChildIndex = static_cast<const sint *>(*DatVertexChildIndex);
 this->VertexChildLen = static_cast<const sint *>(DatVertexChildLen);
 this->ChildEdge = static_cast<const sint *>(*DatChildEdge);
 this->EdgeChild = static_cast<const sint *>(*DatEdgeChild);
 this->EdgeChildIndex = static_cast<const sint *>(*DatEdgeChildIndex);
 this->EdgeChildLen = static_cast<const sint *>(DatEdgeChildLen);
 this->EdgeVertex = static_cast<const sint *>(*DatEdgeVertex);
 this->VertexEdge = static_cast<const sint *>(*DatVertexEdge);
 this->VertexEdgeIndex = static_cast<const sint *>(*DatVertexEdgeIndex);
 this->VertexEdgeLen = static_cast<const sint *>(DatVertexEdgeLen);
 this->NewVertexEqOldVertex = static_cast<const sint *>(DatNewVertexEqOldVertex);
 this->NewVertexEqOldVertexIndex = static_cast<const sint *>(DatNewVertexEqOldVertexIndex);
 this->InteriorVertexOfCell = static_cast<const sint *>(DatInteriorVertexOfCell);
 this->PositionOfIntVert = static_cast<const double *>(*DatPositionOfIntVert);
 this->InteriorEdgeOfCell = static_cast<const sint *>(DatInteriorEdgeOfCell);
 this->InteriorVertexOfEdge = static_cast<const sint *>(*DatInteriorVertexOfEdge);
 this->InteriorVertexOfEdgeLen = static_cast<const sint *>(DatInteriorVertexOfEdgeLen);
 this->OldEdgeNewVertex = static_cast<const sint *>(*DatOldEdgeNewVertex);
 this->OldEdgeNewEdge = static_cast<const sint *>(*DatOldEdgeNewEdge);
 this->OldEdgeNewLocEdge= static_cast<const sint *>(*DatOldEdgeNewLocEdge);
 this->NewEdgeOldEdge = static_cast<const sint *>(DatNewEdgeOldEdge);
}

// explicit instantiation
template class TRefineQuad_4Desc<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END
