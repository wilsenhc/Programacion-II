#include <iostream>

#include "BinaryTree.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Lista<int> pre, in, post;
    
    pre.insertar(10,1);
    pre.insertar(20,2);
    pre.insertar(40,3);
    pre.insertar(80,4);
    pre.insertar(50,5);
    pre.insertar(90,6);
    pre.insertar(30,7);
    pre.insertar(60,8);
    pre.insertar(70,9);
    pre.insertar(100,10);
    pre.insertar(110,11);
    pre.insertar(120,12);
    
    in.insertar(80,1);
    in.insertar(40,2);
    in.insertar(20,3);
    in.insertar(50,4);
    in.insertar(90,5);
    in.insertar(10,6);
    in.insertar(60,7);
    in.insertar(30,8);
    in.insertar(100,9);
    in.insertar(70,10);
    in.insertar(110,11);
    in.insertar(120,12);
    
    post.insertar(80,1);
    post.insertar(40,2);
    post.insertar(90,3);
    post.insertar(50,4);
    post.insertar(20,5);
    post.insertar(60,6);
    post.insertar(100,7);
    post.insertar(120,8);
    post.insertar(110,9);
    post.insertar(70,10);
    post.insertar(30,11);
    post.insertar(10,12);
    
    BinaryTree<int> tree(pre, in, preorden);
    BinaryTree<int> tree2(post, in, postorden);
    
    return 0;
}

