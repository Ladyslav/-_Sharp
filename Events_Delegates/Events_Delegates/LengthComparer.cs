using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Events_Delegates
{
    class LengthComparer : IStringComparer
    {
        public bool Compare(string a, string b)
        {
            return a.Length > b.Length;
        }
    }
}
