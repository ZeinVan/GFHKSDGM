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
using System.Windows.Navigation;
using System.Windows.Shapes;
using Myclasslib.MyCalClass;
namespace MyWpfApp.MyPages
{
    /// <summary>
    /// CalPage.xaml 的交互逻辑
    /// </summary>
    public partial class CalPage : Page
    {
        public CalPage()
        {
            InitializeComponent();
        }

        private void CalSum(object sender, RoutedEventArgs e)
        {
            cal cal = new cal();
            int a = Convert.ToInt32(txt1.Text);
            int b = Convert.ToInt32(txt2.Text);
            SumResult.Content=cal.sum(a, b);
        }
        private void CalSub(object sender, RoutedEventArgs e)
        {
            cal cal = new cal();
            int a = Convert.ToInt32(txt3.Text);
            int b = Convert.ToInt32(txt4.Text);
            SubResult.Content = cal.sub(a, b);
        }
    }
}
