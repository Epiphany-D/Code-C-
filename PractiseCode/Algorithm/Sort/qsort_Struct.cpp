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