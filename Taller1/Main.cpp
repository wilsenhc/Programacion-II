/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <iostream>
#include "../EstructurasLineales/Lista.hpp"
#include "../EstructurasLineales/Cola.hpp"

using namespace std;

int main(int argc, char **argv)
{
    int n, m, numero, mediana, longi;
    Lista<int> L;
    Cola<int> menor, mayor;
    
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
        // Ordenar ascendientemente
        L.ordenar();

        // Calculo de la mediana
        mediana = L.mediana();
        
        longi = L.longitud();
        for (int j = 1; j <= longi; j++)
        {
            numero = L.consultar(1);
            L.eliminar(1);
            if (numero >= mediana)
                mayor.encolar(numero);
            else
                menor.encolar(numero);
        }
        
        longi = menor.longitud();
        for (int j = 0; j < longi && !(menor.esVacia()); j++)
        {
            cout << menor.frente() << " ";
            menor.desencolar();
        }
        cout << endl;
        
        longi = mayor.longitud();
        for (int p = 0; p < longi && !(mayor.esVacia()); p++)
        {
            cout << mayor.frente() << " ";
            mayor.desencolar();
        }
        cout << endl;
        
        // Vaciado de las Listas y Colas
        L.vaciar();
        menor.vaciar();
        mayor.vaciar();
    }
    
    
    return 0;
}

