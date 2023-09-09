#ifndef BARALHO_H
#define BARALHO_H

const int TotalCartas = 52;
enum Ordem
{
    A = 65,
    DOIS = 2,
    TRES,
    QUATRO,
    CINCO,
    SEIS,
    SETE,
    OITO,
    NOVE,
    DEZ,
    J = 74,
    Q = 81,
    K = 75
};
enum Naipe
{
    C = 3,
    U,
    P,
    E
};
struct Carta
{
    Ordem valor;
    Naipe naipe;
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