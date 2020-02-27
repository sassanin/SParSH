/** =======================================================================
* @brief     basic routines for linear algebra (Blas1)
* @author    Sashikumaar Ganesan 
* @date      27.02.2020
* @History   
===========================================================================*/
#include <SParSH_IO.h>
#include <LinAlg.h>
 
SParSH_NAMESPACE_BEGIN

template < typename T>
std::pair<bool, int > FindValAndIdx(const std::vector<T>  & V, const T  & val)
{
	std::pair<bool, int > result;
 
	// Find given value in vector
	auto it = std::find(V.begin(), V.end(), val);
 
	if (it != V.end())
	{
		result.second = distance(V.begin(), it);
		result.first = true;
	}
	else
	{
		result.first = false;
		result.second = -1;
	}
 
	return result;
}
    // how to use
	// std::pair<bool, int> out = FindValAndIdx<int>(V, 45);
	// if (out.first)
	// 	std::cout << "Val Found at index : " << out.second <<std::endl;
	// else
	// 	std::cout << "Val Not Found" << std::endl;
 

SParSH_NAMESPACE_END
