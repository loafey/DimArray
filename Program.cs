using System;
using System.Collections.Generic;

namespace BigNumbus
{
    class Program
    {
        static void Main(string[] args)
        {
            TwoDim<double> testArray = new TwoDim<double>(4, 4);
            for (int x = 0; x < testArray.X; x++)
            {
                for (int y = 0; y < testArray.Y; y++)
                {
                    testArray[x, y] = Math.Pow(x + y, 2);
                }
            }

            Console.WriteLine("2D:\n" + testArray);
            Console.WriteLine("\n1D:" + testArray.ToString1D());
        }
    }
}
