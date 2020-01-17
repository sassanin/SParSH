/** =======================================================================
* @class     TSParSHDatabase
* @brief     base class for SParSh Database 
* @author    Sashikumaar Ganesan 
* @date      08.01.2020
* @History   
===========================================================================*/

#include <SParSH_Variables.h>
#include <CellDesc.h>

#pragma once
SParSH_NAMESPACE_BEGIN

struct TParamDB
{
  /** \brief variables for data output and input files  */   
  std::vector<std::string> OutFile{"SParsh1_Out"};  
  std::vector<std::string> MeshFile{"UnitSquareQuad.mesh"};
  std::vector<std::sint> CellTypes{0};

  /** \brief parameters for grid generation     */
  std::vector<sint> Uniform_Steps{1};
  double Drift_X{0.0}, Drift_Y{0.0}, Drift_Z{0.0};
  double Scale_X{1.0}, Scale_Y{1.0}, Scale_Z{1.0};

  std::string VTKFile{"SParsh_VTK"};
  std::string PSFile{"SParsh_PS"};
  std::string OutDir{"SParsh_Out"};
      
  /** \brief variables for controling output */
  bool Write_PS = false;
  bool Write_VTK = false;
  bool Measure_Errors = false;

  /** free parameters for users */
  std::vector<double> UserDoubleParameter{0., 0., 0., 0., 0.};
  std::vector<int> UserIntParameter{0, 0, 0, 0, 0};
  std::vector<bool> UserBoolParameter{0, 0, 0, 0, 0};
};

// using TParamDB = ParaDB<int>;
 
// /** \brief database for scalar PDEs  */  
// template <class T = sint> 
// struct CDParaDB
// {
//   /** parameters for setting finite element spaces                  */
//   T Ansatz_Order{1};
//   T Test_Order{1};

//   /** \brief Dimensionless numbers                                  */
//   double PE_NR{1};
// };

// template struct CDParaDB<sint>;
template <sint dim> 
class TSParSH_Database {

  public:

   /** \brief general parameters */
  static TParamDB ParamDB;



  // //constructor
  TSParSH_Database();
  
  TSParSH_Database(std::string ReadinFile);
};

SParSH_NAMESPACE_END