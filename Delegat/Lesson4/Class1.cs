using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lesson4
{
  public  class Class1
    {
        internal void SaveFile(Func<string, IFile> download, string path)
        {
            var file = download(path);
        }
        public delegate void EvenHandler(object sender, EventArgs args);
    }
}
