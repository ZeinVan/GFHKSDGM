//
// Created by Anthony Wong on 2023/4/7.
//
//「4-11 定义并实现一个矩形类，有长、宽两个属性，由成员函数计算矩形的面积。」
#include <iostream>
using namespace std;

class Rectangle{
private:
    double length;
    double width;
public:
    Rectangle(double newLength,double newWidth);
    double area();
};

Rectangle::Rectangle(double newLength, double newWidth) {
    length=newLength;
    width=newWidth;
}

double Rectangle::area() {
    return length*width;
}

int main(){
    double m,n;
    cin>>m>>n;
    Rectangle a(m,n);
    cout<<"Area:"<<a.area();
    return 0;
}
