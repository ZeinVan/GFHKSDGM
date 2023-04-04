//
// Created by Anthony Wong on 2023/4/1.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
#include<sys/time.h>

//定义进程结构信息
typedef struct pcbStruct {
    int pid;           //进程id
    char name[10];    //进程名称
    int status;        //进程状态 1－运行  2－就绪  3－等待 0－完成
    int type;         //进程类别 0－系统 进程 1－用户进程
    int res;          //进程需要资源的时间点
    int totalTime;    //进程占用cpu的时间
    int runTime;     //进程执行的时间
    int count;       //进程运行时间计数器
    int prio;         //进程优先级
    struct pcbStruct *next;     //链指针
} PCB;


//定义资源结构
typedef struct resStruct {
    int pid;    //占用进程id
    int free;    //是否可用，1：可用 0：不可用
} Resource;


Resource resource;
PCB *finish,*ready,*tail,*run,*waiter,*head;//队列指针

int N;                     //进程数
int timeSlice=2;     //时间片
int hodeUpTime=5;    //占用资源的时间
int changePrio=0;    //改变优先数的时刻
void sort();    //声明排序函数
void changeRunPrio();    //改变run的优先级函数声明
void changeReadyPrio(); //改变ready的优先级函数声明
int randomPrio(double from,double to) {//产生from到to之间的随机数
    return 1+(int)((to)*rand()/(RAND_MAX+from));
}
runIn() {
    run=ready;
    if(run!=NULL){
    run->status=1;
    ready=ready->next;}

}
readyIn() {
    waiter->status=2;
    tail->next=waiter;
    waiter=waiter->next;

}

//标题输出函数
void print1( ) {
    printf("------------------------------------------------------\n");
    printf("进程号  名称  状态  类别  优先级 res   预期时间   计数器 执行时间\n");
}

//进程PCB的输出
void print2(PCB *q) {
    printf("%d｜ %-4s｜%-4d｜%-4d｜%-4d｜%-4d｜%-8d｜%-5d｜%-d\n",q->pid,q->name,q->status,q->type,q->prio,q->res,q->totalTime,q->count,q->runTime);
}

//输出函数
void print() {
    PCB *p;
    if(ready!=NULL)sort();//按优先数排序
    if(run!=NULL) {
        printf("运行队列：\n");
        print2(run); //输出当前正在运行的PCB
    }
    p=ready;
    if(p!=NULL) printf("就绪队列：\n");//输出就绪队列的PCB
    while(p!=NULL) {
        print2(p);
        p=p->next;
    }
    p=waiter;
    if(p!=NULL)printf("等待队列：\n");//输出等待队列的PCB
    while(p!=NULL) {
        print2(p);
        p=p->next;
    }
    p=finish;
    if(p!=NULL)printf("完成队列：\n");//输出完成队列的PCB
    while(p!=NULL) {
        print2(p);
        p=p->next;
    }
    print1();
}

insertReady(PCB *p2) {//轮转法插入就绪队列函数
tail->next=p2;
tail=p2;
p2->next=NULL;
}

insertWait(PCB *p2) {//轮转法插入等待队列函数
head->next=p2;
head=p2;
p2->next=NULL;
}

void creat() {//轮转法创建进程PCB
    PCB *p;
    int i,time;
    char na[10];
    ready=NULL;       //就绪队列头指针
    finish=NULL;      //完成队列头指针
    run=NULL;         //运行队列指针
    waiter=NULL;		//等待队列指针
    printf("输入进程名和进程时间 : \n");
    for(i=1; i<=N; i++) {
        p=malloc(sizeof(PCB));
        p->pid=1000+i;
        scanf("%s %d",na,&time);
        strcpy(p->name,na);
        p->status=2;//进程状态初始为就绪状态
int n=randomPrio(1.0,9.0);
        int m=randomPrio(1.0,9.0);
        if(i%2==0) {//系统进程

            p->type=0;
            p->prio=randomPrio(1.0,9.0);//系统进程优先级
            //if(i==2)
             //   p->prio=6;
        } else {//用户进程
            p->type=1;
            p->prio=randomPrio(11.0,19.0); //用户进程优先级
            //if(i==1)
           //     p->prio=11;
        }
        p->res=time/2;
        p->totalTime=time;
        p->count=0;
        p->runTime=0;
        if(ready!=NULL)
            insertReady(p);
        else {
            p->next=ready;
            ready=p;
            tail=p;
        }


    }
    printf("************************调度开始************************\n");
    print1();
    print();
    run=ready;
    ready=ready->next;
    run->status=1;
}
PCB *p;
void printwait(){
    PCB *begin;
    begin=waiter;
    printf("此时的等待序列是： ");
    while(waiter!=NULL){
    printf("%d ",waiter->pid);
    waiter=waiter->next;}
    printf("\n");
    waiter=begin;
}
void printrun(){
    printf("此时的运行队列：");
    if(run!=NULL)
    printf("%d\n",run->pid);
}
void printready(){
    PCB *temp,*begin;
    begin=ready;
    printf("此时的就绪序列是： ");
    while(ready!=NULL){

        printf("%d ",ready->pid);
        ready=ready->next;}
    printf("\n");
    ready=begin;
}
int ERRORSTATEMENT=0;
void judge(){
    if(!ERRORSTATEMENT){
        run->runTime=run->runTime+1;
        run->count=run->count+1;
        ERRORSTATEMENT=1;
    }
}
prioChangerun() {
    while(run!=NULL) {
        if(run->res==run->runTime) {    resource.pid=run->pid;  resource.free=0;
        } else {    judge();    run->count=0;   run->status=3;  p=run;
            if(waiter!=NULL)    insertWait(p);
            else {  p->next=waiter;     waiter=p;   head=p;}    print();
            if(ready==NULL&&waiter!=NULL){
                ready=waiter;   waiter=waiter->next;    ready->next=NULL;   tail=ready; }   runIn();
            //printwait();
            //printready();
            //printrun();
        }
        if(ready==NULL&&waiter!=NULL){  ready=waiter;   waiter=waiter->next;    ready->next=NULL;   tail=ready;}
        run->runTime=run->runTime+1;    run->count=run->count+1;    changePrio++;
        if(changePrio%2 == 0) { changeRunPrio();    changeReadyPrio();  }
        //printwait();
        //printready();
        //printrun();
        if((run->runTime-run->res)>=hodeUpTime) resource.free=1;
        if(ready==NULL&&waiter!=NULL){  insertReady(waiter);    waiter=waiter->next;
            //ready->next=NULL;
        }
        if(run->runTime>=run->totalTime) {  if(run->pid==resource.pid)  resource.free=1;
            run->next=finish;   finish=run; run->status=0;  run=NULL;
            if(ready!=NULL) runIn();
        } else if(run->count==timeSlice)   {    run->count=0;
            if(ready!=NULL) {   run->status=2;
                //printwait();
                //printready();
                //printrun();
                insertReady(run);
                //printwait();
                //printready();
                //printrun();
                runIn();
                //printwait();
                //printready();
                //printrun();
            }
        }
        if(ready!=NULL) {   if(run->prio>ready->prio) {
                //run->count=0;
                if(ready!=NULL) {run->status=2; insertReady(run);   runIn();}}}
        if(resource.free==1) {  if(waiter!=NULL) {  waiter->status=2;
                //insertReady(waiter);
                //readyIn();
                if(ready!=NULL) {   insertReady(waiter);    waiter=waiter->next;    }
                else {  ready=waiter;   tail=waiter;    waiter=waiter->next;    ready->next=NULL;}
                //waiter=waiter->next;
                //printwait();
                //printready();
                //printrun();
            }
        }print();}}

void changeRunPrio() {
    if(run->prio<20)
        run->prio += 1;
}

void changeReadyPrio() {
    PCB * p;    p=ready;
    if(p!=NULL) {
        do {
            if(p->type==0) {
                if(p->prio>-20) p->prio -= 2;
            } else {
                if(p->prio>0)   p->prio -= 2;
            }p=p->next;
        } while(p!=NULL);
    }
}
void sort() {
    PCB *p,*min;    min=ready;  p=ready;
    while(p->next!=NULL) {
        if(min->prio > p->next->prio) {
            min=p->next;    p->next=p->next->next;  min->next=ready;    ready=min;
        } else {    if(p->next!=NULL)   p=p->next;  }}p=ready;
    while(p->next!=NULL)    p=p->next;  tail=p;
}
int main() {
    resource.free=1;    printf("输入进程数量：");  scanf("%d",&N);
    creat();    prioChangerun();
}