#ifndef AVLNODE_H
#define AVLNODE_H

template <class T> class AVLNode
{
public:
    AVLNode();
    T data;
    AVLNode *left;
    AVLNode *right;
};

template<typename T>
AVLNode<T>::AVLNode()
{
}

#endif // AVLNODE_H
