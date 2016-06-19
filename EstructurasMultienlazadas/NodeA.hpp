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
        NodoA();
        NodoA(T info, C costo) : key(info), cost(cost), next(NULL) { };

        T getKey() const;
        C getCost() const;
        NodoA<T,C>* getNext() const;

        void setKey(T);
        void setCost(C);
        void setNext(NodoA<T,C>*);
};

#endif