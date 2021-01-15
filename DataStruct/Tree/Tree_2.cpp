#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> Arr;  // 输入数据
int T[1001];      // 二叉搜索树数组，从1开始

// 计算n个结点的完全二叉树左边有多少个结点
int getLeftLength(int n) {
    // n 为结点总数，X为最后一层叶子节点总数
    // 2^H -1 +X = n
    int H = log2(n + 1);
    int X = n + 1 - pow(2, H);
    int maxLeaf = pow(2, H - 1);
    int leftx = (X < maxLeaf) ? X : maxLeaf;
    int L = pow(2, H - 1) - 1 + leftx;
    return L;
}

void solve(int ALeft, int ARight, int TRoot) {
    int n = ARight - ALeft + 1;
    if (n == 0) {
        return;
    }
    int L = getLeftLength(n);  // 左子树有L个结点
    T[TRoot] = Arr[ALeft + L];
    int LeftRoot = TRoot * 2;
    int RightRoot = LeftRoot + 1;
    solve(ALeft, ALeft + L - 1, LeftRoot);
    solve(ALeft + L + 1, ARight, RightRoot);
}
int main() {
    int N = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int curr = 0;
        scanf("%d", &curr);
        Arr.push_back(curr);
    }
    sort(Arr.begin(), Arr.end());

    solve(0, Arr.size() - 1, 1);

    printf("%d", T[1]);
    for (int i = 2; i <= N; i++) {
        printf(" %d", T[i]);
    }
    return 0;
}

 // 前序遍历
    void PreorderTraversal( BinTree BT )
    {
        if( BT ) {
            printf("%d ", BT->Data );
            PreorderTraversal( BT->Left );
            PreorderTraversal( BT->Right );
        }
    }
    // 中序遍历
    void InorderTraversal( BinTree BT )
    {
        if( BT ) {
            InorderTraversal( BT->Left );
            /* 此处假设对BT结点的访问就是打印数据 */
            printf("%d ", BT->Data); /* 假设数据为整型 */
            InorderTraversal( BT->Right );
        }
    }

    // 后序遍历
    void PostorderTraversal( BinTree BT )
    {
        if( BT ) {
            PostorderTraversal( BT->Left );
            PostorderTraversal( BT->Right );
            printf("%d ", BT->Data);
        }
    }