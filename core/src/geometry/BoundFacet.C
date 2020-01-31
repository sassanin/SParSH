#include <SParSH_IO.h>
#include <BoundFacet.h>


SParSH_NAMESPACE_BEGIN

template <sint dim> 
TBoundFacet<dim>::TBoundFacet(FacetType type,  std::size_t id, std::size_t N_Vert, TVertex<dim> **Vert) :
                  TFacet<dim>(type, id, N_Vert, Vert)
 {

  bool IsBDFacet = false;

  //cout<< "TBoundFacet Type: " <<  static_cast<int> (type) <<endl;

  if( type==FacetType::BoundPoint ||  type==FacetType::BoundEdge || type==FacetType::BoundFace  )
   {    IsBDFacet = true;   }
 

  try { 
       if( !( type==FacetType::BoundPoint ||  type==FacetType::BoundEdge || type==FacetType::BoundFace  ) )
        {
          throw std::runtime_error("Facte Type is not matching" ); 
        }
      }
  catch (std::exception &ex)
      { sarshpout(ex); exit(-1); }


  BoundCondType = BoundCond::NotAssigned;
 }

/** constructor with own cell */
template <sint dim> 
TBoundFacet<dim>::TBoundFacet(SParSH::TCellDesc<dim> *owncell) : 
                  TFacet<dim>()
{
 // make OwnCell as dependent by using this->
 this->OwnCell = owncell;
 BoundCondType = BoundCond::NotAssigned;
}


// explicit instantiation
template class TBoundFacet<GEO_DIM>;

SParSH_NAMESPACE_END
