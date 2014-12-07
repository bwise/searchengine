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
    ~AVLNode();
};

template<typename T>
AVLNode<T>::AVLNode(){
    left=NULL;
    right=NULL;
}

template<typename T>
AVLNode<T>::~AVLNode(){
    delete left;
    delete right;
}


#endif // AVLNODE_H
