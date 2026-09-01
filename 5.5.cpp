// 并查集实现

#include <iostream>
#define SIZE 100
using namespace std;

int S[SIZE];

void Initial(int s[]){ // s即并查集
    for(int i=0;i<SIZE;i++)
        s[i] = -1;
}

int Find(int s[], int x){
    while(s[x] >= 0) // 循环寻找x的根
        x = s[x];
    return x;
}

void Union(int s[], int Root1, int Root2){ // 传入的是两个结点的根
    if(Root1 == Root2)
        return ;
    S[Root2] = Root1; // 将根Root2连接到另一根Root1下面
}

void Optimized_Union(int s[], int Root1, int Root2){
    if(Root1 == Root2)
        return ;
    if(S[Root2] > S[Root1]){ // Root2的结点数更少
        S[Root1] += S[Root2]; // 累加集合中的元素总数
        S[Root2] = Root1; // 小树合并到大树
    }
    else{ // Root1的结点数更少
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
}

int Optimized_Find(int s[], int x){ // 改进后的Find操作
    int root = x;
    while(S[root] >= 0){
        root = S[root];
    }
    while(x != root){
        int t = s[x]; // t指向x的父结点
        s[x] = root; // x直接挂到根结点下面
        x = t;
    }
    return root;
}

int main()
{

    return 0;
}