#include <SParSH_IO.h>
#include <SParSH_Database.h>

SParSH_NAMESPACE_BEGIN

TParamDB TSParSH_Database<GEO_DIM>::ParamDB;


template <sint dim> 
TSParSH_Database<dim>::TSParSH_Database() 
 {

  /** \brief Initilize the SparSH Database */
  SParSH::TSParSH_Database<dim> SParSH_DB;


//     cout << "Init :TSParSH_Database<T> " <<endl;
// ParamDB.UserDoubleParameter.push_back(10); 

//     // std::cout<<  " ParamDB : " << ParamDB.Uniform_Steps <<" :  "<<endl;

 }

// explicit instantiation
template class TSParSH_Database<2>;

SParSH_NAMESPACE_END
