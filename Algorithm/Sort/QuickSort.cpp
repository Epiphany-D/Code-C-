#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//划分函数
int Partition(int A[], int left, int right) {
    int tmp = A[left];  //这里是将A[left]作为主元划分
    while (left < right) {
        while (left < right && A[right] >= tmp)  // 从右向左找第一个小于tmp的数
            right--;
        A[left] = A[right];
        while (left < right && A[left] < tmp)  // 从左向右找第一个大于等于tmp的数
            left++;
        A[right] = A[left];
    }
    A[left] = tmp;
    return left;
}

//快速排序
void Quick_Sort(int A[], int left, int right) {
    if (left < right) {
        int pos = Partition(A, left, right);
        Quick_Sort(A, left, pos - 1);
        Quick_Sort(A, pos + 1, right);
    }
}

//当快排的序列中元素的排列比较有序时会接近最坏时间复杂度O(n2)，为了避免这种情况，选择随机主元：

//C语言中rand()函数有一个RAND_MAX常数，一般值为32767，因此需要对更大的区间序列排序时：
int Rand_int(int a, int b) {  //输出一个在a到b区间的随机数，需要引入stdlib.h和time.h头文件
    printf("%d", (int)(round(1.0 * rand() / RAND_MAX * (b - a) + a)));
}

//随机主元划分序列
int Rand_Partition(int A[], int left, int right) {
    int p = (int)(round(1.0 * rand() / RAND_MAX * (right - left) + left));  //随机数p
    swap(A[p], A[left]);
    //以下与Partition函数一致
    int tmp = A[left];  //这里是将A[left]作为主元划分
    while (left < right) {
        while (left < right && A[right] >= tmp)  // 从右向左找第一个小于tmp的数
            right--;
        A[left] = A[right];
        while (left < right && A[left] < tmp)  // 从左向右找第一个大于等于tmp的数
            left++;
        A[right] = A[left];
    }
    A[left] = tmp;
    return left;
}

//随机快排
void Rand_Quick_Sort(int A[], int left, int right) {
    if (left < right) {
        int pos = Rand_Partition(A, left, right);
        Quick_Sort(A, left, pos - 1);
        Quick_Sort(A, pos + 1, right);
    }
}

int main() {
    return 0;
}