#ifndef _BINARY_SEARCH_TREE_HPP_
#define _BINARY_SEARCH_TREE_HPP_
#include <limits>
#include <list>
#include "BinaryTree.hpp"

using std::list;
using std::numeric_limits;

template<class T>
class BST : public BinaryTree<T>
{
    public:
        BST() : BinaryTree<T>() { };
        BST(T e) : BinaryTree<T>(e) { };
        BST(NodeBT<T> *p) : BinaryTree<T>(p) { };
        BST(const BST<T> &p) : BinaryTree<T>(p) { };
        BST(list<T> p, list<T> in, Traverse t) : BinaryTree<T>(p, in, t) { };
    
        bool bst() const;
        T floor(T) const;   // TODO: Implement
        T min() const { return min(this->_root); }
        T max() const { return max(this->_root); }
        void push(T);
        bool search(T e) const { return search(e, this->_root); }
        void erase(T);
        void erase_min();
        void erase_max();
        
    private:
        bool bst(NodeBT<T>*, int, int) const;
        T floor(T, NodeBT<T>*) const;   // TODO
        T min(NodeBT<T>*) const;
        T max(NodeBT<T>*) const;
        NodeBT<T>* push(T, NodeBT<T>*);
        bool search(T, NodeBT<T>*) const;
        NodeBT<T>* erase(T, NodeBT<T>*);
        NodeBT<T>* erase_min(NodeBT<T>*);
        NodeBT<T>* erase_max(NodeBT<T>*);
};

template<class T>
bool BST<T>::bst() const
{
    return bst(this->_root, numeric_limits<T>::min(), numeric_limits<T>::max());
}

template<class T>
T BST<T>::floor(T e) const
{
    return floor(e, this->_root);
}

template<class T>
void BST<T>::push(T e)
{
    this->_root = push(e, this->_root);
}

template<class T>
void BST<T>::erase(T e)
{
    if (search(e))
        this->_root = erase(e, this->_root);
}

template<class T>
void BST<T>::erase_min()
{
    this->_root = erase_min(this->_root);
}

template<class T>
void BST<T>::erase_max()
{
    this->_root = erase_max(this->_root);
}

// =====================================================================
template<class T>
bool BST<T>::bst(NodeBT<T> *p, int min, int max) const
{
    if (p != NULL)
    {        
        return p->getKey() > min && p->getKey() < max
               && bst(p->getLeft(), min, p->getKey())
               && bst(p->getRight(), p->getKey(), max);
    }
    return true;
}

template<class T>
T BST<T>::floor(T e, NodeBT<T> *p) const
{
    if (e == p->getKey()) return;
}

template<class T>
T BST<T>::min(NodeBT<T> *p) const
{
    if (p->getLeft())
        return min(p->getLeft());
    
    return p->getKey();
}

template<class T>
T BST<T>::max(NodeBT<T> *p) const
{
    if (p->getRight())
        return max(p->getRight());
        
    return p->getKey();
}

template<class T>
NodeBT<T>* BST<T>::push(T e, NodeBT<T> *p)
{
    if (p == NULL) return new NodeBT<T>(e);
    
    if (e < p->getKey())
        p->setLeft(push(e, p->getLeft()));
    else if (e > p->getKey())
        p->setRight(push(e, p->getRight()));
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
NodeBT<T>* BST<T>::erase(T e, NodeBT<T> *p)
{
    if (p == NULL) return NULL;
    
    if (e < p->getKey()) p->setLeft(erase(e, p->getLeft()));
    else if (e > p->getKey()) p->setRight(erase(e, p->getRight()));
    else
    {
        if (p->getRight() == NULL) return p->getLeft();
        if (p->getLeft() == NULL) return p->getRight();
        
        NodeBT<T> *t = p;
        p->setKey(min(t->getRight()));
        p->setRight(erase_min(t->getRight()));
        p->setLeft(t->getLeft());
    }
    return p;
}

template<class T>
NodeBT<T>* BST<T>::erase_min(NodeBT<T> *root)
{
    if (root->getLeft() != NULL)
        root->setLeft(erase_min(root->getLeft()));
    else
    {
        NodeBT<T> *p = root->getRight();
        delete root;
        return p;
    }
    return root;
}

template<class T>
NodeBT<T>* BST<T>::erase_max(NodeBT<T> *root)
{
    if (root->getRight() != NULL)
        root->setRight(erase_min(root->getRight()));
    else
    {
        NodeBT<T> *p = root->getLeft();
        delete root;
        return p;
    }
    return root;
}

#endif
