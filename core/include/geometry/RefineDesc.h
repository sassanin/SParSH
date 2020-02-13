/** =======================================================================
* @class     TRefineDesc
* @brief     Refine descriptors 
*            Terminologies are similar as in our in-house package ParMooN
* @author    Sashikumaar Ganesan 
* @date      07.02.2020
* @History   
* ===========================================================================*/
#include <SParSH_IO.h>
#include <SParSH_Variables.h>
#include <CellDesc.h>
#include <memory>

#pragma once
SParSH_NAMESPACE_BEGIN

#define N_RefineTypes  11

/** \brief Types of refinement */
enum class RefineType:sint {NoRef, LineReg, TriReg, QuadReg, ParallReg, RectReg,
                            TetraReg, PyraReg, PrismReg, HexaReg, NotDefined};
 
enum class RefineMarker:sint {NoRefine, Refine, DeRefine, NotDefined};

template <sint dim=GEO_DIM> 
class TRefineDesc {

  protected:

    /** \brief descriptor of this cell */
    shared_ptr<TCellDesc<dim>> CellDesc;

    /** \brief Type contains the enum ID of the cell type */
    CellType Type;

    /** \brief Type contains the enum ID of the refinement type */
    RefineType RefinementType;
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
    vector<unique_ptr<TCellDesc<dim>>> ChildCellDesc;
 
    /** \brief refinement's types of the edges */
    const RefineType *ChildType;
    /** refinement's types of the edges */
    const RefineType *EdgeType;

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
      const RefineType *FaceType;
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

      /**   */
      const sint *OldFaceNewLocFace;

      /**   */
      const sint *ChildTwistIndex;
    #endif

  public:
  
  // Constructors
  TRefineDesc(TCellDesc<dim> celldesc);
    
  //methods 
  /** \brief return type of refinement */
  RefineType GetType()
   { return RefinementType; }
  
  /** return number of children */
  sint GetN_Children()
   { return N_Children; }
  
  /** return number of edges */
  sint GetN_Edges()
   { return N_Edges; }
   
  /** return number of vertices */
  sint GetN_Vertices()
   { return N_Vertices; }

  /** return number of edges on base cell */
  sint GetN_OrigEdges()
   { return N_OrigEdges; }
  
  /** return number of vertices on base cell */
  sint GetN_OrigVertices()
   { return N_OrigVertices; }

  #ifdef __3D__
  /** return number of faces */
  sint GetN_OrigFaces()
   { return N_OrigFaces; }
   
  /** return number of faces on base cell*/
  sint GetN_Faces()
    { return N_Faces; }
  #endif

  /** return a bool, whether to refine or not */
  virtual bool IsToRefine()
   { return true; }
    
  /** return shape descriptor */
  std::shared_ptr<SParSH::TCellDesc<dim>> GetCellDesc()
   { return CellDesc; }

  /** return refinement type of edge pos */
  RefineType GetEdgeRef(sint pos)
    { return EdgeType[pos]; }
   
  //return the raw pointer of the type of child number pos */
  TCellDesc<dim> *GetChildType(sint pos)
    { return (ChildCellDesc.at(pos)).get(); }   

  /** return number of new vertices, which equal old vertices */
  sint GetN_NewVertEqOldVert()
   { return N_NewVertEqOldVert; }
  
  /** return number of new inner vertices */
  sint GetN_InnerVertices()
   { return N_InnerVertices; }
  
  /** return number of new edges, which equal old edges */
  sint GetN_NewEdgeEqOldEdge() 
   { return N_NewEdgeEqOldEdge; }
  
  /** return number of new inner edges */
  sint GetN_InnerEdges()
   { return N_InnerEdges; }

  /** return auxilary fields in order to copy existing vertices */
  void GetNewVertEqOldVert(const sint *&TmpValues, const sint *&TmpIndex)
   {
    TmpValues = NewVertexEqOldVertex;
    TmpIndex = NewVertexEqOldVertexIndex;
   }

  /** return auxilary fields in order to create new inner vertices */
  void GetInnerVerts(const sint *&TmpValues, const double *&TmpPos, sint &MaxLen)
   {
    TmpValues = InteriorVertexOfCell;
    TmpPos = PositionOfIntVert;
    MaxLen = N_OrigVertices;
  }

  /** return auxilary fields in order to copy existing edges */
  void GetNewEdgeEqOldEdge(const sint *&TmpValues, const sint *&TmpIndex)
   {
    TmpValues = NewEdgeEqOldEdge;
    TmpIndex = NewEdgeEqOldEdgeIndex;
   }

  /** return auxilary fields in order to create new inner edges */
  sint GetInnerEdges(const sint *&TmpinE, const sint *&TmpEC, sint &MaxLen)
   {
    TmpinE = InteriorEdgeOfCell;
    TmpEC = EdgeChild;
    MaxLen = MaxN_CpE;
   }

  /** return the array OldEdgeNewEdge */
  void GetOldEdgeNewEdge(const sint *&TmpoEnE, const sint *&TmpLen, sint &MaxLen)
   {
    TmpoEnE = OldEdgeNewEdge;
    TmpLen = InteriorVertexOfEdgeLen;
    MaxLen = MaxN_nEpoE;
   }

  /** return the array OldEdgeNewLocEdge */
  void GetOldEdgeNewLocEdge(const sint *&TmpoEnlE)
   { TmpoEnlE=OldEdgeNewLocEdge; }

  /** return the array NewEdgeOldEdge */
  void GetNewEdgeOldEdge(const sint *&TmpnEoE)
   { TmpnEoE = NewEdgeOldEdge; }

  /** return the array EdgeChild */
  void GetEdgeChild(const sint *&TmpEC, const sint *&TmpLen, sint &MaxLen)
   {
    TmpEC = EdgeChild;
    TmpLen = EdgeChildLen;
    MaxLen = MaxN_CpE;
   }

  /** return the array EdgeChildIndex */
  void GetEdgeChildIndex(const sint *&TmpECI, const sint *&TmpLen, sint &MaxLen)
    {
     TmpECI = EdgeChildIndex;
     TmpLen = EdgeChildLen;
     MaxLen = MaxN_CpE;
    }

  /** return the array OldEdgeNewVertex */
  void GetOldEdgeNewVertex(const sint *&TmpoEnV, const sint *&TmpLen, sint &MaxLen)
   {
    TmpoEnV = OldEdgeNewVertex;
    TmpLen = InteriorVertexOfEdgeLen;
    MaxLen = MaxN_nVpoE;
   }
    
  /** return the array EdgeVertex */
  void GetEdgeVertex(const sint *&TmpEV)
   { TmpEV = EdgeVertex; }

  /** return the array VertexEdge */
  void GetVertexEdge(const sint *&TmpVE, const sint *&TmpLen, sint &MaxLen)
    {
     TmpVE = VertexEdge;
     TmpLen = VertexEdgeLen;
     MaxLen = MaxN_EpV;
    }

  /** return the array VertexEdgeIndex */
  void GetVertexEdgeIndex(const sint *&TmpVEI, const sint *&TmpLen, sint &MaxLen)
   {
    TmpVEI = VertexEdgeIndex;
    TmpLen = VertexEdgeLen;
    MaxLen = MaxN_EpV;
   }

  /** return the array VertexChild */
  void GetVertexChild(const sint *&TmpVC, const sint *&TmpLen, sint &MaxLen)
   {
    TmpVC = VertexChild;
    TmpLen = VertexChildLen;
    MaxLen = MaxN_CpV;
   }

  /** return the array VertexChildIndex */
  void GetVertexChildIndex(const sint *&TmpVCI, const sint *&TmpLen, sint &MaxLen)
   {
    TmpVCI = VertexChildIndex;
    TmpLen = VertexChildLen;
    MaxLen = MaxN_CpV;
    }

    /** return the array ChildVertex */
  void GetChildVertex(const sint *&TmpCV, sint &MaxLen)
   {
    TmpCV =  ChildVertex;
    MaxLen = MaxN_VpC;
   }

  /** return the array ChildEdge */
  void GetChildEdge(const sint *&TmpCE, sint &MaxLen)
   {
    TmpCE =  ChildEdge;
    MaxLen = MaxN_EpC;
   }

  #ifdef __3D__
   /** return number of inner faces */
   sint GetN_InnerFaces()
    {return N_InnerFaces; }
   
 /** return auxilary fields in order to create new inner faces */
  void GetInnerFaces(const sint *&TmpinF, const sint *&TmpFC, sint &MaxLen)
   {
    TmpinF = InteriorFaceOfCell;
    TmpFC = FaceChild;
    MaxLen = MaxN_CpF;
   }

  /** return field of new vertices on an old face */
  void GetOldFaceNewInnerVertex(const sint *&TmpoFniV, const sint *&TmpLen, sint &MaxLen)
   {
    TmpoFniV = OldFaceNewInnerVertices;
    TmpLen = OldFaceNewInnerVerticesLen;
    MaxLen = MaxN_niVpoF;
   }

  /** return field of new faces on old faces */
  void GetOldFaceNewFace(const sint *&TmpoFnF, const sint *&TmpLen,sint &MaxLen)
   {
    TmpoFnF = OldFaceNewFace;
    TmpLen = OldFaceNewFaceLen;
    MaxLen = MaxN_nFpoF;
   }

  /** return the refinement type of face i */
  RefineType GetFaceRef(sint i)
   { return FaceType[i]; }

  /** return number of new faces equal old faces */
  sint GetN_NewFaceEqOldFace()
   { return N_NewFaceEqOldFace; }

  /** return the array NewFaceEqOldFace */
  void GetNewFaceEqOldFace(const sint *&TmpValues, const sint *&TmpIndex)
   {
    TmpValues = NewFaceEqOldFace;
    TmpIndex = NewFaceEqOldFaceIndex;
   }

  /** return the array FaceChild */
  void GetFaceChild(const sint *&TmpFC, const sint *&TmpLen, sint &MaxLen)
   {
    TmpFC = FaceChild;
    TmpLen = FaceChildLen;
    MaxLen = MaxN_CpF;
   }

  /** return the array FaceChildIndex */
  void GetFaceChildIndex(const sint *&TmpFCI, const sint *&TmpLen, sint &MaxLen)
   {
    TmpFCI = FaceChildIndex;
    TmpLen = FaceChildLen;
    MaxLen = MaxN_CpF;
   }

  /** return the array FaceEdge */
  void GetFaceEdge(const sint *&TmpFE, sint &MaxLen)
   {
    TmpFE =  FaceEdge;
    MaxLen = MaxN_EpF;
   }

  /** return field NewVertsOnOldFace for face i */
  void GetNewVertsOnOldFace(const sint *&TmpNV, const double *&TmpPos, sint &MaxLen)
   {
    TmpNV = NewVertsOnOldFace;
    TmpPos = NewVertsOnOldFacePos;
    MaxLen = MaxN_nVpoF;
   }

  /** return the field ChildFace */
  void GetChildFace(const sint *&TmpCF, sint &MaxLen)
   {
    TmpCF = ChildFace;
    MaxLen = MaxN_FpC;
   }

  /** return the field OldFaceNewVertex */
  void GetOldFaceNewVertex(const sint *&TmpoFnV, const sint *&TmpLen, sint &MaxLen)
   {
    TmpoFnV = OldFaceNewVertex;
    TmpLen = OldFaceNewVertexLen;
    MaxLen = MaxN_nVpoF;
   }

  /** return the field OldFaceNewVertex */
  void GetOldFaceNewVertex(const sint *&TmpoFnV, const double *&TmpPos,
                           const sint *&TmpLen, sint &MaxLen1, sint &MaxLen2)
   {
    TmpoFnV = OldFaceNewVertex;
    TmpPos = OldFaceNewVertexPos;
    TmpLen = OldFaceNewVertexLen;
    MaxLen1 = MaxN_nVpoF;
    MaxLen2 = MaxN_oVpoF;
   }

  /** return the field NewFaceOldFace */
  void GetNewFaceOldFace(const sint *&TmpnFoF)
   {
    TmpnFoF = NewFaceOldFace;
   }

  /** return the array OldFaceNewLocFace */
  void GetOldFaceNewLocFace(const sint *&TmpoFnlF)
   {
    TmpoFnlF = OldFaceNewLocFace;
   }

  /** return the array ChildTwistIndex */
  void GetChildTwistIndex(const sint *&TmpCTI)
   {
    TmpCTI = ChildTwistIndex;
   }
      
  /** return the array FaceVertex **/
  void GetFaceVertex (const sint *&TmpFV, sint &TmpLen)
   {
	  TmpFV = FaceVertex;
	  TmpLen = MaxN_VpF;
   }

    #endif 

};

SParSH_NAMESPACE_END