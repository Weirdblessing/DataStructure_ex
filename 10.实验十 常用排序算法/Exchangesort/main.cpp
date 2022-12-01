#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int Max=100;
void Creat(int r[],int n);
void BubbleSort(int r[],int n);
int Partition(int r[],int first,int end);
int QuickSort(int r[],int first,int end);
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
    BubbleSort(b,Max);
    cout<<"执行起泡排序后，元素为：";
    for(i=1;i<=Max;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    cout<<"起泡排序的比较次数是："<<c<<endl;
    cout<<"起泡排序的移动次数是："<<m<<endl;
    c=0,m=0;
    cout<<"对于无序序列：";
    for(i=1;i<=Max;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    QuickSort(a,1,Max);
    cout<<"执行快速排序后，元素为：";
    for(i=1;i<=Max;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"快速排序的比较次数是："<<c<<endl;
    cout<<"快速排序的移动次数是："<<m<<endl;
    return 0;
}

void Creat(int r[],int n)
{
    int i=0;
    srand(time(NULL));
    for(i=1;i<=n;i++)
        r[i]=1+rand()%100;
}

void BubbleSort(int r[],int n)
{
    int exchange=n,bound=n;
    while(exchange!=0)
    {
        bound=exchange;exchange=0;
        for(int j=1;j<bound;j++)
            if(r[j]>r[j+1])
        {
            r[0]=r[j];r[j]=r[j+1];r[j+1]=r[0];
            m+=3;
            exchange=j;
        }
        c++;
    }
}

int Partition(int r[],int first,int end)
{
    int i=first,j=end;
    while(i<j)
    {
        while(i<j&&r[i]<=r[j]) {j--;c++;}
        if(i<j)
        {
            r[0]=r[i];r[i]=r[j];r[j]=r[0];
            i++;m+=3;
        }
        while(i<j&&r[i]<=r[j]) {i++;c++;}
        if(i<j)
        {
            r[0]=r[i];r[i]=r[j];r[j]=r[0];
            j--;
            m+=3;
        }
    }
    return i;
}

int QuickSort(int r[],int first,int end)
{
    if(first<end)
    {
        int pivot=Partition(r,first,end);
        QuickSort(r,first,pivot-1);
        QuickSort(r,pivot+1,end);
    }
}
