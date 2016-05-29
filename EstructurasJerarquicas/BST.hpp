#ifndef _BINARY_SEARCH_TREE_HPP_
#define _BINARY_SEARCH_TREE_HPP_
#include "BinaryTree.hpp"

template<class T>
class BST : public BinaryTree<T>
{
    public:
        void insert(T);
        bool search(T) const;
        void del(T);                // TODO: Implement
    
    private:
        void insert(T, NodeBT<T>*); // TODO: Implement
        bool search(T, NodeBT<T>*);
};

template<class T>
void BST<T>::insert(T e)
{
    if(_root)
    {
        if (!search(e))
            insert(e, _root);
    }
    else
        _root = new NodeBT<T>(e);
}

template<class T>
bool BST<T>::search(T e) const
{
    return search(e, _root);
}

// ---------------------------------------------------------------------

template<class T>
void BST<T>::insert(T e, NodeBT<T> *p)
{
    if (e < p->getKey())
    {
        if (p->getLeft())
            insert(e, p->getLeft());
        else
            p->setLeft(new NodeBT<T>(e));
    }
    else 
    {
        if (p->getRight())
            insert(e, p->getRight())
        else
            p->setRight(new NodeBT<T>(e));
    }
}

template<class T>
bool BST<T>::search(T e, NodeBT<T> *p)
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


#endif
