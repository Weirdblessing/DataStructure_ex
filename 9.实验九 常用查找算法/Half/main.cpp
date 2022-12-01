#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
const int Max=10;
void Creat(int a[]);
int BinSearch(int r[],int n,int k,int &count);
int main()
{
    int a[Max+1]={0};
    int location =0,count=0,k;
    Creat(a);
    for(int i=1;i<=Max;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    k=a[1+rand()%Max];
    location =BinSearch(a,Max,k,count);
    if(k!=0)
    {cout<<"元素"<<k<<"在序列中的序号是"<<location;
    cout<<",共比较"<<count<<"次"<<endl;}
    else cout<<"数据不存在,\n-共比较"<<count<<"次"<<endl;
    return 0;
}

void Creat(int a[])
{
    srand(time(NULL));
    a[0]=0;
    for(int i=1;i<=Max;i++)
        {a[i]=a[i-1]+rand()%Max;
        for(int j=1;j<i;j++)
            if(a[i]==a[j]) i--;
        }
}

int BinSearch(int r[],int n,int k,int &count)
{
    int low=1,high=n;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        count++;
        if(k<r[mid]) high=mid-1;
        else if(k>r[mid]) low=mid+1;
        else return mid;
    }
    return 0;
}
