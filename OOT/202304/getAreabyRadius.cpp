//
// Created by Anthony Wong on 2023/4/8.
//
//「4-13 定义一个 Circle 类，有数据成员 radius（半径），成员函数 getA rea（），计算圆的面积，构造一个 Circle的对象进行测试。」
#include<iostream>
using namespace std;
#define PI 3.1415926

class Circle{
private:
    double radius;
public:
    Circle(double radius);
    double getArea();
};

Circle::Circle(double newRadius) {
    radius=newRadius;
}

double Circle::getArea() {
    return radius*radius*PI;
}

int main(){
    double r=0;
    cin>>r;
    Circle c(r);
    cout<<"Area: "<<c.getArea();
    return 0;
}