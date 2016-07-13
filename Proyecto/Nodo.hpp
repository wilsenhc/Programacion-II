#ifndef _NODO_QUAD_TREE_HPP_
#define _NODO_QUAD_TREE_HPP_
#include <iostream>

enum Color { BLANCO, NEGRO, GRIS };

class Nodo
{
    public:
        static const int MAX = 4;

    private:
        Color info;
        Nodo* hijos[MAX];

    public:
        Nodo() { for(int i = 0; i < MAX; i++) hijos[i] = NULL; };
        Nodo(Color e) : info(e) { for(int i = 0; i < MAX; i++) hijos[i] = NULL; };
        
        Color obtInfo() const { return info; };
        Nodo* obtHijo(int i) const { return hijos[i]; };

        void setInfo(Color e) { info = e; };
        void setHijo(Nodo* p, int i) { hijos[i] = p; };
};

#endif
