// 从两个有序的线性表 合成 为一个大的有序表
#include <bits/stdc++.h>
using namespace std;

int *merge_sorted_arr(int *a, int m, int *b, int n) {
    int *res = new int[m + n];
    int i = 0, j = 0, pos = 0;
    for (; i < m && j < n;) {
        if (a[i] < b[j]) {
            res[pos++] = a[i];
            i++;
        } else {
            res[pos++] = b[j];
            j++;
        }
    }
    while (j < n) {
        res[pos++] = b[j++];
    }
    while (i < m) {
        res[pos++] = a[i++];
    }

    return res;
}

void print_arr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int main(int argc, char *argv[]) {
    {
        int a[] = {1};
        int b[] = {1, 2, 3};
        int *ans = merge_sorted_arr(a, sizeof(a) / 4, b, sizeof(b) / 4);
        print_arr(ans, sizeof(a) + sizeof(b) >> 2);
    }
    {
        int a[] = {1};
        int b[] = {1, 2, 3, 4, 5};
        int *ans = merge_sorted_arr(a, sizeof(a) / 4, b, sizeof(b) / 4);
        print_arr(ans, sizeof(a) + sizeof(b) >> 2);
    }
    return 0;
}
