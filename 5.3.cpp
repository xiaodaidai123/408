// 线索二叉树的实现

#include <iostream>
typedef int ElemType;
using namespace std;

typedef struct ThreadNode{ // 线索二叉树的存储结构
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; // 左右线索标志
}ThreadNode, *ThreadTree;

void visit(ThreadNode *p){
    cout << p->data << endl;
}

void InThread(ThreadTree &p, ThreadTree &pre){ // 线索化过程
    InThread(p->lchild, pre); // 线索化左子树
    if(p->lchild == nullptr){ // 当前结点的左子树为空
        p->lchild = pre;      //建立当前结点的前驱线索
        p->ltag = 1;
    }
    if(pre != nullptr && pre->rchild == nullptr){ //前驱结点非空且其右子树为空
        pre->rchild = p; // 建立前驱结点的后继线索
        pre->rtag = 1;
    }
    pre = p; // 标记当前结点成为刚刚访问过的结点
    InThread(p->rchild, pre); // 线索化右子树
}

void CreateInThread(ThreadTree T){
    ThreadTree pre = nullptr;
    if(T != nullptr){ // 非空二叉树，线索化
        InThread(T, pre); // 线索化二叉树
        pre->rchild = nullptr; // 处理遍历的最后一个结点
        pre->rtag = 1;
    }
}

ThreadNode *Firstnode(ThreadNode *p){ // 求中序遍历中的第一个结点
    while(p->ltag == 0) // 沿左孩子链走到最左下结点
        p = p->lchild;
    return p;
}

ThreadNode *Nextnode(ThreadNode *p){ // 求结点p在中序遍历中的后继
    if(p->rtag == 0)
        return Firstnode(p->rchild); // 右子树中最左下结点
    else
        return p->rchild; // 若rtag==1，则直接返回后继线索
}

void Inorder(ThreadNode *T){ // 非递归的中序遍历
    for(ThreadNode *p = Firstnode(T); p != nullptr; p = Nextnode(p))
        visit(p);
}

int main()
{

    return 0;
}
