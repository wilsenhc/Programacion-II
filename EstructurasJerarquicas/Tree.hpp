/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _TREE_HPP_
#define _TREE_HPP_
#include <iostream>
#include <list>
#include "NodeN.hpp"

template<class T>
class Tree
{
    protected:
        NodeN<T>* _root;
    
    public:
        Tree() : _root(NULL) { };
        Tree(NodeN<T> *p) : _root(p) { };
        Tree(const Tree<T>& t) : _root(copyTree(t._root)) { };
        Tree(T e) : _root(new NodeN<T>(e)) { };
        Tree(T, list<Tree<T>>);
        ~Tree() { _root = clear(_root); };
        
        bool null() const { return _root == NULL; }
        void push(Tree<T>);
        list<Tree<T>> children() const;
        
        void clear() { _root = clear(_root); }
        
        void operator=(const Tree<T> &);
        
    private:
		NodeN<T>* copyTree(NodeN<T>*) const;
        NodeN<T>* clear(NodeN<T>* p);
};

template<class T>
Tree<T>::Tree(T e, list<Tree<T>> L)
{
	_root = new NodeN<T>(e);
	
	if (!L.empty())
	{
        _root->setLeft(copyTree(L.pop_front()._root));
                
        for (NodeN<T>* silbings = _root->getLeft(); !L.empty(); silbings = silbings->getRight())
            silbings->setRight(copyTree(L.pop_front()._root));
	}
}

template<class T>
void Tree<T>::push(Tree<T> t)
{
    if (!t.null())
    {
        NodeN<T> *sil = _root->getLeft();
        while(sil->getRight() != NULL)
            sil = sil->getRight();
        
        sil->setRight(copyTree(t._root));
    }
}

template<class T>
list<Tree<T>> Tree<T>::children() const
{
    list<Tree<T>> L;
    for (NodeN<T> *s = _root->getLeft(); s != NULL; s = s->getRight())
    {
        Tree<T> t(new NodeN<T>(s->getKey(), copyTree(s->getLeft())));
        L.push_back(t);
    }
    return L;
}

template<class T>
void Tree<T>::operator=(const Tree<T> &tree)
{
    if (this != &tree)
    {
        this->_root = clear(this->_root);
        this->_root = copyTree(tree._root);
    }
}

// =====================================================================

template<class T>
NodeN<T>* Tree<T>::copyTree(NodeN<T>* p) const
{
    if (p != NULL)
        return new NodeN<T>(p->getKey(), copyTree(p->getLeft()), copyTree(p->getRight()));
        
    return NULL;
}

template<class T>
NodeN<T>* Tree<T>::clear(NodeN<T>* p)
{
    if (p != NULL)
    {
        p->setLeft(clear(p->getLeft()));
        p->setRight(clear(p->getRight()));
        delete p;
    }
    return NULL;
}

#endif
