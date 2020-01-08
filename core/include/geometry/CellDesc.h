/** =======================================================================
* @class     TCellDesc
* @brief     Cell (element) descriptors
* @author    Sashikumaar Ganesan 
* @date      08.01.2020
* @History   
===========================================================================*/

#include <SParSH_Variables.h>

#pragma once

#define N_CellTypes  20

/** \brief based on https://cgns.github.io/CGNS_docs_current/sids/conv.html#unstructgrid 
 *  and for bubble FEs */
enum class CellType:sint {LINE_2, LINE3,
                          TRI_3, TRI_6, TRI_7,
                          QUAD_4, QUAD_8, QUAD_9, 
                          TETRA_4, TETRA_10, TETRA_14,
                          PYRA_5, PYRA_13, PYRA_14, 
                          PENTA_6, PENTA_15, PENTA_18,
                          HEXA_8, HEXA_20, HEXA_27 };
 
SParSH_NAMESPACE_BEGIN

template <sint dim=0> 
class TCellDesc {

  protected:
    /** \brief Type contains the enum ID of the cell type */
    CellType Type;

    /** \brief number of vertices in this cell */
    int N_Vertices;

    /** \brief number of joints. 1d:vertex, 2d:edge, 3d:face */
    int N_Joints;

    /** \brief Type contains the enum ID of the joint celltype of this cell */
    CellType JointType;

    #ifdef __3D__
      /**  \brief number of edges in a 3d cell */
      int N_Edges;
    #endif

  public:
  
  // Constructors

  //methods 

   /** \brief return the cell type */
    CellType GetCellType()
    { return Type; }

};

SParSH_NAMESPACE_END