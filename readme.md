# DimArray

A simple library abstracting 1D arrays to work like multiple dimension arrays ported to C++

Currently supporting 2 and 3 dimensions

## Installation

For now, clone the repository, and use `make lib` to create the .so file or use `make` to create the test program

For building with optimization use `make lib OPTIMIZE=-O2` and/or `make OPTIMIZE=-O2`

Then you can add it to the directory of your program or the default library path and link it by adding `-ldimarray` to the end of your compile command

## Usage

```cpp

//Taken from the included test program
#include "dimarray.h"
#include <iostream>
int main()
{
    //Creating a new DimArray can be done for any type!
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
    std::cout << t_arr->ToString();
    delete arr;
    delete t_arr;
    return 0;  
    
}


```

## Contributing
samhamnam sais: *"Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change."*

This version is a ported version, and will be updated along side the original lib, please refer to [samhamnam's original project](https://github.com/samhamnam/DimArray) to ask for features - If you want to change something about the C++ version please open a issue or send me an email at antonr@live.dk 

## License
[MIT](https://github.com/samhamnam/DimArray/blob/master/license)
