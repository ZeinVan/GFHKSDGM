//
// Created by Anthony Wong on 2023/3/18.
//
//“完成函数。参数为两个 unsigned short int 型数，返回值为第一个参数除以第二个参数的结果，数据类型为short int；
// 如果第二个参数为 0，则返回值为- 1。在主程序中实现输入输出。”
#include <iostream>
using namespace std;

unsigned cal(unsigned short int a, unsigned short int b){
    return a / b;
}

int main(){
    unsigned short int a,b;
    cin>>a>>b;
    if(b==0)
        return -1;
    cout<<cal(a, b);
    return 0;
}