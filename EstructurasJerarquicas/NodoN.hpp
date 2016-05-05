#ifndef _NODO_N_TREE_HPP_
#define _NODO_N_TREE_HPP_

template<class T>
class NodoN
{
    private:
        T _key;
        NodoN<T> *_leftSon, *_rightSilbing;
    
    public:
        NodoN();
        
        T getKey() const { return _key; }
        NodoN<T>* getLeft() const { return _leftSon; }
        NodoN<T>* getRight() const { return _rightSilbing; }
        
        void setKey(const T);
        void setLeft(const NodoN<T>*);
        void setRight(const NodoN<T>*);
};

template<class T>
void NodoN<T>::setKey(const T item)
{
    _key = item;
}

template<class T>
void NodoN<T>::setLeft(const NodoN<T>* l)
{
    _leftSon = l;
}

template<class T>
void NodoN<T>::setRight(const NodoN<T>* r)
{
    _rightSilbing = r;
}
#endif