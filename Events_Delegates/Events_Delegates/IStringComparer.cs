using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Events_Delegates
{
    interface IStringComparer
    {
        bool Compare(string a, string b);
    }
}
