//
// Created by Anthony Wong on 2023/3/17.
//
#include <iostream>
using namespace std;

struct Time{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

int main(){
    Time time1;
    cout<<"Please enter:";
    cin>>time1.year>>time1.month>>time1.day
    >>time1.hour>>time1.minute>>time1.second;
    cout<<"Time is:"<<time1.hour<<":"<<time1.minute<<":"<<time1.second
    <<" "<<time1.month<<" "<<time1.day<<" "<<time1.year;
    return 0;
}
