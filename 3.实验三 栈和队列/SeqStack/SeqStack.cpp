#include "SeqStack.h"

template <class T>
SeqStack<T>::SeqStack()
{
    top=-1;
}

template <class T>
void SeqStack<T>::Push(T x)
{
    if(top==Stacksize-1) throw "…œ“Á";
    top++;
    data[top] =x;
}

template <class T>
T SeqStack<T>::Pop()
{
    T x;
    if(top==-1) throw "œ¬“Á";
    x=data[top--];
    return x;
}

template <class T>
T SeqStack<T>::GetTop()
{
    if(top!=-1)
        return data[top];
    else cout<<"’ªø’"<<endl;
}

template <class T>
int SeqStack<T>::Empty()
{
    if(top==-1) return 1;
    else return 0;
}
