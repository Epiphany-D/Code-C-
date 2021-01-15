void Quick_Sort(int A[], int low, int high) {
    //low和high是数组的下标
    if (low < high) {
        int temp, mid = A[low];
        int l = low, h = high;
        while (l < h) {
            while (A[l] < mid) l++;
            while (A[h] >= mid) h--;
            if (l < h) {
                temp = A[l];
                A[l] = A[h];
                A[h] = temp;
            }
         }
        Quick_Sort(A, low, l - 1);
        Quick_Sort(A, l + 1, high);
    }
}