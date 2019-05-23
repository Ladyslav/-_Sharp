using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Delegat
{
    class Program
    {
        static void Main(string[] args)
        {
            var counter = new Counter();
            counter.HundredReached += HandleHundreaached;
            counter.Count();

        }

        public static void HandleHundreaached()
        {
            System.Console.WriteLine("HundredReached");
            System.Console.WriteLine("Press Any KEY");
            System.Console.ReadLine();
        }
    }
}
