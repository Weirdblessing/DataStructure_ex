#include "MGraph.h"

int main()
{
    cout<<"输入图的类型(0-有向图，1-无向图)"<<endl;
    int choice,n,e;
    cin>>choice;
    cout<<"输入顶点个数"<<endl;
    cin>>n;
    cout<<"输入顶点数据"<<endl;
    char ch[n];
    for(int i=0; i<n; i++)
        cin>>ch[i];
    cout<<"输入边的个数"<<endl;
    cin>>e;
    MGraph <char> MG(ch,n,e,choice);
    for(int i=0; i<MaxSize; i++)
        visited[i]=0;
    cout<<"深度优先遍历序列是：";
    MG.DFSTraverse(0);
    cout<<endl;
    for(int i=0; i<MaxSize; i++)
        visited[i]=0;
    cout<<"广度优先遍历序列是：";
    MG.BFSTraverse(0);
    cout<<endl;
    return 0;
}
