#include <iostream>
#include <string>
#include "../../EstructurasLineales/Lista.hpp"
#include "../BinaryTree.hpp"

using namespace std;

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m, j, k;
        char c;
        string porden;
        Traverse orden;
        Lista<char> P, IN;
        cin >> m >> j >> k;
        cin >> porden;
        
        if (porden == "PREORDEN")
            orden = preorden;
        else if (porden == "POSTORDEN")
            orden = postorden;
        
        for (int l = 0; l < m; l++)
        {
            cin >> c;
            P.pushUltimo(c);
        }
        
        cin >> porden;
        
        for (int l = 0; l < m; l++)
        {
            cin >> c;
            IN.pushUltimo(c);
        }
        
        BinaryTree<char> tree(P, IN, orden);
        
        tree.print(levels);
        cout << endl;
    }
    
    return 0;
}
