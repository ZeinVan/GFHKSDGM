//
// Created by Anthony Wong on 2023/5/5.
//
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
int id,error=0;
char ch=0;
char c;
int s[100]={0};
int n[100]={0};//记录行
int i=0,j=0,h=1;//h表示行
string w="";
string word="";
ifstream infile("/Users/anthonywong/Documents/Github/GFHKSDGM/PrinciplesOfCompliers/demo.txt",ios::in);
int judge(char d)
{int flag=0;
    if(d>=48&&d<=57)//数字
        flag=1;
    else if((d>=65&&d<=90)||(d>=97&&d<=122))//字母
        flag=2;
    else if(d==' '||d=='\n')
        flag=3;
    else flag=4;
    return flag;
}
void digit()
{
    word=word+ch;
    c=infile.get();
    if(judge(c)==1) {ch=c;digit();}
    else if(judge(c)==2) cout<<"error!"<<endl;
    else
    {id=2;i++;s[i]=id;n[i]=h;
        word="";
        w=w+c;
        void scan();scan();
    }
}
void letter()
{
    word=word+ch;
    c=infile.get();
    if(judge(c)==1||judge(c)==2)
    {ch=c;letter();}
    else {if(word=="if" || word=="else" || word=="then" || word=="begin" || word=="end" || word=="while"||word=="do"||word=="program"||word=="var"||word=="integer"||word=="char"||word=="boolean"||word=="real"||word=="and"||word=="or"||word=="not")
        {if(word=="if")id=11;
            else if(word=="else")id=12;
            else if(word=="then")id=13;
            else if(word=="while")id=14;
            else if(word=="do")id=15;
            else if(word=="begin")id=16;
            else if(word=="end")id=17;
            else if(word=="program")id=18;
            else if(word=="var")id=19;
            else if(word=="integer")id=20;
            else if(word=="char")id=21;
            else if(word=="boolean")id=22;
            else if(word=="real")id=23;
            else if(word=="and")id=43;
            else if(word=="or")id=44;
            else if(word=="not")id=45;
            word="";i++;s[i]=id;n[i]=h;
            w=w+c;
            void scan();scan();
        }
        else {id=1;word="";i++;s[i]=id;n[i]=h;
            w=w+c;void scan();scan();
        }
    }
}
void yuns()
{
    word=word+ch;
    c=infile.get();
    if(c=='=')
    {word=word+c;
        if(word==">=")id=34;
        else if(word==":=")id=32;
        word="";i++;s[i]=id;n[i]=h;void scan();scan();}
    else{if(word==">")id=29;
        else if(word==":")id=41;
        word="";i++;s[i]=id;n[i]=h;
        w=w+c;void scan();scan();
    }
}
void yuns1()
{word=word+ch;
    c=infile.get();
    if(c=='='||c=='>')
    {word=word+c;
        if(word=="<=")id=33;
        else if(word=="<>")id=30;
        word="";i++;s[i]=id;n[i]=h;void scan();scan();}
    else{id=28;word="";i++;s[i]=id;n[i]=h;
        w=w+c;void scan();scan();}
}
void scan()
{if(w!="")
    {ch=c;w="";}
    else
        ch=infile.get();
    while(ch==' '||ch=='\n')
    {if(ch=='\n')h++;
        ch=infile.get();}
    if(judge(ch)==1)//数字
        digit();
    else if(judge(ch)==2) //字母
        letter();
    else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='=')
    { switch(ch)
        {case '+':id=24;break;
            case '-':id=25;break;
            case '*':id=26;break;
            case '=':id=31;break;
            case '/':id=27;break;
        }
        i++;s[i]=id;n[i]=h;scan();}
    else if(ch=='>'||ch==':')
        yuns();
    else if(ch=='<')
        yuns1();
    else if(ch==','||ch==';'||ch=='('||ch==')'||ch=='{'||ch=='}'||ch=='.')
    {switch(ch)
        {case ',':id=35;break;
            case ';':id=36;break;
            case '(':id=37;break;
            case ')':id=38;break;
            case '{':id=39;break;
            case '}':id=40;break;
            case '.':id=42;break;
        }
        i++;s[i]=id;n[i]=h;scan();}

}
void bs()
{if(error==0)
    {
        j++;
        if(s[j]!=19){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少Var"<<endl;error=1;}
        else{     void bldy();
            bldy();//变量定义
            void bs1();bs1();
            j++;
            if(s[j]!=36){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少分号"<<endl;error=1;}
        }
    }
}
void bs1()
{if(error==0)
    {
        if(s[j+1]==35)
        {j++;void bldy();bldy();
            if(s[j+1]==35)bs1();}
    }
}
void bldy()
{ if(error==0)
    {
        j++;
        if(s[j]!=1){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少标识符"<<endl;error=1;}
        else if(s[j+1]!=35)
        {j++;
            if(s[j]!=41){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少冒号"<<endl;error=1;}
            else {void lx();lx();}}
        else {
            void bldy1();bldy1();
            j++;
            if(s[j]!=41){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少冒号"<<endl;error=1;}
            else {void lx();lx();}
        }
    }
}
void bldy1()
{  if(error==0)
    {
        j++;
        if(s[j]!=35){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少逗号"<<endl;error=1;}
        else {
            j++;
            if(s[j]!=1){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少标识符"<<endl;error=1;}
            else if(s[j+1]==41) return;
            else bldy1();
        }

    }
}
void lx()
{if(error==0)
    {
        j++;
        if(s[j]==20||s[j]==21||s[j]==22||s[j]==23)
            return ;
        else {cout<<"error!"<<"第"<<n[j]<<"行"<<"数据类型出错"<<endl;error=1;}
    }
}
void fhyj()
{ if(error==0)
    {
        j++;
        if(s[j]!=16){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少begin"<<endl;error=1;}
        else {
            void yj();yj();
            j++;
            if(s[j]!=36){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少分号"<<endl;error=1;}
            else {
                if(s[j+1]==1||s[j+1]==11)
                {void yj1();yj1();}

                j++;
                if(s[j]!=17){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少end"<<endl;error=1;}
            }
        }
    }
}
void yj()
{if(error==0)
    {
        if(s[j+1]==1){void fzyj();fzyj();}//赋值语句
        else if(s[j+1]==11) {void tjyj();tjyj();}//条件语句
        else {cout<<"error!"<<"第"<<n[j]<<"行"<<"语句类型错误"<<endl;error=1;}
    }
}
void yj1()
{if(error==0)
    {
        yj();
        j++;
        if(s[j]!=36){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少分号"<<endl;error=1;}
        else if(s[j+1]==1||s[j+1]==11)yj1();
    }
}
void fzyj()
{if(error==0)
    {
        j++;
        if(s[j]!=1){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少标识符"<<endl;error=1;}
        else {j++;
            if(s[j]!=32){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少赋值运算符"<<endl;error=1;}
            else {void bds();bds();}//<表达式>
        }
    }
}
void bds()
{if(error==0)
    {
        if(s[j+1]==25)
        {j++;void xg();
            xg();//<项 >
            if(s[j+1]==24||s[j+1]==25)
            {void xg1();xg1();}//{<加法运算符><项>}
        }
        else {void xg();xg();
            if(s[j+1]==24||s[j+1]==25)
            {void xg1();xg1();}}
    }
}
void xg1()
{if(error==0)
    {
        void yun1();yun1();
        void xg();xg();
        if(s[j+1]==24||s[j+1]==25) xg1();
        else return ;
    }
}
void yun1()
{if(error==0)
    {
        j++;
        if(s[j]==24||s[j]==25)return ;
        else {cout<<"error!"<<"第"<<n[j]<<"行"<<"运算符出错"<<endl;error=1;}
    }
}
void xg()
{if(error==0)
    {
        void yz();yz();//<因子>
        if(s[j+1]==26||s[j+1]==27)
        {void yz1(); yz1();}//<乘法运算符><因子>
    }
}
void yz()
{if(error==0)
    {
        j++;
        switch(s[j])
        {case 1:break;
            case 2:break;
            case 37:{bds();j++;if(s[j]!=38){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少反括号"<<endl;error=1;}else return ;};break;
            default: {cout<<"error!"<<"第"<<n[j]<<"行"<<"因式出错"<<endl;error=1;}
        }
    }
}
void yz1()
{if(error==0)
    {
        void yun();
        yun();//<乘法运算符>
        yz();
        if(s[j+1]==26||s[j+1]==27)yz1();
        else return ;
    }
}
void yun()
{if(error==0)
    {
        j++;
        if(s[j]==26||s[j]==27) return;
        else {cout<<"error!"<<"第"<<n[j]<<"行"<<"运算符出错"<<endl;error=1;}
    }
}
void tjyj()
{if(error==0)
    {
        j++;
        j++;
        if(s[j]!=37){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少反括号"<<endl;error=1;}
        else {
            void tj();tj();
            j++;
            if(s[j]!=38){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少反括号"<<endl;error=1;}
            else {j++;
                if(s[j]!=13){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少then"<<endl;error=1;}
                else yj();
                if(s[j+1]==12)
                {j++;
                    yj();
                }
            }
        }
    }
}
void tj()
{if(error==0)
    {
        if(s[j+1]!=37)
        {bds();void yun2();
            yun2();//<关系运算符>
            bds();
        }
        else {j++;bds();
            void yun2();yun2();
            bds();
            j++;
            if(s[j]!=38){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少反括号"<<endl;error=1;}
            else {if(s[j+1]==43||s[j+1]==44||s[j+1]==45)
                {void lbgb();lbgb();}//{<逻辑运算符>(<表达式><关系运算符><表达式>)}
            }
        }
    }
}

void yun2()//关系运算符
{if(error==0)
    {
        j++;
        if(s[j]==28||s[j]==29||s[j]==30||s[j]==33||s[j]==34||s[j]==31)return ;
        else {cout<<"error"<<"第"<<n[j]<<"行"<<"关系运算符出错"<<endl;error=1;}
    }
}
void lbgb()
{if(error==0)
    {
        if(s[j+1]==43||s[j+1]==44||s[j+1]==45)
        {void ljf();ljf();//<逻辑运算符>
            j++;
            if(s[j]!=37){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少反括号"<<endl;error=1;}
            else {
                bds();
                yun2();
                bds();
                j++;
                if(s[j]!=38){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少反括号"<<endl;error=1;}
                else
                if(s[j+1]==43||s[j+1]==44||s[j+1]==45)lbgb();
            }
        }
    }
}
void ljf()
{if(error==0)
    {
        j++;
        if(s[j]==43||s[j]==44||s[j]==45) return;
        else {cout<<"error!"<<"第"<<n[j]<<"行"<<"逻辑符出错"<<endl;error=1;}
    }
}
void parsing()
{j++;
    if(s[j]!=18)
    {cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少program"<<endl;error=1;}
    else {j++;
        if(s[j]!=1){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少标识符"<<endl;error=1;}
        else {j++;
            if(s[j]!=36){cout<<"error!"<<"第"<<n[j]<<"行"<<"缺少分号"<<endl;error=1;}
            else{
                if(s[j+1]==19){bs();fhyj();}//进入变量说明部分
                else if(s[j+1]==16)fhyj();//进入复合语句部分
                else {cout<<"error!"<<"第"<<n[j]<<"行"<<"语句出错"<<endl;error=1; }
                j++;
                if(s[j]!=42&&error==0)cout<<"error!"<<"缺少."<<endl;
                else if(error==0)cout<<"success!"<<endl;}
        }
    }
}
int main()
{
    if(!infile)
    {cerr<<"open /Users/anthonywong/Documents/Github/GFHKSDGM/PrinciplesOfCompliers/demo.txt error!"<<endl;
        exit(1);
    }
    scan();
    parsing();
    //system("pause");
}
