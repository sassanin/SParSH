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
  std::vector<std::string> OutFile{"SParsh1_Out", "SParsh2_Out"};  
  std::vector<std::string> MeshFile{"UnitSquare.mesh", "UnitSquare.mesh"};
  std::vector<std::string> CellTypes{0};

  char *VTKFile{"SParsh_VTK"};
  char *PSFile{"SParsh_PS"};
  char *OutDir{"SParsh_Out"};
      
  /** \brief variables for controling output */
  bool Write_PS{true};
  bool Write_VTK{true};
  bool Measure_Errors{false};


  /** \brief parameters for grid generation                             */
  int Uniform_Steps{1};
  double Drift_X{0.0}, Drift_Y{0.0}, Drift_Z{0.0};

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

  /** \brief CellDB[] contains geometrical description of all CellTypes */
  static vector<SParSH::TCellDesc<SParSH::GEO_DIM>> CellDB[N_CellTypes]; 

  // //constructor
  
  TSParSH_Database();
};

SParSH_NAMESPACE_END