int IsPrime(int x) {
    int i;
    int flag = 1;
    if (x == 1)
        flag = 0;
    for (i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            flag = 0;
            return flag;
        }
    }
    return flag;
}