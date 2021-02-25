int tree[100010], n = 100000;
void add(int x, int num) {
    for (; x <= n; x += x & -x)
        tree[x] += num;
}
int sum(int x) {
    int answer = 0;
    for (; x > 0; x -= x & -x)
        answer += tree[x];
    return answer;
}