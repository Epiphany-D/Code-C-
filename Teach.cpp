#include <stdio.h>
#include <math.h>
int main() {
    int x, i, s, flag;
    while (scanf("%d", &x) != EOF) {
        s = 0;
        while (x > 0) {
            flag = 1;
            if (x == 1)
                flag = 0;
            else {
                for (i = 2; i <= sqrt(x); i++) {
                    if (x % i == 0)
                        flag = 0;
                    break;
                }
            }
            if (flag == 1)
                s += x;
            scanf("%d", &x);
        }
        printf("%d\n", s);
    }
    return 0;
}