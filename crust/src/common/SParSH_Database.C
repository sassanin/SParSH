#include <SParSH_IO.h>
#include <SParSH_Database.h>
#include <iostream>
#include <fstream>
#include<string.h> 

SParSH_NAMESPACE_BEGIN

TParamDB TSParSH_Database<GEO_DIM>::ParamDB;

/** \brief default constructor */
template <sint dim> 
TSParSH_Database<dim>::TSParSH_Database() 
 {
  /** \brief Initilize the SparSH Database */
  // SParSH::TSParSH_Database<dim> SParSH_DB;

    std::cout<<  " Para :  "<<endl;
 }

/** \brief constructor with readin.data file */
template <sint dim> 
TSParSH_Database<dim>::TSParSH_Database(std::string ReadinFile) 
 {

 /** \breif reading the BASIC_DATA from readin file for param database */
  std::ifstream dat(ReadinFile);
  try { if (!dat) throw std::runtime_error("Could not open the readin file");  }
  catch (std::exception &ex)
    { sarshpout(ex); exit(-1); }

  char line[100];
  int tempint;
  sint tempsint, outlen=0, meshlen=0, celltyplen=0, unifmstplen=0;
  std::string tempstr, outstring = "OutFile[" + std::to_string(outlen) + "]:";
  std::string meshstring = "MeshFile[" + std::to_string(meshlen) + "]:";
  std::string celltypstring = "CellTypes[" + std::to_string(celltyplen) + "]:";
  std::string unifmststring = "Uniform_Steps[" + std::to_string(unifmstplen) + "]:";

  // cout << " outstring : "<< outstring <<endl;

  while (!dat.eof())
  {
   dat >> line;

    if (! strcmp(line, "BASIC_DATA_BEGIN"))
    { break; }
  } // while (!dat.eof())

  while (!dat.eof())
  {
   dat >> line;
    if (!strcmp(line, outstring.c_str()))
     {
      if(outlen==0)
       { 
        dat >> TSParSH_Database::ParamDB.OutFile[0];
        outstring = "OutFile[" + std::to_string(++outlen) + "]:";
       }
      else
       {  
        dat >> tempstr;
        TSParSH_Database::ParamDB.OutFile.push_back(tempstr);
        outstring = "OutFile[" + std::to_string(++outlen) + "]:";
       }
     }
    else if (!strcmp(line, meshstring.c_str()))
     {
      if(meshlen==0)
       { 
        dat >> TSParSH_Database::ParamDB.MeshFile[0];
        meshstring = "MeshFile[" + std::to_string(++meshlen) + "]:";
       }
      else
       {  
        dat >> tempstr;
        TSParSH_Database::ParamDB.MeshFile.push_back(tempstr);
        meshstring = "MeshFile[" + std::to_string(++meshlen) + "]:";
       }
     }
    else if (!strcmp(line, celltypstring.c_str()))
     {
      if(celltyplen==0)
       { 
        dat >> TSParSH_Database::ParamDB.CellTypes[0];
        celltypstring = "CellTypes[" + std::to_string(++celltyplen) + "]:";
       }
      else
       {  
        dat >> tempsint;
        TSParSH_Database::ParamDB.CellTypes.push_back(tempsint);
        celltypstring = "CellTypes[" + std::to_string(++celltyplen) + "]:";
       }
     }
    else if (!strcmp(line, unifmststring.c_str()))
     {
      if(unifmstplen==0)
       { 
        dat >> TSParSH_Database::ParamDB.Uniform_Steps[0];
        unifmststring = "Uniform_Steps[" + std::to_string(++unifmstplen) + "]:";
       }
      else
       {  
        dat >> tempsint;
        TSParSH_Database::ParamDB.Uniform_Steps.push_back(tempsint);
        unifmststring = "Uniform_Steps[" + std::to_string(++unifmstplen) + "]:";
       }
     }
   else if (! strcmp(line, "VTKFile:"))
    {    
     dat >> TSParSH_Database::ParamDB.VTKFile;
    }
   else if (! strcmp(line, "PSFile:"))
    {    
     dat >> TSParSH_Database::ParamDB.PSFile;
    }   
   else if (! strcmp(line, "OutDir:"))
    {    
     dat >> TSParSH_Database::ParamDB.OutDir;
    }     
   else if (! strcmp(line, "Write_PS:"))
    {    
     dat >> tempint;
     if(tempint==1)
      { TSParSH_Database::ParamDB.Write_PS=true; }
     else
      { TSParSH_Database::ParamDB.Write_PS=false; }
    }   

   else if (! strcmp(line, "BASIC_DATA_END"))
    { break; }
  } // while (!dat.eof())


   // cout << "Rading  the file" << endl;
  // cin.getline(data, 100);

    // cout << "Init :TSParSH_Database<T> " <<endl;
// ParamDB.UserDoubleParameter.push_back(10); 

  
 }

// explicit instantiation
template class TSParSH_Database<GEO_DIM>;

SParSH_NAMESPACE_END
