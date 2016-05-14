#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_
#include "NodeBT.hpp"
#include "../EstructurasLineales/Lista.hpp"

template<class T>
class BinaryTree
{
    // Attributes
    private:
        NodeBT<T> *_root;
        
    // Methods
    public:
        BinaryTree() : _root(NULL) {};
        BinaryTree(Lista<T>, Lista<T>, Traversal = preorden);
        ~BinaryTree();
        
        bool isNull() const { return _root == NULL; }
        BinaryTree getLeft();
        BinaryTree getRight();
        
        void insert(T);
        NodeBT<T>* search(T);
        void destroy();
        
        enum Traversal { preorden, postorden };
    
    // Helper methods
    private:
        void _insert(T, NodeBT<T>*);
        void _destroy(NodeBT<T>*);
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

/**
 * Insert.
 * Inserts an element in the tree.
 * */
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

// -------------------- Helper methods --------------------
template<class T>
void BinaryTree<T>::_insert(T key, NodeBT<T> *leaf)
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
#endif
