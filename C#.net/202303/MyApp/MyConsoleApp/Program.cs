using MyConsoleApp.Ch01;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MyConsoleApp.Ch01;
namespace MyConsoleApp
{
    class Program
    {
        public static void Main(String[] args)
        {
            System.Console.WriteLine("wpf calls console ! "); 
            CallSubDir cf = new CallSubDir();
            cf.CallFun();
            Console.ReadKey();
        }
    }
}
