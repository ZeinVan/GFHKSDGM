//
// Created by Anthony Wong on 2023/5/19.
//
#include <iostream>
//#include "change.cpp"
using namespace std;
//extern int n;
//int n=0;
int fnl(){
    static int n=10;
    n++;
    cout<<n<<endl;
    return n;
}

int main(){
    //n=3;
    fnl();fnl();fnl();fnl();fnl();fnl();fnl();fnl();fnl();fnl();
    //cout<<n<<endl;
    return 0;
}
