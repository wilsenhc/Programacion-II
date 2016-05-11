#ifndef _NODE_N_TREE_HPP_
#define _NODE_N_TREE_HPP_

template<class T>
class NodeN
{
    private:
        T _key;
        NodeN<T> *_leftChild, *_rightSilbing;
    
    public:
        NodeN();
        
        T getKey() const { return _key; }
        NodeN<T>* getLeft() const { return _leftChild; }
        NodeN<T>* getRight() const { return _rightSilbing; }
        
        void setKey(const T);
        void setLeft(const NodeN<T>*);
        void setRight(const NodeN<T>*);
};

/**
 * Key setter.
 * */
template<class T>
void NodeN<T>::setKey(const T item)
{
    _key = item;
}

/**
 * Left child setter.
 * */
template<class T>
void NodeN<T>::setLeft(const NodeN<T>* l)
{
    _leftChild = l;
}

/**
 * Right Silbing setter.
 * */
template<class T>
void NodeN<T>::setRight(const NodeN<T>* r)
{
    _rightSilbing = r;
}

#endif