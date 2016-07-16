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
    Lista<int> L;
    Queue<int> menor, mayor;
    
    cin >> n; // Lectura de N (Cantidad de casos de prueba)
    for (int i = 0; i < n; i++)
    {
        cin >> m; // Lectura de M (Cantidad de elementos de la Lista)
        for (int j = 1; j <= m; j++)
        {
            // Llenado de la Lista L
            cin >> numero;
            L.insertar(numero, j);
        }
        // sort ascendientemente
        L.sort();

        // Calculo de la mediana
        mediana = L.mediana();
        
        longi = L.longitud();
        for (int j = 1; j <= longi; j++)
        {
            numero = L.get(1);
            L.erase(1);
            if (numero >= mediana)
                mayor.push(numero);
            else
                menor.push(numero);
        }
        
        longi = menor.longitud();
        for (int j = 0; j < longi && !(menor.empty()); j++)
        {
            cout << menor.frente() << " ";
            menor.pop();
        }
        cout << endl;
        
        longi = mayor.longitud();
        for (int p = 0; p < longi && !(mayor.empty()); p++)
        {
            cout << mayor.frente() << " ";
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

