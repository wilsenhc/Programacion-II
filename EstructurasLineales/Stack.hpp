/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _STACK_HPP_
#define _STACK_HPP_
#include <iostream>
#include "Node.hpp"

template<class T>
class Stack
{
    private:
        int length;
        Node<T> *primero;

    public:
        Stack() : length (0), primero(NULL) { };
        Stack(const Stack<T>&);
        ~Stack() { this->clear(); };

        int size() const { return length; };
        bool empty() const { return length == 0; };
        void push(T);
        void pop();
        T top() const { return primero->key(); };
        void clear();
};

/**
 * Constructor copia de Pila.
 * @constructs Pila.
 * */
template<class T>
Stack<T>::Stack(const Stack<T>& in)
{
    if (in.primero != NULL)
    {
        primero = new Node<T>();
        primero->set_key(in.primero->key());
        Node<T> *inaux = in.primero->next();
        Node<T> *thisaux = this->primero;

        while (inaux != NULL)
        {
            Node<T> *nuevo = new Node<T>();
            nuevo->set_key(inaux->key());
            thisaux->set_next(nuevo);
            thisaux = thisaux->next();
            inaux = inaux->next();
        }

    }
    this->length = in.length;
}

/**
 * Apilar.
 * @param {T} e - T a apilar
 * */
template<class T>
void Stack<T>::push(T e)
{
    Node<T> *nuevo;
    nuevo = new Node<T>();
    nuevo->set_key(e);
    nuevo->set_next(primero);
    primero = nuevo;
    length++;
}

/**
 * Desapilar.
 * */
template<class T>
void Stack<T>::pop()
{
    Node<T> *del;
    del = primero;
    primero = primero->next();

    delete del;
}

/**
 * clear Pila
 * */
template<class T>
void Stack<T>::clear()
{
    if (!empty())
    {
        Node<T> *actual, *next;
        actual = primero;
        next = actual->next();

        for (int i = 1; i < length; i++)
        {
            delete actual;
            actual = next;
            next = actual->next();
        }
        delete actual;

        length = 0;
        primero = NULL;
    }
}





#endif
