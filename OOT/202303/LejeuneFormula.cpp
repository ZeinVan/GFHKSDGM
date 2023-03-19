//
// Created by Anthony Wong on 2023/3/19.
//
//用递归的方法编写函数求 n 阶勒让德多项式的值，在主程序中实现输入输出。
//Lejeune Formula
#include <iostream>
using namespace std;

double Lejeune(int n, int x){
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    return ((2 * n - 1) * x * Lejeune(n-1, x) - (n - 1) * Lejeune(n - 2, x)) / n;
}

int main(){
    int n, x;
    cin >> n >> x;
    cout << "Result: " << Lejeune(n, x);
    return 0;
}
