#ifndef STACK_H
#define STACK_H

const int MaxElements = 52;
class Stack
{
private:
    int top;
    int Entry[MaxElements];

public:
    Stack();
    ~Stack() = default;
    void Push(int x);
    void Pop(int &x);
    void Top(int &x);
    bool Empty();
};
#endif