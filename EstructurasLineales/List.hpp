/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _LIST_HPP_
#define _LIST_HPP_
#include "Node.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

template<class T>
class List
{
    private:
        int length;
        Node<T> *primero;
        Node<T> *ultimo;

    public:
        List() : length(0), primero(NULL), ultimo(NULL) { };
        List(const List<T>&);
        ~List() { this->clear(); };

        int size() const { return length; };
        bool empty() const { return this->length == 0; };
        void insert(T, int);
        T get(int) const;
        int find(T) const;
        
        T front() const;
        T back() const;
        void set_front(T);
        void set_back(T);
        void push_front(T);
        void push_back(T);
        T pop_front();
        T pop_back();
        void erase(int);
        void change(T, int);
        void clear();
        List<T> sublist(int, int);
        void reverse();
        void sort();
        bool sorted() const;

        void operator=(const List<T> &);
        bool operator>(const List<T> &) const;
        bool operator<(const List<T> &) const;
        bool operator==(const List<T> &) const;
        bool operator>=(const List<T> &) const;
        bool operator<=(const List<T> &) const;

        template<class Ts>
        friend std::ostream& operator<<(std::ostream&, const List<Ts> &);

    private:
        Node<T>* _reverse(Node<T>*);
        void _dessort();
};    

/**
 * Constructor copia de Lista.
 * @constructs Lista
 * */
template<class T>
List<T>::List(const List<T>& in)
{
    if (in.primero != NULL)
    {
        primero = new Node<T>(in.primero->getInfo());
        Node<T> *inaux = in.primero->getSig();
        Node<T> *thisaux = this->primero;
        Node<T> *nuevo;
        while (inaux != NULL)
        {
            nuevo = new Node<T>(inaux->getInfo());
            thisaux->setSig(nuevo);
            thisaux = thisaux->getSig();
            inaux = inaux->getSig();
        }
        ultimo = nuevo;
    }
    this->length = in.length;
}

/**
 * Insertar en la lista.
 * @param e El Item a insertar en lista.
 * @param pos Posicion en la lista a insertar.
 * */
template<class T>
void List<T>::insert(T e, int pos)
{
    if (pos < 1 || pos > length + 2)
        throw "Posicion invalida";
    else
    {
        Node<T> *nuevo, *actual, *siguiente;
        nuevo = new Node<T>(e);

        if (length == 0)
        {
            primero = nuevo;
            ultimo = nuevo;
        }
        else if (pos == 1)
        {
            nuevo->setSig(primero);
            primero = nuevo;
        }
        else if (pos == length + 1)
        {
            ultimo->setSig(nuevo);
            ultimo = nuevo;
        }
        else
        {
            actual = primero;
            siguiente = actual->getSig();
            for (int i = 2; i < pos; i++)
            {
                actual = siguiente;
                siguiente = siguiente->getSig();
            }
            actual->setSig(nuevo);
            nuevo->setSig(siguiente);
        }
        length++;
    }
}

/**
 * Consultar elemento de la lista
 * @function
 * @param {int} pos - Posicion a consultar
 * */
template<class T>
T List<T>::get(int pos) const
{
    if (pos < 1 || pos > length + 1)
        throw "Posicion invalida";
    else
    {
        if (pos == 1)
            return primero->getInfo();
        else if (pos == length)
            return ultimo->getInfo();
        else
        {
            Node<T> *act = primero;
            for (int i = 1; i < pos; i++)
                act = act->getSig();

            return act->getInfo();
        }
    }
}

/**
 * Buscar
 * */
template<class T>
int List<T>::find(T e) const
{
    if (!empty())
    {
        Node<T> *pivot;
        int i = 0;
        
        pivot = primero;
        while (pivot != NULL)
        {
            if (pivot->getInfo() == e)
                return i;
                
            pivot = pivot->getSig();
            i++;
        }
        return i;
    }
    
    return -1; // No encontrado
}

/**
 * Get Primero.
 * Funcion miembro getter de Lista.
 * Retorna el primer Item de la Lista.
 * @returns {Item} Primer Item de la Lista.
 * */
template<class T>
T List<T>::front() const
{
    return this->primero->getInfo();
}

/**
 * Get Ultimo.
 * Funcion miembro getter de Lista.
 * Retorna el ultimo Item de la Lista.
 * @returns {Item} Ultimo Item de la Lista.
 * */
template<class T>
T List<T>::back() const
{
    return this->ultimo->getInfo();
}

template<class T>
void List<T>::set_front(T e)
{
    primero->setInfo(e);
}

template<class T>
void List<T>::set_back(T e)
{
    ultimo->setInfo(e);
}

template<class T>
void List<T>::push_front(T e)
{
    Node<T> *nuevo = new Node<T>(e);
    if (!empty())
    {
        nuevo->setSig(primero);
        primero = nuevo;
    }
    else
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    length++;
}

template<class T>
void List<T>::push_back(T e)
{
    Node<T> *nuevo = new Node<T>(e);
    if(!empty())
    {
        ultimo->setSig(nuevo);
        ultimo = nuevo;
    }
    else
    {
         primero = nuevo;
         ultimo = nuevo;
    }
    length++;
}

template<class T>
T List<T>::pop_front()
{
    if (!empty())
    {
        Node<T> *aux;
        T e;
        e = primero->getInfo();
        aux = primero;
        primero = aux->getSig();
        length--;
        delete aux;
        return e;   
    }
    return 0;
}

template<class T>
T List<T>::pop_back()
{
    if (!empty())
    {
        Node<T> *ant, *act;
        act = primero;
        for(int i = 0; i < length; i++)
        {
            ant = act;
            act = act->getSig();
        }
        ant->setSig(NULL);
        ultimo = ant;
        T e = act->getInfo();
        delete act;
        return e;
    }
    return 0;
}

/**
 * change
 * */
template<class T>
void List<T>::change(T e, int pos)
{
    if (this->empty())
        throw "Lista vacia";
    else if (pos < 1 || pos > length)
        throw "Posicion invalida";
    else
    {
        if (pos == 1)
            primero->setInfo(e);
        else if (pos == length)
            ultimo->setInfo(e);
        else
        {
            Node<T> *act = primero;
            for (int i = 0; i < pos; i++)
                act = act->getSig();
            
            act->setInfo(e);
        }
    }
}

/**
 * erase de lista
 * @function
 * @param {int} pos - Posicion a erase
 * */
template<class T>
void List<T>::erase(int pos)
{
    if (this->empty())
        throw "Lista vacia";
    else if (pos < 1 || pos > length)
        throw "Posicion invalida";
    else
    {
        Node<T> *ant, *act, *sig;
        if (pos == 1)
        {
            act = primero;
            primero = act->getSig();
        }
        else
        {
            act = primero;
            sig = act->getSig();
            
            for (int i = 0; i < pos; i++)
            {
                ant = act;
                act = sig;
                sig = sig->getSig();
            }
            ant->setSig(sig);
        }
        delete act;
        length--;
    }
}

/**
 * clear lista.
 * */
template<class T>
void List<T>::clear()
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


/**
 * Invertir List.
 * Invierte los elementos de la Lista.
 * */
template<class T>
void List<T>::reverse()
{
    this->ultimo = _reverse(this->primero);
    this->ultimo->setSig(NULL);
}

/**
 * @desc sublist.
 * Genera una sublist a partir de una List inicial.
 * @function
 * @param {int} low - Posicion incial de la sublist.
 * @param {int} high - Posicion final de la sublist.
 * @returns {Lista<Item>} sublist generada.
 * */
template<class T>
List<T> List<T>::sublist(int low, int high)
{
    // Swap preventivo
    if (low > high)
    {
        int aux = low;
        low = high;
        high = aux;
    }

    List<T> *lista = new List<T>();

    if ((low >= 1 && low <= length) && (high >= 1 && high <= length))
    {

        Node<T> *aux = primero;
        Node<T> *aux2 = NULL;
        Node<T> *nuevo;

        for (int i = 1; i <= high; i++)
        {
            if (i >= low)
            {
                nuevo = new Node<T>(*aux);

                if (i == low)
                    lista->primero = nuevo;
                else
                    aux2->setSig(nuevo);

                aux2 = nuevo;
            }
            aux = aux->getSig();
        }
        ultimo = nuevo;
        lista->length = abs(high - low) + 1;
    }
    return *lista;
}

/**
 * Ordena los elementos de la lista.
 * Ordena de menor a mayor los elementos de la lista, utilizando
 * el algoritmo de ordenamiento Bubble Sort.
 * */
template<class T>
void List<T>::sort()
{
    if (!sorted())
    {
        int n = this->length;
        for (int pasada = 0; pasada < n - 1; pasada++)
        {
            Node<T> *pivot = this->primero;
            Node<T> *pivotNext = pivot->getSig();
            for (int j = 0; j < n - pasada - 1; j++)
            {
                if (pivot->getInfo() > pivotNext->getInfo())
                    Node<T>::intercambiar(pivot, pivotNext);

                pivot = pivotNext;
                pivotNext = pivotNext->getSig();
            }
        }
    }
}

/**
 * Indica si la lista esta ordenada.
 * @function
 * @returns {bool} TRUE sí esta ordenada
 * */
template<class T>
bool List<T>::sorted() const
{
    bool ordenada = true;
    if (!empty())
    {
        Node<T> *pivot = this->primero;
        Node<T> *pivotNext = pivot->getSig();
        int i = 0;

        do
        {
            if (pivot->getInfo() > pivotNext->getInfo())
                ordenada = false;

            pivot = pivotNext;
            pivotNext = pivotNext->getSig();
            i++;
        } while (i < length && pivotNext != NULL && ordenada);

    }
    return ordenada;
}

/**
 * Sobrecarga de operador de ostream (Out Stream) para Lista.
 * Permite mostrar por pantalla el contenido de la lista mediante el uso del operador '<<'
 * Necesita que el 'Item' a sobrecargar igualmente pueda ser mostrado por pantalla
 * utilizando este mismo operador.
 * */
template<class T>
std::ostream& operator<<(std::ostream& out, const List<T> &list)
{
    Node<T> *Node;
    Node = list.primero;
    for (int i = 0; i < list.length; i++, Node = Node->getSig())
        if (Node != list.ultimo)
            out << Node->getInfo() << " ";
        else
            out << Node->getInfo();

    return out;
}

/**
 * Sobrecarga de operador de Asignacion para Lista.
 * Permite hacer una copia de una lista mediante el uso del operador '='.
 * Ejemplo: Lista2 = Lista1.sublist(a, b).
 * */
template<class T>
void List<T>::operator=(const List<T> & list)
{
    if (this != &list)
    {
        Node<T> *listPivot = list.primero;
        Node<T> *thisPivot = this->primero;
        Node<T> *nuevo;
        for (int i = 1; i <= list.length; i++, listPivot = listPivot->getSig())
        {
            nuevo = new Node<T>();
            nuevo->setInfo(listPivot->getInfo());

            if (i == 1)
            {
                this->primero = nuevo;
                thisPivot = nuevo;
            }
            else
            {
                thisPivot->setSig(nuevo);
                thisPivot = thisPivot->getSig();
            }
        }
        ultimo = nuevo;
        this->length = list.length;
    }
}

/**
 * Sobrecarga de operador de Mayor Que para Lista.
 * Indica si una Lista tiene o no mas elementos que otra, utilizando
 * el operador '>'.
 * */
template<class T>
bool List<T>::operator>(const List<T> &v) const
{
    if (this != &v)
        return (this->length > v.length);

    return false;
}

/**
 * Sobrecarga de operador de Menor Que para Lista.
 * Indica si una Lista tiene o no menos elementos que otra, utilizando
 * el operador '<'.
 * */
template<class T>
bool List<T>::operator<(const List<T> &v) const
{
    return !(*this > v);
}

/**
 * Sobrecarga de operador de Igual Que para Lista.
 * Indica si una Lista tiene o no los mismos elementos que otra,
 * utilizando el operador '=='.
 * */
template<class T>
bool List<T>::operator==(const List<T> &v) const
{
    if (this != &v)
    {
        if (this->length == v.length)
        {
            Node<T> *thisPivot = this->primero;
            Node<T> *vPivot = v.primero;
            bool esIgual;
            int i = 0;

            do
            {
                esIgual = (thisPivot->getInfo() == vPivot->getInfo());
                i++;
            } while (i <= this->length && esIgual);

            return esIgual;
        }

        return false;
    }

    return true;
}


/**
 * Sobrecarga de operador de Mayor o Igual Que para Lista.
 * Indica si una Lista tiene mas elementos o es igual que otra,
 * utilizando el operador '>='.
 * */
template<class T>
bool List<T>::operator>=(const List<T> &v) const
{
    if (this != &v)
        return (*this > v || *this == v);

    return true;
}


/**
 * Sobrecarga de operador de Menor o Igual Que para Lista.
 * Indica si una Lista tiene menos elementos o es igual que otra,
 * utilizando el operador '<='.
 * */
template<class T>
bool List<T>::operator<=(const List<T> &v) const
{
    if (this != &v)
        return (*this < v || *this == v);

    return true;
}

/**
 * Invertir lista.
 * Helper Method para Invertir la List.
 * Invierte los elementos de la List recursivamente.
 * Esta funcion debe mantenerse como privada.
 * @private
 * */
template<class T>
Node<T>* List<T>::_reverse(Node<T>*Node)
{
    if (Node->getSig() == NULL) // ¿Es el ultimo Node?
        this->primero = Node;
    else
        _reverse(Node->getSig())->setSig(Node);

    return Node;
}

/**
 * Dessort la lista dada.
 * Helper Method para el Algoritmo de QuickSort.
 * Privado porque no le veo uso fuera del algoritmo de QuickSort.
 * Su nivel de acceso puede ser modificado sí es necesario.
 * @private */
template<class T>
void List<T>::_dessort()
{
    std::srand(time(NULL));
    Node<T> *iPivot = this->primero;
    Node<T> *jPivot;
    for (int i = 0; i < this->length; i++)
    {
        int r = std::rand() % (i + 1);
        jPivot = this->primero;

        for (int j = 0; j < r; j++)
            jPivot = jPivot->getSig();

        Node<T>::intercambiar(iPivot, jPivot);

        iPivot = iPivot->getSig();
    }
}

#endif
