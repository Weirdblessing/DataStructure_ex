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
    cout<<"�����������У�";
    for(i=1;i<=Max;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    InsertSort(b,Max);
    cout<<"ִ��ֱ�Ӳ��������Ԫ��Ϊ��";
    for(i=1;i<=Max;i++)
        cout<<b[i]<<" ";
    cout<<endl;
    cout<<"ֱ�Ӳ�������ıȽϴ����ǣ�"<<c<<endl;
    cout<<"ֱ�Ӳ���������ƶ������ǣ�"<<m<<endl;
    c=0,m=0;
    cout<<"�����������У�";
    for(i=1;i<=Max;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    ShellSort(a,Max);
    cout<<"ִ��ϣ�������Ԫ��Ϊ��";
    for(i=1;i<=Max;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"ϣ������ıȽϴ����ǣ�"<<c<<endl;
    cout<<"ϣ��������ƶ������ǣ�"<<m<<endl;
    return 0;
}

void Creat(int r[],int n)
{
    int i=0;
    srand(time(NULL));
    for(i=1;i<=n;i++)
        r[i]=1+rand()%100;
}

void InsertSort(int r[],int n)//0�ŵ�Ԫ��Ϊ�ݴ浥Ԫ�ͼ�����
{
    int j;
    for(int i=2;i<=n;i++)
    {
        r[0]=r[i];                  //�ݴ����ؼ��룬�����ڱ�
        for(j=i-1;r[0]<r[j];j--)    //Ѱ�Ҳ���λ�ã���i-1��ʼ˳�����
            {r[j+1]=r[j];
            c++;m++;}              //��¼����,һֱ��r[0]>=r[j]�����ҵ���r[0]��С�ģ���ʱ������ѭ���������ʹ˽���ѭ��
        r[j+1]=r[0];c++;m+=2;          //������ҵ�����С�ģ�������r[0]����;��ĳ�����嵽��ʱ��λ
    }
}

void ShellSort(int r[],int n)          //0�����ݴ浥Ԫ
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

