#ifndef _ARC_HPP_
#define _ARC_HPP_
#include <iostream>
#include "Vertex.hpp"

template<class T, class C>
class Arc
{
    private:
        C cost;
        Arc<T,C> *next;
        Vertex<T,C> *key;
    
    public:
        Arc() : key(NULL), next(NULL) { };
        Arc(C c) : cost(c), key(NULL), next(NULL) { };
        Arc(C c, Vertex<T,C>* v) : cost(c), key(v)), next(NULL) { };
        Arc(C c, Vertex<T,C>* v, Arc<T,C>* n) : cost(c), key(v)), next(n) { };

        T getKey() const { return key->getKey(); };
        Vertex<T,C>* getKey() const { return key; };
        C getCost() const { return cost; };
        Arc<T,C>* getNext() const { return next; };
};

#endif
