#include "Baralho.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

Baralho::Baralho()
{
    Ordem valor[13] = {A,
                       DOIS,
                       TRES,
                       QUATRO,
                       CINCO,
                       SEIS,
                       SETE,
                       OITO,
                       NOVE,
                       DEZ,
                       J,
                       Q,
                       K};
    Naipe naipe[4] = {U,
                      E,
                      C,
                      P};
    for (int i = 0; i < 4; i++)
    {
        int count = i * 13;
        for (int j = 0; j < 13; j++)
        {
            BaralhoCompleto[j + count].valor = valor[j];
            BaralhoCompleto[j + count].naipe = naipe[i];
        }
    }
}
void Baralho::Embaralhar()
{
    srand(static_cast<unsigned int>(time(0)));
    Carta temp;
    for (int i = 0; i < TotalCartas; i++)
    {
        int j = rand() % TotalCartas;
        temp = BaralhoCompleto[i];
        BaralhoCompleto[i] = BaralhoCompleto[j];
        BaralhoCompleto[j] = temp;
    }
}