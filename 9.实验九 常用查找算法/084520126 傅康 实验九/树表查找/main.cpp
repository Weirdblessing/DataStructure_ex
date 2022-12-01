#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
const int Max=100;
struct BiNode
{
    int data;
    BiNode *lchild,*rchild,*parent;//��Ϊ��������������ɾ����������λ�õ��ж�
};
class BiSortTree
{
public:
    BiSortTree(int a[],int n);
    ~BiSortTree()
    {
        Release(root);
    }
    BiNode* InsertBST(int x)
    {
        return InsertBST(root,x);
    }
    void DeleteBST(BiNode *p,BiNode *f);
    BiNode* SearchBST(int k,int &count)
    {
        return SearchBST(root,k,count);
    }
    void InOrder()
    {
        InOrder(root);
    }
    int Height()
    {
        return Height(root);
    }
private:
    BiNode* InsertBST(BiNode *bt,int x);
    BiNode* SearchBST(BiNode *bt,int k,int &count);
    void Release(BiNode *bt);
    void InOrder(BiNode *bt);
    int Height(BiNode *bt);
    BiNode *root;
};

void BiSortTree::Release(BiNode *bt)//����
{
    if(bt==NULL)
        return;
    else
        {
            Release(bt->lchild);
            Release(bt->rchild);
            delete bt;
        }
}

BiNode* BiSortTree::SearchBST(BiNode* bt,int k,int &count)//����
{
    if(bt==NULL)
        return NULL;
    if(bt->data==k)
        {
            count++;
            return bt;
        }
    else if(bt->data>k)
        {
            count++;
            return SearchBST(bt->lchild,k,count);
        }
    else
        {
            count++;
            return SearchBST(bt->rchild,k,count);
        }
}

BiNode* BiSortTree::InsertBST(BiNode *bt,int x)//����
{
    if(bt==NULL)
        {
            BiNode *s=new BiNode;
            s->data=x;
            s->lchild=s->rchild=NULL;
            bt=s;
            s->parent=bt;
            return bt;
        }
    else if(bt->data>x)
        bt->lchild=InsertBST(bt->lchild,x);
    else
        bt->rchild=InsertBST(bt->rchild,x);
}

BiSortTree::BiSortTree(int a[],int n)//����
{
    root =NULL;
    BiNode *tp=NULL;
    for(int i=0; i<n; i++) //��һ�����һ����Ƕ��ȥ��������ÿ�ζ��Ӹ�������
        {
            tp=root;//tp��ı�ǰ��λ�ã�
            root=InsertBST(root,a[i]);
            root->parent=tp;
        }
}

void BiSortTree::InOrder(BiNode *bt)//�������
{
    if(bt==NULL)
        return;
    else
        {
            InOrder(bt->lchild);
            cout<<bt->data<<" ";
            InOrder(bt->rchild);
        }
}

void BiSortTree::DeleteBST(BiNode *p,BiNode *f)//ɾ��
{
    if((p->lchild==NULL)&&(p->rchild==NULL))//pҶ��
        {
            f->lchild=NULL;
            f->rchild=NULL;
            delete p;
            return;
        }
    if(p->rchild==NULL)//p������
        {
            f->lchild=p->lchild;/*p->lchild->parent=f;*/
            delete p;
            return;
        }
    if(p->lchild==NULL)//p������
        {
            f->lchild=p->rchild;/*p->rchild->parent=f;*/
            delete p;
            return;
        }
    BiNode *par=p,*s=p->rchild;//p��������
    while(s->lchild!=NULL)//���������½��
        {
            par=s;
            s=s->lchild;
        }
    p->data=s->data;
    if(par==p)
        par->rchild=s->rchild;//�������
    else
        par->lchild=s->rchild;
    delete s;
}

int BiSortTree::Height(BiNode *bt)
{
    if(bt==NULL)
        return 0;
    int a=0,b=0;
    if(bt->lchild!=NULL)
        {
            a++,a+=Height(bt->lchild);
        }
    if(bt->rchild!=NULL)
        {
            b++,b+=Height(bt->rchild);
        }
    if(a>b)
        return a;
    else
        return b;
}

int main()
{
    int a[Max]= {0},min=Max,max=1,i,count=0,k,deep=0;
    BiNode* p=NULL;
    srand(time(NULL));
    for(i=0; i<10; i++)
        {
            a[i]=1+rand()%Max;
            for(int j=0; j<i; j++)
                if(a[i]==a[j])
                    i--;
            if(a[i]<min)
                min=a[i];//ֱ��������ʱ�ҳ����ֵ�������ò����㷨��,
            if(a[i]>max)
                max=a[i];//������Ҫ��ȥ�����µ�ǰ������������
        }
    cout<<"����10������������У�";
    i=0;
    while(i<10)
        {
            cout<<a[i]<<" ";
            i++;
        }
    cout<<endl;
    BiSortTree tt(a,10);
    cout<<"������������";
    tt.InOrder();

    cout<<'\n'<<"������Ҫ���ҵĽ�㣺";
    cin>>k;
    count=0;
    p=tt.SearchBST(k,count);
    if(count!=0)
        {
            cout<<"����"<<count<<"�β����ҵ���"<<k;
            if(p->parent->lchild==NULL||p->parent->lchild->data==k)
                cout<<",����ֵλ��������"<<endl;
            else
                cout<<",����ֵλ��������"<<endl;
        }
    else
        cout<<"���ݲ�����"<<endl;

    cout<<"����Ԫ��ֵ�ǣ�"<<max<<'\n'<<"��С��Ԫ��ֵʱ��"<<min<<endl;
    deep=tt.Height();
    cout<<"���ߣ�"<<deep+1<<endl;
//��������ɾ������
    int choice=0;
    cout<<"��ѡ��1����������\t2��ɾ������\t3������BST��\t0���˳�"<<endl;
    cin>>choice;
    while(choice!=0)
        {
            switch(choice)
                {
                case 1:
                    cout<<"������Ҫ�����������";
                    cin>>k;
                    tt.InsertBST(k);
                    cout<<endl;
                    break;
                case 2:
                    cout<<"������Ҫɾ����������";
                    cin>>k;
                    p = tt.SearchBST(k,count);
                    tt.DeleteBST(p,p->parent);
                    cout<<endl;
                    break;
                case 3:
                    tt.InOrder();
                    cout<<endl;
                    break;
                case 0:
                    break;
                default:
                    cout<<"��ѡ��Ϸ�ѡ�"<<endl;
                }
            cout<<'\n'<<"��ѡ��1����������\t2��ɾ������\t3������BST��\t0���˳�"<<endl;
            cin>>choice;
        }
    cout<<'\n'<<"�˳��ɹ���";
    return 0;
}
