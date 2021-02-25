#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

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

//随机选择算法，从A[left，right]中返回第K大的数
int randSelect(int A[], int left, int right, int K) {
    if (left == right)
        return A[left];
    int p = Rand_Partition(A, left, right);  //划分后主元的位置为P
    int M = p - left + 1;                    //A[p]是序列中第M大的数
    if(K<M){
        return randSelect(A, left, p - 1, K);
    }
    else {
        return randSelect(A, p + 1, right, K - M);//主元左边找第K-M大的数，此时的区间内最小的数是A[p]
    }
}

int main() {
    return 0;
}