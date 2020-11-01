namespace DimArray
{
    public class TwoDim<T>
    {
        private T[] _data;

        public uint X;
        public uint Y;

        public TwoDim(uint x, uint y)
        {
            var newData = new T[x * y];
            X = x;
            Y = y;
            _data = newData;
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
}