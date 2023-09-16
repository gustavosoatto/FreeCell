#ifndef FREECELL_H
#define FREECELL_H
#include "Baralho.h"

struct CelulaVazia{
    Carta carta; // carta que esta na FreeCell
    bool vazia; // indica se esta vazia ou nao
};

class FreeCell
{
private:
    int count = 0;
    Carta Entry[TotalCartas],
        *TopColumn[13];

    CelulaVazia celulaVazia[4]; // adiciona as 4 FreeCells

    Carta PilhaSaida[4]; // vetor das 4 pilhas de saida

    void IniciarPilha(Carta &x); // Inicializa as 8 pilhas de jogo e as FreeCells
    void ExibirMesa();
    bool Hierarquia(int p_esta, int p_vai);

public:
    FreeCell() = default;
    ~FreeCell() = default;
    void Mesa();
    void MoverCarta(int &p_esta, int &p_vai);
    void MoverParaCelulaVazia(int p_vai, Carta carta); // qual das 4 FreeCells o jogador deseja usar para mover a carta e carta que o jogador deseja mover para a FreeCell
    void MoverDaCelulaVaziaParaJogo(int p_esta, int p_vai); // qual das 4 FreeCells o jogador deseja usar para mover a carta e para qual coluna do jogo o jogador deseja mover a carta da FreeCell
    void MoverParaPilhaDeSaida(int p_esta);
};

#endif // FREECELL_H