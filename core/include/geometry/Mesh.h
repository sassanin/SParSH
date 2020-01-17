/** =======================================================================
* @class     TMesh
* @brief     base class for Mesh 
* @author    Sashikumaar Ganesan 
* @date      17.01.2020
* @History   
* ===========================================================================*/

#include <SParSH_Variables.h>
#include <Vertex.h>
#include <Facet.h>
#include <Cell.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim=SParSH::GEO_DIM> 
class TMesh {

 protected: 

  /** \brief Vertices contains the list of all vertices in this mesh. */
  static vector<SParSH::TVertex<SParSH::GEO_DIM>> Vertices; 
 
  /** \brief Facets contains the list of all boundaries of all cell in this mesh:
   *         face in 3d, edge in 2d, vertex in 1d   */
  static vector<SParSH::TFacets<SParSH::GEO_DIM>> Facets; 

  /** \brief Cells contains the list of cells/elements in this mesh:
   *         tetra/pyra/Prism/hexa in 3d, tria/quad in 2d, line in 1d  */
  static vector<SParSH::TCellDesc<SParSH::GEO_DIM>> Cells; 

  public:
  
//   /** \brief  Default constructor with coordinates of the vertex */
//   TVertex(double *X);

//   //methods 

//   /** \brief  Assign/Change the coordinates of the vertex */
//   void SetCoords(double *X);

//   /** \brief  Copy and return the coordinates of the vertex */
//   void GetCoords(double *X);

//   /** \brief  Return the address of the vertex */
//   double* GetCoordsPtr()
//   { return V; }
  
//   /** \brief  Return the type (bpoundary vertex or not) of the vertex */
//   bool IsBoundVert();

};

SParSH_NAMESPACE_END