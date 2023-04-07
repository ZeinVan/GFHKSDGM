//
// Created by Anthony Wong on 2023/4/7.
//

//「4-8 定义一个 Dog 类，包含了 age，weight等属性，以及对这些属性操作的方法。实现并测试这个类。」
#include <iostream>
using namespace std;

class Dog{
private:
    int age;
    double weight;
    string name;
public:
    void getAge(int newAge){
        age=newAge;
    }
    void getWeight(double newWeight){
        weight=newWeight;
    }
    void getName(string newName){
        name=newName;
    }
    void display(){
        cout<<name<<" Weight:"<<weight<<" Age:"<<age<<endl;
    }
};

int main(){
    Dog dog1;
    dog1.getAge(4);
    dog1.getName("haha");
    dog1.getWeight(14.2);
    dog1.display();
    return 0;
}