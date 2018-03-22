/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include "../../EstructurasLineales/List.hpp"
#include "../SintaxTree.hpp"
#include "../BinaryTree.hpp"
#include "../BST.hpp"

using namespace std;

int main(int argc, char **argv)
{
    BinaryTree<int> *b1, *b2;
    Lista<int> porden, inorden;
    Traverse orden;
    string s;
    int N, n;
    
    while (cin >> s)
    {
        if (s == "PREORDEN")
			orden = preorden;
		else if (s == "POSTORDEN")
			orden = postorden;
        
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> n;
            porden.push_back(n);
        }
        
        cin >> s >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> n;
            inorden.push_back(n);
        }
        
        b1 = new BinaryTree<int>(porden, inorden, orden);
        porden.clear();
        inorden.clear();
        
        cin >> s >> N;
        if (s == "PREORDEN")
			orden = preorden;
		else if (s == "POSTORDEN")
			orden = postorden;
        
        for (int i = 0; i < N; i++)
        {
            cin >> n;
            porden.push_back(n);
        }
        
        cin >> s >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> n;
            inorden.push_back(n);
        }
        
        b2 = new BinaryTree<int>(porden, inorden, orden);
        porden.clear();
        inorden.clear();
        
        if (b1->min() < b2->max())
            cout << "Es menor" << endl;
        else
            cout << "No es menor" << endl;
        
        delete b1;
        delete b2;
    }
    
    return 0;   
}
