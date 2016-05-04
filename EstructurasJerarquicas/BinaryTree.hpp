#ifndef _ARBOL_BINARIO_HPP_
#define _ARBOL_BInARIO_HPP_
#include "Nodo.hpp"

template<class T>
class BinaryTree
{
        private:
            NodoBT<T> *_parent;
        public:
            BinaryTree() : _parent(NULL) {};
            ~BinaryTree();
            
            bool isNull() const { return _parent == NULL; }
            BinaryTree getLeft();
            BinaryTree getRight();
};


#endif
