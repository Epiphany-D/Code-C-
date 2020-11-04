// //DNA排序
// Problem Description
// 一个序列的逆序数定义为序列中无序元素对的数目。例如，在字符序列DAABEC中，逆序数为5，因为字符D比它右边的4个字符大，而字符E比它右边的1个字符大。字符序列AACEDGG只有1个逆序，即E和D,它几乎是已经排好序的，而字符序列“ZWQM”有6个逆序，它是最大程度的无序，即有序序列的逆序。
// 在本题中，你的任务是对DNA字符串（只包含字符“A”、“C”，“G”和“T”）进行排序。注意不是按照字母顺序，而是按照逆序数从低到高进行排序，所有字符串的长度都一样。

// Input
// 输入文件中包含多组测试数据。每组测试数据的格式为：第1行为2个整数，正整数n(0 < n <= 50，表示字符串的长度)和正整数m(1 < m <= 100,表示字符串的数目)；然后是m行，每一行为一个字符串，长度为n。

// Output
// 对应到输入文件中的N组测试数据，输出也有N组，每2组输出之间有一个空行。对每组输入数据，按逆序数从低到高输出各字符串，如果2个字符串的逆序数一行，则按输入时的先后顺序输出。

// Sample Input
// 10 5
// TTTTGGCCAA
// TTTGGCCAAA
// GATCAGATTT
// CCCGGGGGGA
// ATCGATGCAT
// Sample Output
// CCCGGGGGGA
// GATCAGATTT
// ATCGATGCAT
// TTTTGGCCAA
// TTTGGCCAAA
#include <iostream>
#include <algorithm>

typedef struct DNA {
    int count;  // 逆序数的个数
    char DNAStr[110];
} DNA;

int N;
int SIZE;
int countA, countC, countG;

/** 计算DNA字符串的逆序数  */
int getDNAInversionNumber(char* dnaStr) {
    int count = 0;
    countA = countC = countG = 0;
    for (int j = SIZE - 1; j >= 0; j--) {
        switch (dnaStr[j]) {
        case 'A':
            countA++;
            break;
        case 'C':
            countC++;
            count += countA;
            break;
        case 'G':
            countG++;
            count += countA;
            count += countC;
            break;
        case 'T':
            count += countA;
            count += countC;
            count += countG;
            break;
        }
    }
    return count;
}

int cmp(const void* a, const void* b) {
    DNA* DNA_A = (DNA*)a;
    DNA* DNA_B = (DNA*)b;
    return (DNA_A->count) - (DNA_B->count);
}

int main() {
    using namespace std;
    while (cin >> SIZE >> N) {
        DNA* dnas = new DNA[N];
        for (int i = 0; i < N; i++) {
            cin >> dnas[i].DNAStr;
            dnas[i].count = getDNAInversionNumber(dnas[i].DNAStr);
        }

        qsort(dnas, N, sizeof(DNA), cmp);

        for (int i = 0; i < N; i++) {
            cout << dnas[i].DNAStr << endl;
        }
    }
    return 0;
}