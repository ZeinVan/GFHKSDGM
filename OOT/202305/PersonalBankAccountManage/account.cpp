//
// Created by Anthony Wong on 2023/5/3.
//
#include "account.h"
#include <iostream>
#include <cmath>

using namespace std;
double SavingsAccount::total=0;

SavingsAccount::SavingsAccount(int date, int id, double rate) :
id(id),balance(0),rate(rate),lastDate(date),accumulation(0){
    cout<<date<<"\t#"<<id<<" is created."<<endl;
}

void SavingsAccount::record(int date, double amount) {
    accumulation= accumulate(date);
    lastDate=date;
    amount=floor(amount*100+0.5)/100;
    balance+=amount;
    total+=amount;
    cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}

void SavingsAccount::deposit(int date, double amount) {
    record(date,amount);
}

void SavingsAccount::withdraw(int date, double amount) {
    if(amount>getBalance())
        cout<<"Error:Money not enough."<<endl;
    else
        record(date,-amount);
}

void SavingsAccount::settle(int date) {
    double interest=accumulate(date)*rate/365;
    if(interest)
        record(date, interest);
    accumulation=0;
}

void SavingsAccount::show() {
    cout<<"#"<<id<<"\tBalance: "<<balance<<endl;
}

