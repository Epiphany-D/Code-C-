#include <math.h>
int IsPrime(int x) {
    int flag = 1;
    if (x <= 1)
        flag = 0;  //1既不是素数也不是合数
    for (int i = 2; i <= (int)sqrt(1.0 * x); i++) {
        if (x % i == 0) {
            flag = 0;
            return flag;
        }
    }
    return flag;
}

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// 埃氏筛法
#define NUM 100;  //求NUM以内的所有素数
const int maxn = NUM + 1;
int prime[maxn], pNum = 0;  //prime存放所有素数，pNum表示素数个数
bool p[maxn] = {0};
void Find_Prime() {
    for (int i = 2; i < maxn; i++) {  //这里千万不能写成i<=maxn
        if (p[i] == false) {
            prime[pNum++] = i;
            for (int j = i + i; j < maxn; j += 1) {
                p[j] = true;
            }
        }
    }
}
void printPrime() {
    Find_Prime();
    for (int i = 0; i < pNum; i++) {
        printf("%4d", prime[i]);
    }
}