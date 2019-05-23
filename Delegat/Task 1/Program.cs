using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task_1
{
  public class Program
    {
        static void Main(string[] args)
        {
            var result = new X_Y();
            var tmp = new B();
            result.WOW += tmp.Show;
            result.Add(2, 3);
            tmp.Show(5, 5);
            System.Console.ReadKey();
        }        
    }
}
