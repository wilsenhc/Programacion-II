#ifndef _NODO_BINARY_TREE_HPP_
#define _NODO_BINARY_TREE_HPP_
#include <iostream>

template<class T>
class NodeBT
{
    private:
        T _key;
        NodeBT<T> *_left, *_right;
        
    public:
        NodeBT() : _left(NULL), _right(NULL) { };
        NodeBT(const T in) : _key(in), _left(NULL), _right(NULL) { };
        NodeBT(const T in, NodeBT<T>* l, NodeBT<T>* r) : _key(in), _left(l), _right(r) { };
        NodeBT(const NodeBT<T>& in) : _key(in.key), _left(NULL), _right(NULL) { };
    
        T getKey() const { return _key; }
        NodeBT<T>* getLeft() const { return _left; }
        NodeBT<T>* getRight() const { return _right; }
        bool isLeaf() const { return _left == NULL && _right == NULL; }
        bool isFullNode() const { return _left != NULL && _right != NULL; }
        int height() const;
        
        void setKey(const T);
        void setLeft(NodeBT<T>*);
        void setRight(NodeBT<T>*);
        
    private:
        int height(NodeBT<T>*) const;
        int max(int, int) const;
};

template<class T>
int NodeBT<T>::height() const
{
    if (this != NULL)
        return max(height(_left), height(_right));
    
    return 0;
}

/**
 * Key setter
 * */
template<class T>
void NodeBT<T>::setKey(const T item)
{
    _key = item;
}

/**
 * Left setter
 * */
template<class T>
void NodeBT<T>::setLeft(NodeBT<T>* l)
{
    _left = l;
}

/**
 * Right setter
 * */
template<class T>
void NodeBT<T>::setRight(NodeBT<T>* r)
{
    _right = r;
}

// =====================================================================

template<class T>
int NodeBT<T>::height(NodeBT<T>* p) const
{
    if (p != NULL)
    {
        if (p->isLeaf()) return 1;
        
        return 1 + max(height(p->getLeft()), height(p->getRight()));
    }
    return 0; 
}

template<class T>
int NodeBT<T>::max(int a, int b) const
{
    return a > b ? a : b;
}

#endif
