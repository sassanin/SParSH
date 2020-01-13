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

template <sint dim=SParSH::GEO_DIM> 
class TSParSH_Database {

  private: 
  
  /** \brief CellDB[] contains geometrical description of all CellTypes */
  static vector<SParSH::TCellDesc<dim>> CellDB[N_CellTypes]; 
 
  public:
   
  //constructor
  TSParSH_Database();

};

SParSH_NAMESPACE_END