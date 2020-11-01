# DimArray

A simple library abstracting 1D arrays to work like multiple dimension arrays ported to C++

## Installation

For now, clone the repository, and use `make lib` to create the .so file or use `make` to create the test program

Then you can add it to the directory of your program or the default library path and link it by adding `-ldimarray` to the end of your compile command

## Usage

```cpp

//Taken from the included test program
#include "dimarray.h"
#include <iostream>
int main()
{
    DimArray::TwoDim<int>* arr = new DimArray::TwoDim<int>(5,5);
    
    (*arr)(1,1) = 1;
    std::cout << arr->ToString();
    
    delete arr;
    
    DimArray::TwoDim<std::string> arr = DimArray::TwoDim<std::string>(5,5);
    
    arr(4,1) = "A string buddy";
    
    return 0;  
    
}


```

## Contributing
samhamnam sais: "Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change."

This version is a ported version, and will be updated along side the original lib, please refer to [samhamnam's original project](https://github.com/samhamnam/DimArray) to ask for features - If you want to change something about the C++ version please send me an email at antonr@live.dk

## License
[MIT](https://github.com/samhamnam/DimArray/blob/master/license)
