//
// Created by Anthony Wong on 2023/5/19.
//

//「定义 Boat 与 Car 两个类，二者都有 weight 属性，定义二者的一个友元函数getT otalW eight（），计算二者的重量和。」

#include <iostream>
using namespace std;

class Car;

class Boat{
private:
    int weight;
public:
    Boat(int w){weight=w;};
    friend class Car;
    friend int getTotalWeight(Boat &b,Car &c);
};

class Car{
private:
    int weight;
public:
    Car(int w){weight =w;}
    friend class Boat;
    friend int getTotalWeight(Boat &b,Car &c);
};

int getTotalWeight(Boat &b,Car &c){
    return b.weight+c.weight;
}

int main(){
    Boat b(100);
    Car c(50);
    cout<<getTotalWeight(b,c)<<endl;
    return 0;
}