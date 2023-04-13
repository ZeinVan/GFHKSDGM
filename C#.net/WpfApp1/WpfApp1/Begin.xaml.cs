using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace WpfApp1
{
    /// <summary>
    /// Begin.xaml 的交互逻辑
    /// </summary>
    public partial class Begin : Window
    {

        public Begin()
        {
            //InitializeComponent();
            //var beginWindow = new Begin();
            var aaaWindow = new DataClock();
            // 将 aaa.xaml 窗体作为 Begin.xaml 窗体的子窗体打开
            //aaaWindow.Owner = beginWindow;
            aaaWindow.Show();

            // 创建 bbb.xaml 窗体
            var bbbWindow = new SecondClock();
            // 将 bbb.xaml 窗体作为 Begin.xaml 窗体的子窗体打开
            //bbbWindow.Owner = beginWindow;
            bbbWindow.Show();

            // 创建 ccc.xaml 窗体
            var cccWindow = new Caldays();
            // 将 ccc.xaml 窗体作为 Begin.xaml 窗体的子窗体打开
           // cccWindow.Owner = beginWindow;
            cccWindow.Show();

            // 显示 Begin.xaml 窗体
            //beginWindow.Show();

        }
    }
}
