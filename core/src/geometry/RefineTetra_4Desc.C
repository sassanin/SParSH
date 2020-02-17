/** =======================================================================
* @class     TRefineTetra_4Desc
* @brief     RefineLine descriptors source 
* @author    Sashikumaar Ganesan 
* @date      14.02.2020
* @History   
===========================================================================*/

#ifdef __3D__

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



 static constexpr int DatChildVertex[8][4] = {{0, 4, 6, 7}, {4, 1, 5, 8}, {6, 5, 2, 9}, {7, 8, 9, 3},
                                                {4, 6, 7, 8}, {5, 6, 4, 8}, {6, 7, 8, 9}, {8, 5, 6, 9} };
 static constexpr int DatVertexChild[10][6] = {{0}, {1}, {2}, {3}, {0, 1, 4, 5}, {1, 2, 5, 7}, {0, 2, 4, 5, 6, 7},
                                                {0, 3, 4, 6}, {1, 3, 4, 5, 6, 7}, {2, 3, 6, 7} };
 static constexpr int DatVertexChildIndex[10][6] = {{0}, {1}, {2}, {3}, {1, 0, 0, 2}, {2, 1, 0, 1}, {2, 0, 1, 1, 0, 2}, 
                                                     {3, 0, 2, 1}, {3, 1, 3, 3, 2, 0}, {3, 2, 3, 3}};
 static constexpr int DatVertexChildLen[10] = {1, 1, 1, 1, 4, 4, 6, 4, 6, 4};
 static constexpr int DatChildEdge[8][6] = {{0, 12, 5, 6, 15, 22}, {1, 2, 13, 16, 8, 18}, {14, 3, 4, 21, 19, 10}, {17, 20, 23, 7, 9, 11},
        {12, 22, 15, 16, 24, 17}, {14, 12, 13, 18, 24, 16}, {22, 17, 24, 21, 23, 20}, {18, 14, 24, 20, 19, 21}};
 static constexpr int DatEdgeChild[25][4] = {{0}, {1}, {1}, {2}, {2}, {0}, {0}, {3}, {1}, {3}, {2}, {3}, {0, 4, 5}, {1, 5}, {2, 5, 7}, 
        {0, 4}, {1, 4, 5}, {3, 4, 6}, {1, 5, 7}, {2, 7}, {3, 6, 7}, {2, 6, 7}, {0, 4, 6}, {3, 6}, {4, 5, 6, 7}};
 static constexpr int DatEdgeChildIndex[25][4] = {{0}, {0}, {1}, {1}, {2}, {2}, {3}, {3}, {4}, {4}, {5}, {5}, {1, 0, 1}, {2, 2}, {0, 0, 1}, {4, 2},
        {3, 3, 5}, {0, 5, 1}, {5, 3, 0}, {4, 4}, {1, 5, 3}, {3, 3, 5}, {5, 1, 0}, {2, 4}, {4, 4, 2, 2}};
 static constexpr int DatEdgeChildLen[25] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 3, 2, 3, 3, 3, 2, 3, 3, 3, 2, 4};



static constexpr int DatChildFace[8][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}, {2, 16, 17, 18},
                                            {19, 20, 16, 7}, {17, 21, 12, 22}, {20, 23, 9, 22}};
static constexpr int DatFaceChild[24][2] = {{0}, {0}, {0, 4}, {0}, {1}, {1}, {1}, {1, 5}, {2}, {2, 7}, {2}, {2}, {3, 6}, 
                                             {3}, {3}, {3}, {4, 5}, {4, 6}, {4}, {5}, {5, 7}, {6}, {6, 7}, {7}};
static constexpr int DatFaceChildIndex[24][2] = {{0}, {1}, {2, 0}, {3}, {0}, {1}, {2}, {3, 3}, {0}, {1, 2}, 
       {2}, {3}, {0, 2}, {1}, {2}, {3}, {1, 2}, {2, 0}, {3}, {0}, {1, 0}, {1}, {3, 3}, {1}};

static constexpr int DatFaceChildLen[24] = {1, 1, 2, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 1, 1, 2, 2, 1, 1, 2, 1, 2, 1};



static constexpr int DatEdgeVertex[25][2] = {{0, 4}, {4, 1}, {1, 5}, {5, 2}, {2, 6}, {6, 0}, {0, 7}, {7, 3}, {1, 8}, {8, 3}, {2, 9}, {9, 3}, 
      {6, 4}, {4, 5}, {5, 6}, {7, 4}, {4, 8}, {8, 7}, {8, 5}, {5, 9}, {9, 8}, {9, 6}, {6, 7}, {7, 9}, {6, 8}};
static constexpr int DatVertexEdge[10][7] = {{0, 5, 6}, {1, 2, 8}, {3, 4, 10}, {7, 9, 11}, {0, 1, 12, 13, 15, 16}, {2, 3, 13, 14, 18, 19}, 
       {4, 5, 12, 14, 21, 22, 24}, {6, 7, 15, 17, 22, 23}, {8, 9, 16, 17, 18, 20, 24}, {10, 11, 19, 20, 21, 23}};
static constexpr int DatVertexEdgeIndex[10][7] = {{0, 1, 0}, {1, 0, 0}, {1, 0, 0}, {1, 1, 1}, {1, 0, 1, 0, 1, 0}, {1, 0, 1, 0, 1, 0}, 
       {1, 0, 0, 1, 1, 0, 0}, {1, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 0, 1, 1}, {1, 0, 1, 0, 0, 1}};
static constexpr int DatVertexEdgeLen[10] = {3, 3, 3, 3, 6, 6, 7, 6, 7, 6};
static constexpr int DatFaceVertex[24][3] = {{0, 4, 6}, {0, 7, 4}, {6, 4, 7}, {0, 6, 7}, {4, 1, 5}, {4, 8, 1}, 
       {5, 1, 8}, {4, 5, 8}, {6, 5, 2}, {6, 9, 5}, {2, 5, 9}, {6, 2, 9}, {7, 8, 9}, {7, 3, 8}, {9, 8, 3}, {7, 9, 3}, 
       {4, 8, 6}, {7, 6, 8}, {4, 7, 8}, {5, 6, 4}, {5, 8, 6}, {6, 9, 7}, {6, 8, 9}, {8, 9, 5}};
static constexpr int DatVertexFace[10][12] = {{0, 1, 3}, {4, 5, 6}, {8, 10, 11}, {13, 14, 15}, {0, 1, 2, 4, 5, 7, 16, 18, 19},
       {4, 6, 7, 8, 9, 10, 19, 20, 23}, {0, 2, 3, 8, 9, 11, 16, 17, 19, 20, 21, 22}, {1, 2, 3, 12, 13, 15, 17, 18, 21}, 
       {5, 6, 7, 12, 13, 14, 16, 17, 18, 20, 22, 23}, {9, 10, 11, 12, 14, 15, 21, 22, 23}};
static constexpr int DatVertexFaceIndex[10][12] = {{0, 0, 2}, {1, 2, 0}, {2, 2, 0}, {1, 1, 1}, {1, 2, 0, 0, 0, 2, 0, 2, 2}, 
       {2, 2, 0, 1, 2, 0, 0, 0, 2}, {2, 2, 0, 0, 0, 2, 2, 0, 1, 2, 0, 2}, {1, 1, 1, 0, 0, 2, 2, 0, 2}, 
       {1, 1, 1, 1, 2, 0, 1, 1, 1, 1, 0, 0}, {1, 1, 1, 2, 2, 0, 1, 1, 1}};
static constexpr int DatVertexFaceLen[10] = {3, 3, 3, 3, 9, 9, 12, 9, 12, 9};
static constexpr int DatFaceEdge[24][3] = {{0, 12, 5}, {6, 15, 0}, {15, 22, 12}, {22, 6, 5}, {1, 2, 13}, {16, 8, 1}, {8, 18, 2}, 
       {18, 16, 13}, {14, 3, 4}, {21, 19, 14}, {19, 10, 3}, {10, 21, 4}, {17, 20, 23}, {7, 9, 17}, {9, 11, 20}, {11, 7, 23}, 
       {16, 24, 12}, {24, 17, 22}, {17, 16, 15}, {14, 12, 13}, {18, 24, 14}, {21, 23, 22}, {20, 21, 24}, {20, 19, 18}};
static constexpr int DatEdgeFace[25][4] = {{0, 1}, {4, 5}, {4, 6}, {8, 10}, {8, 11}, {0, 3}, {1, 3}, {13, 15}, {5, 6}, 
       {13, 14}, {10, 11}, {14, 15}, {0, 2, 16, 19}, {4, 7, 19}, {8, 9, 19, 20}, {1, 2, 18}, {5, 7, 16, 18}, {12, 13, 17, 18}, 
       {6, 7, 20, 23}, {9, 10, 23}, {12, 14, 22, 23}, {9, 11, 21, 22}, {2, 3, 17, 21}, {12, 15, 21}, {16, 17, 20, 22}};
static constexpr int DatEdgeFaceIndex[25][4] = {{0, 2}, {0, 2}, {1, 2}, {1, 2}, {2, 2}, {2, 2}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, 
       {1, 0}, {1, 0}, {1, 2, 2, 1}, {2, 2, 2}, {0, 2, 0, 2}, {1, 0, 2}, {0, 1, 0, 1}, {0, 2, 1, 0}, {1, 0, 0, 2}, {1, 0, 1}, 
       {1, 2, 0, 0}, {0, 1, 0, 1}, {1, 0, 2, 2}, {2, 2, 1}, {1, 0, 1, 2}};
static constexpr int DatEdgeFaceLen[25] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 3, 4, 3, 4, 4, 4, 3, 4, 4, 4, 3, 4};
static constexpr int DatNewVertexEqOldVertex[4] = {0, 1, 2, 3};
static constexpr int DatNewVertexEqOldVertexIndex[4] = {0, 1, 2, 3};
static constexpr double DatOldFaceNewVertexPos[4][6][3] = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0.5, 0.5, 0}, {0, 0.5, 0.5}, {0.5, 0, 0.5}},
             {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0.5, 0.5, 0}, {0, 0.5, 0.5}, {0.5, 0, 0.5}},
             {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0.5, 0.5, 0}, {0, 0.5, 0.5}, {0.5, 0, 0.5}},
             {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {0.5, 0.5, 0}, {0, 0.5, 0.5}, {0.5, 0, 0.5}}};
static constexpr int DatInteriorEdgeOfCell[1] = {24};
static constexpr int DatInteriorFaceOfCell[8] = {2, 7, 9, 12, 16, 17, 20, 22};
static constexpr int DatInteriorVertexOfEdge[6][1] = {{4}, {5}, {6}, {7}, {8}, {9}};
static constexpr int DatInteriorVertexOfEdgeLen[6]={1, 1, 1, 1, 1, 1};
static constexpr int DatInteriorEdgeOfFace[4][3] = {{12, 13, 14}, {15, 16, 17}, {18, 19, 20}, {21, 22, 23}};
static constexpr int DatInteriorEdgeOfFaceLen[4] = {3, 3, 3, 3};
static constexpr int DatOldEdgeNewVertex[6][3] = {{0, 4, 1}, {1, 5, 2}, {2, 6, 0}, {0, 7, 3}, {1, 8, 3}, {2, 9, 3}};
static constexpr int DatOldEdgeNewVertexLen[6] = {3, 3, 3, 3, 3, 3 };
static constexpr int DatOldEdgeNewEdge[6][2] = {{0, 1}, {2, 3}, {4, 5}, {6, 7}, {8, 9}, {10, 11}};
static constexpr int DatOldEdgeNewEdgeLen[6] = {2, 2, 2, 2, 2, 2};
static constexpr int DatOldFaceNewVertex[4][6] = {{0, 1, 2, 4, 5, 6}, {0, 3, 1, 7, 8, 4}, {2, 1, 3, 5, 8, 9}, {0, 2, 3, 6, 9, 7}};
static constexpr int DatOldFaceNewVertexLen[4] = {6, 6, 6, 6};
static constexpr int DatOldFaceNewEdge[4][9] = {{0, 1, 2, 3, 4, 5, 12, 13, 14}, {0, 1, 6, 7, 8, 9, 15, 16, 17}, 
       {2, 3, 8, 9, 10, 11, 18, 19, 20}, {4, 5, 6, 7, 10, 11, 21, 22, 23}};
static constexpr int DatOldFaceNewEdgeLen[4] = {9, 9, 9, 9};
static constexpr int DatOldFaceNewFace[4][4] = {{0, 4, 8, 19}, {1, 13, 5, 18}, {10, 6, 14, 23}, {3, 11, 15, 21}};
static constexpr int DatOldFaceNewFaceLen[4] = {4, 4, 4, 4};
static constexpr int DatNewEdgeOldEdge[25] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
static constexpr int DatNewFaceOldFace[24] = {0, 1, -1, 3, 0, 1, 2, -1, 0, -1, 2, 3, -1, 1, 2, 3, -1, -1, 1, 0, -1, 3, -1, 2};
static constexpr int DatOldFaceNewLocFace[8][4] = {{0, 1, -1, 3}, {0, 1, 2, -1}, {0, -1, 2, 3}, {-1, 1, 2, 3}, {-1, 3, -1, -1}, 
       {0, -1, -1, -1}, {-1, -1, -1, 1}, {-1, -1, 1, -1}};
static constexpr int DatChildTwistIndex[24] = {0, 0, -1, 0, 1, 2, 1, -1, 2, -1, 0, 1, -1, 1, 2, 2, -1, -1, 1, 2, -1, 0, -1, 2};

 this->RefinementType = RefineType::Tetra_4Reg;
 this->N_Edges = 25;
 this->N_Vertices = 10;
 this->N_Faces = 24;
 this->N_Children = 8;
 this->N_NewVertEqOldVert = 4;
 this->N_InnerFaces = 8;  
 this->N_InnerEdges = 1;
  
 this->MaxN_VpC = 4;
 this->MaxN_CpV = 6;
 this->MaxN_EpC = 6;
 this->MaxN_CpE = 4;
 this->MaxN_EpV = 7;
 this->MaxN_EpF = 3;
 this->MaxN_FpE = 4;
 this->MaxN_VpF = 3;
 this->MaxN_FpV = 12;
 this->MaxN_FpC = 4;
 this->MaxN_CpF = 2;
 this->MaxN_iVpE = 1;
 this->MaxN_iEpF = 3;
 this->MaxN_nVpoE = 3;
 this->MaxN_nEpoE = 2;
 this->MaxN_nVpoF = 6;
 this->MaxN_oVpoF = 3;
 this->MaxN_nEpoF = 9;
 this->MaxN_nFpoF = 4;

 this->ChildType = static_cast<const CellType *>(DatChildType);
 this->EdgeType = static_cast<const RefineType *>(DatEdgeType);
 this->FaceType = static_cast<const RefineType *>(DatFaceType);

 this->ChildVertex = static_cast<const int *>(*DatChildVertex);
 this->VertexChild =  static_cast<const int *>(*DatVertexChild);
 this->VertexChildIndex = static_cast<const int *>(*DatVertexChildIndex);
 this->VertexChildLen = static_cast<const int *>(DatVertexChildLen);

 this->ChildFace = static_cast<const int *>(*DatChildFace);
 this->FaceChild = static_cast<const int *>(*DatFaceChild);
 this->FaceChildIndex = static_cast<const int *>(*DatFaceChildIndex);
 this->FaceChildLen = static_cast<const int *>(DatFaceChildLen);

 this->ChildEdge = static_cast<const int *>(*DatChildEdge);
 this->EdgeChild = static_cast<const int *>(*DatEdgeChild);
 this->EdgeChildIndex = static_cast<const int *>(*DatEdgeChildIndex);
 this->EdgeChildLen = static_cast<const int *>(DatEdgeChildLen);

 this->EdgeVertex = static_cast<const int *>(*DatEdgeVertex);
 this->VertexEdge = static_cast<const int *>(*DatVertexEdge);
 this->VertexEdgeIndex = static_cast<const int *>(*DatVertexEdgeIndex);
 this->VertexEdgeLen = static_cast<const int *>(DatVertexEdgeLen);

 this->FaceVertex = static_cast<const int *>(*DatFaceVertex);
 this->VertexFace = static_cast<const int *>(*DatVertexFace);
 this->VertexFaceIndex = static_cast<const int *>(*DatVertexFaceIndex);
 this->VertexFaceLen = static_cast<const int *>(DatVertexFaceLen);

 this->FaceEdge = static_cast<const int *>(*DatFaceEdge);
 this->EdgeFace = static_cast<const int *>(*DatEdgeFace);
 this->EdgeFaceIndex = static_cast<const int *>(*DatEdgeFaceIndex);
 this->EdgeFaceLen = static_cast<const int *>(DatEdgeFaceLen);

 this->NewVertexEqOldVertex = static_cast<const int *>(DatNewVertexEqOldVertex);
 this->NewVertexEqOldVertexIndex = static_cast<const int *>(DatNewVertexEqOldVertexIndex);

 this->InteriorEdgeOfCell = static_cast<const int *>(DatInteriorEdgeOfCell);
 this->InteriorFaceOfCell = static_cast<const int *>(DatInteriorFaceOfCell); 
 this->InteriorVertexOfEdge = static_cast<const int *>(*DatInteriorVertexOfEdge);
 this->InteriorVertexOfEdgeLen = static_cast<const int *>(DatInteriorVertexOfEdgeLen);
 this->InteriorEdgeOfFace = static_cast<const int *>(*DatInteriorEdgeOfFace);
 this->InteriorEdgeOfFaceLen = static_cast<const int *>(DatInteriorEdgeOfFaceLen);

 this->OldEdgeNewVertex = static_cast<const int *>(*DatOldEdgeNewVertex);
 this->OldEdgeNewVertexLen = static_cast<const int *>(DatOldEdgeNewVertexLen);

 this->OldEdgeNewEdge = static_cast<const int *>(*DatOldEdgeNewEdge);
 this->OldEdgeNewEdgeLen = static_cast<const int *>(DatOldEdgeNewEdgeLen);
 this->NewEdgeOldEdge = static_cast<const int *>(DatNewEdgeOldEdge);
 this->NewFaceOldFace =  static_cast<const int *>(DatNewFaceOldFace);

 this->OldFaceNewVertex = static_cast<const int *>(*DatOldFaceNewVertex);
 this->OldFaceNewVertexPos = static_cast<const double *>(*(*DatOldFaceNewVertexPos));
 this->OldFaceNewVertexLen = static_cast<const int *>(DatOldFaceNewVertexLen);
 this->OldFaceNewEdge = static_cast<const int *>(*DatOldFaceNewEdge);
 this->OldFaceNewEdgeLen = static_cast<const int *>(DatOldFaceNewEdgeLen);
 this->OldFaceNewFace = static_cast<const int *>(*DatOldFaceNewFace);
 this->OldFaceNewFaceLen = static_cast<const int *>(DatOldFaceNewFaceLen);
 this->OldFaceNewLocFace = static_cast<const int *>(*DatOldFaceNewLocFace);
 this->ChildTwistIndex = static_cast<const int *>(DatChildTwistIndex);
}

// explicit instantiation
template class TRefineTetra_4Desc<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END

#endif