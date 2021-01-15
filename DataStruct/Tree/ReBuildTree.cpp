
#include <iostream>
using namespace std;
int in[31], post[31];
typedef struct BiTNode {
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
} BiTNode, *BiTree;
// 根据中序和后序遍历重构一棵树
BiTree Build(int *in, int *post, int n) {
    if (n <= 0)
        return NULL;
    int *p = in;
    while (p) {
        if (*p == *(post + n - 1))
            break;
        p++;
    }
    BiTree T = new BiTNode;
    T->data = *p;
    int len = p - in;
    T->lchild = Build(in, post, len);
    T->rchild = Build(p + 1, post + len, n - len - 1);
    return T;
}
void PreOrder(BiTree T) {
    if (T) {
        printf(" %d", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
    return;
}
int main() {
    int n;
    BiTree T;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    T = Build(in, post, n);
    printf("Preorder:");
    PreOrder(T);
    return 0;
}