#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
typedef struct student {
    int no;
    float score;
    struct student *next;
} listnode, *linklist;
//建立链表
void create(linklist &head) {
    linklist p = head;
    head->no = 0;
    while (cin >> p->score != 0) {
        p->no++;
        p = p->next;
    }
}
//打印链表
void print(linklist head) {
    while (head != NULL) {
        cout << head->score;
        head = head->next;
    }
}
//删除链表中结点为 num 的结点
void del(linklist &head, int num) {
    linklist p, q;
    while (p != NULL && num < p->no) {
        q = p;
        p = p->next;
    }
    if (num == p->no) {
        q->next = p->next;
        free(p);
        cout << "删除成功" << endl;
    } else {
        cout << "删除失败" << endl;
    }
}
//在第i个位置插入值为x的结点
void insert_pos(linklist &head, int i, int x) {
    linklist p, q;
    while (p != NULL && p->next->no != i) {
        p = p->next;
    }
    
}
// void merge_list(linklist &head1,linklist head2){

// }
int main() {

    return 0;
}