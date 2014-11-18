/*
 * Taken from http://www.sanfoundry.com/cpp-program-implement-avl-trees/ then modified.
 * C++ program to Implement AVL Tree
 */

#ifndef AVLTREE_H
#define AVLTREE_H

#include<iostream>
//#include<cstdio>
//#include<sstream>
//#include<algorithm>
#include "avlnode.h"

//#define pow2(n) (1 << (n))

using namespace std;

template <class T> class AVLTree
{
public:
        int menu();
        int height(AVLNode *);
        int diff(AVLNode *);
        AVLNode <T> *rr_rotation(AVLNode *);
        AVLNode <T> *ll_rotation(AVLNode *);
        AVLNode *lr_rotation(AVLNode *);
        AVLNode *rl_rotation(AVLNode *);
        AVLNode* balance(AVLNode *);
        AVLNode* insert(AVLNode *, int );
        void display(AVLNode *, int);
        void inorder(AVLNode *);
        void preorder(AVLNode *);
        void postorder(AVLNode *);
        AVLTree();
};


#endif // AVLTREE_H
