/** =======================================================================
* @class     TRefineDesc
* @brief     RefineDesc descriptors source 
* @author    Sashikumaar Ganesan 
* @date      07.02.2020
* @History   
===========================================================================*/

#include <RefineDesc.h>

SParSH_NAMESPACE_BEGIN

using namespace std; 

// Constructor
template <sint dim> 
TRefineDesc<dim>::TRefineDesc(TCellDesc<dim> *celldesc)
{
 CellDesc = celldesc;
 RefinementType = RefineType::NoRef;
 N_OrigEdges = CellDesc->GetN_Edges();   
 N_OrigVertices = CellDesc->GetN_Vertices();   
 N_Edges = 0;
 N_Vertices = 0;
 N_Children = 0;
 N_NewVertEqOldVert = 0;
 N_InnerVertices = 0;
 N_NewEdgeEqOldEdge = 0;
 N_InnerEdges = 0;
 MaxN_VpC = 0;
 MaxN_CpV = 0;
 MaxN_EpC = 0;
 MaxN_CpE = 0;
 MaxN_EpV = 0;
 MaxN_iVpE = 0;
 MaxN_nVpoE = 0;
 MaxN_nEpoE = 0;

 ChildType = nullptr;
 EdgeType = nullptr;

 ChildVertex = nullptr;
 VertexChild = nullptr;
 VertexChildIndex = nullptr;
 VertexChildLen = nullptr;

 ChildEdge = nullptr;
 EdgeChild = nullptr;
 EdgeChildIndex = nullptr;
 EdgeChildLen = nullptr;

 EdgeVertex = nullptr;
 VertexEdge = nullptr;
 VertexEdgeIndex = nullptr;
 VertexEdgeLen = nullptr;

 NewVertexEqOldVertex = nullptr;
 NewVertexEqOldVertexIndex = nullptr;

 NewEdgeEqOldEdge = nullptr;
 NewEdgeEqOldEdgeIndex = nullptr;

 InteriorEdgeOfCell = nullptr;
 InteriorVertexOfEdge = nullptr;
 InteriorVertexOfEdgeLen = nullptr;

 OldEdgeNewVertex = nullptr;
 OldEdgeNewVertexLen = nullptr;
 OldEdgeNewLocEdge = nullptr;
  
 OldEdgeNewEdge = nullptr;
 OldEdgeNewEdgeLen = nullptr;
 NewEdgeOldEdge = nullptr;

 #ifdef __3D__
  N_OrigFaces = CellDesc->GetN_Faces();
  N_Faces = 0;

  FaceType = nullptr;

  ChildFace = nullptr;
  FaceChild = nullptr;
  FaceChildIndex = nullptr;
  FaceChildLen = nullptr;

  FaceVertex = nullptr;
  VertexFace = nullptr;
  VertexFaceIndex = nullptr;
  VertexFaceLen = nullptr;

  FaceEdge = nullptr;
  EdgeFace = nullptr;
  EdgeFaceIndex = nullptr;
  EdgeFaceLen = nullptr;

  InteriorFaceOfCell = nullptr;
  InteriorVertexOfFace = nullptr;
  InteriorVertexOfFaceLen = nullptr;
  InteriorEdgeOfFace = nullptr;
  InteriorEdgeOfFaceLen = nullptr;

  NewFaceOldFace = nullptr;

  OldFaceNewVertex = nullptr;
  OldFaceNewVertexPos = nullptr;
  OldFaceNewVertexLen = nullptr;
  OldFaceNewEdge = nullptr;
  OldFaceNewEdgeLen = nullptr;
  OldFaceNewFace = nullptr;
  OldFaceNewFaceLen = nullptr;

  OldFaceNewLocFace = nullptr;
  ChildTwistIndex = nullptr;

 #endif
}

// explicit instantiation
template class TRefineDesc<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END
