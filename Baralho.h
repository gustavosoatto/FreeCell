#ifndef BARALHO_H
#define BARALHO_H

const int TotalCartas = 156; // Define o número total de cartas do baralho
enum Ordem                   // Representa os valores das cartas
{
    AS = 65,
    DOIS = 2,
    TRES = 3,
    QUATRO = 4,
    CINCO = 5,
    SEIS = 6,
    SETE = 7,
    OITO = 8,
    NOVE = 9,
    DEZ = 10,
    J = 74,
    Q = 81,
    K = 75
};
enum Naipe // Representa os naipes das cartas
{
    VAZIO = 0,
    COPAS = 3,
    OUROS,
    PAUS,
    ESPADAS
};
struct Carta // Estrutura para representar uma carta
{
    Ordem valor;
    Naipe naipe;
    int linha;
    int coluna;
};

class Baralho
{
private:
public:
    Carta BaralhoCompleto[TotalCartas]; // Vetor de cartas representando um baralho completo
    Baralho();                          // Construtor da classe Baralho
    ~Baralho() = default;               // Destrutor padrão
    void Embaralhar();                  // Método para embaralhar as cartas do baralho
};

#endif // BARALHO_H