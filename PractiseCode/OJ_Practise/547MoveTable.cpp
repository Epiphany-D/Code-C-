// F003 移动桌子(http://47.106.114.75/problem/547)
// Time Limit: 1000/1000MS (C++/Others) Memory Limit: 65536/65536KB (C++/Others)
// Total Submissions: 86 Accepted Submissions: 65
// Problem Description
// 著名的ACM（Advanced Computer Maker）公司租用了一层有400个房间的办公楼，结构如下。

// 这层楼沿着走廊南北向的两边各有200个房间。最近，公司要做一次装修，需要在各个办公室之间搬运办公桌。由于走廊狭窄，办公桌都很大，走廊里一次只能通过一张办公桌。必须制定计划提高搬运效率。经理制定如下计划：一张办公桌从一个房间移动到另一个房间最多用十分钟。当从房间i移动一张办公桌到房间j，两个办公室之间的走廊都会被占用。所以，每10分钟内，只要不是同一段走廊，都可以在房间之间移动办公桌。为了说得更清楚一些，经理举例说明哪些情况可以同时移动，哪些情况不能同时移动。

// 每个房间，只有一张办公桌进出。现在，经理想找到一种方案，使移动桌子的事情尽快完成。请编写程序解决经理的难题

// Input
// 输入数据有T组测试例，在第一行给出测试例个数（T）。每个测试例的第一行是一个整数N（1≤N≤200），表示要搬运办公桌的次数。接下来N行，每行两个正整数s和t，表示一张桌子，是从房间号码s移到房间号码t。有多组输入数据，输入第一行为一个表示输入数据总数的整数N，然后是N组输入数据。

// Output
// 每组输入都有一行的输出数据，为一整数T，表示完成任务所花费的最少时间。

// Sample Input
// 2
// 4
// 10 20
// 30 40
// 50 60
// 70 80
// 2
// 1 3
// 2 200
// Sample Output
// 10
// 20

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main() {
    int n, tables, corridor[200], i, j, start, end, time, x, y;
    scanf("%d", &n);
    while (n-- > 0) {
        memset(corridor, 0, sizeof(corridor));
        time = 0;
        scanf("%d", &tables);
        for (i = 0; i < tables; i++) {
            scanf("%d%d", &x, &y);
            start = ((x < y ? x : y) - 1) / 2;//除以2将房间号转化为走廊号
            end = ((x > y ? x : y) - 1) / 2;
            for (j = start; j <= end; j++)
                corridor[j] += 10;//每次搬运重叠的走廊部分增加10分钟
        }
        for (i = 0; i < 200; i++)
            time = corridor[i] > time ? corridor[i] : time;
        printf("%d\n", time);
    }
    return 0;
}
