/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _COLA_HPP_
#define _COLA_HPP_
#include "Nodo.hpp"
#include <iostream>

template<class Item>
class Cola
{
    private:
        int length;
        Nodo<Item> *primero;
        Nodo<Item> *ultimo;

    public:
        Cola();
        Cola(const Cola<Item>&);
        ~Cola();

        int longitud();
        bool esVacia();
        void encolar(Item);
        void desencolar();
        Item frente();
        void clear();
        void imprimir();
};

/**
 * Constructor de Cola.
 * Construye una Cola vacia.
 * @constructs Cola
 * */
template<class Item>
Cola<Item>::Cola()
    : length( 0 ), primero( NULL ), ultimo( NULL ) { }

/**
 * Constructor Copia.
 * @constructs Cola
 * */
template<class Item>
Cola<Item>::Cola(const Cola<Item>& in)
{
    std::cout << "Constructor copia" << std::endl;
    if (in.primero != NULL)
    {
        primero = new Nodo<Item>();
        primero->setInfo(in.primero->getInfo());
        Nodo<Item> *inPivot = in.primero->getSig();
        Nodo<Item> *thisPivot = this->primero;
        Nodo<Item> *add;

        while (inPivot != NULL)
        {
            add = new Nodo<Item>();
            add->setInfo(inPivot->getInfo());
            thisPivot->setSig(add);
            thisPivot = thisPivot->getSig();
            inPivot = inPivot->getSig();
        }
        ultimo = add;
    }
    this->length = in.length;
}

/**
 * Destructor de Cola.
 * */
template<class Item>
Cola<Item>::~Cola()
{
    std::cout << "Destructor Cola" << std::endl;
    this->clear();
}

/**
 * Muestra longitud de la cola
 * @returns {int} Longitud de la cola
 * */
template<class Item>
int Cola<Item>::longitud()
{
    return length;
}

/**
 * Indica si la List esta vacia.
 * @returns {bool} TRUE sí esta vacia.
 * */
template<class Item>
bool Cola<Item>::esVacia()
{
    return length == 0;
}

/**
 * Encolar.
 * @param {Item} e - Item a encolar.
 * */
template<class Item>
void Cola<Item>::encolar(Item e)
{
    Nodo<Item> *nuevo = new Nodo<Item>();
    nuevo->setInfo(e);

    if (esVacia())
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        ultimo->setSig(nuevo);
        ultimo = nuevo;
    }

    length++;
}

template<class Item>
void Cola<Item>::desencolar()
{
    Nodo<Item> *del;

    if (esVacia())
        std::cout << "List vacia" << std::endl;
    else
    {
        del = primero;
        primero = del->getSig();
        delete del;
        length--;
    }
}

/**
 * Muestra el elemento del frente.
 * @function
 * @returns {Item} Elemento del frente.
 * */
template<class Item>
Item Cola<Item>::frente()
{
    return primero->getInfo();
}

/**
 * clear Cola.
 * */
template<class Item>
void Cola<Item>::clear()
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
        ultimo = NULL;
    }
}

/**
 * Imprimir cola.
 * Solo para fines de debug.
 * @deprecated
 * */
template<class Item>
void Cola<Item>::imprimir()
{
    if  (length == 0)
        std::cout << "Cola vacia" << std::endl;
    else
    {
        Nodo<Item> *act = primero;
        for (int i = 0; i < length; i++, act = act->getSig())
            std::cout << act->getInfo() << " ";

        std::cout << std::endl;
    }

}

#endif
