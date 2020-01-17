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

  std::cout<<  " ParamDB : " << ReadinFile <<" :  "<<endl;

  char line[100];
  std::ifstream dat(ReadinFile);

  try
    {
    if (!dat) throw std::runtime_error("Could not open file"); 
    }
  
  // {
  //   cerr << "cannot open '" << ReadinFile << "' for input" << endl;
  //   exit(-1);
  // }
catch (std::exception &ex) {
        std::cout << "Ouch! That hurts, because: "
            << ex.what() << "!\n";
}
// #include <stdexcept>
// #include <limits>
// #include <iostream>

// using namespace std;

// void MyFunc(int c)
// {
//     if (c > numeric_limits< char> ::max())
//         throw invalid_argument("MyFunc argument too large.");
//     //...
// }

// int main()
// {
//     try
//     {
//         MyFunc(256); //cause an exception to throw
//     }

//     catch (invalid_argument& e)
//     {
//         cerr << e.what() << endl;
//         return -1;
//     }
//     //...
//     return 0;
// }


  cout << "Rading  the file" << endl;
  // cin.getline(data, 100);

    // cout << "Init :TSParSH_Database<T> " <<endl;
// ParamDB.UserDoubleParameter.push_back(10); 

  
 }

// explicit instantiation
template class TSParSH_Database<GEO_DIM>;

SParSH_NAMESPACE_END
