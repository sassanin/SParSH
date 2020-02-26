/** =======================================================================
*
* @class     TBaseCell
* @brief     base class for Cell (element)
* @author    Sashikumaar Ganesan 
* @date      05.01.2020
* @History   
===========================================================================*/
#include <SParSH_Variables.h>
#include <RefineDesc.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim > 
class TBaseCell {

  protected:
   
  /**  @brief raw pointer of Cell (Shape) descriptor */
  TRefineDesc<dim> *RefinDesc;


  private: 
//    double V[dim]; 
 
  public:
  
  // Constructors
  TBaseCell(TRefineDesc<dim> *refindesc);

  //methods 
  virtual void SetVertGlobalIdx(int localidx, std::size_t globalidx)=0;

};

SParSH_NAMESPACE_END