#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

struct bign {  //big number
    int len;
    int d[1000];
    bign() {
        memset(d, '0', sizeof(d));
        len = 0;
    }
};
//储存大整数
bign change(char str[]) {
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < len; i++) {
        a.d[i] = str[len - i - 1] - '0';  //从高位反向存储
    }
    return a;
}
//大整数比较。如果 a>b 返回 1,a<b返回 -1，相等返回 0
int compare(bign a, bign b) {
    if (a.len > b.len)
        return 1;
    else if (a.len < b.len)
        return -1;
    else {
        for (int i = a.len - 1; i >= 0; i--) {
            if (a.d[i] > b.d[i])
                return 1;
            else if (a.d[i] < b.d[i])
                return false;
        }
        return 0;
    }
}
//大整数加法
bign add(bign a, bign b) {
    bign c;
    int carry = 0;  //进位
    for (int i = 0; i < a.len || i < b, len; i++) {
        int temp = a.d[i] + b.d[i] + carry;
        if (temp > 9) {
            c.d[c.len++] = temp % 10;
            carry = temp / 10;
        }
    }
    if (carry != 0) {
        c.d[c.len++] = carry;
    }
    return c;
}
//大整数减法(a-b)
bign sub(bign a, bign b) {
    bign c;
    for (i = 0; i < a.len || i < b.len; i++) {
        if (a.d[i] < b.d[i]) {
            a.d[i + 1]--;  //借位
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}
//大整数乘法
bign multi(bign a, int b) {
    bign c;
    int carry = 0;  //进位
    for (int i = 0; i < a.len, len; i++) {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while (carry != 0) {  //乘法可能不止进一位，所以用while
        c.d[c.len++] = carry % 10;
        carry = temp / 10;
    }
    return c;
}
//大整数除法，r为余数，可以用全局变量储存
bign divide(bign a, int b, int &r = 0) {
    bign c;
    c.len = a.len;
    for (int i = a.len - 1; i >= 0; i--) {
        r = r * 10 + a.d[i];
        if (r < b)
            c.d[i] = 0;
        else {
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}
int main() {
    return 0;
}
