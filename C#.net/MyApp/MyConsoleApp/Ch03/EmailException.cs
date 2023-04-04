 using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyConsoleApp.Ch03
{
    class EmailException:System.Exception 
    {
        public EmailException(string msg) :base(msg){ }
    }
}
