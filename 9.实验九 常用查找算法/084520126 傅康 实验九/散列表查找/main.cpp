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
    cout<<"ɢ�б��е�Ԫ��Ϊ��"<<endl;
    for(i=0;i<Max;i++)
        cout<<ht[i]<<" ";
    cout<<endl;
    srand(time(NULL));
    temp = s[rand()%Max];
    cout<<"����Ԫ��"<<temp<<endl;
    if(HashSearch(ht,m,temp,index,count))
    cout<<"���ҳɹ���"<<"\nԪ��"<<temp<<"���±�Ϊ��"<<index<<endl;
    else cout<<"���ݲ����ڣ�"<<endl;
    cout<<"���Ƚ�"<<count<<"��"<<endl;

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
    else if (ht[j]==0) {ht[j]=k;return 0;}//����ʧ�ܣ�����
    i=(j+1)%m;
    while(ht[i]!=0&&i!=j)//��i=j��˵���ƶ�һȦ���ƻ����ˣ���δ�ҵ�λ��
    {
        count++;
        if(ht[i]==k) {j=i;return 1;}
        else i=(i+1)%m;
    }
    if(i==j) {cout<<"���";return 0;}
    else {ht[i]=k;j=i;return 0;}//����ʧ�ܣ�����
}
