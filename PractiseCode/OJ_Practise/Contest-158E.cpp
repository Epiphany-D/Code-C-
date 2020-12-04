// E - E009 小木棒
// Time Limit: 1000/1000MS (C++/Others) Memory Limit: 65536/65536KB (C++/Others)
// Problem Description
// George有一些长度相等的木棒，他随意的将这些木棒切成长度最多是50的小木棒。麻烦来了，他现在想将这些杂乱的小木棒恢复到原来的木棒，但是他忘记了原来到木棒的数量和长度。请你帮助他设计一个程序计算出原来木棒可能的最小长度，所有小木棒的长度均表示为大于0的整数。

// Input
// 每组输入数据包括两行。第一行是George切后小木棒的个数，最多有64根小木棒；第二行是这些小木棒的长度，这些长度表示为空格分开的整数。输入样例以整数0表示结束。

// Output
// 输出一行，即为原始木棒可能的最小长度。

// Sample Input
// 9
// 5 2 1 5 2 1 5 2 1
// 4
// 1 2 3 4
// 0
// Sample Output
// 6
// 5

// 自己写的错了↓
// #include <bits/stdc++.h>
// #include <cstdlib>
// using namespace std;

// int main() {
//     int k, n;
//     while (cin >> k, k) {
//         int sum = 0;
//         int max = 0;
//         while (k--) {
//             cin >> n;
//             sum += n;
//             max = max > n ? max : n;
//         }
//         while (max) {
//             if (sum % max == 0) {
//                 cout << max << endl;
//                 break;
//             }
//             max++;
//         }
//     }
// }

// 大佬写的↓
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 70;
int s[maxn];
int vis[maxn];
int n;
int ans;
bool cmp(int a, int b) {
    return a > b;
}
bool dfs(int _sum, int node, int kase, int p, int floor) {
    if (_sum > p)
        return false;
    if (kase == ans - 1)
        return true;
    if (_sum == p && dfs(0, 1, kase + 1, p, 1))
        return true;
    for (int i = node; i <= n; i++) {
        if (vis[i] == 1)
            continue;
        if (vis[i - 1] == 0 && s[i - 1] == s[i])
            continue;
        vis[i] = 1;
        if (dfs(_sum + s[i], node + 1, kase, p, 2))
            return true;
        if (floor == 1) {
            vis[i] = 0;
            return false;
        }
        vis[i] = 0;
    }
    return false;
}
int main() {
    while (scanf("%d", &n) && n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &s[i]);
            sum += s[i];
        }
        sort(s + 1, s + n + 1, cmp);
        for (int i = s[1]; i <= sum; i++) {
            if (i == sum) {
                printf("%d\n", i);
                break;
            }
            //拼成i长度的木棒
            if (sum % i)
                continue;
            ans = sum / i;
            memset(vis, 0, sizeof(vis));
            if (dfs(0, 1, 0, i, 1)) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
