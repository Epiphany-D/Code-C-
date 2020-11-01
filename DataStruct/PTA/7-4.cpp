//7-4 数组循环左移（20 分）
#include <stdio.h>
int main() {
    int n, m;
    int a[101], b[101];
    int i = 0, j = 0, k = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if (n > m)
        k = n - m;
    else {
        while (n <= m)
            m = m - n;
        k = n - m;
    }
    for (j = k; j < n; j++, i++)
        b[j] = a[i];
    for (j = 0; j < k; j++, i++)
        b[j] = a[i];
    for (j = 0; j < n - 1; j++)
        printf("%d ", b[j]);
    printf("%d\n", b[n - 1]);
    return 0;
}