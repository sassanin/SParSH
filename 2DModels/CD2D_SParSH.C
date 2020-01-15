// =======================================================================
// Purpose:     main program for solving a stationary scalar equation using ParMooN
// Author:      Sashikumaar Ganesan
// History:     Implementation started on 28.12.2019
// =======================================================================
#include <SParSH_IO.h>
#include <SParSH_Variables.h>
#include <SParSH_Init.h>
#include <SParSH_Database.h>
#include <algorithm> 

#include <Vertex.h>

// =======================================================================
// main program
// =======================================================================
int main(int argc, char* argv[])
{ 
 
   SParSH::TSParSH_Database<SParSH::GEO_DIM> *DataBase= new SParSH::TSParSH_Database<SParSH::GEO_DIM>();

   std::cout<<  " ParamDB : " << SParSH::TSParSH_Database<SParSH::GEO_DIM>::ParamDB.UserDoubleParameter.size() <<" :  "<<endl;

    int N = 100000;
    vector<int> values(100000); 






    double y[2], x[2]={1.5, 2.8}, *z;





    SParSH::TVertex<SParSH::GEO_DIM> V1(x);
    cout << "Size of One Ver obj:" << sizeof(V1) << endl;
    //V1.SetCoords(x);

      cout << "Size of int_fast8_t :" << sizeof(uint_fast8_t) << endl;
      cout << "Size of sint :" << sizeof(sint) << endl;
      cout << "Size of bool :" << sizeof(bool) << endl;

    V1.GetCoords(y);
    z=V1.GetCoordsPtr();

    for(sint i=0;i<SParSH::GEO_DIM;++i)
     cout << "z[i] :" << z[i] << endl;

    cout << "IsBDVert " << V1.IsBoundVert() << endl;

    //SParSH::TVertex<3> V2(x);




    vector<SParSH::TVertex<SParSH::GEO_DIM>> Vertices;
    
    cout << "Size of Vector Ver obj:" << sizeof(Vertices) << endl;

    vector<double> elems; 

//    const int dim3d = 3;
//    SParSH::TVertex<dim3d> V2(2.3, 4.6, 8.3);

    // Generate Random values 
    auto f = []() -> int { return rand() % 10000; }; 
  
    // Fill up the vector 
    generate(values.begin(), values.end(), f); 
  
    // Get starting timepoint 
    auto start = high_resolution_clock::now(); 
  
    // Call the function, here sort() 
    sort(values.begin(), values.end()); 
  
    // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
  
    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = duration_cast<microseconds>(stop - start); 
  

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 

    start = high_resolution_clock::now(); 
     for(unsigned int i=0; i<8; ++i)
            values[i] *=i; 
    stop = high_resolution_clock::now(); 

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 


    std::vector<int> ints{0,1,2,3,4,5};
    auto even = [](int i){ return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
 
    //for (int i : ints | ranges::views::filter(even) | std::views::transform(square)) {
    //   std::cout << i << ' ';
        
                 
  return 0;
} // end main
