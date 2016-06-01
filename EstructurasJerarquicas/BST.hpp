#ifndef _BINARY_SEARCH_TREE_HPP_
#define _BINARY_SEARCH_TREE_HPP_
#include "BinaryTree.hpp"

template<class T>
class BST : public BinaryTree<T>
{
    public:
        BST() : BinaryTree<T>() { };
        BST(NodeBT<T> *p) : BinaryTree<T>(p) { };
        BST(const BST<T> &p) : BinaryTree<T>(p) { };
        BST(Lista<T> p, Lista<T> in, Traverse t) : BinaryTree<T>(p, in, t) { };
    
        void insert(T);
        bool search(T) const;
        void del(T);
    
    private:
        NodeBT<T>* insert(T, NodeBT<T>*);
        bool search(T, NodeBT<T>*) const;
        void del(T, NodeBT<T>*);
};

template<class T>
void BST<T>::insert(T e)
{
    this->_root = insert(e, this->_root);
}

template<class T>
bool BST<T>::search(T e) const
{
    return search(e, this->_root);
}

template<class T>
void BST<T>::del(T e)
{
    if (search(e))
        del(e, this->_root);
        
}

// ---------------------------------------------------------------------

template<class T>
NodeBT<T>* BST<T>::insert(T e, NodeBT<T> *p)
{
    if (p == NULL) return new NodeBT<T>(e);
    
    if (e < p->getKey())
        p->setLeft(insert(e, p->getLeft()));
    else if (e > p->getKey())
        p->setRight(insert(e, p->getRight()));
    else
        p->setKey(e);
        
    return p;
}

template<class T>
bool BST<T>::search(T e, NodeBT<T> *p) const
{
    if (p != NULL)
    {
        if (e < p->getKey())
            return search(e, p->getLeft());
        else if (e > p->getKey())
            return search(e, p->getRight());
        else
            return true;
    }
    return false;
}

template<class T>
void BST<T>::del(T e, NodeBT<T> *p)
{
    
}

#endif
