#include <iostream>
#include <vector>
#include <cstdlib>
#include "Graph.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Graph<int,int> G, F;
    vector<int> b;
    
    srand(time(NULL));
    for (int i = 0; i < 15; i++)
        G.insertVertex(abs(rand() % 10) + 1);
        
    for (int i = 0; i < 40; i++)
        G.insertArc(abs(rand() % 10) + 1, abs(rand() % 10) + 1, rand() % 10);
    
    cout << G << endl;
    
    b = G.sourceVertices();
    cout << "Source vertices: ";
    for (int i : b)
        cout << i << " ";
        
    b = G.sinkVertices();
    cout << endl << "Sink vertices: ";
    for (int i : b)
        cout << i << " ";
    
    cout << endl << "Orden: " << G.order() << endl;
    int n, m;
    
    cout << "BFS: ";
    b = G.breadthFirstSearch();
    for (int i : b)
        cout << i << " ";
    cout << endl;
    
    cin >> n;
    cout << "BFS (" << n << "): ";
    b = G.breadthFirstSearch(n);
    for (int i : b)
        cout << i << " ";
    cout << endl;
    
    cout << "DFS: ";
    b = G.depthFirstSearch();
    for (int i : b)
        cout << i << " ";
    cout << endl;
       
    return 0;
}
