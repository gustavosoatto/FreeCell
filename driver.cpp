#include "Baralho.h"
#include "FreeCell.h"
#include <iostream>
using namespace std;

int main()
{
    FreeCell FreeCell;
    char newgame;

    while (newgame != 'n')
    {
        FreeCell.Mesa();
        cout << "Deseja jogar novamente: (s/n) " << endl;
        cin >> newgame;
    }
}