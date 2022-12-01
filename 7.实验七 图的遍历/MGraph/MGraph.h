#ifndef MGRAPH_H_INCLUDED
#define MGRAPH_H_INCLUDED
#include <iostream>
using namespace std;
const int MaxSize=10;
int visited[MaxSize]= {0};

template <class T>
class MGraph
{
public:

    MGraph(T a[],int n,int e,int choice);
    ~MGraph() {}
    void DFSTraverse(int v);
    void BFSTraverse(int v);
private:
    T vertex[MaxSize];
    int arc[MaxSize][MaxSize];
    int vertexNum,arcNum;
};

template<class T>
MGraph <T>::MGraph(T a[],int n,int e,int choice)
{
    int i,j,k,flag=1;
    vertexNum=n;
    arcNum=e;
    for(i=0; i<vertexNum; i++)
        vertex[i]=a[i];
    for(i=0; i<vertexNum; i++)
        for(j=0; j<vertexNum; j++)
            arc[i][j]=0;
    if(choice==1)
        {
            for(k=1; k<=arcNum; k++)
                {
                    flag=1;
                    cout<<"请输入无向图边的数据:";
                    char ch1,ch2;
                    cin>>ch1>>ch2;
                    for(i=0; i<vertexNum; i++)
                        for(j=0; j<vertexNum; j++)
                            {
                                if(ch1==vertex[i]&&ch2==vertex[j])
                                    {
                                        if(arc[i][j]==1||arc[j][i]==1)
                                            {
                                                cout<<"这条边重复！"<<endl;
                                                k--;
                                            }
                                        arc[i][j]=1;
                                        arc[j][i]=1;
                                        flag=0;
                                    }
                            }
                    if(flag)
                        {
                            cout<<"输入顶点错误！"<<endl;
                            k--;
                        }
                }
        }/*无向*/
    if(choice==0)
        {
            for(k=0; k<arcNum; k++)
                {
                    flag=1;
                    cout<<"请输入有向图边的数据";
                    char ch1,ch2;
                    cin>>ch1>>ch2;
                    for(i=0; i<vertexNum; i++)
                        for(j=0; j<vertexNum; j++)
                            if(ch1==vertex[i]&&ch2==vertex[j])
                                {
                                    if(arc[i][j])
                                        {
                                            cout<<"这条边重复！"<<endl;
                                            k--;
                                        }
                                    arc[i][j]=1;
                                    flag=0;
                                }
                    if(flag)
                        {
                            cout<<"输入顶点错误！"<<endl;
                            k--;
                        }
                }
        }/*有向*/
}

template <class T>
void MGraph<T>::DFSTraverse(int v)
{
    cout<<vertex[v];
    visited[v]=1;
    for(int j=0; j<vertexNum; j++)
        if(arc[v][j]==1&&visited[j]==0)
            DFSTraverse(j);
}

template <class T>
void MGraph<T>::BFSTraverse(int v)
{
    int Q[MaxSize];
    int front =-1,rear=-1;
    cout<<vertex[v];
    visited[v]=1;
    Q[++rear]=v;
    while(front!=rear)
        {
            v=Q[++front];
            for(int j=0; j<vertexNum; j++)
                if(arc[v][j]==1&&visited[j]==0)
                    {
                        cout<<vertex[j];
                        visited[j]=1;
                        Q[++rear]=j;
                    }
        }
}

#endif // MGRAPH_H_INCLUDED
