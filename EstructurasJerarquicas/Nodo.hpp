#ifndef _NODO_BINARY_TREE_HPP_
#define _NODO_BINARY_TREE_HPP_

template<class T>
class NodoBT
{
	private:
		T key;
		NodoBT<T> *parent, *left, *right;
	public:
		NodoBT();
		NodoBT(const NodoBT<T>&);
	
		T getKey();
		NodoBT<T>* getParent();
		NodoBT<T>* getLeft();
		NodoBT<T>* getRight();
		
		void setKey(T);
		void setParent(NodoBT<T>*);
		void setLeft(NodoBT<T>*);
		void setRight(NodoBT<T>*);
};

/**
 * Constructor de Nodo (para Binary Tree)
 * @constructs NodoBT
 * */
template<class T>
NodoBT<T>::NodoBT<T>()
	: key( 0 ), parent( NULL ), left( NULL ) right( NULL ) { };

/**
 * Constructor copia de Nodo (para Binary Tree)
 * @constructs NodoBT
 * */
template<class T>
NodoBT<T>::NodoBT<T>(const NodoBT<T>& in)
	: key(in.key), parent( NULL ), left( NULL ) right( NULL ) { }



#endif
