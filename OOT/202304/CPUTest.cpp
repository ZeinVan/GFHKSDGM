//
// Created by Anthony Wong on 2023/4/8.
//
//「4-19 编写一个名为 CPU 的类，描述一个 CPU 的以下信息：时钟频率，最大不会超过3000MHz；
// 字长，可以是 32 位或 64 位；
// 核数，可以是单核、双核或四核；
// 是否支持超线程。各项信息要求使用位域来表示。
// 通过输出 sizeof（CPU ）来观察该类所占的字节数。」
#include<iostream>
using namespace std;

class CPU{
private:
    int clock;
    int charLength;
    int core;
    bool threadValid;
public:
    CPU(int clock,int charLength,int core,bool threadValid);
    void display();
};

CPU::CPU(int newClock, int newCharLength, int newCore, bool newThreadValid) {
    if(newClock>3000)
        cout<<"error:Invalid Clock Frequency."<<endl;
    else
        clock=newClock;
    if(newCharLength==32||newCharLength==64)
        charLength=newCharLength;
    else
        cout<<"error:Invalid Character Size."<<endl;
    if(newCore==1||newCore==2||newCore==4)
        core=newCore;
    else
        cout<<"error:Invalid Core Num."<<endl;
    threadValid=newThreadValid;
}

void CPU::display() {
    cout<<"Display::"<<endl;
    cout<<"Clock Frequency: "<<clock<<" MHz"<<endl;
    cout<<"Character Size: "<<charLength<<" bit"<<endl;
    cout<<"Core Num: "<<core<<" Cores"<<endl;
    cout<<"Thread Valid:"<<(threadValid?"Valid":"Invalid")<<endl;
}

int main(){
    int c,cl,cr;
    bool t;
    cin>>c;
    cin>>cl;
    cin>>cr;
    cin>>t;
    CPU cpu(c,cl,cr,t);
    cpu.display();
    return 0;
}
