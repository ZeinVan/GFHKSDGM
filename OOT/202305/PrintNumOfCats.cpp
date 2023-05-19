//
// Created by Anthony Wong on 2023/5/19.
//
#include <iostream>
using namespace std;

class Cat{
private:
    string name;
public:
    Cat(string name);

    static int getNumOfCat();

    static int numOfCat;
};

int Cat::numOfCat=0;

Cat::Cat(std::string hiname) {
    name=hiname;
    numOfCat++;
}

int Cat::getNumOfCat() {
    return numOfCat;
}

int main(){
    Cat cat1("huahua");
    cout<<"Here are "<<Cat::getNumOfCat()<<" cats.";
    return 0;
}