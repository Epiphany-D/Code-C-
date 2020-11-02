#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int common(int x, int y) {
    if (x == y)
        return x;
    if (x < y)
        return common(x, y / 2);
    else
        return common(x / 2, y);
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << common(a, b) << endl;
    }
    system("pause");
    return 0;
}