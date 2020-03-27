#include <SParSH_IO.h>
#include <SParSH_Database.h>
#include <Mesh.h>
#include <BoundFacet.h>
#include <InnerFacet.h>
#include <Line_2.h>
#include <Triangle_3.h>
#include <Quadrangle_4.h>
#include <RefineLine_2Desc.h>
#include <RefineTria_3Desc.h>
#include <RefineQuad_4Desc.h>
#include <RefineNoRef.h>

#ifdef __3D__
#include <Hexahedron_8.h>
#include <Tetrahedron_4.h>
#include <RefineTetra_4Desc.h>
#include <RefineHexa_8Desc.h>
#endif

#include <algorithm>
#include <iostream>
#include <fstream>
#include<string.h> 
#include <functional>
#include <iterator> 

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

  std::unique_ptr<TMesh<dim> > localmesh(make_unique<SParSH::TMesh<GEO_DIM>>());
  // std::cout<<  " localmesh size :  " << sizeof(localmesh) <<endl;

  vector<shared_ptr<TVertex<dim>>> NewVertices(N_Vertices);
  
  double X[3], Y[3];
  for(std::size_t i_vert=0; i_vert<N_Vertices; ++i_vert)
   {
     dat.getline (line, 99);
     dat >> X[0] >> X[1] >> X[2];      
 
     NewVertices[i_vert] = make_shared<TVertex<dim>>(X);
   } 

  localmesh->MoveVertices(std::move(NewVertices));

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

  // std::cout<<  " localmesh NEdges :  " << NBDEdges <<endl;
  std::size_t v1, v2, v3, BoundaryMarker, CellMarker;

  std::vector<std::size_t> BdEdges(2*NBDEdges);
  std::vector<std::size_t> BdMarker(NBDEdges);
  // std::vector<std::size_t> UniqueBdMarker;
  bool Mark;

  for(std::size_t i_edge=0; i_edge<NBDEdges; ++i_edge)
   {
    dat.getline (line, 99);
    dat >> v1 >> v2 >> BoundaryMarker;
    BdEdges[2*i_edge] = v1-1; // C-format,  
    BdEdges[2*i_edge+1] = v2-1; // C-format, 
    BdMarker[i_edge] = BoundaryMarker; 
    // Mark=true;
    // for(std::size_t j_edge=0; j_edge<UniqueBdMarker.size(); ++j_edge)
    //   {
    //    if(UniqueBdMarker[j_edge]==BoundaryMarker) 
    //     {
    //      Mark = false; 
    //      break;
    //     }
    //   }

    // if(Mark)
    //  {
    //   UniqueBdMarker.push_back(BoundaryMarker); 
    //  }

   }// for(std::size_t i_edge=0

   /** store the unique boundaries in the mesh */
  // localmesh->AddBoundIDs(std::move(UniqueBdMarker));

  vector<shared_ptr<TFacet<dim>>> BDFacets;
  vector<size_t>::iterator itBd = begin(BdEdges);
  vector<size_t>::iterator itrB;

  for(size_t i_edge=0; i_edge<NBDEdges; ++i_edge)
   {
    /**\brief Boundary Marker ID must be in the range of 100 and 199 */
    BoundaryMarker = BdMarker[i_edge];
    itrB = next(itBd, 2*i_edge);

     if(BoundaryMarker>99 && BoundaryMarker<199 )
      { 
       BDFacets.push_back(std::move(make_unique<TBoundFacet<dim>>(FacetType::BoundEdge, BoundaryMarker, 2, itrB)));       
      }
      else
      {
        ErrMsg("BoundaryMarker should be between 99 an 199 in GmSH file");
      }
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

  // cout<<"Number of RootCells: "<< N_RootCells<<endl;

  vector<size_t> CellVertices(3*N_RootCells);
  vector<shared_ptr<TGridCell<dim>>> CellTree(N_RootCells);

  TRefineDesc<dim> *TriaRefDesc;
  /* get the raw pointer of tria_3 */
  if(TSParSH_Database::RefineDescDB[static_cast<int>(CellType::TRI_3)])
   { TriaRefDesc = (TSParSH_Database::RefineDescDB[static_cast<int>(CellType::TRI_3)]).get();}
   else
   {
     ErrMsg("Trianlge_3 is not selected in Readin file for Gmsh");
     exit(0);
  }

   std::size_t threei;
   for (size_t i=0;i<N_RootCells; ++i)
   {
    dat.getline (line, 99);
    dat >> v1 >> v2 >> v3  >> CellMarker;  
    threei = 3*i;

    CellVertices[threei    ] = --v1; // C-format,  
    CellVertices[threei + 1] = --v2; // C-format,  
    CellVertices[threei + 2] = --v3; // C-format,  
      
    CellTree[i] = make_shared<TGridCell<dim>>(TriaRefDesc, 0);
    CellTree[i]->SetVertGlobalIdx(0, v1);
    CellTree[i]->SetVertGlobalIdx(1, v1);
    CellTree[i]->SetVertGlobalIdx(2, v3);
    CellTree[i]->SetRegionID(CellMarker);
    //  CellTree[i]->SetClipBoard(i);     
    }
   
   /** move the cells to the mesh */
   localmesh->MoveCellTree(std::move(CellTree));

   // search neighbours
   vector<int> PointNeighb(N_RootCells,0); 
   size_t ThreeTimesRootcells = 3*N_RootCells;

   for (size_t i=0;i<ThreeTimesRootcells;++i)
    PointNeighb[CellVertices[i]]++;

   size_t maxEpV=*std::max_element(PointNeighb.begin(), PointNeighb.end());

   size_t len = ++maxEpV * N_RootCells;
   PointNeighb.assign(len, 0);

   // for every vertex, first column contains the number of cells incident with this vertex
   // at further columns we set the index of corresponding cells 
   size_t j;
   for(size_t i=0;i<ThreeTimesRootcells;++i)
    {
     j = CellVertices[i]*maxEpV;
     PointNeighb[j]++;
     PointNeighb[j + PointNeighb[j]] = i/3;
    }

   // generate new edges
   int N_Facets, k, kk, a, b, Neib[2], CurrNeib, len1, len2, Neighb_tmp;
   int neib0marker, neib1marker;
   size_t i_edge;

   TBaseCell<dim> *cell, *neib0, *neib1;  
   shared_ptr<TFacet<dim>> facet;  
   vector<shared_ptr<TFacet<dim>>> InnerFacets; 
   vector<shared_ptr<TFacet<dim>>> InterFacets;     
   vector<reference_wrapper<TGridCell<dim>>> Cells = localmesh->GetCollection();
   int FacetIDX = 0;

   vector<size_t>::iterator itVert = CellVertices.begin();
   vector<size_t>::iterator itrV;
   vector<size_t>::iterator itr_j;   
   for(size_t i=0;i<N_RootCells; ++i)   
    {   
     cell = &Cells[i].get();
     N_Facets = cell->GetN_Facets();
     itrV = next(itVert, 3*i);
  
     for(size_t ii=0;ii<N_Facets; ++ii)
      {
        kk = (ii+1)%3;
        a = itrV[ii];
        b = itrV[kk];
        Neib[0] = -1;
        Neib[1] = -1;
        CurrNeib = 0;

        len1 = PointNeighb[a*maxEpV];
        len2 = PointNeighb[b*maxEpV];

        // find indices of cells containing the current edge/facet
        for(j=1;j<=len1;j++)
        {
          Neighb_tmp = PointNeighb[a*maxEpV + j];
          for (k=1;k<=len2;k++)
           if (Neighb_tmp == PointNeighb[b*maxEpV + k])
            {
             Neib[CurrNeib++] = Neighb_tmp;
             break;
            } 
          if (CurrNeib == 2) break;
        } // for (j=1;j<=len1;j++

        // inner edge or interface between two domains
        if(CurrNeib == 2)
        {
          // neib0 = &Cells[Neib[0]].get();  
          neib0 = &Cells.at(Neib[0]).get();          
          neib1 = &Cells.at(Neib[1]).get();     
              
          neib0marker = neib0->GetPhaseID();
          neib1marker = neib1->GetPhaseID();    
      
          if(neib0marker==neib1marker)   
          {
            facet = make_shared<TInnerFacet<dim>>(neib0, neib1);
            InnerFacets.push_back(facet);          
          }
          else // interface joint
          {
           //  TInterfaceJoint::CheckOrientation()
           ErrMsg("Yet to be implemented");
          } // else    
        } //  if(CurrNeib == 2)
        else if (CurrNeib == 1) // Boundary face
        {
         /** Get the index of the BDEdge */
         for(i_edge=0; i_edge<NBDEdges; ++i_edge)
           {
            itrB = next(itBd, 2*i_edge);
            if( (a==itrB[0] || b==itrB[0])  && (a==itrB[1] || b==itrB[1]))
             { break; }  
           }

          if(i_edge==NBDEdges)
          {
           output("Error !!!!!!!! in finding BDFacet !");
           exit(0);  
          }

         /** store BDFacets in cell order */
         std::swap(BDFacets[FacetIDX], BDFacets[i_edge]);
         facet = BDFacets[FacetIDX];
         FacetIDX++;
        //  itrB = find_if(begin(itBd, end(BdEdges),[a,b]( ){}  )

        } //  else if (CurrNeib == 1)
        else
        {
          output("Error !!!!!!!! in finding face neighbours!");
          exit(0);  
        }

        // find the local index for the point 'a' on the cell
         itr_j = next(itVert, 3*Neib[0]);
         for (j=0;j<3;j++)
          if (itr_j[j] == a) break;

         // find the local index for the point 'b' on the cell 
         for (k=0;k<3;k++)
          if (itr_j[k] == b) break;

         k = k*10 + j;
         switch (k)
         {
          case  1:
          case 10:
             j = 0;
          break;
          case 12:
          case 21:
             j = 1;
          break;
          case  2:
          case 20:
            j = 2;
          break;
         }

         /** set the local facet to the cell */
         neib0->SetFacet(j, facet);
         if (Neib[1] != -1)
         {
          // find the local index for the point 'a' on the cell
          itr_j = next(itVert, 3*Neib[1]);
          for (j=0;j<3;j++)
           if (itr_j[j] == a) break;

          // find the local index for the point 'b' on the cell 
          for (k=0;k<3;k++)
           if (itr_j[k] == b) break;

          k = k*10 + j;
          switch (k) // j will contain the local index for the current
           {
            case  1:
            case 10:
             j = 0;
            break;
            case 12:
            case 21:
             j = 1;
            break;
            case  2:
            case 20:
             j = 2;
            break;
           }
          neib1->SetFacet(j, facet);
         } //  if (Neib[1] != -1)
      } // ii
    } // for(size_t i=0;

  dat.close();

  OutPut("============SParSH Mesh Info==========="<<endl);
  OutPut(setw(17)  <<"N_RootCells : "<<  Cells.size() << endl);
  OutPut(setw(17)  <<"N_InnerFacets : "<< InnerFacets.size() << endl);
  OutPut(setw(17)  << "N_InterFacets : "<<InterFacets.size() << endl);
  OutPut(setw(17)  <<"N_BDFacets : "<< BDFacets.size() << endl);
 
  localmesh->SetN_InnerFacets(InnerFacets.size());
  localmesh->SetN_InterfaceFacets(InterFacets.size());
  localmesh->SetN_BoundaryFacts(InnerFacets.size());
  
  InnerFacets.insert(std::end(InnerFacets), std::make_move_iterator(std::begin(InterFacets)), std::make_move_iterator(std::end(InterFacets)) );
  InnerFacets.insert(std::end(InnerFacets), std::make_move_iterator(std::begin(BDFacets)), std::make_move_iterator(std::end(BDFacets)) );

  OutPut(setw(17)  <<"Total N_Facets : "<< InnerFacets.size() << endl);
  OutPut("======================================="<<endl);

  /** move the facets to local mesh, needed for integral over facets, eg. dG */
  localmesh->MoveFacets(std::move(InnerFacets));
  
  /** move the genereated coarse mesh (level 0) and consruct the Domain */
  TSParSH_Database::Domain = move(make_unique<TDomain<dim>>(std::move(localmesh))); 

 } // GenerateMesh

template <sint dim> 
void TSParSH_Database<dim>::InitDescriptors() 
{
 int pos;
 /** initialize the cell descriptors */
 TSParSH_Database::CellDB.resize(N_CellTypes);
 TSParSH_Database::RefineDescDB.resize(N_CellTypes+N_RefineTypes);

 pos = static_cast<int>(CellType::LINE_2);
 TSParSH_Database::CellDB[pos] = move(make_unique<TLine_2<dim>>());
 TSParSH_Database::RefineDescDB[pos] = move(make_unique<TRefineNoRef<dim>>((TSParSH_Database::CellDB.at(pos)).get()));
 TSParSH_Database::RefineDescDB[N_CellTypes+static_cast<int>(RefineType::Line_2Reg)] = move(make_unique<TRefineLine_2Desc<dim>>((TSParSH_Database::CellDB.at(pos)).get()));
 
  /** initialize special cell descriptors on demand for the list given in readin file */
  for(size_t i = 0; i<TSParSH_Database::ParamDB->CellTypes.size(); ++i )
   {
    pos = TSParSH_Database::ParamDB->CellTypes[i];
    switch (pos)
    {
     case static_cast<int>(CellType::TRI_3):
      TSParSH_Database::CellDB[pos] = move(make_unique<TTriangle_3<dim>>());
      TSParSH_Database::RefineDescDB[pos] = move(make_unique<TRefineNoRef<dim>>((TSParSH_Database::CellDB.at(pos)).get()));      
      TSParSH_Database::RefineDescDB[N_CellTypes+static_cast<int>(RefineType::Tri_3Reg)] = move(make_unique<TRefineTria_3Desc<dim>>((TSParSH_Database::CellDB.at(pos)).get()));
     break;

     case static_cast<int>(CellType::QUAD_4):
      TSParSH_Database::CellDB[pos] = move(make_unique<TQuadrangle_4<dim>>());
      TSParSH_Database::RefineDescDB[pos] = move(make_unique<TRefineNoRef<dim>>((TSParSH_Database::CellDB.at(pos)).get()));         
      TSParSH_Database::RefineDescDB[N_CellTypes+static_cast<int>(RefineType::Quad_4Reg)] = move(make_unique<TRefineQuad_4Desc<dim>>((TSParSH_Database::CellDB.at(pos)).get()));
     break;

#ifdef __3D__
     case static_cast<int>(CellType::TETRA_4):
      TSParSH_Database::CellDB[pos] = move(make_unique<TTetrahedron_4<dim>>());
      TSParSH_Database::RefineDescDB[pos] = move(make_unique<TRefineNoRef<dim>>((TSParSH_Database::CellDB.at(pos)).get()));         
      TSParSH_Database::RefineDescDB[N_CellTypes+static_cast<int>(RefineType::Tetra_4Reg)] = move(make_unique<TRefineTetra_4Desc<dim>>((TSParSH_Database::CellDB.at(pos)).get()));
     break;

     case static_cast<int>(CellType::HEXA_8):
      TSParSH_Database::CellDB[pos] = move(make_unique<THexahedron_8<dim>>());
      TSParSH_Database::RefineDescDB[pos] = move(make_unique<TRefineNoRef<dim>>((TSParSH_Database::CellDB.at(pos)).get()));   
      TSParSH_Database::RefineDescDB[N_CellTypes+static_cast<int>(RefineType::Hexa_8Reg)] = move(make_unique<TRefineHexa_8Desc<dim>>((TSParSH_Database::CellDB.at(pos)).get()));
     break;
#endif

     default:
      ErrMsg("Check CellTypes in the readin file") 

     break;
    }
   }

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
