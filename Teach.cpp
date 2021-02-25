#include <stdio.h>
#include <math.h>
int gcd(int a, int b);
int main() {
    printf("%d", gcd(3, 9));
    return 0;
}
int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}