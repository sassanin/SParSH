/** =======================================================================
*
* @class     TGridCell
* @brief     base class for Cell (element)
* @author    Sashikumaar Ganesan 
* @date      05.01.2020
* @History   
===========================================================================*/
#include <BaseCell.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim> 
class TGridCell : public TBaseCell<dim>
{
  private: 
//    double V[dim]; 
 
  public:
  
  // Constructors
  TGridCell();

  //methods 

};

SParSH_NAMESPACE_END