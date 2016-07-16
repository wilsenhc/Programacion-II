#include <iostream>
#include <list>
#include "QuadTree.hpp"

using namespace std;


int main(int argc, char **argv)
{
    list<Color> cadena1 = { GRIS, GRIS, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, BLANCO, BLANCO, BLANCO, BLANCO, GRIS, BLANCO, BLANCO, BLANCO, BLANCO };

    list<Color> cadena2 = { BLANCO };
    QuadTree tree1(cadena1), tree2(cadena2);
    QuadTree tree3;
    
    tree3.Union(tree1, tree2);
    
    cout << tree3.pixels_en_negro(3) << endl;
    
    return 0;
}
