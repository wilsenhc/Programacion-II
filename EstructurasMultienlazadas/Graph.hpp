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
};

#endif