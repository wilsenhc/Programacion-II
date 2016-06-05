#include <iostream>
#include <string>
#include "../../EstructurasLineales/Lista.hpp"
#include "../BinaryTree.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Lista<string> POST, IN;
    
    POST.pushUltimo("d");
    POST.pushUltimo("b");
    POST.pushUltimo("f");
    POST.pushUltimo("g");
    POST.pushUltimo("e");
    POST.pushUltimo("c");
    POST.pushUltimo("a");
    
    IN.pushUltimo("d");
    IN.pushUltimo("b");
    IN.pushUltimo("a");
    IN.pushUltimo("f");
    IN.pushUltimo("e");
    IN.pushUltimo("g");
    IN.pushUltimo("c");
    
    BinaryTree<string> tree(POST, IN, postorden);
    
    return 0;
}
