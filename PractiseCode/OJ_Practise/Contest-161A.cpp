// A - C002 赌徒（Gamblers）
// Time Limit: 1000/1000MS (C++/Others) Memory Limit: 65536/65536KB (C++/Others)
// Problem Description
// N个赌徒一起决定玩一个游戏：
// 游戏刚开始的时候，每个赌徒把赌注放在桌上并遮住，侍者要查看每个人的赌注并确保每个人的赌注都不一样。如果一个赌徒没钱了，则他要借一些筹码，因此他的赌注为负数。假定赌注都是整数。
// 最后赌徒们揭开盖子，出示他们的赌注。如果谁下的赌注是其他赌徒中某3个人下的赌注之和，则他是胜利者。如果有多于一个胜利者，则下的赌注最大的赌徒才是最终的胜利者。
// 例如，假定赌徒为：Tom、Bill、John、Roger和Bush，他们下的赌注分别为：$2、$3、$5、$7和$12 。因此最终获胜的是Bush（并且没有其他人是胜利者），因为他下的赌注为$12，而其他的人下的赌注之和也等于12：2+2+3+7=7=12。

// Input
// 输入文件中包含了多组赌徒下的赌注。每组赌注的数据第1行是一个整数n,1<=n<=1000,代表赌徒的个数，然后是他们下的赌注，每个人的赌注占一行，这些赌注各不相同，并且范围是[-536870912,+536870911]。输入文件的最后一行为0，代表输入结束。

// Output
// 对每组赌注，输出胜利者下的赌注，如果没有解，则输出“no solution”。

// Sample Input
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
// Sample Output
// 12
// no solution

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n, i, j, flag, k;
    int a[1005];
    while (scanf("%d", &n), n != 0) {
        flag = 0;
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        for (i = n - 1; i >= 2; i--) {
            for (j = i - 1; j >= 1; j--) {
                for (k = j - 1; k >= 0; k--) {
                    if (a[i] - a[j] == a[k]) {
                        printf("%d\n", a[i]);
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        if (!flag)
            printf("no solution\n");
    }
    return 0;
}