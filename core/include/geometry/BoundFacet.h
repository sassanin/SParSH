/** =======================================================================
* @class     TBoundFacet
* @brief     base class for interface facet 
* @author    Sashikumaar Ganesan 
* @date      25.01.2020
* @History   
===========================================================================*/

#include <Facet.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim=SParSH::GEO_DIM> 
class TBoundFacet : public TFacet<dim>  {

 protected:

 BoundCond BoundCondType;

 public:
  
 // Constructors

 /** \brief  Default constructor with index of the verticies */
 TBoundFacet(SParSH::FacetType type, std::size_t id, std::size_t N_Vert, vector<size_t>::iterator itr);

 /** constructor with one initial neighbour */
 TBoundFacet(SParSH::TBaseCell<dim> *owncell);

 //methods 


};

SParSH_NAMESPACE_END