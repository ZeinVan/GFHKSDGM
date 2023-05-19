//
// Created by Anthony Wong on 2023/5/12.
//
#include <iostream>
using namespace std;

int x=5,y=7;
void myFunction(){
    int y=10;
    cout<<"x from myFucntion: "<<x<<endl;
    cout<<"y from myFunction: "<<y<<endl;
}

int main(){
    cout<<"x from main: "<<x<<endl;
    cout<<"y from main: "<<y<<endl;
    myFunction();
    cout<<"x from main: "<<x<<endl;
    cout<<"y from main: "<<y<<endl;
    return 0;
}