/** =======================================================================
* @class     TInnerFacet
* @brief     base class for facet 
* @author    Sashikumaar Ganesan 
* @date      25.01.2020
* @History   
===========================================================================*/

// #include <SParSH_Variables.h>
#include <Facet.h>
// #include <Vertex.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim=SParSH::GEO_DIM> 
class TInnerFacet : public TFacet<dim>  {

 public:
  
 // Constructors

 /** \brief  Default constructor with coordinates of the vertex */
 TInnerFacet(FacetType type,  std::size_t id, std::size_t N_Vert, vector<size_t>::iterator itr);

 /** constructor with one initial neighbour */
 TInnerFacet(SParSH::TBaseCell<dim> *owncell);

 /** constructor with two initial neighbours */
 TInnerFacet(SParSH::TBaseCell<dim> *owncell, SParSH::TBaseCell<dim> *neibcell);

 //methods 



};

SParSH_NAMESPACE_END