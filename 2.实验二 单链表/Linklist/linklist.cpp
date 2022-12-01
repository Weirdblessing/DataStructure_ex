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
//����
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
//�������
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
    if(p==NULL) throw"λ��";
    else{
        s=new Node<T>;
        s->data=x;
        s->next=p->next;
        p->next=s;
    }
}
//ɾ������
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
    if(p==NULL||p->next==NULL) throw"λ��";
    else{
        q=p->next;
        x=q->data;
        p->next=q->next;
        delete q;
        return x;
    }
}
//��ֵx����
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
//����
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
//��������
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
//���
template <class T>
void Store(Linklist<T> &L)
{
    int x=0;
    if(L.Length()>= Max) throw"���������";
    else{
        srand((int)time(0));
        x=rand()%(9000)+1000;
        while(L.Locate(x)!=0)
        {
            x=rand()%(9000)+1000;
        }
        cout<<"����ɹ������Ĵ������Ϊ��"<<x<<endl;
        L.Insert(1,x);
    }
}
//ȡ��
template <class T>
void Get(Linklist<T> &L)
{
    cout<<"���������Ĵ�����룺";
    int code=0,wz=0;
    cin>>code;
    wz=L.Locate(code);
    if(wz!=0){
        cout<<"ȡ���ɹ�����ȡ�����İ�����"<<endl;
        L.Delete(wz);
    }
    else cout<<"������������ԣ�"<<endl;
}
//���
template <class T>
void Clearlist(Linklist<T> &L)
{
    cout<<"��ǰ�����ʹ��������"<<L.Length()<<endl;
    L.~Linklist();
    cout<<"ɾ��������ɣ�"<<endl;

}

//����
template <class T>
void Dispaylist(Linklist<T> &L,int flag)
{
    if(flag==1) cout<<"��ǰ���������գ�"<<endl;
    else{
    cout<<"��ǰ�����ʹ��������"<<L.Length()<<endl;
    L.Printlist();}
}
