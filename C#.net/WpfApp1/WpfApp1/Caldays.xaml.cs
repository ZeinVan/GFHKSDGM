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
    /// Caldays.xaml 的交互逻辑
    /// </summary>
    public partial class Caldays : Window
    {
        public Caldays()
        {
            InitializeComponent();
            DateTime today = DateTime.Today;
            DateTime startDate = new DateTime(1949, 10, 1);
            TimeSpan elapsed = today - startDate;
            int days = elapsed.Days;
            resultLabel.Content = $"自1949年10月1日到今天一共过了{days}天";
        }
    }
}
