/** =======================================================================
* @class     TRefineDesc
* @brief     Refine descriptors
* @author    Sashikumaar Ganesan 
* @date      07.02.2020
* @History   
* ===========================================================================*/

#include <SParSH_Variables.h>
#include <CellDesc.h>
#include <memory>

#pragma once
SParSH_NAMESPACE_BEGIN

#define N_RefineTypes  11

/** \brief Types of refinement */
enum class RefineType:sint {NoRef, LineReg, TriReg, QuadReg, ParallReg, RectReg,
                            TetraReg, PyraReg, PrismReg, HexaReg};
 
enum class RefineMarker:sint {NoRefine, Refine, DeRefine};

template <sint dim=GEO_DIM> 
class TRefineDesc {

  protected:

    /** \brief descriptor of this cell */
    std::shared_ptr<sint >  CellDesc;
    /** \brief Type contains the enum ID of the refinement type */
    RefineType Type;
    /** \brief number of vertices in this cell */
    sint N_Vertices;
    /** \brief number of edges in a cell */
    sint N_Edges;
    /** \brief number of children */
    sint N_Children;
    /** \brief number of vertices of base cell */
    sint N_OrigVertices;
    /** \brief number of edges of base cell */
    sint N_OrigEdges;
   
#ifdef __3D__
    /** \brief number of faces */
    sint N_Faces;
    /**\brief  number of faces of base cell */
    sint N_OrigFaces;
    /** \brief number of inner faces */
    sint N_InnerFaces;  
#endif
    /** \brief number of new vertices, which equal to old vertices */
    sint N_NewVertEqOldVert;
    /** \brief number of new inner vertices */
    sint N_InnerVertices;
    /** \brief number of new edges, which equal to old edges */
    sint N_NewEdgeEqOldEdge;
    /** \brief number of new inner edges */
    sint N_InnerEdges;

    /** \brief maximum number of vertices per cell */
    sint MaxN_VpC;
    /** \brief maximum number of cells per vertex */
    sint MaxN_CpV;
    /** \brief maximum number of edges per cell */
    sint MaxN_EpC;
    /** \brief maximum number of cells per edge */
    sint MaxN_CpE;
    /** \brief maximum number of edges per vertex */
    sint MaxN_EpV;
    /** \brief maximum number of inner vertices per edge */
    sint MaxN_iVpE;
    /** \brief maximum number of new vertices per old edge */
    sint MaxN_nVpoE;
    /** \brief maximum number of new edges per old edge */
    sint MaxN_nEpoE;

    /** \brief type of children after refinement */
    std::shared_ptr<SParSH::TCellDesc<dim>>  ChildCellDesc;
 
    /** \brief refinement's types of the edges */
    const RefineType *ChildType;

    /** \brief which vertices build a child */
    const sint *ChildVertex;
    /** \brief number of vertices per child */
    const sint *ChildVertexLen;
    /** \brief which children meet on a vertex */
    const sint *VertexChild;
    /** \brief which local index has the vertex in each child */
    const sint *VertexChildIndex;
    /** \brief length of array VertexChild */
    const sint *VertexChildLen;

    /** which edges build a child */
    const sint *ChildEdge;
    /** which children are connectred with an edge */
    const sint *EdgeChild;
    /** which local index has the edge in each child */
    const sint *EdgeChildIndex;
    /** length of array EdgeChild */
    const sint *EdgeChildLen;

    /** which vertices belong to an edge */
    const sint *EdgeVertex;
    /** which edges meet on a vertex */
    const sint *VertexEdge;
    /** which index has the vertex in each edge */
    const sint *VertexEdgeIndex;
    /** length of array VertexEdge */
    const sint *VertexEdgeLen;

    /** which new vertices are equal to old vertices */
    const sint *NewVertexEqOldVertex;
    /** which old indices have the new vertices */
    const sint *NewVertexEqOldVertexIndex;

    /** which new edges are equal to old edges */
    const sint *NewEdgeEqOldEdge;
    /** which old indices have the new edges */
    const sint *NewEdgeEqOldEdgeIndex;

    /** indices of new inner vertices */
    const sint *InteriorVertexOfCell;
    /** position of new inner vertices as the coefficients for a linear
        combination of the old vertices */
    const double *PositionOfIntVert;

    /** indices  of new inner edges */
    const sint *InteriorEdgeOfCell;
    /** indices of inner vertices on an edge */
    const sint *InteriorVertexOfEdge;
    /** length of array InteriorVertexOfEdge */
    const sint *InteriorVertexOfEdgeLen;

    /** which new vertices are on an old edge */
    const sint *OldEdgeNewVertex;
    /** length of array NewVertex per old edge */
    const sint *OldEdgeNewVertexLen;

    /** which local edge of a child lies on an old edge (for each child) */
    const sint *OldEdgeNewLocEdge;

    /** which new edges lie on which old edge */
    const sint *OldEdgeNewEdge;
    /** length of array NewEdge per old edge */
    const sint *OldEdgeNewEdgeLen;
    /** to which old edge belongs a new edge */
    const sint *NewEdgeOldEdge;

    #ifdef __3D__
      /** maximum number of vertices per face */
      sint MaxN_VpF;
      /** maximum number of old vertices per old face */
      sint MaxN_oVpoF;
      /** maximum number of faces per vertex */
      sint MaxN_FpV;
      /** maximum number of edges per face */
      sint MaxN_EpF;
      /** maximum number of faces per edge */
      sint MaxN_FpE;
      /** maximum number of cells per face */
      sint MaxN_CpF;
      /** maximum number of faces per cell */
      sint MaxN_FpC;
      /** maximum number of inner vertices per face */
      sint MaxN_iVpF;
      /** maximum number of inner edges per face */
      sint MaxN_iEpF;
      /** maximum number of new edges per old face */
      sint MaxN_nEpoF;
      /** maximum number of new vertices per old face */
      sint MaxN_nVpoF;
      /** maximum number of new inner vertices per old face */
      sint MaxN_niVpoF;
      /** maximum number of new faces per old face */
      sint MaxN_nFpoF;
      /** refinement's types of the faces */
      const Refinements *FaceType;
      /** which children meet on a face */
      const sint *FaceChild;
      /** which local index has the face in each child */
      const sint *FaceChildIndex;
      /** length of array FaceChild */
      const sint *FaceChildLen;

      /** which edges built a face */
      const sint *FaceEdge;
      /** which faces are connected with edge . */
      const sint *EdgeFace;
      const sint *EdgeFaceLen;
      /** which local index has the edge in each face */
      const sint *EdgeFaceIndex;

      /** which vertices built a face */
      const sint *FaceVertex;
      /** which faces are connected with vertex . */
      const sint *VertexFace;
      const sint *VertexFaceLen;
      /** which local index has the vertex in each face */
      const sint *VertexFaceIndex;

      /** field of new inner faces */
      const sint *InteriorFaceOfCell;

      /** which vertices lie on interior of old face */
      const sint *InteriorVertexOfFace;
      const sint *InteriorVertexOfFaceLen;

      /** which edges lie on interior of old face */
      const sint *InteriorEdgeOfFace;
      const sint *InteriorEdgeOfFaceLen;

      /** which new Inner vertices lie on which old face */
      const sint *OldFaceNewInnerVertices;
      /** lenght of OldFaceNewVertices entries */
      const sint *OldFaceNewInnerVerticesLen;

      /** number of new faces equal old faces */
      sint N_NewFaceEqOldFace;
      /** which new faces are equal to old faces */
      const sint *NewFaceEqOldFace;
      /** which old indices have the new faces */
      const sint *NewFaceEqOldFaceIndex;

      /** number of new vertices on an old face */
      const sint *N_NewVertsOnOldFace;
      /** new vertices on an old face */
      const sint *NewVertsOnOldFace;
      /** position of new vertices on an old face */
      const double *NewVertsOnOldFacePos;

      /** which faces built a child */
      const sint *ChildFace;

      /** which new vertices belong to an old face */
      const sint *OldFaceNewVertex;
      /** position of new vertices on old face (convex linear combination) */
      const double *OldFaceNewVertexPos;
      /** number of new vertices which belong to an old face */
      const sint *OldFaceNewVertexLen;

      /** which new edges belong to an old face */
      const sint *OldFaceNewEdge;
      /** number of new vertices which belong to an old face */
      const sint *OldFaceNewEdgeLen;

      /** which new faces belong to an old face */
      const sint *OldFaceNewFace;
      /** number of new faces which belong to an old face */
      const sint *OldFaceNewFaceLen;

      /** on which old face does a new face lie */
      const sint *NewFaceOldFace;

      /** ??? */
      const sint *OldFaceNewLocFace;

      /** ??? */
      const sint *ChildTwistIndex;
    #endif



  public:
  
  // Constructors
  TRefineDesc();
    
  //methods 
 
};

SParSH_NAMESPACE_END