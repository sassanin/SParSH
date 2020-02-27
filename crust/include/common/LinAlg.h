/** =======================================================================
* @brief     basic routines for linear algebra
* @author    Sashikumaar Ganesan 
* @date      27.02.2020
* @History   
===========================================================================*/

#include <SParSH_Variables.h>

#pragma once
SParSH_NAMESPACE_BEGIN

// =======================================================================
// BLAS 1
// =======================================================================
template < typename T>
std::pair<bool, int > FindValAndIdx(const std::vector<T>  & V, const T  & val);


SParSH_NAMESPACE_END