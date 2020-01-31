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

using namespace std;

#pragma once
SParSH_NAMESPACE_BEGIN

/** \brief factes in 1d, 2d, 3d and in parallel */
enum class FacetType:size_t {InnerPoint, InterfacePoint, BoundPoint, PeriodicBoundPoint,
                           InnerEdge, InterfaceEdge, IsoInterfaceEdge, BoundEdge, IsoBoundEdge, PeriodicBoundEdge,
                           InnerFace, InterFace, IsoInterFace, BoundFace, IsoBoundFace, PeriodicBoundFace,
                           SubDomainEdge, SubDomainHaloEdge, SubDomaineFace, SubDomainHaloFace,
                           NotAssigned};

enum class BoundCond:size_t {Dirichlet, Dirichlet_Weak, Neumann, Robin, FreeSurf, SlipWithFriction, Interface,
                           SubDomainInterface, SubDomainHalloBound, NotAssigned};


template <sint dim=SParSH::GEO_DIM> 
class TFacet {

 protected: 
  
 /** \brief Type of the facet */
 FacetType Type;

 /** \brief ID (inner is 0) of the facet */
 size_t ID;

 /** \brief raw pointer of vertices in this facet */
 vector<TVertex<dim> *> Vertices; 

 /** \brief raw pointers for the own and neib cells */
 SParSH::TCellDesc<dim> *OwnCell, *NeibCell;

 bool BD_Facet=false;

 public:
  
 /** \brief  Default constructor with Null */
 TFacet();

 /** \brief  Default constructor with coordinates of the vertex */
 TFacet(FacetType type, size_t id, size_t N_Vert, TVertex<dim> **Vert);

 //methods 



};

SParSH_NAMESPACE_END