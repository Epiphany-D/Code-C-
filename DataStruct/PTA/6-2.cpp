// 6-2 数组元素的区间删除 (20分)
#include <stdio.h>

#define MAXN 20

int Delete(int A[], int L, int minA, int maxA);

int main() {
    int A[MAXN], L, minA, maxA, i;

    scanf("%d", &L);
    for (i = 0; i < L; i++) scanf("%d", &A[i]);
    scanf("%d %d", &minA, &maxA);
    L = Delete(A, L, minA, maxA);
    for (i = 0; i < L; i++) printf("%d ", A[i]);
    printf("\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
int Delete(int A[], int L, int minA, int maxA) {
    int a[L];
    int j = 0;
    for (int i = 0; i < L; i++)
        if (A[i] <= minA || A[i] >= maxA)
            a[j++] = A[i];
    for (int i = 0; i < j; i++)
        A[i] = a[i];
    return j;
}
