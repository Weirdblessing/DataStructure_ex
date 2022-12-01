#ifndef LINKQUEUE_H_INCLUDED
#define LINKQUEUE_H_INCLUDED
#include <iostream>
using namespace std;
const int M=3;
template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class LinkQueue{
public:
    LinkQueue();
    ~LinkQueue();
    void EnQueue(T x);
    T DeQueue();
    T GetQueue();
    int Empty();
private:
    Node <T>*front,*rear;
};
#endif // LINKQUEUE_H_INCLUDED
