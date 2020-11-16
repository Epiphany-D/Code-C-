#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
#define MAX(a, b) (a) > (b) ? (a) : (b)
#define MIN(a, b) (a) > (b) ? (b) : (a)
#define node (BiTree) malloc(sizeof(BitNode))
typedef int Status;
typedef int elemtype;

//定义树的结构
typedef struct BitNode {
    Status data;
    struct BitNode *lchild, *rchild;
} BitNode, *BiTree;
/*操作函数列表*/

//生成一个二叉树
Status CreatTree(BiTree &T, elemtype x) {
    if ((T = node) == NULL) {
        return ERROR;
    }
    T->data = x;
    T->lchild = NULL;
    T->rchild = NULL;
    return OK;
}
//删除一棵二叉树
Status DestroyTree(BiTree &T) {
    if (T == NULL) {
        return OK;
    } else {
        DestroyTree(T->lchild);
        DestroyTree(T->rchild);
        free(T);
    }
}
//初始化一棵二叉树
Status ClearTree(BiTree &T) {
    DestroyTree(T->lchild);
    DestroyTree(T->rchild);
    T->data = 0;
}
//二叉树插入
Status InsertDataL(elemtype x, BiTree &parent) {
    BiTree p;
    if (parent == NULL) {
        cout << "插入数据失败" << endl;
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
        cout << "插入数据失败" << endl;
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
//二叉树删除叶子节点
Status DeleteNodeL(BiTree &parent) {
    BiTree p;
    if (!parent || !parent->lchild) {
        cout << "删除节点失败" << endl;
        return ERROR;
    }
    p = parent->lchild;
    if (p->lchild || p->rchild) {
        cout << "要删除的节点不是叶子节点" << endl;
        return ERROR;
    }
    parent->lchild = NULL;
    free(p);
    return OK;
}
Status DeleteNodeR(BiTree &parent) {
    BiTree p;
    if (!parent || !parent->rchild) {
        cout << "删除节点失败" << endl;
        return ERROR;
    }
    p = parent->rchild;
    if (p->lchild || p->rchild) {
        cout << "要删除的节点不是叶子节点" << endl;
        return ERROR;
    }
    parent->rchild = NULL;
    free(p);
    return OK;
}
//二叉树的遍历
Status PreOrder(BiTree T) {
    if (T == NULL)
        return OK;
    cout << T->data << endl;
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}
Status InOrder(BiTree T) {
    if (T == NULL)
        return OK;
    PreOrder(T->lchild);
    cout << T->data << endl;
    PreOrder(T->rchild);
}
Status PostOrder(BiTree T) {
    if (T == NULL)
        return OK;
    PreOrder(T->lchild);
    PreOrder(T->rchild);
    cout << T->data << endl;
}
//统计叶子节点数
Status CountLeaf(BiTree T) {
    if (T == NULL)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)
        return 1;
    return CountLeaf(T->lchild) + CountLeaf(T->rchild);
}
//获得树的高度
Status GetHeight(BiTree T) {
    int l, r;
    if (T->lchild)
        l = GetHeight(T->lchild) + 1;
    else if (T->rchild)
        r = GetHeight(T->rchild) + 1;
    else
        return 0;
    return l > r ? l : r;
}
int main() {
    BiTree tree, p;
    CreatTree(tree, 0);
    p = tree;
    InsertDataL(23, p);
    InsertDataR(32, p);
    // ClearTree(p);
    cout << GetHeight(p) << endl;
    system("pause");
    return 0;
}
