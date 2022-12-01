#include <iostream>

using namespace std;
#include <stdlib.h>
#include <time.h>
const int Max=1000,m=997;
void Creat(int s[]);
int HashSearch(int ht[],int m,int k,int &j,int &count);

int main()
{
    int ht[Max]={0},s[Max]={0};
    Creat(s);
    int temp,i=0,index=0,count=0;
    for(i=0;i<Max;i++)
        HashSearch(ht,Max,s[i],index,count);
    cout<<"散列表中的元素为："<<endl;
    for(i=0;i<Max;i++)
        cout<<ht[i]<<" ";
    cout<<endl;
    srand(time(NULL));
    temp = s[rand()%Max];
    cout<<"查找元素"<<temp<<endl;
    if(HashSearch(ht,m,temp,index,count))
    cout<<"查找成功！"<<"\n元素"<<temp<<"的下标为："<<index<<endl;
    else cout<<"数据不存在！"<<endl;
    cout<<"共比较"<<count<<"次"<<endl;

    return 0;
}

void Creat(int s[])
{
    srand(time(NULL));
    for(int i=0;i<Max;i++)
    {
        s[i]=1+rand()%Max;
        for(int j=0;j<i;j++)
            if(s[j]==s[i]) i--;
    }
}

int HashSearch(int ht[],int m,int k,int &j,int &count)
{
    int i;
    j=k % m;
    count=1;
    if(ht[j]==k) return 1;
    else if (ht[j]==0) {ht[j]=k;return 0;}//查找失败，插入
    i=(j+1)%m;
    while(ht[i]!=0&&i!=j)//若i=j，说明移动一圈又移回来了，并未找到位置
    {
        count++;
        if(ht[i]==k) {j=i;return 1;}
        else i=(i+1)%m;
    }
    if(i==j) {cout<<"溢出";return 0;}
    else {ht[i]=k;j=i;return 0;}//查找失败，插入
}
