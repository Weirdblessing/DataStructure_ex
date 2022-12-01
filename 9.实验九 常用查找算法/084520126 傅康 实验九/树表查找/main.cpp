#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
const int Max=100;
struct BiNode
{
    int data;
    BiNode *lchild,*rchild,*parent;//改为三叉链表，更方便删除结点和所在位置的判断
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

void BiSortTree::Release(BiNode *bt)//销毁
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

BiNode* BiSortTree::SearchBST(BiNode* bt,int k,int &count)//查找
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

BiNode* BiSortTree::InsertBST(BiNode *bt,int x)//插入
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

BiSortTree::BiSortTree(int a[],int n)//构造
{
    root =NULL;
    BiNode *tp=NULL;
    for(int i=0; i<n; i++) //是一块接上一块镶嵌上去，而不是每次都从根结点出发
        {
            tp=root;//tp存改变前的位置，
            root=InsertBST(root,a[i]);
            root->parent=tp;
        }
}

void BiSortTree::InOrder(BiNode *bt)//中序遍历
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

void BiSortTree::DeleteBST(BiNode *p,BiNode *f)//删除
{
    if((p->lchild==NULL)&&(p->rchild==NULL))//p叶子
        {
            f->lchild=NULL;
            f->rchild=NULL;
            delete p;
            return;
        }
    if(p->rchild==NULL)//p有左树
        {
            f->lchild=p->lchild;/*p->lchild->parent=f;*/
            delete p;
            return;
        }
    if(p->lchild==NULL)//p有右树
        {
            f->lchild=p->rchild;/*p->rchild->parent=f;*/
            delete p;
            return;
        }
    BiNode *par=p,*s=p->rchild;//p有左右树
    while(s->lchild!=NULL)//查找最左下结点
        {
            par=s;
            s=s->lchild;
        }
    p->data=s->data;
    if(par==p)
        par->rchild=s->rchild;//特殊情况
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
                min=a[i];//直接在生成时找出最大值，再利用查找算法找,
            if(a[i]>max)
                max=a[i];//而不必要再去构建新的前序后序遍历函数
        }
    cout<<"生成10个树的随机序列：";
    i=0;
    while(i<10)
        {
            cout<<a[i]<<" ";
            i++;
        }
    cout<<endl;
    BiSortTree tt(a,10);
    cout<<"中序遍历结果：";
    tt.InOrder();

    cout<<'\n'<<"请输入要查找的结点：";
    cin>>k;
    count=0;
    p=tt.SearchBST(k,count);
    if(count!=0)
        {
            cout<<"经过"<<count<<"次查找找到了"<<k;
            if(p->parent->lchild==NULL||p->parent->lchild->data==k)
                cout<<",所查值位于左子树"<<endl;
            else
                cout<<",所查值位于右子树"<<endl;
        }
    else
        cout<<"数据不存在"<<endl;

    cout<<"最大的元素值是："<<max<<'\n'<<"最小的元素值时："<<min<<endl;
    deep=tt.Height();
    cout<<"树高："<<deep+1<<endl;
//树表插入和删除数据
    int choice=0;
    cout<<"请选择：1、插入整数\t2、删除整数\t3、遍历BST树\t0、退出"<<endl;
    cin>>choice;
    while(choice!=0)
        {
            switch(choice)
                {
                case 1:
                    cout<<"请输入要插入的整数：";
                    cin>>k;
                    tt.InsertBST(k);
                    cout<<endl;
                    break;
                case 2:
                    cout<<"请输入要删除的整数：";
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
                    cout<<"请选择合法选项！"<<endl;
                }
            cout<<'\n'<<"请选择：1、插入整数\t2、删除整数\t3、遍历BST树\t0、退出"<<endl;
            cin>>choice;
        }
    cout<<'\n'<<"退出成功！";
    return 0;
}
