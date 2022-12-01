#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <iostream>
#include <stdio.h>
using namespace std;
const int Max=20;
struct TNode
{
    char data;
    TNode *firstchild,*rightsib;
};

class Tree
{
public:
    Tree();
    ~Tree(){Release(root);}
    void PreOrder(){PreOrder(root);}
    void PostOrder(){PostOrder(root);}
private:
    TNode *root;
    void Release(TNode *bt);
    void PreOrder(TNode *bt);
    void PostOrder(TNode *bt);
};

#endif // TREE_H_INCLUDED
