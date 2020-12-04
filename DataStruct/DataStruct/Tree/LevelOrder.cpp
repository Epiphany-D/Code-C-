#include <bits/stdc++.h>
#define MAX 10000
int n;
typedef struct BiNode {
    int data;
    struct BiNode *lchild;
    struct BiNode *rchild;
} BiNode, *BiTree;
BiTree Build(int *in, int *post, int n) {
    if (n <= 0)
        return NULL;
    int *p = in;
    while (p) {
        if (*p == *(post + n - 1))
            break;
        p++;
    }
    BiTree T = new BiNode;
    T->data = *p;
    int len = p - in;
    T->lchild = Build(in, post, len);
    T->rchild = Build(p + 1, post + len, n - len - 1);
    return T;
}

// void BuildLevelTree(BiTree T, int *Q, int i) {
//     if (!T || i > n)
//         return;
//     Q[i] = T->data;
//     BuildLevelTree(T->lchild, Q, (i + 1) * 2 - 1);
//     BuildLevelTree(T->rchild, Q, (i + 1) * 2);
// }
void BLtree(BiTree bt) {  //层次遍历
    if (bt == NULL)
        return;
    int flag = 0;
    BiTree Q[50];
    int front = -1;
    int rear = 0;
    Q[rear] = bt;
    while (front != rear) {
        flag++;
        printf("%d%c", Q[front]->data, flag < n ? ' ' : '\n');
        if (Q[front]->lchild != NULL) {
            rear++;
            Q[rear] = Q[front]->lchild;
        }
        if (Q[front]->rchild != NULL) {
            rear++;
            Q[rear] = Q[front]->rchild;
        }
    }
}
int main() {
    int in[50], post[50];
    BiTree T;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    T = Build(in, post, n);
    // int Q[MAX] = {0};
    // // BuildLevelTree(T, Q, 0);
    // for (int i = 1; i <= n; i++) {
    //     if (Q[i])
    //         printf("%d%c", Q[i], i <= n ? ' ' : '\n');
    // }
    BLtree(T);
    return 0;
}
