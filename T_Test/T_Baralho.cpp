#include "../Baralho.h"
#include <iostream>
using namespace std;

int main()
{
    Baralho baralho1;
    for (int i = 0; i < 52; i++)
    {
        if (i % 13 == 0)
            cout << endl;

        cout << "[" << baralho1.BaralhoCompleto[i].valor << "-" << baralho1.BaralhoCompleto[i].naipe << "] ";
    }
    cout << "\n\nEMBARALHAR"
         << endl;
    baralho1.Embaralhar();
    for (int i = 0; i < 52; i++)
    {
        if (i % 13 == 0)
            cout
                << endl;

        cout << "[" << baralho1.BaralhoCompleto[i].valor << "-" << baralho1.BaralhoCompleto[i].naipe << "] ";
    }

    return 0;
}
