#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
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
Status CreatTree(BiTree &p, elemtype x);
Status InsertDataL(elemtype x, BiTree &parent);
Status InsertDataR(elemtype x, BiTree &parent);

int main() {
    BiTree tree, p;
    CreatTree(tree, 0);
    p = tree;
    InsertDataL(23, p);
    InsertDataR(32, p);
    cout << p->data << " " << p->lchild->data << endl;
    system("pause");
    return 0;
}

//生成一个树的根
Status CreatTree(BiTree &p, elemtype x) {
    if ((p = (BiTree)malloc(sizeof(BitNode))) == NULL) {
        return ERROR;
    }
    p->data = x;
    p->lchild = NULL;
    p->rchild = NULL;
    return OK;
}
//二叉树插入
Status InsertDataL(elemtype x, BiTree &parent) {
    BiTree p;
    if (parent == NULL) {
        cout << "插入数字出错" << endl;
        return ERROR;
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
Status InsertDataR(elemtype x, BiTree &parent) {
    BiTree p;
    if (parent == NULL) {
        cout << "插入数字出错" << endl;
        return ERROR;
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