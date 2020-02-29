/** =======================================================================
* @class     TInterFacet
* @brief     base class for interface facet 
* @author    Sashikumaar Ganesan 
* @date      25.01.2020
* @History   
===========================================================================*/

#include <Facet.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim=SParSH::GEO_DIM> 
class TInterFacet : public TFacet<dim>  {

 public:
  
 // Constructors

 /** \brief  Default constructor with coordinates of the vertex */
 TInterFacet(FacetType type,  std::size_t id, std::size_t N_Vert, TVertex<dim> **Vert);

 /** constructor with one initial neighbour */
 TInterFacet(SParSH::TBaseCell<dim> *owncell);

 /** constructor with two initial neighbours */
 TInterFacet(SParSH::TBaseCell<dim> *owncell, SParSH::TBaseCell<dim> *neibcell);

 //methods 



};

SParSH_NAMESPACE_END