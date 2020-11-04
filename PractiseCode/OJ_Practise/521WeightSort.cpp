#include <bits/stdc++.h>
using namespace std;

struct dietPp {
    char name[25];
    int day;
    int before;
    int now() {
        return (this->before - this->day);
    }
};
int cmp(const void *a, const void *b) {
    dietPp *p1 = (dietPp *)a;
    dietPp *p2 = (dietPp *)b;
    return p2->now() - p1->now();
}
dietPp guest[15];
int main() {
    char input_start[25], input_name[25];
    while (cin >> input_start) {
        if (strcmp(input_start, "START") == 0) {
            int pos = 0;
            while (cin >> input_name) {
                if (strcmp(input_name, "END") == 0)
                    break;
                strcpy(guest[pos].name, input_name);
                cin >> guest[pos].day >> guest[pos].before;
                pos++;
            }
            qsort(guest, pos, sizeof(guest[0]), cmp);
            for (int i = 0; i < pos; i++)
                cout << guest[i].name << endl;
            cout << endl;
        }
    }
    return 0;
}