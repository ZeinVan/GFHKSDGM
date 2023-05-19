//
// Created by Anthony Wong on 2023/5/19.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct block { //定义一个内存块的结构体
    int size;      	//块的大小
    int start;      //块的起始位置
    int loc;	//是否占用
    struct block *next;  //指向下一个块的指针
    struct block *prior;  //指向前一个块的指针
} block;
int maxsize=512;  //可分配的内存空间总量
block *note;  //初始化的结点
block *id[10];	 //链表头的数组

//打印内存状态函数
void printmem() {
    int i;
    for(i=9; i>=0; i--) {
        printf("%d  ->",i);
        block * temp = (struct block *)malloc(sizeof(struct block));
        temp = id[i]->next;
        while(temp!=NULL) {
            printf("%d(%s)(%d)->",temp->size,temp->loc==1?"占用":"空闲",temp->start);
            //输出内存块的大小、状态、起始位置
            temp=temp->next;
        }
        printf("\n");
    }
}

//初始化
void init() {
    int i;
    for(i=0; i<9; i++) {
        id[i]=(struct block *)malloc(sizeof(struct block));
        id[i]->prior=id[i];
        id[i]->next=NULL;
    }
    note=(struct block *)malloc(sizeof(struct block));
    note->size=maxsize;
    note->start=0;
    note->loc=0;
    note->next=NULL;
    id[9]=(struct block *)malloc(sizeof(struct block));
    id[9]->next=note;
    id[9]->prior=id[9];
    note->prior=id[9];
    printmem();
}

int power(int x,int y) { //计算x的y次幂
    int k=0,tmp=1;
    for(; k<y; k++) {
        tmp=tmp*x;
    }
    return tmp;
}

int root(int x,int y) { //计算y的开x次方
    int result=y,count=0;
    while(result!=1) {
        result=result/x;
        count++;
    }
    return count;
}

//对内存块进行拆分
int split(int tempId) {

    block * pend=(struct block *)malloc(sizeof(struct block));  //被拆分结点
    block * cend=(struct block *)malloc(sizeof(struct block));  //挂载点
    //拆分后的第二个结点
    block * newf=(struct block *)malloc(sizeof(struct block));
    //拆分后的第一个结点
    block * newu=(struct block *)malloc(sizeof(struct block));
    pend=id[tempId]->next;
    int flag=0,isFirst=0;
    while(pend!=NULL) {
        if(pend->loc==0) { //可拆分
            //卸载被拆分结点
            if(isFirst==0) {
                id[tempId]->next=pend->next;
            } else {
                pend->prior->next=pend->next;
            }
            //拆分后的结点初始化
            int size=(pend->size)/2;
            int start=pend->start;
            newu->size=size;
            newu->start=start;
            newf->start=start+size;
            newu->loc=0;
            newf->size=size;
            newf->loc=0;
            newf->prior=newu;
            newu->next=newf;
            newf->next=NULL;

            tempId--;
            cend=id[tempId];
            while(cend->next!=NULL) {
                cend=cend->next;
            }
            cend->next=newu;  //将拆分后的结点进行挂载
            newu->prior=cend;
            flag=1;
            return 1;
        } else {
            pend=pend->next;
            isFirst++;
        }
    }

    if(flag==0) {
        tempId=tempId+1;
        if(tempId<=9) {
            free(pend);
            free(cend);
            free(newu);
            free(newf);
            split(tempId);
        } else {
            return -1;
        }
    }
}

//归并
int merge(int tempId,block *first) {
//合并后的结点
    block * merger=(struct block *)malloc(sizeof(struct block));
    block * second=NULL;  //查找可合并的结点

    second=id[tempId]->next;
    int nextStart=first->start+first->size;
    int preStart=first->start-first->size;
    int flag=0,isFirst=0;
    while(second!=NULL) {

        if((second->start==nextStart || second->start==preStart) &&
           second->loc==0) {

            //初始化合并后的结点
            merger->size=(first->size)+(second->size);
            merger->loc=0;
            merger->start=(first->start)<(second->start)?(first->start):(second->start);

            //卸载可合并的结点
            if(first->next!=NULL) {
                first->next->prior=first->prior;
            }
            if((first->prior->prior)==first->prior) {
                id[tempId]->next=first->next;
            } else {
                first->prior->next=first->next;
            }
            if(second->next!=NULL) {
                second->next->prior=second->prior;
            }
            if(isFirst==0) {
                id[tempId]->next=second->next;
            } else {
                second->prior->next=second->next;
            }

            //挂载合并后的结点
            tempId++;
            merger->next=id[tempId]->next;
            merger->prior=id[tempId];
            if(id[tempId]->next!=NULL) id[tempId]->next->prior=merger;
            id[tempId]->next=merger;
            if(tempId<9) {
                merge(tempId,merger);
            } else {
                return 0;
            }
            return 1;

        } else {
            second=second->next;
            isFirst++;
        }
    }
    return 1;
}

//内存释放
int freeb(int size) {
    block * first=(struct block *)malloc(sizeof(struct block));
    int tempId=root(2,size);
    first=id[tempId]->next;
    int flag=0;
    while(first!=NULL) {
        if(first->loc==1) {
            first->loc=0;
            flag=1;
            break;
        } else {
            first=first->next;
        }
    }
    if(flag==1) {
        merge(tempId,first);  //归并
        printmem();
    } else {
        printf("需要释放的内存块不存在!\n");
    }
    return 1;
}

int requestb(int size) { //申请size个页面
    block * temp=(struct block *)malloc(sizeof(struct block));
    int tempId = root(2,size);
    int flag=0;
    temp=id[tempId]->next;
    while(temp!=NULL) {
        if(temp->loc==0 && temp->size==size) { //分配
            temp->loc=1;
            flag=1;
            printf("分配成功!\n");
            printmem();
            return 1;
        } else {
            temp=temp->next;
        }
    }
    if(flag==0) {
        tempId++;

        if(tempId<=9) {
            int rs=split(tempId);
            if(rs==-1) {
                printf("没有合适的空间可分配!\n");
                return -1;
            } else {
                requestb(size);
            }
        } else {
            printf("没有合适的空间可分配!\n");
            return -1;
        }
    }
    free(temp);
}

int main() {
    init();
    int flag=1;  //是否继续
    int size;  //申请/释放内存大小（2的次幂）
    char order;  //操作命令，r申请，f释放
    do {
        printf("请输入命令:(以空格相隔,示例:r 8)\n");
        scanf("%c %d",&order,&size);
        if(order=='r') { //申请内存
            requestb(size);
        } else if(order=='f') { //释放内存
            freeb(size);
        } else {
            printf("error!");
        }
        printf("是否继续?(1继续，0退出):");
        scanf("%d",&flag);
        getchar();
    } while(flag==1);
}
