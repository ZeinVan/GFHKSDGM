//
// Created by Anthony Wong on 2023/3/17.
//

//“输出九九乘法算表”
#include <iostream>
using namespace std;
int main(){
    int a=1,b=1;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<"*"<<i<<"="<<i*j<<" ";
        }
        cout<<endl;
    }
    return 0;
}