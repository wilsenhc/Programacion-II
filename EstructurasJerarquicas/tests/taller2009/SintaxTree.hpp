#ifndef _SINTAX_TREE_HPP_
#define _SINTAX_TREE_HPP_
#include <cstring>
#include "../../BinaryTree.hpp"

class SintaxTree : BinaryTree<string>
{
    public:
        float evaluar() const;
};

#endif
