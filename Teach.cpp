#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, k, i, j;
    string str[101];
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> str[i];
    for (i = 0; i < k; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1])
                swap(str[j], str[j + 1]);
        }
    }
    for (i = 0; i < n; i++)
        cout << str[i] << endl;
    return 0;
}
