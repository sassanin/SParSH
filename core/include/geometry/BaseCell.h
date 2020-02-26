/** =======================================================================
*
* @class     TBaseCell
* @brief     base class for Cell (element)
* @author    Sashikumaar Ganesan 
* @date      05.01.2020
* @History   
===========================================================================*/
#include <SParSH_Variables.h>
#include <CellDesc.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim > 
class TBaseCell {

  private: 
//    double V[dim]; 
 
  public:
  
  // Constructors
  TBaseCell(const TCellDesc<dim> *CellDesc);

  //methods 
 

};

SParSH_NAMESPACE_END