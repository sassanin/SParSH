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
#include <memory>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim=GEO_DIM> 
class TMesh {

 protected: 

  /** \brief Vertices contains the list of all vertices in this mesh. */
  static std::vector< std::shared_ptr< TVertex<GEO_DIM> > > Vertices; 
 
  /** \brief Facets contains the list of all boundaries of all cell in this mesh:
   *         face in 3d, edge in 2d, vertex in 1d   */
  // static vector<SParSH::TFacets<SParSH::GEO_DIM>> Facets; 

  /** \brief Cells contains the list of cells/elements in this mesh:
   *         tetra/pyra/Prism/hexa in 3d, tria/quad in 2d, line in 1d  */
  static vector<TCellDesc<GEO_DIM>> Cells; 

  public:
  
  /** \brief  Default constructor with coordinates of the vertex */
  TMesh();

  TMesh(int N_Vertices);

//   //methods 
  auto GetVertices()
        { return 0; }
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