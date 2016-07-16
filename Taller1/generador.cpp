/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
    int n = 10, m = 50, x;
    srand(time(NULL));
    
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        x = rand() % m;
        cout << x << endl;
        for (int j = 0; j < x; j++)
        {
            cout << (rand() % m) << " ";
        }
        cout << endl;
    }
    
    return 0;
}

