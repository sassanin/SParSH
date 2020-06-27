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
  vector<shared_ptr<TVertex<dim>>> Vertices; 

  /** \brief list of IDs of physical Boundaries */
  vector<size_t>  BoundIDs;

  /** \brief   list of all Facets in this mesh:
   * first inner facet, then interface and finally boundary facets
   *         face in 3d, edge in 2d, vertex in 1d   */
  vector<shared_ptr<TFacet<dim>>> Facets; 

  /** \brief No. of inner facets */
  size_t N_InnerFacets = 0;

  /** \brief No. of interface facets */
  size_t N_InterfaceFacts = 0;

  /** \brief No. of interface facets */
  size_t N_BoundaryFacts = 0;

  /** \brief Cells contains the list of cells/elements in this mesh:
   *         tetra/pyra/Prism/hexa in 3d, tria/quad in 2d, line in 1d  */
  vector<shared_ptr<TGridCell<dim>>> Cells; 

  private:

  std::vector<reference_wrapper<TGridCell<dim>>> CellsRefs; 

   /** \brief return the locallly stored index for the given BDID */
  size_t GetBoundIndex(size_t BDID);

  public:

  /** \brief  Default constructor with coordinates of the vertex */
  TMesh();

  // methods 
  /** \brief  set of vertires of the mesh */
  void MoveVertices(vector<shared_ptr<TVertex<dim>>> && vertices)
  { 
    Vertices = std::move(vertices);
  }

  /** \brief  add a vertex to the mesh */
  void AddVertex(unique_ptr<TVertex<dim>> && Vert)
  { Vertices.push_back(move(Vert)); }

  /** \brief move the cells to this mesh */
  void MoveCellTree(vector<shared_ptr<TGridCell<dim>>>  && cells_all)
  { Cells = std::move(cells_all); }

  vector<shared_ptr<TGridCell<dim>>> GetCells()
  {return Cells;}

  vector<reference_wrapper<TGridCell<dim>>> GetCollection();

  //send the raw pointer of the vertex V[at]
  TVertex<dim>* GetVerticesAT(size_t pos)
  { return (Vertices.at(pos)).get(); }

  /** \brief adding list of IDs  of physical Boundaries  */
  void AddBoundIDs(vector<size_t> && BDIDs);

  /** \brief Set the N_InnerFacets */
  void SetN_InnerFacets(size_t n)
  {N_InnerFacets= n;}

  /** \brief Set the N_InterfaceFacts */
  void SetN_InterfaceFacets(size_t n)
  {N_InterfaceFacts= n;}

  /** \brief Set the N_BoundaryFacts */
  void SetN_BoundaryFacts(size_t n)
  {N_BoundaryFacts= n;}

  /** \brief  store all Facets of this mesh */
  void MoveFacets(vector<shared_ptr<TFacet<dim>>> && facets_all)
  {  Facets = std::move(facets_all);  }

  /** Return Vertices in the mesh */
  vector<shared_ptr<TVertex<dim>>> GetVertices()
  { return Vertices; }

  /** Send N_Vertices in the mesh */
  int GetN_Vertices()
  { return Vertices.size(); }

  /** Writing the vertices in the give dat file */
  void WriteMesh(std::ofstream &dat);

  // /** \brief  add a BDFacet to the mesh */
  // void MoveBDFacet(unique_ptr<TFacet<dim>> && facet, size_t BDID)
  // { 
  //  size_t idx = this->GetBoundIndex(BDID);
  //  Facets[idx].push_back(move(facet)); 
  // }

  // /** \brief  Return the array of facets for given BoundIDs. Default for internal facets is 0 */
  // const vector<shared_ptr<SParSH::TFacet<dim>> > GetFacets(size_t BDID)
  // { return Facets[this->GetBoundIndex(BDID)]; }
  


//   /** \brief  Return the type (bpoundary vertex or not) of the vertex */
//   bool IsBoundVert();

};

SParSH_NAMESPACE_END