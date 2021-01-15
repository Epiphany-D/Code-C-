#include <bits/stdc++.h>
#define res register int
using namespace std;
inline void move(char A, char B) {
    printf("%c-->%c\n", A, B);
}
inline void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        move(A, C);
        return;
    }
    hanoi(n - 1, A, C, B);
    move(A, C);
    hanoi(n - 1, B, A, C);
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        hanoi(n, 'A', 'B', 'C');
        printf("\n");
    }
    return 0;
}