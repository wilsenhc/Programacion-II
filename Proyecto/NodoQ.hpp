#ifndef _NODO_QUAD_TREE_HPP_
#define _NODO_QUAD_TREE_HPP_
#include <iostream>

typedef enum Color { BLANCO, NEGRO, GRIS };

class NodoQ
{
    private:
        static const int MAX = 4;
        Color info;
        NodoQ* hijos[MAX];

    public:
        NodoQ() { for(int i = 0; i < MAX; i++) hijos[i] = NULL; };
        NodoQ(Color e) : info(e) { for(int i = 0; i < MAX; i++) hijos[i] = NULL; };
        
        Color obtInfo() const { return info; };
        NodoQ* obtHijos() const { return hijos; };

        void setInfo(Color e) { info = e; };
        

};

#endif
