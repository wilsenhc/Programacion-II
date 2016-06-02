#ifndef _TREE_HPP_
#define _TREE_HPP_
#include "NodeN.hpp"
#include "../EstructurasLineales/Lista.hpp"

template<class T>
class Tree
{
    protected:
        Node<T>* _root;
    
    public:
        Tree() : root(NULL) { };
        Tree(T e) : root(new NodeN<T>(e)) { };
        Tree(T, Lista<Tree<T>>);
        ~Tree();
        
        bool isNull() const { return _root == NULL; }
        Lista<Tree<T>> getChilds() const;
        
        void destroy();
        
        void operator=(const Tree<T> &);
};

#endif