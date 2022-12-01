#ifndef BITREE_H_INCLUDED
#define BITREE_H_INCLUDED
#include <iostream>
using namespace std;
struct BiNode
{
    char data;
    BiNode *lchild,*rchild;
};

class BiTree
{
public:
    BiTree(){root=Creat(root);}
    ~BiTree(){Release(root);}
    void PreOrder(){PreOrder(root);}
    void InOrder(){InOrder(root);}
    void PostOrder(){PostOrder(root);}
    void LevelOrder(){LevelOrder(root);}
    void Onechild(){Onechild(root);}
    int Height(){return Height(root)+1;}
private:
    BiNode *root;
    BiNode *Creat(BiNode *bt);
    void Release(BiNode *bt);
    void PreOrder(BiNode *bt);
    void InOrder(BiNode *bt);
    void PostOrder(BiNode *bt);
    void LevelOrder(BiNode *bt);
    void Onechild(BiNode *bt);
    int Height(BiNode *bt);
};

#endif // BITREE_H_INCLUDED
