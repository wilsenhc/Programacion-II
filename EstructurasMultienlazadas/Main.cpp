/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include "Graph.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Graph<int,int> G, F;
    vector<int> b;
    
    srand(time(NULL));
    for (int i = 1; i < 9; i++)
        G.insertVertex(i);

    G.insertArc(1,2,1);
    G.insertArc(3,2,2);
    G.insertArc(2,4,0);
    G.insertArc(2,5,0);
    G.insertArc(5,6,0);
    G.insertArc(6,3,0);
    G.insertArc(3,1,2);
    G.insertArc(4,7,0);
    G.insertArc(7,8,0);
    G.insertArc(8,6,0);
    G.insertArc(8,1,0);
    G.insertArc(4,2,0);
    G.insertArc(3,5,1);
    G.insertArc(5,2,1);
    
    int n, m;
    cin >> n >> m;
    
    b = G.dijkstra(n, m);
    
    for (int i : b)
        cout << i << " ";
        
    //~ cout << endl << G.isConnected();
       
    return 0;
}
