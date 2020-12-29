//英文单词排序
// Problem Description
// 在美国数以百万计的报纸中，有一种单词游戏称为猜词。游戏的目标是猜谜，为了找出答案中缺少的字母，有必要对4个单词的字母顺序重新调整。在本题中，你的任务是编写程序实现对单词中的字母顺序重新调整。

// Input
// 输入文件包含4部分：
// （1） 一部字典，包含至少1个单词，至多100个单词，每个单词占一行；
// （2） 字典后是一行字符串“XXXXXX”，表示字典结束；
// （3） 一个或多个被打乱字母顺序的“单词”，每个单词占一行，你必须整理这些字母的顺序；
// （4） 输入文件的最后一样为字符串“XXXXXX”，代表输入文件结束。
// 所有单词，包括字典中的单词和被打乱字母顺序的单词，都只包含小写英文字母，并且至少包含一个字母，至多包含6个字母。字典中的单词不一定是按顺序排列的，但保证字典中的单词是唯一的。

// Output
// 对输入文件中每个被打乱字母顺序的单词w，按字母顺序输出字典中所有满足以下条件的单词的列表：通过调整单词w中的字母顺序，可以变成字典中的单词。列表中的每个单词占一行。如果列表为空（即单词w不能转换成字典中的任何一个单词），则输出一行字符串“NOT A VALID WORD”。以上两种情形都在列表后，输出一行包含6个星号字符的字符串，表示列表结束。

// Sample Input
// tarp
// given
// score
// refund
// only
// trap
// work
// earn
// course
// pepper
// part
// XXXXXX
// resco
// nfudre
// aptr
// sett
// oresuc
// XXXXXX
// Sample Output
// score
// ******
// refund
// ******
// part
// tarp
// trap
// ******
// NOT A VALID WORD
// ******
// course
// ******

/*我的写法↓AC了*/

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <algorithm>

// using namespace std;
// struct Dir  //字典中的单词
// {
//     char str[10];     //读入时的排列顺序
//     char sorted[10];  //排序后的顺序
// } dir[101];           //字典

// int compare(const void *arg1, const void *arg2) {
//     return strcmp((*(struct Dir *)arg1).str, (*(struct Dir *)arg2).str);
// }

// int main() {
//     int i = 0;
//     while (scanf("%s", &dir[i].str) && strcmp(dir[i].str, "XXXXXX")) {
//         strcpy(dir[i].sorted, dir[i].str);
//         //对字典中每个单词的字母按ASCII编码值进行排序
//         sort(dir[i].sorted, dir[i].sorted + strlen(dir[i].str));
//         ++i;
//     }
//     qsort(dir, i, sizeof(dir[0]), compare);  //对字典中所有单词进行排序
//     char s[10];
//     while (scanf("%s", s) && strcmp(s, "XXXXXX")) {
//         sort(s, s + strlen(s));  //对读入的打乱字母顺序的单词中的字母排序
//         bool flag = false;       //是否查找到匹配单词的标志
//         for (int j = 0; j < i; ++j) {
//             if (strcmp(s, dir[j].sorted) == 0) {
//                 flag = true;
//                 printf("%s\n", dir[j].str);
//             }
//         }
//         if (!flag)
//             printf("NOT A VALID WORD\n");
//         printf("******\n");
//     }
//     return 0;
// }

/*怀智大佬的写法↓*/

#include <bits/stdc++.h>
#define res register int
using namespace std;
const int maxn = 1e2 + 12;
struct node {
    string word;
    string ans;
    void st() {
        sort(this->word.begin(), this->word.end());
    }
} v[maxn];
string s;
inline int cmp(const node &a, const node &b) {
    return a.ans < b.ans;
}
int main() {
    int n = 0;
    while (1) {
        cin >> v[++n].word;
        if (v[n].word == "XXXXXX") {
            n--;
            break;
        }
        v[n].ans = v[n].word;
        v[n].st();
    }
    sort(v + 1, v + n + 1, cmp);
    while (1) {
        s.clear();
        cin >> s;
        if (s == "XXXXXX")
            break;
        else {
            sort(s.begin(), s.end());
            bool cg = 0;
            for (res i = 1; i <= n; i++) {
                if (!s.compare(v[i].word)) {
                    cout << v[i].ans << endl;
                    cg = 1;
                }
            }
            if (!cg)
                cout << "NOT A VALID WORD\n";
            cout << "******\n";
        }
    }
    return 0;
}