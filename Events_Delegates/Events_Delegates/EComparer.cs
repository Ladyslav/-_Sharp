using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Events_Delegates
{
    class EComparer : IStringComparer
    {
        public bool Compare(string a, string b)
        {
            int eA = 0, eB = 0;
            int maxCount = a.Length > b.Length ? a.Length : b.Length;
            for (int i = 0; i < maxCount; i++)
            {
                if (a.Length > i)
                {
                    if (a[i] == 'e')
                    {
                        eA++;
                    }
                }
                if (b.Length > i)
                {
                    if (b[i] == 'e')
                    {
                        eB++;
                    }
                }
            }
            return eA < eB;
        }
    }
}
