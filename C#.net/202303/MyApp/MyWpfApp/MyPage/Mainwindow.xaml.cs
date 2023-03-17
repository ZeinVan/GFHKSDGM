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

namespace MyWpfApp.MyPage
{
    /// <summary>
    /// Mainwindow.xaml 的交互逻辑
    /// </summary>
    public partial class Mainwindow : Window
    {
        public Mainwindow()
        {
            InitializeComponent();
        }

        private void LoadPoem(object sender, RoutedEventArgs e)
        {
            MainFrame.Content = new poem();
        }

        private void LoadEssay(object sender, RoutedEventArgs e)
        {
            MainFrame.Content = new essay();
        }
    }
}
