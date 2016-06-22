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
        Graph() : graph(NULL) { };
        ~Graph();

        bool isNull() const { return graph == NULL; };
        void insertV(T);
        void insertE(T, T, C);

};

#endif