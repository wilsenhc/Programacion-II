/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _DOUBLY_LINKED_LIST_HPP_
#define _DOUBLY_LINKED_LIST_HPP_
#include <iostream>
#include "Binode.hpp"

template<class T>
class DoublyLinkedList
{
    private:
        Binode<T> *_first, *_last;
        int _length;

    public:
        DoublyLinkedList() : _first(NULL), _last(NULL), _length(0) {};
        DoublyLinkedList(const DoublyLinkedList&);
        ~DoublyLinkedList() { clear(); };

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
        void bubblesort();
        void quicksort();

        void operator=(const DoublyLinkedList&);
        bool operator>(const DoublyLinkedList&) const;
        bool operator<(const DoublyLinkedList&) const;
        bool operator==(const DoublyLinkedList&) const;
        bool operator>=(const DoublyLinkedList&) const;
        bool operator<=(const DoublyLinkedList&) const;
        
        template<class Ts>
        friend std::ostream& operator<<(std::ostream&, const DoublyLinkedList<Ts> &);

    private:
        void quicksort(int, int, Binode<T>*, Binode<T>*);
        Binode<T>* quicksort_divide(int, int, Binode<T>*, Binode<T>*, int&);
        
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& arg)
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
bool DoublyLinkedList<T>::sorted() const
{
    bool isSorted = true;
    if (!empty())
    {
        Binode<T> *current = _first;
        Binode<T> *next = current->next();
        int i = 0;

        do
        {
            if (current->key() > next->key())
                isSorted = false;

            current = next;
            next = next->next();
            i++;
        } while (i < _length && next && isSorted);
    }
    return isSorted;
}

template<class T>
T DoublyLinkedList<T>::front() const
{
    if (_first)
        return _first->key();
    
    throw "Empty list";
}

template<class T>
T DoublyLinkedList<T>::back() const
{
    if(_last)
        return _last->key();
    
    throw "Empty list";
}

template<class T>
void DoublyLinkedList<T>::push_front(T e)
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
void DoublyLinkedList<T>::push_back(T e)
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
void DoublyLinkedList<T>::pop_front()
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
void DoublyLinkedList<T>::pop_back()
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
void DoublyLinkedList<T>::erase(int index)
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
void DoublyLinkedList<T>::change(T e, int index)
{
    if (empty())
        throw "Empty list";
    else if (index < 1 || index > _length + 1)
        throw "Index out of bounds";
    else
    {
        if (index == 1)
            _first->set_key(e);
        else if (index == _length)
            _last->set_key(e);
        else
        {
            Binode<T> *pivot = _first;
            for (int i = 1; i < index; i++)
                pivot = pivot->next();
            
            pivot->set_key(e);
        }
    }
}

template<class T>
void DoublyLinkedList<T>::clear()
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

template<class T>
void DoublyLinkedList<T>::reverse()
{
    Binode<T> *current = _first;
    Binode<T> *temp = NULL;

    if (current)
        _last = _first;

    while (current)
    {
        temp = current->prev();
        current->set_prev(current->next());
        current->set_next(temp);
        current = current->prev();
    }
    
    if (temp)
        _first = temp->prev();
}

template<class T>
void DoublyLinkedList<T>::sort()
{
    if (_length <= 20)
        this->bubblesort();
    else
        this->quicksort();
}

template<class T>
void DoublyLinkedList<T>::bubblesort()
{
    if (!sorted())
    {
        for(int p = 0, n = _length; p < n - 1; p++)
        {
            Binode<T> *pivot = _first;
            Binode<T> *next = pivot->next();
            for (int j = 0; j < n - p - 1; j++)
            {
                if (pivot->key() > next->key())
                    Binode<T>::swap(pivot, next);
                
                pivot = next;
                next = next->next();
            }
        }
    }
}

template<class T>
void DoublyLinkedList<T>::quicksort()
{
    if (!sorted())
    {
        quicksort(1, _length, _first, _last);
    }
}

template<class T>
void DoublyLinkedList<T>::quicksort(int start, int end, Binode<T>* nStart, Binode<T>* nEnd)
{
    int pivot;
    Binode<T> *nPivot = NULL;

    if (start < end)
    {
        nPivot = quicksort_divide(start, end, nStart, nEnd, pivot);

        // Recursive calls from here
        quicksort(start, pivot - 1, nStart, nPivot->prev());

        quicksort(pivot + 1, end, nPivot->next(), nEnd);
    }
}

template<class T>
Binode<T>* DoublyLinkedList<T>::quicksort_divide(int start, int end, Binode<T>* nStart, Binode<T>* nEnd, int& pivot)
{
    int left, right;
    Binode<T> *nLeft, *nRight;

    T ppivot = nStart->key();
    left = start;
    right = end;
    nLeft = nStart;
    nRight = nEnd;

    while (left < right)
    {
        while (nRight->key() > ppivot)
        {
            nRight = nRight->prev();
            right--;
        }

        while ((left < right) && (nLeft->key() <= ppivot))
        {
            nLeft = nLeft->next();
            left++;
        }

        if (left < right)
            Binode<T>::swap(nLeft, nRight);
    }

    Binode<T>::swap(nRight, nStart);

    pivot = right;
    return nRight;
}

template<class T>
void DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &list)
{
    if (this != &list)
    {
        this->clear();
        Binode<T> *listPivot = list._first;
        Binode<T> *thisPivot = this->_first;
        Binode<T> *nuevo;
        
        for (int i = 1; i <= list._length; i++, listPivot = listPivot->next())
        {
            nuevo = new Binode<T>();
            nuevo->set_key(listPivot->key());

            if (i == 1)
            {
                this->_first = nuevo;
                thisPivot = nuevo;
            }
            else
            {
                thisPivot->set_next(nuevo);
                nuevo->set_prev(thisPivot);
                thisPivot = thisPivot->next();
            }
        }
        _last = nuevo;
        this->_length = list._length;
    }
}

template<class T>
bool DoublyLinkedList<T>::operator>(const DoublyLinkedList<T> &v) const
{
    if (this != &v)
        return (this->_length > v._length);

    return false;
}

template<class T>
bool DoublyLinkedList<T>::operator<(const DoublyLinkedList<T> &v) const
{
    return !(*this > v);
}

template<class T>
bool DoublyLinkedList<T>::operator==(const DoublyLinkedList<T> &v) const
{
    if (this != &v)
    {
        if (this->_length == v._length)
        {
            Binode<T> *thisPivot = this->_first;
            Binode<T> *vPivot = v._first;
            bool isEqual;
            int i = 1;

            do
            {
                isEqual = (thisPivot->key() == vPivot->key());
                i++;
                thisPivot = thisPivot->next();
                vPivot = vPivot->next();
            } while(i <= this->_length && isEqual);

            return isEqual;
        }

        return false;
    }

    return true;
}

template<class T>
bool DoublyLinkedList<T>::operator>=(const DoublyLinkedList<T> &v) const
{
    if (this != &v)
        return (*this > v || *this == v);
    
    return true;
}


template<class T>
bool DoublyLinkedList<T>::operator<=(const DoublyLinkedList<T> &v) const
{
    if (this != &v)
        return (*this < v || *this == v);

    return true;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T> &list)
{
    Binode<T> *Node;
    Node = list._first;
    for (int i = 0; i < list._length; i++, Node = Node->next())
        if (Node != list._last)
            out << Node->key() << " ";
        else
            out << Node->key();

    return out;
}

#endif
