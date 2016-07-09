#ifndef _ARC_HPP_
#define _ARC_HPP_
#include <iostream>

template<class T, typename C>
class Vertex;

template<class T, typename C>
class Arc
{
    private:
        C cost;
        Arc *next;
        Vertex<T,C> *key;
    
    public:
        Arc() : key(NULL), next(NULL) { };
        Arc(C c) : cost(c), key(NULL), next(NULL) { };
        Arc(C c, Vertex<T,C>* v) : cost(c), key(v), next(NULL) { };
        Arc(C c, Vertex<T,C>* v, Arc* n) : cost(c), key(v), next(n) { };

        T getKey() const { return key->getKey(); };
        Vertex<T,C>* getVertex() const { return key; };
        C getCost() const { return cost; };
        Arc* getNext() const { return next; };
        
        void setVertex(Vertex<T,C> *p) { key = p; };
        void setCost(C c) { cost = c; };
        void setNext(Arc *p) { next = p; };
};

#endif
