#ifndef PILHA_H
#define PILHA_H

#include "Carta.h" // Inclui o arquivo de cabeçalho da classe Carta

// Definição da classe Pilha que gerencia as pilhas do jogo
class Pilha {
public:
    // Construtor e destrutor da classe Pilha
    Pilha();
    ~Pilha();

    // Métodos públicos da classe Pilha
    void Push(const Carta& carta); // Método para empilhar uma carta
    bool Pop(Carta& carta); // Método para desempilhar uma carta
    int Size() const; // Método para obter o tamanho da pilha

    void imprimir() const; // Método para imprimir o conteúdo da pilha

private:
    // Estrutura interna que representa um elemento da pilha
    struct Elemento {
        Carta carta; // Armazena uma carta
        Elemento* proximo; // Aponta para o próximo elemento

        Elemento(const Carta& c) : carta(c), proximo(nullptr) {}
        // Construtor da estrutura Elemento que inicializa a carta e o próximo como nullptr
    };

    Elemento* topo; // Ponteiro para o elemento no topo da pilha

    // Função auxiliar para liberar a memória da pilha
    void liberarPilha();
};

#endif // PILHA_H

