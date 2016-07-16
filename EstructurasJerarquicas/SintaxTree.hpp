/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#ifndef _SINTAX_TREE_HPP_
#define _SINTAX_TREE_HPP_
#include <list>
#include <string>
#include <sstream>
#include "BinaryTree.hpp"

using namespace std;

class SintaxTree : public BinaryTree<string>
{
    public:
		SintaxTree() : BinaryTree<string>() { };
        SintaxTree(NodeBT<string> *p) : BinaryTree<string>(p) { };
        SintaxTree(const SintaxTree &p) : BinaryTree<string>(p) { };
        SintaxTree(list<string> p, list<string> in, Traverse t) : BinaryTree<string>(p, in, t) { };
        
        float solve() const;
        
    private:
        float solve(NodeBT<string>*) const;
};

float SintaxTree::solve() const
{
    return solve(_root);
}

float SintaxTree::solve(NodeBT<string>* p) const
{
    if(p)
    {
        string key = p->getKey();
    
        if (key == "+") return solve(p->getLeft()) + solve(p->getRight());
        else if (key == "-") return solve(p->getLeft()) - solve(p->getRight());
        else if (key == "*") return solve(p->getLeft()) * solve(p->getRight());
        else if (key == "/") return solve(p->getLeft()) / solve(p->getRight());
        else return stof(key);
    }
    return 0;
}

// In case everything fails..
// Everything == -std=c++11
//~ stringstream ss("string");
//~ float number;
//~ ss >> number;

#endif
