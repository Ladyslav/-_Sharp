using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Disposable
{
   internal class ResourceUser
    {
        internal void Do()
        {
            var resource = new UnmanageResourceHandler();
            using (resource)
            {
                resource.Start();
            }

            var anotherResource = new UnmanageResourceHandler();
            try
            {
                resource.Start();
            }
            finally
            {
                resource.Dispose();
            }
        }

        internal void DoSomeThingVisibleOblyInternal()
        {

        }
    }
}
