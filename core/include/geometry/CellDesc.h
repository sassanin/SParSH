/** =======================================================================
* @class     TCellDesc
* @brief     Cell (element) descriptors, an abstract class
* @author    Sashikumaar Ganesan 
* @date      08.01.2020
* @History   
* ===========================================================================*/

#include <SParSH_Variables.h>
#include <Vertex.h>

#pragma once
SParSH_NAMESPACE_BEGIN

#define N_CellTypes  20

/** \brief based on https://cgns.github.io/CGNS_docs_current/sids/conv.html#unstructgrid 
 *  and for bubble FEs */
enum class CellType:sint {LINE_2, LINE_3,
                          TRI_3, TRI_6, TRI_7,
                          QUAD_4, QUAD_8, QUAD_9, 
                          TETRA_4, TETRA_10, TETRA_14,
                          PYRA_5, PYRA_13, PYRA_14, 
                          PRISM_6, PRISM_15, PRISM_18,
                          HEXA_8, HEXA_20, HEXA_27,
                          NOT_DEFINED };

 enum class VTKCellType:sint {LINE_2=3, TRI_3=5, QUAD_4=9, TETRA_4=10,
                              HEXA_8=12, NOT_DEFINED };

template <sint dim=GEO_DIM> 
class TCellDesc {

  protected:
    /** \brief Type contains the enum ID of the cell type */
    CellType Type;

    /** \brief VTK Type the cell */
    VTKCellType VTKType;

    /** \brief number of vertices in this cell */
    sint N_Vertices;

    /**  \brief number of edges in a cell */
    sint N_Edges;

    /** \brief number of Facets: 1d::vertex, 2d::edge, 3d::face */
    sint N_Facets;

    /** \brief Type contains the enum ID of the edge celltype of this cell */
    CellType EdgeType;

    /** \brief maximum number of edges per vertex */
    sint MaxN_EpV;
 
    /** \brief vertices that belong to one edge */
    const sint *EdgeVertex;

    /** \brief edges that meet at a vertex */
    const sint *VertexEdge;

// #ifdef __3D__
    /**  \brief number of faces in a 3d cell */
    sint N_Faces;

    /** \brief maximum number of vertices per face */
    sint MaxN_VpF;

    /** \brief maximum number of faces per vertex */
    sint MaxN_FpV;

    /** \brief maximum number of edges per face */
    sint MaxN_EpF;

    /** \brief maximum number of faces per edge */
    sint MaxN_FpE;

    /** \brief \brief which vertices are on one face */
    const sint *FaceVertex;
    
    /** number of  vertices on one face */
    const sint *FaceVertexLen;

    /** \brief which edges are on one face */
    const sint *FaceEdge;

    /** \brief number of edges on one face */
    const sint *FaceEdgeLen;

    /** \brief Type contains the enum ID of the face celltype of this cell */
    const CellType *FaceType;
   
    /** \brief which faces meet at a vertex */
    const sint *VertexFace;
    
    /** \brief which faces meet a one edge */
    const sint *EdgeFace;      
// #endif

  public:
  
  // Constructors
  TCellDesc();

    // Detructors
    virtual ~TCellDesc() 
    { }  

  //methods 

    /** \brief return the number of vertices */
    sint GetN_Vertices()
    { return N_Vertices; }
    /** \brief return the number of edges */
    sint GetN_Edges()
    { return N_Edges; }
    /** \brief return the number of joints */
    sint GetN_Facets()
    { return N_Facets; }

    /** brief return the EdgeVertex array */
    void GetEdgeVertex(const sint *&TmpEV)
    {
     TmpEV = EdgeVertex;
    }

    /** brief return the MaxN_EpV */
    sint GetMaxN_EpV()
    { return MaxN_EpV; }

    /** brief return the EdgeVertex array */
    void GetVertexEdge(const sint *&TmpVE)
    {
      TmpVE = VertexEdge;
    }

    // #ifdef __3D__
      /** brief return the number of faces */
      sint GetN_Faces()
      { return N_Faces; }

      /** brief return the FaceVertex array */
      void GetFaceVertex(const sint *&TmpFV, const sint *&TmpLen, sint &MaxLen)
      {
        TmpFV = FaceVertex;
        TmpLen = FaceVertexLen;
        MaxLen = MaxN_VpF;
      }

      /** brief return the FaceEdge array */
      void GetFaceEdge(const sint *&TmpFV, const sint *&TmpLen, sint &MaxLen)
      {
        TmpFV = FaceEdge;
        TmpLen = FaceEdgeLen;
        MaxLen = MaxN_EpF;
      }

      /** brief return the EdgeFace array */
      void GetEdgeFace(const sint *&TmpEF, sint &MaxLen)
      {
        TmpEF = EdgeFace;
        MaxLen = MaxN_FpE;
      }

      /** brief return the FaceType array */
      void GetFaceType(const CellType *&TmpFT)
      {
        TmpFT = FaceType;
      } 
      
    // #endif

    /** \brief return the cell type */
    CellType GetCellType()
    { return Type; }

    /** \brief return the cell type */
    int GetVTKCellType()
    { return (int)VTKType; }

    /** \brief  pure virtual function that is used in all derived classes to return diameter of a cell */
    virtual double GetDiameter(SParSH::TVertex<dim> **Verts)=0;

    // /** \brief  pure virtual function that is used in all derived classes to return shortest of a cell */
    virtual double GetShortestEdge(SParSH::TVertex<dim> **Verts)=0;

    /** \brief  pure virtual function that is used in all derived classes to return the length of the cell defined with the reference map */
    virtual double GetLengthWithReferenceMap(SParSH::TVertex<dim> **Verts)=0;

    /** \brief pure virtual function that is used in all derived classes to return the measure of the cell */
    virtual double GetMeasure(SParSH::TVertex<dim> **Verts)=0;

};

SParSH_NAMESPACE_END