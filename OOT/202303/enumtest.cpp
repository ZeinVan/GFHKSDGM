//
// Created by Anthony Wong on 2023/3/17.
//

//“声明枚举类型Weekday，包括 SUNDAY到SATURDAY七个元素在程序中声明Weekday类型的变量，对其赋值，声明整型变量，
// 看看能否对其赋Weekday 类型的值。”

#include <iostream>
using namespace std;

enum Weekdays{
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

int main(){
    int a;
    a=Sunday;
    cout<<a;
    return 0;
}
