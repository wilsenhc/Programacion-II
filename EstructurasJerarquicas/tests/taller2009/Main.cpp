#include <iostream>
#include <cstring>
#include "../../BinaryTree.hpp"
#include "../../../EstructurasLineales/Lista.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Lista<string> orden, inorden;
    string instring;
    BinaryTree<string> *sintaxis;
    Traverse recorrido;
    
    while (!cin.eof())
    {
        cin >> instring;

        if (instring == "PREORDEN")
            recorrido = preorden;
        else if (instring == "POSTORDEN")
            recorrido = postorden;
        
        while (instring != "INORDEN")
		{
			cin >> instring;
			if (instring != "INORDEN")
				orden.pushUltimo(instring);
		}
		
		while (instring != "\n")
		{
			cin >> instring;
			if (instring != "\n")
				inorden.pushUltimo(instring);
		}
		
		sintaxis = new BinaryTree<string>(orden, inorden, recorrido);
	}
    
    return 0;
}

