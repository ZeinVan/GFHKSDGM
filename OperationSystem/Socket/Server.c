//
// Created by Anthony Wong on 2023/4/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>
#define SERVPORT 3333
#define BACKLOG 10
#define MAXDATASIZE 100
int main(){
    int sockfd,client_fd;  //服务端socket标识  客户端socket标识
    struct sockaddr_in my_addr;  //声明套接字变量
    struct sockaddr_in remote_addr;
    int sin_size;
    int recvbytes;
    int i;
    int answer;
    char *delim=",";
    char *p;
    char *str[3];
    char buf[MAXDATASIZE];
    //服务端创建socket
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) {
        perror("error in create socket");
        exit(1);
    }
    //初始化套接字变量
    my_addr.sin_family=AF_INET;
    my_addr.sin_port=htons(SERVPORT);
    my_addr.sin_addr.s_addr=INADDR_ANY;
    bzero(&(my_addr.sin_zero),8);
    //将服务端标识与套接字绑定
    if(bind(sockfd,(struct sockaddr *) &my_addr,sizeof(struct sockaddr))==-1) {
        perror("error in bind");
        exit(1);
    }
    //服务器端通知核心，准备好接收来自客户的连接
    if(listen(sockfd,BACKLOG)==-1) {
        perror("error in listen");
        exit(1);
    }

    while(1) {
        sin_size=sizeof(struct sockaddr_in);
        if((client_fd=accept(sockfd,(struct sockaddr *)&remote_addr,&sin_size))==-1)
//服务器端接收一次客户端发起的连接，返回一个客户端标识
        {
            perror("error in accept");
            continue;
        }
        printf("received a connection from %s\n",inet_ntoa(remote_addr.sin_addr));
//IP地址转换
        if(!fork()) {
            if(send(client_fd,"Server can calculate.Please enter :\n",40,0)==-1)
//向客户端发送消息
            {
                perror("error in send");
                exit(1);
            }
            if((recvbytes=recv(client_fd,buf,MAXDATASIZE,0))==-1)
//接收客户端发来的消息
            {
                perror("error in receive");
                exit(1);
            }
            //字节处理
            buf[recvbytes]='\0';
            str[0]=strtok(buf,delim);
            for(i=1; i<3; i++)
                str[i]=strtok(NULL,delim);

            if(strcmp("+",str[0])==0) { //运算符判断
                answer=atoi(str[1])+atoi(str[2]);  //计算
                //返回结果
                if(send(client_fd,&answer,sizeof(answer),0)==-1) {
                    perror("error in send");
                }
            } else if(strcmp("-",str[0])==0) {
                answer=atoi(str[1])-atoi(str[2]);
                if(send(client_fd,&answer,sizeof(answer),0)==-1) {
                    perror("error in send");
                }
            } else if(strcmp("*",str[0])==0) {
                answer=atoi(str[1])*atoi(str[2]);
                if(send(client_fd,&answer,sizeof(answer),0)==-1) {
                    perror("error in send");
                }
            } else if(strcmp("/",str[0])==0) {
                answer=atoi(str[1])/atoi(str[2]);
                if(send(client_fd,&answer,sizeof(answer),0)==-1) {
                    perror("error in send");
                }
            }
        }
        close(client_fd);  //关闭客户端链接
    }
}


