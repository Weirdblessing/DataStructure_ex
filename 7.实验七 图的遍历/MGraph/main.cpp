#include "MGraph.h"

int main()
{
    cout<<"����ͼ������(0-����ͼ��1-����ͼ)"<<endl;
    int choice,n,e;
    cin>>choice;
    cout<<"���붥�����"<<endl;
    cin>>n;
    cout<<"���붥������"<<endl;
    char ch[n];
    for(int i=0; i<n; i++)
        cin>>ch[i];
    cout<<"����ߵĸ���"<<endl;
    cin>>e;
    MGraph <char> MG(ch,n,e,choice);
    for(int i=0; i<MaxSize; i++)
        visited[i]=0;
    cout<<"������ȱ��������ǣ�";
    MG.DFSTraverse(0);
    cout<<endl;
    for(int i=0; i<MaxSize; i++)
        visited[i]=0;
    cout<<"������ȱ��������ǣ�";
    MG.BFSTraverse(0);
    cout<<endl;
    return 0;
}
