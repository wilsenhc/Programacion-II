#include <iostream>
#include "Vertex.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Vertex<int, int> *v, *w, *z, *j, *k;
    v = new Vertex<int,int>(1);
    w = new Vertex<int,int>(2);
    z = new Vertex<int,int>(3);
    j = new Vertex<int,int>(4);
    k = new Vertex<int,int>(5);
    
    v->insertArc(w, 0);
    v->insertArc(z, 1);
    v->insertArc(j, 2);
    v->insertArc(k, 3);
    
    w->insertArc(v, 4);
    w->insertArc(j, 5);
    
    z->insertArc(w, 6);
    z->insertArc(k, 7);
    
    k->insertArc(v, 8);
    k->insertArc(w, 9);
    
    return 0;
}
