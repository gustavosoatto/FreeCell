#ifndef FREECELL_H
#define FREECELL_H
#include "Baralho.h"

class FreeCell
{
private:
    int count = 0;
    Carta Entry[TotalCartas],
        *TopColumn[13];

    void IniciarPilha(Carta &x); // Inicializa as 8 pilhas de jogo e as FreeCells
    void ExibirMesa();
    bool Hierarquia(int p_esta, int p_vai);
    void MoverEntreColuna(int &p_esta, int &p_vai);
    void MoverFreeCell(int &p_esta, int &p_vai);

public:
    FreeCell() = default;
    ~FreeCell() = default;
    void Mesa();
    void MoverCarta(int &p_esta, int &p_vai);
};

#endif // FREECELL_H