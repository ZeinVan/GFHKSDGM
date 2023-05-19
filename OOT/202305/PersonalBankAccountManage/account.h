//
// Created by Anthony Wong on 2023/5/3.
//

#ifndef GFHKSDGM_ACCOUNT_H
#define GFHKSDGM_ACCOUNT_H
class SavingsAccount{
private:
    int id;
    double balance;
    double rate;
    int lastDate;
    double accumulation;
    static double total;
    void record(int date,double account);
    double accumulate(int date) const{
        return accumulation+balance*(date-lastDate);
    }
public:
    SavingsAccount(int date, int id, double rate);
    int getId() const{return id;}
    double getBalance() const{return balance;}
    double getRate() const{return rate;}
    static double getTotal() {return total;}
    void deposit(int date,double amount);
    void withdraw(int date, double amount);
    void settle(int date);
    void show();
};
#endif //GFHKSDGM_ACCOUNT_H
