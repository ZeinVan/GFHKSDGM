//
// Created by Anthony Wong on 2023/3/19.
//
//“编写递归函数 getPower计算χy，在同一个程序中针对整型和实型实现两个重载的函数：
//  在主程序中实现输入输出，分别输入一个整数 a 和一个实数 b 作为底数，再输入一个整数 m 作为指数，输出 a m和b m。
#include <iostream>
using namespace std;

int getPower(int a, int m){
    int res = 1;
    for(int i = 0; i < m; i++)
        res *= a;
    return res;
}

double getPower(double b, int m){
    double res = 1.0;
    for(int i = 0; i < m; i++)
        res *= b;
    return res;
}

int main(){
    int x, m;
    double y;
    cin >> x >> y >> m;
    cout << "ResultA:" << getPower(x, m) << endl << "ResultB:" << getPower(y, m);
    return 0;
}