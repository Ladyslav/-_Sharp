using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Human
{
    public class Person
    {
       public string Id { get; }
       public string Name { get; }
       public string Surname { get; }


        public Person(string _id, string _name, string _surname)
        {
            Id = _id;
            Name = _name;
            Surname = _surname;
        }

        public override string ToString()
        {
            return $"ID={Id} Name={Name} Surname={Surname}";
        }
        
    }

}
