/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _DEQUE_HPP_
#define _DEQUE_HPP_
#include <iostream>
#include "Binode.hpp"

template<class T>
class Deque
{
    private:
        Binode<T> *_first, *_last;
        int _length;

    public:
        Deque() : _first(NULL), _last(NULL), _length(0) {};
        Deque(const Deque&);
        ~Deque() { clear(); };

        bool empty() const { return _length == 0; };
        int size() const { return _length; };
        T front() const;
        T back() const;

        void push_front(T);
        void push_back(T);
        void pop_front();
        void pop_back();
        void clear();
}

template<class T>
Deque<T>::Deque(const Deque& arg)
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
T Deque<T>::front() const
{
    if (_first)
        return _first->key();
    
    throw "Empty queue";
}

template<class T>
T Deque<T>::back() const
{
    if(_last)
        return _last->key();
    
    throw "Empty queue";
}

template<class T>
void Deque<T>::push_front(T e)
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
void Deque<T>::push_back(T e)
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
void Deque<T>::pop_front()
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
        throw "Empty queue";
}

template<class T>
void Deque<T>::pop_back()
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
        throw "Empty queue";
}

template<class T>
void Deque<T>::clear()
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