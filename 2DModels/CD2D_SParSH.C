// =======================================================================
// Purpose:     main program for solving a stationary scalar equation using ParMooN
// Author:      Sashikumaar Ganesan
// History:     Implementation started on 28.12.2019
// =======================================================================
#include <SParSH_IO.h>
#include <algorithm> 
#include <ranges> 

// =======================================================================
// main program
// =======================================================================
int main(int argc, char* argv[])
{
    int N = 100000;
    vector<int> values(100000); 
  
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
 
    for (int i : ints | ranges::views::filter(even) | std::views::transform(square)) {
        std::cout << i << ' ';
        
                 
  return 0;
} // end main
