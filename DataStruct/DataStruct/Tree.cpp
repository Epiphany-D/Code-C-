#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) > (b) ? (b) : (a)
#define node (BiTree)malloc(sizeof(BitNode))
typedef int Status;
typedef int elemtype;

//定义树的结构
typedef struct BitNode {
    Status data;
    struct BitNode *lchild, *rchild;
} BitNode, *BiTree;
//操作函数列表
Status InitBiTree(BiTree &p);
Status DesstroyBiTree(BiTree &p);
Status CreatTree(BiTree &p, elemtype x);
Status ClearTree(BiTree &p);
Status IsEmpty(BiTree p);
Status Depth(BiTree p);
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
    if ((p = node) == NULL) {
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
    if ((p = node) == NULL) {
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
    if ((p = node) == NULL) {
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
//初始化一棵二叉树
Status InitBiTree(BiTree &p){
    
}
Status DesstroyBiTree(BiTree &p);
Status ClearTree(BiTree &p);
Status IsEmpty(BiTree p);
Status Depth(BiTree p);