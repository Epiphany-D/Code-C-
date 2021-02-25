int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}
// int gcd(int a, int b) {
//     if (b == 0)
//         return a;
//     else
//         return gcd(b, a % b);
// }
