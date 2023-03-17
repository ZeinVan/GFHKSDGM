//
// Created by Anthony Wong on 2023/3/17.
//
//漢娜塔問題
#include <iostream>
using namespace std;

void move(char a, char b){
    cout<<a<<"--->"<<b<<endl;
}

void hanoi(int m, char left, char mid, char right){
    if(m == 1)
        move(left,right);
    else {
        while (m) {
            hanoi(m - 1, left, right, mid);
            move(left, right);
            hanoi(m - 1, mid, right, left);
            m--;
        }
    }
}

int main(){
    int m;
    cout<<"Enter the num of Disks: ";
    cin>>m;
    cout<<"Here are the method of moving "<<m<<" disks in hanoi:"<<endl;
    hanoi(m,'A','B','C');
    return 0;
}
