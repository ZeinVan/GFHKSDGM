//
// Created by Anthony Wong on 2023/3/28.
//
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
using namespace std;

const char *FILENAME = "../demo.txt";

struct Word {
    int num; ///词所属种类
    char w[10]; ///词的属性值
};

char KEYWORDS[30][10]= {
        "var","integer","longint","bool","if","then","else","while","do","for","begin","end",
        "and","or","+","-","*","/","==", "<>", "<",">","<=",">=",":=","(",")",",",";",":"
};

bool IsIDLegal(char* c) { ///判断标识符是否合法
    if(strlen(c)>10)
        return false;
    for(int i=0; i<strlen(c); i++) {
        if(!isalpha(c[i]))
            return false;
    }
    return true;
}

bool IsNumLegal(char* num) { ///判断常数是否合法
    for(int i=0; i<strlen(num); i++) {
        if(!isdigit(num[i]))
            return false;
    }
    return true;
}

void Show() {
    FILE *fp;
    char ch;
    fp=fopen(FILENAME, "r");
    if(!fp) {
        printf("Error: %s !\n", FILENAME);
        exit(1);
    }
    printf("接收到的代码如下:\n");
    while((ch=fgetc(fp))!=EOF) {
        putchar(ch);
    }
    fclose(fp);
    cout<<endl<<"词法分析如下："<<endl;
}

void A() {
    char ch;
    char word_temp[30]="";  ///缓存区
    int i=0, j=0, k=0, key=0, flag=0;
    FILE *fp;
    Word word[100]; ///创建词对象
    Show();
    fp=fopen(FILENAME, "r");
    while((ch=fgetc(fp)) != EOF) { ///独立子程序，每次只读取一个单词，直至文件末尾
        if(isalnum(ch)) { ///判断字母、数字
            word_temp[key++] = ch;  ///添加字母、数字序列
            word_temp[key] = '\0';
            continue;
        } else {
            if(strcmp(word_temp, "")!=0) {
                strcpy(word[i].w, word_temp); ///将字母、数字序列拷贝到结构数组中
                strcpy(word_temp, ""); ///临时数组置空
                key=0; ///回到临时数组的开始位置
                i++; ///结构数组的下标加1
            }
            if(ch==' '|| ch==10 || ch==13 || ch=='	') ///去掉空格、回车、换行和制表符
                continue;
            else { ///判断特殊符号组合、算符/界符
                word_temp[0] = ch, flag = 0;
                if(word_temp[0]=='>'|| word_temp[0]=='<'||word_temp[0]==':'||word_temp[0]=='=')
                    ch=fgetc(fp), flag = 1;
                if((ch=='='&&flag)||(word_temp[0]=='<' && ch=='>'))
                    word_temp[1]=ch, word_temp[2]='\0';
                else
                    word_temp[1]='\0';
                strcpy(word[i].w, word_temp); ///将非字母、数字符号序列拷贝到结构数组中
                strcpy(word_temp, "");
                key=0, i++;
            }
        }
    }
    ///分类别
    for(j=0; j<i; j++) {
        for(k=0; k<30; k++) {
            if((strcmp(word[j].w, KEYWORDS[k]))==0) {
                if(k>=0 && k<14)
                    word[j].num=1; ///关键字
                else if(k>=10 && k<30)
                    word[j].num=k; ///算符/界符
                break;
            } else if(IsIDLegal(word[j].w))
                word[j].num=2; ///标识符
            else if(IsNumLegal(word[j].w))
                word[j].num=3; ///常数
            else
                word[j].num=0; ///无法识别
        }
    }
    for(j=0; j<i; j++) { ///格式化打印输出, 即(种类, 属性值)
        if(word[j].num == 1)
            printf("%s\t%s\n", word[j].w,"关键字");
        else if(word[j].num == 2)
            printf("%s\t%s\n", word[j].w, "标识符");
        else if(word[j].num == 3)
            printf("%s\t%s\n", word[j].w, "常数");
        else if(word[j].num == 0)
            printf("%s\t%s\n", word[j].w, "ERROR");
        else {
            if(!(strcmp("+", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "加号");
            else if(!(strcmp("-", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "减号");
            else if(!(strcmp("*", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "乘号");
            else if(!(strcmp("/", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "除号");
            else if(!(strcmp("==", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "等于号");
            else if(!(strcmp("<>", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "不等于号");
            else if(!(strcmp("<", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "小于号");
            else if(!(strcmp(">", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "大于号");
            else if(!(strcmp("<=", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "小于等于号");
            else if(!(strcmp(">=", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "大于等于号");
            else if(!(strcmp(":=", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "赋值符号");
            else if(!(strcmp("(", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "左括号");
            else if(!(strcmp(")", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "右括号");
            else if(!(strcmp(",", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "逗号");
            else if(!(strcmp(";", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "分号");
            else if(!(strcmp(":", KEYWORDS[word[j].num])))
                printf("%s\t%s\n",  word[j].w, "冒号");
            else
                printf("%s\t%s\n",  word[j].w, "ERROR");
        }
    }
    fclose(fp); ///关闭文件
}

int main() {
    A();
    return 0;
}
