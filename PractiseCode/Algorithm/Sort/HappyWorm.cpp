//快乐的蠕虫
// Problem Description
// 有一只快乐的蠕虫居住在一个m×n大小的网格中。在网格的某些位置放置了k块石头。网格中的每个位置要么是空的，要么放置了一块石头。当蠕虫睡觉时，它在水平方向或垂直方向上躺着，把身体尽可能伸展开来。蠕虫的身躯既不能进入到放有石块的方格中，也不能伸出网格外。而且蠕虫的长度不会短于2个方格的大小。
// 本题的任务是给定网格，要计算蠕虫可以在多少个不同的位置躺下睡觉。

// Input
// 输入文件的第1行是一个整数t，1<=t<=11,表示测试数据的个数。每个测试数据的第1行为3个整数：m,n和k(0<=m,n,k<=200000),接下来有k行，每行为2个整数，描述了一块石头的位置（行和列，最左上角位置为（1,1））。

// Output
// 对每个测试数据，输出占一行，为一个整数，表示蠕虫可以躺着睡觉的不同位置的数目。

// Sample Input
// 1
// 5 5 6
// 1 5
// 2 3
// 2 4
// 4 2 
// 4 3
// 5 1
// Sample Output
// 9

#include <stdio.h>
#include <stdlib.h>

struct In {
    int x;
    int y;
} s[1000000];  //存储石头的位置（包括后添加的石头）

int cmpx(const void *a, const void *b)  //二级排序，先比较x，再比较y
{
    struct In *c = (In *)a;
    struct In *d = (In *)b;
    if (c->x != d->x)
        return c->x - d->x;
    return c->y - d->y;
}
int cmpy(const void *a, const void *b)  //二级排序，先比较y，再比较x
{
    struct In *c = (In *)a;
    struct In *d = (In *)b;
    if (c->y != d->y)
        return c->y - d->y;
    return c->x - d->x;
}

int main() {
    int kase;  //输入文件中测试数据个数
    scanf("%d", &kase);
    while (kase--) {
        int m, n, k;  //每个测试数据中的3个数
        int i, j;     //循环变量
        scanf("%d%d%d", &m, &n, &k);
        for (i = 0; i < k; i++)  //读入k块石头的位置
            scanf("%d%d", &s[i].x, &s[i].y);
        for (j = 1; j <= n; j++)  //添加垂直方向上边界的石头
        {
            s[i].x = 0;
            s[i].y = j;
            i++;
            s[i].x = m + 1;
            s[i].y = j;
            i++;
        }
        for (j = 1; j <= m; j++)  //添加水平方向上边界的石头
        {
            s[i].y = 0;
            s[i].x = j;
            i++;
            s[i].y = n + 1;
            s[i].x = j;
            i++;
        }
        int t = 0;  //蠕虫可以躺着睡觉的不同位置的数目
        qsort(s, i, sizeof(s[0]), cmpx);
        for (j = 0; j < i - 1; j++) {
            //如果前后两个位置的x坐标相同，y坐标相差超过2
            if (s[j].x == s[j + 1].x && s[j + 1].y - s[j].y > 2)
                t++;
        }
        qsort(s, i, sizeof(s[0]), cmpy);
        for (j = 0; j < i - 1; j++) {
            //如果前后两个位置的y坐标相同，x坐标相差超过2
            if (s[j].y == s[j + 1].y && s[j + 1].x - s[j].x > 2)
                t++;
        }
        printf("%d\n", t);
    }
    return 0;
}
