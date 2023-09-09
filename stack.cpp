#include "stack.h"
#include "Baralho.h"
#include <iostream>
using namespace std;

void Stack::IniciarPilha(Carta &x)
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
void Stack::MoverCarta(int p_esta, int p_vai)
{
}
bool Stack::Hierarquia(int p_esta, int p_vai)
{
    if (TopColumn[p_esta].naipe % 2 == TopColumn[p_vai].naipe % 2)
        return false;
    else
        return true;
}