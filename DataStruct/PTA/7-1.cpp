//7-1 两个有序链表的交集
#include <stdio.h>
#include <stdlib.h>

#define N 100000

typedef struct linknode {
    int data;
    struct linknode *next;
} node, *LNode;

LNode creatList() {
    int x;
    LNode p, s, last;
    s = NULL;
    last = NULL;
    while (~scanf("%d", &x)) {
        if (x < 0)
            break;
        p = (LNode)malloc(sizeof(node));
        p->data = x;
        if (s == NULL) {
            p->next = s;
            s = p;
            last = p;
        } else {
            last->next = p;
            p->next = NULL;
            last = p;
        }
    }
    return s;
}

int main() {
    LNode s1, s2, s3, p, q, z;
    s1 = NULL;
    s2 = NULL;
    s3 = NULL; //三个链表头
    s1 = creatList();
    s2 = creatList();
    s3 = (LNode)malloc(sizeof(node));
    s3->next = NULL;
    for (p = s1, q = s2, z = s3; p != NULL && q != NULL;) {
        if (p->data == q->data) {
            z->next = p;
            z = z->next;
            p = p->next;
            q = q->next;
        } else if (p->data < q->data) {
            p = p->next;
        } else if (p->data > q->data) {
            q = q->next;
        }
    }

    if ((s3->next == NULL || s1 == NULL) || s2 == NULL) {
        printf("NULL");
    } else {
        p = s3->next;
        while (p != NULL) {
            printf("%d", p->data);
            if (p->next != NULL) {
                printf(" ");
            }
            p = p->next;
        }
    }
    return 0;
}