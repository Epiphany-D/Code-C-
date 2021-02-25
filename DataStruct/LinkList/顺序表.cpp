#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define MAXSIZE 10000
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef ElemType int;
typedef Status int;

typedef struct {
    ElemType *elem;  //指向数据元素的基地址
    int length;      //线性表的当前长度
} SqList;

int InitList_Sq(SqList &L) {         //构造一个空的顺序表L
    L.elem = new ElemType[MAXSIZE];  //为顺序表分配空间
    if (!L.elem)
        exit(OVERFLOW);  //存储分配失败
    L.length = 0;        //空表长度为0
    return OK;
}
void DestroyList(SqList &L) {
    if (L.elem)
        delete[] L.elem;  //释放存储空间
}
void ClearList(SqList &L) {
    L.length = 0;  //将线性表的长度置为0
}
int GetLength(SqList L) {
    return (L.length);
}
int IsEmpty(SqList L) {
    if (L.length == 0)
        return 1;
    else
        return 0;
}
Status GetElem(SqList L, int i,ElemType &e) {
    if (i < 1 || i > L.length)
        return ERROR;
    //判断i值是否合理，若不合理，返回ERROR
    e = L.elem[i - 1];  //第i-1的单元存储着第i个数据
    return OK;
}
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
int LocateELem(SqList L, ElemType e) {
    for (i = 0; i < L.length; i++)
        if (L.elem[i] == e)
            return i + 1;
    return 0;
}
Status ListInsert_Sq(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1)
        return ERROR;  //i值不合法
    if (L.length == MAXSIZE)
        return ERROR;  //当前存储空间已满
    for (j = L.length - 1; j >= i - 1; j--)
        L.elem[j + 1] = L.elem[j];  //插入位置及之后的元素后移
    L.elem[i - 1] = e;              //将新元素e放入第i个位置
    L.length++;                     //表长增1
    return OK;
}
Status ListDelete_Sq(SqList &L, int i) {
    if ((i < 1) || (i > L.length))
        return ERROR;  //i值不合法
    for (j = i - 1; j < L.length - 1; j++)
        　  　L.elem[j] = L.elem[j + 1];  //被删除元素之后的元素前移
    L.length--;                           //表长减1
    return OK;
}

int main() {
    return 0;
}