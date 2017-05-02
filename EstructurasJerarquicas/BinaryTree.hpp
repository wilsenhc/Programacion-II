/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_
#include "NodeBT.hpp"
#include <list>

using std::list;
using std::cout;
using std::endl;

enum Traverse { preorden, postorden, inorden, levels, topview };

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
        BinaryTree(list<T> , list<T> , Traverse);
        ~BinaryTree() { _root = clear(_root); }
        
        bool null() const { return _root == NULL; }
        bool full() const;
        BinaryTree left();
        BinaryTree right();
        void mirror() { mirror(_root); }
        list<T> print(Traverse) const;
        int height() const { return _root->height() - 1; }
        void clear() { _root = clear(_root); }
        
        void operator=(const BinaryTree<T> &);
        bool operator==(const BinaryTree<T> &) const;
        
    private:
        bool full(NodeBT<T>*) const;
        void mirror(NodeBT<T>*);
        NodeBT<T>* pre_in(list<T>&, list<T>&);
        NodeBT<T>* post_in(list<T>&, list<T>&);
        NodeBT<T>* copyBinTree(NodeBT<T>*);
        bool equal(NodeBT<T>* p, NodeBT<T>* q) const;
        NodeBT<T>* clear(NodeBT<T>*);
        
    protected:
        void list_pre(list<T>&, NodeBT<T>*) const;
        void list_post(list<T>&, NodeBT<T>*) const;
        void list_in(list<T>&, NodeBT<T>*) const;
        void list_lvl(list<T>&) const;
        void list_topview(list<T>&, NodeBT<T>*) const;
        void list_topview_left(list<T>&, NodeBT<T>*) const;
        void list_topview_right(list<T>&, NodeBT<T> *) const;
};

template<class T>
BinaryTree<T>::BinaryTree(T e, BinaryTree<T> l, BinaryTree<T> r)
{
    _root = new NodeBT<T>(e);
    _root->setLeft(copyBinTree(l._root));
    _root->setRight(copyBinTree(r._root));
}

template<class T>
bool BinaryTree<T>::full() const
{
    return full(_root);
}

template<class T>
BinaryTree<T>::BinaryTree(list<T> ordenA, list<T> ordenB, Traverse e)
{
    if (e == preorden)
        _root = pre_in(ordenA, ordenB);
    else if (e == postorden)
        _root = post_in(ordenA, ordenB);
    else
        _root = NULL;
}

template<class T>
BinaryTree<T> BinaryTree<T>::left()
{
    BinaryTree<T> tree(copyBinTree(_root->getLeft()));
    return tree;
}

template<class T>
BinaryTree<T> BinaryTree<T>::right()
{
    BinaryTree<T> tree(copyBinTree(_root->getRight()));
    return tree;
}

template<class T>
list<T> BinaryTree<T>::print(Traverse e) const
{
    list<T> L;
    
    if (e == preorden) list_pre(L, _root);
    else if (e == postorden) list_post(L, _root);
    else if (e == inorden) list_in(L, _root);
    else if (e == levels) list_lvl(L);
    else if (e == topview) list_topview(L, _root);
    
    return L;
        
}

template<class T>
void BinaryTree<T>::operator=(const BinaryTree<T> &tree)
{
    if (this != &tree)
    {
        this->_root = clear(this->_root);
        this->_root = copyBinTree(tree._root);
    }
}

template<class T>
bool BinaryTree<T>::operator==(const BinaryTree<T> & tree) const
{
    if (this != &tree)
    {
        return equal(this->_root, tree._root);
    }
    return true;
}

// -------------------- Helper methods --------------------
template<class T>
bool BinaryTree<T>::full(NodeBT<T> *p) const
{
    if (p->isFullNode())
        return full(p->getLeft()) && full(p->getRight());
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
NodeBT<T>* BinaryTree<T>::pre_in(list<T> &pre, list<T> &in)
{
    if (!in.empty())
    {
        list<T> sub;
        T e;
        while (pre.front() != in.front())
        {
            sub.push_back(in.front());
            in.pop_front();
        }
        
        in.pop_front();
        e = pre.front();
        pre.pop_front();
        
        return new NodeBT<T>(e, pre_in(pre, sub), pre_in(pre,in));
    }
    return NULL;
}

template<class T>
NodeBT<T>* BinaryTree<T>::post_in(list<T> &post, list<T> &in)
{
    if (!in.empty())
    {
        list<T> sub;
        NodeBT<T> *der;
        T e;
        while (post.back() != in.front())
        {
            sub.push_back(in.front());
            in.pop_front();
        }
        
        in.pop_front();
        e = post.back();
        post.pop_back();
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
bool BinaryTree<T>::equal(NodeBT<T>* p, NodeBT<T>* q) const
{
    if (p == NULL && q == NULL) return true;
    
    if (p != NULL && q != NULL)
    {
        return p->getKey() == q->getKey()
               && equal(p->getLeft(), q->getLeft())
               && equal(p->getRight(), q->getRight());
    }
    
    return false;
}

template<class T>
NodeBT<T>* BinaryTree<T>::clear(NodeBT<T>* leaf)
{
    if (leaf != NULL)
    {
        leaf->setLeft(clear(leaf->getLeft()));
        leaf->setRight(clear(leaf->getRight()));
        delete leaf;
    }
    return NULL;
}

template<class T>
void BinaryTree<T>::list_pre(list<T> &L, NodeBT<T> *n) const
{
    if (n)
    {
        L.push_back(n->getKey());
        list_pre(L, n->getLeft());
        list_pre(L, n->getRight());
    }
}

template<class T>
void BinaryTree<T>::list_post(list<T> &L, NodeBT<T> *n) const
{
    if (n)
    {
        list_post(L, n->getLeft());
        list_post(L, n->getRight());
        L.push_back(n->getKey());
    }
}

template<class T>
void BinaryTree<T>::list_in(list<T> &L, NodeBT<T> *n) const
{
    if (n)
    {
        list_in(L, n->getLeft());
        L.push_back(n->getKey());
        list_in(L, n->getRight());
    }
}

template<class T>
void BinaryTree<T>::list_lvl(list<T> &L) const
{
    if (!null())
    {
        list<NodeBT<T>*> lvl;
        
        lvl.push_back(_root);
        
        while(!lvl.empty())
        {
            NodeBT<T>* n = lvl.front();
            lvl.pop_front();
            
            if (n->getLeft())
                lvl.push_back(n->getLeft());
            
            if (n->getRight())
                lvl.push_back(n->getRight());
                
            L.push_back(n->getKey());
        }
    }
}

template<class T>
void BinaryTree<T>::list_topview(list<T> &L, NodeBT<T> *root) const
{
    if (root)
    {
        list_topview_left(L, root->getLeft());
        L.push_back(root->getKey());
        list_topview_right(L, root->getRight());
    }
    
}

template<class T>
void BinaryTree<T>::list_topview_left(list<T> &L, NodeBT<T> *root) const
{
    if (root)
    {
        list_topview_left(L, root->getLeft());
        L.push_back(root->getKey());
    }
}
template<class T>
void BinaryTree<T>::list_topview_right(list<T> &L, NodeBT<T> *root) const
{
    if (root)
    {
        L.push_back(root->getKey());
        list_topview_right(L, root->getRight());
    }
}


#endif
