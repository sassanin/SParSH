/** =======================================================================
* @class     TRefineLine_2Desc
* @brief     RefineLine descriptors source 
* @author    Sashikumaar Ganesan 
* @date      13.02.2020
* @History   
===========================================================================*/

#include <RefineLine_2Desc.h>

SParSH_NAMESPACE_BEGIN

using namespace std; 

// Constructor
template <sint dim> 
TRefineLine_2Desc<dim>::TRefineLine_2Desc(TCellDesc<dim> *celldesc) : TRefineDesc<dim>(celldesc)
{
 static constexpr int DatEdgeVertex[1][2] = { {0, 1}};
 static constexpr int DatVertexEdge[2][1] = { {0}, {0}};

 static constexpr CellType DatChildType[2] = { CellType::LINE_2, CellType::LINE_2};

 static constexpr int DatChildVertex[2][2] = { {0, 2},  {2, 1}};
 static constexpr int DatVertexChild[3][2] = { {0},  {1},  {0, 1}};
 static constexpr int DatVertexChildIndex[3][2] = { {0},  {1},  {1, 0}};

 static constexpr int DatNewVertexEqOldVertex[2] = { 0, 1};
 static constexpr int DatNewVertexEqOldVertexIndex[2] = { 0, 1};

 static constexpr int DatInteriorVertexOfCell[1] = { 2};
 static constexpr double DatPositionOfIntVert[1][2] = { {0.5, 0.5}};

 this->RefinementType = RefineType::Line_2Reg;
 this->N_Edges = 2;
 this->N_Vertices = 3;
 this->N_Children = 2;
 this->N_NewVertEqOldVert = 2;

 this->MaxN_VpC = 2;
 this->MaxN_CpV = 2;

 this->ChildType = static_cast<const CellType *>(DatChildType);
 this->ChildVertex = static_cast<const int *>(*DatChildVertex);

 this->VertexChild = static_cast<const int *>(*DatVertexChild);
 this->VertexChildIndex = static_cast<const int *>(*DatVertexChildIndex);

 this->NewVertexEqOldVertex = static_cast<const int *>(DatNewVertexEqOldVertex);
 this->NewVertexEqOldVertexIndex = static_cast<const int *>(DatNewVertexEqOldVertexIndex);

 this->InteriorVertexOfCell = static_cast<const int *>(DatInteriorVertexOfCell);
 this->PositionOfIntVert = static_cast<const double *> (*DatPositionOfIntVert);
}

// explicit instantiation
template class TRefineLine_2Desc<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END
