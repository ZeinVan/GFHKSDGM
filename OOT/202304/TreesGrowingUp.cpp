//
// Created by Anthony Wong on 2023/4/8.
//
//「4-14 定义一个 T ree（树）类，有成员 ages（树龄），成员函数 grow（int years）对 ages加上years，age（）显示 tree对象的 ages的值。」
#include<iostream>
using namespace std;

class Tree{
private:
    int ages;
public:
    Tree(int newAges);
    void grow(int years);
    void age();
};

Tree::Tree(int newAges) {
    ages=newAges;
}

void Tree::grow(int years) {
    ages+=years;
}

void Tree::age() {
    cout<<"Age: "<<ages<<endl;
}

int main(){
    int y=0;
    cin>>y;
    Tree t(y);
    t.age();
    t.grow(3);
    t.age();
    return 0;
}
