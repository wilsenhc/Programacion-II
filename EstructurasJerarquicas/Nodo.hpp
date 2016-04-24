#ifndef _NODO_BINARY_TREE_HPP_
#define _NODO_BINARY_TREE_HPP_
#include <iostream>

template<class T>
class NodoBT
{
	private:
		T key;
		NodoBT<T> *left, *right;
		
	public:
		NodoBT() : key(0), left(NULL), right(NULL) { };
		NodoBT(const T in) : key(in), left(NULL), right(NULL) { };
		NodoBT(const NodoBT<T>& in) : key(in.key), left(NULL), right(NULL) { };
	
		T getKey() const { return key; }
		NodoBT<T>* getLeft() const { return left; }
		NodoBT<T>* getRight() const { return right; }
		
		void setKey(const T);
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
