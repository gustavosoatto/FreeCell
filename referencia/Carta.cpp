#include "Carta.h" // Inclui o arquivo de definição da classe Carta

// Inclui a definição da classe Carta para que as implementações de métodos saibam sobre ela

// Implementação do construtor da classe Carta
Carta::Carta(Naipes naipes, Ordem ordem) : naipes_(naipes), ordem_(ordem) {}
// Definição do construtor da classe Carta com inicialização das variáveis de membro naipes_ e ordem_

// Implementação do método para identificar o naipe da carta
Carta::Naipes Carta::identificarNaipes() const {
    return naipes_; // Retorna o naipe da carta
}
// Definição da função que retorna o naipe da carta

// Implementação do método para identificar a ordem da carta
Carta::Ordem Carta::identificarOrdem() const {
    return ordem_; // Retorna a ordem da carta
}
// Definição da função que retorna a ordem da carta

// Implementação do método para identificar a cor da carta
Carta::Cores Carta::identificarCor() const {
    // Retorna a cor da carta com base no naipe
    return (naipes_ == ESPADAS || naipes_ == PAUS) ? PRETO : VERMELHO;
}
// Definição da função que retorna a cor da carta com base no naipe

