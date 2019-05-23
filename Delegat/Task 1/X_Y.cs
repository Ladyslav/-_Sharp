using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task_1
{
    public delegate void XYZ(int a, int b);

   public class X_Y
    {
        
        public void Add(int a, int b)
        {           
            a = a * a;
            b = b * b;
            WOW?.Invoke(a,b);
        }

        public event XYZ WOW;
    }
}
