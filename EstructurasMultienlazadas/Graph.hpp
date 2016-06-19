#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_
#include "NodeA.hpp"
#include "NodeV.hpp"

template<class T, class C>
class Graph
{
    private:
        NodeV<T,C> graph;
    public:
        Graph();
        ~Graph();

        bool isNull();

};

#endif