#ifndef _NODO_V_HPP_
#define _NODO_V_HPP_
#include "NodeA.hpp"

template<class T, class C>
class NodeV
{
    private:
        T key;
        NodoV<T,C> *next;
        NodoA<T,C> *ady;

    public:
        NodoV();
        
};

#endif