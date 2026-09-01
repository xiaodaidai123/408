// 树与森林的存储结构

#include <iostream>
using namespace std;
#define MAX_TREE_SIZE 100
typedef int ElemType;

typedef struct{ // 1.双亲表示法
    ElemType data;
    int parent; // 双亲位置域
}PTNode;

typedef struct{
    PTNode nodes[MAX_TREE_SIZE];
    int n; // 结点数
}PTree;

struct CTNode{ // 2.孩子表示法
    int child; // 孩子结点在数组中的位置
    struct CTNode *next;
};

typedef struct{
    ElemType data;
    struct CTNode *firstChild; // 第一个孩子
}CTBox;

typedef struct{
    CTBox nodes[MAX_TREE_SIZE];
    int n, r; // 结点数和根的位置
}CTree;

int main()
{

    return 0;
}