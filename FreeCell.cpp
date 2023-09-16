#include "Baralho.h"
#include "FreeCell.h"
#include <iostream>
using namespace std;

// private
void FreeCell::IniciarPilha(Carta &x)
{
    Entry[count] = x;
    // Iniciando Cartas até o topo de cada pilha
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
        Entry[count].linha = 0;
        TopColumn[count - 139] = &Entry[count];
    }
    count++;
}
void FreeCell::ExibirMesa()
{
    for (int k = 9; k < 13; k++)
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
    for (int j = 9; j < 13; j++)
    {
        if (j > 9)
            cout << " [" << j << " ]  ";
        else
            cout << " [ " << j << " ]  ";
    }
    for (int j = 1; j < 5; j++)
        cout << " [ " << 0 << " ]  ";
    cout << endl;
    cout << endl;
    for (int j = 1; j < 20; j++)
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
    }
    cout << "===============================================================" << endl;
    for (int j = 1; j < 9; j++)
        cout << " [ " << j << " ]  ";
    cout << endl;
}
bool FreeCell::Hierarquia(int p_esta, int p_vai)
{
    if ((p_vai > 8 && p_vai < 13 && TopColumn[p_vai]->naipe == VAZIO))
        return true;
    if ((TopColumn[p_esta]->naipe < 5) == (TopColumn[p_vai]->naipe < 5))
    {
        cout << "Naipe incompativel: utilize uma carta com um Naipe de cor diferente!" << endl;
        return false;
    }

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
    int l_vai, l_esta;
    l_vai = TopColumn[p_vai]->linha + 1;
    l_esta = TopColumn[p_esta]->linha - 1;
    for (int i = 0; i < TotalCartas; i++)
        if ((Entry[i].coluna == p_vai) && (Entry[i].linha == l_vai))
        {
            Entry[i].coluna = p_esta;
            Entry[i].linha = TopColumn[p_esta]->linha;
        }
    TopColumn[p_esta]->linha = TopColumn[p_vai]->linha + 1;
    TopColumn[p_esta]->coluna = p_vai;
    TopColumn[p_vai] = TopColumn[p_esta];
    for (int i = 0; i < TotalCartas; i++)
        if ((Entry[i].coluna == p_esta) && (Entry[i].linha == l_esta))
            TopColumn[p_esta] = &Entry[i];
}
void FreeCell::MoverFreeCell(int &p_esta, int &p_vai)
{
    int l_esta = TopColumn[p_esta]->linha - 1;
    if (TopColumn[p_vai]->naipe == VAZIO)
    {
        for (int i = 0; i < TotalCartas; i++)
            if (Entry[i].coluna == p_vai)
            {
                Entry[i].coluna = p_esta;
                Entry[i].linha = TopColumn[p_esta]->linha;
            }
        TopColumn[p_esta]->linha = 0;
        TopColumn[p_esta]->coluna = p_vai;
        TopColumn[p_vai] = TopColumn[p_esta];
        for (int i = 0; i < TotalCartas; i++)
            if ((Entry[i].coluna == p_esta) && (Entry[i].linha == l_esta))
                TopColumn[p_esta] = &Entry[i];
    }
    else
        return;
}
// public
void FreeCell::Mesa()
{
    Baralho baralho;
    FreeCell jogo;

    baralho.Embaralhar();
    for (int i = 0; i < TotalCartas; i++)
        jogo.IniciarPilha(baralho.BaralhoCompleto[i]);

    char continuar;
    int x, y;
    jogo.ExibirMesa();
    cout << "Digite a coluna que ira retirar e depois a que ira inserir a carta: " << endl;
    while (true)
    {
        cin >> x;
        cin >> y;
        jogo.MoverCarta(x, y);
        jogo.ExibirMesa();
    }
}
void FreeCell::MoverCarta(int &p_esta, int &p_vai)
{
    if (p_esta < 0 || p_esta > 12 || p_vai < 0 || p_vai > 12)
    {
        cout << "Posicao incompativel: utilize posicoes entre 0-12!" << endl;
        return;
    }
    else if (p_vai > 8 && p_vai < 13)
        MoverFreeCell(p_esta, p_vai);
    else if (Hierarquia(p_esta, p_vai) == false)
        return;
    else
        MoverEntreColuna(p_esta, p_vai);

    cout << TopColumn[p_esta]->valor << TopColumn[p_esta]->naipe << " C: " << TopColumn[p_esta]->coluna << " L: " << TopColumn[p_esta]->linha << endl;
    cout << TopColumn[p_vai]->valor << TopColumn[p_vai]->naipe << " C: " << TopColumn[p_vai]->coluna << " L: " << TopColumn[p_vai]->linha << endl;
}