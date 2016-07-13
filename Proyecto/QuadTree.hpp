#ifndef _QUADTREE_HPP_
#define _QUADTREE_HPP_
#include <iostream>
#include <list>
#include "Nodo.hpp"

using std::list; 

class QuadTree
{
    private:
        Nodo *_root;
    
    public:
        QuadTree() : _root(NULL) {};
        QuadTree(list<Color> pre);

    private:
        Nodo* _pre(list<Color> &pre);
};

QuadTree::QuadTree(list<Color> pre)
{
    _root = _pre(pre);
}

Nodo* QuadTree::_pre(list<Color> &pre)
{
    if (!pre.empty())
    {
        Color e = pre.front();
        pre.pop_front();
        if (e == BLANCO)
            return new Nodo(BLANCO);
        else if (e == NEGRO)
            return new Nodo(NEGRO);
        else
        {
            Nodo *nodo = new Nodo(GRIS);
            for (int i = 0; i < Nodo::MAX; i++)
                nodo->setHijo(_pre(pre), i);
            
            return nodo;            
        }
    }
    return NULL;
}

#endif
