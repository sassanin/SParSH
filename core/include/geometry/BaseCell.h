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
 
 
  public:
  
  // Constructors
  TBaseCell(TRefineDesc<dim> *refindesc);

  //methods 

  /**  @brief return the number of joints */
  int GetN_Facets()
  {  return RefinDesc->GetCellDesc()->GetN_Facets(); }

  virtual void SetVertGlobalIdx(int localidx, std::size_t globalidx)=0;

  virtual void SetRegionID(int id)=0;



};

SParSH_NAMESPACE_END