#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_
#include <iostream>
#include <vector>
#include "Arc.hpp"
#include "Vertex.hpp"

using std::vector;
using std::cout;
using std::endl;

template<class T, class C>
class Graph
{
    private:
        Vertex<T,C> *graph;

    public:
        Graph() : graph(NULL) { };
        Graph(const Graph &g);
        ~Graph();

        int order() const;
        bool adjacent(T, T) const;
        vector<T> successors(T) const;
        vector<T> predecessors(T) const;
        vector<T> sourceVertices() const;
        vector<T> sinkVertices() const;
        
        void insertVertex(T);
        void insertArc(T, T, C);
        void deleteVertex(T);

        template<class E, class F>
        friend std::ostream& operator<<(std::ostream&, const Graph<E,F>&);
        
    private:
        Vertex<T,C>* findVertex(T) const;
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
Graph<T,C>::~Graph()
{
    Vertex<T,C> *p;
    while (graph)
    {
        p = graph;
        graph = graph->getNext();
        delete p;
    }
}

template<class T, class C>
bool Graph<T,C>::adjacent(T v, T w) const
{
    Vertex<T,C> *V, *W;
    V = findVertex(v);
    W = findVertex(w);

    if (V && W)
    {
        Arc<T,C> *pivot = V->ady;
        while (pivot)
        {
            if (pivot->getVertex() == W)
                return true;
            pivot = pivot->getNext();
        }

        pivot = W->ady;
        while (pivot)
        {
            if (pivot->getVertex() == V)
                return true;
            pivot = pivot->getNext();
        }
    }
    return false;
}

template<class T, class C>
vector<T> Graph<T,C>::successors(T e) const
{
    Vertex<T,C> *p = findVertex(e);
    if (p)
        return p->successors;
}

template<class T, class C>
vector<T> Graph<T,C>::predecessors(T e) const
{
    Vertex<T,C> *p, *pivot;
    vector<T> out;
    p = findVertex(e);
    if (p)
    {
        pivot = graph;
        while (pivot)
        {
            if (pivot != p)
            {
                Arc<T,C> *a = pivot->ady;
                while (a)
                {
                    if (a->getVertex() == p)
                        out.push_back(pivot->getKey());

                    a = a->getNext();
                }
            }
            pivot = pivot->getNext();
        }
    }
    return out;
}

template<class T, class C>
vector<T> Graph<T,C>::sourceVertices() const
{
    Vertex<T,C> *pivot = graph;
    vector<T> out;
    while (pivot)
    {
        if (pivot->inDegree == 0)
            out.push_back(pivot->getKey());
        pivot = pivot->getNext();
    }
    return out;
}

template<class T, class C>
vector<T> Graph<T,C>::sinkVertices() const
{
    Vertex<T,C> *pivot = graph;
    vector<T> out;
    while (pivot)
    {
        if (pivot->outDegree == 0)
            out.push_back(pivot->getKey());
        pivot = pivot->getNext();
    }
    return out;
}

template<class T, class C>
int Graph<T,C>::order() const
{
    Vertex<T,C> *pivot = graph;
    int cont = 0;
    while (pivot)
    {
        cont++;
        pivot = pivot->getNext();
        
    }
    return cont;
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

template<class T, class C>
void Graph<T,C>::deleteVertex(T v)
{
    Vertex<T,C> *V = findVertex(v);
    if (V)
    {
        Vertex<T,C> *pivot;
        for (pivot = graph; pivot; pivot = pivot->getNext())
            pivot->deleteArc(V);
        
        if (V != graph)
        {
            pivot = graph;
            while (pivot->getNext() != V)
                pivot = pivot->getNext();
            
            pivot->setNext(V->getNext());
        }
        else
            graph = graph->getNext();
        
        delete V;
    }
}

template<class E, class F>
std::ostream& operator<<(std::ostream& out, const Graph<E,F> &g)
{
    Vertex<E,F> *pivot = g.graph;
    while (pivot)
    {
        out << pivot->getKey();
        Arc<E,F> *a = pivot->getAdy();
        while (a)
        {
            out << " " << a->getKey();
            a = a->getNext();
        }
        out << endl;
        pivot = pivot->getNext();
    }
    return out;
}

#endif
