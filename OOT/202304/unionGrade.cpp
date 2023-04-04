//
// Created by Anthony Wong on 2023/4/4.
//
#include<iostream>
#include<string>
using namespace std;

class ExamInfo{
public:
    ExamInfo(string name,char grade):name(name),mode(GRADE),grade(grade){}
    ExamInfo(string name,bool pass):name(name),mode(PASS),pass(pass){}
    ExamInfo(string name,int percentage):name(name),mode(PERCENTAGE),percentage(percentage){}
    void show();
private:
    string name;
    enum{
        GRADE,
        PASS,
        PERCENTAGE
    }mode;
    union{
        char grade;
        bool pass;
        int percentage;
    };
};

void ExamInfo::show(){
    cout<<"name:"<<name;
    switch(mode){
        case GRADE:cout<<" grade:"<<grade<<endl;break;
        case PASS:cout<<" pass:"<<(PASS?"PASS":"FAIL")<<endl;break;
        case PERCENTAGE:cout<<" Percentage:"<<percentage<<endl;break;
    }

}


int main(){
    ExamInfo course1("English",'B');
    ExamInfo course2("Mathematics",true);
    ExamInfo course3("C++",99);
    course1.show();
    course2.show();
    course3.show();
    return 0;
}
