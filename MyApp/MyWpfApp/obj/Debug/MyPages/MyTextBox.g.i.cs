﻿#pragma checksum "..\..\..\MyPages\MyTextBox.xaml" "{8829d00f-11b8-4213-878b-770e8597ac16}" "8459812DE60D2C991DB1988D8918938F1D44B805763AFE9C76093D8B0328028E"
//------------------------------------------------------------------------------
// <auto-generated>
//     此代码由工具生成。
//     运行时版本:4.0.30319.42000
//
//     对此文件的更改可能会导致不正确的行为，并且如果
//     重新生成代码，这些更改将会丢失。
// </auto-generated>
//------------------------------------------------------------------------------

using MyWpfApp.MyPages;
using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;


namespace MyWpfApp.MyPages {
    
    
    /// <summary>
    /// MyTextBox
    /// </summary>
    public partial class MyTextBox : System.Windows.Controls.Page, System.Windows.Markup.IComponentConnector {
        
        
        #line 23 "..\..\..\MyPages\MyTextBox.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.PasswordBox pwd;
        
        #line default
        #line hidden
        
        
        #line 24 "..\..\..\MyPages\MyTextBox.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox pwd1;
        
        #line default
        #line hidden
        
        
        #line 26 "..\..\..\MyPages\MyTextBox.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.CheckBox CheckBoxPwd;
        
        #line default
        #line hidden
        
        
        #line 33 "..\..\..\MyPages\MyTextBox.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox txt1;
        
        #line default
        #line hidden
        
        
        #line 36 "..\..\..\MyPages\MyTextBox.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox txt2;
        
        #line default
        #line hidden
        
        
        #line 39 "..\..\..\MyPages\MyTextBox.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Label Result;
        
        #line default
        #line hidden
        
        
        #line 40 "..\..\..\MyPages\MyTextBox.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button btnOK;
        
        #line default
        #line hidden
        
        
        #line 42 "..\..\..\MyPages\MyTextBox.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button btnClear;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/MyWpfApp;component/mypages/mytextbox.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\..\MyPages\MyTextBox.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "4.0.0.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            this.pwd = ((System.Windows.Controls.PasswordBox)(target));
            return;
            case 2:
            this.pwd1 = ((System.Windows.Controls.TextBox)(target));
            return;
            case 3:
            this.CheckBoxPwd = ((System.Windows.Controls.CheckBox)(target));
            
            #line 26 "..\..\..\MyPages\MyTextBox.xaml"
            this.CheckBoxPwd.Click += new System.Windows.RoutedEventHandler(this.DisplayPwd);
            
            #line default
            #line hidden
            return;
            case 4:
            this.txt1 = ((System.Windows.Controls.TextBox)(target));
            return;
            case 5:
            this.txt2 = ((System.Windows.Controls.TextBox)(target));
            return;
            case 6:
            this.Result = ((System.Windows.Controls.Label)(target));
            return;
            case 7:
            this.btnOK = ((System.Windows.Controls.Button)(target));
            
            #line 40 "..\..\..\MyPages\MyTextBox.xaml"
            this.btnOK.Click += new System.Windows.RoutedEventHandler(this.CalSum);
            
            #line default
            #line hidden
            return;
            case 8:
            this.btnClear = ((System.Windows.Controls.Button)(target));
            
            #line 42 "..\..\..\MyPages\MyTextBox.xaml"
            this.btnClear.Click += new System.Windows.RoutedEventHandler(this.CalClear);
            
            #line default
            #line hidden
            return;
            }
            this._contentLoaded = true;
        }
    }
}

