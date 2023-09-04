#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    srand(time(0));
    for (int i = 0; i < 52; i++)
    {
        int x = rand() % 52;
        cout << x << endl;
    }
}