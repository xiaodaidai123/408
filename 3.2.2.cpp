// 队列的存储结构

#include <iostream>
using namespace std;
typedef int ElemType;
#define MaxSize 50

typedef struct{ // 队列的顺序存储结构
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;

typedef struct LinkNode{ // 队列的链式存储结构
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q){ // 初始化带头结点的链式队列
    Q.front = Q.rear = new LinkNode; // 建立头结点
    Q.front->next = nullptr;
};

bool QueueEmpty(LinkQueue Q){
    if(Q.front == Q.rear)
        return true;
    else
        return false;
}

void EnQueue(LinkQueue &Q, ElemType x){ // 入队
    LinkNode *s = new LinkNode;
    s->data = x;
    s->next = nullptr;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &x){ // 出队
    if(Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
}

int main()
{

    return 0;
}