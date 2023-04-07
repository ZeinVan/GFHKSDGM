//
// Created by Anthony Wong on 2023/4/7.
//
//「4-12 定义一个 D ataType（数据类型）类，能处理包含字符型、整型、浮点型 3 种类型的数据，给出其构造函数。」
#include <iostream>
using namespace std;
class DataType
{
public:
    DataType(int i){
        data.i = i;
        type = INT;
    }
    DataType(char c){
        data.c= c;
        type = CHAR;
    }
    DataType(float f){
        data.f = f;
        type = FLOAT;
    }
    void Show(){
        switch (type){
            case CHAR:
                cout << data.c << endl;
                break;
            case INT:
                cout << data.i << endl;
                break;
            case FLOAT:
                cout << data.f << endl;
                break;
            default:
                break;
        }
    }
private:
    enum TYPE { INT, CHAR, FLOAT };
    union DATA{
        int i;
        char c;
        float f;
    };
    TYPE type;
    DATA data;
};
int main(){
    DataType a('c');
    a.Show();
    DataType b(960);
    b.Show();
    DataType c(265.12f);
    c.Show();
    return 0;
}