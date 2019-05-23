using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace neural_networks
{
  class InputLayer
    {
          private (double[], double[])[] _trainset = new(double[], double[])[]//да-да, массив кортежей из 2 массивов
        {
            (new double[]{ 0, 0 }, new double[]{ 0, 1 }),
            (new double[]{ 0, 1 }, new double[]{ 1, 0 }),
            (new double[]{ 1, 0 }, new double[]{ 1, 0 }),
            (new double[]{ 1, 1 }, new double[]{ 0, 1 })
        };
        
        public (double[], double[])[] Trainset { get => _trainset; }//такие няшные свойства нынче в C# 7
     
    }
}
