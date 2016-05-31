#include <iostream>
#include "BinaryTree.hpp"
#include "BST.hpp"

using namespace std;

int main(int argc, char **argv)
{
    BST<int> arbol;
    
    arbol.insert(4);
    arbol.insert(2);
    arbol.insert(6);
    arbol.insert(1);
    arbol.insert(3);
    arbol.insert(5);
    
    arbol.print(preorden);
    
    return 0;
}

