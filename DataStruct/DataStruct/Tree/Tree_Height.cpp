#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight(BinTree BT);

int main() {
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}
/* 你的代码将被嵌在这里 */
int GetHeight(BinTree BT) {
    int l, r;
    if (BT->Left)
        l = GetHeight(BT->Left) + 1;
    else if (BT->Right)
        r = GetHeight(BT->Right) + 1;
    else
        return 0;
    return l > r ? l : r;
}