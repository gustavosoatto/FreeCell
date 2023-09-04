#ifndef BARALHO_H
#define BARALHO_H

const int TotalCartas = 52;
enum Ordem
{
    AS = 1,
    DOIS,
    TRES,
    QUATRO,
    CINCO,
    SEIS,
    SETE,
    OITO,
    NOVE,
    DEZ,
    VALETE,
    DAMA,
    REI
};
enum Naipe
{
    OUROS,
    ESPADAS,
    COPAS,
    PAUS
};

class Baralho
{
private:
    struct Carta
    {
        Ordem valor;
        Naipe naipe;
    };

public:
    Carta BaralhoCompleto[TotalCartas];
    Baralho();
    ~Baralho() = default;
    void Embaralhar();
    void Ordenar();
};

#endif