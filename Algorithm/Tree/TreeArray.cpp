// https://blog.csdn.net/weixin_43914593/article/details/107842628
#include <cstdio>
user namespace std;
#define lowbit(x) ((x) & -(x))
int tree[Maxn];
void update(int x, int d) {  //修改元素ax,  ax = ax + d
    while (x <= Maxn) {
        tree[x] += d;
        x += lowbit(x);
    }
}
int sum(int x) {  //返回值是前缀和：ans = a1 + ... + ax
    int ans = 0;
    while (x > 0) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

//例题：
/*Color the ball hdu 1556
问题描述：N个气球排成一排，从左到右依次编号为1, 2, 3 … N。每次给定2个整数L, R(L<= R)，lele从气球L开始到气球R依次给每个气球涂一次颜色。
但是N次以后lele已经忘记了第i个气球已经涂过几次颜色了，你能帮他算出每个气球被涂过几次颜色吗？
输入：每个测试实例第一行为一个整数N，(N <= 100000)。接下来的N行，每行包括2个整数L, R(1 <= L<= R<= N)。当N = 0，输入结束。
输出：每个测试实例输出一行，包括N个整数，第I个数代表第I个气球总共被涂色的次数。*/

//hdu 1556代码
//tree[Maxn]，lowbit(x)，update()，sum()的代码前面已给出
// const int Maxn = 100010;
// int main() {
//     int n;
//     while (~scanf("%d", &n)) {
//         memset(tree, 0, sizeof(tree));  //只需要一个tree[]数组
//         for (int i = 1; i <= n; i++) {  //区间修改
//             int L, R;
//             scanf("%d%d", &L, &R);
//             update(L, 1);  //本题的d = 1
//             update(R + 1, -1);
//         }
//         for (int i = 1; i <= n; i++) {  //单点查询
//             if (i != n)
//                 printf("%d ", sum(i));  //把sum(i)看成a[i]
//             else
//                 printf("%d\n", sum(i));
//         }
//     }
//     return 0;
// }

//hdu 1556 用差分数组求解
#include<bits/stdc++.h>
using namespace std;
const int Maxn = 100010;
int a[Maxn],D[Maxn];               //a是气球，D是差分数组

int main(){
    int n;
    while(~scanf("%d",&n)) { 
        memset(a,0,sizeof(a)); memset(D,0,sizeof(D));
        for(int i=1;i<=n;i++){
            int L,R; scanf("%d%d",&L,&R);
            D[L]++;                 //差分，原理和前面树状数组一样
            D[R+1]--;
        }
        for(int i=1;i<=n;i++){
            a[i] = a[i-1] + D[i];          //求前缀和a[]，a[i]就是气球i的值
            if(i!=n)  printf("%d ", a[i]);  //逐个打印结果
            else      printf("%d\n",a[i]);
        }        
    }
    return 0;
}

