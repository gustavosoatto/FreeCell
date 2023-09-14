#ifndef BARALHO_H
#define BARALHO_H

const int TotalCartas = 152;
enum Ordem
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
enum Naipe
{
    VAZIO = 0,
    COPAS = 3,
    OUROS,
    PAUS,
    ESPADAS
};
struct Carta
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
    Carta BaralhoCompleto[TotalCartas];
    Baralho();
    ~Baralho() = default;
    void Embaralhar();
};

#endif // BARALHO_H