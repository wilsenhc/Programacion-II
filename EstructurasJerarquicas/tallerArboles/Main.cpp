/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include "../../EstructurasLineales/List.hpp"
#include "../BinaryTree.hpp"

using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m, j, k;
        char c;
        string porden;
        Traverse orden;
        Lista<char> P, IN;
        cin >> m >> j >> k;
        cin >> porden;
        
        if (porden == "PREORDEN")
            orden = preorden;
        else if (porden == "POSTORDEN")
            orden = postorden;
        
        for (int l = 0; l < m; l++)
        {
            cin >> c;
            P.push_back(c);
        }
        
        cin >> porden;
        
        for (int l = 0; l < m; l++)
        {
            cin >> c;
            IN.push_back(c);
        }
        
        BinaryTree<char> tree(P, IN, orden);
        
        tree.print(levels);
        cout << endl;
    }
    
    return 0;
}
