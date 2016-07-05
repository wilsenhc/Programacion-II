#ifndef _NODO_QUAD_TREE_HPP_
#define _NODO_QUAD_TREE_HPP_
#include <iostream>

template<class T>
class NodoQ
{
    private:
        static const int MAX = 4;
        T info;
        NodoQ* hijos[MAX];

    public:
        NodoQ() : hijos({NULL, NULL, NULL, NULL}) {};
        NodoQ(T e) : info(e), hijos({NULL, NULL, NULL, NULL}) {};
        
        T obtInfo() const { return info; };
        

};

#endif
