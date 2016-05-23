#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_
#include <cstring>
#include "NodeBT.hpp"
#include "../EstructurasLineales/Lista.hpp"

enum Traverse { preorden, postorden, inorden };

template<class T>
class BinaryTree
{
    // Attributes
    private:
        NodeBT<T> *_root;
        
    // Methods
    public:
        BinaryTree() : _root(NULL) {};
        BinaryTree(Lista<T> , Lista<T> , Traverse);
        ~BinaryTree();
        
        bool isNull() const { return _root == NULL; }
        BinaryTree getLeft();
        BinaryTree getRight();
        
        void destroy();
        
        // Parcial 2009 - Arboles Sintaxis
        int evaluar() const;
        
    
    // Helper methods
    private:
        NodeBT<T>* _pre_in(Lista<T>&, Lista<T>&);
        NodeBT<T>* _post_in(Lista<T>&, Lista<T>&);
        void _insert(T, NodeBT<T>*);
        void _destroy(NodeBT<T>*);
        
        int _evaluar(NodeBT<T> *) const;
};

/**
 * Tree Destructor.
 * */
template<class T>
BinaryTree<T>::~BinaryTree()
{
    if (!isNull())
        _destroy(_root);
}

template<class T>
BinaryTree<T>::BinaryTree(Lista<T> ordenA, Lista<T> ordenB, Traverse e)
{
    if (e == preorden)
		_root = _pre_in(ordenA, ordenB);
    else if (e == postorden)
    {
		ordenA.invertir();
        _root = _post_in(ordenA, ordenB);
    }   
}
// -------------------- Helper methods --------------------

template<class T>
NodeBT<T>* BinaryTree<T>::_pre_in(Lista<T> &pre, Lista<T> &in)
{
    if (!in.esVacia())
    {
        Lista<T> sub;
        T e;
        while (pre.getPrimero() != in.getPrimero())
            sub.pushUltimo(in.popPrimero());
        
        in.popPrimero();
        e = pre.popPrimero();
        
        return new NodeBT<T>(e, _pre_in(pre, sub), _pre_in(pre,in));
    }
    return NULL;
}

template<class T>
NodeBT<T>* BinaryTree<T>::_post_in(Lista<T> &post, Lista<T> &in)
{
    if (!in.esVacia())
    {
        Lista<T> sub;
        NodeBT<T> *der;
        T e;
        while (post.getPrimero() != in.getPrimero())
            sub.pushUltimo(in.popPrimero());
        
        in.popPrimero();
        e = post.popPrimero();
        der = _post_in(post, in);
        
        return new NodeBT<T>(e, _post_in(post, sub), der);
    }
    return NULL;
}

// ------------
/*
template<class T>
void BinaryTree<T>::_insert(Item key, NodeBT<T> *leaf)
{
    if (key < leaf->getKey())
    {
        if (leaf->getLeft() != NULL)
            _insert(key, leaf->getLeft());
        else
            leaf->setLeft(new NodeBT<T>(key));
    }
    else if (key >= leaf->getKey())
    {
		if (leaf->getRight() != NULL)
			_insert(key, leaf->getRight());
		else
			leaf->setRight(new NodeBT<T>(key));
	}
}
* */

template<class T>
void BinaryTree<T>::_destroy(NodeBT<T>* leaf)
{
    if (leaf != NULL)
    {
        _destroy(leaf->getLeft());
        _destroy(leaf->getRight());
        delete leaf;
    }
}

// Parcial IV - 2009
template<class T>
int BinaryTree<T>::evaluar() const
{
    return _evaluar(_root);
}

template<class T>
int BinaryTree<T>::_evaluar(NodeBT<T> *node) const
{
    if (node != NULL)
    {
		T key = node->getKey();
        
        if (key == "+") return _evaluar(node->getLeft()) + _evaluar(node->getRight());
        else if (key == "-") return _evaluar(node->getLeft()) - _evaluar(node->getRight());
        else if (key == "*") return _evaluar(node->getLeft()) * _evaluar(node->getRight());
        else if (key == "/") return _evaluar(node->getLeft()) / _evaluar(node->getRight());
        else return stoi(key);
	}
    return 0;
}

#endif

/* 

 * Insert.
 * Inserts an element in the Itree.
 * 
template<class T>
void BinaryTree<T>::insert(T key)
{
    if (_root != NULL)
        _insert(key, _root);
    else
    {
        _root = new NodeBT<T>(key);
    }
} 



*/
