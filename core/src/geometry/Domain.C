
#include <SParSH_IO.h>
#include <Domain.h>

SParSH_NAMESPACE_BEGIN

template <sint dim> 
TDomain<dim>::TDomain(unique_ptr<TMesh<dim>> && coarsemesh) 
 {
  Meshes.clear();
  Meshes.push_back(std::move(coarsemesh));
 }
 
/** \brief uniformaly refine the exisiting finest level mesh */
template <sint dim> 
void TDomain<dim>::UniformRefine() 
{
 auto PrevLevel = size(Meshes)-1;
 vector<shared_ptr<TGridCell<dim>>> ParentCells = (Meshes.at(PrevLevel))->GetCells();
 vector<shared_ptr<TVertex<dim>>> ParentVertics = (Meshes.at(PrevLevel))->GetVertices();

 // new level
 std::unique_ptr<TMesh<dim> > newmesh(make_unique<SParSH::TMesh<GEO_DIM>>());

 size_t N_NewCells = 0;
//  for(auto cell : ParentCells)
  // {cell-> }
 
//  vector<shared_ptr<TVertex<dim>>> NewVertices(N_Vertices);


//  for

 output(ParentCells.size());
 output("UniformRefine" )
// TMesh<dim>
// Meshes.at(pos)).get()


} // UniformRefine

template <sint dim> 
void TDomain<dim>::WriteVTKMesh() 
 {
  TMesh<dim> *FineMesh= Meshes[Meshes.size()-1].get();

  char outfile[] = {"Test.vtk"}; 
  std::ofstream dat(outfile);
  if (!dat)
  {
    Error("cannot open file for output\n");
    exit(-1);
  }
  dat.setf(std::ios::fixed);
  dat << setprecision(9);
  dat << "# vtk DataFile Version 4.2" << endl;
  dat << "file created by SParSH " << endl;

  dat << "ASCII" << endl;
  dat << "DATASET UNSTRUCTURED_GRID" << endl;

  FineMesh->WriteMesh(dat);

  dat.close();
  
  output(outfile);

 }


// explicit instantiation
 template class TDomain<SParSH::GEO_DIM>;


SParSH_NAMESPACE_END
