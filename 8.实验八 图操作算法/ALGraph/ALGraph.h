#ifndef ALGRAPH_H_INCLUDED
#define ALGRAPH_H_INCLUDED
#include <iostream>
using namespace std;

const int MaxSize=10;
int visited[MaxSize]= {0};

struct ArcNode
{
    int adjvex;
    ArcNode *next;
};
template <class T>
struct VertexNode
{
    T vertex;
    ArcNode *firstedge;
};

template <class T>
class ALGraph
{
public:
    ALGraph(T a[],int n,int e,int choice);
    ~ALGraph();
    void DFSTraverse(int v);
    void BFSTraverse(int v);
private:
    VertexNode <T> adjlist[MaxSize];
    int vertexNum,arcNum;
};

template <class T>
ALGraph<T>::ALGraph(T a[],int n,int e,int choice)
{
    ArcNode *s,*p;
    int i,j,k;
    int ii,jj;
    T aa,bb;
    vertexNum=n;
    arcNum=e;
    for(i=0; i<vertexNum; i++)
        {
            adjlist[i].vertex=a[i];
            adjlist[i].firstedge=NULL;
        }
    for(k=0; k<arcNum; k++)
        {
            int flag[MaxSize][MaxSize]= {0},check=1;
            cout<<"������ߵ��������㣺";
            cin>>aa>>bb;
            s=new ArcNode;
            p=new ArcNode;
            for(i=0; i<vertexNum; i++)
                for(j=0; j<vertexNum; j++)/*��ĸƥ�����*/
                    if(aa==adjlist[i].vertex&&bb==adjlist[j].vertex)
                        {
                            ii=i;    /*��¼������ĸ���,����һ���滻���Ͳ��ؾ�����˫��ѭ����*/
                            jj=j;
                            check=0;
                        }
            if(check==1)
                {
                    cout<<"���붥�����"<<endl;    /*��ƥ��check==1���ʾ�������*/
                    k--;
                    continue;
                }
            if(choice==1&&(flag[ii][jj]==1||flag[jj][ii]==1))
                {
                    cout<<"�������ظ���"<<endl;    /*�Ҷ������һ���Ƿ����ظ���*/
                    k--;
                    continue;
                }
            else if(flag[ii][jj]==1)
                {
                    cout<<"�������ظ���"<<endl;    /*�Ҷ������һ���Ƿ����ظ���*/
                    k--;
                    continue;
                }
            else
                {
                    /*�������*/
                    s->adjvex=jj;
                    s->next=adjlist[ii].firstedge;
                    adjlist[ii].firstedge=s;
                    flag[ii][jj]=1;
                    if(choice==1) /*����ͼҪ˫��*/
                        {
                            p->adjvex=ii;
                            p->next=adjlist[jj].firstedge;
                            adjlist[jj].firstedge=p;
                            flag[jj][ii]=1;
                        }
                    continue;
                }
        }
}

template <class T>
ALGraph<T>::~ALGraph()
{
    ArcNode*p=NULL;
    for(int i=0; i<vertexNum; i++)
        {
            p=adjlist[i].firstedge;
            while(p!=NULL)
                {
                    adjlist[i].firstedge=p->next;
                    delete p;
                    p=adjlist[i].firstedge;
                }
        }
}

template <class T>
void ALGraph<T>::DFSTraverse(int v)
{
    ArcNode *p=NULL;
    int i,j,count=1;
    cout<<adjlist[v].vertex;
    visited[v]=1;
    p=adjlist[v].firstedge;
    while(p!=NULL)
        {
            j=p->adjvex;
            if(visited[j]==0)
                DFSTraverse(j);
            p=p->next;
        }
}

template <class T>
void ALGraph<T>::BFSTraverse(int v)
{
    int Q[MaxSize];
    int front =-1,rear=-1;
    ArcNode*p=NULL;
    cout<<adjlist[v].vertex;
    visited[v]=1;
    Q[++rear]=v;
    while(front!=rear)
        {
            v=Q[++front];
            p=adjlist[v].firstedge;
            while(p!=NULL)
                {
                    int j=p->adjvex;
                    if(visited[j]==0)
                        {
                            cout<<adjlist[j].vertex;
                            visited[j]=1;
                            Q[++rear]=j;
                        }
                    p=p->next;
                }
        }
}
#endif // ALGRAPH_H_INCLUDED
