/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _NODE_HPP_
#define _NODE_HPP_
#include <iostream>

template<class T>
class Node
{
    private:
        T info;
        Node<T> *sig;

    public:
        Node() : sig(NULL) { };
        Node(const Node<T>& in) : info(in.info), sig(NULL) { };
        Node(T e) : info(e), sig(NULL) { };
        //~Node();

        void setInfo(T);
        void setSig(Node<T>*);
        T getInfo();
        Node<T>* getSig();


        void operator=(const T &);
        bool operator>(const Node<T>&);
        bool operator<(const Node<T>&);
        bool operator==(const Node<T>&);
        bool operator>=(const Node<T>&);
        bool operator<=(const Node<T>&);

        static void intercambiar(Node<T> *, Node<T> *);
};

/**
 * Setter de Info.
 * @function
 * @param {T} Info
 * */
template<class T>
void Node<T>::setInfo(T item)
{
    info = item;
}

/**
 * Setter de siguiente Node.
 * @function
 * @param {Node<T>*} Apuntador a siguiente nodo
 * */
template<class T>
void Node<T>::setSig(Node<T> * siguiente)
{
    sig = siguiente;
}

/**
 * Getter de Info.
 * @function
 * @returns {T} Info Item
 * */
template<class T>
T Node<T>::getInfo()
{
    return info;
}

/**
 * Getter de siguiente Node.
 * @function
 * @returns {Node<T>*} Siguiente Node
 * */
template<class T>
Node<T>* Node<T>::getSig()
{
    return sig;
}


/**
 * Sobrecarga de operador de Mayor Que de Node.
 * */
template<class T>
bool Node<T>::operator>(const Node<T> &a)
{
    if (this != &a)
        return (this->getInfo() > a.getInfo());

    return false;
}

/**
 * Sobrecarga de operador Menor Que de Node.
 * */
template<class T>
bool Node<T>::operator<(const Node<T> &a )
{
    if (this != &a)
        return (this->getInfo() < a.getInfo());

    return false;
}

/**
 * Sobrecarga de operador de Igual Que de Node.
 * */
template<class T>
bool Node<T>::operator==(const Node<T> &a)
{
    return (this->getInfo() == a.getInfo());
}

/**
 * Sobrecarga de operador Mayor o Igual Que de Node.
 * */
template<class T>
bool Node<T>::operator>=(const Node<T> &a)
{
    return (*this > a || *this == a);
}

/**
 * Sobrecarga de operador Menor o Igual Que de Node.
 * */
template<class T>
bool Node<T>::operator<=(const Node<T> &a)
{
    return (*this < a || *this == a);
}

/**
 * Intercambia la info de dos nodos dados.
 * @static
 * */
template<class T>
void Node<T>::intercambiar(Node<T> *a, Node<T> *b)
{
    T aux = a->getInfo();
    a->setInfo(b->getInfo());
    b->setInfo(aux);
}

#endif
