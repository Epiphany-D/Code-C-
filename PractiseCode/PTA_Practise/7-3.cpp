// 7-3 一元多项式的乘法与加法运算 (20分)
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

#define N 10000

void Read(int M[]);
void Print(int M[]);
void Multi(int c[], int a[], int b[]);
void Add(int d[], int a[], int b[]);

int main() {
    int a[N] = {0}, b[N] = {0};  //两个待操作数组
    int c[N] = {0}, d[N] = {0};  //积数组与和数组
    Read(a);
    Read(b);
    Multi(c, a, b);
    Add(d, a, b);
    Print(c);
    Print(d);
    return 0;
}

void Read(int M[]) {
    int i, x, z;
    scanf("%d", &i);  //读入第一个单项式
    while (i--) {
        scanf("%d %d", &x, &z);
        M[z] += x;  //指数为z的系数放在z位置上
    }
}

void Print(int M[]) {
    int i;
    int flag = 0;
    for (i = N - 1; i >= 0; i--) {
        if (M[i]) {
            if (flag)
                printf(" ");
            printf("%d %d", M[i], i);
            flag++;
        }
    }
    if (!flag)
        printf("0 0\n");
    else
        printf("\n");
}

void Multi(int c[], int a[], int b[]) {
    //多项式乘法
    int i, j;
    for (i = N - 1; i >= 0; i--)
        if (a[i])
            for (j = 0; j < N; j++)
                if (b[j])
                    c[i + j] += a[i] * b[j];
}

void Add(int d[], int a[], int b[]) {
    //多项式加法
    int i, j;
    for (i = N - 1; i >= 0; i--)
        if (a[i])
            d[i] += a[i];
    for (j = N - 1; j >= 0; j--)
        if (b[j])
            d[j] += b[j];
}