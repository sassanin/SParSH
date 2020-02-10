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

  public:
  
  // Constructors
  TRefineDesc();
    
  //methods 
 
};

SParSH_NAMESPACE_END