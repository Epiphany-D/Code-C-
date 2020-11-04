//英文名字排序
// Problem Description
// 在汉语里，对汉语姓名可以按拼音排序，也可以按笔画顺序排序。在英语里，对英语姓名主要按字母顺序排序。本题要求给定的一组英文姓名按长短顺序排序。

// Input
// 输入文件中包含多个测试数据。每个测试数据的第1行是一个正整数N（0 < N < 100），表示该测试数据中英文姓名的数目；接下来有N行，每行为一个英文姓名，姓名中允许出现的字符有大小写英文字母、空格和点号（.），每个英文姓名长度至少为2、但不超过50.N=0表示输入结束。

// Output
// 对输入文件中的每个测试数据，输出排序后的姓名。排序方法为：先按姓名长度从长到短的顺序排序，对长度相同的姓名，则按字母顺序排序。每2个测试数据的输出之间输出一个空行。

// Sample Input
// 4
// David A. Forsyth
// Jean Ponce
// Tom M. Mitchell
// Thomas H. Cormen
// 0
// Sample Output
// David A. Forsyth
// Thomas H. Cormen
// Tom M. Mitchell
// Jean Ponce
#include <bits/stdc++.h>
using namespace std;
struct Name {
    char str[55];
    int length() {
        int pos = 0;
        while (this->str[pos++] != '\0')
            ;
        return pos - 1;
    }
} name[105];

int cmp(const void *a, const void *b) {
    Name *p1 = (Name *)a;
    Name *p2 = (Name *)b;
    if (p2->length() == p1->length())
        return strcmp(p1->str, p2->str);
    else
        return p2->length() - p1->length();
}

int main() {
    int i, n;
    while (cin >> n && n != 0) {
        getchar();
        memset(name, '\0', sizeof(name));
        for (i = 0; i < n; i++) {
            cin.getline(name[i].str, 55);
            if (name[i].length() < 2) {
                i--;//吐了，还给你不符合条件的名字
            }
        }
        qsort(name, n, sizeof(name[0]), cmp);
        for (i = 0; i < n; i++)
            cout << name[i].str << endl;
        cout << endl;
    }
    return 0;
}