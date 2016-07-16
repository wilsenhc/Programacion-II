/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_
#include "Node.hpp"
#include <iostream>

template<class T>
class Queue
{
    private:
        int length;
        Node<T> *primero;
        Node<T> *ultimo;

    public:
        Queue() : length( 0 ), primero( NULL ), ultimo( NULL ) { };
        Queue(const Queue<T>&);
        ~Queue();

        int size() const { return length; };
        bool empty() const { return length == 0; };
        void push(T);
        void pop();
        T front() const { return primero->getInfo(); };
        void clear();
};

/**
 * Constructor Copia.
 * @constructs Cola
 * */
template<class T>
Queue<T>::Queue(const Queue<T>& in)
{
    if (in.primero != NULL)
    {
        primero = new Node<T>();
        primero->setInfo(in.primero->getInfo());
        Node<T> *inPivot = in.primero->getSig();
        Node<T> *thisPivot = this->primero;
        Node<T> *add;

        while (inPivot != NULL)
        {
            add = new Node<T>();
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
template<class T>
Queue<T>::~Queue()
{
    this->clear();
}

/**
 * Encolar.
 * @param {T} e - Item a encolar.
 * */
template<class T>
void Queue<T>::push(T e)
{
    Node<T> *nuevo = new Node<T>();
    nuevo->setInfo(e);

    if (empty())
        primero = nuevo;
    else
        ultimo->setSig(nuevo);
    
    ultimo = nuevo;
    length++;
}

template<class T>
void Queue<T>::pop()
{
    Node<T> *del;

    if (empty())
        std::cout << "Cola vacia" << std::endl;
    else
    {
        del = primero;
        primero = del->getSig();
        delete del;
        length--;
    }
}

/**
 * clear Cola.
 * */
template<class T>
void Queue<T>::clear()
{
    if (!empty())
    {
        Node<T> *actual, *next;
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

#endif
