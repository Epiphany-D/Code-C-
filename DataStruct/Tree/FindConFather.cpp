#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int findFather(int n, int m);
int main() {
    int BTree[1011] = {'\0'};  //顺序树
    int N;
    int ans = 0;
    scanf("%d", &N);  //输入树的容量
    int i = 0;
    for (i = 0; i < N; i++) {
        scanf("%d", &BTree[i]);
    }
    int num_1 = 0, num_2 = 0;
    scanf("%d %d", &num_1, &num_2);     //输入寻找结点的位置
    ans = findFather(num_1, num_2);  //调用函数
    if (num_1 == num_2)                 //当寻找重合结点时
        printf("%d %d\n", num_1, BTree[num_1 - 1]);
    else if (BTree[num_1 - 1] == 0)  //当寻找的结点不存在时
        printf("ERROR: T[%d] is NULL\n", num_1);
    else if (BTree[num_2 - 1] == 0)
        printf("ERROR: T[%d] is NULL\n", num_2);
    else
        printf("%d %d\n", ans, BTree[ans - 1]);

    return 0;
}
int findFather(int n, int m) {
    while (1) {
        if (n > m)
            n /= 2;
        else
            m /= 2;
        if (n == m)
            break;
    }
    return n;
}