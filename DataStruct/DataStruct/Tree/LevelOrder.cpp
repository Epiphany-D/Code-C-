#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
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
    BiTree T = new BiTNode;
    T->data = *p;
    int len = p - in;
    T->lchild = Build(in, post, len);
    T->rchild = Build(p + 1, post + len, n - len - 1);
    return T;
}
void CoutPre(BiTree T)  //先序输出
{
    if (T != NULL) {
        printf(" %d", T->data);
        CoutPre(T->lchild);
        CoutPre(T->rchild);
    }
}
int main() {
    int N, *End, *Mid;
    scanf("%d", &N);
    End = (int *)malloc(sizeof(int) * N);
    Mid = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        scanf("%d", &End[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &Mid[i]);
    BiTree T = BuildPreTree(End, Mid, N);
    printf("Preorder:");
    CoutPre(T);
}