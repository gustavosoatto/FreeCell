#ifndef FREECELL_H
#define FREECELL_H
#include "T_Baralho.h"

class FreeCell
{
private:
    int count = 0;
    Carta Entry[TotalCartas],
        TopColumn[13];

public:
    FreeCell() = default;
    ~FreeCell() = default;
    void IniciarPilha(Carta &x);
    void Mesa();
    void MoverCarta(int p_esta, int p_vai);
    bool Hierarquia(int p_esta, int p_vai);
    void ExibirMesa();
};

#endif // FREECELL_H