#ifndef SEQ_H_INCLUDED
#define SEQ_H_INCLUDED
#include <iostream>
#include <string.h>
using namespace std;
const int Max=1000;
template <class T>
class Seqlist
{
public:
    Seqlist(){length=0;}
    Seqlist(T a[],int n);
    ~Seqlist(){}
    int Length(){return length;}
    void Insert(int i,T x);
    T Getdata(int i);
    T Delete(int i);
    int Locate(T x);
    void PrintList();
private:
    T data[Max];
    int length;
};
#endif // SEQ_H_INCLUDED
