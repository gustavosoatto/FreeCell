#ifndef FREECELL_H
#define FREECELL_H
#include "Baralho.h"

class FreeCell
{
private:
    int count = 0;            // Variável auxiliar para prencher "Entry[]"
    Carta Entry[TotalCartas], // Vetor de estruturas Carta que representa as cartas no jogo
        *TopColumn[13];       // Vetor de ponteiros para as cartas no topo de cada coluna de jogo

    void IniciarPilha(Carta &x);                    // Inicializa as 8 pilhas de jogo e as FreeCells
    void ExibirMesa();                              // Exibe a configuração atual do jogo, mostrando as cartas
    bool Hierarquia(int p_esta, int p_vai);         // Verifica se é permitido mover uma carta de uma coluna ou freecell para outra
    void MoverEntreColuna(int &p_esta, int &p_vai); // Move uma carta entre as colunas de jogo
    bool CartaFreecell(int &position);              // Verifica se uma movimentação envolve alguma freecell
    void MoverFreeCell(int &p_esta, int &p_vai);    // Faz uma movimentação que envolve alguma freecell
    bool HierarquiaSaida(int p_esta, int p_vai);    // Verifica se é permitido mover uma carta para as colunas de saída
    void MoverSaida(int &p_esta, int &p_vai);       // Move uma carta para as colunas de saída
    void MoverCarta(int &p_esta, int &p_vai);       // Coordena todas as movimentações de cartas no jogo
    bool Ganhou();                                  // Verifica se o jogo foi ganho

public:
    FreeCell() = default;
    ~FreeCell() = default;
    void Mesa(); // Coordena o jogo
};

#endif // FREECELL_H