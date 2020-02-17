/** =======================================================================
* @class     TRefineHexa_8Desc
* @brief     Refine Hexa_8 descriptors source 
* @author    Sashikumaar Ganesan 
* @date      17.02.2020
* @History   
===========================================================================*/

#ifdef __3D__

#include <RefineHexa_8Desc.h>

SParSH_NAMESPACE_BEGIN

using namespace std; 

// Constructor
template <sint dim> 
TRefineHexa_8Desc<dim>::TRefineHexa_8Desc(TCellDesc<dim> *celldesc) : TRefineDesc<dim>(celldesc)
{
 static constexpr CellType DatChildType[8] = {CellType::HEXA_8, CellType::HEXA_8, CellType::HEXA_8, CellType::HEXA_8,
                                              CellType::HEXA_8, CellType::HEXA_8, CellType::HEXA_8, CellType::HEXA_8};
 static constexpr RefineType DatEdgeType[6] = {RefineType::Hexa_8Reg, RefineType::Hexa_8Reg, RefineType::Hexa_8Reg,
                                               RefineType::Hexa_8Reg, RefineType::Hexa_8Reg, RefineType::Hexa_8Reg };
 static constexpr RefineType DatFaceType[12] = {RefineType::Quad_4Reg, RefineType::Quad_4Reg, RefineType::Quad_4Reg, RefineType::Quad_4Reg,
                                                RefineType::Quad_4Reg, RefineType::Quad_4Reg};

 static constexpr int DatChildVertex[8][8] = { { 0,  8, 12, 11, 15, 16, 26, 24}, { 1,  9, 12,  8, 13, 19, 26, 16},
           { 2, 10, 12,  9, 17, 22, 26, 19}, { 3, 11, 12, 10, 20, 24, 26, 22},
           { 4, 23, 25, 14, 15, 24, 26, 16}, { 5, 14, 25, 18, 13, 16, 26, 19},
           { 6, 18, 25, 21, 17, 19, 26, 22}, { 7, 21, 25, 23, 20, 22, 26, 24}};        
 static constexpr int DatVertexChild[27][8] = {{0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {0,1},
         {1,2}, {2,3}, {0,3}, {0,1,2,3}, {1,5}, {4,5}, {0,4}, {0,1,4,5}, {2,6},
         {5,6}, {1,2,5,6}, {3,7}, {6,7}, {2,3,6,7}, {4,7}, {0,3,4,7}, {4,5,6,7}, {0,1,2,3,4,5,6,7} };
 static constexpr int DatVertexChildIndex[27][8] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {1,3},
         {1,3}, {1,3}, {3,1}, {2,2,2,2}, {4,4}, {3,1}, {4,4}, {5,7,7,5}, {4,4},
         {3,1}, {5,7,7,5}, {4,4}, {3,1}, {5,7,7,5}, {1,3}, {7,5,5,7}, {2,2,2,2}, {6,6,6,6,6,6,6,6}};
 static constexpr int DatVertexChildLen[27] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 4, 2, 2, 2, 4, 2, 2, 4, 2, 2, 4, 2, 4, 4, 8};

 static constexpr int DatChildEdge[96][12] = {{ 0,  8, 11,  7, 17, 18, 52, 40, 21, 48, 51, 41}, 
                   { 2,  9,  8,  1, 12, 26, 52, 18, 29, 49, 48, 19},
                   { 4, 10,  9,  3, 22, 34, 52, 26, 37, 50, 49, 27}, 
                   { 6, 11, 10,  5, 30, 40, 52, 34, 43, 51, 50, 35},
                   {38, 47, 44, 15, 16, 42, 53, 20, 41, 51, 48, 21}, 
                   {14, 44, 45, 25, 13, 20, 53, 28, 19, 48, 49, 29},
                   {24, 45, 46, 33, 23, 28, 53, 36, 27, 49, 50, 37}, 
                   {32, 46, 47, 39, 31, 36, 53, 42, 35, 50, 51, 43}};
 static constexpr int DatEdgeChild[54][4] = {{0}, {1}, {1}, {2}, {2}, {3}, {3}, {0}, {0,1}, {1,2}, 
                 {2,3}, {0,3}, {1}, {5}, {5}, {4}, {4}, {0}, {0,1}, {1,5}, 
                 {4,5}, {0,4}, {2}, {6}, {6}, {5}, {1,2}, {2,6}, {5,6}, {1,5}, 
                 {3}, {7}, {7}, {6}, {2,3}, {3,7}, {6,7}, {2,6}, {4}, {7}, 
                 {0,3}, {0,4}, {4,7}, {3,7}, {4,5}, {5,6}, {6,7}, {4,7}, 
                 {0,1,4,5}, {1,2,5,6}, {2,3,6,7}, {0,3,4,7}, 
                 {0,1,2,3}, {4,5,6,7}};
 static constexpr int DatEdgeChildIndex[54][4] = {{0}, {3}, {0}, {3}, {0}, {3}, {0}, {3}, {1,2}, {1,2},
                   {1,2}, {2,1}, {4}, {4}, {0}, {3}, {4}, {4}, {5,7}, {11,8},
                   {7,5}, {8,11}, {4}, {4}, {0}, {3}, {5,7}, {11,8}, {7,5}, {8,11},
                   {4}, {4}, {0}, {3}, {5,7}, {11,8}, {7,5}, {8,11}, {0}, {3},
                   {7,5}, {11,8}, {5,7}, {8,11}, {2,1}, {2,1}, {2,1}, {1,2},
                   {9,10,10,9}, {9,10,10,9}, {9,10,10,9}, {10,9,9,10},
                   {6,6,6,6}, {6,6,6,6}};
 static constexpr int DatEdgeChildLen[54] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
                   2, 2, 1, 1, 1, 1, 1, 1, 2, 2,
                   2, 2, 1, 1, 1, 1, 2, 2, 2, 2,
                   1, 1, 1, 1, 2, 2, 2, 2, 1, 1,
                   2, 2, 2, 2, 2, 2, 2, 2,
                   4, 4, 4, 4, 4, 4};

 static constexpr int DatChildFace[8][6] = {{0,4,24,28,17,32},  {1,8,29,24,5,33},   {2,12,25,29,9,34}, 
                   {3,16,28,25,13,35}, {20,18,31,27,7,32}, {21,6,27,30,11,33},
                   {22,10,30,26,15,34}, {23,14,26,31,19,35}};
 static constexpr int DatFaceChild[36][2] = {{0}, {1}, {2}, {3}, {0}, {1}, {5}, {4}, {1}, {2}, 
                   {6}, {5}, {2}, {3}, {7}, {6}, {3}, {0}, {4}, {7}, 
                   {4}, {5}, {6}, {7}, {0,1}, {2,3}, {6,7}, {4,5}, {0,3}, {1,2}, 
                   {5,6}, {4,7}, {0,4}, {1,5}, {2,6}, {3,7}};
 static constexpr int DatFaceChildIndex[36][2] = {{0}, {0}, {0}, {0}, {1}, {4}, {1}, {4}, {1}, 
                   {4}, {1}, {4}, {1}, {4}, {1}, {4}, {1}, {4}, 
                   {1}, {4}, {0}, {0}, {0}, {0}, {2,3}, {2,3}, {3,2}, 
                   {3,2}, {3,2}, {2,3}, {3,2}, {2,3}, {5,5}, {5,5}, {5,5}, {5,5}};
 static constexpr int DatFaceChildLen[36] = {1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1, 1, 2, 2, 2,
                    2, 2, 2, 2, 2, 2, 2, 2, 2};


static constexpr int DatEdgeVertex[54][2] = {{0,8},  {8,1},  {1,9},  {9,2}, {2,10}, {10,3}, {3,11},
          {11,0}, {8,12}, {9,12},{10,12},{11,12}, {1,13}, {13,5},
          {5,14}, {14,4}, {4,15}, {15,0}, {8,16},{13,16},{14,16},
         {15,16}, {2,17}, {17,6}, {6,18}, {18,5}, {9,19},{17,19},
         {18,19},{13,19}, {3,20}, {20,7}, {7,21}, {21,6},{10,22},
         {20,22},{21,22}, {17,22},{4,23}, {23,7},{11,24},{15,24},
         {23,24},{20,24}, {14,25},{18,25},{21,25},{23,25},{16,26},
         {19,26},{22,26}, {24,26},{12,26},{25,26}};
static constexpr int DatVertexEdge[27][6] = {{0,7,17}, {1,2,12}, {3,4,22}, {5,6,30}, {15,16,38}, {13,14,25}, 
      {23,24,33}, {31,32,39}, {0,1,8,18}, {2,3,9,26}, {4,5,10,34}, {6,7,11,40},
      {8,9,10,11,52}, {12,13,19,29}, {14,15,20,44}, {16,17,21,41},
      {18,19,20,21,48}, {22,23,27,37}, {24,25,28,45}, {26,27,28,29,49},
      {30,31,35,43}, {32,33,36,46}, {34,35,36,37,50}, {38,39,42,47},
      {40,41,42,43,51}, {44,45,46,47,53}, {48,49,50,51,52,53}};
static constexpr int DatVertexEdgeIndex[27][6] = {{0,1,1}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,0}, {1,0,1}, 
          {1,0,1}, {1,0,1}, {1,0,0,0}, {1,0,0,0}, {1,0,0,0}, {1,0,0,0},
          {1,1,1,1,0}, {1,0,0,0}, {1,0,0,0}, {1,0,0,0}, {1,1,1,1,0},
          {1,0,0,0}, {1,0,0,0}, {1,1,1,1,0}, {1,0,0,0}, {1,0,0,0}, {1,1,1,1,0},
          {1,0,0,0}, {1,1,1,1,0}, {1,1,1,1,0}, {1,1,1,1,1,1}};
static constexpr int DatVertexEdgeLen[27] = {3, 3, 3, 3, 3, 3,
           3, 3, 4, 4, 4, 4,
           5, 4, 4, 4, 5,
           4, 4, 5, 4, 4, 5,
           4, 5, 5, 6};

static constexpr int DatFaceVertex[36][4] = 
        { {0,8,12,11},   {1,9,12,8},    {2,10,12,9},   {3,11,12,10},
          {0,8,16,15},   {1,13,16,8},   {5,14,16,13},  {4,15,16,14},
          {1,9,19,13},   {2,17,19,9},   {6,18,19,17},  {5,13,19,18},
          {2,10,22,17},  {3,20,22,10},  {7,21,22,20},  {6,17,22,21},
          {3,11,24,20},  {0,15,24,11},  {4,23,24,15},  {7,20,24,23},
          {4,14,25,23},  {5,18,25,14},  {6,21,25,18},  {7,23,25,21},
          {8,12,26,16},  {10,22,26,12}, {21,25,26,22}, {14,16,26,25},
          {11,12,26,24}, {9,19,26,12},  {18,25,26,19}, {23,24,26,25},
          {15,16,26,24}, {13,19,26,16}, {17,22,26,19}, {20,24,26,22}};
static constexpr int DatVertexFace[27][12] =
        { {0,4,17}, {1,5,8}, {2,9,12}, {3,13,16}, {7,18,20}, {6,11,21}, 
          {10,15,22}, {14,19,23}, {0,1,4,5,24}, {1,2,8,9,29}, 
          {2,3,12,13,25}, {0,3,16,17,28}, {0,1,2,3,24,25,28,29},
          {5,6,8,11,33}, {6,7,20,21,27}, {4,7,17,18,32}, {4,5,6,7,24,27,32,33},
          {9,10,12,15,34}, {10,11,21,22,30}, {8,9,10,11,29,30,33,34},
          {13,14,16,19,35}, {14,15,22,23,26}, {12,13,14,15,25,26,34,35},
          {18,19,20,23,31}, {16,17,18,19,28,31,32,35}, {20,21,22,23,26,27,30,31},
          {24,25,26,27,28,29,30,31,32,33,34,35}};
static constexpr int DatVertexFaceIndex[27][12] = 
        { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
          {0,0,0}, {0,0,0}, {1,3,1,3,0}, {1,3,1,3,0}, 
          {1,3,1,3,0}, {3,1,1,3,0}, {2,2,2,2,1,3,1,3}, 
          {1,3,3,1,0}, {1,3,1,3,0}, {3,1,1,3,0}, {2,2,2,2,3,1,1,3}, 
          {1,3,3,1,0}, {1,3,1,3,0}, {2,2,2,2,1,3,1,3},
          {1,3,3,1,0}, {1,3,1,3,0}, {2,2,2,2,1,3,1,3}, 
          {1,3,3,1,0}, {2,2,2,2,3,1,3,1}, {2,2,2,2,1,3,1,3}, 
          {2,2,2,2,2,2,2,2,2,2,2,2}};
static constexpr int DatVertexFaceLen[27] =
        {  3, 3, 3, 3, 3, 3,
           3, 3, 5, 5, 5, 5, 8,
           5, 5, 5, 8, 5, 5, 8,
           5, 5, 8, 5, 8, 8, 12};

static constexpr int DatFaceEdge[36][4] =
      { {0,8,11,7}, {2,9,8,1}, {4,10,9,3}, {6,11,10,5}, /* 0-3 */
        {0,18,21,17}, {12,19,18,1}, {14,20,19,13}, {16,21,20,15}, /* 4-7 */
        {2,26,29,12}, {22,27,26,3}, {24,28,27,23}, {13,29,28,25}, /* 8-11 */
        {4,34,37,22}, {30,35,34,5}, {32,36,35,31}, {23,37,36,33}, /* 12-15 */
        {6,40,43,30}, {17,41,40,7}, {38,42,41,16}, {31,43,42,39}, /* 16-19 */
        {15,44,47,38}, {25,45,44,14}, {33,46,45,24}, {39,47,46,32}, /* 20-23 */
        {8,52,48,18}, {34,50,52,10}, {46,53,50,36}, {20,48,53,44}, /* 24-27 */
        {11,52,51,40}, {26,49,52,9}, {45,53,49,28}, {42,51,53,47}, /* 28-31 */
        {21,48,51,41}, {29,49,48,19}, {37,50,49,27}, {43,51,50,35}}; /* 32-35 */
static constexpr int DatEdgeFace[54][4] =
      { {0,4}, {1,5}, {1,8}, {2,9}, {2,12}, {3,13}, {3,16}, {0,17},
        {0,1,24}, {1,2,29}, {2,3,25}, {0,3,28}, {5,8}, {6,11}, {6,21},
        {7,20}, {7,18}, {4,17}, {4,5,24}, {5,6,33}, {6,7,27}, {4,7,32},
        {9,12}, {10,15}, {10,22}, {11,21}, {8,9,29}, {9,10,34}, {10,11,30},
        {8,11,33}, {13,16}, {14,19}, {14,23}, {15,22}, {12,13,25}, {13,14,35},
        {14,15,26}, {12,15,34}, {18,20}, {19,23}, {16,17,28}, {17,18,32},
        {18,19,31}, {16,19,35}, {20,21,27}, {21,22,30}, {22,23,26}, {20,23,31},
        {24,27,32,33}, {29,30,33,34}, {25,26,34,35},
        {28,31,32,35}, {24,25,28,29}, {26,27,30,31}};
static constexpr int DatEdgeFaceIndex[54][4] =
        { {0,0}, {3,3}, {0,0}, {3,3}, {0,0}, {3,3}, {0,0}, {3,3},  /* 0-7 */
          {1,2,0}, {1,2,3}, {1,2,3}, {2,1,0}, {0,3}, {3,0}, {0,3}, /* 8 -14 */
          {3,0}, {0,3}, {3,0}, {1,2,3}, {1,2,3}, {1,2,0}, {2,1,0}, /* 15-21 */
          {0,3}, {3,0}, {0,3}, {3,0}, {1,2,0}, {1,2,3}, {1,2,3},   /* 22-28 */
          {2,1,0}, {0,3}, {3,0}, {0,3}, {3,0}, {1,2,0}, {1,2,3},   /* 29-35 */
          {1,2,3}, {2,1,0}, {0,3}, {3,0}, {1,2,3}, {1,2,3},        /* 36-41 */
          {1,2,0}, {2,1,0}, {1,2,3}, {1,2,0}, {1,2,0}, {2,1,3},    /* 42-47 */
          {2,1,1,2}, {1,2,1,2}, {1,2,1,2},   /* 48-50 */         
          {2,1,2,1}, {1,2,1,2}, {1,2,1,2}};  /* 51-53 */
static constexpr int DatEdgeFaceLen[54] =
        {  2, 2, 2, 2, 2, 2, 2, 2,
           3, 3, 3, 3, 2, 2, 2,
           2, 2, 2, 3, 3, 3, 3,
           2, 2, 2, 2, 3, 3, 3,
           3, 2, 2, 2, 2, 3, 3,
           3, 3, 2, 2, 3, 3,
           3, 3, 3, 3, 3, 3,
           4, 4, 4, 4, 4, 4};

static constexpr int DatNewVertexEqOldVertex[8] = { 0, 1, 2, 3, 4, 5, 6, 7};
static constexpr int DatNewVertexEqOldVertexIndex[8] = { 0, 1, 2, 3, 4, 5, 6, 7};
static constexpr int DatInteriorVertexOfCell[1] = {26};
static constexpr double DatOldFaceNewVertexPos[6][9][4] =
   { { {1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}, {0.5,0.5,0,0},
       {0,0.5,0.5,0}, {0,0,0.5,0.5}, {0.5,0,0,0.5}, {0.25, 0.25, 0.25, 0.25} },
     { {1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}, {0.5,0.5,0,0},
       {0,0.5,0.5,0}, {0,0,0.5,0.5}, {0.5,0,0,0.5}, {0.25, 0.25, 0.25, 0.25} },
     { {1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}, {0.5,0.5,0,0},
       {0,0.5,0.5,0}, {0,0,0.5,0.5}, {0.5,0,0,0.5}, {0.25, 0.25, 0.25, 0.25} },
     { {1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}, {0.5,0.5,0,0},
       {0,0.5,0.5,0}, {0,0,0.5,0.5}, {0.5,0,0,0.5}, {0.25, 0.25, 0.25, 0.25} },
     { {1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}, {0.5,0.5,0,0},
       {0,0.5,0.5,0}, {0,0,0.5,0.5}, {0.5,0,0,0.5}, {0.25, 0.25, 0.25, 0.25} },
     { {1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}, {0.5,0.5,0,0},
       {0,0.5,0.5,0}, {0,0,0.5,0.5}, {0.5,0,0,0.5}, {0.25, 0.25, 0.25, 0.25} }};

static const double DatPositionOfIntVert[1][8] =
        { { 0.125,0.125,0.125,0.125,0.125,0.125,0.125,0.125 } };

static constexpr int DatInteriorEdgeOfCell[6] = {48, 49, 50, 51, 52, 53};
static constexpr int DatInteriorFaceOfCell[12] = {24, 25, 26, 27, 28, 29, 30, 31, 32 ,33, 34, 35};

static constexpr int DatInteriorVertexOfEdge[12][1] = {{8}, {9}, {10}, {11}, {15}, {13}, {17}, {20}, {14}, {18}, {21}, {23}};
static constexpr int DatInteriorVertexOfEdgeLen[12]={1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
static const int DatInteriorVertexOfFace[6][1] = { {12}, {16}, {19}, {22}, {24}, {25}};
static const int DatInteriorVertexOfFaceLen[6] ={ 1, 1, 1, 1, 1, 1};

static constexpr int DatInteriorEdgeOfFace[6][4] = {{8,9,10,11}, {18,19,20,21}, {26,27,28,29},{34,35,36,37}, {40,41,42,43}, {44,45,46,47}};
static constexpr int DatInteriorEdgeOfFaceLen[6] = {4, 4, 4, 4, 4, 4};
static constexpr int DatOldEdgeNewVertex[12][3] = {{0,8,1}, {1,9,2}, {2,10,3}, {3,11,0}, {0,15,4}, {1,13,5}, 
                                                  {2,17,6}, {3,20,7}, {4,14,5}, {5,18,6}, {6,21,7}, {7,23,4}};
static constexpr int DatOldEdgeNewVertexLen[12] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
static constexpr int DatOldEdgeNewEdge[12][2] = {{0,1}, {2,3}, {4,5}, {6,7}, {17,16}, {12,13}, {22,23}, 
                                                {30,31}, {15,14}, {25,24}, {33,32}, {39,38}};
static constexpr int DatOldEdgeNewEdgeLen[12] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
static constexpr int DatOldFaceNewVertex[6][9] = {{0,1,2,3,8,9,10,11,12}, {0,4,5,1,15,14,13,8,16},
        {1,5,6,2,13,18,17,9,19}, {2,6,7,3,17,21,20,10,22},
        {0,3,7,4,11,20,23,15,24}, {4,7,6,5,23,21,18,14,25}};
static constexpr int DatOldFaceNewVertexLen[6] = {9, 9, 9, 9, 9, 9};
static constexpr int DatOldFaceNewEdge[6][12] = {{0,1,2,3,4,5,6,7,8,9,10,11}, {17,16,15,14,13,12,1,0,21,20,19,18},
    {12,13,25,24,23,22,3,2,29,28,27,26}, {22,23,33,32,31,30,5,4,37,36,35,34},
    {7,6,30,31,39,38,16,17,40,43,42,41}, {38,39,32,33,24,25,14,15,47,46,45,44}};
static constexpr int DatOldFaceNewEdgeLen[6] = {12, 12, 12, 12, 12, 12};
static constexpr int DatOldFaceNewFace[6][4] = {{0,1,2,3}, {4,7,6,5}, {8,11,10,9}, {12,15,14,13}, {17,16,19,18}, {20,23,22,21}};
static constexpr int DatOldFaceNewFaceLen[6] = {4, 4, 4, 4, 4, 4};
static constexpr int DatNewEdgeOldEdge[54] = {0,  0,  1,  1,  2,  2,  3,  3, -1, -1,
        -1, -1,  5,  5,  8,  8,  4,  4, -1, -1,
        -1, -1,  6,  6,  9,  9, -1, -1, -1, -1,
         7,  7, 10, 10, -1, -1, -1, -1, 11, 11,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1,-1, -1, -1};
static constexpr int DatNewFaceOldFace[36] = {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
static constexpr int DatOldFaceNewLocFace[8][6] = {{ 0, 1, -1, -1, 4, -1}, { 0, 4, 1, -1, -1, -1}, 
         { 0, -1, 4, 1, -1, -1}, { 0, -1, -1, 4, 1, -1},
         { -1, 4, -1, -1, 1, 0}, { -1, 1, 4, -1, -1, 0},
         { -1, -1, 1, 4, -1, 0}, { -1, -1, -1, 1, 4, 0}};
static constexpr int DatChildTwistIndex[36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
 
 this->RefinementType = RefineType::Hexa_8Reg;

 this->N_Vertices = 27;
 this->N_Edges = 54;
 this->N_Faces = 36;
 this->N_Children = 8;
 this->N_InnerVertices = 1;
 this->N_NewVertEqOldVert = 8;
 this->N_InnerEdges = 6;
 this->N_InnerFaces = 12;  

 this->MaxN_VpC = 8;
 this->MaxN_CpV = 8;
 this->MaxN_EpC = 12;
 this->MaxN_CpE = 4;
 this->MaxN_EpV = 6;
 this->MaxN_EpF = 4;
 this->MaxN_FpE = 4;
 this->MaxN_VpF = 4;
 this->MaxN_FpV = 12;
 this->MaxN_FpC = 6;
 this->MaxN_CpF = 2;
 this->MaxN_iVpE = 1;
 this->MaxN_iVpF = 1;
 this->MaxN_iEpF = 4;
 this->MaxN_nVpoE = 3;
 this->MaxN_nEpoE = 3;
 this->MaxN_nVpoF = 9;
 this->MaxN_oVpoF = 4;
 this->MaxN_nEpoF = 12;
 this->MaxN_nFpoF = 4;

 this->ChildType = static_cast<const CellType *>(DatChildType);
 this->EdgeType = static_cast<const RefineType *>(DatEdgeType);
 this->FaceType = static_cast<const RefineType *>(DatFaceType);

 this->ChildVertex = static_cast<const int *>(*DatChildVertex);
 this->VertexChild =  static_cast<const int *>(*DatVertexChild);
 this->VertexChildIndex = static_cast<const int *>(*DatVertexChildIndex);
 this->VertexChildLen = static_cast<const int *>(DatVertexChildLen);

 this->ChildFace = static_cast<const int *>(*DatChildFace);
 this->FaceChild = static_cast<const int *>(*DatFaceChild);
 this->FaceChildIndex = static_cast<const int *>(*DatFaceChildIndex);
 this->FaceChildLen = static_cast<const int *>(DatFaceChildLen);

 this->ChildEdge = static_cast<const int *>(*DatChildEdge);
 this->EdgeChild = static_cast<const int *>(*DatEdgeChild);
 this->EdgeChildIndex = static_cast<const int *>(*DatEdgeChildIndex);
 this->EdgeChildLen = static_cast<const int *>(DatEdgeChildLen);

 this->EdgeVertex = static_cast<const int *>(*DatEdgeVertex);
 this->VertexEdge = static_cast<const int *>(*DatVertexEdge);
 this->VertexEdgeIndex = static_cast<const int *>(*DatVertexEdgeIndex);
 this->VertexEdgeLen = static_cast<const int *>(DatVertexEdgeLen);

 this->FaceVertex = static_cast<const int *>(*DatFaceVertex);
 this->VertexFace = static_cast<const int *>(*DatVertexFace);
 this->VertexFaceIndex = static_cast<const int *>(*DatVertexFaceIndex);
 this->VertexFaceLen = static_cast<const int *>(DatVertexFaceLen);

 this->FaceEdge = static_cast<const int *>(*DatFaceEdge);
 this->EdgeFace = static_cast<const int *>(*DatEdgeFace);
 this->EdgeFaceIndex = static_cast<const int *>(*DatEdgeFaceIndex);
 this->EdgeFaceLen = static_cast<const int *>(DatEdgeFaceLen);

 this->NewVertexEqOldVertex = static_cast<const int *>(DatNewVertexEqOldVertex);
 this->NewVertexEqOldVertexIndex = static_cast<const int *>(DatNewVertexEqOldVertexIndex);

 this->InteriorVertexOfCell = static_cast<const int *>(DatInteriorVertexOfCell);
 this->PositionOfIntVert = static_cast<const double *> (*DatPositionOfIntVert);

 this->InteriorEdgeOfCell = static_cast<const int *>(DatInteriorEdgeOfCell);
 this->InteriorFaceOfCell = static_cast<const int *>(DatInteriorFaceOfCell); 
 this->InteriorVertexOfEdge = static_cast<const int *>(*DatInteriorVertexOfEdge);
 this->InteriorVertexOfEdgeLen = static_cast<const int *>(DatInteriorVertexOfEdgeLen);
 this->InteriorVertexOfFace = static_cast<const int *>(*DatInteriorVertexOfFace);
 this->InteriorVertexOfFaceLen = static_cast<const int *>(DatInteriorVertexOfFaceLen);
  this->InteriorEdgeOfFace = static_cast<const int *>(*DatInteriorEdgeOfFace);
 this->InteriorEdgeOfFaceLen = static_cast<const int *>(DatInteriorEdgeOfFaceLen);

 this->OldEdgeNewVertex = static_cast<const int *>(*DatOldEdgeNewVertex);
 this->OldEdgeNewVertexLen = static_cast<const int *>(DatOldEdgeNewVertexLen);

 this->OldEdgeNewEdge = static_cast<const int *>(*DatOldEdgeNewEdge);
 this->OldEdgeNewEdgeLen = static_cast<const int *>(DatOldEdgeNewEdgeLen);
 this->NewEdgeOldEdge = static_cast<const int *>(DatNewEdgeOldEdge);
 this->NewFaceOldFace =  static_cast<const int *>(DatNewFaceOldFace);

 this->OldFaceNewVertex = static_cast<const int *>(*DatOldFaceNewVertex);
 this->OldFaceNewVertexPos = static_cast<const double *>(*(*DatOldFaceNewVertexPos));
 this->OldFaceNewVertexLen = static_cast<const int *>(DatOldFaceNewVertexLen);
 this->OldFaceNewEdge = static_cast<const int *>(*DatOldFaceNewEdge);
 this->OldFaceNewEdgeLen = static_cast<const int *>(DatOldFaceNewEdgeLen);
 this->OldFaceNewFace = static_cast<const int *>(*DatOldFaceNewFace);
 this->OldFaceNewFaceLen = static_cast<const int *>(DatOldFaceNewFaceLen);
 
 this->OldFaceNewLocFace = static_cast<const int *>(*DatOldFaceNewLocFace);
 this->ChildTwistIndex = static_cast<const int *>(DatChildTwistIndex);
}

// explicit instantiation
template class TRefineHexa_8Desc<SParSH::GEO_DIM>;

SParSH_NAMESPACE_END

#endif