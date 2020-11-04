// CS902：赌徒（Gamblers）（1343）
// （来源：ZOJ 1101，程序设计方法及在线实践指导（王衍等） P346）
// 问题描述：
// 	N个赌徒一起决定玩一个游戏：
// 	游戏刚开始的时候，每个赌徒把赌注放在桌上并遮住，侍者要查看每个人的赌注并确保每个人的赌注都不一样。如果一个赌徒没钱了，则他要借一些筹码，因此他的赌注为负数。假定赌注都是整数。
// 	最后赌徒们揭开盖子，出示他们的赌注。如果谁下的赌注是其他赌徒中某3个人下的赌注之和，则他是胜利者。如果有多于一个胜利者，则下的赌注最大的赌徒才是最终的胜利者。
// 	例如，假定赌徒为：Tom、Bill、John、Roger和Bush，他们下的赌注分别为：$2、$3、$5、$7和$12 。因此最终获胜的是Bush（并且没有其他人是胜利者），因为他下的赌注为$12，而其他的人下的赌注之和也等于12：$2+$3+$7=$12。
// 输入：
// 输入文件中包含了多组赌徒下的赌注。每组赌注的数据第1行是一个整数n,1<=n<=1000,代表赌徒的个数，然后是他们下的赌注，每个人的赌注占一行，这些赌注各不相同，并且范围是[-536870912,+536870911]。输入文件的最后一行为0，代表输入结束。
// 输出：
// 对每组赌注，输出胜利者下的赌注，如果没有解，则输出“no solution”。
// 样例输入：
// 5
// 2
// 3
// 5
// 7
// 12
// 5
// 2
// 16
// 64
// 256
// 1024
// 0
// 样例输出：
// 12
// no solution
#include <stdio.h>
#include <stdlib.h>

const int MAXN = 1001;
int data[MAXN], n;  //赌徒们下的赌注及赌徒的人数

//排序函数的比较因子，升序排序
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int search(int x)  //在data数组中查找x，如果查找到，返回相应的下标，否则返回-1,采用二分搜索法
{
    int low = 0, high = n - 1, mid;  //计算左右边界
    while (low <= high) {
        mid = (low + high) / 2;  //中间位置
        if (data[mid] == x)
            return mid;  //找到了，返回位置序号
        if (data[mid] > x)
            high = mid - 1;
        if (data[mid] < x)
            low = mid + 1;
    }
    return -1;  //没有找到
}

//枚举算法，求解答案
void work() {
    qsort(data, n, sizeof(data[0]), cmp);  //从小到大排序
    int i, j, k, m;
    //枚举查找
    for (i = n - 1; i >= 0; i--)  //赢家从序列的后面取，确保是最大的
    {
        for (j = 0; j < n; j++) {
            if (i == j)
                continue;
            for (k = j + 1; k < n; k++) {
                if (i == k)
                    continue;
                m = search(data[i] - data[j] - data[k]);
                //存在第4个人下的赌注为data[i]-data[j]-data[k]
                //并且这个人不是i,j,也不是k，则i就是胜利者
                if (m >= 0 && m != i && m != j && m != k) {
                    printf("%d\n", data[i]);
                    return;
                }
            }
        }
    }
    printf("no solution\n");
}

int main() {
    while (scanf("%d", &n)) {
        int i;
        if (n == 0)
            break;
        for (i = 0; i < n; i++)
            scanf("%d", &data[i]);
        work();
    }
    return 0;
}
