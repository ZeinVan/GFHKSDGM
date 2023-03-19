//
// Created by Anthony Wong on 2023/3/19.
//
//用递归的方法编写函数求 Fibonacci级数，公式为
//  F n= F n-1+ F n-2（n > 2）， F 1= F 2= 1
//  观察递归调用的过程。”
//Fibonacci Recursive
#include <iostream>
using namespace std;

long long int Fibonacci(int n){
    if(n == 1 || n == 2)
        return 1;
    return Fibonacci(n - 1)+Fibonacci(n - 2);
}

int main(){
    int n;
    cin >> n;
    cout << Fibonacci(n);
    return 0;
}
