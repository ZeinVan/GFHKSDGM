using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace MyWpfApp
{
    /// <summary>
    /// App.xaml 的交互逻辑
    /// </summary>
    public partial class App : Application
    {
        public static void ExecConsoleApp(string arg) { 
            //获取ExampleWpfApp.exe文件的完整路径
            string path=System.Reflection.Assembly .GetExecutingAssembly().Location;
            //得到ExampleConsoleApp.exe的完整路径
            path = path.Replace(@"MyWpfApp\bin\Debug\MyWpfApp.exe", @"MyConsoleApp\bin\Debug\MyConsoleApp.exe");
            System.Diagnostics.Process.Start(path,arg);
        }
    }
}
