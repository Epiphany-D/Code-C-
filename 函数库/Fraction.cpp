//分数的表示/化简/运算
#include <bits/stdc++.h>
int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

struct Fraction {
    int up, down;  //分子和分母
};

Fraction reduction(Fraction x) {  //分数的化简
    if (x.down < 0) {
        x.up = -x.up;
        x.down = -x.down;
    }
    if (x.up == 0) {
        x.down = 1;
    } else {
        int d = gcd(abs(x.up), abs(x.down));
        x.up /= d;
        x.down /= d;
    }
    return x;
}

