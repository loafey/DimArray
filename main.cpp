#include "dimarray.h"
#include <iostream>
#include <chrono>
int main()
{
    DimArray::TwoDim<int>* arr = new DimArray::TwoDim<int>(5,5);
    DimArray::ThreeDim<int>* t_arr = new DimArray::ThreeDim<int>(50,50,50);
    for(unsigned int x = 0; x < t_arr->X; x++)
    {
        for(unsigned int y = 0; y < t_arr->Y; y++)
        {
          for(unsigned int z = 0; z < t_arr->Z;z++)
          {
             (*t_arr)(x,y,z) = std::stoi(std::to_string(x) + std::to_string(y) + std::to_string(z)); 
          }
        }
    }
    (*arr)(1,1) = 1;
    std::cout << arr->ToString() << std::endl << std::endl;
    //std::cout << t_arr->ToString();
    delete arr;
    delete t_arr;
    auto start = std::chrono::high_resolution_clock::now();
    DimArray::ThreeDim<std::string>* s_arr = new DimArray::ThreeDim<std::string>(250,250,250);
    for(unsigned int x = 0; x < t_arr->X; x++)
    {
        for(unsigned int y = 0; y < t_arr->Y; y++)
        {
          for(unsigned int z = 0; z < t_arr->Z;z++)
          {
             (*s_arr)(x,y,z) = std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
             //(*s_arr)(x,y,z) = std::stoi(std::to_string(x) + std::to_string(y) + std::to_string(z));
          }
        }
    }
    //std::cout << s_arr->ToString();
    std::cout << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(stop - start); 
    std::cout << "Execution of generating WITHOUT couting a 250,250,250 std::string array took: " << duration.count() << " milliseconds or around ";
    std::cout << seconds.count() << " seconds" <<std::endl;
    delete s_arr;
    return 0;  
    
}
