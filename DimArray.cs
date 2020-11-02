namespace DimArray
{
    public class NDim<T>
    {
        private T[] _data;

        public int[] Sizes;

        public NDim(int[] size)
        {
            Sizes = size;
            int arraySize = 1;
            for (int i = 0; i < size.Length; i++)
            {
                arraySize *= size[i];
            }
            _data = new T[arraySize];
        }

        private int generateIndex(int[] arrIndex)
        {
            int returnIndex = arrIndex[0];
            for (int i = 1; i < arrIndex.Length; i++)
            {
                int offset = arrIndex[i];
                for (int j = 0; j < i; j++)
                {
                    offset *= Sizes[j];
                }
                returnIndex += offset;
            }
            return returnIndex;
        }
        private int _generateIndex(int[] arrIndex)
        {
            int[] rounds = new int[Sizes.Length - 1];
            int returnIndex = 0;
            int tmpRoundData = 1;
            for (int u = 0; u < Sizes.Length - 1; u++)
            {
                for (int i = 0; i < Sizes.Length - u - 1; i++)
                {
                    tmpRoundData *= Sizes[i];
                }
                tmpRoundData *= arrIndex[Sizes.Length - 1 - u];
                rounds[u] = tmpRoundData;
                tmpRoundData = 1;
            }
            for (int z = 0; z < Sizes.Length - 1; z++)
            {
                returnIndex += rounds[z];
            }
            returnIndex += arrIndex[0];
            return returnIndex;
        }

        public T this[int[] index]
        {
            get
            {
                return _data[generateIndex(index)];
            }

            set
            {
                _data[generateIndex(index)] = value;
            }
        }

        public override string ToString()
        {
            string s = "[";

            for (int i = 0; i < _data.Length; i++)
            {
                s += _data[i];
                if (i != _data.Length - 1) s += ", ";
            }
            return s + "]";
        }
    }


    public class TwoDim<T>
    {
        private T[] _data;

        public int X;
        public int Y;

        public TwoDim(int x, int y)
        {
            X = x;
            Y = y;
            _data = new T[x * y];
        }

        public T this[int xIndex, int yIndex]
        {
            get
            {
                return _data[xIndex + Y * yIndex];
            }

            set
            {
                _data[xIndex + Y * yIndex] = value;
            }
        }

        public override string ToString()
        {
            string s = "[";

            for (int x = 0; x < X; x++)
            {
                for (int y = 0; y < Y; y++)
                {
                    s += this[x, y].ToString();

                    if (x != X - 1 || y != Y - 1) s += ",\t";
                }
                if (x != X - 1) s += "\n";
            }
            return s + "]";
        }

        public string ToString1D()
        {
            string s = "[";
            for (int i = 0; i < _data.Length; i++)
            {
                s += _data[i];
                if (i != _data.Length - 1) s += ", ";
            }
            s += "]";

            return s;
        }
    }

    public class ThreeDim<T>
    {
        private T[] _data;

        public int X;
        public int Y;
        public int Z;

        public ThreeDim(int x, int y, int z)
        {
            X = x;
            Y = y;
            Z = z;
            _data = new T[x * y * z];
        }

        public T this[int xIndex, int yIndex, int zIndex]
        {
            get
            {
                return _data[xIndex + X * (yIndex + Y * zIndex)];
            }

            set
            {
                _data[xIndex + X * (yIndex + Y * zIndex)] = value;
            }
        }

        public override string ToString()
        {
            string s = "[";

            for (int x = 0; x < X; x++)
            {
                for (int y = 0; y < Y; y++)
                {
                    string temp = "[";
                    for (int z = 0; z < Z; z++)
                    {
                        temp += this[x, y, z];
                        if (z != this.Z - 1) temp += ", ";
                    }
                    s += temp + "]";

                    if (x != X - 1 || y != Y - 1) s += ",\t";
                }
                if (x != X - 1) s += "\n";
            }
            return s + "]";
        }

        public string ToString1D()
        {
            string s = "[";

            for (int x = 0; x < X; x++)
            {
                for (int y = 0; y < Y; y++)
                {
                    string temp = "";
                    for (int z = 0; z < Z; z++)
                    {
                        temp += this[x, y, z];
                        if (z != this.Z - 1) temp += ", ";
                    }
                    s += temp;
                    if (x != X - 1 || y != Y - 1) s += ", ";
                }
            }
            return s + "]";
        }
    }
}