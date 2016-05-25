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
bool BST<T>::search(T e) const
{
    return search(e, _root);
}


// ---------------------------------------------------------------------

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
