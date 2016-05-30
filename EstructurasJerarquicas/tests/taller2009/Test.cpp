#include <iostream>
#include <string>
#include "../../SintaxTree.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Lista<string> pre, in;
    
    pre.insertar("+",1);
    pre.insertar("-",2);
    pre.insertar("*",3);
    pre.insertar("5",4);
    pre.insertar("7",5);
    pre.insertar("3",6);
    pre.insertar("*",7);
    pre.insertar("6",8);
    pre.insertar("+",9);
    pre.insertar("2",10);
    pre.insertar("1",11);
    
    in.insertar("5",1);
    in.insertar("*",2);
    in.insertar("7",3);
    in.insertar("-",4);
    in.insertar("3",5);
    in.insertar("+",6);
    in.insertar("6",7);
    in.insertar("*",8);
    in.insertar("2",9);
    in.insertar("+",10);
    in.insertar("1",11);
    
    SintaxTree tree(pre, in, preorden);

    cout << tree.evaluar() << endl;
    
    return 0;
}
