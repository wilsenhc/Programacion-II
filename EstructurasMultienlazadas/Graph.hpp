#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_
#include "Arc.hpp"
#include "Vertex.hpp"

template<class T, class C>
class Graph
{
    private:
        Vertex<T,C> *graph;

    public:
        Graph() : graph(NULL) { };
        Graph(const Graph &g);

        Vertex<T,C>* findVertex(T) const;
        void insertVertex(T);
        void insertArc(T, T, C);
};

template<class T, class C>
Graph<T,C>::Graph(const Graph &g)
{
    if (g.graph != NULL)
    {
        Vertex<T,C> *p;
        Vertex<T,C> *q;
        this->graph = new Vertex<T,C>(g.graph->getKey());
        p = g.graph;
        q = this->graph;

        while (p->getNext() != NULL)
        {
            p = p->getNext();
            q->setNext(new Vertex<T,C>(p->getKey()));            
            q = q->getNext();
        }

        for (p = g.graph; p; p = p->getNext())
        {
            Arc<T,C> *a = p->ady;
            while (a)
            {
                this->insertArc(p->getKey(), a->getKey(), a->getCost());
                a = a->getNext();
            }
        }
    }
}

template<class T, class C>
Vertex<T,C>* Graph<T,C>::findVertex(T e) const
{
    Vertex<T,C>* pivot = graph;

    while (pivot)
    {
        if (pivot->getKey() == e)
            return pivot;
        
        pivot = pivot->getNext();
    }

    return NULL;
}

template<class T, class C>
void Graph<T,C>::insertVertex(T v)
{
    if (graph == NULL)
        graph = new Vertex<T,C>(v);
    else if (graph->getKey() > v)
    {
        Vertex<T,C> *n = new Vertex<T,C>(v);
        n->setNext(graph);
        graph = n;
    }
    else
    {
        Vertex<T,C> *pivot = graph;
        Vertex<T,C> *before;

        while (pivot && pivot->getKey() <= v)
        {
            if (pivot)
            {
                if (pivot->getKey() == v)
                    before = NULL;
                else
                    before = pivot;
            }
            pivot = pivot->getNext();
        }

        if (before)
        {
            before->setNext(new Vertex<T,C>(v));
            before->getNext()->setNext(pivot);
        }
    }
}

template<class T, class C>
void Graph<T,C>::insertArc(T v, T w, C c)
{
    if (v != w)
    {
        Vertex<T,C> *V = findVertex(v);
        Vertex<T,C> *W = findVertex(w);

        if (V != NULL && W != NULL)
            V->insertArc(W, c);
    }
}

#endif