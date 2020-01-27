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

using namespace std;

template <sint dim=GEO_DIM> 
class TMesh {

 protected: 

  /** \brief Vertices contains the list of all vertices in this mesh. */
  vector< unique_ptr< TVertex<dim> > > Vertices; 

  /** \brief list of IDs  of the  (physical) Boundary  */
  static vector<size_t>  BoundIDs;

  /** \brief BD ID of list of Facets  */

  /** \brief Facets contains the list of all boundaries of all cell in this mesh:
   *         face in 3d, edge in 2d, vertex in 1d   */
  // static vector<SParSH::TFacets<SParSH::dim>> BDFacets; 

  /** \brief Cells contains the list of cells/elements in this mesh:
   *         tetra/pyra/Prism/hexa in 3d, tria/quad in 2d, line in 1d  */
  static vector<TCellDesc<dim>> Cells; 

  public:
  
  /** \brief  Default constructor with coordinates of the vertex */
  TMesh();

  TMesh(size_t N_Vertices);

  // methods 

  //send the raw pointer of the vertex V[at]
  TVertex<dim>* GetVerticesAT(size_t pos)
   { return Vertices.at(pos).get(); }

  /** \brief  add a vertex to the mesh */
  void AddVertex(unique_ptr<TVertex<dim>> && Vert)
  { Vertices.push_back(move(Vert)); }

//   /** \brief  Copy and return the coordinates of the vertex */
//   void GetCoords(double *X);

//   /** \brief  Return the address of the vertex */
//   double* GetCoordsPtr()
//   { return V; }
  
//   /** \brief  Return the type (bpoundary vertex or not) of the vertex */
//   bool IsBoundVert();

};

SParSH_NAMESPACE_END