//
// Created by Anthony Wong on 2023/3/18.
//
//“编写函数把华氏温度转换为摄氏温度,公式为
//  C = (F - 32) * 5/9;
//  在主程序中提示用户输入一个华氏温度，转化后输出相应的摄氏温度。”
#include <iostream>
using namespace std;

double transfer(double a){
    return 5.0*(a-32.0)/9.0;
}

int main(){
    double f;
    cin>>f;
    cout<<"Result: "<<transfer(f);
    return 0;
}