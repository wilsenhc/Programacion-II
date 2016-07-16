/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <iostream>
#include "../EstructurasLineales/List.hpp"
#include "../EstructurasLineales/Queue.hpp"

using namespace std;

int main(int argc, char **argv)
{
    int n, m, numero, mediana, longi;
    List<int> L;
    Queue<int> menor, mayor;
    
    cin >> n; // Lectura de N (Cantidad de casos de prueba)
    for (int i = 0; i < n; i++)
    {
        cin >> m; // Lectura de M (Cantidad de elementos de la Lista)
        for (int j = 1; j <= m; j++)
        {
            // Llenado de la Lista L
            cin >> numero;
            L.insert(numero, j);
        }
        // sort ascendientemente
        L.sort();

        // Calculo de la mediana
        if (L.size() % 2)
            mediana = (L.size() + 1)/2;
        else
            mediana = ((L.size()/2) + ((L.size()/2)+1))/2 ;
        
        longi = L.size();
        for (int j = 0; j < longi; j++)
        {
            numero = L.front();
            L.pop_front();
            if (j >= mediana)
                mayor.push(numero);
            else
                menor.push(numero);
        }
        
        longi = menor.size();
        for (int j = 0; j < longi && !(menor.empty()); j++)
        {
            cout << menor.front() << " ";
            menor.pop();
        }
        cout << endl;
        
        longi = mayor.size();
        for (int p = 0; p < longi && !(mayor.empty()); p++)
        {
            cout << mayor.front() << " ";
            mayor.pop();
        }
        cout << endl;
        
        // Vaciado de las Listas y Colas
        L.clear();
        menor.clear();
        mayor.clear();
    }
    
    
    return 0;
}

