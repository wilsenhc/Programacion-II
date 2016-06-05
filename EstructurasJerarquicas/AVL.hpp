#ifndef _AVL_TREE_HPP__
#define _AVL_TREE_HPP__
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
        void delete(T);
};

#endif