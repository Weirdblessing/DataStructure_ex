#include "Seq.h"
//Seqlist��ĳ�Ա��������
template <class T>
Seqlist<T>::Seqlist(T a[],int n) {
    if(n>Max)
        throw"�����Ƿ�";
    for(int i=0; i<n; i++)
        data[i]=a[n-i-1];
    length=n;
}

template <class T>
void Seqlist<T>::Insert(int i,T x) {
    if(length>=Max)
        throw"�����";
    if(i<1||i>length+1)
        throw"λ�÷Ƿ�";
    for(int j=length; j>=i; j--)//�ɵ�λ�ָ�λ�洢�����ڼ��㣬���ʱ�ٷ�����
        data[j]=data[j-1];
    data[i-1]=x;
    length++;
}

template <class T>
T Seqlist<T>::Delete(int i) {
    if(length==0)
        throw"�����";
    if(i<1||i>length)
        throw "λ�÷Ƿ�";
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

template <class T>//�����������ʾ��λ����λ
void Seqlist<T>::PrintList() {
    for(int i=length; i>=0; i--)
        cout<<data[i-1]<<" ";
    cout<<endl;
}

template <class T>
T Seqlist<T>::Getdata(int i) {
    if(i<1||i>length)
        throw"����λ�÷Ƿ�";
    else
        return data[i-1];
}


