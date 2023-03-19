//
// Created by Anthony Wong on 2023/3/18.
//
//“编写函数判别一个数是否是质数，在主程序中实现输入输出。”
#include <iostream>
#include <cmath>
using namespace std;

void isPrime(int a){
    if(a<2)
        cout<<"NO";
    else{
        int flag = 0;
        for(int i=2; i <= sqrt(a); i++){
            if(a % i == 0)
                flag=1;
        }
        if(flag == 0)
            cout<<"YES";
        else
            cout<<"NO";
    }

}

int main(){
    int a;
    cin>>a;
    isPrime(a);
    return 0;
}
