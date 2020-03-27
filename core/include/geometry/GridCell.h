/** =======================================================================
*
* @class     TGridCell
* @brief     base class for Cell (element)
* @author    Sashikumaar Ganesan 
* @date      05.01.2020
* @History   
===========================================================================*/
#include <BaseCell.h>
#include <iostream>

#pragma once
SParSH_NAMESPACE_BEGIN

template <sint dim> 
class TGridCell : public TBaseCell<dim>
{
  protected:
  
  /** Global index of the local vertices  */
  vector <std::size_t> GlobalVertIndex;

  /** Region/Phase ID of the cell */
  int RegionID;

  private: 
//    double V[dim]; 
 
  public:
  
  // Constructors
  TGridCell(TRefineDesc<dim> *refindesc, int reflevel);

  //methods 
  virtual void SetVertGlobalIdx(int localidx, std::size_t globalidx)
  { GlobalVertIndex[localidx] = globalidx; }

  /** brief write the global vert indices of the cell */
  void WriteCell(std::ofstream &dat);

   /** set the region I of this cell */
  virtual void SetRegionID(int id)
  {  RegionID = id; }

};

SParSH_NAMESPACE_END