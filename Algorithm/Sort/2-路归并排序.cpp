//递归实现归并排序
//递增合并序列
void Merge(int* a, int low, int mid, int high) {
    int i = low, j = mid + 1, p = 0;   //对应a数组的下标
    int* r = new int[high - low + 1];  //申请另一个对应大小的数组来存放排好序的数据
    while (i <= mid && j <= high) {
        r[p++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    }
    while (i <= mid)
        r[p++] = a[i++];
    while (j <= high)
        r[p++] = a[j++];
    for (p = 0, i = low; i <= high; p++, i++)
        a[i] = r[p];  //最后再把有序数据存进a数组中，使得a数组对应部分数据有序
    delete[] r;
}
//自顶向下(递归实现)
void MSort(int* a, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MSort(a, low, mid);
        MSort(a, mid + 1, high);//分到不能再分
        Merge(a, low, mid, high);
    }
}
