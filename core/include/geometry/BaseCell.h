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
#include <memory>

/** forward decleration */


#pragma once
SParSH_NAMESPACE_BEGIN
template <sint dim> 
class TFacet;

template <sint dim > 
class TBaseCell {

  protected:
   
  /**  @brief raw pointer of Cell (Shape) descriptor */
  TRefineDesc<dim> *RefinDesc;

  /** No. of facets in the cell */
  int N_Facets;

  /**  @brief array of all joints */
  vector<shared_ptr<TFacet<dim>>> Facets;
 
  /** Phase ID of the cell , default 0 */  
  int PhaseID;

  private: 
 
 
  public:
  
  // Constructors
  TBaseCell(TRefineDesc<dim> *refindesc);

  //methods 

  /**\brief set Facet to this cell   */
  void SetFacet(int i, shared_ptr<TFacet<dim>> facet)
  { Facets.at(i) = facet; }

  /**\brief set PhaseID to this cell   */
  void SetPhaseID(int val)
  {PhaseID = val;}

  /** \brief set PhaseID to this cell   */
  int GetPhaseID() const
  {return PhaseID;}   

  /** \brief return the number of joints */
  int GetN_Facets()
  {  return N_Facets; }

  // /** \brief  retun the facet for the given index */
  // TFacet<dim> *GetFacet(int idx)
  // { 
  //   TFacet<dim> *ret_ptr = nullptr;
  //   // output(Facets.size());
  //   if(Facets.size()<idx) {ret_ptr = nullptr; }
  //   else {
  //      output(idx);
  //     // ret_ptr = (Facets.at(idx)).get(); 
  //     }

  //   return ret_ptr;
  // }

  virtual void SetVertGlobalIdx(int localidx, std::size_t globalidx)=0;

  virtual void SetRegionID(int id)=0;



};

SParSH_NAMESPACE_END