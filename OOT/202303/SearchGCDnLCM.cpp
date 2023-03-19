//
// Created by Anthony Wong on 2023/3/19.
//
//“编写函数求两个整数的最大公约数和最小公倍数。”
//Search for Great Common Divisor and Least Common Multiple
#include <iostream>
using namespace std;

void GCD(int a, int b){
    if(a > b){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    for(int i = a;i >= 1; i--){
        if(a % i == 0 && b % i == 0){
            cout<<"GCD: "<<i<<endl;
            break;
        }
    }
}

void LCM(int a, int b){
    if(a > b){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    for(int i = b;i<=2999999;i++){
        if(i % b == 0 && i % a == 0){
            cout<<"LCM: "<<i<<endl;
            break;
        }
    }
}

int main(){
    int a, b;
    cin >> a >> b;
    GCD(a,b);
    LCM(a,b);
    return 0;
}
