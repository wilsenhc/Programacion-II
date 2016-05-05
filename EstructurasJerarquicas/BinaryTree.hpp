#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_
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
