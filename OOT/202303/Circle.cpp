//
// Created by Anthony Wong on 2023/3/21.
//
//“一圆形游泳池如图 4-2 所示，现在需在其周围建一圆形过道，并在其四周围上栅栏。栅栏价格为 35 元/米，过道造价为 20 元/平方米。
// 过道宽度为 3 米，游泳池半径由键盘输入。要求编程计算并输出过道和栅栏的造价。”
#include <iostream>
using namespace std;

const float FENCE_PRICE = 35;
const float CONCRETE_PRICE = 20;
const float PI = 3.1415936;

class Circle{
public:
    Circle(float r);
    float circumference();
    float area();
private:
    int radius;
};

Circle::Circle(float r) {
    radius = r;
}

float Circle::circumference() {
    return 2 * PI * radius;
}

float Circle::area() {
    return PI * radius * radius;
}

int main(){
    float radius;
    cout<<"Enter the radius of the circle: ";
    cin>>radius;
    Circle pool(radius);
    Circle poolRim(radius + 3);
    float fenceCost = poolRim.circumference() * FENCE_PRICE;
    cout <<"FenceCost: $" << fenceCost << endl;
    float concreteCost = (poolRim.area() - pool.area()) * CONCRETE_PRICE;
    cout << "ConcreteCost: $" << concreteCost;
    return 0;
}
