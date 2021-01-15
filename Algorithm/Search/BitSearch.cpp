#include <stdio.h>
#define MAX 10
int binarySearch(int A[], int left, int right, int x) {
    int mid;  //mid 为left和right的中点
    while (left <= right) {
        mid = (left + right) / 2;
        if (A[mid] == x)
            return mid;
        else if (A[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;  //查找失败
}
int main() {
    int A[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", binarySearch(A, 0, MAX - 1, 5));
    return 0;
}