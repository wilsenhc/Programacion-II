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

#endif