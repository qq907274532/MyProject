using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TempLate
{
    class Program
    {
        static void Swap<T>(ref T lhs, ref T rhs)
        {
            T temp;
            temp = lhs;
            lhs = rhs;
            rhs = temp;
        }

        static void Main(string[] args)
        {
            int a = 1;
            int b = 2;

            Swap<int>(ref a, ref b);
        }
    }
}

