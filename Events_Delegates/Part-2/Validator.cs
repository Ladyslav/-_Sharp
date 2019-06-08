using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Part_2
{
    delegate bool Validate(string s);


    class Validator
    {
        public Validate[] _validators;

        public Validator(Validate[] validators)
        {
            _validators = validators;
        }

        public bool IsValid(string s)
        {
            bool isValid = true;
            foreach(var validator in _validators)
            {
                if (!validator(s))
                {
                    isValid = false;
                    break;
                }
            }
            return isValid;
        }
    }
}
