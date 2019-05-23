using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Delegat
{

  public delegate void HandHundredDelegate();



  public class Counter
    {
        public void Count()
        {
            for (int i = 0; i<=100; i++)
            {
                if (i == 100)
                {
                    HundredReached?.Invoke();
                    i = 0;
                }
            }
        }
        public event HandHundredDelegate HundredReached;
    }
}
