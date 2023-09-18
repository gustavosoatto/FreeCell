#include "Baralho.h"
#include "FreeCell.h"
#include <iostream>
using namespace std;

// private
void FreeCell::IniciarPilha(Carta &x)
{
    Entry[count] = x;
    //  Iniciando Cartas até o topo de cada pilha
    if (count < 7)
    {
        Entry[count].coluna = 1;
        Entry[count].linha = count + 1;
        TopColumn[1] = &Entry[count];
    }
    else if (count < 14)
    {
        Entry[count].coluna = 2;
        Entry[count].linha = count - 6;
        TopColumn[2] = &Entry[count];
    }
    else if (count < 21)
    {
        Entry[count].coluna = 3;
        Entry[count].linha = count - 13;
        TopColumn[3] = &Entry[count];
    }
    else if (count < 28)
    {
        Entry[count].coluna = 4;
        Entry[count].linha = count - 20;
        TopColumn[4] = &Entry[count];
    }
    else if (count < 34)
    {
        Entry[count].coluna = 5;
        Entry[count].linha = count - 27;
        TopColumn[5] = &Entry[count];
    }
    else if (count < 40)
    {
        Entry[count].coluna = 6;
        Entry[count].linha = count - 33;
        TopColumn[6] = &Entry[count];
    }
    else if (count < 46)
    {
        Entry[count].coluna = 7;
        Entry[count].linha = count - 39;
        TopColumn[7] = &Entry[count];
    }
    else if (count < 52)
    {
        Entry[count].coluna = 8;
        Entry[count].linha = count - 45;
        TopColumn[8] = &Entry[count];
    }
    // Iniciando as Casas Vazias
    else if (count < 64)
    {
        Entry[count].coluna = 1;
        Entry[count].linha = count - 44;
    }
    else if (count < 76)
    {
        Entry[count].coluna = 2;
        Entry[count].linha = count - 56;
    }
    else if (count < 88)
    {
        Entry[count].coluna = 3;
        Entry[count].linha = count - 68;
    }
    else if (count < 100)
    {
        Entry[count].coluna = 4;
        Entry[count].linha = count - 80;
    }
    else if (count < 112)
    {
        Entry[count].coluna = 5;
        Entry[count].linha = count - 93;
    }
    else if (count < 124)
    {
        Entry[count].coluna = 6;
        Entry[count].linha = count - 105;
    }
    else if (count < 136)
    {
        Entry[count].coluna = 7;
        Entry[count].linha = count - 117;
    }
    else if (count < 148)
    {
        Entry[count].coluna = 8;
        Entry[count].linha = count - 129;
    }
    // FreeCells
    else if (count < 152)
    {
        Entry[count].coluna = count - 139;
        Entry[count].linha = 1;
        TopColumn[count - 139] = &Entry[count];
    }
    // Pilha de Saída
    else if (count < 156)
    {
        Entry[count].coluna = count - 139;
        Entry[count].linha = 1;
        TopColumn[0] = &Entry[152];
    }
    count++;
}
void FreeCell::ExibirMesa()
{
    for (int k = 9; k < 17; k++) // Exibe o conteúdo das freecells e pilhas de saída
    {
        for (int i = 0; i < TotalCartas; i++)
        {
            if (Entry[i].coluna == k)
            {
                char naipe = Entry[i].naipe;
                if (Entry[i].naipe == VAZIO)
                    cout << "|     | ";
                else if (Entry[i].valor == AS || Entry[i].valor == J || Entry[i].valor == Q || Entry[i].valor == K)
                {
                    char valor = Entry[i].valor;
                    cout << "[ " << valor << "-" << naipe << " ] ";
                }
                else
                {
                    if (Entry[i].valor == 10)
                        cout << "[" << Entry[i].valor << "-" << naipe << " ] ";
                    else
                        cout << "[ " << Entry[i].valor << "-" << naipe << " ] ";
                }
            }
        }
    }
    cout << endl;
    for (int j = 9; j < 17; j++) // Exibe o valor que representa a coluna
    {
        if (j == 9)
            cout << " [ " << j << " ]  ";
        else if (j < 13)
            cout << " [" << j << " ]  ";
        else if (j < 17)
            cout << " [ " << 0 << " ]  ";
    }
    cout << endl
         << endl;

    for (int j = 1; j < 20; j++) // Exibe as cartas da mesa
    {
        for (int k = 1; k < 9; k++)
        {
            for (int i = 0; i < TotalCartas; i++)
            {
                if (Entry[i].coluna == k && Entry[i].linha == j)
                {
                    char naipe = Entry[i].naipe;
                    if (Entry[i].naipe == VAZIO)
                        cout << "|     | ";
                    else if (Entry[i].valor == AS || Entry[i].valor == J || Entry[i].valor == Q || Entry[i].valor == K)
                    {
                        char valor = Entry[i].valor;
                        cout << "[ " << valor << "-" << naipe << " ] ";
                    }
                    else if (Entry[i].valor == 10)
                        cout << "[" << Entry[i].valor << "-" << naipe << " ] ";
                    else
                        cout << "[ " << Entry[i].valor << "-" << naipe << " ] ";
                }
            }
        }
        cout << endl;
    }
    cout << "===============================================================" << endl;
    for (int j = 1; j < 9; j++) // Exibe o valor que representa a coluna
        cout << " [ " << j << " ]  ";
    cout << endl;
}
bool FreeCell::Hierarquia(int p_esta, int p_vai)
{
    if ((TopColumn[p_vai]->naipe == VAZIO))
        return true;
    if ((TopColumn[p_esta]->naipe < 5) == (TopColumn[p_vai]->naipe < 5)) // Verifica se o naipe é de cor diferente
    {
        cout << "Naipe incompativel: utilize uma carta com um Naipe de cor diferente!" << endl;
        return false;
    }

    // Converte os valores especiais das cartas (AS, J, Q, K) em valores numéricos correspondentes
    p_esta = TopColumn[p_esta]->valor;
    p_vai = TopColumn[p_vai]->valor;
    if (p_esta == AS)
        p_esta = 1;
    if (p_vai == AS)
        p_vai = 1;
    if (p_esta == J)
        p_esta = 11;
    if (p_vai == J)
        p_vai = 11;
    if (p_esta == Q)
        p_esta = 12;
    if (p_vai == Q)
        p_vai = 12;
    if (p_esta == K)
        p_esta = 13;
    if (p_vai == K)
        p_vai = 13;
    if (p_esta != p_vai - 1)
    {
        cout << "Valor incompativel: utilize uma carta com um Valor inferior ao da carta de destino!" << endl;
        return false;
    }
    else
        return true;
}
void FreeCell::MoverEntreColuna(int &p_esta, int &p_vai)
{
    cout << "Carta da coluna [ " << TopColumn[p_esta]->coluna << " ] movida para [ " << TopColumn[p_vai]->coluna << " ]!" << endl;
    int l_vai, l_esta;
    l_vai = TopColumn[p_vai]->linha + 1;
    l_esta = TopColumn[p_esta]->linha - 1;
    if (TopColumn[p_vai]->naipe == VAZIO) // Garante que não iremos pular linhas em colunas vazias
        l_vai--;
    for (int i = 0; i < TotalCartas; i++)
        if ((Entry[i].coluna == p_vai) && (Entry[i].linha == l_vai))
        {
            Entry[i].coluna = p_esta;
            Entry[i].linha = TopColumn[p_esta]->linha;
        }
    TopColumn[p_esta]->linha = l_vai;
    TopColumn[p_esta]->coluna = p_vai;
    TopColumn[p_vai] = TopColumn[p_esta];
    if (l_esta < 1) // Garante que o topo de uma coluna vazia não aponde para outra
        l_esta = 1;
    for (int i = 0; i < TotalCartas; i++)
        if ((Entry[i].coluna == p_esta) && (Entry[i].linha == l_esta))
            TopColumn[p_esta] = &Entry[i];
}
bool FreeCell::CartaFreecell(int &position)
{
    return (position > 8 && position < 13); // Verifica se a variável usa alguma coluna de freecell
}
void FreeCell::MoverFreeCell(int &p_esta, int &p_vai)
{
    if (CartaFreecell(p_vai) && (TopColumn[p_vai]->naipe != VAZIO))
        cout << "Posicao ocupada: tente mover para uma posicao vazia" << endl;
    else if (TopColumn[p_vai]->naipe == VAZIO) // Caso enviamos uma carta para uma posição VAZIA (coluna de freecell ou jogo)
    {
        int l_esta = TopColumn[p_esta]->linha - 1;
        for (int i = 0; i < TotalCartas; i++)
            if (Entry[i].coluna == p_vai && Entry[i].linha == 1)
            {
                Entry[i].coluna = p_esta;
                Entry[i].linha = TopColumn[p_esta]->linha;
            }
        TopColumn[p_esta]->linha = 1;
        TopColumn[p_esta]->coluna = p_vai;
        TopColumn[p_vai] = TopColumn[p_esta];
        if (l_esta < 1) // Garante que o topo de uma coluna vazia não aponde para outra
            l_esta = 1;
        for (int i = 0; i < TotalCartas; i++)
            if ((Entry[i].coluna == p_esta) && (Entry[i].linha == l_esta))
                TopColumn[p_esta] = &Entry[i];
    }
    else if (TopColumn[p_vai]->naipe != VAZIO) // Caso enviamos a carta para uma pilha de cartas
    {
        int l_vai = TopColumn[p_vai]->linha + 1;
        for (int i = 0; i < TotalCartas; i++)
            if (Entry[i].coluna == p_vai && Entry[i].linha == l_vai)
            {
                Entry[i].coluna = p_esta;
                Entry[i].linha = TopColumn[p_esta]->linha;
            }
        TopColumn[p_esta]->linha = l_vai;
        TopColumn[p_esta]->coluna = p_vai;
        TopColumn[p_vai] = TopColumn[p_esta];
        for (int i = 0; i < TotalCartas; i++)
            if (Entry[i].coluna == p_esta)
                TopColumn[p_esta] = &Entry[i];
    }
    if (CartaFreecell(p_esta))
        cout << "Carta movida da FreeCell!" << endl;
    if (CartaFreecell(p_vai))
        cout << "Carta movida para FreeCell!" << endl;
}
bool FreeCell::HierarquiaSaida(int p_esta, int p_vai)
{
    if (TopColumn[p_esta]->naipe == COPAS) // Verifica a qual naipe a carta de origem pretence
    {
        TopColumn[p_vai] = &Entry[154]; // Ajusta o ponteiro TopColumn[0] para a coluna de saida
        if ((TopColumn[p_esta]->valor == AS) && (Entry[154].naipe == VAZIO))
            return true;
        else
        {
            p_esta = TopColumn[p_esta]->valor;
            p_vai = Entry[154].valor;
            if (p_esta == AS)
                p_esta = 1;
            if (p_vai == AS)
                p_vai = 1;
            if (p_esta == J)
                p_esta = 11;
            if (p_vai == J)
                p_vai = 11;
            if (p_esta == Q)
                p_esta = 12;
            if (p_vai == Q)
                p_vai = 12;
            if (p_esta == K)
                p_esta = 13;
            if (p_vai == K)
                p_vai = 13;
            if (p_esta == p_vai + 1)
                return true;
            else
            {
                cout << "Valor incompativel: utilize uma carta com um valor superior ao da carta de destino!" << endl;
                return false;
            }
        }
    }
    else if (TopColumn[p_esta]->naipe == OUROS) // Verifica a qual naipe a carta de origem pretence
    {
        TopColumn[p_vai] = &Entry[152]; // Ajusta o ponteiro TopColumn[0] para a coluna de saida
        if ((TopColumn[p_esta]->valor == AS) && (Entry[152].naipe == VAZIO))
            return true;
        else
        {
            p_esta = TopColumn[p_esta]->valor;
            p_vai = Entry[152].valor;
            if (p_esta == AS)
                p_esta = 1;
            if (p_vai == AS)
                p_vai = 1;
            if (p_esta == J)
                p_esta = 11;
            if (p_vai == J)
                p_vai = 11;
            if (p_esta == Q)
                p_esta = 12;
            if (p_vai == Q)
                p_vai = 12;
            if (p_esta == K)
                p_esta = 13;
            if (p_vai == K)
                p_vai = 13;
            if (p_esta == p_vai + 1)
                return true;
            else
            {
                cout << "Valor incompativel: utilize uma carta com um valor superior ao da carta de destino!" << endl;
                return false;
            }
        }
    }
    else if (TopColumn[p_esta]->naipe == PAUS) // Verifica a qual naipe a carta de origem pretence
    {
        TopColumn[p_vai] = &Entry[155]; // Ajusta o ponteiro TopColumn[0] para a coluna de saida
        if ((TopColumn[p_esta]->valor == AS) && (Entry[155].naipe == VAZIO))
            return true;
        else
        {
            p_esta = TopColumn[p_esta]->valor;
            p_vai = Entry[155].valor;
            if (p_esta == AS)
                p_esta = 1;
            if (p_vai == AS)
                p_vai = 1;
            if (p_esta == J)
                p_esta = 11;
            if (p_vai == J)
                p_vai = 11;
            if (p_esta == Q)
                p_esta = 12;
            if (p_vai == Q)
                p_vai = 12;
            if (p_esta == K)
                p_esta = 13;
            if (p_vai == K)
                p_vai = 13;
            if (p_esta == p_vai + 1)
                return true;
            else
            {
                cout << "Valor incompativel: utilize uma carta com um valor superior ao da carta de destino!" << endl;
                return false;
            }
        }
    }
    else if (TopColumn[p_esta]->naipe == ESPADAS) // Verifica a qual naipe a carta de origem pretence
    {
        TopColumn[p_vai] = &Entry[153]; // Ajusta o ponteiro TopColumn[0] para a coluna de saida
        if ((TopColumn[p_esta]->valor == AS) && (Entry[153].naipe == VAZIO))
            return true;
        else
        {
            p_esta = TopColumn[p_esta]->valor;
            p_vai = Entry[153].valor;
            if (p_esta == AS)
                p_esta = 1;
            if (p_vai == AS)
                p_vai = 1;
            if (p_esta == J)
                p_esta = 11;
            if (p_vai == J)
                p_vai = 11;
            if (p_esta == Q)
                p_esta = 12;
            if (p_vai == Q)
                p_vai = 12;
            if (p_esta == K)
                p_esta = 13;
            if (p_vai == K)
                p_vai = 13;
            if (p_esta == p_vai + 1)
                return true;
            else
            {
                cout << "Valor incompativel: utilize uma carta com um valor superior ao da carta de destino!" << endl;
                return false;
            }
        }
    }
    return false;
}
void FreeCell::MoverSaida(int &p_esta, int &p_vai)
{
    cout << "Carta da coluna [ " << p_esta << " ] movida para saida!" << endl;
    int l_esta = TopColumn[p_esta]->linha - 1;
    for (int i = 13; i < 17; i++)
    {
        if ((TopColumn[p_vai]->naipe == VAZIO && TopColumn[p_esta]->valor == AS) || (TopColumn[p_esta]->naipe == TopColumn[p_vai]->naipe))
        {
            *TopColumn[p_vai] = *TopColumn[p_esta];
            TopColumn[p_vai]->coluna = i;
            TopColumn[p_vai]->linha = 1;
            TopColumn[p_esta]->naipe = VAZIO;
            i = 17;
            if (l_esta < 1)
                l_esta = 1;
            for (int i = 0; i < TotalCartas; i++)
                if (Entry[i].coluna == p_esta && Entry[i].linha == l_esta)
                    TopColumn[p_esta] = &Entry[i];
        }
        TopColumn[p_vai] = TopColumn[p_vai] + 1;
    }
}
void FreeCell::MoverCarta(int &p_esta, int &p_vai)
{
    if (p_esta < 1 || p_esta > 12 || p_vai < 0 || p_vai > 12) // Verifica se as colunas especificadas pelo jogador estão dentro dos limites permitidos
    {
        cout << "Posicao invalida: tente mover das colunas 1-12 ou enviar para saida 0!" << endl;
        return;
    }
    else if (TopColumn[p_esta]->naipe == VAZIO) // Verifica se o jogador está tentando mover uma célula vazia
    {
        cout << "Posicao invalida: essa posicao esta VAZIA!" << endl;
        return;
    }
    else if (p_vai == 0) // Verifica se o jogador quer mover uma carta para uma pilha de saída
        if (HierarquiaSaida(p_esta, p_vai) == true)
            MoverSaida(p_esta, p_vai);
        else
            return;
    else if (Hierarquia(p_esta, p_vai) == false)
        return;
    else if (CartaFreecell(p_vai) || CartaFreecell(p_esta))
        MoverFreeCell(p_esta, p_vai);
    else
        MoverEntreColuna(p_esta, p_vai);
}
bool FreeCell::Ganhou()
{
    return (Entry[152].valor == K && Entry[153].valor == K && Entry[154].valor == K && Entry[155].valor == K);
}
// public
void FreeCell::Mesa()
{
    Baralho baralho;
    FreeCell jogo;

    cout << endl;
    cout << "      ____________ _____ _____ _____  _____ _      _     " << endl;
    cout << "      |  ___| ___ \\  ___|  ___/  __ \\|  ___| |    | |    " << endl;
    cout << "      | |_  | |_/ / |__ | |__ | /  \\/| |__ | |    | |    " << endl;
    cout << "      |  _| |    /|  __||  __|| |    |  __|| |    | |    " << endl;
    cout << "      | |   | |\\ \\| |___| |___| \\__/\\| |___| |____| |____" << endl;
    cout << "      \\_|   \\_| \\_\\____/\\____/ \\____/\\____/\\_____/\\_____/" << endl;
    cout << endl;

    // Prepara o baralho e a mesa iniciando os valores necessáriso
    baralho.Embaralhar();
    for (int i = 0; i < TotalCartas; i++)
        jogo.IniciarPilha(baralho.BaralhoCompleto[i]);

    int x, y;
    jogo.ExibirMesa();
    while (!Ganhou()) // Verifica a cada movimento se o jogador ganhou
    {
        cout << "Digite o valor da coluna que ira retirar e depois a que ira inserir a carta: " << endl;
        cin >> x;
        cin >> y;
        jogo.MoverCarta(x, y);
        jogo.ExibirMesa();
    }

    printf("\n");
    printf("                         ___________\n");
    printf("                        '._==_==_=_.'\n");
    printf("                        .-\\:      /-.\n");
    printf("                       | (|:.     |) |\n");
    printf("                        '-|:.     |-'\n");
    printf("                          \\::.    /\n");
    printf("                           '::. .'\n");
    printf("                             ) (\n");
    printf("                           _.' '._\n");
    printf("                          `\"\"\"\"\"\"\"`\n");
    printf("\n");
}