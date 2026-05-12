// 栈的实现及操作
// 2026-05-12

#include <iostream>
#define MaxSize 50
typedef int ElemType;
using namespace std;

typedef struct LinkNode // 链栈的实现
{
    ElemType data;
    struct LinkNode *next;
}LiStack;

typedef struct // 顺序栈的实现
{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S)
{
    S.top = -1; // 初始化栈顶指针
}

bool StackEmpty(SqStack S)
{
    if(S.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack &S, ElemType x)
{
    if(S.top == MaxSize-1)
        return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x)
{
    if(S.top == -1)
        return false;
    x = S.data[--S.top];
    return true;
}

bool GetTop(SqStack S, ElemType &x) // 读栈顶元素
{
    if(S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

int main()
{

    return 0;
}