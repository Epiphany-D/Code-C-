#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    int age;
    int grade;
} student, *stu;

int cmpOfStruct1(const void *elem1, const void *elem2) {
    return ((stu)elem1)->age - ((stu)elem2)->age;
}

int cmpOfStruct2(const void *elem1, const void *elem2) {
    stu a = (stu)elem1;
    stu b = (stu)elem2;
    if (a->grade == b->grade) {
        return a->grade - b->grade;
    } else {
        return a->age - b->age;
    }
}
int cmpOfnum(const void *elem1, const void *elem2) {
    return *(int *)elem2 - *(int *)elem1;
}

int main() {
    int i = 0;
    int a[110];
    while (i < 100) {
        a[i] = abs(rand() % 100);
        i++;
    }
    qsort(a, 101, sizeof(a[0]), cmpOfnum);
    while (i--) {
        printf("%5d%c", a[i], i % 10 == 0 ? '\n' : ' ');
    }
}