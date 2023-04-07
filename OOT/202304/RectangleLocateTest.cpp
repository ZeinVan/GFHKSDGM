//
// Created by Anthony Wong on 2023/4/7.
//
//「4-9 设计并测试一个名为 Rectangle 的矩形类，其属性为矩形的左下角与右上角两个点的坐标，根据坐标能计算矩形的面积。」
#include<iostream>
using namespace std;

class Point{
private:
    double x;
    double y;
public:
    void getX(double newX){x=newX;}
    void getY(double newY){y=newY;}
    double showX(){return x;}
    double showY(){return y;}
};

class Rectangle{
private:
    Point X;
    Point Y;
public:
    Rectangle(Point X,Point Y);

    double area(){
        return (Y.showX()-X.showX())*(Y.showY()-X.showY());
    }
};

Rectangle::Rectangle(Point newX, Point newY) {
    X=newX;
    Y=newY;
}

int main(){
    Point X,Y;
    double x,y,m,n;
    scanf("(%lf,%lf) (%lf,%lf)",&x,&y,&m,&n);
    X.getX(x);
    X.getY(y);
    Y.getX(m);
    Y.getY(n);
    Rectangle rect(X,Y);
    cout<<"Area: "<<rect.area();
    return 0;
}
