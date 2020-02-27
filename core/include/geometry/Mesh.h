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
#include <GridCell.h>
#include <memory>
#include <iostream>

#pragma once
SParSH_NAMESPACE_BEGIN

using namespace std;

template <sint dim=GEO_DIM> 
class TMesh {

 protected: 

  /** \brief Vertices contains the list of all vertices in this mesh. */
  vector< unique_ptr< TVertex<dim> > > Vertices; 

  /** \brief list of IDs of physical Boundaries */
  vector<size_t>  BoundIDs;

  /** \brief Facets contains the list of all boundaries of all cell in this mesh:
   *         face in 3d, edge in 2d, vertex in 1d   */
  vector<vector<shared_ptr<SParSH::TFacet<dim>> > > Facets; 

  /** \brief Cells contains the list of cells/elements in this mesh:
   *         tetra/pyra/Prism/hexa in 3d, tria/quad in 2d, line in 1d  */
  vector<unique_ptr<TBaseCell<dim>>> Cells; 



  private:

  std::vector<reference_wrapper<TBaseCell<dim>>> CellsRefs; 

   /** \brief return the locallly stored index for the given BDID */
  size_t GetBoundIndex(size_t BDID);

  public:

  /** \brief  Default constructor with coordinates of the vertex */
  TMesh();

  // methods 
  /** \brief  set a set of vertires to the mesh */
  void SetVertices(vector<unique_ptr<TVertex<dim>>> && Verticies)
  { Vertices = std::move(Verticies); }

  /** \brief  add a vertex to the mesh */
  void AddVertex(unique_ptr<TVertex<dim>> && Vert)
  { Vertices.push_back(move(Vert)); }

  void AddCellTree(vector<unique_ptr<TBaseCell<dim>>> && cells)
  { Cells = std::move(cells); }

  vector<reference_wrapper<TBaseCell<dim>>> GetCollection();

  //send the raw pointer of the vertex V[at]
  TVertex<dim>* GetVerticesAT(size_t pos)
  { return (Vertices.at(pos)).get(); }

  /** \brief adding list of IDs  of physical Boundaries  */
  void AddBoundIDs(vector<size_t> && BDIDs);

  /** \brief  add a BDFacet to the mesh */
  void MoveBDFacet(unique_ptr<TFacet<dim>> && facet, size_t BDID)
  { 
   size_t idx = this->GetBoundIndex(BDID);
   Facets[idx].push_back(move(facet)); 
  }

  /** \brief  Return the arry of facets for given BoundIDs. Default for internal facets is 0 */
  const vector<shared_ptr<SParSH::TFacet<dim>> > GetFacets(size_t BDID)
  { return Facets[this->GetBoundIndex(BDID)]; }
  


//   /** \brief  Return the type (bpoundary vertex or not) of the vertex */
//   bool IsBoundVert();

};

SParSH_NAMESPACE_END