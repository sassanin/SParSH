#include <SParSH_IO.h>
#include <InterFacet.h>


SParSH_NAMESPACE_BEGIN

template <sint dim> 
TInterFacet<dim>::TInterFacet(FacetType type,  std::size_t id, std::size_t N_Vert, vector<size_t>::iterator itr) :
                  TFacet<dim>(type, id, N_Vert, itr)
 {

  try { 
       if(type!=FacetType::InterfacePoint ||  type!=FacetType::InterfaceEdge ||  type!=FacetType::InterFace )
          throw std::runtime_error("Facte Type is not matching"); 
      }
  catch (std::exception &ex)
      { sarshpout(ex); exit(-1); }

 }

/** constructor with one initial neighbour */
template <sint dim> 
TInterFacet<dim>::TInterFacet(SParSH::TBaseCell<dim> *owncell) : 
                  TFacet<dim>()
{
 // make OwnCell as dependent by using this->
 this->OwnCell = owncell;
}

 /** constructor with two initial neighbours */
 template <sint dim> 
TInterFacet<dim>::TInterFacet(SParSH::TBaseCell<dim> *owncell, SParSH::TBaseCell<dim> *neibcell):
                  TFacet<dim>()
{
 this->OwnCell = owncell;
 this->NeibCell = neibcell;
}

// explicit instantiation
template class TInterFacet<GEO_DIM>;

SParSH_NAMESPACE_END
