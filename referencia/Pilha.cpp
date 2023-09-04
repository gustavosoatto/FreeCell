#include "Pilha.h"

// Inclui o arquivo de definição da classe Pilha

Pilha::Pilha() : topo(nullptr) {}

// Implementação do construtor da classe Pilha. Inicializa o ponteiro 'topo' com nullptr.

Pilha::~Pilha() {
    liberarPilha();
}

// Implementação do destrutor da classe Pilha. Chama a função 'liberarPilha()' para liberar a memória.

void Pilha::Push(const Carta& carta) {
    Elemento* novoElemento = new Elemento(carta);
    novoElemento->proximo = topo;
    topo = novoElemento;
}

// Implementação do método Push para adicionar uma nova carta à pilha. 
// Cria um novo Elemento com a carta, aponta o próximo para o antigo topo e atualiza o topo.

bool Pilha::Pop(Carta& carta) {
    if (topo) {
        carta = topo->carta;
        Elemento* temp = topo;
        topo = topo->proximo;
        delete temp;
        return true;
    }
    return false;
}

// Implementação do método Pop para remover e retornar a carta do topo da pilha.
// Verifica se a pilha não está vazia, atribui a carta do topo, remove o elemento e atualiza o topo.

int Pilha::size() const {
    int count = 0;
    Elemento* atual = topo;
    while (atual) {
        count++;
        atual = atual->proximo;
    }
    return count;
}

// Implementação do método size para retornar o número de elementos na pilha.
// Usa um loop para contar o número de elementos percorrendo a lista encadeada.

void Pilha::imprimir() const {
    Elemento* atual = topo;
    while (atual) {
        Carta::Ordem ordem = atual->carta.identificarOrdem();
        Carta::Naipes naipe = atual->carta.identificarNaipes();
        // Obtém a ordem e o naipe da carta usando métodos da classe Carta
        // Exemplo: std::cout << "Carta: " << ordem << " de " << naipe << std::endl;
        atual = atual->proximo;
    }
}

// Implementação do método imprimir para mostrar o conteúdo da pilha.
// Usa um loop para percorrer a pilha e obter as informações de cada carta para impressão.

void Pilha::liberarPilha() {
    while (topo) {
        Elemento* temp = topo;
        topo = topo->proximo;
        delete temp;
    }
}

// Implementação da função auxiliar liberarPilha para desalocar a memória de todos os elementos da pilha.
// Usa um loop para percorrer a pilha e deletar cada elemento.

