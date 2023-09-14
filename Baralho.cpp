#include "Baralho.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

Baralho::Baralho()
{
    Ordem valor[13] = {AS,
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
    Naipe naipe[5] = {OUROS,
                      ESPADAS,
                      COPAS,
                      PAUS,
                      VAZIO};
    for (int i = 0; i < 4; i++)
    {
        int count = i * 13;
        for (int j = 0; j < 13; j++)
        {
            BaralhoCompleto[j + count].valor = valor[j];
            BaralhoCompleto[j + count].naipe = naipe[i];
        }
    }
    for (int i = 52; i < 152; i++)
        BaralhoCompleto[i].naipe = VAZIO;
}
void Baralho::Embaralhar()
{
    srand(static_cast<unsigned int>(time(0)));
    Carta temp;
    for (int i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        temp = BaralhoCompleto[i];
        BaralhoCompleto[i] = BaralhoCompleto[j];
        BaralhoCompleto[j] = temp;
    }
}