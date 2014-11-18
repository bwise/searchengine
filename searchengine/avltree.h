/*
 * Taken from http://www.sanfoundry.com/cpp-program-implement-avl-trees/ then modified.
 * C++ program to Implement AVL Tree
 */

//Needs search functionality, destructor, what to do for == case

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
        int height(AVLNode <T> *);
        int diff(AVLNode <T> *);
        AVLNode <T> *rr_rotation(AVLNode <T> *);
        AVLNode <T> *ll_rotation(AVLNode <T> *);
        AVLNode <T> *lr_rotation(AVLNode <T> *);
        AVLNode <T> *rl_rotation(AVLNode <T> *);
        AVLNode <T> * balance(AVLNode <T> *);
        AVLNode <T> * insert(AVLNode <T> *, int );
        void display(AVLNode <T> *, int);
        void inorder(AVLNode <T> *);
        void preorder(AVLNode <T> *);
        void postorder(AVLNode <T> *);
        AVLTree();
private:
        AVLNode <T> * root;
};

template<typename T>
AVLTree<T>::AVLTree()
{
    root = NULL;
}

/*
 * Main Contains Menu
 */
template<typename T>
int AVLTree<T>::menu()
{
    int choice, item;
    AVLTree<T> avl;
    while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"AVL Tree Implementation"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Display Balanced AVL Tree"<<endl;
        cout<<"3.InOrder traversal"<<endl;
        cout<<"4.PreOrder traversal"<<endl;
        cout<<"5.PostOrder traversal"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>item;
            root = avl.insert(root, item);
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            avl.display(root, 1);
            break;
        case 3:
            cout<<"Inorder Traversal:"<<endl;
            avl.inorder(root);
            cout<<endl;
            break;
        case 4:
            cout<<"Preorder Traversal:"<<endl;
            avl.preorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder Traversal:"<<endl;
            avl.postorder(root);
            cout<<endl;
            break;
        case 6:
            exit(1);
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}

/*
 * Height of AVL Tree
 */
template<typename T>
int AVLTree<T>::height(AVLNode<T> *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

/*
 * Height Difference
 */
template<typename T>
int AVLTree<T>::diff(AVLNode<T> *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

/*
 * Right- Right Rotation
 */
template<typename T>
AVLNode<T> *AVLTree<T>::rr_rotation(AVLNode<T> *parent)
{
    AVLNode<T> *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
/*
 * Left- Left Rotation
 */
template<typename T>
AVLNode<T> *AVLTree<T>::ll_rotation(AVLNode<T> *parent)
{
    AVLNode<T> *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

/*
 * Left - Right Rotation
 */
template<typename T>
AVLNode<T> *AVLTree<T>::lr_rotation(AVLNode<T> *parent)
{
    AVLNode<T> *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}

/*
 * Right- Left Rotation
 */
template<typename T>
AVLNode<T> *AVLTree<T>::rl_rotation(AVLNode<T> *parent)
{
    AVLNode<T> *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}

/*
 * Balancing AVL Tree
 */
template<typename T>
AVLNode<T> *AVLTree<T>::balance(AVLNode<T> *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}

/*
 * Insert Element into the tree
 */
template<typename T>
AVLNode<T> *AVLTree<T>::insert(AVLNode<T> *root, int value)
{
    if (root == NULL)
    {
        root = new AVLNode<T>;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }else if (value == root->data){
        // Deal with duplicate values ? Not sure if needed
        cout << "------------------ Duplicate Detected--------------";
    }
    return root;
}

/*
 * Display AVL Tree
 */
template<typename T>
void AVLTree<T>::display(AVLNode<T> *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}

/*
 * Inorder Traversal of AVL Tree
 */
template<typename T>
void AVLTree<T>::inorder(AVLNode<T> *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->data<<"  ";
    inorder (tree->right);
}
/*
 * Preorder Traversal of AVL Tree
 */
template<typename T>
void AVLTree<T>::preorder(AVLNode<T> *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    preorder (tree->left);
    preorder (tree->right);

}

/*
 * Postorder Traversal of AVL Tree
 */
template<typename T>
void AVLTree<T>::postorder(AVLNode<T> *tree)
{
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<tree->data<<"  ";
}



#endif // AVLTREE_H
