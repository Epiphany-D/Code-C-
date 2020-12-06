#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;  // 顶点下标
typedef int WeightType;
typedef char DataType;

// 边
typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

// 邻接点
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
    Vertex AdjV;  // 邻接点下标
    WeightType Weight;
    PtrToAdjVNode Next;
};

// 顶点表头节点
typedef struct Vnode {
    PtrToAdjVNode FirstEdge;
    DataType Data;
} AdjList[MaxVertexNum];

// 图
typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

// 初始化
LGraph CreateGraph(int VertexNum) {
    LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for (Vertex V = 0; V < Graph->Nv; V++) {
        Graph->G[V].FirstEdge = NULL;
    }

    return Graph;
}

void InsertEdge(LGraph Graph, Edge E) {
    PtrToAdjVNode NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    // 无向图
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph() {
    LGraph Graph;
    int Nv = 0;
    scanf("%d", &Nv);
    Graph = CreateGraph(Nv);

    scanf("%d", &(Graph->Ne));
    if (Graph->Ne != 0) {
        Edge E = (Edge)malloc(sizeof(struct ENode));
        for (int i = 0; i < Graph->Ne; i++) {
            scanf("%d %d %d", &(E->V1), &(E->V2), &(E->Weight));
            InsertEdge(Graph, E);
        }
    }

    for (Vertex V = 0; V < Graph->Nv; V++) {
        scanf(" %c", &(Graph->G[V].Data));
    }

    return Graph;
}

int main() {
    LGraph Graph = BuildGraph();
    printf("Nv = %d\n", Graph->Nv);
    printf("Ne = %d\n", Graph->Ne);
    printf("Node = %c\n", Graph->G[0].Data);
}

// 输入数据：
// 6 11
// 3 4 70
// 1 2 1
// 5 4 50
// 2 6 50
// 5 6 60
// 1 3 70
// 4 6 60
// 3 6 80
// 5 1 100
// 2 4 60
// 5 2 80
// A b c d e f