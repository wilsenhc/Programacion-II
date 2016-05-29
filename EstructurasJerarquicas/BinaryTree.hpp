#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_
#include "NodeBT.hpp"
#include "../EstructurasLineales/Lista.hpp"

enum Traverse { preorden, postorden, inorden };

template<class T>
class BinaryTree
{
    // Attributes
    protected:
        NodeBT<T> *_root;
        
    // Methods
    public:
        BinaryTree() : _root(NULL) {};
        BinaryTree(NodeBT<T> *p) : _root(p) {};
        BinaryTree(const BinaryTree<T> &p) : _root(copyBinTree(p._root)) { } ;
        BinaryTree(Lista<T> , Lista<T> , Traverse);
        ~BinaryTree();
        
        bool isNull() const { return _root == NULL; }
        BinaryTree getLeft();
        BinaryTree getRight();
        
        void print(Traverse) const;
        
        void destroy();
        
        void operator=(const BinaryTree<T> &);
        
    // Helper methods
    private:
        // Constructor helper
        NodeBT<T>* pre_in(Lista<T>&, Lista<T>&);
        NodeBT<T>* post_in(Lista<T>&, Lista<T>&);
        NodeBT<T>* copyBinTree(NodeBT<T>*);
        // Destructor helper
        void destroy(NodeBT<T>*);
        
        // Imprimir helper
        void print_pre(Lista<T>&, NodeBT<T>*) const;
        void print_post(Lista<T>&, NodeBT<T>*) const;
        void print_in(Lista<T>&, NodeBT<T>*) const;
};

/**
 * Tree Destructor.
 * */
template<class T>
BinaryTree<T>::~BinaryTree()
{
    if (!isNull())
    {
        destroy(_root);
        _root = NULL;
    }   
}

template<class T>
BinaryTree<T>::BinaryTree(Lista<T> ordenA, Lista<T> ordenB, Traverse e)
{
    if (e == preorden)
		_root = pre_in(ordenA, ordenB);
    else if (e == postorden)
    {
		ordenA.invertir();
        _root = post_in(ordenA, ordenB);
    }   
}

template<class T>
BinaryTree<T> BinaryTree<T>::getLeft()
{
	BinaryTree<T> tree(copyBinTree(_root->getLeft()));
	return tree;
}

template<class T>
BinaryTree<T> BinaryTree<T>::getRight()
{
	BinaryTree<T> tree(copyBinTree(_root->getRight()));
	return tree;
}

template<class T>
void BinaryTree<T>::print(Traverse e) const
{
	Lista<T> L;
	if (e == preorden) print_pre(L, _root);
	else if (e == postorden) print_post(L, _root);
	else if (e == inorden) print_in(L, _root);
	
	if (!L.esVacia())
        std::cout << L << std::endl;
}

template<class T>
void BinaryTree<T>::destroy()
{
    if (!isNull())
    {
        destroy(_root);
        _root = NULL;
    }  
}

template<class T>
void BinaryTree<T>::operator=(const BinaryTree<T> & tree)
{
    if (this != &tree)
    {
        this->_root = copyBinTree(tree._root);
    }
}

// -------------------- Helper methods --------------------
template<class T>
NodeBT<T>* BinaryTree<T>::pre_in(Lista<T> &pre, Lista<T> &in)
{
    if (!in.esVacia())
    {
        Lista<T> sub;
        T e;
        while (pre.getPrimero() != in.getPrimero())
            sub.pushUltimo(in.popPrimero());
        
        in.popPrimero();
        e = pre.popPrimero();
        
        return new NodeBT<T>(e, pre_in(pre, sub), pre_in(pre,in));
    }
    return NULL;
}

template<class T>
NodeBT<T>* BinaryTree<T>::post_in(Lista<T> &post, Lista<T> &in)
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
        der = post_in(post, in);
        
        return new NodeBT<T>(e, post_in(post, sub), der);
    }
    return NULL;
}

template<class T>
NodeBT<T>* BinaryTree<T>::copyBinTree(NodeBT<T> *p)
{
    if (p)
        return new NodeBT<T>(p->getKey(), copyBinTree(p->getLeft()), copyBinTree(p->getRight()));
    
    return NULL;
    
}

template<class T>
void BinaryTree<T>::destroy(NodeBT<T>* leaf)
{
    if (leaf != NULL)
    {
        destroy(leaf->getLeft());
        destroy(leaf->getRight());
        delete leaf;
    }
}

template<class T>
void BinaryTree<T>::print_pre(Lista<T> &L, NodeBT<T> *n) const
{
    if (n)
    {
        L.pushUltimo(n->getKey());
        print_pre(L, n->getLeft());
        print_pre(L, n->getRight());
    }
}

template<class T>
void BinaryTree<T>::print_post(Lista<T> &L, NodeBT<T> *n) const
{
    if (n)
    {
        print_post(L, n->getLeft());
        print_post(L, n->getRight());
        L.pushUltimo(n->getKey());
    }
}

template<class T>
void BinaryTree<T>::print_in(Lista<T> &L, NodeBT<T> *n) const
{
    if (n)
    {
        print_in(L, n->getLeft());
        L.pushUltimo(n->getKey());
        print_in(L, n->getRight());
    }
}

#endif
