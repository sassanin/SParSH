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
  protected:
   vector <std::size_t> GlobalVertIndex;


  private: 
//    double V[dim]; 
 
  public:
  
  // Constructors
  TGridCell(TRefineDesc<dim> *refindesc, int reflevel);

  //methods 
  virtual void SetVertGlobalIdx(int localidx, std::size_t globalidx)
  {GlobalVertIndex[localidx] = globalidx; }

};

SParSH_NAMESPACE_END