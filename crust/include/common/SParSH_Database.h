/** =======================================================================
* @class     TSParSHDatabase
* @brief     base class for SParSh Database 
* @author    Sashikumaar Ganesan 
* @date      08.01.2020
* @History   
===========================================================================*/

#include <SParSH_Variables.h>
#include <CellDesc.h>
#include <RefineDesc.h>
#include <Domain.h>

using namespace std; 

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim=SParSH::GEO_DIM> 
struct TParamDB
{
  /** \brief variables for data output and input files  */   
  vector<string> OutFile{"SParsh1_Out"};  
  vector<string> MeshFile{"UnitSquareQuad.mesh"};
  vector<size_t> CellTypes{0};

  /** \brief parameters for grid generation     */
  vector<size_t> Uniform_Steps{1};
  double Drift_X{0.0}, Drift_Y{0.0}, Drift_Z{0.0};
  double Scale_X{1.0}, Scale_Y{1.0}, Scale_Z{1.0};

  string VTKFile{"SParsh_VTK"};
  string PSFile{"SParsh_PS"};
  string OutDir{"SParsh_Out"};
      
  /** \brief variables for controling output */
  bool Write_PS = false;
  bool Write_VTK = false;
  bool Measure_Errors = false;

  /** free parameters for users */
  vector<double> UserDoubleParameter{0.};
  vector<int> UserIntParameter{0};
  // vector<bool> UserBoolParameter{false};
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

template <sint dim=SParSH::GEO_DIM> 
class TSParSH_Database {

  public:

   /** \brief general parameters */
  static unique_ptr<TParamDB<dim> > ParamDB;

  /** database of shape descriptors */
  static vector<unique_ptr<TCellDesc<dim>>> CellDB;
  static vector<unique_ptr<TRefineDesc<dim>>> RefineDescDB;
  static  unique_ptr<TDomain<dim>> Domain; 



  //constructor

  /** default constructor */
  TSParSH_Database();
  
  /** \brief read the data for the database from the given readin file */
  TSParSH_Database(string ReadinFile);


  //methods
  /** \brief Initilize the coarse mesh */
  void InitDomain(string mesh);

  private:
  
  /** \brief read the data for the database from the given readin file */
  void InitDescriptors();

  /** \brief gererating an unitsquare mesh */
  void UnitSquareQuad();

  /** \brief gererating an unitsquare mesh */
  void UnitSquareTria();

  /** \brief gererating a mesh using the given Gmsh file */
   void GenerateGmsh(string MeshFile);
};

/** \brief initialize the static ParamDB */
template <sint dim> 
unique_ptr<SParSH::TParamDB<dim>> SParSH::TSParSH_Database<dim>::ParamDB(make_unique<SParSH::TParamDB<dim>>());

/** \brief initialize the static CellDB */
template <sint dim> 
vector<unique_ptr<SParSH::TCellDesc<dim>>> SParSH::TSParSH_Database<dim>::CellDB;

/** \brief initialize the static RefineDescDB */
template <sint dim> 
vector<unique_ptr<SParSH::TRefineDesc<dim>>> SParSH::TSParSH_Database<dim>::RefineDescDB;

/** \brief initialize the static Domain */
template <sint dim> 
unique_ptr<SParSH::TDomain<dim>> SParSH::TSParSH_Database<dim>::Domain;

SParSH_NAMESPACE_END