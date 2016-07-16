/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
/* Main.cpp
 * 
 * Universidad de Carabobo
 * Facultad Experimental de Ciencias y Tecnologia
 * Departamento de Computacion
 * Progamacion II
 * Seccion 02
 * Proyecto Arboles I-2016
 * 
 * Freddy Duran     <freddyjdr03@gmail.com>
 * Wilsen Hernandez <wilsenh95@gmail.com>
 * 
 * Julio, 2016
 * */
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
    int MAX_ALT = 3;
    int n;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        char key;
        list<Color> cadena1, cadena2;
        
        while ((key = cin.get()) != '\n')
            cadena1.push_back(elegirColor(key));
        
        while ((key = cin.get()) != '\n')
            cadena2.push_back(elegirColor(key));
        
        QuadTree qt1(cadena1), qt2(cadena2), qt3;
        qt3.Union(qt1, qt2);
        
        cout << "Hay " << qt3.pixels_en_negro(MAX_ALT) << " pixels en negro." << endl;
        
        
    }
    
    return 0;
}
