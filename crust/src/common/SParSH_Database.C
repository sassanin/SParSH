#include <SParSH_IO.h>
#include <SParSH_Database.h>
#include <Mesh.h>
#include <iostream>
#include <fstream>
#include<string.h> 

SParSH_NAMESPACE_BEGIN


/** \brief initialize the static ParamDB  */
template<>
std::unique_ptr<TParamDB> TSParSH_Database<GEO_DIM>::ParamDB = NULL;

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
  double tempdouble;
  sint tempsint, outlen=0, meshlen=0, celltyplen=0, unifmstplen=0, usrdblen=0., usrintlen=0;
  std::string tempstr, outstring = "OutFile[" + std::to_string(outlen) + "]:";
  std::string meshstring = "MeshFile[" + std::to_string(meshlen) + "]:";
  std::string celltypstring = "CellTypes[" + std::to_string(celltyplen) + "]:";
  std::string unifmststring = "Uniform_Steps[" + std::to_string(unifmstplen) + "]:";
  std::string usrdblstring = "UserDoubleParameter[" + std::to_string(usrdblen) + "]:";
  std::string usrintstring = "UserIntParameter[" + std::to_string(usrintlen) + "]:";

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
        dat >> TSParSH_Database::ParamDB->OutFile[0];
        outstring = "OutFile[" + std::to_string(++outlen) + "]:";
       }
      else
       {  
        dat >> tempstr;
        TSParSH_Database::ParamDB->OutFile.push_back(tempstr);
        outstring = "OutFile[" + std::to_string(++outlen) + "]:";
       }
     }
    else if (!strcmp(line, meshstring.c_str()))
     {
      if(meshlen==0)
       { 
        dat >> TSParSH_Database::ParamDB->MeshFile[0];
        meshstring = "MeshFile[" + std::to_string(++meshlen) + "]:";
       }
      else
       {  
        dat >> tempstr;
        TSParSH_Database::ParamDB->MeshFile.push_back(tempstr);
        meshstring = "MeshFile[" + std::to_string(++meshlen) + "]:";
       }
     }
    else if (!strcmp(line, celltypstring.c_str()))
     {
      if(celltyplen==0)
       { 
        dat >> TSParSH_Database::ParamDB->CellTypes[0];
        celltypstring = "CellTypes[" + std::to_string(++celltyplen) + "]:";
       }
      else
       {  
        dat >> tempsint;
        TSParSH_Database::ParamDB->CellTypes.push_back(tempsint);
        celltypstring = "CellTypes[" + std::to_string(++celltyplen) + "]:";
       }
     }
    else if (!strcmp(line, unifmststring.c_str()))
     {
      if(unifmstplen==0)
       { 
        dat >> TSParSH_Database::ParamDB->Uniform_Steps[0];
        unifmststring = "Uniform_Steps[" + std::to_string(++unifmstplen) + "]:";
       }
      else
       {  
        dat >> tempsint;
        TSParSH_Database::ParamDB->Uniform_Steps.push_back(tempsint);
        unifmststring = "Uniform_Steps[" + std::to_string(++unifmstplen) + "]:";
       }
     }
   else if (! strcmp(line, "VTKFile:"))
    {    
     dat >> TSParSH_Database::ParamDB->VTKFile;
    }
   else if (! strcmp(line, "PSFile:"))
    {    
     dat >> TSParSH_Database::ParamDB->PSFile;
    }   
   else if (! strcmp(line, "OutDir:"))
    {    
     dat >> TSParSH_Database::ParamDB->OutDir;
    }     
   else if (! strcmp(line, "Write_PS:"))
    {    
     dat >> tempint;
     if(tempint==1)
      { TSParSH_Database::ParamDB->Write_PS=true; }
     else
      { TSParSH_Database::ParamDB->Write_PS=false; }
    }   
    else if (!strcmp(line, usrdblstring.c_str()))
     {
      if(usrdblen==0)
       { 
        dat >> TSParSH_Database::ParamDB->UserDoubleParameter[0];
        usrdblstring = "UserDoubleParameter[" + std::to_string(++usrdblen) + "]:";
       }
      else
       {  
        dat >> tempdouble;
        TSParSH_Database::ParamDB->UserDoubleParameter.push_back(tempdouble);
        usrdblstring = "UserDoubleParameter[" + std::to_string(++usrdblen) + "]:";
       }
     }
    else if (!strcmp(line, usrintstring.c_str()))
     {
      if(usrintlen==0)
       { 
        dat >> TSParSH_Database::ParamDB->UserIntParameter[0];
        usrintstring = "UserIntParameter[" + std::to_string(++usrintlen) + "]:";
       }
      else
       {  
        dat >> tempint;
        TSParSH_Database::ParamDB->UserIntParameter.push_back(tempdouble);
        usrintstring = "UserIntParameter[" + std::to_string(++usrintlen) + "]:";
       }
     }
   else if (! strcmp(line, "BASIC_DATA_END"))
    {  break; }

  } // while (!dat.eof())

  dat.close();

 } // TSParSH_Database



template <sint dim> 
void TSParSH_Database<dim>::GenerateGmsh(std::string MeshFile) 
 {
  std::cout<<  " Gmsh File :  " << MeshFile <<endl;

  std::ifstream dat(MeshFile);  
  try { if (!dat) throw std::runtime_error("Could not open Gmsh file");  }
  catch (std::exception &ex)
    { sarshpout(ex); exit(-1); }

  char  line[100];
  int dimension;
  while (!dat.eof())
  {
    dat >> line;    
    if ( (!strcmp(line, "Dimension"))  ||  (!strcmp(line, "dimension")) ||  (!strcmp(line, "DIMENSION")))
    {
     dat.getline (line, 99);
     dat >> dimension;
     break;
    }
    dat.getline (line, 99);   
  }

  //still the Dim of Gmsh is 3 even for 2D mesh???
  if(dimension!=3)
   {
    cerr << "dimension: " << dimension << endl;
    cerr<<  " MESHFile " << MeshFile <<     endl;    
    exit(-1);
   }

  int N_Vertices;
  while (!dat.eof())
   {
    dat >> line;    
    if ( (!strcmp(line, "Vertices")) ||  (!strcmp(line, "vertices"))   ||  (!strcmp(line, "VERTICES"))   ) 
    {
     dat.getline (line, 99);
     dat >> N_Vertices;
     break;
    }
    dat.getline (line, 99);
   }

  std::unique_ptr<TMesh<GEO_DIM> > localmesh(make_unique<SParSH::TMesh<GEO_DIM>>(N_Vertices)  );
  // std::cout<<  " localmesh size :  " << sizeof(localmesh) <<endl;
  shared_ptr<TVertex<GEO_DIM> > svert;
  unique_ptr<TVertex<GEO_DIM> > vert;
  double X[3], Y[3];
  for(int i_vert=0; i_vert<N_Vertices; ++i_vert)
   {
     dat.getline (line, 99);
     dat >> X[0] >> X[1] >> X[2];      
 
    svert = std::move(vert = make_unique<TVertex<GEO_DIM>>(X));

    // localmesh->AddVertex(std::move(vert = make_unique<TVertex<GEO_DIM>>(X)));
    // std::cout<<  " Meshes size :  " << sizeof(vert)  <<endl;
    svert->GetCoords(Y);
     std::cout<<  X[0] << " Coord:  " << Y[0] <<endl;

      // if (X > Xmax) Xmax = X;
      // if (X < Xmin) Xmin = X;
      // if (Y > Ymax) Ymax = Y;
      // if (Y < Ymin) Ymin = Y;
   } 

 

  // std::vector< std::auto_ptr< TVertex<GEO_DIM> > > Vertices; // = localmesh->GetVertices();

   dat.close();



 } // GenerateMesh


// explicit instantiation
template class TSParSH_Database<GEO_DIM>;

SParSH_NAMESPACE_END
