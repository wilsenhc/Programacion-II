#include <iostream>
#include <cstdlib>
#include "Graph.hpp"

using namespace std;

void a(Graph<int,int> valor, Graph<int,int> referencia)
{
    int a = 10;
    a *= 10;
}

int main(int argc, char **argv)
{
    Graph<int,int> G;
    
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        G.insertVertex(abs(rand() % 10));
        
    for (int i = 0; i < 40; i++)
        G.insertArc(abs(rand() % 10), abs(rand() % 10), 0);
    
    a(G, G);
    
    return 0;
}
