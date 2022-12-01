
#include "ALGraph.h"


int main()
{
   cout<<"输入图的类型(0-有向图，1-无向图)"<<endl;
    int choice,n,e,count=0;
    cin>>choice;
    cout<<"输入顶点个数"<<endl;
    cin>>n;
    cout<<"输入顶点数据"<<endl;
    char ch[n];
    for(int i=0; i<n; i++)
        cin>>ch[i];
    cout<<"输入边的个数"<<endl;
    cin>>e;
    ALGraph <char> ALG(ch,n,e,choice);
    for(int i=0; i<MaxSize; i++)
        visited[i]=0;
    for(int ii=0;ii<n;ii++)
    {
     if(visited[ii]==0)
     {cout<<"深度优先遍历序列是：";
      ALG.DFSTraverse(ii);
      cout<<endl;
      count++;}
    }
    if(count==1) cout<<"是(强)连通图。"<<endl;
    else  cout<<"不是(强)连通图。"<<endl;
    cout<<"(强)连通分量的数目为："<<count<<endl;
    for(int i=0; i<MaxSize; i++)
        visited[i]=0;
    for(int jj=0;jj<n;jj++)
    {
     if(visited[jj]==0)
     {cout<<"广度优先遍历序列是：";
      ALG.BFSTraverse(jj);
      cout<<endl;
      count++;}
    }
    return 0;
}
