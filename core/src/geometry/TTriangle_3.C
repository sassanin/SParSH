
/** =======================================================================
* @class     TTriangle_3
* @brief     TRI_3 (element) descriptors source 
* @author    Sashikumaar Ganesan 
* @date      06.02.2020
* @History   
===========================================================================*/

#include <Triangle_3.h>

SParSH_NAMESPACE_BEGIN

using namespace std; 

constexpr static const int DatFacetVertex[3][2] = { {0, 1},  {1, 2},  {2, 0}};
constexpr static const int DatVertexFacet[3][2] = { {2, 0},  {0, 1},  {1, 2}};
 
// Constructor
template <sint dim> 
TTriangle_3<dim>::TTriangle_3()
{
  this->MaxN_FacetPerVert = 3;
  this->FacetVertex = (const int *) DatFacetVertex;
  this->VertexFacet = (const int *) DatVertexFacet;
  this->Type = CellType::TRI_3;
  this->N_Vertices = 3;   
  this->N_Facets = 3;   
}

// Methods
template <sint dim> 
double TTriangle_3<dim>::GetMeasure(SParSH::TVertex<dim> **Verts)
{
  double x1,x2,y1,y2;

  // x1 = Verts[0]->GetX();
  // y1 = Verts[0]->GetY();
  // x2 = Verts[1]->GetX();
  // y2 = Verts[1]->GetY();

  // return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


// explicit instantiation
template class TTriangle_3<GEO_DIM>;

SParSH_NAMESPACE_END
