// C - E003 信道分配
// Time Limit: 1000/1000MS (C++/Others) Memory Limit: 65536/65536KB (C++/Others)
// Problem Description
// 当无线电台在一个非常大的区域上传播信号时，为了每个接收器都能得到较强信号，使用转发器转发信号。然而，需要仔细地选择每个转发器使用的频道，以使附近的转发器不彼此干扰。如果邻近的转发器使用不同的频道，条件就得到满足。
// 因为无线电波的频谱是宝贵的资源，转发器所需频道的数量应减到最少。编程任务：读取转发器网络的描述信息，并计算出所需频道的最小使用量。

// Input
// 输入包含许多转发器网络图。每幅图的第一行是转发器数目（1~26）。转发器用连续的大写字母表示，从A开始。例如，10个转发器的名称分别是A，B，C，…，I和J。当转发器的个数是0时，表示输入结束。
// 转发器数目之后，是其邻近关系的列表。每行的格式为
// A：BCDH
// 表示转发器B、C、D和H与转发器A邻近。第一行描述与转发器A邻近的，第二行描述与B邻近的，直到描述完所有的转发器。如果某个转发器不与其他转发器相邻，它的形式为
// A：
// 转发器依字母顺序列出。
// 注意：相邻是对称的关系；如果A与B相邻，那么B与A也相邻。因为转发器位于水平面内，由相邻的转发器构成的网络图没有相交的线。

// Output
// 对于每幅图（除了最后一个没有转发器），输出一行，是转发器不互相干扰所需的最少频道数。输出格式参考样例输出。注意：频道数为1的话，“channel”为单数。

// Sample Input
// 2
// A:
// B:
// 4
// A:BC
// B:ACD
// C:ABD
// D:BC
// 0
// Sample Output
// 1 channel needed.
// 3 channels needed.

#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    int inx;
    int ans;
    char s[30];
    while (~scanf("%d", &n), n) {
        int ans = 0;
        int flag[30] = {0};  //储存颜色种类，先使得所有字母都用颜色0来标注
        int lock[30] = {0};  //上锁，当lock[对应字母]为1后该字母颜色不改变
        while (n--) {
            scanf("%s", &s);
            int i = 2;
            while (s[i] != '\0') {
                if (flag[s[0] - 'A'] == flag[s[i] - 'A'] && !lock[s[i] - 'A']) {
                    flag[s[i] - 'A']++;//颜色冲突，换下一种颜色
                }
                i++;
            }
            lock[s[0] - 'A']++;
            ans = ans > flag[s[0] - 'A'] + 1 ? ans : flag[s[0] - 'A'] + 1;
            if (ans > 3)
                break;
        }
        if (ans == 1)
            printf("1 channel needed.\n");
        else if (ans == 2)
            printf("2 channels needed.\n");
        else if (ans == 3)
            printf("3 channels needed.\n");
        else
            printf("4 channels needed.\n");
    }
    return 0;
}