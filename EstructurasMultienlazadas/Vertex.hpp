#ifndef _VERTEX_HPP_
#define _VERTEX_HPP_
#include <iostream>
#include <vector>
#include "Arc.hpp"

using std::vector;

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
        bool visited;

    public:
        Vertex() : ady(NULL), next(NULL), visited(false) { };
        Vertex(T info) : key(info), ady(NULL), next(NULL), visited(false) { };
        ~Vertex();

        T getKey() const { return key; };
        bool getVisited() const { return visited; };
        Vertex* getNext() const { return next; };
        Arc<T,C>* getAdy() const { return ady; };
        vector<T> successors() const;

        void setVisited(bool v) { visited = v; };
        void setKey(T k) { key = k; };
        void setNext(Vertex* p) { next = p; };

        void insertArc(Vertex*, C);
        void deleteArc(Vertex*);
};

template<class T, class C>
Vertex<T,C>::~Vertex()
{
    Arc<T,C> *p;
    while (ady)
    {   
        p = ady;
        ady = p->getNext();
        delete p;
    }
}

template<class T, class C>
vector<T> Vertex<T,C>::successors() const
{   
    vector<T> out;
    if(this)
    {
        Arc<T,C> *pivot = ady;
        while (pivot)
        {
            out.push_back(pivot->getKey());
            pivot = pivot->getNext();
        }
    }
    return out;

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

template<class T, class C>
void Vertex<T,C>::deleteArc(Vertex* s)
{
    Arc<T,C> *pivot = ady;
    Arc<T,C> *aPivot = NULL;

    while (pivot)
    {
        if (pivot->getVertex() == s)
        {
            if (aPivot)
                aPivot->setNext(pivot->getNext());
            else
                ady = pivot->getNext();
                
            delete pivot;

        }
        aPivot = pivot;
        pivot = pivot->getNext();
    }    
}
#endif
