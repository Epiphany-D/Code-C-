// B - E002 闪避湖泊
// Time Limit: 1000/1000MS (C++/Others) Memory Limit: 65536/65536KB (C++/Others)
// Problem Description
// 农夫约翰的农场在最近的一场暴风雨中被水淹没。但保险公司仅根据他得农场中最大的“湖泊”的大小赔偿一个数额。
// 农场可表示为N行M列的长方形网格，（1 ≤ N ≤ 100,1 ≤ M ≤ 100）。网格中的每个单元或是干的或是被淹没的，且恰有K个单元被水淹没，（1 ≤ K ≤ N*M）。正如人们所希望的，湖泊是一个中间单元，它与其他的单元共享一条长边（不是角落）。任何与中间单元共享一条长边或者与连通单元共享一条长边的单元是一个连通单元，是湖泊的一部分。

// Input
// 有多组数据。每组的第1行有3个整数N，M和K。第2行到第K+1行，是整数R和C，表示被淹没的位置。

// Output
// 对每组测试数据，输出有最大湖泊的单元的数目

// Sample Input
// 3 4 5
// 3 2
// 2 2
// 3 1
// 2 3
// 1 1
// 3 5 4
// 2 3
// 3 2
// 2 4
// 1 2
// Sample Output
// 4

// 2

#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

// int flag[110][110] = 0;不需要
int sub[110][110] = {0};
int Area(int x, int y);

int main() {
    int n, m, k, x, y;
    while (cin >> n >> m >> k) {
        int max = 0;
        while (k--) {
            cin >> x >> y;
            sub[x][y] = 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (sub[i][j]) {
                    int tmp = Area(i, j);
                    max = tmp > max ? tmp : max;
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}

int Area(int x, int y) {
    int num = 0;
    if (sub[x][y]) {
        num++;
        sub[x][y] = 0;
        num += Area(x + 1, y);
        num += Area(x - 1, y);
        num += Area(x, y + 1);
        num += Area(x, y - 1);
    }
    return num;
}
