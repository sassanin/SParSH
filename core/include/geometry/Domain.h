/** =======================================================================
* @class     TDomain
* @brief     base class for Domain 
* @author    Sashikumaar Ganesan 
* @date      27.03.2020
* @History   
===========================================================================*/

#include <SParSH_Variables.h>
#include <Mesh.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim=SParSH::GEO_DIM> 
class TDomain {

  private: 
  
  /** \brief Hierarchy of meshes */
  vector<unique_ptr<TMesh<dim>>> Meshes;
 
  public:
  
  /** \brief  Default constructor with coordinates of the vertex */
  TDomain(unique_ptr<TMesh<dim>> && coarsemesh);

  //methods 

  /** \brief  Assign/Change the coordinates of the vertex */
  void WriteVTKMesh();

};

SParSH_NAMESPACE_END