// 7-2 堆栈操作合法性 (20分)
#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <string>
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef int Status;
using namespace std;
typedef struct
{
    char *base;
    char *top;
    int stacksize;
} SqStack;
Status InitStack(SqStack &S, int L) {
    S.base = new char[L];
    if (!S.base)
        exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = L;
    return OK;
}
Status push(SqStack &S, char c) {
    if (S.top - S.base == S.stacksize)
        return ERROR;
    *S.top++ = c;
    return OK;
}
Status pop(SqStack &S, char c) {
    if (S.top == S.base)
        return ERROR;
    c = *(--S.top);
    return OK;
}
bool IsRight(string s, int L) {
    int i = 0, flag = 1;
    SqStack St;
    InitStack(St, L);
    while (s[i] != '\0') {
        if (s[i] == 'S') {
            if (push(St, s[i]) == OK)
                i++;
            else {
                flag = 0;
                break;
            }
        } else {
            if (pop(St, s[i]) == OK)
                i++;
            else {
                flag = 0;
                break;
            }
        }
    }
    if ((St.top == St.base) && s[i] == '\0')
        flag = 1;
    else
        flag = 0;
    if (flag == 1)
        return true;
    else
        return false;
}
int main() {
    int N, M, k = 0;
    char c;
    string ss;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> ss;
        if (IsRight(ss, M) == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    system("pause");
}