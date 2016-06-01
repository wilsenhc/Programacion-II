#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_
#include "NodeBT.hpp"
#include "../EstructurasLineales/Lista.hpp"

enum Traverse { preorden, postorden, inorden };

template<class T>
class BinaryTree
{
    protected:
        NodeBT<T> *_root;
        
    public:
        BinaryTree() : _root(NULL) {};
        BinaryTree(T e) : _root(new NodeBT<T>(e)) { };
        BinaryTree(NodeBT<T> *p) : _root(p) {};
        BinaryTree(T, BinaryTree<T>, BinaryTree<T>);
        BinaryTree(const BinaryTree<T> &p) : _root(copyBinTree(p._root)) { } ;
        BinaryTree(Lista<T> , Lista<T> , Traverse);
        ~BinaryTree();
        
        bool isNull() const { return _root == NULL; }
        BinaryTree getLeft();
        BinaryTree getRight();
        void print(Traverse) const;
        void destroy();
        
        void operator=(const BinaryTree<T> &);
        
    private:
        NodeBT<T>* pre_in(Lista<T>&, Lista<T>&);
        NodeBT<T>* post_in(Lista<T>&, Lista<T>&);
        NodeBT<T>* copyBinTree(NodeBT<T>*);
        void destroy(NodeBT<T>*);
        
    protected:
        void list_pre(Lista<T>&, NodeBT<T>*) const;
        void list_post(Lista<T>&, NodeBT<T>*) const;
        void list_in(Lista<T>&, NodeBT<T>*) const;
};

template<class T>
BinaryTree<T>::BinaryTree(T e, BinaryTree<T> l, BinaryTree<T> r)
{
    _root = new NodeBT<T>(e);
    _root->setLeft(copyBinTree(l._root));
    _root->setRight(copyBinTree(r._root));
}

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
    if (e == preorden) list_pre(L, _root);
    else if (e == postorden) list_post(L, _root);
    else if (e == inorden) list_in(L, _root);
    
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
void BinaryTree<T>::list_pre(Lista<T> &L, NodeBT<T> *n) const
{
    if (n)
    {
        L.pushUltimo(n->getKey());
        list_pre(L, n->getLeft());
        list_pre(L, n->getRight());
    }
}

template<class T>
void BinaryTree<T>::list_post(Lista<T> &L, NodeBT<T> *n) const
{
    if (n)
    {
        list_post(L, n->getLeft());
        list_post(L, n->getRight());
        L.pushUltimo(n->getKey());
    }
}

template<class T>
void BinaryTree<T>::list_in(Lista<T> &L, NodeBT<T> *n) const
{
    if (n)
    {
        list_in(L, n->getLeft());
        L.pushUltimo(n->getKey());
        list_in(L, n->getRight());
    }
}

#endif
