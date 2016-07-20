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
        T _key;
        Node *_next;

    public:
        Node() : _next(NULL) { };
        Node(const Node& in) : _key(in._key), _next(NULL) { };
        Node(T e) : _key(e), _next(NULL) { };
        //~Node();

        void set_key(T e) { _key = e; };
        void set_next(Node *n) { _next = n; };
        
        T key() const { return _key; };
        Node* next() const { return _next; };


        void operator=(const T &);
        bool operator>(const Node&);
        bool operator<(const Node&);
        bool operator==(const Node&);
        bool operator>=(const Node&);
        bool operator<=(const Node&);

        static void swap(Node*, Node*);
};

/**
 * Sobrecarga de operador de Mayor Que de Node.
 * */
template<class T>
bool Node<T>::operator>(const Node<T> &a)
{
    if (this != &a)
        return (this->key() > a.key());

    return false;
}

/**
 * Sobrecarga de operador Menor Que de Node.
 * */
template<class T>
bool Node<T>::operator<(const Node<T> &a )
{
    if (this != &a)
        return (this->key() < a.key());

    return false;
}

/**
 * Sobrecarga de operador de Igual Que de Node.
 * */
template<class T>
bool Node<T>::operator==(const Node<T> &a)
{
    return (this->key() == a.key());
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
void Node<T>::swap(Node<T> *a, Node<T> *b)
{
    T aux = a->_key;
    a->_key = b->_key;
    b->_key = aux;
}

#endif
