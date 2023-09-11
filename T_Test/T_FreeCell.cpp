#include "T_Baralho.h"
#include "T_FreeCell.h"
#include <iostream>
using namespace std;

void FreeCell::IniciarPilha(Carta &x)
{
    Entry[count] = x;
    if (count < 7)
        TopColumn[1] = Entry[count];
    else if (count < 14)
        TopColumn[2] = Entry[count];
    else if (count < 21)
        TopColumn[3] = Entry[count];
    else if (count < 28)
        TopColumn[4] = Entry[count];
    else if (count < 34)
        TopColumn[5] = Entry[count];
    else if (count < 40)
        TopColumn[6] = Entry[count];
    else if (count < 46)
        TopColumn[7] = Entry[count];
    else if (count < 52)
        TopColumn[8] = Entry[count];
    count++;
}
void ExibirMesa()
{
}
void FreeCell::Mesa()
{
    Baralho baralho;
    FreeCell jogo;

    baralho.Embaralhar();
    for (int i = 0; i < TotalCartas; i++)
    {
        jogo.IniciarPilha(baralho.BaralhoCompleto[i]);
    }

    for (int i = 0; i < TotalCartas; i++)
    {
        char naipe = jogo.Entry[i].naipe;
        if (jogo.Entry[i].valor == A || jogo.Entry[i].valor == J || jogo.Entry[i].valor == Q || jogo.Entry[i].valor == K)
        {
            char valor = jogo.Entry[i].valor;
            cout << "[ " << valor << "-" << naipe << " ] ";
        }
        else
        {
            if (jogo.Entry[i].valor == 10)
                cout << "[" << jogo.Entry[i].valor << "-" << naipe << " ] ";
            else
                cout << "[ " << jogo.Entry[i].valor << "-" << naipe << " ] ";
        }
        for (int j = 1; j < 9; j++)
            if (jogo.Entry[i].valor == jogo.TopColumn[j].valor && jogo.Entry[i].naipe == jogo.TopColumn[j].naipe)
                cout << endl;
    }
    cout << "===============================================================" << endl;
    for (int j = 1; j < 9; j++)
        cout << " [ " << j << " ]  ";
    cout << endl;
}
void FreeCell::MoverCarta(int p_esta, int p_vai)
{
}
bool FreeCell::Hierarquia(int p_esta, int p_vai)
{
    if (TopColumn[p_esta].naipe % 2 == TopColumn[p_vai].naipe % 2)
        return false;
    else
        return true;
}