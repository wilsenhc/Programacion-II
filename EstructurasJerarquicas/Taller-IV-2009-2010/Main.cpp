/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include "../SintaxTree.hpp"
#include "../BinaryTree.hpp"
#include "../BST.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Lista<string> porden, inorden;
    SintaxTree *tree;
    string s;
    Traverse orden;
    int i = 1;
    
    while (cin >> s)
    {
		if (i != 1)
			cout << endl;
		
        if (s == "PREORDEN")
			orden = preorden;
		else if (s == "POSTORDEN")
			orden = postorden;
			
        
        while (cin.get() != '\n')
        {
            cin >> s;
            porden.pushUltimo(s);
        }
        
        cin >> s;
        
        while (cin.get() != '\n')
        {
            cin >> s;
            inorden.pushUltimo(s);
        }
        
        tree = new SintaxTree(porden, inorden, orden);
        
		cout << "Caso #" << i++ << ":" << endl 
		<< tree->solve() << endl;
		
		porden.vaciar();
		inorden.vaciar();
		delete tree;
    }
    
    return 0;
}
