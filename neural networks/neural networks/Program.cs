using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using static System.Math;
using static System.Console;


enum MemoryMode { GET, SET }
enum NeuronType { Hidden, Output }

namespace neural_networks
{
    class Program
    {
        static void Main(string[] args)
        {
             Network net = new Network();
            Train(net);
            Test(net);
            ReadKey();
        }
    }
}
