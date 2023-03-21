//
// Created by Anthony Wong on 2023/3/21.
//
#include <iostream>
using namespace std;

class Clock{
public:
    Clock(int newH, int newM, int newS);
    Clock(){
        hour = 0;
        minute = 0;
        second = 0;
    }
    void setTime(int newH, int newM, int newS);
    void showTime();
private:
    int hour, minute, second;
};

Clock::Clock(int newH,int newM, int newS){
    hour = newH;
    minute = newM;
    second = newS;
}

void Clock::setTime(int newH, int newM, int newS) {
    hour = newH;
    minute = newM;
    second = newS;
}

void Clock::showTime(){
    cout<<"Time is: "<<hour<<":"<<minute<<":"<<second<<endl;
}

int main(){
    Clock c1(0,0,0);
    Clock c2;
    c1.setTime(13,14,0);
    c1.showTime();
    return 0;
}
