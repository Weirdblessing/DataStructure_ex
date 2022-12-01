#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int Max=100;
void Creat(int r[],int n);
void SelectSort(int r[],int n);
void Sift(int r[],int k,int m);
void HeapSort(int r[],int n);
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
    SelectSort(b,Max);
    cout<<"执行简单选择排序后，元素为：";
    for(i=1;i<=Max;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    cout<<"简单排序的比较次数是："<<c<<endl;
    cout<<"简单排序的移动次数是："<<m<<endl;
    c=0,m=0;
    cout<<"对于无序序列：";
    for(i=1;i<=Max;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    HeapSort(a,Max);
    cout<<"执行堆排序后，元素为：";
    for(i=1;i<=Max;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"简单排序的比较次数是："<<c<<endl;
    cout<<"简单排序的移动次数是："<<m<<endl;
    return 0;
}

void Creat(int r[],int n)
{
    int i=0;
    srand(time(NULL));
    for(i=1;i<=n;i++)
        r[i]=1+rand()%100;
}

void SelectSort(int r[],int n)
{
    for(int i=1;i<n;i++)
    {
        int index=i;
        for(int j=1+i;j<=n;j++)
            if(r[j]<r[index]) {index=j;c++;}
        if(index!=i)
        {
            r[0]=r[i];r[i]=r[index];r[index]=r[0];
            m+=3;
        }
    }
}

void Sift(int r[],int k,int m)
{
    int i=k,j=2*i;
    while(j<=m)
    {
        if(j<m&&r[j]<r[j+1]) {j++;c++;}
        if(r[i]>r[j]) {c++;break;}
        else
        {
            r[0]=r[i];r[i]=r[j];r[j]=r[0];
            i=j;j=2*i;
            m+=3;
        }
    }
}

void HeapSort(int r[],int n)
{
    int i=0;
    for(i=n/2;i>=1;i--)
        Sift(r,i,n);
    for(i=1;i<n;i++)
    {
        r[0]=r[1];r[1]=r[n-i+1];r[n-i+1]=r[0];
        m+=3;
        Sift(r,1,n-i);
    }
}
