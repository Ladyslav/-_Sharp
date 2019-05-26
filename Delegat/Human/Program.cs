using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Human
{
    class Program
    {
        static void Main(string[] args)
        {

            var person = new Person("10", "Vlad", "Istchenko");
            var _filePAth = @"D:\Person.txt";
            using (var stream = new StreamWriter(_filePAth))
            {
                stream.WriteLine(person.ToString());
            }
        }
    }
}
