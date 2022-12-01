#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <iostream>
using namespace std;
#include<ctime>
#include<cstdlib>
const int Max=1000;
template<class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class Linklist
{
public:
    Linklist();
    Linklist(T a[],int n);
    ~Linklist();
    int Locate(T x);
    void Insert(int i,T x);
    int Length();
    T Delete(int i);
    void Printlist();
private:
    Node<T>* first;
};
template <class T>
void Store(Linklist <T> &L);
template <class T>
void Get(Linklist<T> &L);
template <class T>
void Clearlist(Linklist<T> &L);
template <class T>
void Dispaylist(Linklist<T> &L);
#endif // LINKLIST_H_INCLUDED
