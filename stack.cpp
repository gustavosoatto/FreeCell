#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack(){
    top = 0;
}

Stack::~Stack(){
    cout << "Pilha destruida" << endl;
}

bool Stack::Full(){
    return top == (MaxElements - 1);
}

bool Stack::Empty(){
    return top == 0;
}
void Stack::Push(int x){
    if (!Full())
    {
        top++;
        Entry[top] = x;
    }else
    {
        cout << "Pilha cheia" << endl;
        return;
    }
}

void Stack::Pop(int &x){
    if (!Empty())
    {   
        x = Entry[top];
        top--;
    }else{
        cout << "Pilha vazia" << endl;
        return;
    }
}

void Stack::Top(int &x){
    if (top == 0){ //Não tem necessidade de chamar a função Empty() pela optimização
        cout << "Pilha vazia" << endl;
        return;
    }
    else{
        x = Entry[top];
    }
}
    