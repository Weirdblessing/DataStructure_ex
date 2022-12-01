#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
//#include <set> 数据量大的时候可以尝试，优点是不重复，但同时也会自动弱排序
const int Max =10;
void Creat(int a[]);
int SeqSearch(int r[],int n,int k,int &count);

int main()
{
    int a[Max+1]={0};
    int location=0,count=0,k;
    Creat(a);
    for(int i=1;i<=Max;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    k=1+rand()%Max;
    location=SeqSearch(a,Max,k,count);
    if(location!=0)
    cout<<"元素"<<k<<"在序列中的序号是"<<location;
    else cout<<"数据不存在"<<endl;
    cout<<",共比较"<<count<<"次"<<endl;
    return 0;
}

/*void Creat(int a[])
{
    srand(time(NULL));
    set <int> s;
    while(s.size()<Max)
    {
        s.insert(1+rand()%Max);
    }
   int i=1;
    for(set<int>::iterator iter=s.begin();(iter!=s.end())&&(i<=Max);++iter,i++)
        a[i]=*iter;
}*/

void Creat(int a[])
{
    srand(time(NULL));
    for(int i=1;i<=Max;i++)
        {a[i]=1+rand()%Max;
        for(int j=1;j<i;j++)
            if(a[i]==a[j]) i--;
        }

}

int SeqSearch(int r[],int n,int k,int &count)
{
    int i=n;
    r[0]=k;
    while(++count&&r[i]!=k)
        i--;
    return i;
}
