#include <iostream>
#include <cstdlib>
#include <string>
#include "../EstructurasLineales/Lista.hpp"
#include "SintaxTree.hpp"
#include "BinaryTree.hpp"
#include "Tree.hpp"
#include "BST.hpp"
#include "AVL.hpp"

using namespace std;

int main(int argc, char **argv)
{    
    AVL<string> tree;
    
    tree.insert("M");
    tree.insert("E");
    tree.insert("R");
    tree.insert("V");
    
    tree.insert("Z");
    
    return 0;
}

