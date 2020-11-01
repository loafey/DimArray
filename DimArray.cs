namespace DimArray
{
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