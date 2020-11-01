#pragma once
#include <iostream>
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
                    s += std::to_string(_data[x + Y * y]);

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
                    s += std::to_string(_data[i]);
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
};
//Load the function definitions
