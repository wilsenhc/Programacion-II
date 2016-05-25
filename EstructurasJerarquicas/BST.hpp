#ifndef _BINARY_SEARCH_TREE_HPP_
#define _BINARY_SEARCH_TREE_HPP_

template<class T>
class BST : public BinaryTree<T>
{
    void insert(T);
    bool search(T) const;
    void del(T);
};

#endif
