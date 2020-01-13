#include <SParSH_IO.h>
#include <SParSH_Init.h>
#include <SParSH_Database.h>

SParSH_NAMESPACE_BEGIN

template <int dim> 
TSParSH_Init<dim>::TSParSH_Init() 
 {
    /** \brief Initilize the SparSH Database */
   // SParSH::TSParSH_Database<dim> SParSH_DB();
    cout << "Init :TSParSH_Database<dim> " <<endl;
 }

// template <sint dim> 
// bool TSParSH_Init<dim>::Test() 
//  {
//   return true;
//  }

// explicit instantiation done in the main program
template class TSParSH_Init<GEO_DIM>;

SParSH_NAMESPACE_END
