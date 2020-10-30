#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) > (b) ? (b) : (a)
typedef int Status;
typedef int elemtype;
//定义树的结构
typedef struct BitNode {
    Status data;
    struct BitNode *lchild, *rchild;
} BitNode, *BiTree;
//操作函数列表
BiTree CreatTree(elemtype x = 0);
Status InsertL(BiTree p, elemtype x, BiTree &parent);
Status InsertR(BiTree p, elemtype x, BiTree &parent);

int main() {
    BiTree tree = CreatTree();
    
    system("pause");
    return 0;
}
//生成一个树的根
BiTree CreatTree(elemtype x = 0) {
    BiTree p;
    if ((p = (BiTree)malloc(sizeof(BitNode))) == NULL) {
        return ERROR;
    }
    p->data = x;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}
//二叉树插入
Status InsertL(BiTree p, elemtype x, BiTree &parent) {
    if (parent == NULL) {
        cout << "插入出错" << endl;
        return OVERFLOW;
    }
    if ((p = (BiTree)malloc(sizeof(BitNode))) == NULL) {
        return ERROR;
    }
    p->data = x;
    p->lchild = NULL;
    p->rchild = NULL;
    if (parent->lchild == NULL) {
        parent->lchild = p;
    } else {
        p->lchild = parent->lchild;
        parent->lchild = p;
    }
    return OK;
}
Status InsertR(BiTree p, elemtype x, BiTree &parent) {
    if (parent == NULL) {
        cout << "插入出错" << endl;
        return OVERFLOW;
    }
    if ((p = (BiTree)malloc(sizeof(BitNode))) == NULL) {
        return ERROR;
    }
    p->data = x;
    p->lchild = NULL;
    p->rchild = NULL;
    if (parent->rchild == NULL) {
        parent->rchild = p;
    } else {
        p->rchild = parent->rchild;
        parent->rchild = p;
    }
    return OK;
}