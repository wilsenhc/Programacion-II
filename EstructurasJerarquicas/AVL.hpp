#ifndef _AVL_TREE_HPP__
#define _AVL_TREE_HPP__
#include <iostream>
#include <cstdlib>
#include "BST.hpp"

template<class T>
class AVL : public BST<T>
{
    public:
        AVL() : BST<T>() { };
        AVL(T e) : BST<T>(e) { };
        AVL(NodeBT<T>* p) : BST<T>(p) { };
        AVL(const AVL<T>& t) : BST<T>(t) { }
        AVL(Lista<T> p, Lista<T> in, Traverse t) : BST<T>(p, in, t) { };
        
        void insert(T);
        void del(T);
        
    private:
        NodeBT<T>* insert(T, NodeBT<T>*);
};

template<class T>
void AVL<T>::insert(T e)
{
    this->_root = insert(e, this->_root);
}

// =====================================================================

template<class T>
NodeBT<T>* AVL<T>::insert(T e, NodeBT<T> *p)
{
    if (p == NULL) return new NodeBT<T>(e);
    
    if (e < p->getKey())
        p->setLeft(insert(e, p->getLeft()));
    else if (e > p->getKey())
        p->setRight(insert(e, p->getRight()));
    else
        p->setKey(e);
    
    if (abs(p->getLeft()->height() - p->getRight()->height()) > 1)
    {
        std::cout << "test" << std::endl;
    }    
    
    return p;
}
#endif
