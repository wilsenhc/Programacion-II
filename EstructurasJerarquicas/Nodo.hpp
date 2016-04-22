#ifndef _NODO_BINARY_TREE_HPP_
#define _NODO_BINARY_TREE_HPP_
#include <iostream>

template<class T>
class NodoBT
{
	private:
		T key;
		NodoBT<T> *parent, *left, *right;
		
	public:
		NodoBT() : key(0), parent(NULL), left(NULL), right(NULL) { };
		NodoBT(const T in) : key(in), parent(NULL), left(NULL), right(NULL) { };
		NodoBT(const NodoBT<T>& in) : key(in.key), parent(NULL), left(NULL), right(NULL) { };
	
		T getKey() const { return key; }
		NodoBT<T>* getParent() const { return parent; }
		NodoBT<T>* getLeft() const { return left; }
		NodoBT<T>* getRight() const { return right; }
		
		void setKey(const T);
		void setParent(const NodoBT<T>*);
		void setLeft(const NodoBT<T>*);
		void setRight(const NodoBT<T>*);
};

/**
 * Key setter
 * */
template<class T>
void NodoBT<T>::setKey(const T item)
{
	key = item;
}

/**
 * Parent setter
 * */
template<class T>
void NodoBT<T>::setParent(const NodoBT<T>* p)
{
	parent = p;
}

/**
 * Left setter
 * */
template<class T>
void NodoBT<T>::setLeft(const NodoBT<T>* l)
{
	left = l;
}

/**
 * Right setter
 * */
template<class T>
void NodoBT<T>::setRight(const NodoBT<T>* r)
{
	right = r;
}

#endif
