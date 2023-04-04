using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyConsoleApp.Ch03
{
    public class MyExClass:System.Exception
    {
        public MyExClass(string msg) :base(msg){ }
    }
}
