// B - F002 装箱
// Time Limit: 1000/1000MS (C++/Others) Memory Limit: 65536/65536KB (C++/Others)
// Problem Description
// 一个工厂生产的产品形状都是长方体，高度都是h，主要有1*1，2*2，3*3，4*4，5*5，6*6等6种。这些产品在邮寄时被包装在一个6*6*h的长方体包裹中。由于邮费很贵，工厂希望减小每个订单的包裹数量以增加他们的利润。因此他们需要一个好的程序帮他们解决这个问题。你的任务就是设计这个程序。

// Input
// 输入包括多组测试数据，每一行代表一个订单。每个订单里的一行包括六个整数，用空格隔开，从小到大分别为这6种产品的数量。6个0表示文件结束。

// Output
// 针对每个订单输出一个整数，占一行，代表对应的订单所需的最小包裹数。没有多余的空行。

// Sample Input
// 0 0 4 0 0 1
// 7 5 1 0 0 0
// 0 0 0 0 0 0
// Sample Output
// 2
// 1

//装箱问题，因为高度统一不在考虑范围内，该问题等同于在6*6平面内画正方形

#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    int x, y;  //x为可以放1*1箱子的空余位置，y为可以放2*2箱子的空余位置
    int cl[4] = {0, 5, 3, 1};
    int sum = 0;

    while (1) {
        cin >> a >> b >> c >> d >> e >> f;
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
            break;
        sum = d + e + f + (c + 3) / 4;  // c+3为向上取整
        y = 5 * d + cl[c % 4];
        if (b > y)
            sum += (b - y + 8) / 9;  //+8向上取整
        x = 36 * sum - 36 * f - 25 * e - 16 * d - 9 * c - 4 * b;
        if (a > x)
            sum += (a - x + 35) / 36;  //+35向上取整
        cout << sum << endl;
    }
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <iostream>
// using namespace std;
// const int NUM = 6;
// int res[NUM];
// int main() {
//     int x6, x5, x4, x3, x2, x1;
//     cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6;
//     while (x1 + x2 + x3 + x4 + x5 + x6 > 0) {
//         for (int i = 0; i < NUM; i++) res[i] = 0;
//         int sum = 0;

//         sum += x6;

//         sum += x5;
//         res[0] -= 11 * x5;

//         sum += x4;
//         res[1] -= 5 * x4;

//         sum += x3 / 4;
//         int tmp = x3 % 4;
//         if (tmp == 1) {
//             sum += 1;
//             res[1] -= 5;
//             res[0] -= 7;
//         } else if (tmp == 2) {
//             sum += 1;
//             res[1] -= 3;
//             res[0] -= 6;
//         } else if (tmp == 3) {
//             sum += 1;
//             res[1] -= 1;
//             res[0] -= 5;
//         }

//         if (x2 + res[1] <= 0)
//             res[0] += 4 * (res[1] + x2);
//         else {
//             sum += (x2 + res[1] + 8) / 9;
//             res[0] -= (9 - (x2 + res[1]) % 9) * 4;
//         }

//         if (x1 + res[0] > 0)
//             sum += (x1 + res[0] + 35) / 36;

//         cout << sum << endl;

//         cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6;
//     }
//     return 0;
// }