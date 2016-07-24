/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _BINODE_HPP_
#define _BINODE_HPP_
#include <iostream>

template<class T>
class Binode
{
    private:
        T _key;
        Binode *_prev, *_next;

    public:
        Binode() : _prev(NULL), _next(NULL) {};
        Binode(const Binode& in) : _key(in._key), _prev(NULL), _next(NULL) {};
        Binode(T e) : _key(e), _prev(NULL), _next(NULL) {};

        void set_key(T e) { _key = e; };
        void set_prev(Binode *l) { _prev = l; };
        void set_next(Binode *n) { _next = n; };

        T key() const { return _key; };
        Binode* prev() const { return _prev; };
        Binode* next() const { return _next; };

        static void swap(Binode*, Binode*);
};

template<class T>
void Binode<T>::swap(Binode* a, Binode* b)
{
    T aux = a->_key;
    a->_key = b->_key;
    b->_key = aux;
}

#endif
