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
        int length;

    public:
        Bilist() : _first(NULL), _last(NULL), length(0) {};
        Bilist(const Bilist&);
        ~Bilist();

        bool empty() const { return length == 0; };
        int size() const { return length; };
        bool sorted() const;
        T front() const;
        T back() const;

        void push_front();
        void push_back();
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

#endif