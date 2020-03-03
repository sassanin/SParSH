#include <SParSH_IO.h>
#include <InnerFacet.h>
// #include <Vertex.h>
// #include <iostream> 
// #include <vector> 

SParSH_NAMESPACE_BEGIN

template <sint dim> 
TInnerFacet<dim>::TInnerFacet(FacetType type,  std::size_t id, std::size_t N_Vert,  vector<size_t>::iterator itr) :
                  TFacet<dim>(type, id, N_Vert, itr)
 {

  try { 
       if(type!=FacetType::InnerPoint ||  type!=FacetType::InnerEdge ||  type!=FacetType::InnerFace )
          throw std::runtime_error("Facte Type is not matching"); 
      }
  catch (std::exception &ex)
      { sarshpout(ex); exit(-1); }

 }

/** constructor with one initial neighbour */
template <sint dim> 
TInnerFacet<dim>::TInnerFacet(SParSH::TBaseCell<dim> *owncell) : 
                  TFacet<dim>()
{
 // make OwnCell as dependent by using this->
 this->OwnCell = owncell;
}

 /** constructor with two initial neighbours */
 template <sint dim> 
TInnerFacet<dim>::TInnerFacet(SParSH::TBaseCell<dim> *owncell, SParSH::TBaseCell<dim> *neibcell):
                  TFacet<dim>()
{
 this->OwnCell = owncell;
 this->NeibCell = neibcell;
 this->Type = FacetType::InnerEdge;
}

// explicit instantiation
template class TInnerFacet<GEO_DIM>;

SParSH_NAMESPACE_END
