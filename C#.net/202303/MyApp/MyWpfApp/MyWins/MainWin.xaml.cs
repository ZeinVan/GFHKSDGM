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

namespace MyWpfApp.MyWins
{
    /// <summary>
    /// MainWin.xaml 的交互逻辑
    /// </summary>
    public partial class MainWin : Window
    {
        public MainWin()
        {
            InitializeComponent();
        }

        private void OpenWin(object sender, RoutedEventArgs e)
        {
            MyWindow mywindow = new MyWindow();
            mywindow.Show();
        }

        private void CloseWin(object sender, RoutedEventArgs e)
        {
            this.Close();
                
        }
    }
}
