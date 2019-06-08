using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part_2
{
    class Program
    {
        
        static void Main(string[] args)
        {
            Validator emailValidator = new Validator(new Validate[] {MaxChar, IsEmail});
            string input = Console.ReadLine();
            if (emailValidator.IsValid(input))
            {
                Console.WriteLine("Message was sent!");
            }
            else
            {
                Console.WriteLine("Sorry, I'm wasted");
            }
            Console.ReadKey();
        }

        static bool MaxChar(string s)
        {
            return s.Length > 0 && s.Length < 255;
        }

        static bool IsEmail(string s)
        {
            return s.Contains("@");
        }

    }
}
