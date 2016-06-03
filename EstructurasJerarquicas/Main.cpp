#include <iostream>
#include <string>
#include "SintaxTree.hpp"
#include "BinaryTree.hpp"
#include "BST.hpp"

using namespace std;

int main(int argc, char **argv)
{
    BST<string> tree;
    
    tree.insert("S");
    tree.insert("E");
    tree.insert("X");
    tree.insert("A");
    tree.insert("R");
    tree.insert("C");
    tree.insert("H");
    tree.insert("M");
    tree.insert("W");
    
    cout << tree.min() << endl;
    cout << tree.max() << endl;
    
    tree.del("S");
    tree.del("E");
    
    return 0;
}

