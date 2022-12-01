#include "Bitree.h"

int main()
{
    BiTree T;
    cout<<"------前序遍历-------"<<endl;
    T.PreOrder();
    cout<<endl;
    cout<<"------中序遍历-------"<<endl;
    T.InOrder();
    cout<<endl;
    cout<<"------后序遍历-------"<<endl;
    T.PostOrder();
    cout<<endl;
    cout<<"------层序遍历-------"<<endl;
    T.LevelOrder();
    cout<<endl;
    cout<<"------找一个孩子的结点-------"<<endl;
    T.Onechild();
    cout<<endl;
    cout<<"------求高度-------"<<endl;
    cout<<T.Height();
    cout<<endl;
    return 0;
}
