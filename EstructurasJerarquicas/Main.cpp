#include <iostream>
#include <cstdlib>
#include <string>
#include "../EstructurasLineales/Lista.hpp"
#include "SintaxTree.hpp"
#include "BinaryTree.hpp"
#include "Tree.hpp"
#include "BST.hpp"

using namespace std;

int main(int argc, char **argv)
{
    BST<int> tree, tree2;
    
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        tree.insert(rand() % 1000);
        tree2.insert(rand() % 100);
    }
    
    cout << (tree == tree2) << endl;
    tree2 = tree;
    cout << (tree == tree2) << endl;
    tree.mirror();
    
    return 0;
}

