//
// Created by Anthony Wong on 2023/3/19.
//
//“在主程序中提示输入整数 n，编写函数用递归的方法求 1+ 2+…+ n 的值。”
//Recursive Sum
#include <iostream>
using namespace std;

int Sum(int n){
    if(n==1)
        return 1;
    else
        return n+Sum(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<Sum(n);
    return 0;
}