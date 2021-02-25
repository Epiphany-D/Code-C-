#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int ElemType;
typedef int Status;
typedef struct student {
    ElemType score;
    struct student *next;
} LNode, *LinkList;
//建立链表
Status InitList_L(LinkList &L) {
    L = new LNode;  //L = (linklist)malloc(sizeof(LNode));
    L->next = NULL;
    return OK;
}
Status DestroyList_L(LinkList &L) {
    LinkList p;
    while (L) {
        p = L;
        L = L->next;
        delete p;  //free(p);
    }
    return OK;
}
Status ClearList(LinkList &L) {
    // 将L重置为空表
    LinkList p, q;
    p = L->next;  //p指向第一个结点
    while (p)     //没到表尾
    {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = NULL;  //头结点指针域为空
    return OK;
}
int ListLength(LinkList L) {
    //返回L中数据元素个数
    LinkList p;
    p = L->next;  //p指向第一个结点
    i = 0;
    while (p) {  //遍历单链表,统计结点数
        i++;
        p = p->next;
    }
    return i;
}
int ListEmpty(LinkList L) {
    //若L为空表，则返回1，否则返回0
    if (L->next)  //非空
        return 0;
    else
        return 1;
}
Status GetElem_L(LinkList L, int i, ElemType &e) {
    p = L->next;
    j = 1;                //初始化
    while (p && j < i) {  //向后扫描，直到p指向第i个元素或p为空
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;  //第i个元素不存在
    e = p->data;       //取第i个元素
    return OK;
}
LinkList LocateELem_L(LinkList L, ElemType e) {
    //返回L中值为e的数据元素的地址，查找失败返回NULL
    p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}
int LocateELem_L(LinkList L,ElemType e) {//返回L中值为e的数据元素的位置序号，查找失败返回0
    p = L->next;
    j = 1;
    while (p && p->data != e) {
        p = p->next;
        j++;
    }
    if (p)
        return j;
    else
        return 0;
}
Status ListInsert_L(LinkList &L, int i, ElemType e) {
    p = L;
    j = 0;
    while (p && j < i−1) {
        p = p->next;
        ++j;
    }  //寻找第i−1个结点
    if (!p || j > i−1)
        return ERROR;   //i大于表长 + 1或者小于1
    s = new LNode;      //生成新结点s
    s->data = e;        //将结点s的数据域置为e
    s->next = p->next;  //将结点s插入L中
    p->next = s;
    return OK;
}
Status ListDelete_L(LinkList &L, int i, ElemType &e) {  //被删除结点的数据保存在e中
    p = L;
    j = 0;
    while (p->next && j < i - 1) {  //寻找第i个结点，并令p指向其前驱
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)
        return ERROR;   //删除位置不合理
    q = p->next;        //临时保存被删结点的地址以备释放
    p->next = q->next;  //改变删除结点前驱结点的指针域
    e = q->data;        //保存删除结点的数据域
    delete q;           //释放删除结点的空间
    return OK;
}
void CreateList_F(LinkList &L, int n) {  //头插法
    L = new LNode;
    L->next = NULL;  //先建立一个带头结点的单链表
    for (i = n; i > 0; --i) {
        p = new LNode;   //生成新结点
        cin >> p->data;  //输入元素值
        p->next = L->next;
        L->next = p;  //插入到表头
    }
}
void CreateList_L(LinkList &L, int n) {  //尾插法
    //正位序输入n个元素的值，建立带表头结点的单链表L
    L = new LNode;
    L->next = NULL;
    r = L;  //尾指针r指向头结点
    for (i = 0; i < n; ++i) {
        p = new LNode;   //生成新结点
        cin >> p->data;  //输入元素值
        p->next = NULL;
        r->next = p;  //插入到表尾
        r = p;        //r指向新的尾结点
    }
}

int main() {
    return 0;
}