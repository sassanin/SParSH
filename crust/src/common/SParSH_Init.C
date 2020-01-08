#include <SParSH_IO.h>
#include <SParSH_Init.h>
#include <SParSH_Database.h>

SParSH_NAMESPACE_BEGIN

template <sint dim> 
TSParSH_Init<dim>::TSParSH_Init() 
 {
    /** \brief Initilize the SparSH Database */
    SParSH::TSParSH_Database<dim> SParSH_DB();
    cout << "Init :TSParSH_Database<dim> " <<endl;
 }

// explicit instantiation done in the main program
// template class TSParSH_Init<>;

SParSH_NAMESPACE_END
