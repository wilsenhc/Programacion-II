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
        
        void destroy();
        
        enum Traversal { preorden, postorden };
    
    // Helper methods
    private:
        NodeBT<T>* _pre_in(Lista<T>, Lista<T>);
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

template<class T>
BinaryTree(Lista<T> ordenA, Lista<T> ordenB, Traversal e)
{
    if (e = preorden)
        
}
// -------------------- Helper methods --------------------
template<class T>
NodeBT<T>* BinaryTree<T>::_pre_in(Lista<T> preorden, Lista<T> inorden)
{
    // TODO: Test
    if (preorden.longitud() > 1)
    {
        T root = preorden.getPrimero();
        int pos = inorden.buscar(root)
        
        Lista<T> inIz = inorden.sublista(1, pos-1);
        Lista<T> preIz = preorden.sublista(2, 1+inIz.longitud());
        Lista<T> inDer = inorden.sublista(pos+1, inorden.longitud());
        Lista<T> preDer = preorden.sublista(1+inIz.longitud(), preorden.longitud());
        
        return new NodeBT<T>(root,
                            _pre_in(preIz, inIz),
                            _pre_in(preDer, inDer));
    }
    else
    {
        return new NodeBT<T>(preorden.getPrimero());
    }
}

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

/* 

/**
 * Insert.
 * Inserts an element in the tree.
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