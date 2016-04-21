#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
	int n = 10, m = 100, x;
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

