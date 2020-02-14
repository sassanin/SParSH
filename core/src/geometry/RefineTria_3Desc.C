/** =======================================================================
* @class     TRefineTria_3Desc
* @brief     RefineLine descriptors source 
* @author    Sashikumaar Ganesan 
* @date      13.02.2020
* @History   
===========================================================================*/
#include <RefineTria_3Desc.h>

SParSH_NAMESPACE_BEGIN

using namespace std; 

// Constructor
template <sint dim> 
TRefineTria_3Desc<dim>::TRefineTria_3Desc(TCellDesc<dim> *celldesc) : TRefineDesc<dim>(celldesc)
{
 static constexpr CellType DatChildType[3] = { CellType::TRI_3, CellType::TRI_3, CellType::TRI_3};
 static constexpr RefineType DatEdgeType[3] = { RefineType::Line_2Reg, RefineType::Line_2Reg, RefineType::Line_2Reg};
 static constexpr int DatChildVertex[4][3] = { {0, 3, 5},  {1, 4, 3},  {2, 5, 4},  {3, 4, 5}};
 static constexpr int DatVertexChild[6][3] = { {0}, {1}, {2}, {0, 1, 3},  {1, 2, 3},  {0, 2, 3}}; 
 static constexpr int DatVertexChildIndex[6][3] = { {0}, {0}, {0}, {1, 2, 0},  {1, 2, 1},  {2, 1, 2}};
 static constexpr int DatVertexChildLen[6] = { 1,  1,  1,  3,  3,  3};
 static constexpr int DatChildEdge[4][3] = { {0, 8, 5},  {2, 6, 1},  {4, 7, 3},  {6, 7, 8}};
 static constexpr int DatEdgeChild[9][2] ={ {0}, {1}, {1}, {2}, {2}, {0}, {1, 3}, {2, 3}, {0, 3}};
 static constexpr int DatEdgeChildIndex[9][2] = { {0}, {2}, {0}, {2}, {0}, {2}, {1, 0}, {1, 1}, {1, 2}};
 static constexpr int DatEdgeChildLen[9] = { 1,  1,  1,  1,  1,  1,  2,  2,  2};
 static constexpr int DatEdgeVertex[9][2] = { {0, 3},  {3, 1},  {1, 4},  {4, 2},  {2, 5},
                                         {5, 0},  {3, 4},  {4, 5},  {5, 3} };
 static constexpr int DatVertexEdge[6][4] = { {0, 5},  {1, 2},  {3, 4},  {0, 1, 6, 8},
                                         {2, 3, 6, 7},  {4, 5, 7, 8} };
 static constexpr int DatVertexEdgeIndex[6][4] = { {0, 1},  {1, 0},  {1, 0},  {1, 0, 0, 1},
                                             {1, 0, 1, 0},  {1, 0, 1, 0}};
 static constexpr int DatVertexEdgeLen[6] = { 2,  2,  2,  4,  4,  4};
 static constexpr int DatNewVertexEqOldVertex[3] = { 0, 1, 2};
 static constexpr int DatNewVertexEqOldVertexIndex[3] = { 0, 1, 2};
 static constexpr int DatInteriorEdgeOfCell[3] = { 6, 7, 8};
 static constexpr int DatInteriorVertexOfEdge[3][1] = { {3},  {4},  {5} };
 static constexpr int DatInteriorVertexOfEdgeLen[3] = { 1,  1,  1};
 static constexpr int DatOldEdgeNewVertex[3][3] = { {0, 3, 1}, {1, 4, 2},  {2, 5, 0}};
 static constexpr int DatOldEdgeNewEdge[3][2] = { {0, 1},  {2, 3},  {4, 5}};
 static constexpr int DatOldEdgeNewLocEdge[4][3] = { {0, -1, 2}, {2, 0, -1}, {-1, 2, 0}, {-1, -1, -1} };
 static constexpr int DatNewEdgeOldEdge[9] ={ 0,  0,  1,  1,  2,  2, -1, -1, -1};
 
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
 this->InteriorEdgeOfCell = static_cast<const int *>(DatInteriorEdgeOfCell);
 this->InteriorVertexOfEdge = static_cast<const int *>(*DatInteriorVertexOfEdge);
 this->InteriorVertexOfEdgeLen = static_cast<const int *>(DatInteriorVertexOfEdgeLen);
 this->OldEdgeNewVertex = static_cast<const int *>(*DatOldEdgeNewVertex);
 this->OldEdgeNewEdge = static_cast<const int *>(*DatOldEdgeNewEdge);
 this->OldEdgeNewLocEdge= static_cast<const int *>(*DatOldEdgeNewLocEdge);
 this->NewEdgeOldEdge = static_cast<const int *>(DatNewEdgeOldEdge);
}

// explicit instantiation
template class TRefineTria_3Desc<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END
