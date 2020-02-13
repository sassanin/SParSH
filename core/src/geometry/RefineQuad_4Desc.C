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
 static constexpr sint DatChildVertex[4][3] = { {0, 3, 5},  {1, 4, 3},  {2, 5, 4},  {3, 4, 5}};
 static constexpr sint DatVertexChild[6][3] = { {0}, {1}, {2}, {0, 1, 3},  {1, 2, 3},  {0, 2, 3}}; 
 static constexpr sint DatVertexChildIndex[6][3] = { {0}, {0}, {0}, {1, 2, 0},  {1, 2, 1},  {2, 1, 2}};
 static constexpr sint DatVertexChildLen[6] = { 1,  1,  1,  3,  3,  3};
 static constexpr sint DatChildEdge[4][3] = { {0, 8, 5},  {2, 6, 1},  {4, 7, 3},  {6, 7, 8}};
 static constexpr sint DatEdgeChild[9][2] ={ {0}, {1}, {1}, {2}, {2}, {0}, {1, 3}, {2, 3}, {0, 3}};
 static constexpr sint DatEdgeChildIndex[9][2] = { {0}, {2}, {0}, {2}, {0}, {2}, {1, 0}, {1, 1}, {1, 2}};
 static constexpr sint DatEdgeChildLen[9] = { 1,  1,  1,  1,  1,  1,  2,  2,  2};
 static constexpr sint DatEdgeVertex[9][2] = { {0, 3},  {3, 1},  {1, 4},  {4, 2},  {2, 5},
                                         {5, 0},  {3, 4},  {4, 5},  {5, 3} };
 static constexpr sint DatVertexEdge[6][4] = { {0, 5},  {1, 2},  {3, 4},  {0, 1, 6, 8},
                                         {2, 3, 6, 7},  {4, 5, 7, 8} };
 static constexpr sint DatVertexEdgeIndex[6][4] = { {0, 1},  {1, 0},  {1, 0},  {1, 0, 0, 1},
                                             {1, 0, 1, 0},  {1, 0, 1, 0}};
 static constexpr sint DatVertexEdgeLen[6] = { 2,  2,  2,  4,  4,  4};
 static constexpr sint DatNewVertexEqOldVertex[3] = { 0, 1, 2};
 static constexpr sint DatNewVertexEqOldVertexIndex[3] = { 0, 1, 2};
 static constexpr sint DatInteriorEdgeOfCell[3] = { 6, 7, 8};
 static constexpr sint DatInteriorVertexOfEdge[3][1] = { {3},  {4},  {5} };
 static constexpr sint DatInteriorVertexOfEdgeLen[3] = { 1,  1,  1};
 static constexpr sint DatOldEdgeNewVertex[3][3] = { {0, 3, 1}, {1, 4, 2},  {2, 5, 0}};
 static constexpr sint DatOldEdgeNewEdge[3][2] = { {0, 1},  {2, 3},  {4, 5}};
 static constexpr sint DatOldEdgeNewLocEdge[4][3] = { {0, -1, 2}, {2, 0, -1}, {-1, 2, 0}, {-1, -1, -1} };
 static constexpr sint DatNewEdgeOldEdge[9] ={ 0,  0,  1,  1,  2,  2, -1, -1, -1};
 
 this->RefinementType = RefineType::Tri_3Reg;
 this->N_Edges = 9;
 this->N_Vertices = 6;
 this->N_Children = 4;
 this->N_NewVertEqOldVert = 3;

 this->MaxN_VpC = 3;
 this->MaxN_CpV = 3;
 this->MaxN_EpC = 3;
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
