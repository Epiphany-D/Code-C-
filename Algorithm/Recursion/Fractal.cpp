#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char mapp[800][800];  //记录图形
void solve(int n, int x, int y) {
    if (n == 1) {
        mapp[x][y] = 'X';
    } else {
        int sizee = pow(3.0, n - 2);
        solve(n - 1, x, y);  //递归
        solve(n - 1, x + sizee * 2, y);
        solve(n - 1, x + sizee, y + sizee);
        solve(n - 1, x, y + sizee * 2);
        solve(n - 1, x + sizee * 2, y + sizee * 2);
    }
}
int main() {
    int n;
    while (cin >> n) {
        if (n == -1)
            break;
        int m = pow(3.0, n - 1);  //m为图形大小
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                mapp[i][j] = ' ';  //初始化
        }
        for (int i = 0; i < m; i++) {
            mapp[i][m] = '\0';
        }
        solve(n, 0, 0);
        for (int i = 0; i < m; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (mapp[i][j] == 'X')  //若为X则该行遍历结束
                    break;
                else if (mapp[i][j] != 'X')  //若非X则赋为'\0'
                    mapp[i][j] = '\0';
            }
        }
        for (int i = 0; i < m; i++)
            printf("%s\n", mapp[i]);
        printf("----------\n");
    }
    return 0;
}