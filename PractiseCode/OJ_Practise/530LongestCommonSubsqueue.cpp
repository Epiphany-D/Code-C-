// D004 最长公共子序列
// Time Limit: 1000/1000MS (C++/Others) Memory Limit: 65536/65536KB (C++/Others)
// Problem Description
// 我们称序列Z = < z1, z2, ..., zk >是序列X = < x1, x2, ..., xm >的子序列当且仅当存在严格上升的序列< i1, i2, ..., ik >，使得对j = 1, 2, ... ,k, 有xij = zj。比如Z = < a, b, f, c > 是X = < a, b,c, f, b, c >的子序列。
// 现在给出两个序列X和Y，你的任务是找到X和Y的最大公共子序列，也就是说要找到一个最长的序列Z，使得Z既是X的子序列也是Y的子序列。

// Input
// 输入包括多组测试数据。每组数据包括一行，给出两个长度不超过200的字符串，表示两个序列。两个字符串之间由若干个空格隔开。

// Output
// 对每组输入数据，输出一行，给出两个序列的最大公共子序列的长度。

// Sample Input
// abcfbc abfcab
// programming contest
// abcd mnp
// Sample Output
// 4
// 2
// 0

/*↓这个程序没有运用动态规划的思想，大量的重复计算导致会产生超时*/

// #include <bits/stdc++.h>
// #include <cstdlib>
// using namespace std;
// #define Max(a, b) (a) > (b) ? (a) : (b)

// char z[210], x[210];
// int z_len, x_len;

// int LongestComSubqueue(int i, int j) {
//     if (i == 0 || j == 0) {
//         return 0;
//     } else if (z[i] == x[j]) {
//         return LongestComSubqueue(i - 1, j - 1) + 1;
//     } else {
//         return Max(LongestComSubqueue(i - 1, j), LongestComSubqueue(i, j - 1));
//     }
// }
// int main() {
//     int i, j, ans;
//     while (~scanf("%s %s", z, x)) {
//         i = j = ans;
//         z_len = strlen(z) - 1;
//         x_len = strlen(x) - 1、;
//         ans = LongestComSubqueue(z_len, x_len);
//         cout << ans << endl;
//     }
//     return 0;
// }

/*↓这个是对的*/

// #include <stdio.h>
// #include <string.h>
// #define MAX_LEN 1000

// char sz1[MAX_LEN];
// char sz2[MAX_LEN];
// int aMaxLen[MAX_LEN][MAX_LEN];

// main() {
//     while (scanf("%s%s", sz1 + 1, sz2 + 1) > 0) {
//         int nLength1 = strlen(sz1 + 1);
//         int nLength2 = strlen(sz2 + 1);
//         int nTmp;
//         int i, j;
//         for (i = 0; i <= nLength1; i++)
//             aMaxLen[i][0] = 0;
//         for (j = 0; j <= nLength2; j++)
//             aMaxLen[0][j] = 0;
//         for (i = 1; i <= nLength1; i++) {
//             for (j = 1; j <= nLength2; j++) {
//                 if (sz1[i] == sz2[j])
//                     aMaxLen[i][j] = aMaxLen[i - 1][j - 1] + 1;
//                 else {
//                     int nLen1 = aMaxLen[i][j - 1];
//                     int nLen2 = aMaxLen[i - 1][j];
//                     if (nLen1 > nLen2)
//                         aMaxLen[i][j] = nLen1;
//                     else
//                         aMaxLen[i][j] = nLen2;
//                 }
//             }
//         }
//         printf("%d\n", aMaxLen[nLength1][nLength2]);
//     }
// }
// // https://blog.csdn.net/hrn1216/article/details/51534607

/*怀智大佬写的更简单的↓*/

#include <bits/stdc++.h>
#define res register int
#define Mem(a, c) memset(a, c, sizeof(a))
using namespace std;
const int maxn = 2e2 + 12;
char a[maxn], b[maxn];
int dp[maxn][maxn];
int main() {
    while (~scanf("%s", a)) {
        scanf(" %s", b);
        int la = strlen(a), lb = strlen(b);
        Mem(dp, 0);
        for (res i = 0; i < la; i++) {
            for (res j = 0; j < lb; j++) {
                if (a[i] == b[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        printf("%d\n", dp[la][lb]);
    }
    return 0;
}