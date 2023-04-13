
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
using System.Timers;


namespace WpfApp1
{

    public partial class SecondClock : Window
    {
        // 定义计时器和计时器间隔时间
        private Timer timer;
        private const int Interval = 1; // 以毫秒为单位，更新频率为 1 毫秒

        // 定义计时器开始时间和计时器计时时间
        private DateTime startTime;
        private TimeSpan elapsedTime;

        // 定义一个 DispatcherTimer 用于在 UI 线程上更新计时器显示
        private DispatcherTimer dispatcherTimer;

        public SecondClock()
        {
            InitializeComponent();
            timer = new Timer(Interval);

            // 初始化计时器开始时间和计时器计时时间
            startTime = DateTime.MinValue;
            elapsedTime = TimeSpan.Zero;

            // 初始化 DispatcherTimer
            dispatcherTimer = new DispatcherTimer();
            dispatcherTimer.Interval = TimeSpan.FromMilliseconds(Interval);
            dispatcherTimer.Tick += dispatcherTimer_Tick;

        }

        // StartButton 的 Click 事件处理函数
        private void StartButton_Click(object sender, RoutedEventArgs e)
        {
            // 启动计时器和 DispatcherTimer
            timer.Start();
            dispatcherTimer.Start();

            // 更新计时器开始时间
            startTime = DateTime.Now;
        }

        // StopButton 的 Click 事件处理函数
        private void StopButton_Click(object sender, RoutedEventArgs e)
        {
            // 停止计时器和 DispatcherTimer
            timer.Stop();
            dispatcherTimer.Stop();

            // 更新计时器计时时间
            elapsedTime = DateTime.Now - startTime;

            // 更新计时器显示
            UpdateTimeTextBlock();
        }

        // 计时器 Tick 事件处理函数
        private void timer_Tick(object sender, ElapsedEventArgs e)
        {
            // 更新计时器计时时间
            elapsedTime += TimeSpan.FromMilliseconds(Interval);

            // 在 UI 线程上更新计时器显示
            Dispatcher.Invoke(UpdateTimeTextBlock);
        }

        // DispatcherTimer Tick 事件处理函数
        private void dispatcherTimer_Tick(object sender, EventArgs e)
        {
            // 更新计时器计时时间
            elapsedTime += TimeSpan.FromMilliseconds(Interval);

            // 更新计时器显示
            UpdateTimeTextBlock();
        }

        // 更新计时器显示
        private void UpdateTimeTextBlock()
        {
            TimeTextBlock.Text = string.Format("{0:D2}:{1:D2}:{2:D2}.{3:D3}",
                                                elapsedTime.Hours, elapsedTime.Minutes,
                                                elapsedTime.Seconds, elapsedTime.Milliseconds);
        }
    } 
}

