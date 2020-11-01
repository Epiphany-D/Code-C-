//最长上升子序列
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000

int b[MAX_N + 10];
int aMaxLen[MAX_N + 10];

int main() {
    int N;
    int nMax = -1;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> b[i];
    }
    aMaxLen[1] = 1;
    for (int i = 2; i <= N; i++) {
        int nTmp = 0;
        for (int j = 1; j < i; j++) {
            if (b[j] < b[i]) {
                if (nTmp < aMaxLen[j]) {
                    nTmp = aMaxLen[j];
                }
            } else {
                aMaxLen[i] = nTmp + 1;
            }
        }
        for (int i = 1; i <= N; i++) {
            if (nMax < aMaxLen[i]) {
                nMax = aMaxLen[i];
            }
        }
    }
    cout << nMax << endl;
    //getchar();
    system("pause");
    return 0;
}