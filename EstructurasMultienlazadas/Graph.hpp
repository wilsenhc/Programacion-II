#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Arc.hpp"
#include "Vertex.hpp"

using std::vector;
using std::queue;
using std::stack;
using std::cout;
using std::endl;

template<class T, typename C>
class Graph
{
    private:
        Vertex<T,C> *graph;

    public:
        Graph() : graph(NULL) { };
        Graph(const Graph &g);
        ~Graph();

        int order() const;
        bool null() const { return graph == NULL; };
        bool isConnected() const;
        bool hasCycle() const;
        bool adjacent(T, T) const;
        bool findArc(T, T) const;
        C arcCost(T, T) const;
        vector<T> successors(T) const;
        vector<T> predecessors(T) const;
        vector<T> sourceVertices() const;
        vector<T> sinkVertices() const;
        vector<T> breadthFirstSearch() const;
        vector<T> breadthFirstSearch(T) const;
        vector<T> depthFirstSearch() const;
        vector<T> depthFirstSearch(T) const;
        vector<T> topologicalSorting() const;

        void insertVertex(T);
        void insertArc(T, T, C);
        void deleteVertex(T);

        template<class E, typename F>
        friend std::ostream& operator<<(std::ostream&, const Graph<E,F>&);
        
    private:
        void isConnected(Vertex<T,C> *p, int &count) const;
        Arc<T,C>* getArc(T, T) const;
        Vertex<T,C>* getVertex(T) const;
        void depthFirstSearch(Vertex<T,C>*, vector<T>&) const;
};

template<class T, typename C>
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

template<class T, typename C>
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

template<class T, typename C>
bool Graph<T,C>::isConnected() const
{
    Vertex<T,C> *pivot;
    int count = 0;
    isConnected(graph, count);

    pivot = graph;
    while (pivot)
    {
        pivot->visited = false;
        pivot = pivot->getNext();
    }
    
}

template<class T, typename C>
void Graph<T,C>::isConnected(Vertex<T,C> *p, int &count)
{
    if (!p->visited)
    {
        Arc<T,C> *pivot = p->ady;
        p->visited = true;
        count++;
        while (pivot)
        {
            isConnected(pivot, count);
            pivot = pivot->getNext();
        }
    }
}

template<class T, typename C>
bool Graph<T,C>::hasCycle() const
{
    Graph<T,C> in(*this);
    vector<T> suc;
    suc = in.sourceVertices();

    while (!suc.empty())
    {
        while (!suc.empty())
        {
            T u = suc.back();
            suc.pop_back();
            in.deleteVertex(u);
        }
        suc = in.sourceVertices();
    }
    return !in.null();
}

template<class T, typename C>
bool Graph<T,C>::adjacent(T v, T w) const
{
    Vertex<T,C> *V, *W;
    V = getVertex(v);
    W = getVertex(w);

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

template<class T, typename C>
bool Graph<T,C>::findArc(T v, T w) const
{
    Vertex<T,C> *V = getVertex(v);
    Vertex<T,C> *W = getVertex(w);

    if (V && W)
    {
        Arc<T,C> *pivot = V->ady;
        while (pivot)
        {
            if (pivot->getVertex() == W)
                return true;
            pivot = pivot->getNext();
        }
    }

    return false;
}

template<class T, typename C>
C Graph<T,C>::arcCost(T v, T w) const
{
    C a;
    Arc<T,C> out = getArc(v, w);
    if (out)
        return out->getCost();
    
    return a;
}

template<class T, typename C>
vector<T> Graph<T,C>::successors(T e) const
{
    Vertex<T,C> *p = getVertex(e);
    if (p)
        return p->successors;
}

template<class T, typename C>
vector<T> Graph<T,C>::predecessors(T e) const
{
    Vertex<T,C> *p, *pivot;
    vector<T> out;
    p = getVertex(e);
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

template<class T, typename C>
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

template<class T, typename C>
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

template<class T, typename C>
vector<T> Graph<T,C>::breadthFirstSearch() const
{
    Vertex<T,C> *pivot = graph;
    vector<T> out;
    queue<Vertex<T,C>*> q;
    while (pivot)
    {
        if (!pivot->visited)
        {
            q.push(pivot);
            pivot->visited = true;
            out.push_back(pivot->getKey());

            while (!q.empty())
            {
                Vertex<T,C> *u = q.front();
                q.pop();
                Arc<T,C> *a = u->ady;
                while (a)
                {
                    Vertex<T,C> *w = a->getVertex();
                    if (!w->visited)
                    {
                        q.push(w);
                        w->visited = true;
                        out.push_back(w->getKey());
                    }
                    a = a->getNext();
                }
            }
        }
        pivot = pivot->getNext();
    }
    pivot = graph;
    while (pivot)
    {
        pivot->visited = false;
        pivot = pivot->getNext();
    }

    return out;
}

template<class T, typename C>
vector<T> Graph<T,C>::breadthFirstSearch(T v) const
{
    Vertex<T,C> *w = getVertex(v);
    vector<T> out;
    queue<Vertex<T,C>*> q;
    
    if (w)
    {
        q.push(w);
        w->visited = true;
        out.push_back(w->getKey());

        while (!q.empty())
        {
            Vertex<T,C> *p = q.front();
            q.pop();
            Arc<T,C> *pivot = p->ady;
            while (pivot)
            {
                Vertex<T,C> *u = pivot->getVertex();
                if (!u->visited)
                {
                    q.push(w);
                    u->visited = true;
                    out.push_back(u->getKey());
                }
                pivot = pivot->getNext();
            }
        }
    }
    w = graph;
    while (w)
    {
        w->visited = false;
        w = w->getNext();
    }
    return out;
}

template<class T, typename C>
vector<T> Graph<T,C>::depthFirstSearch() const
{
    Vertex<T,C> *pivot = graph;
    vector<T> out;
    while (pivot)
    {
        depthFirstSearch(pivot, out);
        pivot = pivot->getNext();
    }
    pivot = graph;
    while (pivot)
    {
        pivot->visited = false;
        pivot = pivot->getNext();
    }
    return out;
}

template<class T, typename C>
vector<T> Graph<T,C>::depthFirstSearch(T v) const
{
    Vertex<T,C> *pivot = getVertex(v);
    vector<T> out;
    if (pivot)
        depthFirstSearch(pivot, out);
    pivot = graph;
    while (pivot)
    {
        pivot->visited = false;
        pivot = pivot->getNext();
    }
    return out;
}

template<class T, typename C>
void Graph<T,C>::depthFirstSearch(Vertex<T,C> *v, vector<T> &out) const
{
    if (!v->visited)
    {
        Arc<T,C> *pivot = v->ady;
        v->visited = true;
        while (pivot)
        {
            depthFirstSearch(pivot->getVertex(), out);
            pivot = pivot->getNext();
        }
        out.push_back(v->getKey());
    }
}

template<class T, typename C>
vector<T> Graph<T,C>::topologicalSorting() const
{
    vector<T> out;
    if (!this->hasCycle())
    {
        Graph<T,C> in(*this);
        vector<T> source;

        while (!in.null())
        {
            source = in.sourceVertices();
            while (!source.empty())
            {
                in.deleteVertex(source.back());
                out.push_back(source.back());
                source.pop_back();
            }
        }
    }
    return out;
}

template<class T, typename C>
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

template<class T, typename C>
Vertex<T,C>* Graph<T,C>::getVertex(T e) const
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

template<class T, typename C>
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

template<class T, typename C>
void Graph<T,C>::insertArc(T v, T w, C c)
{
    if (v != w)
    {
        Vertex<T,C> *V = getVertex(v);
        Vertex<T,C> *W = getVertex(w);

        if (V != NULL && W != NULL)
            V->insertArc(W, c);
    }
}

template<class T, typename C>
void Graph<T,C>::deleteVertex(T v)
{
    Vertex<T,C> *V = getVertex(v);
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

template<class E, typename F>
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
