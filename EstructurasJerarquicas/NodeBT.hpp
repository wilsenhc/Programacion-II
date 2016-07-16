/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
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
        
        void setKey(const T item) { _key = item; };
        void setLeft(NodeBT<T> *l) { _left = l; };
        void setRight(NodeBT<T> *r) { _right = r; };
        
    private:
        int height(NodeBT<T>*) const;
        int max(int a, int b) const { return a > b ? a : b; };
};

template<class T>
int NodeBT<T>::height() const
{
    if (this != NULL)
        return max(height(_left), height(_right));
    
    return 0;
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

#endif
