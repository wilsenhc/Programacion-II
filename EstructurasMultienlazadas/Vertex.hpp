#ifndef _VERTEX_HPP_
#define _VERTEX_HPP_
#include <iostream>
#include "Arc.hpp"

template<class T, class C>
class Arc;

template<class T, class C>
class Vertex
{
    private:
        T key;
        Arc<T,C> *ady;
        Vertex<T,C> *next;

    public:
        Vertex() : ady(NULL), next(NULL) { };
        Vertex(T info) : key(info), ady(NULL), next(NULL) { };

        T getKey() const { return key; };
        void insertArc(Vertex<T,C>*, C);
};

template<class T, class C>
void Vertex<T,C>::insertArc(Vertex<T,C> *w, C cost)
{
    Arc<T,C> *pivot = this->ady;
    Arc<T,C> *pivotL = NULL;
    bool connected = false;

    while (pivot != NULL && !connected)
    {
        connected = (pivot->getKey() == w->getKey());
        pivotL = pivot;
        pivot = pivot->getNext();
    }

    if (!connected)
    {
        if (!pivotL && !pivot)
        {
            pivot = this->ady;
            Arc<T,C> *v;
            v = new Arc<T,C>();
            v->setCost(cost);
            v->setVertex(w);
            v->setNext(pivot);
            this->ady = v;
        }
        else
            pivotL->setNext(new Arc<T,C>(cost, w, NULL));
    }
}

#endif
