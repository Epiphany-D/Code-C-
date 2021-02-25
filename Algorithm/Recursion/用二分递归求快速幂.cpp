//快速幂的递归写法
#include <stdio.h>
typedef long long LL;
//快速求a的b次方
LL binaryPow(LL a, LL b) {
    if (b == 0)
        return 1;
    if (b & 1) {  //判断b的最后一位是否为1，即判断b是否为奇数
        return a * binaryPow(a, b - 1);
    } else {
        LL tmp = binaryPow(a, b / 2);
        return tmp * tmp;
    }
}

int main() {
    LL a = 23, b = 9;
    printf("%lld", binaryPow(a, b));
}