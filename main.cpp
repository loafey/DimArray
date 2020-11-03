#include "dimarray.h"
#include <iostream>
#include <chrono>
/*int main()
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
    
    //start timer
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
    auto stop = std::chrono::high_resolution_clock::now(); //stop timer
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(stop - start); 
    std::cout << "Execution of generating WITHOUT couting a 250,250,250 std::string array took: " << duration.count() << " milliseconds or around ";
    std::cout << seconds.count() << " seconds" <<std::endl;
    delete s_arr;
    return 0;  
    
}*/
int main()
{
    unsigned int* dimSizes = new unsigned int[5] {5,5,5,5,5};
    /*dimSizes[0] = 5;
    dimSizes[1] = 5;
    dimSizes[2] = 5;
    dimSizes[3] = 4;
    dimSizes[4] = 5;
    dimSizes[5] = 6;*/
    unsigned int* dimIndex = new unsigned int[5] {1,3,1,3,1};
    /*dimIndex[0] = 1;
    dimIndex[1] = 3;
    dimIndex[2] = 1;
    dimIndex[3] = 3;
    dimIndex[4] = 4;
    dimIndex[5] = 1;*/
    DimArray::NDim<int>* nd = new DimArray::NDim<int>(5,dimSizes);
    (*nd)(dimIndex) = 13131;
    std::cout << nd->ToString1D() << std::endl;
    std::cout << std::endl;
    
    delete[] dimSizes;
    delete[] dimIndex;
    delete(nd);
  
}
