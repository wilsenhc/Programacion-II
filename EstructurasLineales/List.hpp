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
        Node<T> *_first;
        Node<T> *_last;

    public:
        List() : length(0), _first(NULL), _last(NULL) { };
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

template<class T>
List<T>::List(const List<T>& in)
{
    if (in._first != NULL)
    {
        _first = new Node<T>(in._first->key());
        Node<T> *inaux = in._first->next();
        Node<T> *thisaux = this->_first;
        Node<T> *nuevo;
        while (inaux != NULL)
        {
            nuevo = new Node<T>(inaux->key());
            thisaux->set_next(nuevo);
            thisaux = thisaux->next();
            inaux = inaux->next();
        }
        _last = nuevo;
    }
    this->length = in.length;
}

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
            _first = nuevo;
            _last = nuevo;
        }
        else if (pos == 1)
        {
            nuevo->set_next(_first);
            _first = nuevo;
        }
        else if (pos == length + 1)
        {
            _last->set_next(nuevo);
            _last = nuevo;
        }
        else
        {
            actual = _first;
            siguiente = actual->next();
            for (int i = 2; i < pos; i++)
            {
                actual = siguiente;
                siguiente = siguiente->next();
            }
            actual->set_next(nuevo);
            nuevo->set_next(siguiente);
        }
        length++;
    }
}

template<class T>
T List<T>::get(int pos) const
{
    if (pos < 1 || pos > length + 1)
        throw "Posicion invalida";
    else
    {
        if (pos == 1)
            return _first->key();
        else if (pos == length)
            return _last->key();
        else
        {
            Node<T> *act = _first;
            for (int i = 1; i < pos; i++)
                act = act->next();

            return act->key();
        }
    }
}

template<class T>
int List<T>::find(T e) const
{
    if (!empty())
    {
        Node<T> *pivot;
        int i = 0;
        
        pivot = _first;
        while (pivot != NULL)
        {
            if (pivot->key() == e)
                return i;
                
            pivot = pivot->next();
            i++;
        }
        return i;
    }
    
    return -1; // No encontrado
}

template<class T>
T List<T>::front() const
{
    if (_first)
        return this->_first->key();

    throw "Empty list"
}

template<class T>
T List<T>::back() const
{
    if (_last)
        return this->_last->key();
    
    throw "Empty list"
}

template<class T>
void List<T>::set_front(T e)
{
    _first->set_key(e);
}

template<class T>
void List<T>::set_back(T e)
{
    _last->set_key(e);
}

template<class T>
void List<T>::push_front(T e)
{
    Node<T> *nuevo = new Node<T>(e);
    if (!empty())
    {
        nuevo->set_next(_first);
        _first = nuevo;
    }
    else
    {
        _first = nuevo;
        _last = nuevo;
    }
    length++;
}

template<class T>
void List<T>::push_back(T e)
{
    Node<T> *nuevo = new Node<T>(e);
    if(!empty())
    {
        _last->set_next(nuevo);
        _last = nuevo;
    }
    else
    {
         _first = nuevo;
         _last = nuevo;
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
        e = _first->key();
        aux = _first;
        _first = aux->next();
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
        act = _first;
        for(int i = 0; i < length; i++)
        {
            ant = act;
            act = act->next();
        }
        ant->set_next(NULL);
        _last = ant;
        T e = act->key();
        delete act;
        return e;
    }
    return 0;
}

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
            _first->set_key(e);
        else if (pos == length)
            _last->set_key(e);
        else
        {
            Node<T> *act = _first;
            for (int i = 0; i < pos; i++)
                act = act->next();
            
            act->set_key(e);
        }
    }
}

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
            act = _first;
            _first = act->next();
        }
        else
        {
            act = _first;
            sig = act->next();
            
            for (int i = 0; i < pos; i++)
            {
                ant = act;
                act = sig;
                sig = sig->next();
            }
            ant->set_next(sig);
        }
        delete act;
        length--;
    }
}

template<class T>
void List<T>::clear()
{
    if (!empty())
    {
        Node<T> *actual, *next;
        actual = _first;
        next = actual->next();

        for (int i = 1; i < length; i++)
        {
            delete actual;
            actual = next;
            next = actual->next();
        }
        delete actual;

        length = 0;
        _first = NULL;
        _last = NULL;
    }
}

template<class T>
void List<T>::reverse()
{
    this->_last = _reverse(this->_first);
    this->_last->set_next(NULL);
}

template<class T>
List<T> List<T>::sublist(int low, int high)
{
    if (low > high)
    {
        int aux = low;
        low = high;
        high = aux;
    }

    List<T> *lista = new List<T>();

    if ((low >= 1 && low <= length) && (high >= 1 && high <= length))
    {

        Node<T> *aux = _first;
        Node<T> *aux2 = NULL;
        Node<T> *nuevo;

        for (int i = 1; i <= high; i++)
        {
            if (i >= low)
            {
                nuevo = new Node<T>(*aux);

                if (i == low)
                    lista->_first = nuevo;
                else
                    aux2->set_next(nuevo);

                aux2 = nuevo;
            }
            aux = aux->next();
        }
        _last = nuevo;
        lista->length = abs(high - low) + 1;
    }
    return *lista;
}

template<class T>
void List<T>::sort()
{
    if (!sorted())
    {
        int n = this->length;
        for (int pasada = 0; pasada < n - 1; pasada++)
        {
            Node<T> *pivot = this->_first;
            Node<T> *pivotNext = pivot->next();
            for (int j = 0; j < n - pasada - 1; j++)
            {
                if (pivot->key() > pivotNext->key())
                    Node<T>::swap(pivot, pivotNext);

                pivot = pivotNext;
                pivotNext = pivotNext->next();
            }
        }
    }
}

template<class T>
bool List<T>::sorted() const
{
    bool ordenada = true;
    if (!empty())
    {
        Node<T> *pivot = this->_first;
        Node<T> *pivotNext = pivot->next();
        int i = 0;

        do
        {
            if (pivot->key() > pivotNext->key())
                ordenada = false;

            pivot = pivotNext;
            pivotNext = pivotNext->next();
            i++;
        } while (i < length && pivotNext != NULL && ordenada);

    }
    return ordenada;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const List<T> &list)
{
    Node<T> *Node;
    Node = list._first;
    for (int i = 0; i < list.length; i++, Node = Node->next())
        if (Node != list._last)
            out << Node->key() << " ";
        else
            out << Node->key();

    return out;
}

template<class T>
void List<T>::operator=(const List<T> & list)
{
    if (this != &list)
    {
        Node<T> *listPivot = list._first;
        Node<T> *thisPivot = this->_first;
        Node<T> *nuevo;
        for (int i = 1; i <= list.length; i++, listPivot = listPivot->next())
        {
            nuevo = new Node<T>();
            nuevo->set_key(listPivot->key());

            if (i == 1)
            {
                this->_first = nuevo;
                thisPivot = nuevo;
            }
            else
            {
                thisPivot->set_next(nuevo);
                thisPivot = thisPivot->next();
            }
        }
        _last = nuevo;
        this->length = list.length;
    }
}

template<class T>
bool List<T>::operator>(const List<T> &v) const
{
    if (this != &v)
        return (this->length > v.length);

    return false;
}

template<class T>
bool List<T>::operator<(const List<T> &v) const
{
    return !(*this > v);
}

template<class T>
bool List<T>::operator==(const List<T> &v) const
{
    if (this != &v)
    {
        if (this->length == v.length)
        {
            Node<T> *thisPivot = this->_first;
            Node<T> *vPivot = v._first;
            bool esIgual;
            int i = 1;

            do
            {
                esIgual = (thisPivot->key() == vPivot->key());
                i++;
                thisPivot = thisPivot->next();
                vPivot = vPivot->next();
            } while (i <= this->length && esIgual);

            return esIgual;
        }

        return false;
    }

    return true;
}

template<class T>
bool List<T>::operator>=(const List<T> &v) const
{
    if (this != &v)
        return (*this > v || *this == v);

    return true;
}

template<class T>
bool List<T>::operator<=(const List<T> &v) const
{
    if (this != &v)
        return (*this < v || *this == v);

    return true;
}

template<class T>
Node<T>* List<T>::_reverse(Node<T> *arg)
{
    if (arg->next() == NULL)
        this->_first = arg;
    else
        _reverse(arg->next())->set_next(arg);

    return arg;
}

template<class T>
void List<T>::_dessort()
{
    std::srand(time(NULL));
    Node<T> *iPivot = this->_first;
    Node<T> *jPivot;
    for (int i = 0; i < this->length; i++)
    {
        int r = std::rand() % (i + 1);
        jPivot = this->_first;

        for (int j = 0; j < r; j++)
            jPivot = jPivot->next();

        Node<T>::swap(iPivot, jPivot);

        iPivot = iPivot->next();
    }
}

#endif
