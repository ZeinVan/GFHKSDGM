//
// Created by Anthony Wong on 2023/5/19.
//
#include <iostream>
using namespace std;
#include "head.h"

int main(){
    X x1;
    x1.show();
    Y y1;
    y1.g(&x1);
    x1.show();
    Z z1;
    z1.f(&x1);
    x1.show();
    h(&x1);
    x1.show();
    return 0;
}