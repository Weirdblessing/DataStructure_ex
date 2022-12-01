#include "Linklist.h"

template <class T>
Linklist<T>::Linklist()
{
    first=new Node <T>;
    first->next=NULL;
}

template <class T>
Linklist<T>::Linklist(T a[],int n)
{
    Node <T> *r,*s;
    first=new Node<T>;
    r=first;
    for(int i=0;i<n;i++)
    {
        s=new Node<T>;
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL;
}
//析构
template <class T>
Linklist<T>::~Linklist()
{
    Node <T> *q=NULL;
    while(first!=NULL)
    {
        q=first;
        first=first->next;
        delete q;
    }
}
//插入操作
template<class T>
void Linklist<T>::Insert(int i,T x)
{
    Node<T>*p=first,*s=NULL;
    int count=0;
    while(p!=NULL&&count<i-1)
    {
        p=p->next;
        count++;
    }
    if(p==NULL) throw"位置";
    else{
        s=new Node<T>;
        s->data=x;
        s->next=p->next;
        p->next=s;
    }
}
//删除操作
template<class T>
T Linklist<T>::Delete(int i)
{
    Node <T>*p=first,*q=NULL;
    T x;
    int count=0;
    while(p!=NULL&&count<i-1)
    {
        p=p->next;
        count++;
    }
    if(p==NULL||p->next==NULL) throw"位置";
    else{
        q=p->next;
        x=q->data;
        p->next=q->next;
        delete q;
        return x;
    }
}
//按值x查找
template<class T>
int Linklist<T>::Locate(T x)
{
    Node <T>*p=first->next;
    int count=1;
    while(p!=NULL)
    {
        if(p->data==x) return count;
        p=p->next;
        count++;
    }
    return 0;
}
//遍历
template <class T>
void Linklist<T>::Printlist()
{
    Node<T>*p=first->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
//求单链表长度
template <class T>
int Linklist<T>::Length()
{
    Node<T> *p=first->next;
    int count=0;
    while(p!=NULL)
    {
        p=p->next;
        count++;
    }
    return count;
}
//存包
template <class T>
void Store(Linklist<T> &L)
{
    int x=0;
    if(L.Length()>= Max) throw"存包柜已满";
    else{
        srand((int)time(0));
        x=rand()%(9000)+1000;
        while(L.Locate(x)!=0)
        {
            x=rand()%(9000)+1000;
        }
        cout<<"存包成功！您的存包密码为："<<x<<endl;
        L.Insert(1,x);
    }
}
//取包
template <class T>
void Get(Linklist<T> &L)
{
    cout<<"请输入您的存包密码：";
    int code=0,wz=0;
    cin>>code;
    wz=L.Locate(code);
    if(wz!=0){
        cout<<"取包成功！请取走您的包裹！"<<endl;
        L.Delete(wz);
    }
    else cout<<"密码错误，请重试！"<<endl;
}
//清空
template <class T>
void Clearlist(Linklist<T> &L)
{
    cout<<"当前存包柜使用数量："<<L.Length()<<endl;
    L.~Linklist();
    cout<<"删除操作完成！"<<endl;

}

//管理
template <class T>
void Dispaylist(Linklist<T> &L,int flag)
{
    if(flag==1) cout<<"当前存包柜已清空！"<<endl;
    else{
    cout<<"当前存包柜使用数量："<<L.Length()<<endl;
    L.Printlist();}
}
