/** =======================================================================
* @class     TCellDesc
* @brief     Cell (element) descriptors
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
 
template <sint dim=GEO_DIM> 
class TCellDesc {

  protected:
    /** \brief Type contains the enum ID of the cell type */
    CellType Type;

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

#ifdef __3D__
    /**  \brief number of faces in a 3d cell */
    sint N_Faces;

    /** \brief Type contains the enum ID of the face celltype of this cell */
    CellType FaceType;

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

    /** \brief which shapes have the faces got */
    const Shapes *FaceType;

    /** \brief which faces meet at a vertex */
    const sint *VertexFace;
    
    /** \brief which faces meet a one edge */
    const sint *EdgeFace;      
#endif


  public:
  
  // Constructors
  TCellDesc();
    
  //methods 

   /** \brief return the cell type */
    CellType GetCellType()
    { return Type; }

    /** \brief return diameter of a cell */
    // virtual double GetDiameter(SParSH::TVertex<dim> **Verts) = 0;

    // /** \brief return shortest of a cell */
    // virtual double GetShortestEdge(SParSH::TVertex<dim> **Verts) = 0;

    // /** \brief return the length of the cell defined with the reference map */
    // virtual double GetLengthWithReferenceMap(SParSH::TVertex<dim> **Verts) = 0;

    // /** \brief return measure of a cell */
    // virtual double GetMeasure(SParSH::TVertex<dim> **Verts) = 0;

};

SParSH_NAMESPACE_END