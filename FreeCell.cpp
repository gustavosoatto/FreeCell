#include "Baralho.h"
#include "FreeCell.h"
#include <iostream>
using namespace std;

void FreeCell::IniciarPilha(Carta &x)
{
    Entry[count] = x;
    if (count < 7)
    {
        Entry[count].posicao.coluna = 1;
        Entry[count].posicao.linha = count + 1;
        TopColumn[1] = Entry[count];
    }
    else if (count < 14)
    {
        Entry[count].posicao.coluna = 2;
        Entry[count].posicao.linha = count - 6;
        TopColumn[2] = Entry[count];
    }
    else if (count < 21)
    {
        Entry[count].posicao.coluna = 3;
        Entry[count].posicao.linha = count - 13;
        TopColumn[3] = Entry[count];
    }
    else if (count < 28)
    {
        Entry[count].posicao.coluna = 4;
        Entry[count].posicao.linha = count - 20;
        TopColumn[4] = Entry[count];
    }
    else if (count < 34)
    {
        Entry[count].posicao.coluna = 5;
        Entry[count].posicao.linha = count - 27;
        TopColumn[5] = Entry[count];
    }
    else if (count < 40)
    {
        Entry[count].posicao.coluna = 6;
        Entry[count].posicao.linha = count - 33;
        TopColumn[6] = Entry[count];
    }
    else if (count < 46)
    {
        Entry[count].posicao.coluna = 7;
        Entry[count].posicao.linha = count - 39;
        TopColumn[7] = Entry[count];
    }
    else if (count < 52)
    {
        Entry[count].posicao.coluna = 8;
        Entry[count].posicao.linha = count - 45;
        TopColumn[8] = Entry[count];
    }
    count++;
}

void FreeCell::ExibirMesa(FreeCell &jogo)
{
    for (int j = 1; j < 20; j++)
    {
        for (int k = 1; k < 9; k++)
        {
            for (int i = 0; i < TotalCartas; i++)
            {
                if (jogo.Entry[i].posicao.coluna == k && jogo.Entry[i].posicao.linha == j)
                {
                    char naipe = jogo.Entry[i].naipe;
                    if (jogo.Entry[i].valor == A || jogo.Entry[i].valor == J || jogo.Entry[i].valor == Q || jogo.Entry[i].valor == K)
                    {
                        char valor = jogo.Entry[i].valor;
                        cout << "[ " << valor << "-" << naipe << " ] ";
                    }
                    else
                    {
                        if (jogo.Entry[i].valor == 10)
                            cout << "[" << jogo.Entry[i].valor << "-" << naipe << " ] ";
                        else
                            cout << "[ " << jogo.Entry[i].valor << "-" << naipe << " ] ";
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
    // Mesa alinhada na vertical
    // for (int i = 0; i < TotalCartas; i++)
    // {
    //     char naipe = jogo.Entry[i].naipe;
    //     if (jogo.Entry[i].valor == A || jogo.Entry[i].valor == J || jogo.Entry[i].valor == Q || jogo.Entry[i].valor == K)
    //     {
    //         char valor = jogo.Entry[i].valor;
    //         cout << "[ " << valor << "-" << naipe << " ] ";
    //     }
    //     else
    //     {
    //         if (jogo.Entry[i].valor == 10)
    //             cout << "[" << jogo.Entry[i].valor << "-" << naipe << " ] ";
    //         else
    //             cout << "[ " << jogo.Entry[i].valor << "-" << naipe << " ] ";
    //     }
    //     for (int j = 1; j < 9; j++)
    //         if (jogo.Entry[i].valor == jogo.TopColumn[j].valor && jogo.Entry[i].naipe == jogo.TopColumn[j].naipe)
    //             cout << endl;
    // }
    // Teste do Topo das colunas
    // for (int j = 1; j < 9; j++)
    //     cout << "[ " << jogo.TopColumn[j].posicao.coluna << "-" << jogo.TopColumn[j].posicao.linha << " ] ";
}
void FreeCell::Mesa()
{
    Baralho baralho;
    FreeCell jogo;

    baralho.Embaralhar();
    for (int i = 0; i < TotalCartas; i++)
        jogo.IniciarPilha(baralho.BaralhoCompleto[i]);

    char continuar;
    int x, y;
    cout << "Digite a coluna que ira retirar e depois a que ira inserir a carta: " << endl;
    while (continuar != 'n')
    {
        jogo.ExibirMesa(jogo);
        cin >> x;
        cin >> y;
        jogo.MoverCarta(x, y);
        cout << "Deseja continuar (s/n): " << endl;
        cin >> continuar;
    }
}
bool FreeCell::Hierarquia(int p_esta, int p_vai)
{
    if ((TopColumn[p_esta].naipe < 5) == (TopColumn[p_vai].naipe < 5))
    {
        cout << "Naipe incompativel: utilize uma carta com um Naipe de cor diferente!" << endl;
        return false;
    }

    p_esta = TopColumn[p_esta].valor;
    p_vai = TopColumn[p_vai].valor;
    if (p_esta == A)
        p_esta = 1;
    if (p_vai == A)
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
void FreeCell::MoverCarta(int &p_esta, int &p_vai)
{
    if (p_esta < 0 || p_esta > 12 || p_vai < 0 || p_vai > 12)
        cout << "Posicao incompativel: utilize posicoes entre 0-12!" << endl;
    else if (Hierarquia(p_esta, p_vai) == false)
        return;
    else
    {
        cout << "Sucesso" << endl;
        Carta temp;
        temp = TopColumn[p_esta];
    }
}