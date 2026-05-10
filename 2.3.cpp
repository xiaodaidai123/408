// 单链表
#include <iostream>
typedef int ElemType;
using namespace std;

// struct LNode // 单链表C++定义
// {
//     ElemType data;
//     struct LNode *next;
// };
// typedef LNode *LinkList;

typedef struct LNode // 单链表C语言定义
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList &L) // 带头结点的单链表初始化
{
    L = new LNode;
    L->next = nullptr;
    return true;
}

bool InitList2(LinkList &L) //不带头结点的单链表初始化
{
    L = NULL;
    return true;
}

int Length(LinkList L) // 求表长
{
    int len = 0;
    LNode *p = L;
    while(p->next != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

LNode *GetElem(LinkList L, int i) //按序号查找结点
{
    LNode *p = L;
    int j = 0;
    while(p->next != NULL && i != j)
    {
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next; // 从第一个结点开始查找数据域为e的结点
    while(p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p; // 找到后返回该结点指针，否则返回NULL
}

bool ListInsert(LinkList &L, int i, ElemType e) // 插入结点操作
{
    LNode *p = L; // L是头结点的指针，不能去改变
    int j=0;
    while(p != NULL && j < i-1)
    {
        p = p->next;
        j++;
    }
    if(p == NULL) // i值不合法
        return false;
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 删除第i个结点，先检查i的合法性，再找到第i-1个结点(前驱)，再删除其后继结点，并释放内存
// 假设找到的第i-1个结点为*p，其后继为被删结点*q，先将*p的next指向*q的后继结点，然后释放*q。
bool ListDelete(LinkList &L, int i, ElemType &e)
{
    LNode *p = L;
    int j = 0;
    while(p->next != NULL && j < i-1)
    {
        p = p->next;
        j++;
    }
    if(p->next == NULL || j > i-1) // i值不合法
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

void ListHeadInsert(LinkList &L) // 头插法建立单链表
{
    LNode *s;
    int x;
    L = new LNode; // 创建头结点
    L->next = NULL;
    cin >> x;
    while(x != 9999)
    {
        s = new LNode;
        s->data = x;
        s->next = L->next;
        L->next = s;
    }
}

void List_TailInsert(LinkList &L) // 尾插法创建单链表
{
    L = new LNode;
    LNode *s, *r = L; // r为尾节点指针
    int x;
    L->next = NULL;
    cin >> x;
    while(x != 9999)
    {
        s = new LNode;
        s->data = x;
        s->next = NULL;
        r->next = s;
        r = s;
        cin >> x;
    }
} 

int main()
{
    cout << (NULL == nullptr) << endl;
    return 0;
}