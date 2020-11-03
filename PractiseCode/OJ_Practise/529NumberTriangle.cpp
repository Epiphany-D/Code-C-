//数字三角形
#include <stdio.h>
int max[101][101];
int d[101][101];
int main() {
    int n, i, j;
    while (~scanf("%d", &n)) {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= i; j++)
                scanf("%d", &d[i][j]);
        for (i = 1; i <= n; i++)
            max[n][i] = d[n][i];
        for (i = n - 1; i >= 1; i--)
            for (j = 1; j <= i; j++)
                if (max[i + 1][j] > max[i + 1][j + 1])
                    max[i][j] = d[i][j] + max[i + 1][j];
                else
                    max[i][j] = d[i][j] + max[i + 1][j + 1];
        printf("%d\n", max[1][1]);
    }
    return 0;
}