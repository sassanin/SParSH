
#include <SParSH_IO.h>

std::ofstream OutFile;

void OpenFiles()
{
  // OutFile.open("TDatabase::ParamDB->OUTFILE");
  OutFile.open("sparsh_OutFile.out");
  OutFile.setf(std::ios::scientific);
}

void CloseFiles()
{
  OutFile.close();
}


