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
        bool isFullNode() const { return _left != NULL || _right != NULL; }

        void setKey(const T);
        void setLeft(const NodeBT<T>*);
        void setRight(const NodeBT<T>*);
};

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
void NodeBT<T>::setLeft(const NodeBT<T>* l)
{
    _left = l;
}

/**
 * Right setter
 * */
template<class T>
void NodeBT<T>::setRight(const NodeBT<T>* r)
{
    _right = r;
}

#endif
