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
		NodoBT();
		NodoBT(const T);
		NodoBT(const NodoBT<T>&);
	
		T getKey() const;
		NodoBT<T>* getParent() const;
		NodoBT<T>* getLeft() const;
		NodoBT<T>* getRight() const;
		
		void setKey(const T);
		void setParent(const NodoBT<T>*);
		void setLeft(const NodoBT<T>*);
		void setRight(const NodoBT<T>*);
};

/**
 * Constructor de Nodo (para Binary Tree)
 * @constructs NodoBT
 * */
template<class T>
NodoBT<T>::NodoBT()
	: key( 0 ), parent( NULL ), left( NULL ), right( NULL ) { };
	
/**
 * Constructor de Nodo (para Binary Tree)
 * @constructs NodoBT
 * */
template<class T>
NodoBT<T>::NodoBT(const T in)
	: key(in), parent( NULL ), left( NULL ), right( NULL ) { }

/**
 * Constructor copia de Nodo (para Binary Tree)
 * @constructs NodoBT
 * */
template<class T>
NodoBT<T>::NodoBT(const NodoBT<T>& in)
	: key(in.key), parent( NULL ), left( NULL ), right( NULL ) { }

/**
 * Key getter
 * */
template<class T>
T NodoBT<T>::getKey() const
{
	return key;
}

/**
 * Parent Node getter
 * */
template<class T>
NodoBT<T>* NodoBT<T>::getParent() const
{
	return parent;
}

/**
 * Left Node getter
 * */
template<class T>
NodoBT<T>* NodoBT<T>::getLeft() const
{
	return left;
}

/**
 * Right Node getter
 * */
template<class T>
NodoBT<T>* NodoBT<T>::getRight() const
{
	return right;
}

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
