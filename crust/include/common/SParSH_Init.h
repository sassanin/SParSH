/** =======================================================================
* @class     TSParSH_Init
* @brief     base class for Init SParSh Package 
* @author    Sashikumaar Ganesan 
* @date      08.01.2020
* @History   
===========================================================================*/

#include <SParSH_Variables.h>

#pragma once
SParSH_NAMESPACE_BEGIN

template <int dim> 
class TSParSH_Init {

  private: 
    int N;

  public:
   
  //default constructor
  TSParSH_Init();

  //methods
  //  /** \brief  Return the type (bpoundary vertex or not) of the vertex */
  // bool Test();

};

SParSH_NAMESPACE_END