#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int Max=100;
void Creat(int r[],int n);
void InsertSort(int r[],int n);
void ShellSort(int r[],int n);
int c=0,m=0;


int main()
{

    int a[Max+1]={0},b[Max+1]={0};
    int i=0;
    Creat(a,Max);
    for(i=1;i<=Max;i++)
        b[i]=a[i];
    cout<<"对于无序序列：";
    for(i=1;i<=Max;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    InsertSort(b,Max);
    cout<<"执行直接插入排序后，元素为：";
    for(i=1;i<=Max;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    cout<<"直接插入排序的比较次数是："<<c<<endl;
    cout<<"直接插入排序的移动次数是："<<m<<endl;
    c=0,m=0;
    cout<<"对于无序序列：";
    for(i=1;i<=Max;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    ShellSort(a,Max);
    cout<<"执行希尔排序后，元素为：";
    for(i=1;i<=Max;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"希尔排序的比较次数是："<<c<<endl;
    cout<<"希尔排序的移动次数是："<<m<<endl;
    return 0;
}

void Creat(int r[],int n)
{
    int i=0;
    srand(time(NULL));
    for(i=1;i<=n;i++)
        r[i]=1+rand()%100;
}

void InsertSort(int r[],int n)//0号单元作为暂存单元和监视哨
{
    int j;
    for(int i=2;i<=n;i++)
    {
        r[0]=r[i];                  //暂存待插关键码，设置哨兵
        for(j=i-1;r[0]<r[j];j--)    //寻找插入位置，从i-1开始顺序查找
            {r[j+1]=r[j];
            c++;m++;}              //记录后移,一直到r[0]>=r[j]，即找到比r[0]更小的，此时不满足循环条件，就此结束循环
        r[j+1]=r[0];c++;m+=2;          //将最后找到的最小的，无论是r[0]或中途的某个数插到此时空位
    }
}

void ShellSort(int r[],int n)          //0号作暂存单元
{
    int j;
    for(int d=d/2;d>=1;d=d/2)
    {
        for(int i=d+1;i<=n;i++)
        {
            r[0]=r[i];
            for(j=i-d;j>0&&r[0]<r[j];j=j-d)
                {r[j+d]=r[j];c++,m++;}
            r[j+d]=r[0];c++;m+=2;
        }
    }
}

