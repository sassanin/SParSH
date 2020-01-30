/** =======================================================================
* @class     TFacet
* @brief     base class for facet 
* @author    Sashikumaar Ganesan 
* @date      17.01.2020
* @History   
===========================================================================*/

#include <SParSH_Variables.h>
#include <Cell.h>
#include <Vertex.h>

#pragma once
SParSH_NAMESPACE_BEGIN

/** \brief factes in 1d, 2d, 3d and in parallel */
enum class FacetType:std::size_t {InnerPoint, InterfacePoint, BoundPoint, PeriodicBoundPoint,
                           InnerEdge, InterfaceEdge, IsoInterfaceEdge, BoundEdge, IsoBoundEdge, PeriodicBoundEdge,
                           InnerFace, InterFace, IsoInterFace, BoundFace, IsoBoundFace, PeriodicBoundFace,
                           SubDomainEdge, SubDomainHaloEdge, SubDomaineFace, SubDomainHaloFace,
                           NotAssigned};

enum class BoundCond:std::size_t {Dirichlet, Dirichlet_Weak, Neumann, Robin, FreeSurf, SlipWithFriction, Interface,
                           SubDomainInterface, SubDomainHalloBound, NotAssigned};


template <sint dim=SParSH::GEO_DIM> 
class TFacet {

 protected: 
  
 /** \brief Type of the facet */
 FacetType Type;

 /** \brief ID (inner is 0) of the facet */
 std::size_t ID;

 /** \brief V[] contains the indices of the vertices */
 vector<std::size_t> V; 

 /** \brief Inner Vertices on the facet */
 vector<unique_ptr< TVertex<dim>>> InnerVertices;

 /** \brief raw pointers for the own and neib cells */
 SParSH::TCellDesc<dim> *OwnCell, *NeibCell;

 bool BD_Facet=false;

 public:
  
 /** \brief  Default constructor with Null */
 TFacet();

 /** \brief  Default constructor with coordinates of the vertex */
 TFacet(FacetType type,  std::size_t id, std::size_t N_Vert,  std::size_t *Vindex);

 //methods 



};

SParSH_NAMESPACE_END