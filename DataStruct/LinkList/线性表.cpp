#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define MAXSIZE 10000
#define OK 1
#define ERROR 0
typedef int Status;
typedef struct LNode *List;
struct LNode {
    Status Data[MAXSIZE];
    int lenth;
};
//初始化线性表
List Init_SqList() {
    List Ptrl;
    Ptrl = new LNode;
    Ptrl->lenth = -1;
    return Ptrl;
}
//判断线性表中元素
int Elem_SqList(List L, Status m) {
    int i = 0;
    while (i <= L->lenth && L->Data[i] != m) {
        i++;
    }
    if (i > L->lenth) {
        return ERROR;
    } else {
        return OK;
    }
}

int main() {
    return 0;
}