//
// Created by Anthony Wong on 2023/4/8.
//
#include<stdio.h>
#include<pthread.h>
#include<math.h>
#include<time.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<errno.h>
#include <unistd.h>

#define RN 3
#define WN 2
int readcount=0;    //readcount和writecount分别用于记录读者和写者的个数
pthread_t Writers[WN];          //写者线程组
pthread_t Readers[RN];          //读者线程组
int mn[10];                //读写序列
int semid;
int rc = 0;              //记录实际已读读者数目
int wc = 0;             //记录实际已写写者数目

union sem_un{int val;struct semid_ds* buf;ushort* array;};  //定义信号量结构
static struct sembuf px={0,-1,0};    //信号量x的down操作，用于控制对readcount的访问
static struct sembuf vx={0,1,0};    //信号量x的up操作，用于控制对readcount的访问
static struct sembuf pz={1,-1,0};   //信号量z的down操作，用于控制读写队列
static struct sembuf vz={1,1,0};    //信号量z的up操作，用于控制读写队列
static struct sembuf pwsem={2,-1,0};  //信号量wsem的down操作，用于读写互斥和写写互斥
static struct sembuf vwsem={2,1,0};   //信号量wsem的up操作，用于读写互斥和写写互斥

void Show(int s, int t_id,int j)     //用于显示读或写的位置和内容
{
    int i;
    printf("Location:%d   Content:%d\n",s,t_id);
    if (j==1)                    //如果是写者，则显示写后的新序列
    {
        printf("now the sequence is:");
        for(i=0;i<10;i++)
        {
            printf("%3d",mn[i]);
        }
        printf("\n");
    }
    printf("\n");
}

void *reader(void *a1)         //读者
{
    int s;     //s用于产生一个随机值作为访问读写序列的序号
    s=rand()%10;
    printf(">>Reader pthread %d creat\n",a1);
    semop(semid,&pz,1);         //对z执行down操作，进入队列
    semop(semid,&px,1);         //获得对readcount的互斥访问权

    if (readcount==0)      //有读者线程，则阻塞写者
        semop(semid,&pwsem,1);
    readcount++;

    semop(semid,&vx,1);    //释放对readcount的互斥访问权
    semop(semid,&vz,1);    //对z的down操作

    printf("Reader %d begin to read, and %d writers %d readers are waiting...\n",a1,WN-wc,RN-rc-1);
    sleep(2);  //读的时间
    printf("Reader %d Read Succeed!\n",a1);
    Show(s+1,mn[s],0);

    semop(semid,&px,1);      //获得对readcount的互斥访问权
    readcount--;
    if (readcount==0)
        semop(semid,&vwsem,1);    //如果没有读者在读，可以让写者进行写操作
    semop(semid,&vx,1);        //释放对readcount的互斥访问权
}

void *writer(void *a2)    //写者
{
    int s;           //s用于产生一个随机值作为访问读写序列的序号
    int newdata;     //newdata为写入的新值，使用rand来产生随机数
    s=rand()%10;
    printf(">>Writer pthread %d creat\n",a2);

    semop(semid,&pwsem,1);       //阻塞其他写者，进行写操作
    printf("Writer %d begin to write, and %d writers %d readers are waiting...\n",a2,WN-wc,RN-rc);
    newdata=rand()%10+1;
    mn[s]=newdata;
    sleep(2);    //写的时间
    printf("Writer %d write Succeed:    ",a2);
    Show(s+1,mn[s],1);
    semop(semid,&vwsem,1);    //写操作完成，允许其他写者进行写操作
}

int main(int argc,char *argv[])
{
    int i;
    int pid;
    int ret;
    union sem_un sem;
    sem.val=1;
    key_t key=ftok("mem",0);

    semid=semget(key,4,IPC_CREAT|0666);   //创建4信号集
    ret=semctl(semid,0,SETVAL,sem);    //初始化信号量0
    if(ret==-1)
    {
        perror("semctl 0:");
    }
    ret=semctl(semid,1,SETVAL,sem);   //初始化信号量1
    if(ret==-1)
    {
        perror("semctl 0:");
    }
    ret=semctl(semid,2,SETVAL,sem);  //初始化信号量2
    if(ret==-1)
    {
        perror("semctl 0:");
    }
    ret=semctl(semid,3,SETVAL,sem);  //初始化信号量3
    if(ret==-1)
    {
        perror("semctl 0:");
    }
    int j;
    for(j=0;j<10;j++)    //初始化读写序列mn[]
    {
        mn[j]=j+1;
    }
    printf("the original sequence is:\n");     //输出原始序列
    for(j=0;j<10;j++)
    {
        printf("%d ",mn[j]);
    }
    printf("\n");
    char c;//选择
    while(1)
    {
        printf("r/w : ");
        scanf("%s",&c);
        if(c == 'w')//选择的是写
        {
            if(wc == WN-1 && rc != RN)//写者已经完成
                printf("writers are finished.\n");
            else//有写者未完成，则写者开始写
            {
                pthread_create(&Writers[wc],NULL,(void *)writer,(void *)(wc + 1));
                wc++;
                sleep(3);
            }
        }
        else if(c == 'r')//选择的是读
        {
            if(rc == RN && wc != WN)//读者已经全部读完
                printf("readers are finished.\n");
            else//读者开始读
            {
                for(rc = 0;rc < RN;rc ++)
                {
                    pthread_create(&Readers[rc],NULL,(void *)reader,(void *)(rc + 1));
                    sleep(3);
                }
            }
        }
        else
            printf("you input a wrong choice,try again:\n");
        if(wc == WN && rc == RN)
        {
            printf("All writers and readers are finished.\n");
            exit(0);
        }
    }
    semctl(semid,IPC_RMID,0);      //删除信号量
    return 0;
}
