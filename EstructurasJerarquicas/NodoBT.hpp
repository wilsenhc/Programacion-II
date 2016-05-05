#ifndef _NODO_BINARY_TREE_HPP_
#define _NODO_BINARY_TREE_HPP_
#include <iostream>

template<class T>
class NodoBT
{
	private:
		T _key;
		NodoBT<T> *_left, *_right;
		
	public:
		NodoBT() : _key(0), _left(NULL), _right(NULL) { };
		NodoBT(const T in) : _key(in), _left(NULL), _right(NULL) { };
		NodoBT(const NodoBT<T>& in) : _key(in.key), _left(NULL), _right(NULL) { };
	
		T getKey() const { return _key; }
		NodoBT<T>* getLeft() const { return _left; }
		NodoBT<T>* getRight() const { return _right; }
		bool isLeaf() const { return _left == NULL && _right == NULL; }
		bool isFullNode() const { return _left != NULL || _right != NULL; }

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
	_key = item;
}

/**
 * Left setter
 * */
template<class T>
void NodoBT<T>::setLeft(const NodoBT<T>* l)
{
	_left = l;
}

/**
 * Right setter
 * */
template<class T>
void NodoBT<T>::setRight(const NodoBT<T>* r)
{
	_right = r;
}

#endif
