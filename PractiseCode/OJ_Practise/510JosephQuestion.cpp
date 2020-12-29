// 约瑟夫问题
// 递推公式： f(N,M)=(f(N−1,M)+M)%N

#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int n, m, i, s = 0;
    scanf("%d%d", &n, &m);
    for (i = 2; i <= n; i++)
        s = (s + m) % i;
    cout << s + 1 << endl;
    return 0;
}