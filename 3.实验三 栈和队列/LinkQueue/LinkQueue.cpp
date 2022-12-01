#include "LinkQueue.h"
template <class T>
LinkQueue<T>::LinkQueue()
{
    Node <T>*s =NULL;
    s=new Node<T>;
    s->next=NULL;
    front=rear=s;
}

template <class T>
LinkQueue<T>::~LinkQueue()
{
    Node <T>*p=NULL;
    while(front!=NULL)
    {
        p=front->next;
        delete front;
        front=p;
    }
}

template <class T>
void LinkQueue<T>::EnQueue(T x)
{
    Node<T> *s=NULL;
    s=new Node<T>;
    s->data=x;
    s->next=NULL;
    rear->next=s;rear=s;
}

template<class T>
T LinkQueue<T>::DeQueue()
{
    Node <T>*p=NULL;
    int x;
    if(rear==front) throw"ÏÂÒç";
    p=front->next;
    x=p->data;
    front->next=p->next;
    if(p->next==NULL) rear=front;
    delete p;
    return x;
}

template <class T>
T LinkQueue<T>::GetQueue()
{
    if(front!=rear)
        return front->next->data;
}

template <class T>
int LinkQueue<T>::Empty()
{
    if(front==rear)
        return 1;
    else
        return 0;
}
