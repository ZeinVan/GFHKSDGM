//
// Created by Anthony Wong on 2023/4/14.
//
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int d1[2];  //管道描述符号P1-P2
    int d2[2];  //管道描述符号P2-P3
    int d3[2];  //管道描述符号P2-P4
    int r,j,k;   //存储管道创建的返回值
    char buff[200];  //用户输入的字符串
    printf("Please input a string: ");
    scanf("%s",buff);
    //创建管道
    r=pipe(d1);
    if(r==-1) {
        printf("创建管道失败1\n");
        exit(1);
    }

    r=pipe(d2);
    if(r==-1) {
        printf("创建管道失败2\n");
        exit(1);
    }
    r=pipe(d3);
    if(r==-1) {
        printf("创建管道失败3\n");
        exit(1);
    }
    //P1创建子进程P2
    r=fork();
    if(r) { //是P2执行
        close(d1[1]);       //P1必须关闭写
        read(d1[0],buff,sizeof(buff));    //P2从pipe1中读信息
        if(strlen(buff)%2 == 1) { //判断字符串长度 若为奇数
            j=fork();  //创建子进程P3
            if(j) { //P3执行
                close(d2[1]);  //关闭P2的写
                read(d2[0],buff,sizeof(buff));  //P3从pipe2中读
                printf("P3 pipe2 odd length string：%s\n",buff);
                close(d2[0]);  //关闭P2的读
                exit(0);
            } else { //P2执行
                close(d2[0]);  //关闭P3的读
                write(d2[1],buff,strlen(buff));  //P2写入pipe2
                printf("P2 finishes writing to pipe2.\n");
                close(d2[1]);  //关闭写
                exit(0);
            }
        } else { //字符串长度为偶数
            k=fork();  //创建P4
            if(k) { //P4执行
                close(d3[1]);  //关闭P2的写
                read(d3[0],buff,sizeof(buff));  //从pipe2中读
                printf("P4 pipe3 even length string：%s\n",buff);
                close(d3[0]);  //关闭读
                exit(0);
            } else { //P2执行
                close(d3[0]);  //关闭P4的读
                write(d3[1],buff,strlen(buff));  //P2写入pipe3
                printf("P2 finishes writing to pipe3.\n");
                close(d3[1]);  //关闭写
                exit(0);
            }
        }
    } else { //P1执行
        close(d1[0]);  //关闭pipe1 P2的读
        write(d1[1],buff,strlen(buff));  //将用户输入的字符串写入pipe1
        close(d1[1]);  //关闭写
        exit(0);
    }
}

