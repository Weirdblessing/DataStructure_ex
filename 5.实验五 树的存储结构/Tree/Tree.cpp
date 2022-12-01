#include "Tree.h"

Tree::Tree()
{
    TNode*Q[Max]={NULL};
    int front=-1,rear=-1;
    char ch1='#',ch2='#';
    TNode *p=NULL,*q=NULL;
    cout<<"���������㣺";
    cin>>ch1;
    p=new TNode;p->data=ch1;
    p->firstchild=p->rightsib=NULL;
    root=p;
    Q[++rear]=p;
    cout<<"��������ԣ��Կո�ָ���";
    fflush(stdin);
    ch1=getchar();getchar();ch2=getchar();
    while(ch1!='#'||ch2!='#')
    {
        p=new TNode;p->data=ch2;
        p->firstchild=p->rightsib=NULL;
        Q[++rear]=p;
        while(front!=rear)
        {
            q=Q[front+1];
            if(q->data!=ch1)
                front++;
            else
            {
                if(q->firstchild==NULL)
                    q->firstchild=p;
                else
                {
                q=q->firstchild;//��������λ��
                while(q->rightsib!=NULL)
                    q=q->rightsib;
                q->rightsib=p;
                }
                break;
            }
        }
    cout<<"��������ԣ��Կո�ָ���";
    fflush(stdin);
    ch1=getchar();getchar();ch2=getchar();
    }
}

void Tree::Release(TNode *bt)
{
    if(bt==NULL) return;
    else
    {
        Release(bt->firstchild);
        Release(bt->rightsib);
        delete bt;
    }
}

void Tree::PreOrder(TNode *bt)
{
    if(bt==NULL) return;
    else
    {
        cout<<bt->data;
        PreOrder(bt->firstchild);
        PreOrder(bt->rightsib);
    }
}

void Tree::PostOrder(TNode *bt)
{
    if(bt==NULL) return;
    else
    {
        PostOrder(bt->firstchild);
        cout<<bt->data;
        PostOrder(bt->rightsib);

    }
}
