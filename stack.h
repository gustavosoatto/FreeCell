#ifndef STACK_H
#define STACK_H

#include "Baralho.h"

class Stack
{
private:
    int count = 0;

public:
    Carta Entry[TotalCartas],
        TopColumn[K];
    Stack() = default;
    ~Stack() = default;
    void IniciarPilha(Carta &x);
    void MoverCarta(int p_esta, int p_vai);
    bool Hierarquia(int p_esta, int p_vai);
};

#endif // STACK_H