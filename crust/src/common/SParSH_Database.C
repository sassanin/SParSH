#include <SParSH_IO.h>
#include <SParSH_Database.h>
#include <Mesh.h>
#include <BoundFacet.h>
#include <Line_2.h>
#include <Triangle_3.h>
#include <Quadrangle_4.h>

#ifdef __3D__
#include <Hexahedron_8.h>
#include <Tetrahedron_4.h>
#endif

#include <iostream>
#include <fstream>
#include<string.h> 

SParSH_NAMESPACE_BEGIN

/** \brief default constructor */
template <sint dim> 
TSParSH_Database<dim>::TSParSH_Database() 
 {

  /** \brief Initilize the SparSH Database */

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

  //cout << " outstring : "<< TSParSH_Database::ParamDB->MeshFile[0] <<endl;

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
        // dat >> tempstr;
        // auto it = TSParSH_Database::ParamDB->OutFile.begin();
        // TSParSH_Database::ParamDB->OutFile.insert(it, tempstr);
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

  cout << "SParSH_Database : BASIC_DATA Read Completed "<<endl;

  /** initialise the descriptors */
  this->InitDescriptors();

 } // TSParSH_Database



template <sint dim> 
void TSParSH_Database<dim>::GenerateGmsh(std::string MeshFile) 
 {
  std::cout<<  "Start Read Gmsh File :  " << MeshFile <<endl;

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

  std::size_t N_Vertices;
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

  std::unique_ptr<TMesh<dim> > localmesh(make_unique<SParSH::TMesh<GEO_DIM>>(N_Vertices));
  // std::cout<<  " localmesh size :  " << sizeof(localmesh) <<endl;

  //TVertex<dim> *svert;
  unique_ptr<TVertex<dim> > vert;
  double X[3], Y[3];

  for(std::size_t i_vert=0; i_vert<N_Vertices; ++i_vert)
   {
     dat.getline (line, 99);
     dat >> X[0] >> X[1] >> X[2];      
 
     vert = make_unique<TVertex<dim>>(X);
     localmesh->AddVertex(std::move(vert));
     //svert = localmesh->GetVerticesAT(i_vert);
     //svert->GetCoords(Y);
     //std::cout<<  X[0] << " Coord:  " << Y[0] <<endl;

      // if (X > Xmax) Xmax = X;
      // if (X < Xmin) Xmin = X;
      // if (Y > Ymax) Ymax = Y;
      // if (Y < Ymin) Ymin = Y;
   } 

  std::size_t NBDEdges;
  while (!dat.eof())
   {
    dat >> line;    
    if ( (!strcmp(line, "Edges")) ||  (!strcmp(line, "EDGES"))   ||  (!strcmp(line, "edges"))   ) 
    {
     dat.getline (line, 99);
     dat >> NBDEdges;
     break;
    }    
    // read until end of line
    dat.getline (line, 99);
   }  

  //std::cout<<  " localmesh NEdges :  " << NBDEdges <<endl;
  std::size_t v1, v2, v3, BoundaryMarker, CellMarker;

  std::vector<std::size_t> BdEdges;
  std::vector<std::size_t> BdMarker;
  std::vector<std::size_t> UniqueBdMarker;
  bool Mark;
  // std::cout<<  " Size of BdEdges :  " << sizeof( BdEdges)  <<endl;

  for(std::size_t i_edge=0; i_edge<NBDEdges; ++i_edge)
   {
    dat.getline (line, 99);
    dat >> v1 >> v2 >> BoundaryMarker;
    BdEdges.push_back(v1-1); // C-format,  
    BdEdges.push_back(v2-1); // C-format, 
    BdMarker.push_back(BoundaryMarker); 

    Mark=true;
    for(std::size_t j_edge=0; j_edge<UniqueBdMarker.size(); ++j_edge)
      {
       if(UniqueBdMarker[j_edge]==BoundaryMarker) 
        {
         Mark = false; 
         break;
        }
      }

    if(Mark)
     {
      UniqueBdMarker.push_back(BoundaryMarker); 
     }

   }// for(std::size_t i_edge=0

   /** store the unique boundaries in the mesh */
  localmesh->AddBoundIDs(std::move(UniqueBdMarker));

  unique_ptr<TBoundFacet<dim>> BDFacet;
  std::size_t* BDFacet_ptr = BdMarker.data();
  TVertex<dim> *FacetVert[2];


  for(size_t i_edge=0; i_edge<NBDEdges; ++i_edge)
   {
     /**\brief Boundary Marker ID must be in the range of 100 and 199 */
     BoundaryMarker = BdMarker[i_edge];
     FacetVert[0] = localmesh->GetVerticesAT(BdEdges[2*i_edge]);
     FacetVert[1] = localmesh->GetVerticesAT(BdEdges[(2*i_edge) + 1]);

     if(BoundaryMarker>99 && BoundaryMarker<199 )
       BDFacet = make_unique<TBoundFacet<dim>>(FacetType::BoundEdge, BoundaryMarker, 2, FacetVert);
     localmesh->MoveBDFacet(std::move(BDFacet), BoundaryMarker);
   }

  size_t N_FacetPerCell, N_RootCells;
  while (!dat.eof())
  {
    dat >> line;
    
    if ( (!strcmp(line, "Triangles")) ||  (!strcmp(line, "TRIANGLES"))   ||  (!strcmp(line, "triangles"))   ) 
    {
     N_FacetPerCell = 3;
     dat.getline (line, 99);
     dat >> N_RootCells;
     break;
    } 
    else if ( (!strcmp(line, "Quadrilateral")) ||  (!strcmp(line, "QUADRILATERAL"))   ||  (!strcmp(line, "quadrilateral"))   ) 
    {
     N_FacetPerCell = 3;
        cerr <<   " Quad Gmsh not yet implmented!!" <<  endl;
        exit(-1); 
    }     
    
    // read until end of line
    dat.getline (line, 99);   
   }

  cout<<"Number of RootCells: "<< N_RootCells<<endl;

  for (size_t i=0;i<N_RootCells;i++)
   {
    dat.getline (line, 99);
    dat >> v1 >> v2 >> v3  >> CellMarker;  
    // CellVertices[3*i    ] = v1-1; // C-format,  
    //  CellVertices[3*i + 1] = v2-1; // C-format,  
    //  CellVertices[3*i + 2] = v3-1; // C-format,  
     
    //  CellTree[i] = new TMacroCell(TDatabase::RefDescDB[Triangle], 0);

    //  CellTree[i]->SetVertex(0, NewVertices[CellVertices[3*i    ]]);
    //  CellTree[i]->SetVertex(1, NewVertices[CellVertices[3*i + 1]]);
    //  CellTree[i]->SetVertex(2, NewVertices[CellVertices[3*i + 2]]);

    //  CellTree[i]->SetRegionID(CellMarker);
    //  CellTree[i]->SetClipBoard(i);     
    //  ((TMacroCell *) CellTree[i])->SetSubGridID(0);
    }
   


    //  for(std::size_t i_edge=0; i_edge<UniqueBdMarker.size(); ++i_edge)
      //  cout << "z[i] :" << UniqueBdMarker[i_edge] << endl;

   dat.close();

 } // GenerateMesh


template <sint dim> 
void TSParSH_Database<dim>::InitDescriptors() 
{

 /** initialize the cell descriptors */
 TSParSH_Database::CellDB.resize(N_CellTypes);
 
 /** regular share of initialized by default */
 TSParSH_Database::CellDB[static_cast<int>(CellType::LINE_2)] = move(make_unique<TLine_2<dim>>());
 TSParSH_Database::CellDB[static_cast<int>(CellType::TRI_3)] = move(make_unique<TTriangle_3<dim>>());
 TSParSH_Database::CellDB[static_cast<int>(CellType::QUAD_4)] = move(make_unique<TQuadrangle_4<dim>>());

#ifdef __3D__
 TSParSH_Database::CellDB[static_cast<int>(CellType::TETRA_4)] = move(make_unique<TTetrahedron_4<dim>>());
 TSParSH_Database::CellDB[static_cast<int>(CellType::HEXA_8)] = move(make_unique<THexahedron_8<dim>>());
#endif

 //  /** initialize special cell descriptors on demand for the list given in readin file */
 //  for(size_t i = 0; i<TSParSH_Database::ParamDB->CellTypes.size(); ++i )
 //   {
 //    switch (TSParSH_Database::ParamDB->CellTypes[i])
 //    {
 //     default:
 //     break;
 //    }
 //   }

  //verify
  // if(TSParSH_Database::CellDB[5])
  // {
  //  cout << "SParSH_Database : InitDescriptors  Completed " << TSParSH_Database::CellDB[5]->GetN_Edges() <<endl;

  //  const sint *TmpEV;
  //  TSParSH_Database::CellDB[5]->GetEdgeVertex(TmpEV);
  //    for (sint i=0; i<6; ++i)
  //      cout << "TTriangle_3 EdgeVertex: " << TmpEV[i] <<endl;
  // }
}


// explicit instantiation
template class TSParSH_Database<GEO_DIM>;

SParSH_NAMESPACE_END
