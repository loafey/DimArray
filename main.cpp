#include "dimarray.h"
#include <iostream>
int main()
{
    DimArray::TwoDim<int>* arr = new DimArray::TwoDim<int>(5,5);
    (*arr)(1,1) = 1;
    std::cout << arr->ToString();
    delete arr;
    return 0;  
    
}
