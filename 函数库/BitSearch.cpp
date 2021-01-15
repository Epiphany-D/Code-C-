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