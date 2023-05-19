//
// Created by Anthony Wong on 2023/5/3.
//
#include<iostream>
#include "account.h"
using namespace std;

int main(){
    SavingsAccount sa1(1,2020001,0.0012);
    SavingsAccount sa2(2,2020002,0.002);
    sa1.deposit(20,20000);
    sa2.deposit(30,10000);
    sa1.deposit(40,1000);
    sa2.withdraw(50,2000);
    sa1.settle(90);
    sa2.settle(90);
    sa1.show();
    sa2.show();
    cout<<"Total: "<<SavingsAccount::getTotal()<<endl;
    return 0;
}