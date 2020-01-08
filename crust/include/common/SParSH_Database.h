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

template <sint dim=0> 
class TSParSHDatabase {

  private: 
  
  /** \brief CellDB[] contains geometrical description of all CellTypes */
  static vector<SParSH::TCellDesc<dim>> CellDB[N_CellTypes]; 
 
  public:
   
  //constructor
  TSParSHDatabase();

};

SParSH_NAMESPACE_END