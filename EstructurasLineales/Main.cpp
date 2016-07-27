/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Wilsen Hernandez. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/
#include <iostream>
#include "Bilist.hpp"

using namespace std;

void a(Bilist<int> b)
{
    b.erase(5);
    b.pop_front();
    b.pop_back();
    cout << "A END" << endl;
}

int main(int argc, char **argv)
{
    Bilist<int> l;

    for (int i = 1; i <= 10; i++)
        l.push_back(i);

    a(l);
    
    l.reverse();

    return 0;
}

