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
		NodoBT(const NodoBT&);
	
		T getKey();
		NodoBT<T>* getParent();
		NodoBT<T>* getLeft();
		NodoBT<T>* getRight();
		
		void setKey(T);
		void setParent(NodoBT<T>*);
		void setLeft(NodoBT<T>*);
		void setRight(NodoBT<T>*);
};

#endif
