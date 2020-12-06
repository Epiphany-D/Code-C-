#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
#define INFINITY INT_MAX    //最大值
#define MAX_VERTEX_NUM 20;  //最大顶点个数
typedef char VertexData;
typedef enum { DG,
               DN,
               UDG,
               UDN } Graphkind;  //有向图,有向网,无向图,无向网
//图的一个顶点
typedef struct ArcNode {
    AdjType adj;  //顶点关系类型,对于无权图用0和1来表示是否相邻；对有权图表示权值
    OtherInfo *info;
} ArcNode, AdjNodes[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
// 表示图的连接矩阵
typedef struct AdjM {
    VertexData vexs[MAX_VERTEX_NUM];  //顶点向量
    AdjNode arcs;                     //邻接矩阵
    int vexnum, arcnum;               //图当前的顶点数量和弧的数量
    Graphkind kind;                   //图的种类标记
} * AdjMatrix;

/* 7.1 采用邻接矩阵表示法创建有向图*/
// 求顶点位置
int LocateVertex(AdjMatrix &G, VertexData v) {
    int j = Error;
    int k;
    for (k = 0; k < G->vexnum; k++) {
        if (G->vexs[k] == v) {
            j = k;
            break;
        }
    }
    return j;
}
// 创建一个有向网
int CreateDN(AdjMatrix &G) {
    int i, j, k, weight;
    VertexData v1, v2;
    cout << "输入图的顶点数和弧数" << endl;
    cin >> G->arcnum >> G->vexnum;
    for (i = 0; i < G->vexnum; i++) {
        for (j = 0; j < G->vexnum; j++) {
            G->arcs[i][j].adj = INFINITY;
        }
    }
    cout << "输入图的顶点" << endl;
    for (i = 0; i < G->vexnum; i++) {
        cin >> G->vexs[i];
    }
    cout << "输入一条弧的两个顶点以及权值" << endl;
    for (k = 0; k < G->arcnum; k++) {
        cin >> v1 >> v2 >> weight;
        i = LocateVertex(G, v1);
        j = LocateVertex(G, v2);
        G->arcs[i][j].adj = weight;  //建立一条弧
    }
    return OK;
}
//
//
//
//
//
//
//

/*大佬代码*/
#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100
#define INFINITY 65535
typedef int Vertex;  // 顶点下标
typedef int WeightType;
typedef char DataType;

// 图
typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;  // 顶点数
    int Ne;  // 边数
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;

// 边
typedef struct ENode *PtrToEnode;
struct ENode {
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToEnode Edge;

// 初始化
MGraph CreateGraph(int VertexNum) {
    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for (Vertex V = 0; V < Graph->Nv; V++) {
        for (Vertex W = 0; W < Graph->Nv; W++) {
            Graph->G[V][W] = INFINITY;
        }
    }
    return Graph;
}

void InsertEdge(MGraph Graph, Edge E) {
    Graph->G[E->V1][E->V2] = E->Weight;
    // 无向图
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph() {
    MGraph Graph;
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
        scanf(" %c", &(Graph->Data[V]));
    }

    return Graph;
}

int main() {
    MGraph Graph = BuildGraph();
    printf("Nv = %d\n", Graph->Nv);
    printf("Ne = %d\n", Graph->Ne);

    for (Vertex V = 0; V < Graph->Nv; V++) {
        printf(" %c", Graph->Data[V]);
    }
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
