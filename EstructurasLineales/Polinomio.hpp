/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_
#include <iostream>
#include "Lista.hpp"
#include "Monomio.hpp"

class Polinomio : private Lista<Monomio>
{
    public:
        void insertar(Monomio);
        void suma(Polinomio, Polinomio);
        void multiplicacion(Polinomio, Polinomio);
};

void Polinomio::insertar(Monomio m)
{
    this->Lista<Monomio>::insertar(m, this->longitud() + 1);
}

void Polinomio::suma(Polinomio p, Polinomio q)
{

}

void Polinomio::multiplicacion(Polinomio p, Polinomio q)
{

}

#endif
