//
// Created by Anthony Wong on 2023/4/9.
//
//定义一个负数类 Com plex，使得下面的代码能够工作。
//（复数计算）
#include<iostream>
using namespace std;

class Complex{
private:
    double num;
    int tailNum;
public:
    Complex(double num,int tailNum);
    Complex(double num);
    void add(Complex complex);
    void show();
};

Complex::Complex(double newNum, int newTailNum) {
    num=newNum;
    tailNum=newTailNum;
}

Complex::Complex(double newNum) {
    num=newNum;
    tailNum=0;
}

void Complex::add(Complex complex) {
    num+=complex.num;
    tailNum+=complex.num;
}

void Complex::show() {
    cout<<num;
    if(tailNum)
        cout<<"+"<<tailNum<<endl;
}

int main(){
    Complex c1(3,5);
    Complex c2=4.5;
    c1.add(c2);
    c1.show();
    return 0;
}
