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
                       VALETE,
                       DAMA,
                       REI};
    Naipe naipe[4] = {OUROS,
                      ESPADAS,
                      COPAS,
                      PAUS};
    for (int i = 0; i < 4; i++)
    {
        int count = i * REI;
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
        int j = rand() % 52;
        temp = BaralhoCompleto[i];
        BaralhoCompleto[i] = BaralhoCompleto[j];
        BaralhoCompleto[j] = temp;
    }
}
void Baralho::Ordenar()
{
}