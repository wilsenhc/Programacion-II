/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _PILA_HPP_
#define _PILA_HPP_
#include <iostream>
#include "Nodo.hpp"

template<class Item>
class Pila
{
    private:
        int length;
        Nodo<Item> *primero;

    public:
        Pila();
        Pila(const Pila<Item>&);
        ~Pila();

        int longitud();
        bool esVacia();
        void apilar(Item);
        void desapilar();
        Item tope();
        void vaciar();
};

/**
 * Contructor de Pila.
 * Construye una Pila vacia.
 * @constructs Pila
 * */
template<class Item>
Pila<Item>::Pila()
    : length ( 0 ), primero( NULL ) { }

/**
 * Constructor copia de Pila.
 * @constructs Pila.
 * */
template<class Item>
Pila<Item>::Pila(const Pila<Item>& in)
{
    if (in.primero != NULL)
    {
        primero = new Nodo<Item>();
        primero->setInfo(in.primero->getInfo());
        Nodo<Item> *inaux = in.primero->getSig();
        Nodo<Item> *thisaux = this->primero;

        while (inaux != NULL)
        {
            Nodo<Item> *nuevo = new Nodo<Item>();
            nuevo->setInfo(inaux->getInfo());
            thisaux->setSig(nuevo);
            thisaux = thisaux->getSig();
            inaux = inaux->getSig();
        }

    }
    this->length = in.length;
}

/**
 * Destructor de Pila.
 * */
template<class Item>
Pila<Item>::~Pila()
{
    this->vaciar();
}

/**
 * Muestra longitud de la Pila.
 * @returns {int} Longitud de la Pila.
 * */
template<class Item>
int Pila<Item>::longitud()
{
    return length;
}

/**
 * Indica si la Pila esta vacia.
 * @returns {bool} TRUE sí esta vacia.
 * */
template<class Item>
bool Pila<Item>::esVacia()
{
    return length == 0;
}

/**
 * Apilar.
 * @param {Item} e - Item a apilar
 * */
template<class Item>
void Pila<Item>::apilar(Item e)
{
    Nodo<Item> *nuevo;
    nuevo = new Nodo<Item>();
    nuevo->setInfo(e);
    nuevo->setSig(primero);
    primero = nuevo;
    length++;
}

/**
 * Desapilar.
 * */
template<class Item>
void Pila<Item>::desapilar()
{
    Nodo<Item> *del;
    del = primero;
    primero = primero->getSig();

    delete del;
}

/**
 * Muestra el elemento en el tope.
 * @function
 * @returns {Item} Elemento en el tope
 * */
template<class Item>
Item Pila<Item>::tope()
{
    return primero->getInfo();
}

/**
 * Vaciar Pila
 * */
template<class Item>
void Pila<Item>::vaciar()
{
    if (!esVacia())
    {
        Nodo<Item> *actual, *next;
        actual = primero;
        next = actual->getSig();

        for (int i = 1; i < length; i++)
        {
            delete actual;
            actual = next;
            next = actual->getSig();
        }
        delete actual;

        length = 0;
        primero = NULL;
    }
}





#endif
