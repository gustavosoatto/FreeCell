// FreecellGame.h
#ifndef FREECELLGAME_H
#define FREECELLGAME_H

#include "Carta.h" // Inclui o arquivo de cabeçalho da classe Carta
#include "Pilha.h" //  Inclui o arquivo de cabeçalho da classe Pilha

// Definição da classe FreecellGame que gerencia o jogo
class FreecellGame {
public:
    // Números fixos para o jogo
    static const int NUM_CELLS = 4;
    static const int NUM_OBJETIVO = 4;
    static const int NUM_PILHAS = 8;

    // Enumeração para os tipos de pilhas
    enum class TipoCell {
        FREE_CELL,
        OBJETIVO,
        PILHAS
    };

    // Construtor e destrutor da classe FreecellGame
    FreecellGame();
    ~FreecellGame();

    // Método principal para jogar o jogo
    void play();

private:
    // Estrutura para os elementos das pilhas
    struct Elemento {
        Carta carta; // Armazena uma carta
        Elemento* proximo; // Aponta para o próximo elemento

        // Construtor do elemento com uma carta
        Elemento(const Carta &c) : carta(c), proximo(nullptr) {}
    };

    // Estrutura da Pilha com um topo de elementos
    struct Pilha {
        Elemento* topo; // O elemento no topo da pilha

        // Construtor da pilha
        Pilha() : topo(nullptr) {}

        // Destrutor da pilha para liberar a memória
        ~Pilha() {
            while (topo) {
                Elemento* temp = topo;
                topo = topo->proximo;
                delete temp;
            }
        }

        // Métodos da pilha: empilhar, desempilhar, tamanho
        void push(const Carta& c);
        bool pop(Carta& c);
        int size() const;
    };

    Pilha freeCells_[NUM_CELLS]; // Pilhas de células livres
    Pilha objetivo_[NUM_OBJETIVO]; // Pilhas de objetivo
    Pilha pilhas_[NUM_PILHAS]; // Pilhas principais do jogo

    // Métodos para gerenciar o jogo
    void inicializarJogo();
    void apresentarJogo();
    bool movimentoValido(const Carta &buscaCarta, const Carta &destinoCarta);
    void moverCarta(TipoCell buscaTipo, int buscaIndice, TipoCell destinoTipo, int destinoIndice);
    bool verificarSituacao();
};

#endif // FREECELLGAME_H

