//
// Created by Anthony Wong on 2023/4/14.
//
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#define SERVPORT 3333
#define MAXDATASIZE 100
int main(int argc,char *argv[]) {
    int sockfd,recvbytes;  //客户端套接字标识，接收消息标识
    char buf[MAXDATASIZE];  //建立消息缓冲区
    struct hostent *host;
    struct sockaddr_in serv_addr;  //声明套接字
    while(1) {
        if(argc<2) {
            fprintf(stderr,"Please enter :\n");
            //exit(1);
        }

        /*if((host=gethostbyname(argv[1]))==NULL) {
            herror("error in get host by name");
            //exit(1);
        }*/
//创建客户端Socket
        if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) {
            perror("error in create socket");
            //exit(1);
        }
        //初始化客户端套接字
        serv_addr.sin_family=AF_INET;
        serv_addr.sin_port=htons(SERVPORT);
        if(host)
            serv_addr.sin_addr=*((struct in_addr *)host->h_addr);
        bzero(&(serv_addr.sin_zero),8);
        //客户端向服务端发起一次连接
        if(connect(sockfd,(struct sockaddr *) &
                serv_addr,sizeof(struct sockaddr ) )== -1) {
            perror("error in connect");
            exit(1);
        }
        //从服务端接收连接消息
        if((recvbytes=recv(sockfd,buf,MAXDATASIZE,0))==-1) {
            perror("error in receive");
            exit(1);
        }
        //字节转换
        buf[recvbytes]='\0';
        printf("Receive:%s",buf);
        scanf("%s",buf);
        buf[strlen(buf)]='\0';
        //客户端发送计算类型及参数
        if(send(sockfd,buf,MAXDATASIZE,0)==-1) {
            perror("error in send");
            exit(1);
        }
        //接收计算结果
        int result=0;
        if((recvbytes=recv(sockfd,&result,sizeof(result),0))==-1) {
            perror("error in receive");
            exit(1);
        }
        if(buf[0]=='q') break;
        printf("The answer is :%d\n",result);
        close(sockfd);  //关闭客户端套接字
    }
}

