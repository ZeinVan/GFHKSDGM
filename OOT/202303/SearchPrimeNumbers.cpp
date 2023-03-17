//
// Created by Anthony Wong on 2023/3/17.
//
//搜尋數字from1to100的質數

//1 method ：for loop
/*
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int i,n,flag;
    for(n=1;n<=100;n++){
        for(i=2;i<=sqrt(n);i++){
            if(n%i==0)
                flag=1;
        }
        if(flag==0)
            cout<<n<<endl;
        flag=0;
    }
    return 0;
}
 */

//2 method：while loop
/*
#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int i,n,flag;
    n=1;i=1;
    while(n<=100){
        while(i<=sqrt(n)){
            if(n%i==0)
                flag=1;
            i++;
        }
        if(flag==0)
            cout<<n<<endl;
        flag=0;
        n++;
    }
    return 0;
}
*/

//3. 3 method do-while loop
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int i, n, flag,stop;
    n=2;i=2;flag=0;stop=0;
    do{
        do{
            if(i<=sqrt(n)){
                if(n%i==0){
                    flag=1;
                    stop=1;}
                i++;
            }
            else
                stop=1;
        }while(stop==0);
        stop=0;i=2;
        if(flag==0)
            cout<<n<<endl;
        else
            flag=0;
        n++;
    }while(n<=100);
    return 0;
}