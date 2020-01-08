/** =======================================================================
* @class     TCellDesc
* @brief     Cell (element) descriptors
* @author    Sashikumaar Ganesan 
* @date      08.01.2020
* @History   
===========================================================================*/

#include <SParSH_Variables.h>

#pragma once

#define N_CellTypes  37

/** based on https://cgns.github.io/CGNS_docs_current/sids/conv.html#unstructgrid */
enum class CellType:sint {LINE_2, LINE3, LINE_4, LINE_5,
                       TRI_3, TRI_6, TRI_9, TRI_12,
                       QUAD_4, QUAD_8, QUAD_9, QUAD_12, QUAD_16, QUAD_P4_16, 
                       TETRA_4, TETRA_10, TETRA_16, TETRA_20, TETRA_22,
                       PYRA_5, PYRA_13, PYRA_14, PYRA_21, PYRA_29, PYRA_30, PYRA_P4_29, 
                       PENTA_6, PENTA_15, PENTA_18, PENTA_24, PENTA_38, PENTA_40,  PENTA_33,
                       HEXA_8, HEXA_20, HEXA_27, HEXA_32 };
 

SParSH_NAMESPACE_BEGIN

template <CellType celltype > 
class TCellDesc {

  protected:
    /** \brief Type contains the enum ID of the cell type */
    CellType Type = celltype;

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