// C005 电缆主（Cable master）
// Time Limit: 1000/1000MS (C++/Others) Memory Limit: 65536/65536KB (C++/Others)
// Total Submissions: 185 Accepted Submissions: 40
// Problem Description
// 奶牛的居民决定举办一场编程区域赛。裁判委员会自告奋勇并宣称要举办有史以来最公正的比赛。队员们的电脑采用“星型”拓扑结构互连（也就是说要把所有电脑都连在一个中央集线器上）。为了让比赛尽可能公正，裁判委员会的头头们决定：将比赛队员们平均地安置在集线器周围，距离集线器有一个相同的距离。
// 裁判委员会为了采买网络电缆，联系了一家当地的网络方案提供商，要求他们提供一些登等长的电缆。这些电缆应越长越好，从而使得队员们与其他队员的距离越大。
// 这家公司的电缆工来办这件事。他知道仓库里每个电缆的长度（精确到厘米）。他每次切割电缆时的精度也是厘米。但他现在不知切多少，所以完全茫然中。
// 你要写个程序计算出一条电缆最多多长使之可以提供一定能够数目的电缆，帮着这位电缆工完成任务。

// Input
// 第一行是两个整数N和K，N（1<=N<=10000）是仓库里的电缆数，K（1<=K<=10000）是所需电缆数。接下来的N行每一行一个数，表示电缆的长度（单位是米）。电缆长度最小为1米，最大为100千米。每个表示长度的数均表示为带两位小数的浮点数（及精确到厘米）。

// Output
// 所需的电缆一条最长有多少（精确到米）。如果不能提供K条大于等于1厘米的等长电缆就输出“0.00”。

// Sample Input
// 4 11
// 8.02
// 7.43
// 4.57
// 5.39
// Sample Output
// 2.00

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 10000 + 10;
int n, m;
int a[maxn], maxa;
void solve() {
    int L = 0, R = maxa + 1, mid;
    int ans = 0;
    while (L + 1 < R) {
        ans = 0;
        mid = (L + R) / 2;
        for (int i = 0; i < n; i++)
            ans += a[i] / mid;
        if (ans < m)
            R = mid;
        else
            L = mid;
    }
    printf("%.2lf\n", L / 100.00);
}
int main() {
    cin >> n >> m;
    maxa = 0;
    double t;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &t);
        a[i] = t * 100;
        maxa = max(maxa, a[i]);
    }
    solve();
    return 0;
}
