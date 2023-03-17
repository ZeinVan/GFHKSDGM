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

namespace MyWpfApp.MyPages
{
    /// <summary>
    /// MyMainwin.xaml 的交互逻辑
    /// </summary>
    public partial class MyMainwin : Window
    {
        public MyMainwin()
        {
            InitializeComponent();
        }

        private void LoadPage1(object sender, RoutedEventArgs e)
        {
            MainFrame.Content = new Page1();
        }

        private void LoadPage2(object sender, RoutedEventArgs e)
        {
            MainFrame.Content=new Page2();
        }

        private void LoadMyTextBox(object sender, RoutedEventArgs e)
        {
            MainFrame.Content = new MyTextBox();
        }

        private void LoadCalPage(object sender, RoutedEventArgs e)
        {
            MainFrame.Content = new CalPage();
        }
    }
}
