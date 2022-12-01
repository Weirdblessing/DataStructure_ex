#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED
#include <iostream>
using namespace std;
const int Stacksize=10;
template <class T>
class SeqStack{
public:
    SeqStack();
    ~SeqStack(){}
    void Push(T x);
    T Pop();
    T GetTop();
    int Empty();
private:
    T data[Stacksize];
    int top;
};
#endif // SEQSTACK_H_INCLUDED
