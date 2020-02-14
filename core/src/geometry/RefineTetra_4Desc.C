/** =======================================================================
* @class     TRefineTetra_4Desc
* @brief     RefineLine descriptors source 
* @author    Sashikumaar Ganesan 
* @date      14.02.2020
* @History   
===========================================================================*/
#include <RefineTetra_4Desc.h>

SParSH_NAMESPACE_BEGIN

using namespace std; 

// Constructor
template <sint dim> 
TRefineTetra_4Desc<dim>::TRefineTetra_4Desc(TCellDesc<dim> *celldesc) : TRefineDesc<dim>(celldesc)
{
 static constexpr CellType DatChildType[8] = {CellType::TETRA_4, CellType::TETRA_4, CellType::TETRA_4, CellType::TETRA_4,
                                               CellType::TETRA_4, CellType::TETRA_4, CellType::TETRA_4, CellType::TETRA_4};
 static constexpr RefineType DatEdgeType[6] = {RefineType::Line_2Reg, RefineType::Line_2Reg, RefineType::Line_2Reg,
                                                RefineType::Line_2Reg, RefineType::Line_2Reg, RefineType::Line_2Reg };



 static constexpr RefineType DatFaceType[4] = {RefineType::Tri_3Reg, RefineType::Tri_3Reg, RefineType::Tri_3Reg, RefineType::Tri_3Reg};



 static constexpr sint DatChildVertex[8][4] = {{0, 4, 6, 7}, {4, 1, 5, 8}, {6, 5, 2, 9}, {7, 8, 9, 3},
                                                {4, 6, 7, 8}, {5, 6, 4, 8}, {6, 7, 8, 9}, {8, 5, 6, 9} };
 static constexpr sint DatVertexChild[10][6] = {{0}, {1}, {2}, {3}, {0, 1, 4, 5}, {1, 2, 5, 7}, {0, 2, 4, 5, 6, 7},
                                                {0, 3, 4, 6}, {1, 3, 4, 5, 6, 7}, {2, 3, 6, 7} };
 static constexpr sint DatVertexChildIndex[10][6] = {{0}, {1}, {2}, {3}, {1, 0, 0, 2}, {2, 1, 0, 1}, {2, 0, 1, 1, 0, 2}, 
                                                     {3, 0, 2, 1}, {3, 1, 3, 3, 2, 0}, {3, 2, 3, 3}};
 static constexpr sint DatVertexChildLen[10] = {1, 1, 1, 1, 4, 4, 6, 4, 6, 4};
 static constexpr sint DatChildEdge[8][6] = {{0, 12, 5, 6, 15, 22}, {1, 2, 13, 16, 8, 18}, {14, 3, 4, 21, 19, 10}, {17, 20, 23, 7, 9, 11},
        {12, 22, 15, 16, 24, 17}, {14, 12, 13, 18, 24, 16}, {22, 17, 24, 21, 23, 20}, {18, 14, 24, 20, 19, 21}};
 static constexpr sint DatEdgeChild[25][4] = {{0}, {1}, {1}, {2}, {2}, {0}, {0}, {3}, {1}, {3}, {2}, {3}, {0, 4, 5}, {1, 5}, {2, 5, 7}, 
        {0, 4}, {1, 4, 5}, {3, 4, 6}, {1, 5, 7}, {2, 7}, {3, 6, 7}, {2, 6, 7}, {0, 4, 6}, {3, 6}, {4, 5, 6, 7}};
 static constexpr sint DatEdgeChildIndex[25][4] = {{0}, {0}, {1}, {1}, {2}, {2}, {3}, {3}, {4}, {4}, {5}, {5}, {1, 0, 1}, {2, 2}, {0, 0, 1}, {4, 2},
        {3, 3, 5}, {0, 5, 1}, {5, 3, 0}, {4, 4}, {1, 5, 3}, {3, 3, 5}, {5, 1, 0}, {2, 4}, {4, 4, 2, 2}};
 static constexpr sint DatEdgeChildLen[25] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 3, 2, 3, 3, 3, 2, 3, 3, 3, 2, 4};



static constexpr sint DatChildFace[8][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}, {2, 16, 17, 18},
                                            {19, 20, 16, 7}, {17, 21, 12, 22}, {20, 23, 9, 22}};
static constexpr sint DatFaceChild[24][2] = {{0}, {0}, {0, 4}, {0}, {1}, {1}, {1}, {1, 5}, {2}, {2, 7}, {2}, {2}, {3, 6}, 
                                             {3}, {3}, {3}, {4, 5}, {4, 6}, {4}, {5}, {5, 7}, {6}, {6, 7}, {7}};
static constexpr sint DatFaceChildIndex[24][2] = {{0}, {1}, {2, 0}, {3}, {0}, {1}, {2}, {3, 3}, {0}, {1, 2}, 
       {2}, {3}, {0, 2}, {1}, {2}, {3}, {1, 2}, {2, 0}, {3}, {0}, {1, 0}, {1}, {3, 3}, {1}};

static constexpr sint DatFaceChildLen[24] = {1, 1, 2, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 1, 1, 2, 2, 1, 1, 2, 1, 2, 1};



static constexpr sint DatEdgeVertex[25][2] = {{0, 4}, {4, 1}, {1, 5}, {5, 2}, {2, 6}, {6, 0}, {0, 7}, {7, 3}, {1, 8}, {8, 3}, {2, 9}, {9, 3}, 
      {6, 4}, {4, 5}, {5, 6}, {7, 4}, {4, 8}, {8, 7}, {8, 5}, {5, 9}, {9, 8}, {9, 6}, {6, 7}, {7, 9}, {6, 8}};
static constexpr sint DatVertexEdge[10][7] = {{0, 5, 6}, {1, 2, 8}, {3, 4, 10}, {7, 9, 11}, {0, 1, 12, 13, 15, 16}, {2, 3, 13, 14, 18, 19}, 
       {4, 5, 12, 14, 21, 22, 24}, {6, 7, 15, 17, 22, 23}, {8, 9, 16, 17, 18, 20, 24}, {10, 11, 19, 20, 21, 23}};
static constexpr sint DatVertexEdgeIndex[10][7] = {{0, 1, 0}, {1, 0, 0}, {1, 0, 0}, {1, 1, 1}, {1, 0, 1, 0, 1, 0}, {1, 0, 1, 0, 1, 0}, 
       {1, 0, 0, 1, 1, 0, 0}, {1, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 0, 1, 1}, {1, 0, 1, 0, 0, 1}};
static constexpr sint DatVertexEdgeLen[10] = {3, 3, 3, 3, 6, 6, 7, 6, 7, 6};
static constexpr sint DatFaceVertex[24][3] = {{0, 4, 6}, {0, 7, 4}, {6, 4, 7}, {0, 6, 7}, {4, 1, 5}, {4, 8, 1}, 
       {5, 1, 8}, {4, 5, 8}, {6, 5, 2}, {6, 9, 5}, {2, 5, 9}, {6, 2, 9}, {7, 8, 9}, {7, 3, 8}, {9, 8, 3}, {7, 9, 3}, 
       {4, 8, 6}, {7, 6, 8}, {4, 7, 8}, {5, 6, 4}, {5, 8, 6}, {6, 9, 7}, {6, 8, 9}, {8, 9, 5}};
static constexpr sint DatVertexFace[10][12] = {{0, 1, 3}, {4, 5, 6}, {8, 10, 11}, {13, 14, 15}, {0, 1, 2, 4, 5, 7, 16, 18, 19},
       {4, 6, 7, 8, 9, 10, 19, 20, 23}, {0, 2, 3, 8, 9, 11, 16, 17, 19, 20, 21, 22}, {1, 2, 3, 12, 13, 15, 17, 18, 21}, 
       {5, 6, 7, 12, 13, 14, 16, 17, 18, 20, 22, 23}, {9, 10, 11, 12, 14, 15, 21, 22, 23}};
static constexpr sint DatVertexFaceIndex[10][12] = {{0, 0, 2}, {1, 2, 0}, {2, 2, 0}, {1, 1, 1}, {1, 2, 0, 0, 0, 2, 0, 2, 2}, 
       {2, 2, 0, 1, 2, 0, 0, 0, 2}, {2, 2, 0, 0, 0, 2, 2, 0, 1, 2, 0, 2}, {1, 1, 1, 0, 0, 2, 2, 0, 2}, 
       {1, 1, 1, 1, 2, 0, 1, 1, 1, 1, 0, 0}, {1, 1, 1, 2, 2, 0, 1, 1, 1}};
static constexpr sint DatVertexFaceLen[10] = {3, 3, 3, 3, 9, 9, 12, 9, 12, 9};
static constexpr sint DatFaceEdge[24][3] = {{0, 12, 5}, {6, 15, 0}, {15, 22, 12}, {22, 6, 5}, {1, 2, 13}, {16, 8, 1}, {8, 18, 2}, 
       {18, 16, 13}, {14, 3, 4}, {21, 19, 14}, {19, 10, 3}, {10, 21, 4}, {17, 20, 23}, {7, 9, 17}, {9, 11, 20}, {11, 7, 23}, 
       {16, 24, 12}, {24, 17, 22}, {17, 16, 15}, {14, 12, 13}, {18, 24, 14}, {21, 23, 22}, {20, 21, 24}, {20, 19, 18}};
static constexpr sint DatEdgeFace[25][4] = {{0, 1}, {4, 5}, {4, 6}, {8, 10}, {8, 11}, {0, 3}, {1, 3}, {13, 15}, {5, 6}, 
       {13, 14}, {10, 11}, {14, 15}, {0, 2, 16, 19}, {4, 7, 19}, {8, 9, 19, 20}, {1, 2, 18}, {5, 7, 16, 18}, {12, 13, 17, 18}, 
       {6, 7, 20, 23}, {9, 10, 23}, {12, 14, 22, 23}, {9, 11, 21, 22}, {2, 3, 17, 21}, {12, 15, 21}, {16, 17, 20, 22}};
static constexpr sint DatEdgeFaceIndex[25][4] = {{0, 2}, {0, 2}, {1, 2}, {1, 2}, {2, 2}, {2, 2}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, 
       {1, 0}, {1, 0}, {1, 2, 2, 1}, {2, 2, 2}, {0, 2, 0, 2}, {1, 0, 2}, {0, 1, 0, 1}, {0, 2, 1, 0}, {1, 0, 0, 2}, {1, 0, 1}, 
       {1, 2, 0, 0}, {0, 1, 0, 1}, {1, 0, 2, 2}, {2, 2, 1}, {1, 0, 1, 2}, };
static constexpr sint DatEdgeFaceLen[25] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 3, 4, 3, 4, 4, 4, 3, 4, 4, 4, 3, 4};
static constexpr sint DatNewVertexEqOldVertex[4] = {0, 1, 2, 3};
static constexpr sint DatNewVertexEqOldVertexIndex[4] = {0, 1, 2, 3};
static const double DatOldFaceNewVertexPos[4][6][3] = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0.5, 0.5, 0}, {0, 0.5, 0.5}, {0.5, 0, 0.5}},
             {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0.5, 0.5, 0}, {0, 0.5, 0.5}, {0.5, 0, 0.5}},
             {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0.5, 0.5, 0}, {0, 0.5, 0.5}, {0.5, 0, 0.5}},
             {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0.5, 0.5, 0}, {0, 0.5, 0.5}, {0.5, 0, 0.5}}};
static constexpr sint DatInteriorEdgeOfCell[1] = {24};
static constexpr sint DatInteriorFaceOfCell[8] = {2, 7, 9, 12, 16, 17, 20, 22};
static constexpr sint DatInteriorVertexOfEdge[6][1] = {{4}, {5}, {6}, {7}, {8}, {9}};
static constexpr sint DatInteriorVertexOfEdgeLen[6]={1, 1, 1, 1, 1, 1};
static constexpr sint DatInteriorEdgeOfFace[4][3] = {{12, 13, 14}, {15, 16, 17}, {18, 19, 20}, {21, 22, 23}};
static constexpr sint DatInteriorEdgeOfFaceLen[4] = {3, 3, 3, 3};
static constexpr sint DatOldEdgeNewVertex[6][3] = {{0, 4, 1}, {1, 5, 2}, {2, 6, 0}, {0, 7, 3}, {1, 8, 3}, {2, 9, 3}};
static constexpr sint DatOldEdgeNewVertexLen[6] = {3, 3, 3, 3, 3, 3 };
static constexpr sint DatOldEdgeNewEdge[6][2] = {{0, 1}, {2, 3}, {4, 5}, {6, 7}, {8, 9}, {10, 11}};
static constexpr sint DatOldEdgeNewEdgeLen[6] = {2, 2, 2, 2, 2, 2};
static constexpr sint DatOldFaceNewVertex[4][6] = {{0, 1, 2, 4, 5, 6}, {0, 3, 1, 7, 8, 4}, {2, 1, 3, 5, 8, 9}, {0, 2, 3, 6, 9, 7}};
static constexpr sint DatOldFaceNewVertexLen[4] = {6, 6, 6, 6};
static constexpr sint DatOldFaceNewEdge[4][9] = {{0, 1, 2, 3, 4, 5, 12, 13, 14}, {0, 1, 6, 7, 8, 9, 15, 16, 17}, 
       {2, 3, 8, 9, 10, 11, 18, 19, 20}, {4, 5, 6, 7, 10, 11, 21, 22, 23}};
static constexpr sint DatOldFaceNewEdgeLen[4] = {9, 9, 9, 9};
static constexpr sint DatOldFaceNewFace[4][4] = {{0, 4, 8, 19}, {1, 13, 5, 18}, {10, 6, 14, 23}, {3, 11, 15, 21}};
static constexpr sint DatOldFaceNewFaceLen[4] = {4, 4, 4, 4};
static constexpr sint DatNewEdgeOldEdge[25] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
static constexpr sint DatNewFaceOldFace[24] = {0, 1, -1, 3, 0, 1, 2, -1, 0, -1, 2, 3, -1, 1, 2, 3, -1, -1, 1, 0, -1, 3, -1, 2};
static constexpr sint DatOldFaceNewLocFace[8][4] = {{0, 1, -1, 3}, {0, 1, 2, -1}, {0, -1, 2, 3}, {-1, 1, 2, 3}, {-1, 3, -1, -1}, 
       {0, -1, -1, -1}, {-1, -1, -1, 1}, {-1, -1, 1, -1}};
static constexpr sint DatChildTwistIndex[24] = {0, 0, -1, 0, 1, 2, 1, -1, 2, -1, 0, 1, -1, 1, 2, 2, -1, -1, 1, 2, -1, 0, -1, 2};

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
//  this->InteriorVertexOfCell = static_cast<const sint *>(DatInteriorVertexOfCell);
//  this->PositionOfIntVert = static_cast<const double *>(*DatPositionOfIntVert);
 this->InteriorEdgeOfCell = static_cast<const sint *>(DatInteriorEdgeOfCell);
 this->InteriorVertexOfEdge = static_cast<const sint *>(*DatInteriorVertexOfEdge);
 this->InteriorVertexOfEdgeLen = static_cast<const sint *>(DatInteriorVertexOfEdgeLen);
 this->OldEdgeNewVertex = static_cast<const sint *>(*DatOldEdgeNewVertex);
 this->OldEdgeNewEdge = static_cast<const sint *>(*DatOldEdgeNewEdge);
//  this->OldEdgeNewLocEdge= static_cast<const sint *>(*DatOldEdgeNewLocEdge);
 this->NewEdgeOldEdge = static_cast<const sint *>(DatNewEdgeOldEdge);
}

// explicit instantiation
template class TRefineTetra_4Desc<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END
