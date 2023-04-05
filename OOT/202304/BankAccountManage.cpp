//
// Created by Anthony Wong on 2023/4/5.
//
#include <iostream>
#include <cmath>

using namespace std;

class SavingAccount{
private:
    int id;
    double balance;
    double rate;
    int lastDate;
    double accumulation;
    void record(int count, double amount);
    double accumulate(int date) const{
        return accumulation+balance*(date-lastDate);
    }
public:
    SavingAccount(int dqte,int id,double rate);
    int getId(){ return id;}
    double getBalance(){ return balance;}
    double getRate(){ return rate;}
    void deposit(int date, double amount);
    void withdraw(int date,double amount);
    void settle(int date);
    void show();
};

SavingAccount::SavingAccount(int date, int id, double rate) :id(id),balance(0),rate(rate),lastDate(date),accumulation(accumulation){
    cout<<date<<"\t#"<<id<<" is created."<<endl;
}

void SavingAccount::record(int date, double amount){
    accumulation= accumulate(date);
    lastDate=date;
    amount=floor(amount*100+0.5)/100;
    balance+=amount;
    cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}

void SavingAccount::deposit(int date,double amount){
    record(date,amount);
}

void SavingAccount::withdraw(int date,double amount){
    if(amount<=getBalance())
        record(date,-amount);
    else
        cout<<"Error: Not enough money"<<endl;
}

void SavingAccount::settle(int date){
    double interest=accumulate(date)*rate/365;
    if(interest)
        record(date,interest);
    accumulation=0;
}

void SavingAccount::show(){
    cout<<"#"<<id<<"\tBalance:"<<balance<<endl;
}

int main(){
    SavingAccount sa0(1,1234567,0.012);
    SavingAccount sa1(34,2345678,0.012);
    sa0.deposit(20,3000);
    sa1.deposit(30,5000);
    sa0.withdraw(45,2000);
    sa1.withdraw(50,4000);
    sa0.settle(60);
    sa1.settle(60);
    sa0.show();
    sa1.show();
    return 0;
}
