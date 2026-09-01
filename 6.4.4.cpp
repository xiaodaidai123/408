// 拓扑排序

#include <iostream>
using namespace std;

bool TopologicalSort(Graph G){
    InitStack(S);
    int i;
    for(i=0; i<G.vexnum; i++){
        if(indegree[i] == 0)
            Push(S, i);
    }
    int count = 0;
    while(!StackEmpty(S)){
        Pop(S, i);
        print[count++] = i;
        for(p=G.vertices[i].firstarc; p; p=p->nextarc){
            v = p->adjvex;
            if(!(--indegree[v]))
                Push(S, v);
        }
    }
    if(count < G.vexnum)
        return false;
    else
        return true;
}





int main()
{

    return 0;
}