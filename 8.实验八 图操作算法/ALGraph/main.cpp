
#include "ALGraph.h"


int main()
{
   cout<<"����ͼ������(0-����ͼ��1-����ͼ)"<<endl;
    int choice,n,e,count=0;
    cin>>choice;
    cout<<"���붥�����"<<endl;
    cin>>n;
    cout<<"���붥������"<<endl;
    char ch[n];
    for(int i=0; i<n; i++)
        cin>>ch[i];
    cout<<"����ߵĸ���"<<endl;
    cin>>e;
    ALGraph <char> ALG(ch,n,e,choice);
    for(int i=0; i<MaxSize; i++)
        visited[i]=0;
    for(int ii=0;ii<n;ii++)
    {
     if(visited[ii]==0)
     {cout<<"������ȱ��������ǣ�";
      ALG.DFSTraverse(ii);
      cout<<endl;
      count++;}
    }
    if(count==1) cout<<"��(ǿ)��ͨͼ��"<<endl;
    else  cout<<"����(ǿ)��ͨͼ��"<<endl;
    cout<<"(ǿ)��ͨ��������ĿΪ��"<<count<<endl;
    for(int i=0; i<MaxSize; i++)
        visited[i]=0;
    for(int jj=0;jj<n;jj++)
    {
     if(visited[jj]==0)
     {cout<<"������ȱ��������ǣ�";
      ALG.BFSTraverse(jj);
      cout<<endl;
      count++;}
    }
    return 0;
}
