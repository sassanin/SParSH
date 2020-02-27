/**=======================================================================
// @brief     routines for IO
// @author    Sashikumaar Ganesan, 
// @date      28/12/2019
// =======================================================================*/

#ifndef __SParSH_IO__
#define __SParSH_IO__

#include <chrono> 
#include <iostream> 
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>

using std::cout;
using std::cerr;
using std::endl;
using std::ends;
using std::setw;
using std::setprecision;

using namespace std; 
using namespace std::chrono; 

void OpenFiles();
void CloseFiles();

#define output(x) {cout << "SParSH Out: "<<__FILE__<<", line "<<__LINE__<<": "<< x <<endl;}
#define OutPut(x) {OutFile << x; cout << x;}
#define ErrMsg(x) { cerr <<"Error in file "<<__FILE__<<", line "<<__LINE__<<":\n"<<x<<endl; OutFile<<"Error in file "<<__FILE__<<", line "<<__LINE__<<":\n"<<x<<endl;}
#define Error(x) {ErrMsg(x)}

extern std::ofstream OutFile;

#endif
