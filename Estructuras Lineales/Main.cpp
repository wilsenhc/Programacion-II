#include <iostream>

#include "Lista.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Lista<int> l;

    for (int i = 1; i <= 10; i++)
        l.insertar(i, i);

    l.invertir();
    l.quickSort();

    cout << l << endl;

    return 0;
}

