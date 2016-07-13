#include <iostream>
#include <list>
#include "QuadTree.hpp"

using namespace std;

Color elegirColor(char a)
{
    switch (a)
    {
        case 'p': return GRIS;
        case 'e': return BLANCO;
        case 'f': return NEGRO;
    }
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        char key;
        Color c;
        list<Color> cadena1, cadena2;
        while ((key = cin.get()) != '\n')
        {
            cadena1.push_back(elegirColor(key));
        }
        
        while ((key = cin.get()) != '\n')
        {
            cadena2.push_back(elegirColor(key));
        }
        
        QuadTree tree1(cadena1), tree2(cadena2);
    }

    return 0;
}
