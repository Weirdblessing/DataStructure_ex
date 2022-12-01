#include "str.h"
int strlen(char *s)
{
    char *p=s;
    int len=0;
    while(*p!='\0')
    {
        len++;
        p++;
    }
    return len;
}

char *strcat(char *s1,char *s2)
{
    char *p=s1,*q=s2;
    while(*p!='\0')
        p++;
    while(*q!='\0')
    {
        *p=*q;
        p++;q++;
    }
    *p='\0';
    return s1;
}

int strcmp(char *s1,char *s2)
{
    char *p=s1,*q=s2;
    while(*p!='\0'&&*q!='\0')
    {
        if(*p>*q) return 1;
        else if(*p<*q) return -1;
        else {p++;q++;}
    }
    if(*p=='\0'&&*q=='\0') return 0;
    if(*p!='\0') return 1;
    if(*q!='\0') return -1;
}

void BF(char S[],char T[])
{int i=0,j=0,start=0,count=0;
cout<<"模式"<<T<<"出现的位置为：";
    while(S[start]!='\0')
    {i=start,j=0;
    while(S[i]!='\0'&&T[j]!='\0')
    {
        if(S[i]==T[j]){i++;j++;}
        else {start++;i=start;j=0;}
    }
    if(T[j]=='\0') {cout<<start+1<<' ';start+=strlen(T);count++;}
    else cout<<"匹配完毕，无对应匹配字符串！"<<endl;
    }
    cout<<"\n模式"<<T<<"出现的次数为："<<count;
}
