//
// Created by Anthony Wong on 2023/3/17.
//

//在程序中定义一个整型变量，赋予 1～100 的值。要求用户猜这个数，比较两个数的大小，
// 把结果提示给用户，直到猜对为止。分别使用 while，do…while语句实现循环。

//while 方法
/*
#include <iostream>
using namespace std;
int main(){
    int num=74, flag=1, temp;
    cout<<"Guess:";
    while(flag == 1){
        cin>>temp;
        if(temp==num)
            flag=0;
        else
            cout<<"Try again:";
    }
    cout<<"Success!";
    return 0;
}
*/

//do...while 方法
#include <iostream>
using namespace std;
int main() {
    int num = 74, flag = 1, temp;
    cout << "Guess:";
    do{
        cin>>temp;
        if(temp!=num)
            cout<<"Try again:";
        else
            flag=0;
    }while(flag==1);
    cout<<"Success!";
    return 0;
}