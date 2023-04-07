//
// Created by Anthony Wong on 2023/4/7.
//
//「4-10 设计一个用于人事管理的“人员”类。由于考虑到通用性，这里只抽象出所有类型人员都具有的属性：编号、性别、出生日期、身份证号等。
// 其中“出生日期”声明为一个“日期”类内嵌子对象。用成员函数实现对人员信息的录入和显示。
// 要求包括：构造函数和析构函数、复制构造函数、内联成员函数、带默认形参值的成员函数、类的组合。」
#include <iostream>
using namespace std;

class Date{
private:
    int year;
    int month;
    int day;
public:
    Date(int newYear=1970, int newMonth=1, int newDay=1) {
        year=newYear;
        month=newMonth;
        day=newDay;
    }
    Date(const Date& newDate);
    void setDate(int newYear,int newMonth,int newDay);
    void getDate();
};

void Date::setDate(int newYear, int newMonth, int newDay) {
    year=newYear;
    month=newMonth;
    day=newDay;
}

void Date::getDate() {
    cout<<month<<"-"<<day<<"-"<<year;
}

Date::Date(const Date &newDate) {
    year=newDate.year;
    month=newDate.month;
    day=newDate.day;
}

class Employee{
private:
    int eid;
    char gender;
    Date birthday;
    string identityNo;
public:
    Employee(int newEid,char newGender,Date newBirth,string newIdNo);
    Employee(const Employee& newEmployee);
    void setEmployee(int eid,char gender,Date birthday,string identity);
    void getEmployee();
};

Employee::Employee(int newEid, char newGender, Date newBirth, string newIdNo) : birthday(newBirth){
    eid=newEid;
    gender=newGender;
    identityNo=newIdNo;
    birthday=newBirth;
}

Employee::Employee(const Employee &newEmployee) :birthday(newEmployee.birthday){
    eid=newEmployee.eid;
    gender=newEmployee.gender;
    birthday=newEmployee.birthday;
    identityNo=newEmployee.identityNo;
}

void Employee::setEmployee(int newEid, char newGender, Date newBirth, string newIdNo) {
    eid=newEid;
    gender=newGender;
    birthday=newBirth;
    identityNo=newIdNo;
}

void Employee::getEmployee() {
    cout<<"ID:"<<eid<<" Gender:"<<gender<<" Birthday:";
    birthday.getDate();
    cout<<" IdNo:"<<identityNo<<endl;
}

int main(){
    Date date;
    int year,month,day;
    cout<<"Set the birthday:";
    scanf("%d-%d-%d",&month,&day,&year);
    date.setDate(year,month,day);
    cout<<"Set your ID and Gender:";
    char gender;
    scanf("%d %c",&year,&gender);
    cout<<"Enter your ID Num:";
    string Idno;
    cin>>Idno;
    Employee employeeA(year,gender,date,Idno);
    Employee employeeB(employeeA);
    employeeB.setEmployee(2,'F',date,"999999999999999");
    employeeA.getEmployee();
    employeeB.getEmployee();
    return 0;
}