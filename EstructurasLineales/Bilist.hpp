/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _BILIST_HPP_
#define _BILIST_HPP_
#include <iostream>
#include "Binode.hpp"

template<class T>
class Bilist
{
    private:
        Binode<T> *_first, *_last;
        int _length;

    public:
        Bilist() : _first(NULL), _last(NULL), _length(0) {};
        Bilist(const Bilist&);
        ~Bilist() { clear(); };

        bool empty() const { return _length == 0; };
        int size() const { return _length; };
        bool sorted() const;
        T front() const;
        T back() const;

        void push_front(T);
        void push_back(T);
        void pop_front();
        void pop_back();
        void erase(int);
        void change(T, int);
        void clear();
        void reverse();
        void sort();

        void operator=(const Bilist&);
        bool operator>(const Bilist&);
        bool operator<(const Bilist&);
        bool operator==(const Bilist&);
        bool operator>=(const Bilist&);
        bool operator<=(const Bilist&);
};

template<class T>
Bilist<T>::Bilist(const Bilist& arg)
{
    Binode<T> *argpivot = arg._first;
    Binode<T> *iprev = NULL;
    Binode<T> *add = NULL;
    _first = NULL;
    _length = arg._length;

    while(argpivot)
    {
        add = new Binode<T>(argpivot->key());
        if (_first)
        {
            add->set_prev(iprev);
            iprev->set_next(add);
        }
        else
            _first = add;

        iprev = add;
        argpivot = argpivot->next();
    }
    _last = add;
}

template<class T>
T Bilist<T>::front() const
{
    if (_first)
        return _first->key();
    
    throw "Empty list";
}

template<class T>
T Bilist<T>::back() const
{
    if(_last)
        return _last->key();
    
    throw "Empty list";
}

template<class T>
void Bilist<T>::push_front(T e)
{
    Binode<T> *add = new Binode<T>(e);
    
    if(_length == 0)
        _last = add;
    else
    {
        add->set_next(_first);
        _first->set_prev(add);
    }

    _first = add;
    _length++;
}

template<class T>
void Bilist<T>::push_back(T e)
{
    Binode<T> *add = new Binode<T>(e);
    
    if(_length == 0)
        _first = add;
    else
    {
        add->set_prev(_last);
        _last->set_next(add);
    }
    
    _last = add;
    _length++;
}

template<class T>
void Bilist<T>::pop_front()
{
    if (!empty())
    {
        Binode<T> *aux = _first;
        _first = aux->next();
        _first->set_prev(NULL);
        _length--;
        delete aux;
    }
    else
        throw "Empty list";
}

template<class T>
void Bilist<T>::pop_back()
{
    if (!empty())
    {
        Binode<T> *aux = _last;
        _last = aux->prev();
        _last->set_next(NULL);
        _length--;
        delete aux;
    }
    else
        throw "Empty list";
}

template<class T>
void Bilist<T>::erase(int index)
{
    if (empty())
        throw "Empty list";
    else if (index < 1 || index > _length + 1)
        throw "Index out of bounds";
    else
    {
        Binode<T> *aux;
        if (index == 1)
        {
            aux = _first;
            _first = aux->next();
            _first->set_prev(NULL);
        }
        else if (index == _length)
        {
            aux = _last;
            _last = aux->prev();
            _last->set_next(NULL);
        }
        else
        {
            Binode<T> *pivot = _first;
            for (int i = 1; i < index; i++)
                pivot = pivot->next();
            
            aux = pivot;
            aux->next()->set_prev(aux->prev());
            aux->prev()->set_next(aux->next());
        }
        delete aux;
        _length--;
    }
}

template<class T>
void Bilist<T>::clear()
{
    Binode<T> *pivot = _first;
    Binode<T> *aux;
    while (pivot)
    {
        aux = pivot;
        pivot = pivot->next();
        delete aux;
    }
    _first = NULL;
    _last = NULL;
    _length = 0;
}

#endif
