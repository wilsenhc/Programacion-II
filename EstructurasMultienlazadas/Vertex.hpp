#ifndef _VERTEX_HPP_
#define _VERTEX_HPP_
#include <iostream>
#include "Arc.hpp"

template<class T, class C>
class Graph;

template<class T, class C>
class Arc;

template<class T, class C>
class Vertex
{
    private:
        friend class Graph<T,C>;
        T key;
        Arc<T,C>* ady;
        Vertex* next;

    public:
        Vertex() : ady(NULL), next(NULL) { };
        Vertex(T info) : key(info), ady(NULL), next(NULL) { };
        ~Vertex();

        T getKey() const { return key; };
        Vertex* getNext() const { return next; };

        void setKey(T k) { key = k; };
        void setNext(Vertex* p) { next = p; };

        void insertArc(Vertex*, C);
        
};

template<class T, class C>
Vertex<T,C>::~Vertex()
{
    Arc<T,C> *p;
    while (ady)
    {   
        p = ady;
        ayd = p->getNext();
        delete p;

    }
}

template<class T, class C>
void Vertex<T,C>::insertArc(Vertex *w, C cost)
{
    if (this != w)
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
}

#endif
