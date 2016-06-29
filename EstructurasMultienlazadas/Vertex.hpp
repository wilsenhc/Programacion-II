#ifndef _VERTEX_HPP_
#define _VERTEX_HPP_
#include <iostream>
#include "Arc.hpp"

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
    bool connected = false;

    while (pivot != NULL && !connected)
    {
        connected = (pivot->getKey() == w->getKey());
        pivot = pivot->getNext();
    }

    if (!connected)
    {
        pivot = this->ady;
        Arc<T,C> *v = new Arc<T,C>(cost, w, pivot);
        this->ady = v;
    }
}

int main(int argc, char **argv)
{
    Vertex<int, int> *v, *w, *z;
    v = new Vertex<int,int>(1);
    w = new Vertex<int,int>(2);
    z = new Vertex<int,int>(3);
    
    v->insertArc(w, 0);
    
    return 0;
}

#endif

