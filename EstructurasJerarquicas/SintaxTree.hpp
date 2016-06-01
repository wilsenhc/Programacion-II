#ifndef _SINTAX_TREE_HPP_
#define _SINTAX_TREE_HPP_
#include <string>
#include "../EstructurasLineales/Lista.hpp"
#include "BinaryTree.hpp"

using namespace std;

class SintaxTree : public BinaryTree<string>
{
    public:
		SintaxTree() : BinaryTree<string>() { };
        SintaxTree(NodeBT<string> *p) : BinaryTree<string>(p) { };
        SintaxTree(const SintaxTree &p) : BinaryTree<string>(p) { };
        SintaxTree(Lista<string> p, Lista<string> in, Traverse t) : BinaryTree<string>(p, in, t) { };
        
        float evaluar() const;
        
    private:
        float evaluar(NodeBT<string>*) const;
};

float SintaxTree::evaluar() const
{
    return evaluar(_root);
}

float SintaxTree::evaluar(NodeBT<string>* p) const
{
    if(p)
    {
        string key = p->getKey();
    
        if (key == "+") return evaluar (p->getLeft()) + evaluar(p->getRight());
        else if (key == "-") return evaluar (p->getLeft()) - evaluar(p->getRight());
        else if (key == "*") return evaluar (p->getLeft()) * evaluar(p->getRight());
        else if (key == "/") return evaluar (p->getLeft()) / evaluar(p->getRight());
        else return stof(key);
    }
    return 0;
}

#endif
