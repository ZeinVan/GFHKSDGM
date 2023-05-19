//
// Created by Anthony Wong on 2023/5/5.
//
#include<stdio.h>
#include<stdlib.h>
#include <curses.h>

#define BOOL int
#define TRUE 1
#define FALSE 0
#define MAXSIZE 50

typedef struct{
    int no;
    char str[MAXSIZE];
}Element;

Element ch;
FILE *in,*out;

void scan();
void error(int error);
void P();
void S();
void SS();
void S1();
void S2();
void S3();
void E();
void SS2();
void R();
void T();
void F();
void V();
void W();
void N();

void scan(){
    char buffer;
    int i=0;
    int temp=0;
    do{
        buffer=fgetc(in);
        ch.str[i++]=buffer;
    }while(buffer!=',');
    while(TRUE){
        buffer=fgetc(in);
        if(buffer!='\n'){
            temp=10*temp+buffer-48;
        }
        else
            break;
    }
    ch.no = temp;
    ch.str[--i]='\0';
}

void error(int n){
    switch(n){
        case 1:
            printf("标识符begin错误!");
            break;
        case 2:
            printf("标识符if错误!");
            break;
        case 3:
            printf("标识符then错误!");
            break;
        case 4:
            printf("标识符while错误!");
            break;
        case 5:
            printf("标识符do错误!");
            break;
        case 6:
            printf("标识符end错误!");
            break;
        case 7:
            printf("不是有效的句子!");
            break;
        case 8:
            printf("判断语句出错!");
            break;
        case 9:
            printf("循环语句出错!");
            break;
        case 10:
            printf("不是正确的标识符!");
            break;
        case 11:
            printf("条件表达式错误!");
            break;
        case 12:
            printf("算术表达式错误!");
            break;
        case 18:
            printf("赋值语句错误!");
            break;
        case 28:
            printf("缺少')'!");
            break;
        default:
            printf("Compile failed!");
            break;
    }
    getch();
    exit(1);
}

void P(){

    if(ch.no==1){
        scan();
        S();
        if(ch.no==6)
            scan();
        else
            error(6);
    }
    else
        error(1);
}

void S(){
    SS();
    while(ch.no==26){
        scan();
        SS();
    }
}

void SS(){
    switch(ch.no){
        case 10:
            S1();
            break;
        case 2:
            S2();
            break;
        case 4:
            S3();
            break;
        default:
            error(7);
            break;
    }
}

void S1(){
    V();
    if(ch.no==18){
        scan();
        E();
        fputc(':',out);
        fputc('=',out);
        fputc(' ',out);
    }
    else
        error(18);
}

void S2(){
    if(ch.no==2){
        scan();
        SS2();
        if(ch.no==3){
            scan();
            switch(ch.no)
            {
                case 10:
                case 2:
                case 4:
                    SS();
                    break;
                case 1:
                    P();
                    break;
                default:
                    error(8);
                    break;
            }
            fputc('!',out);
            fputc(' ',out);
        }
        else
            error(3);
    }
    else
        error(2);
}

void S3(){
    if(ch.no==4){
        scan();
        SS2();
        if(ch.no==5){
            scan();
            switch(ch.no){
                case 10:
                case 2:
                case 4:
                    SS();
                    break;
                case 1:
                    P();
                    break;
                default:
                    error(9);
                    break;
            }
            fputc('@',out);
            fputc(' ',out);
        }
        else
            error(5);
    }
    else
        error(4);
}

void V(){
    W();
}

void E(){
    T();
    while(ch.no==13){
        scan();
        T();
        fputc('+',out);
        fputc(' ',out);
    }

    while(ch.no==14){
        scan();
        T();
        fputc('-',out);
        fputc(' ',out);
    }
}

void SS2(){
    int temp;
    E();
    temp=ch.no;
    R();
    E();
    switch(temp){
        case 20:
            fputc('<',out);
            fputc(' ',out);
            break;
        case 21:
            fputc('<',out);
            fputc('>',out);
            fputc(' ',out);
            break;
        case 22:
            fputc('<',out);
            fputc('=',out);
            fputc(' ',out);
            break;
        case 23:
            fputc('>',out);
            fputc(' ',out);
            break;
        case 24:
            fputc('>',out);
            fputc('=',out);
            fputc(' ',out);
            break;
        case 25:
            fputc('=',out);
            fputc(' ',out);
            break;
    }
}

void R(){
    switch(ch.no){
        case 20:
            scan();
            break;
        case 21:
            scan();
            break;
        case 22:
            scan();
            break;
        case 23:
            scan();
            break;
        case 24:
            scan();
            break;
        case 25:
            scan();
            break;
        default:
            error(11);
            break;
    }
}

void W(){
    int i=0;
    if(ch.no==10){
        while(ch.str[i]!='\0')
            fputc(ch.str[i++],out);
        fputc(' ',out);
        scan();
    }
    else
        error(10);
}

void T(){
    F();
    while(ch.no==15){
        scan();
        F();
        fputc('*',out);
        fputc(' ',out);
    }
    while(ch.no==16){
        scan();
        F();
        fputc('/',out);
        fputc(' ',out);
    }
}

void F(){
    switch(ch.no){
        case 10:
            V();
            break;
        case 11:
            N();
            break;
        case 27:
            scan();
            E();
            if(ch.no==28)
                scan();
            else
                error(28);
            break;
        default:
            error(12);
            break;
    }
}

void N(){
    int i=0;
    if(ch.no==11){
        while(ch.str[i]!='\0')
            fputc(ch.str[i++],out);
        fputc(' ',out);
        scan();
    }

    else
        error(12);
}

int main(){
    const char* input="scaned.txt";
    const char* output="compiled.txt";
    if(!(in=fopen(input,"r")))
        error(-1);
    out=fopen(output,"w");
    scan();
    P();
    if(ch.no==0){
        printf("Success!");
        fputc('#',out);
    }
    else
        error(-1);
    fclose(in);
    fclose(out);
    getch();
    return 0;
}