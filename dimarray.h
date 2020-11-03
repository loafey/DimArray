#pragma once
#include <iostream>
//for internal use
std::string to_string(const std::string& value)
{
    return value;
}
namespace DimArray
{
    
    template<typename T>
    class TwoDim
    {
        public:
            T operator()(unsigned int xIndex,unsigned int yIndex) const
            {
                return _data[xIndex + Y * yIndex];
            }
            T& operator()(unsigned int xIndex,unsigned int yIndex) 
            {
                return _data[xIndex + Y * yIndex];
            }
            TwoDim(unsigned int x, unsigned int y)
            {
                T* newData = new T[x*y];
                X = x;
                Y = y;
                _data = newData;
                _length = x*y;
    
            }
            
            std::string ToString()
            {
            std::string s = "[";

            for (int x = 0; x < X; x++)
            {
                for (int y = 0; y < Y; y++)
                {
                    //using the namespace std here makes it so if the dataType is std::string, we end up calling our own to_string function that can just return the string instead of getting segfaulted
                    using namespace std;
                    s += to_string(_data[x + Y * y]);

                    if (x != X - 1 || y != Y - 1) s += ",\t";
                }
                if (x != X - 1) s += "\n";
            }
            return s + "]";
            }
            
            std::string ToString1D()
            {
                std::string s = "[";
                for (int i = 0; i < _length; i++)
                {
                    //using the namespace std here makes it so if the dataType is std::string, we end up calling our own to_string function that can just return the string instead of getting segfaulted
                    using namespace std;
                    s += to_string(_data[i]);
                    if (i != _length - 1) s += ", ";
                }
                s += "]";

                return s;
            }
            const T* get() const { return _data; } 
            void get(const T* t) { _data = t; };
            unsigned int X;
            unsigned int Y;
            ~TwoDim()
            {
              delete[] _data;  
            }
            
        private:
            T* _data;
            uint32_t _length;
    };
    template<typename T>
    class ThreeDim
    {
        public:
            T operator()(unsigned int xIndex,unsigned int yIndex, unsigned int zIndex) const
            {
                return _data[xIndex + X * (yIndex + Y * zIndex)];
            }
            T& operator()(unsigned int xIndex,unsigned int yIndex, unsigned int zIndex) 
            {
                return _data[xIndex + X * (yIndex + Y * zIndex)];
            }
            ThreeDim(unsigned int x, unsigned int y, unsigned int z)
            {
                T* newData = new T[x*y*z];
                X = x;
                Y = y;
                Z = z;
                _data = newData;
                _length = x*y*z;
    
            }
            
            std::string ToString()
            {
            std::string s = "[";

            for (int x = 0; x < X; x++)
            {
                for (int y = 0; y < Y; y++)
                {

                    for (int z = 0; z < Z; z++)
                    {
                        //using the namespace std here makes it so if the dataType is std::string, we can just return the string instead of getting segfaulted
                        using namespace std;
                        s += to_string(_data[x + X * (y + Y * z)]);
                        if (x != X - 1 || z != Y - 1 || z != Z - 1) s += ",\t";
                    }
                }
                if (x != X - 1) s += "\n";
            }
            return s + "]";
            }
            
            std::string ToString1D()
            {
                std::string s = "[";
                for (int i = 0; i < _length; i++)
                {   
                    //using the namespace std here makes it so if the dataType is std::string, we can just return the string instead of getting segfaulted
                    using namespace std;
                    s += to_string(_data[i]);
                    if (i != _length - 1) s += ", ";
                }
                s += "]";

                return s;
            }
            const T* get() const { return _data; } 
            void get(const T* t) { _data = t; };
            unsigned int X;
            unsigned int Y;
            unsigned int Z;
            ~ThreeDim()
            {
              delete[] _data;  
            }
            
        private:
            T* _data;
            uint32_t _length;
    };
    template<typename T>
    class NDim
    {
        public:
            T operator()(unsigned int* nArrIndexes) const
            {
                //dimention 0 = x 1 = y and so on
                unsigned int* rounds = new unsigned int[Dims-1];
                unsigned int returnIndex = 0;
                unsigned int tmpRoundData = 1;
                for(unsigned int u = 0; u < Dims-1;u++)
                {
                    for(unsigned int i = 0; i < Dims-u-1; i++)
                    {
                        tmpRoundData *= Sizes[i]; 
                    }
                    tmpRoundData *= nArrIndexes[Dims-1-u];
                    rounds[u] = tmpRoundData;
                    tmpRoundData = 1;
                    std::cout << "Round Data added up to " << tmpRoundData << std::endl;
                }
                std::cout << "Combining : ";
                for(int z = 0; z < Dims-1; z++)
                {
                    returnIndex += rounds[z];
                    std::cout << " " << rounds[z];
                }
                returnIndex += nArrIndexes[0];
                std::cout << std:: endl << "Total: " << returnIndex << std::endl; 
                
                
                 
                delete[] rounds;
                return _data[returnIndex];
            }
            
            T& operator()(unsigned int* nArrIndexes) 
            {
                //dimention 0 = x 1 = y and so on
                unsigned int* rounds = new unsigned int[Dims-1];
                unsigned int returnIndex = 0;
                unsigned int tmpRoundData = 1;
                for(unsigned int u = 0; u < Dims-1;u++)
                {
                    for(unsigned int i = 0; i < Dims-u-1; i++)
                    {
                        tmpRoundData *= Sizes[i]; 
                    }
                    tmpRoundData *= nArrIndexes[Dims-1-u];
                    rounds[u] = tmpRoundData;
                    tmpRoundData = 1;
                    std::cout << "Round Data added up to " << tmpRoundData << std::endl;
                }
                std::cout << "Combining : ";
                for(int z = 0; z < Dims-1; z++)
                {
                    returnIndex += rounds[z];
                    std::cout << " " << rounds[z];
                }
                returnIndex += nArrIndexes[0];
                std::cout << std:: endl << "Total: " << returnIndex << std::endl; 
                
                
                 
                delete[] rounds;
                return _data[returnIndex];
            }
            
            NDim(unsigned int dimentions, unsigned int* dimentionSizes)
            {
                Dims = dimentions;
                Sizes = new unsigned int[dimentions];
                unsigned int size = 1;
                for(unsigned int i = 0; i < dimentions;i++)
                {
                    size *= dimentionSizes[i];
                    std::cout << "New dimention at index: " << i << " of size: " << dimentionSizes[i] << std::endl;
                    Sizes[i] = dimentionSizes[i];
                }
                
                T* newData = new T[size];
                std::cout << "Total Size: "<< size << std::endl;
                _data = newData;
                _length = size;
    
            }
            
            std::string ToString()
            {
                std::string s = "[";

                /*for (int x = 0; x < X; x++)
                {
                    for (int y = 0; y < Y; y++)
                    {

                        for (int z = 0; z < Z; z++)
                        {
                            //using the namespace std here makes it so if the dataType is std::string, we can just return the string instead of getting segfaulted
                            using namespace std;
                            s += to_string(_data[x + X * (y + Y * z)]);
                            if (x != X - 1 || z != Y - 1 || z != Z - 1) s += ",\t";
                        }
                    }
                    if (x != X - 1) s += "\n";
                }
                return s + "]";*/
                    
                /*unsigned int returnIndex = 1;
                unsigned int lastDim = nArrIndexes[length-1];
                for(unsigned int u = 0; u < length-1;u++)
                {
                    for(unsigned int i = 0; i < length-u-1; i++)
                    {
                        returnIndex *= Sizes[i]; 
                    }
                    returnIndex *= nArrIndexes[length-1-u];
                }
                returnIndex += nArrIndexes[0];*/
                return s+"]";
            
                }
            
            std::string ToString1D()
            {
                std::string s = "[";
                for (int i = 0; i < _length; i++)
                {   
                    //using the namespace std here makes it so if the dataType is std::string, we can just return the string instead of getting segfaulted
                    using namespace std;
                    s += to_string(_data[i]);
                    if (i != _length - 1) s += ", ";
                }
                s += "]";

                return s;
            }
            const T* get() const { return _data; } 
            void get(const T* t) { _data = t; };
            unsigned int X;
            unsigned int Y;
            unsigned int Z;
            unsigned int Dims;
            unsigned int* Sizes;
            ~NDim()
            {
              delete[] _data;
              delete[] Sizes;
            }
            
        private:
            T* _data;
            uint32_t _length;
    };
};
//Load the function definitions
