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
using System.Windows.Threading;
namespace WpfApp1
{
    /// <summary>
    /// DataClock.xaml 的交互逻辑
    /// </summary>
    public partial class DataClock : Window
    {
        public DataClock()
        {
            InitializeComponent();
            DispatcherTimer timer = new DispatcherTimer();
            timer.Interval=TimeSpan.FromSeconds(1);
            timer.Tick += Timer_Tick;
            timer.Start();
        }

        void Timer_Tick(object sender, EventArgs e)
        {

            lblTime.Content = DateTime.Now.ToString("yyyy-MM-dd dddd tt HH:mm:ss");
        }
    }
}
