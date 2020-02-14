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
enum class RefineType:sint {NoRef, Line_2Reg, Tri_3Reg, Quad_4Reg, ParallReg, RectReg,
                            Tetra_4Reg, Pyra_5Reg, Prism_6Reg, Hexa_8Reg, NotDefined};
 
enum class RefineMarker:sint {NoRefine, Refine, DeRefine, NotDefined};

template <sint dim=GEO_DIM> 
class TRefineDesc {

  protected:

    /** \brief descriptor (raw) of this cell */
    TCellDesc<dim> *CellDesc;

    /** \brief Type contains the enum ID of the refinement type */
    RefineType RefinementType;

    /** \brief number of vertices in this cell */
    int N_Vertices;

    /** \brief number of edges in a cell */
    int N_Edges;

    /** \brief number of children */
    int N_Children;

    /** \brief number of vertices of base cell */
    int N_OrigVertices;

    /** \brief number of edges of base cell */
    int N_OrigEdges;
   
#ifdef __3D__
    /** \brief number of faces */
    int N_Faces;
    /**\brief  number of faces of base cell */
    int N_OrigFaces;
    /** \brief number of inner faces */
    int N_InnerFaces;  
#endif
    /** \brief number of new vertices, which equal to old vertices */
    int N_NewVertEqOldVert;
    /** \brief number of new inner vertices */
    int N_InnerVertices;
    /** \brief number of new edges, which equal to old edges */
    int N_NewEdgeEqOldEdge;
    /** \brief number of new inner edges */
    int N_InnerEdges;

    /** \brief maximum number of vertices per cell */
    int MaxN_VpC;
    /** \brief maximum number of cells per vertex */
    int MaxN_CpV;
    /** \brief maximum number of edges per cell */
    int MaxN_EpC;
    /** \brief maximum number of cells per edge */
    int MaxN_CpE;
    /** \brief maximum number of edges per vertex */
    int MaxN_EpV;
    /** \brief maximum number of inner vertices per edge */
    int MaxN_iVpE;
    /** \brief maximum number of new vertices per old edge */
    int MaxN_nVpoE;
    /** \brief maximum number of new edges per old edge */
    int MaxN_nEpoE;

    /** \brief type of children after refinement */
    vector<unique_ptr<TCellDesc<dim>>> ChildCellDesc;
 
    /** \brief refinement's types of the edges */
    const CellType *ChildType;
    
    /** refinement's types of the edges */
    const RefineType *EdgeType;

    /** \brief which vertices build a child */
    const int *ChildVertex;
    /** \brief number of vertices per child */
    const int *ChildVertexLen;
    /** \brief which children meet on a vertex */
    const int *VertexChild;
    /** \brief which local index has the vertex in each child */
    const int *VertexChildIndex;
    /** \brief length of array VertexChild */
    const int *VertexChildLen;

    /** which edges build a child */
    const int *ChildEdge;
    /** which children are connectred with an edge */
    const int *EdgeChild;
    /** which local index has the edge in each child */
    const int *EdgeChildIndex;
    /** length of array EdgeChild */
    const int *EdgeChildLen;

    /** which vertices belong to an edge */
    const int *EdgeVertex;
    /** which edges meet on a vertex */
    const int *VertexEdge;
    /** which index has the vertex in each edge */
    const int *VertexEdgeIndex;
    /** length of array VertexEdge */
    const int *VertexEdgeLen;

    /** which new vertices are equal to old vertices */
    const int *NewVertexEqOldVertex;
    /** which old indices have the new vertices */
    const int *NewVertexEqOldVertexIndex;

    /** which new edges are equal to old edges */
    const int *NewEdgeEqOldEdge;
    /** which old indices have the new edges */
    const int *NewEdgeEqOldEdgeIndex;

    /** indices of new inner vertices */
    const int *InteriorVertexOfCell;
    /** position of new inner vertices as the coefficients for a linear
        combination of the old vertices */
    const double *PositionOfIntVert;

    /** indices  of new inner edges */
    const int *InteriorEdgeOfCell;
    /** indices of inner vertices on an edge */
    const int *InteriorVertexOfEdge;
    /** length of array InteriorVertexOfEdge */
    const int *InteriorVertexOfEdgeLen;

    /** which new vertices are on an old edge */
    const int *OldEdgeNewVertex;
    /** length of array NewVertex per old edge */
    const int *OldEdgeNewVertexLen;

    /** which local edge of a child lies on an old edge (for each child) */
    const int *OldEdgeNewLocEdge;

    /** which new edges lie on which old edge */
    const int *OldEdgeNewEdge;
    /** length of array NewEdge per old edge */
    const int *OldEdgeNewEdgeLen;
    /** to which old edge belongs a new edge */
    const int *NewEdgeOldEdge;

    #ifdef __3D__
      /** maximum number of vertices per face */
      int MaxN_VpF;
      /** maximum number of old vertices per old face */
      int MaxN_oVpoF;
      /** maximum number of faces per vertex */
      int MaxN_FpV;
      /** maximum number of edges per face */
      int MaxN_EpF;
      /** maximum number of faces per edge */
      int MaxN_FpE;
      /** maximum number of cells per face */
      int MaxN_CpF;
      /** maximum number of faces per cell */
      int MaxN_FpC;
      /** maximum number of inner vertices per face */
      int MaxN_iVpF;
      /** maximum number of inner edges per face */
      int MaxN_iEpF;
      /** maximum number of new edges per old face */
      int MaxN_nEpoF;
      /** maximum number of new vertices per old face */
      int MaxN_nVpoF;
      /** maximum number of new inner vertices per old face */
      int MaxN_niVpoF;
      /** maximum number of new faces per old face */
      int MaxN_nFpoF;
      /** refinement's types of the faces */
      const RefineType *FaceType;
      /** which children meet on a face */
      const int *FaceChild;
      /** which local index has the face in each child */
      const int *FaceChildIndex;
      /** length of array FaceChild */
      const int *FaceChildLen;

      /** which edges built a face */
      const int *FaceEdge;
      /** which faces are connected with edge . */
      const int *EdgeFace;
      const int *EdgeFaceLen;
      /** which local index has the edge in each face */
      const int *EdgeFaceIndex;

      /** which vertices built a face */
      const int *FaceVertex;
      /** which faces are connected with vertex . */
      const int *VertexFace;
      const int *VertexFaceLen;
      /** which local index has the vertex in each face */
      const int *VertexFaceIndex;

      /** field of new inner faces */
      const int *InteriorFaceOfCell;

      /** which vertices lie on interior of old face */
      const int *InteriorVertexOfFace;
      const int *InteriorVertexOfFaceLen;

      /** which edges lie on interior of old face */
      const int *InteriorEdgeOfFace;
      const int *InteriorEdgeOfFaceLen;

      /** which new Inner vertices lie on which old face */
      const int *OldFaceNewInnerVertices;
      /** lenght of OldFaceNewVertices entries */
      const int *OldFaceNewInnerVerticesLen;

      /** number of new faces equal old faces */
      int N_NewFaceEqOldFace;
      /** which new faces are equal to old faces */
      const int *NewFaceEqOldFace;
      /** which old indices have the new faces */
      const int *NewFaceEqOldFaceIndex;

      /** number of new vertices on an old face */
      const int *N_NewVertsOnOldFace;
      /** new vertices on an old face */
      const int *NewVertsOnOldFace;
      /** position of new vertices on an old face */
      const double *NewVertsOnOldFacePos;

      /** which faces built a child */
      const int *ChildFace;

      /** which new vertices belong to an old face */
      const int *OldFaceNewVertex;
      /** position of new vertices on old face (convex linear combination) */
      const double *OldFaceNewVertexPos;
      /** number of new vertices which belong to an old face */
      const int *OldFaceNewVertexLen;

      /** which new edges belong to an old face */
      const int *OldFaceNewEdge;
      /** number of new vertices which belong to an old face */
      const int *OldFaceNewEdgeLen;

      /** which new faces belong to an old face */
      const int *OldFaceNewFace;
      /** number of new faces which belong to an old face */
      const int *OldFaceNewFaceLen;

      /** on which old face does a new face lie */
      const int *NewFaceOldFace;

      /**   */
      const int *OldFaceNewLocFace;

      /**   */
      const int *ChildTwistIndex;
    #endif

  public:
  
  // Constructors
  TRefineDesc(TCellDesc<dim> *celldesc);
    
  //methods 
  /** \brief return type of refinement */
  RefineType GetType()
   { return RefinementType; }
  
  /** return number of children */
  int GetN_Children()
   { return N_Children; }
  
  /** return number of edges */
  int GetN_Edges()
   { return N_Edges; }
   
  /** return number of vertices */
  int GetN_Vertices()
   { return N_Vertices; }

  /** return number of edges on base cell */
  int GetN_OrigEdges()
   { return N_OrigEdges; }
  
  /** return number of vertices on base cell */
  int GetN_OrigVertices()
   { return N_OrigVertices; }

  #ifdef __3D__
  /** return number of faces */
  int GetN_OrigFaces()
   { return N_OrigFaces; }
   
  /** return number of faces on base cell*/
  int GetN_Faces()
    { return N_Faces; }
  #endif

  /** return a bool, whether to refine or not */
  virtual bool IsToRefine()
   { return true; }
    
  /** return cell (raw) descriptor */
  // TCellDesc<dim> *GetCellDesc()
  //  { return CellDesc; }

  /** return refinement type of edge pos */
  RefineType GetEdgeRef(int pos)
    { return EdgeType[pos]; }
   
  //return the raw pointer of the type of child number pos */
  TCellDesc<dim> *GetChildType(int pos)
    { return (ChildCellDesc.at(pos)).get(); }   

  /** return number of new vertices, which equal old vertices */
  int GetN_NewVertEqOldVert()
   { return N_NewVertEqOldVert; }
  
  /** return number of new inner vertices */
  int GetN_InnerVertices()
   { return N_InnerVertices; }
  
  /** return number of new edges, which equal old edges */
  int GetN_NewEdgeEqOldEdge() 
   { return N_NewEdgeEqOldEdge; }
  
  /** return number of new inner edges */
  int GetN_InnerEdges()
   { return N_InnerEdges; }

  /** return auxilary fields in order to copy existing vertices */
  void GetNewVertEqOldVert(const int *&TmpValues, const int *&TmpIndex)
   {
    TmpValues = NewVertexEqOldVertex;
    TmpIndex = NewVertexEqOldVertexIndex;
   }

  /** return auxilary fields in order to create new inner vertices */
  void GetInnerVerts(const int *&TmpValues, const double *&TmpPos, int &MaxLen)
   {
    TmpValues = InteriorVertexOfCell;
    TmpPos = PositionOfIntVert;
    MaxLen = N_OrigVertices;
  }

  /** return auxilary fields in order to copy existing edges */
  void GetNewEdgeEqOldEdge(const int *&TmpValues, const int *&TmpIndex)
   {
    TmpValues = NewEdgeEqOldEdge;
    TmpIndex = NewEdgeEqOldEdgeIndex;
   }

  /** return auxilary fields in order to create new inner edges */
  int GetInnerEdges(const int *&TmpinE, const int *&TmpEC, int &MaxLen)
   {
    TmpinE = InteriorEdgeOfCell;
    TmpEC = EdgeChild;
    MaxLen = MaxN_CpE;
   }

  /** return the array OldEdgeNewEdge */
  void GetOldEdgeNewEdge(const int *&TmpoEnE, const int *&TmpLen, int &MaxLen)
   {
    TmpoEnE = OldEdgeNewEdge;
    TmpLen = InteriorVertexOfEdgeLen;
    MaxLen = MaxN_nEpoE;
   }

  /** return the array OldEdgeNewLocEdge */
  void GetOldEdgeNewLocEdge(const int *&TmpoEnlE)
   { TmpoEnlE=OldEdgeNewLocEdge; }

  /** return the array NewEdgeOldEdge */
  void GetNewEdgeOldEdge(const int *&TmpnEoE)
   { TmpnEoE = NewEdgeOldEdge; }

  /** return the array EdgeChild */
  void GetEdgeChild(const int *&TmpEC, const int *&TmpLen, int &MaxLen)
   {
    TmpEC = EdgeChild;
    TmpLen = EdgeChildLen;
    MaxLen = MaxN_CpE;
   }

  /** return the array EdgeChildIndex */
  void GetEdgeChildIndex(const int *&TmpECI, const int *&TmpLen, int &MaxLen)
    {
     TmpECI = EdgeChildIndex;
     TmpLen = EdgeChildLen;
     MaxLen = MaxN_CpE;
    }

  /** return the array OldEdgeNewVertex */
  void GetOldEdgeNewVertex(const int *&TmpoEnV, const int *&TmpLen, int &MaxLen)
   {
    TmpoEnV = OldEdgeNewVertex;
    TmpLen = InteriorVertexOfEdgeLen;
    MaxLen = MaxN_nVpoE;
   }
    
  /** return the array EdgeVertex */
  void GetEdgeVertex(const int *&TmpEV)
   { TmpEV = EdgeVertex; }

  /** return the array VertexEdge */
  void GetVertexEdge(const int *&TmpVE, const int *&TmpLen, int &MaxLen)
    {
     TmpVE = VertexEdge;
     TmpLen = VertexEdgeLen;
     MaxLen = MaxN_EpV;
    }

  /** return the array VertexEdgeIndex */
  void GetVertexEdgeIndex(const int *&TmpVEI, const int *&TmpLen, int &MaxLen)
   {
    TmpVEI = VertexEdgeIndex;
    TmpLen = VertexEdgeLen;
    MaxLen = MaxN_EpV;
   }

  /** return the array VertexChild */
  void GetVertexChild(const int *&TmpVC, const int *&TmpLen, int &MaxLen)
   {
    TmpVC = VertexChild;
    TmpLen = VertexChildLen;
    MaxLen = MaxN_CpV;
   }

  /** return the array VertexChildIndex */
  void GetVertexChildIndex(const int *&TmpVCI, const int *&TmpLen, int &MaxLen)
   {
    TmpVCI = VertexChildIndex;
    TmpLen = VertexChildLen;
    MaxLen = MaxN_CpV;
    }

    /** return the array ChildVertex */
  void GetChildVertex(const int *&TmpCV, int &MaxLen)
   {
    TmpCV =  ChildVertex;
    MaxLen = MaxN_VpC;
   }

  /** return the array ChildEdge */
  void GetChildEdge(const int *&TmpCE, int &MaxLen)
   {
    TmpCE =  ChildEdge;
    MaxLen = MaxN_EpC;
   }

  #ifdef __3D__
   /** return number of inner faces */
   int GetN_InnerFaces()
    {return N_InnerFaces; }
   
 /** return auxilary fields in order to create new inner faces */
  void GetInnerFaces(const int *&TmpinF, const int *&TmpFC, int &MaxLen)
   {
    TmpinF = InteriorFaceOfCell;
    TmpFC = FaceChild;
    MaxLen = MaxN_CpF;
   }

  /** return field of new vertices on an old face */
  void GetOldFaceNewInnerVertex(const int *&TmpoFniV, const int *&TmpLen, int &MaxLen)
   {
    TmpoFniV = OldFaceNewInnerVertices;
    TmpLen = OldFaceNewInnerVerticesLen;
    MaxLen = MaxN_niVpoF;
   }

  /** return field of new faces on old faces */
  void GetOldFaceNewFace(const int *&TmpoFnF, const int *&TmpLen,int &MaxLen)
   {
    TmpoFnF = OldFaceNewFace;
    TmpLen = OldFaceNewFaceLen;
    MaxLen = MaxN_nFpoF;
   }

  /** return the refinement type of face i */
  RefineType GetFaceRef(int i)
   { return FaceType[i]; }

  /** return number of new faces equal old faces */
  int GetN_NewFaceEqOldFace()
   { return N_NewFaceEqOldFace; }

  /** return the array NewFaceEqOldFace */
  void GetNewFaceEqOldFace(const int *&TmpValues, const int *&TmpIndex)
   {
    TmpValues = NewFaceEqOldFace;
    TmpIndex = NewFaceEqOldFaceIndex;
   }

  /** return the array FaceChild */
  void GetFaceChild(const int *&TmpFC, const int *&TmpLen, int &MaxLen)
   {
    TmpFC = FaceChild;
    TmpLen = FaceChildLen;
    MaxLen = MaxN_CpF;
   }

  /** return the array FaceChildIndex */
  void GetFaceChildIndex(const int *&TmpFCI, const int *&TmpLen, int &MaxLen)
   {
    TmpFCI = FaceChildIndex;
    TmpLen = FaceChildLen;
    MaxLen = MaxN_CpF;
   }

  /** return the array FaceEdge */
  void GetFaceEdge(const int *&TmpFE, int &MaxLen)
   {
    TmpFE =  FaceEdge;
    MaxLen = MaxN_EpF;
   }

  /** return field NewVertsOnOldFace for face i */
  void GetNewVertsOnOldFace(const int *&TmpNV, const double *&TmpPos, int &MaxLen)
   {
    TmpNV = NewVertsOnOldFace;
    TmpPos = NewVertsOnOldFacePos;
    MaxLen = MaxN_nVpoF;
   }

  /** return the field ChildFace */
  void GetChildFace(const int *&TmpCF, int &MaxLen)
   {
    TmpCF = ChildFace;
    MaxLen = MaxN_FpC;
   }

  /** return the field OldFaceNewVertex */
  void GetOldFaceNewVertex(const int *&TmpoFnV, const int *&TmpLen, int &MaxLen)
   {
    TmpoFnV = OldFaceNewVertex;
    TmpLen = OldFaceNewVertexLen;
    MaxLen = MaxN_nVpoF;
   }

  /** return the field OldFaceNewVertex */
  void GetOldFaceNewVertex(const int *&TmpoFnV, const double *&TmpPos,
                           const int *&TmpLen, int &MaxLen1, int &MaxLen2)
   {
    TmpoFnV = OldFaceNewVertex;
    TmpPos = OldFaceNewVertexPos;
    TmpLen = OldFaceNewVertexLen;
    MaxLen1 = MaxN_nVpoF;
    MaxLen2 = MaxN_oVpoF;
   }

  /** return the field NewFaceOldFace */
  void GetNewFaceOldFace(const int *&TmpnFoF)
   {
    TmpnFoF = NewFaceOldFace;
   }

  /** return the array OldFaceNewLocFace */
  void GetOldFaceNewLocFace(const int *&TmpoFnlF)
   {
    TmpoFnlF = OldFaceNewLocFace;
   }

  /** return the array ChildTwistIndex */
  void GetChildTwistIndex(const int *&TmpCTI)
   {
    TmpCTI = ChildTwistIndex;
   }
      
  /** return the array FaceVertex **/
  void GetFaceVertex (const int *&TmpFV, int &TmpLen)
   {
	  TmpFV = FaceVertex;
	  TmpLen = MaxN_VpF;
   }

    #endif 

};

SParSH_NAMESPACE_END