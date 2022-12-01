#include "Bitree.h"

BiNode* BiTree::Creat(BiNode *bt)
{
    char ch;
    cout<<"请输入创建一棵二叉树的结点数据"<<endl;
    cin>>ch;
    if(ch=='#') return NULL;
    else{
        bt=new BiNode;
        bt->data=ch;
        bt->lchild=Creat(bt->lchild);
        bt->rchild=Creat(bt->rchild);
    }
    return bt;
}

void BiTree::Release(BiNode *bt)
{
    if(bt!=NULL){
        Release(bt->lchild);
        Release(bt->rchild);
        delete bt;
    }
}

void BiTree::PreOrder(BiNode *bt)
{
    if(bt==NULL) return;
    else{
        cout<<bt->data<<" ";
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

void BiTree::InOrder(BiNode *bt)
{
    if(bt==NULL) return;
    else{
        InOrder(bt->lchild);
        cout<<bt->data<<" ";
        InOrder(bt->rchild);
    }
}

void BiTree::PostOrder(BiNode *bt)
{
    if(bt==NULL) return;
    else{
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout<<bt->data<<" ";
    }
}

void BiTree::LevelOrder(BiNode *bt)
{
    BiNode *Q[100],*q=NULL;
    int front=-1,rear=-1;
    if(root==NULL) return;
    Q[++rear]=root;
    while(front!=rear)
    {
        q=Q[++front];
        cout<<q->data<<"\t";
        if(q->lchild!=NULL) Q[++rear]=q->lchild;
        if(q->rchild!=NULL) Q[++rear]=q->rchild;
    }
}

void BiTree::Onechild(BiNode *bt)
{
    if(bt==NULL) return;
    Onechild(bt->lchild);
    Onechild(bt->rchild);
    if(bt->lchild==NULL&&bt->rchild==NULL) return;
    if(bt->lchild!=NULL&&bt->rchild!=NULL) return;
    cout<<bt->data<<" ";
}

int BiTree::Height(BiNode *bt)
{
    if(bt==NULL) return 0;
    int a=0,b=0;
    if(bt->lchild!=NULL) {a++,a+=Height(bt->lchild);}
    if(bt->rchild!=NULL) {b++,b+=Height(bt->rchild);}
    if(a>b) return a;
        else return b;
}
