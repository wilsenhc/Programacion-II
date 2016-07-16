/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <iostream>
#include "List.hpp"

using namespace std;

void a(List<int> b)
{
	cout << "ENTRADA A VOID" << endl << endl;
	cout << b << endl;
	
	b.clear();
	
	cout << b << endl;
	cout << "SALE VOID" << endl << endl;
}

int main(int argc, char **argv)
{
    List<int> l;

    for (int i = 1; i <= 10; i++)
        l.insertar(i, i);

    l.invertir();
    l.sort();

    cout << l << endl;

	a(l);
	
	cout << l << endl;

    return 0;
}

