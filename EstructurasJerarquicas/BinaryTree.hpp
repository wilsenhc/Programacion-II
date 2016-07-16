/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_
#include "NodeBT.hpp"
#include "../EstructurasLineales/Lista.hpp"

enum Traverse { preorden, postorden, inorden, levels };

template<class T>
class BinaryTree
{
    protected:
        NodeBT<T> *_root;
        
    public:
        BinaryTree() : _root(NULL) {};
        BinaryTree(NodeBT<T> *p) : _root(p) {};
        BinaryTree(T e) : _root(new NodeBT<T>(e)) { };
        BinaryTree(T, BinaryTree<T>, BinaryTree<T>);
        BinaryTree(const BinaryTree<T> &p) : _root(copyBinTree(p._root)) { } ;
        BinaryTree(Lista<T> , Lista<T> , Traverse);
        ~BinaryTree() { _root = destroy(_root); }
        
        bool isNull() const { return _root == NULL; }
        bool isFullTree() const;
        BinaryTree getLeft();
        BinaryTree getRight();
        void mirror() { mirror(_root); }
        void print(Traverse) const;
        int height() const { return _root->height() - 1; }
        void destroy() { _root = destroy(_root); }
        
        void operator=(const BinaryTree<T> &);
        bool operator==(const BinaryTree<T> &) const;
        
    private:
        bool isFullTree(NodeBT<T>*) const;
        void mirror(NodeBT<T>*);
        NodeBT<T>* pre_in(Lista<T>&, Lista<T>&);
        NodeBT<T>* post_in(Lista<T>&, Lista<T>&);
        NodeBT<T>* copyBinTree(NodeBT<T>*);
        bool isEqual(NodeBT<T>* p, NodeBT<T>* q) const;
        NodeBT<T>* destroy(NodeBT<T>*);
        
    protected:
        void list_pre(Lista<T>&, NodeBT<T>*) const;
        void list_post(Lista<T>&, NodeBT<T>*) const;
        void list_in(Lista<T>&, NodeBT<T>*) const;
        void list_lvl(Lista<T>&) const;
};

template<class T>
BinaryTree<T>::BinaryTree(T e, BinaryTree<T> l, BinaryTree<T> r)
{
    _root = new NodeBT<T>(e);
    _root->setLeft(copyBinTree(l._root));
    _root->setRight(copyBinTree(r._root));
}

template<class T>
bool BinaryTree<T>::isFullTree() const
{
    return isFullTree(_root);
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
    else
        _root = NULL;
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
    else if (e == levels) list_lvl(L);
    
    if (!L.esVacia())
        std::cout << L << std::endl;
}

template<class T>
void BinaryTree<T>::operator=(const BinaryTree<T> & tree)
{
    if (this != &tree)
    {
        this->_root = destroy(this->_root);
        this->_root = copyBinTree(tree._root);
    }
}

template<class T>
bool BinaryTree<T>::operator==(const BinaryTree<T> & tree) const
{
    if (this != &tree)
    {
        return isEqual(this->_root, tree._root);
    }
    return true;
}

// -------------------- Helper methods --------------------
template<class T>
bool BinaryTree<T>::isFullTree(NodeBT<T> *p) const
{
    if (p->isFullNode())
        return isFullTree(p->getLeft()) && isFullTree(p->getRight());
    else if (p->isLeaf())
        return true;
        
    return false;
}

template<class T>
void BinaryTree<T>::mirror(NodeBT<T>* p)
{
    if (p != NULL)
    {
        mirror(p->getLeft());
        mirror(p->getRight());
        
        NodeBT<T>* t = p->getLeft();
        p->setLeft(p->getRight());
        p->setRight(t);
    }
}

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
bool BinaryTree<T>::isEqual(NodeBT<T>* p, NodeBT<T>* q) const
{
    if (p == NULL && q == NULL) return true;
    
    if (p != NULL && q != NULL)
    {
        return p->getKey() == q->getKey()
               && isEqual(p->getLeft(), q->getLeft())
               && isEqual(p->getRight(), q->getRight());
    }
    
    return false;
}

template<class T>
NodeBT<T>* BinaryTree<T>::destroy(NodeBT<T>* leaf)
{
    if (leaf != NULL)
    {
        leaf->setLeft(destroy(leaf->getLeft()));
        leaf->setRight(destroy(leaf->getRight()));
        delete leaf;
    }
    return NULL;
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

template<class T>
void BinaryTree<T>::list_lvl(Lista<T> &L) const
{
    if (!isNull())
    {
        Lista<NodeBT<T>*> lvl;
        
        lvl.pushUltimo(_root);
        
        while(!lvl.esVacia())
        {
            NodeBT<T>* n = lvl.popPrimero();
            
            if (n->getLeft())
                lvl.pushUltimo(n->getLeft());
            
            if (n->getRight())
                lvl.pushUltimo(n->getRight());
                
            L.pushUltimo(n->getKey());
        }
    }
}

#endif
