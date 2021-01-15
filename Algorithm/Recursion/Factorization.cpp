// A014 分解因式
// Time Limit: 1000/1000MS (C++/Others) Memory Limit: 65536/65536KB (C++/Others)
// Total Submissions: 78 Accepted Submissions: 42
// Problem Description
// 给出一个正整数a，要求分解成若干个正整数的乘积，即a = a1 * a2 * a3 * ... * an，并且1 < a1 <= a2 <= a3 <= ... <= an，问这样的分解的种数有多少。注意到a = a也是一种分解。

// Input
// 第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a (1 < a < 32768)。

// Output
// n行，每行输出对应一个输入。输出应是一个正整数，指明满足要求的分解的种数。

// Sample Input
// 2
// 2
// 20
// Sample Output
// 1
// 4
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int cnt = 0;

int Factorization(int i, int num) {
    if (i == 1) {
        return 0;
    }
    if (num == 1) {
        return 1;
    }
    if (num % i == 0) {
        return Factorization(i, num / i) + Factorization(i - 1, num);
    } else
        return Factorization(i - 1, num);
}

int main() {
    int n;
    int num;
    cin >> n;
    while (n--) {
        cin >> num;
        cout << Factorization(num, num) << endl;
    }

    return 0;
}