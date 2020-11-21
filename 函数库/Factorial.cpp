int Factorial(int x) {
    int i = 1;
    int ans = 1;
    while (i <= x) {
        ans *= i;
        i++;
    }
    return ans;
}