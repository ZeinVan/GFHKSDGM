using MyConsoleApp.Ch01;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MyConsoleApp.Ch01;
using MyConsoleApp.Ch03;
namespace MyConsoleApp
{
    class Program
    {
        public static void Main(String[] args)
        {
            /*
            System.Console.WriteLine("wpf calls console ! "); 
            CallSubDir cf = new CallSubDir();
            cf.CallFun();
            Console.ReadKey();
            */
            Console.WriteLine("please input email address:");
            string email = Console.ReadLine();
            string[] substrings = email.Split('@', '.');
            try 
            {
                if (substrings.Length != 3)
                {
                    throw new EmailException("输入的Email地址错误");
                }
                else
                {
                    Console.WriteLine("输入正确");
                }
            }
            catch(EmailException  e) {
                Console.WriteLine(e.Message);
            }
        }
    }
}
