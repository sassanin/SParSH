#include <SParSH_IO.h>
#include <SParSH_Database.h>
#include <iostream>
#include <fstream>

SParSH_NAMESPACE_BEGIN

TParamDB TSParSH_Database<GEO_DIM>::ParamDB;

/** \brief default constructor */
template <sint dim> 
TSParSH_Database<dim>::TSParSH_Database() 
 {
  /** \brief Initilize the SparSH Database */
  // SParSH::TSParSH_Database<dim> SParSH_DB;

    std::cout<<  " Para  :  :  "<<endl;
 }

/** \brief constructor with readin.data file */
template <sint dim> 
TSParSH_Database<dim>::TSParSH_Database(std::string ReadinFile) 
 {
  /** \brief Initilize the SparSH Database */
  // SParSH::TSParSH_Database<dim> SParSH_DB;

  std::cout<<  " ParamDB : " << ReadinFile <<" :  "<<endl;

  char data[100];
  std::ifstream myfile(ReadinFile);

  cout << "Rading  the file" << endl;
  // cin.getline(data, 100);

    // cout << "Init :TSParSH_Database<T> " <<endl;
// ParamDB.UserDoubleParameter.push_back(10); 

  
 }

// explicit instantiation
template class TSParSH_Database<GEO_DIM>;

SParSH_NAMESPACE_END
