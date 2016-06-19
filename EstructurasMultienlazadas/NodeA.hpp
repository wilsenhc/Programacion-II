#ifndef _NODO_A_HPP_
#define _NODO_A_HPP_

template<class T, class C>
class NodeA
{
    private:
        T key;
        C cost;
        NodoA<T,C> *next;

    public:
        NodoA() : next(NULL);
        NodoA(T info, C costo) : key(info), cost(cost), next(NULL) { };

        T getKey() const { return key; };
        C getCost() const { return cost; };
        NodoA<T,C>* getNext() const { return next; };

        void setKey(T k) { key = k; };
        void setCost(C c) { cost = c; };
        void setNext(NodoA<T,C>* p) { next = p; };
};

#endif