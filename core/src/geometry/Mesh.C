#include <SParSH_IO.h>
#include <Mesh.h>
#include <Vertex.h>
#include <iostream> 
#include <vector> 

SParSH_NAMESPACE_BEGIN

template <sint dim> 
TMesh<dim>::TMesh(size_t N_Vertices) 
 {
  Vertices.reserve(N_Vertices);
 }


template <sint dim> 
void TMesh<dim>::AddBoundIDs(vector<std::size_t> && BDIDs)
{

 BoundIDs = std::move(BDIDs);

 /** Arracy contains the internal facets and boundary factes */ 
 Facets.reserve(BoundIDs.size()+1);

 for(std::size_t i_edge=0; i_edge<BoundIDs.size(); ++i_edge)
       cout << "BDIDs[i] :" << BoundIDs[i_edge] << endl;

}// AddVertex

template <sint dim> 
vector<shared_ptr<SParSH::TFacet<dim>> > TMesh<dim>::GetFacets(size_t BoundIDs)
{

   return Facets[0];

    cout << "No. Facet Types: " << Facets.size() <<endl;
    for(std::size_t i_facet=0; i_facet<Facets.size(); ++i_facet)
      cout <<"No. Facets in Type : " <<  i_facet << "is " << Facets[i_facet].size() <<endl;

}// GetFacets(size_t BoundIDs)


// explicit instantiation
template class TMesh<GEO_DIM>;

SParSH_NAMESPACE_END
