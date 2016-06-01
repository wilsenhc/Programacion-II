#include <iostream>

#include "Lista.hpp"

using namespace std;

void a(Lista<int> b)
{
	cout << "ENTRADA A VOID" << endl << endl;
	cout << b << endl;
	
	b.vaciar();
	
	cout << b << endl;
	cout << "SALE VOID" << endl << endl;
}

int main(int argc, char **argv)
{
    Lista<int> l;

    for (int i = 1; i <= 10; i++)
        l.insertar(i, i);

    l.invertir();
    l.ordenar();

    cout << l << endl;

	a(l);
	
	cout << l << endl;

    return 0;
}

