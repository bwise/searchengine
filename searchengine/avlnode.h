#ifndef AVLNODE_H
#define AVLNODE_H

//Needs Encapsulation Protection?

template <class T> class AVLNode
{

public:
    AVLNode();
    T data;
    AVLNode *left;
    AVLNode *right;
};

template<typename T>
AVLNode<T>::AVLNode(){
    left=NULL;
    right=NULL;
}

#endif // AVLNODE_H
