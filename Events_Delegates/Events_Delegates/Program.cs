using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Events_Delegates
{
    class Program
    {
        delegate bool Comparer(string a, string b);
 
        static void Main(string[] args)
        {
            string[] array = { "T", "TE", "Tst", "Teeets" };
            Sort(array, new LengthComparer());

            foreach(var e in array)
            {
                Console.WriteLine(e);
            }
            Console.ReadKey();
        }

        
        
        static void Sort(string[] array, IStringComparer comparer)
        {
            for(int p=0; p<=array.Length - 2; p++)
            {
                for(int i=0; i <= array.Length - 2; i++)
                {
                    if (comparer.Compare(array[i], array[i + 1]))
                    {
                        string t = array[i + 1];
                        array[i + 1] = array[i];
                        array[i] = t;
                    }
                }
            }
        }
    }
}
