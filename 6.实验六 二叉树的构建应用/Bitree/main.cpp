#include "Bitree.h"

int main()
{
    BiTree T;
    cout<<"------ǰ�����-------"<<endl;
    T.PreOrder();
    cout<<endl;
    cout<<"------�������-------"<<endl;
    T.InOrder();
    cout<<endl;
    cout<<"------�������-------"<<endl;
    T.PostOrder();
    cout<<endl;
    cout<<"------�������-------"<<endl;
    T.LevelOrder();
    cout<<endl;
    cout<<"------��һ�����ӵĽ��-------"<<endl;
    T.Onechild();
    cout<<endl;
    cout<<"------��߶�-------"<<endl;
    cout<<T.Height();
    cout<<endl;
    return 0;
}
