/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
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

