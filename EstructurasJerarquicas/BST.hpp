#ifndef _BINARY_SEARCH_TREE_HPP_
#define _BINARY_SEARCH_TREE_HPP_
#include "../EstructurasLineales/Lista.hpp"
#include "BinaryTree.hpp"

template<class T>
class BST : public BinaryTree<T>
{
    public:
        BST() : BinaryTree<T>() { };
        BST(T e) : BinaryTree<T>(e) { };
        BST(NodeBT<T> *p) : BinaryTree<T>(p) { };
        BST(const BST<T> &p) : BinaryTree<T>(p) { };
        BST(Lista<T> p, Lista<T> in, Traverse t) : BinaryTree<T>(p, in, t) { };
    
        bool isBST() const;
        T floor(T) const;   // TODO: Implement
        T min() const { return min(this->_root); }
        T max() const { return max(this->_root); }
        void insert(T);
        bool search(T e) const { return search(e, this->_root); }
        void del(T);
        void delMin();
        void delMax();
        
    private:
        bool isBST(NodeBT<T>*) const;
        T floor(T, NodeBT<T>*) const;   // TODO
        T min(NodeBT<T>*) const;
        T max(NodeBT<T>*) const;
        NodeBT<T>* insert(T, NodeBT<T>*);
        bool search(T, NodeBT<T>*) const;
        NodeBT<T>* del(T, NodeBT<T>*);
        NodeBT<T>* delMin(NodeBT<T>*);
        NodeBT<T>* delMax(NodeBT<T>*);
};

template<class T>
bool BST<T>::isBST() const
{
    return isBST(this->_root);
}

template<class T>
T BST<T>::floor(T e) const
{
    return floor(e, this->_root);
}

template<class T>
void BST<T>::insert(T e)
{
    this->_root = insert(e, this->_root);
}

template<class T>
void BST<T>::del(T e)
{
    if (search(e))
        this->_root = del(e, this->_root);
}

template<class T>
void BST<T>::delMin()
{
    this->_root = delMin(this->_root);
}

template<class T>
void BST<T>::delMax()
{
    this->_root = delMax(this->_root);
}

// =====================================================================
template<class T>
bool BST<T>::isBST(NodeBT<T> *p) const
{
    if (p != NULL)
    {
        bool max = true;
        bool min = true;
        
        if (p->getRight())
            max = this->max(p->getLeft()) < p->getKey();
        
        if (p->getLeft())
            min = this->min(p->getRight()) > p->getKey();
            
        return max && min
                && isBST(p->getLeft())
                && isBST(p->getRight());
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
NodeBT<T>* BST<T>::del(T e, NodeBT<T> *p)
{
    if (p == NULL) return NULL;
    
    if (e < p->getKey()) p->setLeft(del(e, p->getLeft()));
    else if (e > p->getKey()) p->setRight(del(e, p->getRight()));
    else
    {
        if (p->getRight() == NULL) return p->getLeft();
        if (p->getLeft() == NULL) return p->getRight();
        
        NodeBT<T> *t = p;
        p->setKey(min(t->getRight()));
        p->setRight(delMin(t->getRight()));
        p->setLeft(t->getLeft());
    }
    return p;
}

template<class T>
NodeBT<T>* BST<T>::delMin(NodeBT<T> *root)
{
    if (root->getLeft() != NULL)
        root->setLeft(delMin(root->getLeft()));
    else
    {
        NodeBT<T> *p = root->getRight();
        delete root;
        return p;
    }
    return root;
}

template<class T>
NodeBT<T>* BST<T>::delMax(NodeBT<T> *root)
{
    if (root->getRight() != NULL)
        root->setRight(delMin(root->getRight()));
    else
    {
        NodeBT<T> *p = root->getLeft();
        delete root;
        return p;
    }
    return root;
}

#endif
