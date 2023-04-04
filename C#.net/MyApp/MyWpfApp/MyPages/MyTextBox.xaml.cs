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

namespace MyWpfApp.MyPages
{
    /// <summary>
    /// MyTextBox.xaml 的交互逻辑
    /// </summary>
    public partial class MyTextBox : Page
    {
        public MyTextBox()
        {
            InitializeComponent();
        }

        private void CalSum(object sender, RoutedEventArgs e)
        {
            int t1 = Convert.ToInt32(txt1.Text);
            int t2 = Convert.ToInt32(txt2.Text);
            Result.Content = t1+t2;
        }

        private void CalClear(object sender, RoutedEventArgs e)
        {
            this.Result.Content = "";
        }

        private void DisplayPwd(object sender, RoutedEventArgs e)
        {
            if (CheckBoxPwd.IsChecked == true)
            {
                pwd.Visibility = Visibility.Collapsed;
                pwd1.Visibility = Visibility.Visible;
                pwd1.Text = pwd.Password;
            }
            else { 
                pwd1.Visibility= Visibility.Collapsed;
                pwd.Visibility= Visibility.Visible;
                pwd.Password=pwd1.Text;
            }

        }
    }
}
