#ifndef CARTA_H
#define CARTA_H

// Inclusão de guarda de inclusão (include guard) para evitar inclusões múltiplas deste arquivo
// Se CARTA_H já estiver definido, o conteúdo deste arquivo não será incluído novamente

class Carta {
public:
    // Enumerações que definem os possíveis valores de naipe, ordem e cor de uma carta
    enum Naipes { ESPADAS, PAUS, COPAS, OUROS };
    enum Ordem { AS = 1, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, DEZ, VALETE, DAMA, REI };
    enum Cores { PRETO, VERMELHO };

    // Construtor da classe Carta que recebe o naipe e a ordem da carta
    Carta(Naipes naipes, Ordem ordem);

    // Métodos para identificar o naipe, a ordem e a cor da carta
    Naipes identificarNaipes() const;
    Ordem identificarOrdem() const;
    Cores identificarCor() const;

private:
    Naipes naipes_; // Variável de membro que armazena o naipe da carta
    Ordem ordem_; // Variável de membro que armazena a ordem da carta
};

#endif // CARTA_H

// O fim da definição da classe e o fechamento do include guard

