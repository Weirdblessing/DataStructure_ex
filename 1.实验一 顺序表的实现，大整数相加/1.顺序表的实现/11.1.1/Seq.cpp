#include "Seq.h"
//Seqlist类的成员函数定义
template <class T>
Seqlist<T>::Seqlist(T a[],int n) {
    if(n>Max)
        throw"参数非法";
    for(int i=0; i<n; i++)
        data[i]=a[n-i-1];
    length=n;
}

template <class T>
void Seqlist<T>::Insert(int i,T x) {
    if(length>=Max)
        throw"上溢出";
    if(i<1||i>length+1)
        throw"位置非法";
    for(int j=length; j>=i; j--)//由低位字高位存储，便于计算，输出时再反过来
        data[j]=data[j-1];
    data[i-1]=x;
    length++;
}

template <class T>
T Seqlist<T>::Delete(int i) {
    if(length==0)
        throw"下溢出";
    if(i<1||i>length)
        throw "位置非法";
    int x=data[i-1];
    for(int j=i; j<length; j++)
        data[j-1]=data[j];
    length--;
    return x;
}

template <class T>
int Seqlist<T>::Locate(T x) {
    for(int i=0; i<length; i++)
        if(data[i]==x)
            return i+1;
    return 0;
}

template <class T>//倒着输出以显示高位至低位
void Seqlist<T>::PrintList() {
    for(int i=length; i>=0; i--)
        cout<<data[i-1]<<" ";
    cout<<endl;
}

template <class T>
T Seqlist<T>::Getdata(int i) {
    if(i<1||i>length)
        throw"查找位置非法";
    else
        return data[i-1];
}


