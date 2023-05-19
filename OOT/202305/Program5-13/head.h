//
// Created by Anthony Wong on 2023/5/19.
//
/*「定义类 X ，Y ，Z，函数 h（X *），满足：类 X 有私有成员 i，Y 的成员函数 g（X *）是 X 的友元函数，实现对 X 的成员 i加 1；
 * 类 Z 是类 X 的友元类，其成员函数 f（X *）实现对 X 的成员 i加 5；函数 h（X *）是 X 的友元函数，实现对 X 的成员 i加 10。
 * 在一个文件中定义和实现类，在另一个文件中实现 m ain（）函数。」
*/
#ifndef GFHKSDGM_HEAD_H
#define GFHKSDGM_HEAD_H
#include <iostream>
using namespace std;
class X;

class Y{
public:
    void g(X* p);
};
class Z{
public:
    void f(X* p);
};



class X{
private:
    int i;
public:
    X():i(0){}
    friend void Y::g(X* p);
    friend class Z;
    void show(){    cout<<i<<endl;  }
    friend void h(X* p);
};

void Y::g(X *p) {
    p->i++;
}

void Z::f(X* p){
    p->i+=5;
}

void h(X* p){
    p->i+=10;
}
#endif //GFHKSDGM_HEAD_H
