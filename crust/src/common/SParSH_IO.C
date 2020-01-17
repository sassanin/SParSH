
#include <SParSH_IO.h>

std::ofstream OutFile;

void OpenFiles()
{
  // OutFile.open("SParSH::TSParSH_Database::ParamDB->OutFile[0]");
  OutFile.open("sparsh_OutFile.out");
  OutFile.setf(std::ios::scientific);
}

void CloseFiles()
{
  OutFile.close();
}


